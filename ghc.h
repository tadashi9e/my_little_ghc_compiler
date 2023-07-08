#ifndef GHC_H_
#define GHC_H_
#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <atomic>
#include <cassert>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <vector>

const char ENV_GHC_LOGLEVEL[] = "GHC_LOGLEVEL";

using Q = intptr_t;
using A = std::atomic<Q>;

enum TAG_T {
  TAG_REF,
  TAG_ATOM,
  TAG_INT,
  TAG_LIST,
  TAG_NIL,
  TAG_STR,
  TAG_SUS,
  TAG_OBJ
};

std::string to_str(TAG_T tag) {
  switch (tag) {
  case TAG_REF: return "REF";
  case TAG_ATOM: return "ATOM";
  case TAG_INT: return "INT";
  case TAG_LIST: return "LIST";
  case TAG_NIL: return "NIL";
  case TAG_STR: return "STR";
  case TAG_SUS: return "SUS";
  case TAG_OBJ: return "OBJ";
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

class SymbolDictionary {
 public:
  static SymbolDictionary& getInstance();
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
  SymbolDictionary()
    : last_index_(0) {
  }
};

SymbolDictionary& SymbolDictionary::getInstance() {
  static SymbolDictionary instance_;
  return instance_;
}

Q to_atom(const char* cstr, int arity) {
  const int64_t id =
    SymbolDictionary::getInstance().id_of_str(cstr);
  return tagvalue<TAG_ATOM>(id << 5 | arity);
}
std::string atom_str_of(Q q) {
  int64_t id = value_of<int64_t>(q) >> 5;
  return SymbolDictionary::getInstance().str_of_id(id);
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
    {
      const int i = atom_arity_of(q);
      if (i != 0) {
        ss << "/" << i;
      }
    }
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
  case TAG_STR:
    ss << "<STR>" << ptr_of<A>(q);
    break;
  case TAG_SUS:
    ss << "<SUS>" << value_of<int64_t>(q);
    break;
  case TAG_OBJ:
    ss << "<OBJ>" << value_of<int64_t>(q);
    break;
  }
  return ss.str();
}

namespace reg {

struct in {
  int index;
  explicit in(int index) : index(index) {
  }
  operator int() {
    return index;
  }
};
struct x {
  int index;
  explicit x(int index) : index(index) {
  }
  operator int() {
    return index;
  }
};
struct out {
  int index;
  explicit out(int index) : index(index) {
  }
  operator int() {
    return index;
  }
};

}  // namespace reg

#define INITIAL_REG_SIZE 32
#define HEAP_SIZE 4096

class HeapList {
 public:
  using RawHeap = std::shared_ptr<std::array<A, HEAP_SIZE> >;
  static HeapList& getInstance();
  RawHeap allocate() {
    RawHeap r = std::make_shared<std::array<A, HEAP_SIZE> >();
    for (size_t i = 0; i < HEAP_SIZE; ++i) {
      std::atomic_init(&(*r)[i], static_cast<Q>(0));
    }
    heaps_.push_back(r);
    return r;
  }
 private:
  std::vector<RawHeap> heaps_;
};

HeapList& HeapList::getInstance() {
  static HeapList heap_list_;
  return heap_list_;
}

class Heap {
 public:
  Heap() {
    heap_ = HeapList::getInstance().allocate();
  }
  void fresh_heap() {
    heap_ = HeapList::getInstance().allocate();
  }
  A& operator[](size_t index) {
    if (index >= HEAP_SIZE) {
      throw new std::runtime_error("out of heap");
    }
    return (*heap_)[index];
  }
  const A& operator[](size_t index) const {
    if (index >= HEAP_SIZE) {
      throw new std::runtime_error("out of heap");
    }
    return (*heap_)[index];
  }
  size_t size() const {
    return HEAP_SIZE;
  }

 private:
  std::shared_ptr<std::array<A, HEAP_SIZE> > heap_;
};

struct VM;

class Scheduler {
 public:
  static Scheduler& getInstance();
  void push_vm(std::shared_ptr<VM> vm) {
    queue_.push_back(vm);
  }
  std::shared_ptr<VM> pop_vm() {
    if (queue_.empty()) {
      return NULL;
    }
    std::shared_ptr<VM> vm = queue_.front();
    queue_.pop_front();
    return vm;
  }

 private:
  std::deque<std::shared_ptr<VM> > queue_;
};

Scheduler& Scheduler::getInstance() {
  static Scheduler scheduler_;
  return scheduler_;
}

struct Context {
  Context()
    : in_offset(0),
      pc_continue(-1),
      pc_on_error(-1),
      push_pos(0) {
  }
  size_t in_offset;
  int pc_continue;
  int pc_on_error;
  size_t push_pos;
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

struct VM : std::enable_shared_from_this<VM> {
  using ptr = std::shared_ptr<VM>;
  LOG_LEVEL log_level;
  int64_t inferences;
  bool failed;
  int pc;
  std::vector<Q> reg;
  Q* in;
  Q* out;
  std::vector<Context> contexts;
  Context next_context;
  size_t required;
  std::vector<Q> wait_list;
  Heap heap;
  size_t published;
  std::shared_ptr<VM> child;
  VM() : inferences(0), failed(false),
         required(0), published(0) {
    const std::string logLevel = getenv(ENV_GHC_LOGLEVEL);
    log_level = ((logLevel == "ERROR") ? ERROR :
                 (logLevel == "INFO") ? INFO :
                 (logLevel == "DEBUG") ? DEBUG :
                 TRACE);
    reg.resize(INITIAL_REG_SIZE);
    contexts.push_back(Context());
    in = &reg[0];
    out = in;
  }
  bool is_log_trace() const {
    return log_level <= TRACE;
  }
  bool is_log_debug() const {
    return log_level <= DEBUG;
  }
  bool is_log_info() const {
    return log_level <= INFO;
  }
  void dump() const {
    std::cerr << "--------------------" << std::endl;
    std::cerr << "[depth] continue : on_error : (reg) Goal" << std::endl;
    int depth = 0;
    for (const Context& context : contexts) {
      const Q* in0 = &reg[context.in_offset];
      Q goal = *in0;
      const int arity = atom_arity_of(goal);
      std::stringstream ss;
      std::cerr << "[" << std::setw(3) << depth << "] "
                << context.pc_continue << " : " << context.pc_on_error
                << " : (" << context.in_offset << ")"
                << atom_str_of(goal) << "/" << arity
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
    for (size_t i = 0; i < 20; ++i) {
      std::cerr << "reg[" << std::setw(3) << i << "] : "
                << to_str(reg[i]) << std::endl;
    }
    for (size_t
           i = 0; i < std::max(required, static_cast<size_t>(10)); ++i) {
      std::cerr << "IN[" << std::setw(3) << i << "] : "
                << to_str(in[i]) << std::endl;
    }
    dump_heap(0, published + 1);
    std::cerr << "--------------------" << std::endl;
  }
  void dump_register(int reg_index) const {
    std::cerr << " IN[" << std::setw(3) << reg_index << "] : "
              << to_str(in[reg_index]) << std::endl;
  }
  void dump_register_out(int reg_index) const {
    std::cerr << " OUT[" << std::setw(3) << reg_index << "] : "
              << to_str(out[reg_index]) << std::endl;
  }
  void dump_heap(int heap_index, size_t size) const {
    for (size_t i = 0; i < size; ++i) {
      size_t h = heap_index + i;
      std::cerr << " " << &heap[h] << " heap[" << std::setw(3) << h << "] : "
                << to_str(heap[h].load()) << std::endl;
    }
  }
  void dump_heap(A* p, size_t size) const {
    for (size_t i = 0; i < size; ++i) {
      size_t h = p - &heap[0];
      std::cerr << " " << p << " heap[" << std::setw(3) << h << "] : "
                << to_str(p->load()) << std::endl;
      ++p;
    }
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
    out = &in[n];
    next_context.in_offset = out - &reg[0];
    while (static_cast<size_t>(out - &reg[0] + 64) > reg.size()) {
      reg.resize(reg.size() * 2);
      in = &reg[contexts.back().in_offset];
      out = &reg[next_context.in_offset];
    }
  }
  void switch_next_window(int target, int return_pc) {
    next_context.pc_continue = return_pc;
    next_context.pc_on_error = -1;
    in = out;
    pc = target;
    contexts.push_back(next_context);
  }
  bool switch_prev_window() {
    if (contexts.size() <= 1) {
      pc = -1;
      return false;
    }
    Context& context = contexts.back();
    pc = context.pc_continue;
    contexts.pop_back();
    in = &reg[contexts.back().in_offset];
    return true;
  }
  void require(int n) {
    while (&in[contexts.back().in_offset + n] > &reg.back()) {
      const size_t sz = reg.size();
      reg.resize(sz * 2);
      log_info(this, "resize register: " <<
               sz << " to " << (2 * sz));
      in = &reg[contexts.back().in_offset];
      out = in;
    }
    required = n;
  }
  size_t heap_publishing(size_t sz) {
    if (published + sz < heap.size()) {
      return published;
    }
    heap.fresh_heap();
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
    in[++contexts.back().push_pos] = q;
  }
  Q pop() {
    return in[contexts.back().push_pos--];
  }
  void add_wait_list(Q q) {
    wait_list.push_back(q);
  }
  void fail() {
    pc = contexts.back().pc_on_error;
    if (pc != -1) {
      return;
    }
    for (;;) {
      if (!switch_prev_window()) {
        pc = -1;
        return;
      }
      pc = contexts.back().pc_on_error;
      if (pc != -1) {
        return;
      }
    }
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
    if (tag1 != tag2) {
      return false;
    }
    switch (tag1) {
    case TAG_LIST:
      {
        A* p1 = ptr_of<A>(q1);
        A* p2 = ptr_of<A>(q1);
        return unify(p1[0].load(), p2[0].load())
          && unify(p1[1].load(), p2[1].load());
      }
    case TAG_STR:
      {
        A* p1 = ptr_of<A>(q1);
        A* p2 = ptr_of<A>(q1);
        Q f1 = p1[0].load();
        Q f2 = p2[0].load();
        if (f1 != f2) {
          return false;
        }
        for (int i = 1; i <= atom_arity_of(f1); ++i) {
          if (!unify(p1[i].load(), p2[i].load())) {
            return false;
          }
        }
        return true;
      }
    default:
      return false;
    }
  }
};

class RuntimeError: public std::runtime_error {
 public:
  RuntimeError() : runtime_error("GHC runtime error") {
  }
};

#define MACRO_goal(pc, goal)                                     \
  ++vm->inferences;                                              \
  vm->in[0] = (goal);                                            \
  if (vm->is_log_info()) {                                       \
    std::stringstream ss;                                        \
    ss << std::setw(5) << pc << ": GOAL: "                       \
       << std::string(vm->contexts.size() - 1, ' ')              \
       << atom_str_of(goal) << "(";                              \
    for (int i = 1; i <= atom_arity_of(goal); ++i) {             \
      if (i != 1) {                                              \
        ss << ",";                                               \
      }                                                          \
      ss << to_str(deref(vm->in[i]));                            \
    }                                                            \
    ss << ")";                                                   \
    log_info(vm, ss.str());                                      \
  }

#define MACRO_requires(n)                                 \
  log_trace(vm, vm->pc << ": requires(" << n << ")");     \
  vm->require(n);                                         \
  vm->contexts.back().push_pos = n + 1
#define MACRO_fail vm->fail(); continue
#define MACRO_wait(Ai)                                \
  log_trace(vm, vm->pc << ": wait(" << Ai << ")");    \
  {                                                   \
    const Q q = deref(vm->in[Ai]);                    \
    vm->in[Ai] = q;                                   \
    const TAG_T t = tag_of(q);                        \
    if (t == TAG_REF) {                               \
      vm->add_wait_list(q);                           \
      vm->fail();                                     \
      continue;                                       \
    }                                                 \
  }
#define MACRO_wait_for(tag, Ai)                   \
  {                                               \
    const Q q = deref(vm->in[Ai]);                \
    vm->in[Ai] = q;                               \
    log_trace(vm, vm->pc                          \
              << ": wait_for(" << to_str(tag)     \
              << ", " << Ai << "):"               \
              << to_str(q));                      \
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
  vm->contexts.back().pc_on_error = (jump_to)
#define MACRO_try_guard_else_suspend                       \
  log_trace(vm, vm->pc << ": try_guard_else_suspend");     \
  vm->contexts.back().pc_on_error = -1
#define MACRO_trust_me                      \
  log_trace(vm, vm->pc << ": trust_me");    \
  vm->contexts.back().pc_on_error = -2

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
#define MACRO_execute(jump_to, arity)                       \
  log_trace(vm, vm->pc << ": execute(" << jump_to << ")");  \
  for (int i = 1; i <= arity; ++i) {                        \
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

#define MACRO_put_variable(Vn, Ai)                              \
  {                                                             \
    const size_t h = vm->heap_publishing(1);                    \
    const Q q = tagptr<TAG_REF>(&vm->heap[h]);                  \
    vm->heap[h].store(q);                                       \
    vm->in[Ai] = q;                                             \
    vm->in[Vn] = q;                                             \
    vm->heap_published(1);                                      \
  }                                                             \
  log_trace(vm, vm->pc                                          \
            << ": put_variable(" << Vn << "," << Ai << ") :"    \
            << to_str(vm->in[Vn]))

#define MACRO_put_value(Vn, Ai)                             \
  log_trace(vm, vm->pc                                      \
            << ": put_value(" << Vn << "," << Ai << ") :"   \
            << to_str(vm->in[Vn]));                         \
  {                                                         \
    const Q q = deref(vm->in[Vn]);                          \
    vm->in[Vn] = q;                                         \
    vm->in[Ai] = q;                                         \
  }
#define MACRO_put_constant(C, Ai)                           \
  log_trace(vm, vm->pc                                      \
            << ": out_constant(" << to_str(C) << "," << Ai  \
            << ")");                                        \
  vm->in[Ai] = C
#define MACRO_put_nil(Ai)                       \
  log_trace(vm, vm->pc                          \
            << ": put_nil(" << Ai << ")");      \
  vm->in[Ai] = tagptr<TAG_NIL, Q>(0)
#define MACRO_put_list(Ai)                          \
  log_trace(vm, vm->pc                              \
            << ": put_list(" << Ai << ")");         \
  {                                                 \
    const size_t h = vm->heap_publishing(2);        \
    const Q q = tagptr<TAG_LIST>(&vm->heap[h]);     \
    vm->in[Ai] = q;                                 \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));    \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));    \
    vm->heap_published(2);                          \
    if (vm->is_log_trace()) {                       \
      vm->dump_register(Ai);                        \
      vm->dump_heap(h, 2);                          \
    }                                               \
  }
#define MACRO_put_structure(Fn, Ai)                               \
  log_trace(vm, vm->pc                                            \
            << ": put_structure("                                 \
            << atom_str_of(Fn) << "/" << atom_arity_of(Fn)        \
            << "," << Ai << ")");                                 \
  {                                                               \
    const int arity = atom_arity_of(Fn);                          \
    const size_t h = vm->heap_publishing(1 + arity);              \
    vm->heap[h].store(Fn);                                        \
    for (int i = arity; i > 0; --i) {                             \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
    }                                                             \
    const Q q = tagptr<TAG_STR>(&vm->heap[h]);                    \
    vm->in[Ai] = q;                                               \
    vm->heap_published(1 + arity);                                \
    if (vm->is_log_trace()) {                                     \
      vm->dump_register(Ai);                                      \
      vm->dump_heap(h, 1 + arity);                                \
    }                                                             \
  }                                                               \

#define MACRO_out_variable(Vn, Oi)                              \
  {                                                             \
    const size_t h = vm->heap_publishing(1);                    \
    const Q q = tagptr<TAG_REF>(&vm->heap[h]);                  \
    vm->heap[h].store(q);                                       \
    vm->out[Oi] = q;                                            \
    vm->in[Vn] = q;                                             \
    vm->heap_published(1);                                      \
  }                                                             \
  if (vm->is_log_trace()) {                                     \
    log_trace(vm, vm->pc                                        \
              << ": out_variable(" << Vn << "," << Oi << ") :"  \
              << to_str(vm->in[Vn]));                           \
    vm->dump_register(Vn);                                      \
    vm->dump_register_out(Oi);                                  \
  }

#define MACRO_out_value(Vn, Oi)                             \
  log_trace(vm, vm->pc                                      \
            << ": out_value(" << Vn << "," << Oi << ")");   \
  {                                                         \
    const Q q = deref(vm->in[Vn]);                          \
    vm->in[Vn] = q;                                         \
    vm->out[Oi] = q;                                        \
    if (vm->is_log_trace()) {                               \
      vm->dump_register(Vn);                                \
      vm->dump_register_out(Oi);                            \
    }                                                       \
  }
#define MACRO_out_constant(C, Oi)                           \
  log_trace(vm, vm->pc                                      \
            << ": out_constant(" << to_str(C) << "," << Oi  \
            << ")");                                        \
  vm->out[Oi] = C;                                          \
  if (vm->is_log_trace()) {                                 \
    vm->dump_register_out(Oi);                              \
  }
#define MACRO_out_nil(Oi)                       \
  log_trace(vm, vm->pc                          \
            << ": out_nil(" << Oi << ")");      \
  vm->out[Oi] = tagptr<TAG_NIL, Q>(0)
#define MACRO_out_list(Oi)                       \
  log_trace(vm, vm->pc                           \
            << ": out_list(" << Oi << ")");      \
  {                                              \
    const size_t h = vm->heap_publishing(2);     \
    const Q q = tagptr<TAG_LIST>(&vm->heap[h]);  \
    vm->out[Oi] = q;                             \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1])); \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0])); \
    vm->heap_published(2);                       \
    if (vm->is_log_trace()) {                    \
      vm->dump_register(Oi);                     \
      vm->dump_heap(h, 2);                       \
    }                                            \
  }

