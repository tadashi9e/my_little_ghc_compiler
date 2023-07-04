#include <stdio.h>
#include <stdint.h>
#include <atomic>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <vector>

using Q = intptr_t;
using A = std::atomic<Q>;

enum TAG_T {
  TAG_REF,
  TAG_ATOM,
  TAG_INT,
  TAG_LIST,
  TAG_NIL
};

std::string to_str(TAG_T tag) {
  switch (tag) {
  case TAG_REF: return "REF";
  case TAG_ATOM: return "ATOM";
  case TAG_INT: return "INT";
  case TAG_LIST: return "LIST";
  case TAG_NIL: return "NIL";
  default: return "---";
  }
}

std::ostream& operator<<(std::ostream& stream,
                         TAG_T tag) {
  stream << to_str(tag);
  return stream;
}

template<TAG_T TAG, typename VALUE>
Q tagvalue(VALUE value) {
  return (static_cast<Q>(value) << 3) | TAG;
}

template<TAG_T TAG, typename VALUE>
Q tagptr(VALUE* p) {
  return (reinterpret_cast<Q>(p) & ~static_cast<Q>(0x7)) | TAG;
}

TAG_T tag_of(Q q) {
  return static_cast<TAG_T>(q & 0x7);
}

template<typename VALUE>
VALUE value_of(Q q) {
  return static_cast<VALUE>(q >> 3);
}

template<typename VALUE>
VALUE* ptr_of(Q q) {
  return reinterpret_cast<VALUE*>(q & ~static_cast<Q>(0x7));
}

Q deref(Q q) {
  for (;;) {
    const TAG_T tag = tag_of(q);
    if (tag != TAG_REF) {
      break;
    }
    A* a = ptr_of<A>(q);
    Q q2 = a->load();
    if (q == q2) {
      break;
    }
    q = q2;
  }
  return q;
}

class AtomDictionary {
 public:
  static AtomDictionary& getInstance();
  int64_t id_of_str(const std::string& str) {
    std::unique_lock<std::mutex> lock(mutex_);
    std::unordered_map<std::string, int64_t>::const_iterator
      iter = str_index_map_.find(str);
    if (iter != str_index_map_.end()) {
      return iter->second;
    }
    ++last_index_;
    str_index_map_[str] = last_index_;
    index_str_map_[last_index_] = str;
    return last_index_;
  }
  std::string str_of_id(int64_t id) const {
    std::unique_lock<std::mutex> lock(mutex_);
    std::unordered_map<int64_t, std::string>::const_iterator
      iter = index_str_map_.find(id);
    if (iter != index_str_map_.end()) {
      return iter->second;
    }
    return "";
  }

 private:
  mutable std::mutex mutex_;
  std::unordered_map<std::string, int64_t> str_index_map_;
  std::unordered_map<int64_t, std::string> index_str_map_;
  int64_t last_index_;
  AtomDictionary()
    : last_index_(0) {
  }
};
AtomDictionary& AtomDictionary::getInstance() {
  static AtomDictionary instance_;
  return instance_;
}

Q to_atom(const char* cstr, int arity) {
  const int64_t id =
    AtomDictionary::getInstance().id_of_str(cstr);
  return tagvalue<TAG_ATOM>(id << 5 | arity);
}
std::string atom_str_of(Q q) {
  int64_t id = value_of<int64_t>(q) >> 5;
  return AtomDictionary::getInstance().str_of_id(id);
}
int atom_arity_of(Q q) {
  return value_of<int64_t>(q) & 0x1f;
}

std::string to_str(Q q) {
  const TAG_T tag = tag_of(q);
  std::stringstream ss;
  switch (tag) {
  case TAG_REF:
    ss << "<REF>" << ptr_of<void>(q);
    break;
  case TAG_ATOM:
    ss << "<ATOM>'" << atom_str_of(q) << "'";
    break;
  case TAG_INT:
    ss << "<INT>" << value_of<int64_t>(q);
    break;
  case TAG_LIST:
    ss << "<LIST>" << ptr_of<A>(q);
    break;
  case TAG_NIL:
    ss << "<NIL>" << ptr_of<A>(q);
    break;
  }
  return ss.str();
}

namespace reg {
  struct in {
    int index;
    in(int index) : index(index) {
    }
    operator int() {
      return index;
    }
  };
  struct x {
    int index;
    x(int index) : index(index) {
    }
    operator int() {
      return index;
    }
  };
  struct out {
    int index;
    out(int index) : index(index) {
    }
    operator int() {
      return index;
    }
  };
}  // namespace reg

