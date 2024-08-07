#ifndef GHC_VM_H_
#define GHC_VM_H_

#include <array>
#include <atomic>
#include <cassert>
#include <condition_variable>
#include <deque>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include "./ghc_tagutils.h"
#include "./ghc_dumpdot.h"

const char ENV_GHC_LOGLEVEL[] = "GHC_LOGLEVEL";

namespace reg {

struct in {
  int index;
  explicit in(int index) : index(index) {
  }
  operator int() {
    return index;
  }
};
struct y {
  int index;
  explicit y(int index) : index(index) {
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

#define INITIAL_CONTEXTS 256
#define INITIAL_REG_SIZE 512
#define HEAP_SIZE (256*1024)

class HeapList {
 public:
  using RawHeap = std::shared_ptr<std::array<A, HEAP_SIZE> >;
  static HeapList& getInstance();
  RawHeap allocate() {
    RawHeap r = std::make_shared<std::array<A, HEAP_SIZE> >();
    for (size_t i = 0; i < HEAP_SIZE; ++i) {
      std::atomic_init(&((*r)[i]), static_cast<Q>(0));
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
#if 0
    if (index >= HEAP_SIZE) {
      throw new std::runtime_error("out of heap");
    }
#endif
    return (*heap_)[index];
  }
  const A& operator[](size_t index) const {
#if 0
    if (index >= HEAP_SIZE) {
      throw new std::runtime_error("out of heap");
    }
#endif
    return (*heap_)[index];
  }
  size_t size() const {
    return HEAP_SIZE;
  }

 private:
  HeapList::RawHeap heap_;
};

inline std::string goal_str_of(const Q* goal) {
  const int arity = atom_arity_of(goal[0]);
  std::stringstream ss;
  ss << atom_str_of(goal[0]);
  if (arity > 0) {
    ss << "(";
    for (int i = 1; i <= arity; ++i) {
      if (i != 1) {
        ss << ", ";
      }
      ss << to_str(deref(goal[i]));
    }
    ss << ")";
  }
  return ss.str();
}
inline std::string goal_str_of(A* goal) {
  const int arity = atom_arity_of(goal[0].load());
  std::stringstream ss;
  ss << atom_str_of(goal[0].load());
  if (arity > 0) {
    ss << "(";
    for (int i = 1; i <= arity; ++i) {
      if (i != 1) {
        ss << ", ";
      }
      ss << to_str(goal[i].load());
    }
    ss << ")";
  }
  return ss.str();
}

class Scheduler {
 public:
  std::mutex mutex_;
  static Scheduler& getInstance();
  void dump_list(const char* title) {
    Q h = head.load();
    A* a = ptr_of<A>(h);
    int i = 0;
    while (a != &head) {
      A* goal = ptr_of<A>(a[1].load());
      std::cerr << i << ": " << goal_str_of(goal + 2) << std::endl;
      const Q h2 = a->load();
      a = ptr_of<A>(h2);
    }
  }
  void enqueue_list(A* list) {
    const Q h0 = head.load();
    const Q h1 = list->load();
    head.store(h1);
    list->store(h0);
    cond_.notify_one();
  }
  void wait_for_enqueue() {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock);
  }
  A* dequeue_list() {
    std::unique_lock<std::mutex> lock(mutex_);
    Q h = head.load();
    A* a = ptr_of<A>(h);
    Q h2 = a->load();
    A* a2 = ptr_of<A>(h2);
    if (a2 == a) {
      return NULL;
    }
    head.store(tagptr<TAG_REF>(a2));
    A* goal = ptr_of<A>(a[1].load());
    return goal;
  }

 private:
  std::condition_variable cond_;
  A head;
  Scheduler() {
    head.store(tagptr<TAG_REF>(&head));
  }
};

Scheduler& Scheduler::getInstance() {
  static Scheduler scheduler_;
  return scheduler_;
}

enum exec_status {
  ST_ACTIVE = 0,
  ST_IN_GUARD = 1,
  ST_SUBGOAL_IN_GUARD = 2,
};

struct Context {
  Context()
    : status(ST_IN_GUARD),
      in_offset(0),
      pc_continue(-1),
      pc_on_error(-1) {
  }
  int status;
  size_t in_offset;
  int pc_goal;  // ゴール開始プログラム位置
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

class Program;

struct VM : std::enable_shared_from_this<VM> {
  using ptr = std::shared_ptr<VM>;
  LOG_LEVEL log_level;
  int64_t inference_count;
  int64_t resume_count;
  bool failed;
  int pc;
  std::vector<Q> reg;
  Q* in;
  Q* out;
  std::vector<Context> contexts;
  Context next_context;
  size_t required;
  std::set<Q> wait_list;
  Heap heap;
  size_t published;
  using stack_t = std::stack<Q, std::vector<Q> >;
  stack_t pdl;
  VM() : inference_count(0), resume_count(0), failed(false),
         required(0), published(0) {
    const std::string llstr = upper(getenv(ENV_GHC_LOGLEVEL));
    log_level = ((llstr == "TRACE") ? TRACE :
                 (llstr == "DEBUG") ? DEBUG :
                 (llstr == "INFO") ? INFO :
                 (llstr == "ERROR") ? ERROR :
                 ERROR);
    reg.resize(INITIAL_REG_SIZE);
    contexts.reserve(INITIAL_CONTEXTS);
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
  // for built-in dump_to_dot/1
  void dump_to_dot(const std::string& dotfile) const {
    DotFile dot;
    std::ofstream st;
    st.open(dotfile);
    st << "digraph GHC {" << std::endl;
    st << "contexts [ shape = record, label = \"{";
    for (size_t i = 0; i < contexts.size(); ++i) {
      const Context& context = contexts[i];
      if (i != 0) {
        st << "|";
      }
      st << "<" << i << "> " <<
        ((context.status == ST_ACTIVE) ? "active" :
         (context.status == ST_IN_GUARD) ? "passive" : "Passive");
    }
    st << "}\" ];" << std::endl;
    for (size_t i = 0; i < contexts.size(); ++i) {
      const Context& context = contexts[i];
      st << "contexts:" << i
         << ":e -> registers:" << context.in_offset << ":w;" << std::endl;
    }
    size_t reg_max = contexts.back().in_offset;
    if (tag_of(reg[reg_max]) == TAG_ATOM) {
      reg_max += atom_arity_of(reg[reg_max]);
    }
    if (reg_max >= reg.size()) {
      reg_max = reg.size();
    }
    st << "registers [ shape = record, label = \"{";
    for (size_t i = 0; i <= reg_max; ++i) {
      const Q q = reg[i];
      dot.add_edge_from(q);
      if (i != 0) {
        st << "|";
      }
      st << "<" << i << ">" << esc(to_str(q));
    }
    st << "}\" ];" << std::endl;
    for (size_t i = 0; i <= reg_max; ++i) {
      TAG_T tag = tag_of(reg[i]);
      switch (tag) {
      case TAG_LREF:
        {
          Q* p = ptr_of<Q>(reg[i]);
          if (p != &reg[i]) {
            st << "registers:" << i <<
              ":e -> " << "registers:" << (p - &reg[0]) << ":e" << std::endl;
          }
        }
        break;
      case TAG_REF:  // fall through
      case TAG_LIST:  // fall through
      case TAG_STR:  // fall through
      case TAG_SUS:  // fall through
        {
          A* a = ptr_of<A>(reg[i]);
          if (a != NULL) {
            st << "registers:" << i <<
              " -> " << dot.getPortName(a) << std::endl;
          }
        }
        break;
      default:
        break;
      }
    }
    dot.dump_nodes(st);
    dot.dump_edges(st);
    st << "}" << std::endl;
    st.close();
  }
  // for built-in dump_to_dot/2
  void dump_to_dot(const std::string& dotfile, Q q) const {
    DotFile dot;
    dot.add_edge_from(q);
    std::ofstream st;
    st.open(dotfile);
    st << "digraph GHC {" << std::endl;
    st << "var [ shape = record, label = \"{" << esc(to_str(q)) << "}\" ];"
       << std::endl;
    const TAG_T tag = tag_of(q);
    switch (tag) {
    case TAG_REF:  // fall through
    case TAG_LIST:  // fall through
    case TAG_STR:  // fall through
    case TAG_SUS:  // fall through
      {
        A* a = ptr_of<A>(q);
        if (a != NULL) {
          st << "var -> " << dot.getPortName(a) << std::endl;
        }
      }
      break;
    default:
      break;
    }
    dot.dump_nodes(st);
    dot.dump_edges(st);
    st << "}" << std::endl;
    st.close();
  }
  void dump() const {
    std::cerr << "--------------------" << std::endl;
    dump_context();
    for (size_t i = 0; i < 20; ++i) {
      std::cerr << &reg[i] << " reg[" << std::setw(3) << i << "] : "
                << to_str(reg[i]) << std::endl;
    }
    std::cerr << "wait_list: ";
    for (Q q : wait_list) {
      std::cerr << to_str(q) << ",";
    }
    std::cerr << std::endl;
    for (size_t
           i = 0; i < std::max(required, static_cast<size_t>(10)); ++i) {
      std::cerr << &in[i] << " IN[" << std::setw(3) << i << "] : "
                << to_str(in[i]) << std::endl;
    }
    dump_heap(0, published + 1);
    std::cerr << "--------------------" << std::endl;
  }
  void dump_context() const {
    std::cerr << "[depth] continue : on_error : (reg) Goal" << std::endl;
    int depth = 0;
    for (const Context& context : contexts) {
      std::stringstream ss;
      std::cerr << "[" << std::setw(3) << depth << "] "
                << context.pc_continue
                << " : " << context.pc_on_error
                << " : (status "
                << ((context.status == ST_ACTIVE) ? "active" :
                    (context.status == ST_IN_GUARD) ? "passive" :
                    "Passive")
                << ") : (in " << context.in_offset << ")"
                << goal_str_of(&reg[context.in_offset]) << std::endl;
      ++depth;
    }
  }
  void dump_register(int index) const {
    std::cerr << " " << &in[index]
              << " IN[" << std::setw(3) << index << "] : "
              << to_str(in[index]) << std::endl;
  }
  void dump_register_out(int index) const {
    std::cerr << " " << &out[index]
              << " OUT[" << std::setw(3) << index << "] : "
              << to_str(out[index]) << std::endl;
  }
  void dump_heap(int heap_index, size_t size) const {
    for (size_t i = 0; i < size; ++i) {
      size_t h = heap_index + i;
      std::cerr << " " << &heap[h]
                << " heap[" << std::setw(3) << h << "] : "
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
  void run(void (&module)(VM::ptr, Program*), Program* prog) {
    for (;;) {
      A* goal = Scheduler::getInstance().dequeue_list();
      if (!goal) {
        break;
      }
      ++resume_count;
      Q g = goal[2].load();
      const int arity = atom_arity_of(g);
      in[0] = g;
      for (int i = 1; i <= arity; ++i) {
        in[i] = goal[2 + i].load();
      }
      Context& context = contexts.back();
      context.pc_continue = -1;
      context.pc_on_error = -1;
      pc = value_of<int>(goal[1]);
      failed = false;
      try {
        module(shared_from_this(), prog);
      } catch (const std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
        dump();
        dump_to_dot("dump/runtime_error.dot");
      }
    }
  }
  void spawn(int target_pc, Q goal) {
    const int arity = atom_arity_of(goal);
    // upgrade local-variables to heap-variables
    for (int i = 1; i <= arity; ++i) {
      Q q = deref(out[i]);
      const TAG_T tag = tag_of(q);
      if (tag == TAG_LREF) {
        q = local_to_heap(q);
      }
      out[i] = q;
    }
    const size_t h = heap_publishing(5 + arity);
    heap[h + 0].store(tagptr<TAG_REF>(&heap[h + 0]));
    heap[h + 1].store(tagptr<TAG_REF>(&heap[h + 2]));
    heap[h + 2].store(tagvalue<TAG_INT>(0));
    heap[h + 3].store(tagvalue<TAG_INT>(target_pc));
    for (int i = 0; i <= arity; ++i) {
      heap[h + 4 + i].store(ref_of(out[i]));
    }
    heap_published(5 + arity);
    A* lst = &heap[h + 0];
    Scheduler::getInstance().enqueue_list(lst);
  }
  void resize_registers(size_t sz) {
    if (sz < reg.size()) {
      return;
    }
    const Q* old_reg = &reg[0];
    reg.resize(sz);
    // update LREF addresses in register window
    const Q* new_reg = &reg[0];
    for (size_t i = 0; i < reg.size(); ++i) {
      const Q q = reg[i];
      const TAG_T tag = tag_of(q);
      if (tag == TAG_LREF && q != 0) {
        const Q* p = ptr_of<Q>(q);
        const Q lref = tagptr<TAG_LREF>(p + (new_reg - old_reg));
        reg[i] = lref;
      }
    }
    // update LREF addresses in wait list
    std::set<Q> wait_list2;
    for (Q q : wait_list) {
      const TAG_T tag = tag_of(q);
      if (tag == TAG_LREF) {
        const Q* p = ptr_of<Q>(q);
        const Q lref = tagptr<TAG_LREF>(p + (new_reg - old_reg));
        wait_list2.insert(lref);
      } else {
        wait_list2.insert(q);
      }
    }
    std::swap(wait_list, wait_list2);
  }
  void create_new_window(size_t n) {
    out = &in[n];
    next_context.in_offset = out - &reg[0];
    while (static_cast<size_t>(out - &reg[0] + 64) > reg.size()) {
#if 0
      log_trace(this, "extending register size: "
                << reg.size() << " => " << (reg.size() * 2));
#endif
      in = &reg[contexts.back().in_offset];
      out = &reg[next_context.in_offset];
    }
  }
  void switch_next_window(int target_pc, int return_pc) {
    contexts.back().pc_continue = return_pc;
    const int status = contexts.back().status;
    next_context.status =
      (status != ST_ACTIVE) ? ST_SUBGOAL_IN_GUARD : ST_IN_GUARD;
    next_context.pc_continue = target_pc;
    next_context.pc_on_error = -1;
    in = out;
    pc = target_pc;
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
    clear_pdl();
    resize_registers(contexts.back().in_offset + n);
    while (&in[contexts.back().in_offset + n] > &reg.back()) {
      const size_t sz = reg.size();
      reg.resize(sz * 2);
#if 0
      log_info(this, "resize register: " <<
               sz << " to " << (2 * sz));
#endif
      in = &reg[contexts.back().in_offset];
      out = in;
    }
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
    clear_pdl();
    if (contexts.back().status != ST_SUBGOAL_IN_GUARD) {
      wait_list.clear();
      contexts.back().status = ST_ACTIVE;
      contexts.back().pc_on_error = -3;
    } else {
      contexts.back().pc_on_error = -1;
    }
  }
  void clear_pdl() {
    stack_t empty;
    std::swap(pdl, empty);
  }
  void push(Q q) {
    pdl.push(q);
  }
  Q pop() {
    const Q q = pdl.top();
    pdl.pop();
    return q;
  }
  void add_wait_list(Q q) {
    const TAG_T tag = tag_of(q);
    if (tag == TAG_LREF) {
      assert(*ptr_of<Q>(q) == q);
    }
    wait_list.insert(q);
  }
  std::string space() {
    std::string s;
    for (const Context& context : contexts) {
      switch (context.status) {
      case ST_ACTIVE: s += '='; break;
      case ST_IN_GUARD: s += '?'; break;
      case ST_SUBGOAL_IN_GUARD: s += '+'; break;
      default:
        s += '*';
      }
    }
    s += ' ';
    return s;
  }
  void fail() {
#if 0
    log_info(this,
             std::setw(5) << pc << "        " << space()
             << "fail()");
#endif
    for (;;) {
      pc = contexts.back().pc_on_error;
      contexts.back().pc_on_error = -1;
      if (pc != -1) {
#if 0
        log_trace(this, "fail: on_error " << pc);
#endif
        break;
      }
      if (!switch_prev_window()) {
        pc = -1;
#if 0
        log_trace(this, "fail: no more prev goal: " << pc);
#endif
        break;
      }
    }
    if ((pc < 0) && (contexts.back().status == ST_IN_GUARD)) {
      bool retry_this_goal = false;
      if (!wait_list.empty()) {
        const int arity = atom_arity_of(in[0]);
        for (int i = 1; i <= arity; ++i) {
          Q q = deref(in[i]);
          const TAG_T tag = tag_of(q);
          if (tag == TAG_LREF) {
            q = local_to_heap(q);
          }
          in[i] = q;
        }
        const size_t h = heap_publishing(3 + arity);
        Q goal = tagptr<TAG_REF>(&heap[h]);
        heap[h + 0].store(tagvalue<TAG_INT>(0));
        heap[h + 1].store(tagvalue<TAG_INT>(contexts.back().pc_goal));
        for (int i = 0; i <= arity; ++i) {
          heap[h + 2 + i].store(ref_of(in[i]));
        }
        heap_published(3 + arity);
        for (Q q : wait_list) {
          // q can be upgraded by above local_to_heap or something
          q = deref(q);
          const TAG_T tag = tag_of(q);
          if (tag == TAG_LREF) {
            const size_t h = heap_publishing(3);
            const Q susp = tagptr<TAG_SUS>(&heap[h + 0]);
            const Q lst1 = tagptr<TAG_REF>(&heap[h + 1]);
            heap[h + 0].store(susp);
            heap[h + 1].store(lst1);
            heap[h + 2].store(goal);
            Q* p = ptr_of<Q>(q);
            *p = tagptr<TAG_REF>(&heap[h + 0]);
            heap_published(3);
          } else if (tag == TAG_REF) {
            const size_t h = heap_publishing(3);
            const Q susp = tagptr<TAG_SUS>(&heap[h + 0]);
            const Q lst1 = tagptr<TAG_REF>(&heap[h + 1]);
            heap[h + 0].store(susp);
            heap[h + 1].store(lst1);
            heap[h + 2].store(goal);
            A* p = ptr_of<A>(q);
            if (!p->compare_exchange_strong(q, tagptr<TAG_REF>(&heap[h + 0]))) {
              retry_this_goal = true;
              break;
            }
            heap_published(3);
          } else if (tag == TAG_SUS) {
            const size_t h = heap_publishing(2);
            Q lst1 = tagptr<TAG_REF>(&heap[h + 0]);
            heap[h + 0].store(lst1);
            heap[h + 1].store(goal);
            A* p2 = ptr_of<A>(q) + 1;
            Q lst2 = p2->load();
            if (!p2->compare_exchange_strong(lst2, lst1)) {
              retry_this_goal = true;
              break;
            }
            A* p1 = &heap[h + 0];
            if (!p1->compare_exchange_strong(lst1, lst2)) {
              retry_this_goal = true;
              break;
            }
            heap_published(2);
          } else {
            retry_this_goal = true;
            break;
          }
        }
      }
      if (retry_this_goal) {
        pc = contexts.back().pc_goal;
#if 0
        log_trace(this, "fail: retry_this_goal " << pc);
#endif
        return;
      }
      wait_list.clear();
      /*
      pc = contexts.back().pc_continue;
      contexts.back().pc_continue = -1;
      */
      for (;;) {
        if (!switch_prev_window()) {
          pc = -1;
#if 0
          log_trace(this, "fail: no more prev goal: " << pc);
#endif
          break;
        }
        pc = contexts.back().pc_continue;
        if (pc != -1) {
#if 0
          log_trace(this, "fail: on_error " << pc);
#endif
          break;
        }
      }
    }
  }
  void proceed() {
    wait_list.clear();
    if (switch_prev_window()) {
      pc = contexts.back().pc_continue;
      return;
    }
    A* goal = Scheduler::getInstance().dequeue_list();
    if (!goal) {
      log_info(this, "no queued goals");
      return;
    }
    ++resume_count;
    Q g = goal[2].load();
    const int arity = atom_arity_of(g);
    in[0] = g;
    for (int i = 1; i <= arity; ++i) {
      in[i] = goal[2 + i].load();
    }
    Context& context = contexts.back();
    context.pc_continue = -1;
    context.pc_on_error = -1;
    pc = value_of<int>(goal[1]);
  }
  void wake(Q q) {
    std::unique_lock<std::mutex> lock(Scheduler::getInstance().mutex_);
    A* lst = ptr_of<A>(q) + 1;
    Scheduler::getInstance().enqueue_list(lst);
  }
  bool equals(Q q1, Q q2) {
    q2 = deref(q2);
    q1 = deref(q1);
    if (q1 == q2) {
      return true;
    }
    TAG_T tag2 = tag_of(q2);
    if (tag2 == TAG_LREF ||
        tag2 == TAG_REF ||
        tag2 == TAG_SUS) {
      add_wait_list(q2);
      return false;
    }
    TAG_T tag1 = tag_of(q1);
    if (tag1 == TAG_LREF ||
        tag1 == TAG_REF ||
        tag1 == TAG_SUS) {
      add_wait_list(q1);
      return false;
    }
    if (tag1 != tag2) {
      return false;
    }
    switch (tag1) {
    case TAG_LIST:
      {
        A* p1 = ptr_of<A>(q1);
        A* p2 = ptr_of<A>(q2);
        if (!equals(p1[0].load(), p2[0].load())) {
          return false;
        }
        if (!equals(p1[1].load(), p2[1].load())) {
          return false;
        }
        return true;
      }
    case TAG_STR:
      {
        A* p1 = ptr_of<A>(q1);
        A* p2 = ptr_of<A>(q2);
        const Q f1 = p1[0].load();
        const Q f2 = p2[0].load();
        if (f1 != f2) {
          return false;
        }
        for (int i = 1; i <= atom_arity_of(f1); ++i) {
          if (!equals(p1[i].load(), p2[i].load())) {
            return false;
          }
        }
        return true;
      }
    default:
      return false;
    }
  }
  bool unify(Q q1, Q q2) {
    q2 = deref(q2);
    q1 = deref(q1);
    if (q1 == q2) {
      return true;
    }
    do {
      TAG_T tag1 = tag_of(q1);
      TAG_T tag2 = tag_of(q2);
      if (tag2 == TAG_LREF) {
        assert(*ptr_of<Q>(q2) == q2);
        Q* p2 = ptr_of<Q>(q2);
        if (tag1 == TAG_LREF) {
          assert(*ptr_of<Q>(q1) == q1);
          Q* p1 = ptr_of<Q>(q1);
          // lesser address has longer life...
          if (p1 < p2) {
            *p2 = q1;
          } else {
            *p1 = q2;
          }
          return true;
        }
        *p2 = q1;
        return true;
      }
      if (tag1 == TAG_LREF) {
        assert(*ptr_of<Q>(q1) == q1);
        Q* p1 = ptr_of<Q>(q1);
        *p1 = q2;
        return true;
      }
      if (tag2 == TAG_REF) {
        A* p2 = ptr_of<A>(q2);
        if (!p2->compare_exchange_strong(q2, ref_of(q1))) {
          q2 = p2->load();
          continue;
        }
        return true;
      }
      if (tag1 == TAG_REF) {
        A* p1 = ptr_of<A>(q1);
        if (!p1->compare_exchange_strong(q1, ref_of(q2))) {
          q1 = p1->load();
          continue;
        }
        return true;
      }
      if (tag2 == TAG_SUS && tag1 != TAG_SUS) {
        A* p2 = ptr_of<A>(q2);
        std::unique_lock<std::mutex> lock(Scheduler::getInstance().mutex_);
        // p2[0] = q2 <--- q2
        // p2[1]: 次の待ち要素へのリンク
        // p2[2]: ゴールレコードへのポインタ
        if (!p2->compare_exchange_strong(q2, ref_of(q1))) {
          q2 = p2->load();
          continue;
        }
        Scheduler::getInstance().enqueue_list(p2 + 1);
        return true;
      }
      if (tag1 == TAG_SUS && tag2 != TAG_SUS) {
        A* p1 = ptr_of<A>(q1);
        std::unique_lock<std::mutex> lock(Scheduler::getInstance().mutex_);
        // p1[0] = q1 <--- q1
        // p1[1]: 次の待ち要素へのリンク
        // p1[2]: ゴールレコードへのポインタ
        if (!p1->compare_exchange_strong(q1, ref_of(q2))) {
          q1 = p1->load();
          continue;
        }
        Scheduler::getInstance().enqueue_list(p1 + 1);
        return true;
      }
      if (tag1 == TAG_SUS && tag2 == TAG_SUS) {
        std::unique_lock<std::mutex> lock(Scheduler::getInstance().mutex_);
        // check again in lock
        q1 = deref(q1);
        q2 = deref(q2);
        if (tag_of(q1) != TAG_SUS ||
            tag_of(q2) != TAG_SUS) {
          continue;
        }
        // splice list
        A* p1 = ptr_of<A>(q1);
        A* p2 = ptr_of<A>(q2);
        A* lst1 = p1 + 1;
        A* lst2 = p2 + 1;
        const Q qq1 = lst1->load();
        const Q qq2 = lst2->load();
        lst1->store(qq2);
        lst2->store(qq1);
        // one references another
        p1->store(tagptr<TAG_REF>(p2));
        return true;
      }
      if (tag1 != tag2) {
        return false;
      }
      switch (tag1) {
      case TAG_LIST:
        {
          A* p1 = ptr_of<A>(q1);
          A* p2 = ptr_of<A>(q2);
          const bool is_ok = unify(p1[0].load(), p2[0].load())
            && unify(p1[1].load(), p2[1].load());
          return is_ok;
        }
      case TAG_STR:
        {
          A* p1 = ptr_of<A>(q1);
          A* p2 = ptr_of<A>(q2);
          const Q f1 = p1[0].load();
          const Q f2 = p2[0].load();
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
    } while (0);
    return false;
  }
  void copy_from_out_to_in(int arity) {
    for (int i = 1; i <= arity; ++i) {
      const Q q = deref(out[i]);
      const TAG_T tag = tag_of(q);
      in[i] = (tag == TAG_REF) ? local_to_heap(q) : q;
    }
  }
  Q local_to_heap(Q q) {
    Q* p = ptr_of<Q>(q);
    assert(*p == q);  // q must be a dereferenced local variable
    const size_t h = heap_publishing(1);
    const Q var = tagptr<TAG_REF>(&heap[h]);
    heap[h].store(var);
    heap_published(1);
    *p = var;
    return var;
  }
};

class RuntimeError: public std::runtime_error {
 public:
  RuntimeError() : runtime_error("GHC runtime error") {
  }
};

#endif  // GHC_VM_H_