#define MACRO_out_structure(Fn, Oi)                               \
  log_trace(vm, vm->pc                                            \
            << ": out_structure("                                 \
            << atom_str_of(Fn) << "/" << atom_arity_of(Fn)        \
            << "," << Oi << ")");                                 \
  {                                                               \
    const int arity = atom_arity_of(Fn);                          \
    const size_t h = vm->heap_publishing(1 + arity);              \
    vm->heap[h].store(Fn);                                        \
    for (int i = arity; i > 0; --i) {                             \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
    }                                                             \
    const Q q = tagptr<TAG_STR>(&vm->heap[h]);                    \
    vm->out[Oi] = q;                                              \
    vm->heap_published(1 + arity);                                \
    if (vm->is_log_trace()) {                                     \
      vm->dump_register(Oi);                                      \
      vm->dump_heap(h, 1 + arity);                                \
    }                                                             \
  }

#define MACRO_write_variable(Vn)                                  \
  log_trace(vm, vm->pc                                            \
            << ": write_variable(" << Vn << ")");                 \
  {                                                               \
    const Q q = vm->pop();                                        \
    A* p = ptr_of<A>(q);                                          \
    p->store(q);                                                  \
    vm->in[Vn] = q;                                               \
    if (vm->is_log_trace()) {                                     \
      vm->dump_register(Vn);                                      \
      vm->dump_heap(p, 1);                                        \
    }                                                             \
  }