#define INITIAL_REG_SIZE 256
#define HEAP_SIZE 256

class Heap {
 public:
  Heap() {
    for (size_t i = 0; i < HEAP_SIZE; ++i) {
      std::atomic_init(&heap_[i], static_cast<Q>(0));
    }
  }
  A& operator[](size_t index) {
    return heap_[index];
  }
  const A& operator[](size_t index) const {
    return heap_[index];
  }
  size_t size() const {
    return HEAP_SIZE;
  }
 private:
  std::array<A, HEAP_SIZE> heap_;
};

struct VM;

class Scheduler {
 public:
  static Scheduler& getInstance();
  void push_vm(std::shared_ptr<VM> vm) {
    vec_.push_back(vm);
  }

 private:
  std::vector<std::shared_ptr<VM> > vec_;
};

Scheduler& Scheduler::getInstance() {
  static Scheduler scheduler_;
  return scheduler_;
}

struct Context {
  Context* prev;
  int pc_continue;
  int pc_on_error;
};

enum LOG_LEVEL {
  TRACE,
  DEBUG,
  INFO,
  ERROR
};

#define log_trace(vm, args)                     \
  do {                                          \
    if (vm->log_level <= TRACE) {               \
      std::cerr << args << std::endl;           \
    }                                           \
  } while (0)
#define log_debug(vm, args)                     \
  do {                                          \
    if (vm->log_level <= DEBUG) {               \
      std::cerr << args << std::endl;           \
    }                                           \
  } while (0)
#define log_info(vm, args)                      \
  do {                                          \
    if (vm->log_level <= INFO) {                \
      std::cerr << args << std::endl;           \
    }                                           \
  } while (0)