#define MACRO_write_value(Vn)                       \
  log_trace(vm, vm->pc                              \
            << ": write_value(" << Vn << ") :"      \
            << to_str(vm->in[Vn]));                 \
  {                                                 \
    const Q q = vm->pop();                          \
    ptr_of<A>(q)->store(vm->in[Vn]);                \
    if (vm->is_log_trace()) {                       \
      vm->dump_register(Vn);                        \
      vm->dump_heap(ptr_of<A>(q), 2);               \
    }                                               \
  }

#define MACRO_write_constant(C)                                   \
  log_trace(vm, vm->pc                                            \
            << ": write_constant(" << to_str(C) << ")");          \
  {                                                               \
    const Q q = vm->pop();                                        \
    ptr_of<A>(q)->store(C);                                       \
  }
#define MACRO_write_nil                         \
  log_trace(vm, vm->pc                          \
            << ": write_nil()");                \
  {                                             \
    const Q q = vm->pop();                      \
    A* p = ptr_of<A>(q);                        \
    p->store(tagptr<TAG_NIL, Q>(0));            \
    if (vm->is_log_trace()) {                   \
      vm->dump_heap(p, 1);                      \
    }                                           \
  }
#define MACRO_write_list                                          \
  log_trace(vm, vm->pc                                            \
            << ": write_list()");                                 \
  {                                                               \
    const size_t h = vm->heap_publishing(2);                      \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));                  \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));                  \
    const Q q = vm->pop();                                        \
    A* p = ptr_of<A>(q);                                          \
    p->store(tagptr<TAG_LIST>(&vm->heap[h + 0]));                 \
    vm->heap_published(2);                                        \
    if (vm->is_log_trace()) {                                     \
      vm->dump_heap(p, 1);                                        \
      vm->dump_heap(h, 2);                                        \
    }                                                             \
  }