struct VM {
  LOG_LEVEL log_level;
  bool failed;
  int pc;
  std::vector<Q> reg;
  Context* context;
  Q* in;
  Q* out;
  Context* next_context;
  size_t required;
  size_t push_pos;
  std::vector<Q> wait_list;
  Heap heap;
  size_t published;
  std::shared_ptr<VM> child;
  VM() : log_level(TRACE), failed(false), next_context(NULL),
         required(0), push_pos(0), published(0) {
    reg.resize(INITIAL_REG_SIZE);
    context = reinterpret_cast<Context*>(&reg[0]);
    context->prev = NULL;
    in = reinterpret_cast<Q*>(context + 1);
    out = in;
  }
  bool is_log_debug() const {
    return log_level <= DEBUG;
  }
  void dump() const {
    if (!is_log_debug()) {
      return;
    }
    std::cerr << "--------------------" << std::endl;
    std::cerr << "[depth] continue : on_error : goal" << std::endl;
    int depth = 0;
    for (Context* cp = context; cp != NULL; cp = cp->prev) {
      Q* in0 = reinterpret_cast<Q*>(cp + 1);
      Q goal = *in0;
      int arity = atom_arity_of(goal);
      std::stringstream ss;
      std::cerr << "[" << depth << "] "
                << cp->pc_continue << " : " << cp->pc_on_error
                << " : " << atom_str_of(goal) << "/" << arity
                << "(";
      ++depth;
      for (int i = 1; i <= arity; ++i) {
        if (i != 1) {
          std::cerr << ",";
        }
        std::cerr << to_str(in0[i]);
      }
      std::cerr << ")" << std::endl;
    }
    for (size_t i = 0;i < 20; ++i) {
      std::cerr << "reg[" << i << "] : " << to_str(reg[i]) << std::endl;
    }
    for (size_t
           i = 0;i < std::max(required, static_cast<size_t>(10)); ++i) {
      std::cerr << "IN[" << i << "] : " << to_str(in[i]) << std::endl;
    }
    for (size_t i = 0;i < published; ++i) {
      std::cerr << &heap[i] << " heap[" << i << "] : "
                << to_str(heap[i].load()) << std::endl;
    }
    std::cerr << "--------------------" << std::endl;
  }
  void create_child_vm() {
    child = std::make_shared<VM>();
    out = child->in;
  }
  void spawn_child_vm(int pc) {
    child->pc = pc;
    Scheduler::getInstance().push_vm(child);
    child.reset();
  }
  void create_new_window(size_t n) {
    next_context = reinterpret_cast<Context*>(&in[n]);
    out = reinterpret_cast<Q*>(next_context + 1);
    if (out - &reg[0] > reg.size() + 64) {
      const size_t in_offset = &in[0] - &reg[0];
      reg.resize(reg.size() * 2);
      next_context = reinterpret_cast<Context*>(&in[n]);
      out = reinterpret_cast<Q*>(next_context + 1);
    }
  }
  void switch_next_window(int target, int return_pc) {
    next_context->pc_continue = return_pc;
    next_context->prev = context;
    context = next_context;
    in = out;
    pc = target;
    in[0] = 0;
  }
  void switch_prev_window() {
    pc = context->pc_continue;
    context = context->prev;
    in = reinterpret_cast<Q*>(context + 1);
  }
  void require(int n) {
    while (&in[n] > &reg.back()) {
      const size_t sz = reg.size();
      reg.resize(sz * 2);
      log_info(this, "resize register: " <<
               sz << " to " << (2 * sz));
    }
    n += sizeof(Context);
    required = n;
    push_pos = n;
  }
  void new_heap() {
  }
  size_t heap_publishing(size_t sz) {
    if (published + sz < heap.size()) {
      return published;
    }
    new_heap();
    published = 0;
    assert(published + sz < heap.size());
    return published;
  }
  void heap_published(size_t sz) {
    assert(published + sz < heap.size());
    published += sz;
  }
  void activate() {
    wait_list.clear();
  }
  void push(Q q) {
    in[++push_pos] = q;
  }
  Q pop() {
    return in[push_pos--];
  }
  bool check_value_if(TAG_T tag, Q q) {
    const TAG_T t = tag_of(q);
    if (t == TAG_REF) {
      add_wait_list(q);
      fail();
      return false;
    }
    if (t != tag) {
      fail();
      return false;
    }
    return true;
  }
  // レジスタ Ai の値がタグ tag でなければ fail
  bool check_if(TAG_T tag, reg::in Ai) {
    const int i = Ai;
    const Q q = in[i] = deref(in[i]);
    const TAG_T t = tag_of(q);
    if (t == TAG_REF) {
      add_wait_list(q);
      fail();
      return false;
    }
    if (t != tag) {
      fail();
      return false;
    }
    return true;
  }
  // 値 q がタグ tag でなければ fail
  // tag がリストなら car/cdr を push
  bool push_value_if(TAG_T tag, Q q) {
    const TAG_T t = tag_of(q);
    if (t == TAG_REF) {
      add_wait_list(q);
      fail();
      return false;
    }
    if (t != tag) {
      fail();
      return false;
    }
    if (tag == TAG_LIST) {
      A* cons = ptr_of<A>(q);
      push((cons + 1)->load());  // cdr
      push((cons + 0)->load());  // car
      return true;
    }
    push(q);
    return true;
  }
  // レジスタ Ai の値がタグ tag でなければ fail
  // tag がリストなら car/cdr を push
  bool push_if(TAG_T tag, reg::in Ai) {
    const int i = Ai;
    const Q q = in[i] = deref(in[i]);
    const TAG_T t = tag_of(q);
    if (t == TAG_REF) {
      add_wait_list(q);
      fail();
      return false;
    }
    if (t != tag) {
      fail();
      return false;
    }
    if (tag == TAG_LIST) {
      A* cons = ptr_of<A>(q);
      push((cons + 1)->load());  // cdr
      push((cons + 0)->load());  // car
      return true;
    }
    push(q);
    return true;
  }
  void add_wait_list(Q q) {
    wait_list.push_back(q);
  }
  void fail() {
    pc = context->pc_on_error;
    context->pc_on_error = -1;
  }
  void proceed() {
    if (!wait_list.empty()) {
    }
    switch_prev_window();
  }
  bool unify(Q q1, Q q2) {
    q2 = deref(q2);
    q1 = deref(q1);
    if (q1 == q2) {
      return true;
    }
    TAG_T tag2 = tag_of(q2);
    if (tag2 == TAG_REF) {
      A* p2 = ptr_of<A>(q2);
      return p2->compare_exchange_strong(q2, q1);
    }
    TAG_T tag1 = tag_of(q1);
    if (tag1 == TAG_REF) {
      A* p1 = ptr_of<A>(q1);
      return p1->compare_exchange_strong(q1, q2);
    }
    return false;
  }
};

class RuntimeError: public std::runtime_error {
 public:
  RuntimeError() : runtime_error("GHC runtime error") {
  }
};

#define MACRO_goal(pc, goal)                                     \
  vm->in[0] = (goal);                                            \
  if (vm->is_log_debug()) {                                      \
    std::stringstream ss;                                        \
    ss << pc << ": goal("                                        \
       << atom_str_of(goal) << "/" << atom_arity_of(goal)        \
       << ") : "                                                 \
       << atom_str_of(goal) << "(";                              \
    for (int i = 1; i <= atom_arity_of(goal); ++i) {             \
      if (i != 1) {                                              \
        ss << ",";                                               \
      }                                                          \
      ss << to_str(vm->in[i]);                                   \
    }                                                            \
    ss << ")";                                                   \
    log_debug(vm, ss.str());                                     \
    vm->dump();                                                  \
  }

#define MACRO_requires(n)                                 \
  log_trace(vm, vm->pc << ": requires(" << n << ")");     \
  vm->require(n)
#define MACRO_fail vm->fail(); continue
#define MACRO_wait(Ai)                                \
  log_trace(vm, vm->pc << ": wait(" << Ai << ")");    \
  {                                                   \
    const int i = Ai;                                 \
    const Q q = deref(vm->in[i]);                     \
    vm->in[i] = q;                                    \
    const TAG_T t = tag_of(q);                        \
    if (t == TAG_REF) {                               \
      vm->add_wait_list(q);                           \
      vm->fail();                                     \
      continue;                                       \
    }                                                 \
  }
#define MACRO_wait_for(tag, Ai)                   \
  log_trace(vm, vm->pc                            \
            << ": wait_for(" << to_str(tag)       \
            << ", " << Ai << ")");                \
  {                                               \
    const int i = Ai;                             \
    const Q q = deref(vm->in[i]);                 \
    vm->in[i] = q;                                \
    const TAG_T t = tag_of(q);                    \
    if (t == TAG_REF) {                           \
      vm->add_wait_list(q);                       \
      vm->fail();                                 \
      continue;                                   \
    } else if (t != tag) {                        \
      vm->fail();                                 \
      continue;                                   \
    }                                             \
  }

#define MACRO_try_guard_else(jump_to)                                   \
  log_trace(vm, vm->pc << ": try_guard_else(" << (jump_to) << ")");     \
  vm->context->pc_on_error = (jump_to)
#define MACRO_try_guard_else_suspend                       \
  log_trace(vm, vm->pc << ": try_guard_else_suspend");     \
  vm->context->pc_on_error = -1
#define MACRO_trust_me                      \
  log_trace(vm, vm->pc << ": trust_me");    \
  vm->context->pc_on_error = -2

// call 呼び出しに備えて次レジスタウィンドウをセットアップする。
// out レジスタ位置を次レジスタウィンドウ上に設定する。
#define MACRO_seq(N)                                \
  log_trace(vm, vm->pc << ": seq(" << N << ")");    \
  vm->create_new_window(N)

// レジスタウィンドウを進め、target を呼びだす。
// このとき、return_pc を戻り先アドレスとする。
#define MACRO_call(target, return_pc)                          \
  log_trace(vm, vm->pc                                         \
            <<": call(" << target <<"," << return_pc << ")");  \
  vm->switch_next_window(target, return_pc);                   \
  continue

// spawn 呼び出しに備えて新しいコンテキストを生成する。
// out レジスタ位置を新しいコンテキスト上に設定する。
#define MACRO_par                                 \
  log_trace(vm, vm->pc << ": par");               \
  vm->create_child_vm()

// 新しいコンテストの実行開始位置を start_from に設定する。
// 新しいコンテキストをコンテキストキューに投入する。
#define MACRO_spawn(start_from)                                \
  log_trace(vm, vm->pc << ": spawn(" << start_from << ")");    \
  vm->spawn_child_vm(start_from)

// jump 呼び出しに備えて out レジスタ位置を設定する。
#define MACRO_tail(N)                             \
  log_trace(vm, vm->pc << ": tail(" << N << ")"); \
  vm->out = &vm->in[N]
// out レジスタの内容を in レジスタにコピーし、
// 制御を jump_to に移す。
#define MACRO_execute(jump_to, n)                           \
  log_trace(vm, vm->pc << ": execute(" << jump_to << ")");  \
  for (int i = 1; i <= n; ++i) {                            \
    vm->in[i] = vm->out[i];                                 \
  }                                                         \
  vm->pc = jump_to;                                         \
  continue

#define MACRO_link(jump_to)                     \
  vm->next_pc = jump_to

#define MACRO_activate                          \
  log_trace(vm, vm->pc << ": activate");        \
  vm->activate()
#define MACRO_proceed                           \
  log_trace(vm, vm->pc << ": proceed");         \
  vm->proceed();                                \
  continue
#define MACRO_return                            \
  log_trace(vm, vm->pc << ": return");          \
  vm->switch_prev_window();                     \
  continue