#define MACRO_write_structure(Fn)                                 \
  log_trace(vm, vm->pc                                            \
            << ": write_structure("                               \
            << atom_str_of(Fn) << "/" << atom_arity_of(Fn)        \
            << ")");                                              \
  {                                                               \
    const size_t h = vm->heap_publishing(1 + atom_arity_of(Fn));  \
    vm->heap[h].store(Fn);                                        \
    for (int i = atom_arity_of(Fn); i > 0; --i) {                 \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
    }                                                             \
    const Q q = vm->pop();                                        \
    A* p = ptr_of<A>(q);                                          \
    p->store(tagptr<TAG_STR>(&vm->heap[h]));                      \
    vm->heap_published(1 + atom_arity_of(Fn));                    \
  }

#define MACRO_get_variable(Vn, Ai)                        \
  log_trace(vm, vm->pc                                    \
            << ": get_value(" << Vn << "," << Ai << ")"); \
  {                                                       \
    const Q q = deref(vm->in[Ai]);                        \
    vm->in[Ai] = q;                                       \
    vm->in[Vn] = q;                                       \
    if (vm->is_log_trace()) {                             \
      vm->dump_register(Vn);                              \
      vm->dump_register(Ai);                              \
    }                                                     \
  }
#define MACRO_get_value(Vn, Ai)                           \
  log_trace(vm, vm->pc                                    \
            << ": get_value(" << Vn << "," << Ai << "):"  \
            << to_str(vm->in[Vn]) << ","                  \
            << to_str(vm->in[Ai]));                       \
  if (!vm->unify(vm->in[Vn], vm->in[Ai])) {               \
    vm->fail();                                           \
    continue;                                             \
  }                                                       \
  if (vm->is_log_trace()) {                               \
    vm->dump_register(Vn);                                \
    vm->dump_register(Ai);                                \
  }