#define MACRO_out_variable(Vn, Oi)                              \
  log_trace(vm, vm->pc                                          \
            << ": out_variable(" << Vn << "," << Oi << ")");    \
  {                                                             \
    const size_t h = vm->heap_publishing(1);                    \
    const Q q = tagptr<TAG_REF>(&vm->heap[h]);                  \
    vm->heap[h].store(q);                                       \
    vm->out[Oi] = q;                                            \
    vm->in[Vn] = q;                                             \
    vm->heap_published(1);                                      \
  }

#define MACRO_out_value(Vn, Ai)                             \
  log_trace(vm, vm->pc                                      \
            << ": out_value(" << Vn << "," << Ai << ") :"   \
            << to_str(vm->in[Vn]));                         \
  {                                                         \
    const Q q = deref(vm->in[Vn]);                          \
    vm->in[Vn] = q;                                         \
    vm->out[Ai] = q;                                        \
  }
#define MACRO_out_constant(C, Ai)
#define MACRO_out_nil(Ai)
#define MACRO_out_list(Ai)
#define MACRO_out_structure(Fn, Ai)

#define MACRO_write_variable(Vn)
#define MACRO_write_value(Vn)
#define MACRO_write_constant(C)
#define MACRO_write_nil
#define MACRO_write_list
#define MACRO_write_structure(Fn)

#define MACRO_get_variable(Vn, Ai)
#define MACRO_get_value(Vn, Ai)
#define MACRO_get_constant(C, Ai)                                   \
  log_trace(vm, vm->pc                                              \
            << ": get_constant(" << to_str(C) << "," << Ai << ")"); \
  if (!vm->unify(C, vm->in[Ai])) {                                  \
    vm->fail();                                                     \
    continue;                                                       \
  }
  
#define MACRO_get_nil(Ai)
#define MACRO_get_list(Ai)
#define MACRO_get_structure(Fn, Ai)

#define MACRO_unify_variable(Vn)
#define MACRO_unify_value(Vn)
#define MACRO_unify_constant(C)
#define MACRO_unify_nil
#define MACRO_unify_list
#define MACRO_unify_structure(Fn)

#define MACRO_check_variable(Vn, Ai)
#define MACRO_check_value(Vn, Ai)
#define MACRO_check_constant(C, Ai)
#define MACRO_check_nil(Ai)                                 \
  log_trace(vm, vm->pc << ": check_nil(" << Ai << ")");     \
  if (!check_if(TAG_NIL, Ai)) {                             \
    continue;                                               \
  }
#define MACRO_check_list(Ai)                      \
  log_trace(vm, vm->pc                            \
            << ": check_list(" << Ai << "): "     \
            << to_str(vm->in[Ai]));               \
  if (!vm->push_if(TAG_LIST, Ai)) {               \
    continue;                                     \
  }
#define MACRO_check_structure(Fn, Ai)

#define MACRO_read_variable(Vn)                               \
  {                                                           \
    Q q = vm->pop();                                          \
    log_trace(vm, vm->pc                                      \
              << ": read_variable(" << Vn << ") : "           \
              << to_str(q));                                  \
    vm->in[Vn] = q;                                           \
  }
  
#define MACRO_read_value(Vn)
#define MACRO_read_constant(C)
#define MACRO_read_nil \
  {                                                         \
    Q q = vm->pop();                                        \
    log_trace(vm, vm->pc << ": read_nil" << to_str(q));     \
    if (!vm->check_value_if(TAG_NIL, q)) {                  \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_list                                       \
  {                                                           \
    Q q = vm->pop();                                          \
    log_trace(vm, vm->pc << ": read_list: " << to_str(q));    \
    if (!vm->push_value_if(TAG_LIST, q)) {                    \
      continue;                                               \
    }                                                         \
  }
#define MACRO_read_structure(Fn)

typedef void(*Code)(VM*);

class Program {
 public:
  void add_entry_point(Q q, int pc) {
    fun_pc_map_[q] = pc;
    std::cout << "add_entry_point: "
              << atom_str_of(q) << "/" << atom_arity_of(q)
              << " = " << pc << std::endl;
  }
  int query_entry_point(Q q) const {
    std::unordered_map<Q, int>::const_iterator
      iter = fun_pc_map_.find(q);
    if (iter == fun_pc_map_.end()) {
      return -1;
    }
    return iter->second;
  }

 private:
  std::unordered_map<Q, int> fun_pc_map_;
};

extern void setup(Program* prog);
extern void module(VM* vm);