#define MACRO_get_constant(C, Ai)                                   \
  log_trace(vm, vm->pc                                              \
            << ": get_constant(" << to_str(C) << "," << Ai << ")"); \
  if (!vm->unify(C, vm->in[Ai])) {                                  \
    vm->fail();                                                     \
    continue;                                                       \
  }                                                                 \
  if (vm->is_log_trace()) {                                         \
    vm->dump_register(Ai);                                          \
  }

#define MACRO_get_nil(Ai)                               \
  log_trace(vm, vm->pc                                  \
            << ": get_nil(" << Ai << ")");              \
  if (!vm->unify(tagptr<TAG_NIL, Q>(0), vm->in[Ai])) {  \
    vm->fail();                                         \
    continue;                                           \
  }
#define MACRO_get_list(Ai)                        \
  log_trace(vm, vm->pc                            \
            << ": get_list(" << Ai << ")");       \
  {                                               \
    Q q = deref(vm->in[Ai]);                      \
    vm->in[Ai] = q;                               \
    const TAG_T tag = tag_of(q);                  \
    if (tag == TAG_REF) {                         \
      A* p = ptr_of<A>(q);                        \
      const size_t h = vm->heap_publishing(2);    \
      Q q0 = tagptr<TAG_REF>(&vm->heap[h + 0]);   \
      Q q1 = tagptr<TAG_REF>(&vm->heap[h + 1]);   \
      vm->heap[h + 0].store(q0);                  \
      vm->heap[h + 1].store(q1);                  \
      Q lst = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
      if (!p->compare_exchange_strong(q, lst)) {  \
        vm->fail();                               \
        continue;                                 \
      }                                           \
      vm->heap_published(2);                      \
      vm->push(q1);                               \
      vm->push(q0);                               \
      if (vm->is_log_trace()) {                   \
        vm->dump_register(Ai);                    \
        vm->dump_heap(h, 2);                      \
      }                                           \
    } else if (tag == TAG_LIST) {                 \
      A* p = ptr_of<A>(q);                        \
      vm->push((p + 1)->load());                  \
      vm->push((p + 0)->load());                  \
      if (vm->is_log_trace()) {                   \
        vm->dump_register(Ai);                    \
        vm->dump_heap(p, 2);                      \
      }                                           \
    } else {                                      \
      if (vm->is_log_trace()) {                   \
        vm->dump_register(Ai);                    \
      }                                           \
      vm->fail();                                 \
      continue;                                   \
    }                                             \
  }
#define MACRO_get_structure(Fn, Ai)             \
  throw std::runtime_error("fix me: get_structure")

#define MACRO_unify_variable(Vn)                             \
  log_trace(vm, vm->pc << ": unify_variable(" << Vn << ")"); \
  {                                                          \
    Q q = deref(vm->pop());                                  \
    vm->in[Vn] = q;                                          \
    if (vm->is_log_trace()) {                                \
      vm->dump_register(Vn);                                 \
    }                                                        \
  }
#define MACRO_unify_value(Vn)                             \
  log_trace(vm, vm->pc << ": unify_value(" << Vn << ")"); \
  {                                                       \
    Q q = vm->pop();                                      \
    if (!vm->unify(q, vm->in[Vn])) {                      \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
    if (vm->is_log_trace()) {                             \
      vm->dump_register(Vn);                              \
    }                                                     \
  }
#define MACRO_unify_constant(C)                           \
  log_trace(vm, vm->pc << ": unify_constant("             \
            << to_str(C) << ")");                         \
  {                                                       \
    Q q = vm->pop();                                      \
    if (!vm->unify(C, q)) {                               \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_nil                                   \
  log_trace(vm, vm->pc << ": unify_nil" << ")");          \
  {                                                       \
    Q q = deref(vm->pop());                               \
    if (!vm->unify(tagptr<TAG_NIL, Q>(0), q)) {           \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_list                         \
  log_trace(vm, vm->pc << ": unify_list" << ")");\
  {                                              \
    Q q = deref(vm->pop());                      \
    const TAG_T tag = tag_of(q);                 \
    if (tag == TAG_REF) {                        \
      A* p = ptr_of<A>(q);                       \
      if (vm->is_log_trace()) {                  \
        vm->dump_heap(p, 1);                     \
      }                                          \
      const size_t h = vm->heap_publishing(2);   \
      Q car = tagptr<TAG_REF>(&vm->heap[h + 0]); \
      Q cdr = tagptr<TAG_REF>(&vm->heap[h + 1]); \
      vm->heap[h + 0] = car;                     \
      vm->heap[h + 1] = cdr;                     \
      if (!p->compare_exchange_strong(q, car)) { \
        vm->fail();                              \
        continue;                                \
      }                                          \
      vm->push(cdr);                             \
      vm->push(car);                             \
      vm->heap_published(2);                     \
    } else if (tag == TAG_LIST) {                \
      A* p = ptr_of<A>(q);                       \
      vm->push((p + 1)->load());                 \
      vm->push((p + 0)->load());                 \
      if (vm->is_log_trace()) {                  \
        vm->dump_heap(p, 2);                     \
      }                                          \
    } else {                                     \
      vm->fail();                                \
      continue;                                  \
    }                                            \
  }

#define MACRO_unify_structure(Fn)                                     \
  log_trace(vm, vm->pc                                                \
              << ": unify_structure("                                 \
              << atom_str_of(Fn) << "/" << atom_arity_of(Fn) << ")"); \
  {                                                                   \
    Q q = deref(vm->pop());                                           \
    const TAG_T tag = tag_of(q);                                      \
    if (tag == TAG_REF) {                                             \
      A* p = ptr_of<A>(q);                                            \
      if (vm->is_log_trace()) {                                       \
        vm->dump_heap(p, 1);                                          \
      }                                                               \
      const int arity = atom_arity_of(Fn);                            \
      const size_t h = vm->heap_publishing(1 + arity);                \
      vm->heap[h + 0] = Fn;                                           \
      for (int i = arity; i > 0; --i) {                               \
        vm->heap[h + i] = tagptr<TAG_REF>(&vm->heap[h + i]);          \
        vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                  \
      }                                                               \
      const Q s = tagptr<TAG_STR>(&vm->heap[h]);                      \
      if (!p->compare_exchange_strong(q, s)) {                        \
        vm->fail();                                                   \
        continue;                                                     \
      }                                                               \
      vm->heap_published(1 + arity);                                  \
      if (vm->is_log_trace()) {                                       \
        vm->dump_heap(p, 1);                                          \
        vm->dump_heap(h, arity + 1);                                  \
      }                                                               \
    } else if (tag == TAG_STR) {                                      \
      A* p = ptr_of<A>(q);                                            \
      if (p->load() != Fn) {                                          \
        vm->fail();                                                   \
        continue;                                                     \
      }                                                               \
      const int arity = atom_arity_of(Fn);                            \
      for (int i = arity; i > 0; --i) {                               \
        vm->push(p[i].load());                                        \
      }                                                               \
      if (vm->is_log_trace()) {                                       \
        vm->dump_heap(p, arity + 1);                                  \
      }                                                               \
    } else {                                                          \
      vm->fail();                                                     \
      continue;                                                       \
    }                                                                 \
  }

#define MACRO_check_variable(Vn, Ai)                 \
  log_trace(vm, vm->pc << ": check_variable(" << Vn  \
            << "," << Ai << ")");                    \
  {                                                  \
    vm->in[Vn] = vm->in[Ai] = deref(vm->in[Ai]);     \
  }                                                  \
  if (vm->is_log_trace()) {                          \
    vm->dump_register(Vn);                           \
    vm->dump_register(Ai);                           \
  }

#define MACRO_check_value(Vn, Ai)                    \
  throw std::runtime_error("fix me: check_value")

#define MACRO_check_constant(C, Ai)                         \
  log_trace(vm, vm->pc << ": check_constant(" << to_str(C)  \
            << "," << Ai << ")");                           \
  {                                                         \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);             \
    const TAG_T t = tag_of(q);                              \
    if (t == TAG_REF) {                                     \
      vm->add_wait_list(q);                                 \
      fail();                                               \
      continue;                                             \
    }                                                       \
    if (q != C) {                                           \
      fail();                                               \
      continue;                                             \
    }                                                       \
  }
  
#define MACRO_check_nil(Ai)                                 \
  log_trace(vm, vm->pc << ": check_nil(" << Ai << ")");     \
  {                                                         \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);             \
    const TAG_T t = tag_of(q);                              \
    if (t == TAG_REF) {                                     \
      vm->add_wait_list(q);                                 \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
    if (t != TAG_NIL) {                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
    if (vm->is_log_trace()) {                               \
      vm->dump_register(Ai);                                \
    }                                                       \
  }
#define MACRO_check_list(Ai)                      \
  log_trace(vm, vm->pc                            \
            << ": check_list(" << Ai << ")");     \
  {                                               \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);   \
    const TAG_T t = tag_of(q);                    \
    if (t == TAG_REF) {                           \
      vm->add_wait_list(q);                       \
      vm->fail();                                 \
      continue;                                   \
    }                                             \
    if (t != TAG_LIST) {                          \
      vm->fail();                                 \
      continue;                                   \
    }                                             \
    A* p = ptr_of<A>(q);                          \
    vm->push((p + 1)->load());                    \
    vm->push((p + 0)->load());                    \
    if (vm->is_log_trace()) {                     \
      vm->dump_register(Ai);                      \
      vm->dump_heap(p, 2);                        \
    }                                             \
  }

#define MACRO_check_structure(Fn, Ai)                      \
  log_trace(vm, vm->pc                                     \
            << ": check_structure("                        \
            << atom_str_of(Fn) << "/" << atom_arity_of(Fn) \
            << "," << Ai << "): "                          \
            << to_str(vm->in[Ai]));                        \
  {                                                        \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);            \
    const TAG_T t = tag_of(q);                             \
    if (t == TAG_REF) {                                    \
      vm->add_wait_list(q);                                \
      vm->fail();                                          \
      continue;                                            \
    }                                                      \
    if (t != TAG_STR) {                                    \
      vm->fail();                                          \
      continue;                                            \
    }                                                      \
    A* p = ptr_of<A>(q);                                   \
    if (p->load() != Fn) {                                 \
      vm->fail();                                          \
      continue;                                            \
    }                                                      \
    const int arity = atom_arity_of(Fn);                   \
    for (int i = arity; i > 0; --i) {                      \
      vm->push((p + i)->load());                           \
    }                                                      \
    if (vm->is_log_trace()) {                              \
      vm->dump_register(Ai);                               \
      vm->dump_heap(p, 1 + arity);                         \
    }                                                      \
  }

#define MACRO_read_variable(Vn)                               \
  {                                                           \
    Q q = deref(vm->pop());                                   \
    log_trace(vm, vm->pc                                      \
              << ": read_variable(" << Vn << ") : "           \
              << to_str(q));                                  \
    vm->in[Vn] = q;                                           \
  }                                                           \
  if (vm->is_log_trace()) {                                   \
    vm->dump_register(Vn);                                    \
  }

#define MACRO_read_value(Vn)                                \
  log_trace(vm, vm->pc << ": read_value(" << Vn << ")");    \
  {                                                         \
    Q q = deref(vm->pop());                                 \
    const TAG_T t = tag_of(q);                              \
    if (t == TAG_REF) {                                     \
      vm->add_wait_list(q);                                 \
      fail();                                               \
      continue;                                             \
    }                                                       \
    Q q2 = deref(vm->in[Vn]);                               \
    if (q != q2) {                                          \
      fail();                                               \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_constant(C)                              \
  log_trace(vm, vm->pc << ": read_constant("                \
            << to_str(C) << ")");                           \
  {                                                         \
    Q q = deref(vm->pop());                                 \
    const TAG_T t = tag_of(q);                              \
    if (t == TAG_REF) {                                     \
      vm->add_wait_list(q);                                 \
      fail();                                               \
      continue;                                             \
    }                                                       \
    if (q != C) {                                           \
      fail();                                               \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_nil                                      \
  {                                                         \
    Q q = deref(vm->pop());                                 \
    log_trace(vm, vm->pc << ": read_nil" << to_str(q));     \
    const TAG_T t = tag_of(q);                              \
    if (t == TAG_REF) {                                     \
      vm->add_wait_list(q);                                 \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
    if (t != TAG_NIL) {                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_list                                       \
  {                                                           \
    Q q = deref(vm->pop());                                   \
    log_trace(vm, vm->pc << ": read_list: " << to_str(q));    \
    const TAG_T t = tag_of(q);                                \
    if (t == TAG_REF) {                                       \
      vm->add_wait_list(q);                                   \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    if (t != TAG_LIST) {                                      \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    A* p = ptr_of<A>(q);                                      \
    vm->push((p + 1)->load());                                \
    vm->push((p + 0)->load());                                \
    if (vm->is_log_trace()) {                                 \
      vm->dump_heap(p, 2);                                    \
    }                                                         \
  }
#define MACRO_read_structure(Fn)                    \
  throw std::runtime_error("fix me: read_structure")

class Program {
 public:
  void add_entry_point(Q q, int pc) {
    fun_pc_map_[q] = pc;
    /*
    std::cerr << "add_entry_point: "
              << atom_str_of(q) << "/" << atom_arity_of(q)
              << " = " << pc << std::endl;
    */
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
extern void module(VM::ptr vm, Program* prog);

#endif  // GHC_H_
