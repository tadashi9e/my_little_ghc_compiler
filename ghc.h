#ifndef GHC_H_
#define GHC_H_
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <condition_variable>
#include <cassert>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
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
    if (tag != TAG_REF && tag != TAG_SUS) {
      break;
    }
    A* a = ptr_of<A>(q);
    const Q q2 = a->load();
    if (q == q2) {
      break;
    }
    q = q2;
  }
  return q;
}

struct VM;

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
    ss << "<SUS>" << ptr_of<A>(q);
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
  HeapList::RawHeap heap_;
};

std::string goal_str_of(const Q* goal) {
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
std::string goal_str_of(A* goal) {
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
      pc_on_error(-1),
      push_pos(0) {
  }
  int status;
  size_t in_offset;
  int pc_goal;  // ゴール開始プログラム位置
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

std::string upper(const char* s) {
  if (s == NULL) {
    return "";
  }
  std::string str = std::string(s);
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::toupper(c); });
  return str;
}

struct PortGroup {
  using ptr = std::shared_ptr<PortGroup>;
  A* a;
  int n;
  PortGroup() : a(0), n(0) {
  }
  void add(ptr p) {
    A* new_a = std::min(a, p->a);
    int new_n = std::max(&a[n], &p->a[p->n]) - new_a;
    a = new_a;
    n = new_n;
  }
  bool contains(A* addr) {
    return (addr >= a) && (addr < a + n);
  }
};
class PortGroupSet {
 public:
  bool add_group(A* a, int n) {
    PortGroup::ptr group = std::make_shared<PortGroup>();
    group->a = a;
    group->n = n;
    bool b = false;
    for (int i = 0; i < n; ++i) {
      A* a2 = a + i;
      std::map<A*, PortGroup::ptr>::iterator
        iter = map_.find(a2);
      if (iter == map_.end()) {
        b = true;
        continue;
      }
      group->add(iter->second);
    }
    for (int i = 0; i < group->n; ++i) {
      map_[group->a + i] = group;
    }
    return b;
  }
  PortGroup::ptr seek(A* a) {
    for (std::map<A*, PortGroup::ptr>::value_type&
           v: map_) {
      PortGroup::ptr group = v.second;
      if (group->contains(a)) {
        return group;
      }
    }
    PortGroup::ptr group = std::make_shared<PortGroup>();
    group->a = a;
    group->n = 1;
    return group;
  }
  std::set<PortGroup::ptr> getGroupSet() {
    std::set<PortGroup::ptr> groups;
    for (std::map<A*, PortGroup::ptr>::value_type&
           v: map_) {
      PortGroup::ptr group = v.second;
      groups.insert(group);
    }
    return groups;
  }

 private:
  std::map<A*, PortGroup::ptr> map_;
};

/*
 * dot ファイル向けに '<' および '>' をエスケープする。
 */
std::string esc(const std::string& s0) {
  std::string s;
  for (char c : s0) {
    switch (c) {
    case'<': s += "\\<"; break;
    case'>': s += "\\>"; break;
    default: s += c;
    }
  }
  return s;
}
class DotFile {
 public:
  void add_edge_from(A* a) {
    const Q q = a->load();
    const TAG_T tag = tag_of(q);
    switch (tag) {
    case TAG_REF:  // fall thgourh
    case TAG_LIST:  // fall thgourh
    case TAG_STR:  // fall thgourh
    case TAG_SUS:  // fall thgourh
    case TAG_OBJ:
      {
        A* a2 = ptr_of<A>(q);
        if (a2 != NULL) {
          add_edge(a, a2);
          add_edge_from(q);
        }
      }
      break;
    default:
      break;
    }
  }
  void add_edge_from(Q q) {
    const TAG_T tag = tag_of(q);
    switch (tag) {
    case TAG_REF:
      {
        A* a = ptr_of<A>(q);
        if (a == NULL) {
          return;
        }
        add_ref_port(a);
      }
      break;
    case TAG_LIST:
      {
        A* a = ptr_of<A>(q);
        if (a == NULL) {
          return;
        }
        add_list_port(a);
      }
      break;
    case TAG_STR:
      {
        A* a = ptr_of<A>(q);
        if (a == NULL) {
          return;
        }
        add_str_port(a);
      }
      break;
    case TAG_SUS:
      {
        A* a = ptr_of<A>(q);
        if (a == NULL) {
          return;
        }
        add_sus_port(a);
      }
      break;
    default:
      break;
    }
  }
  std::string getPortName(A* a) {
    PortGroup::ptr group = portGroupSet.seek(a);
    std::stringstream ss;
    ss << "ref_" << group->a << ":" << (a-(group->a));
    return ss.str();
  }
  void dump_nodes(std::ofstream& st) {
    for (PortGroup::ptr group : portGroupSet.getGroupSet()) {
      st << "ref_" << group->a << " [ shape = record, label = \"{";
      for (int i = 0; i < group->n; ++i) {
        const Q q = group->a[i].load();
        if (i != 0) {
          st << "|";
        }
        st << "<" << i << ">" << esc(to_str(q));
      }
      st << "}\"];"<< std::endl;
    }
  }
  void dump_edges(std::ofstream& st) {
    for (const std::pair<A*, A*>& edge : edges) {
      if (edge.first == edge.second) {
        st << getPortName(edge.first) << ":e -> "
           << getPortName(edge.second) << ":e" <<std::endl;
      } else {
        st << getPortName(edge.first) << " -> "
           << getPortName(edge.second) << std::endl;
      }
    }
  }

 private:
  std::set<std::pair<A*, A*> > edges;
  PortGroupSet portGroupSet;
  void add_edge(A* a1, A* a2) {
    edges.insert(std::make_pair(a1, a2));
  }
  void add_ref_port(A* a) {
    if (portGroupSet.add_group(a, 1)) {
      add_edge_from(a);
    }
  }
  void add_list_port(A* a) {
    if (portGroupSet.add_group(a, 2)) {
      add_edge_from(&a[0]);
      add_edge_from(&a[1]);
    }
  }
  void add_str_port(A* a) {
    const Q q = a->load();
    const int arity = atom_arity_of(q);
    if (portGroupSet.add_group(a, 1 + arity)) {
      for (int i = 1; i <= arity; ++i) {
        add_edge_from(&a[i]);
      }
    }
  }
  void add_sus_port(A* a) {
    const Q q = a->load();
    if (tag_of(q) != TAG_SUS ||
        ptr_of<A>(q) != a) {
      // 自己参照ループでない
      portGroupSet.add_group(a, 1);
      add_edge_from(a);
      return;
    }
    // 自己参照ループである
    if (portGroupSet.add_group(a, 3)) {
      for (int i = 0; i < 3; ++i) {
        add_edge_from(&a[i]);
      }
      // ゴールレコード
      // 0: フラグ
      // 1: pc
      // 2: fun/n
      // 3: args...
      A* goal = ptr_of<A>(a[2].load());
      const int arity = atom_arity_of(goal[2].load());
      if (portGroupSet.add_group(goal, 2 + arity + 1)) {
        for (int i = 1; i <= arity; ++i) {
          add_edge_from(&goal[2 + i]);
        }
      }
      // リストを辿って表示
      A* lst = &a[1];
      int link_max = 0;  // for safety
      for (A* p = ptr_of<A>(lst->load()); p != lst;
           p = ptr_of<A>(p->load())) {
        if (link_max > 10) {
          break;
        }
        ++link_max;
        portGroupSet.add_group(p, 2);
        add_edge_from(&p[0]);
        add_edge_from(&p[1]);
        A* goal = ptr_of<A>(p[1].load());
        const int arity = atom_arity_of(goal[2].load());
        if (portGroupSet.add_group(goal, 2 + arity + 1)) {
          for (int i = 1; i <= arity; ++i) {
            add_edge_from(&goal[2 + i]);
          }
        }
      }
    }
  }
};

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
  VM() : inference_count(0), resume_count(0), failed(false),
         required(0), published(0) {
    const std::string llstr = upper(getenv(ENV_GHC_LOGLEVEL));
    log_level = ((llstr == "TRACE") ? TRACE :
                 (llstr == "DEBUG") ? DEBUG :
                 (llstr == "INFO") ? INFO :
                 (llstr == "ERROR") ? ERROR :
                 ERROR);
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
      case TAG_REF:  // fall through
      case TAG_LIST:  // fall through
      case TAG_STR:  // fall through
      case TAG_SUS:  // fall through
      case TAG_OBJ:
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
    case TAG_OBJ:
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
        in[i] = deref(goal[2 + i].load());
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
        // dump_to_dot("dump/runtime_error.dot");
      }
    }
  }
  void create_new_window(size_t n) {
    out = &in[n];
    next_context.in_offset = out - &reg[0];
    while (static_cast<size_t>(out - &reg[0] + 64) > reg.size()) {
      log_trace(this, "extending register size: "
                << reg.size() << " => " << (reg.size() * 2));
      reg.resize(reg.size() * 2);
      in = &reg[contexts.back().in_offset];
      out = &reg[next_context.in_offset];
    }
    log_trace(this, "IN = " << &in[0]);
    log_trace(this, "OUT = " << &out[0]);
  }
  void switch_next_window(int target, int return_pc) {
    contexts.back().pc_continue = return_pc;
    const int status = contexts.back().status;
    next_context.status =
      (status != ST_ACTIVE) ? ST_SUBGOAL_IN_GUARD : ST_IN_GUARD;
    next_context.pc_continue = target;
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
    if (contexts.back().status != ST_SUBGOAL_IN_GUARD) {
      wait_list.clear();
      contexts.back().status = ST_ACTIVE;
      contexts.back().pc_on_error = -3;
    } else {
      contexts.back().pc_on_error = -1;
    }
  }
  void push(Q q) {
    in[++contexts.back().push_pos] = q;
  }
  Q pop() {
    return in[contexts.back().push_pos--];
  }
  void add_wait_list(Q q) {
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
    log_info(this,
             std::setw(5) << pc << "        " << space()
             << "fail()");
    for (;;) {
      pc = contexts.back().pc_on_error;
      contexts.back().pc_on_error = -1;
      if (pc != -1) {
        log_trace(this, "fail: on_error " << pc);
        break;
      }
      if (!switch_prev_window()) {
        pc = -1;
        log_trace(this, "fail: no more prev goal: " << pc);
        break;
      }
    }
    if ((pc < 0) && (contexts.back().status == ST_IN_GUARD)) {
      bool retry_this_goal = false;
      if (!wait_list.empty()) {
        const int arity = atom_arity_of(in[0]);
        const size_t h = heap_publishing(3 + arity);
        Q goal = tagptr<TAG_REF>(&heap[h]);
        heap[h + 0].store(tagvalue<TAG_INT>(0));
        heap[h + 1].store(tagvalue<TAG_INT>(contexts.back().pc_goal));
        for (int i = 0; i <= arity; ++i) {
          heap[h + 2 + i].store(in[i]);
        }
        if (is_log_trace()) {
          dump_heap(h, 3 + arity);
        }
        heap_published(3 + arity);
        for (Q q : wait_list) {
          log_info(this,
                   std::setw(5) << contexts.back().pc_goal
                   << "        " << space()
                   << "+ suspend: " << to_str(q)
                   << " goal:"
                   << goal_str_of(&reg[contexts.back().in_offset]));
          const TAG_T tag = tag_of(q);
          if (tag == TAG_REF) {
            const size_t h = heap_publishing(3);
            heap[h + 0].store(tagptr<TAG_SUS>(&heap[h + 0]));
            heap[h + 1].store(tagptr<TAG_REF>(&heap[h + 1]));
            heap[h + 2].store(goal);
            A* p = ptr_of<A>(q);
            if (!p->compare_exchange_strong(q, tagptr<TAG_REF>(&heap[h + 0]))) {
              retry_this_goal = true;
              break;
            }
            heap_published(3);
            if (is_log_trace()) {
              dump_heap(p, 1);
              dump_heap(h, 3);
            }
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
            if (is_log_trace()) {
              dump_heap(p2, 1);
              dump_heap(h, 2);
            }
          }
        }
      }
      if (retry_this_goal) {
        pc = contexts.back().pc_goal;
        log_trace(this, "fail: retry_this_goal " << pc);
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
          log_trace(this, "fail: no more prev goal: " << pc);
          break;
        }
        pc = contexts.back().pc_continue;
        if (pc != -1) {
          log_trace(this, "fail: on_error " << pc);
          break;
        }
      }
    }
  }
  void proceed() {
    log_info(this,
             std::setw(5) << pc
             << "        " << space()
             << "proceed()");
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
      in[i] = deref(goal[2 + i].load());
    }
    Context& context = contexts.back();
    context.pc_continue = -1;
    context.pc_on_error = -1;
    pc = value_of<int>(goal[1]);
    log_info(this,
             std::setw(5) << pc
             << "        " << space()
             << "retrying " << to_str(g));
    if (is_log_trace()) {
      for (int i = 0; i <= arity; ++i) {
        dump_register(i);
      }
    }
    log_info(this, "dequeued goal " << to_str(g));
  }
  void wake(Q q) {
    std::unique_lock<std::mutex> lock(Scheduler::getInstance().mutex_);
    A* lst = ptr_of<A>(q) + 1;
    Scheduler::getInstance().enqueue_list(lst);
  }
  bool unify(Q q1, Q q2) {
    q2 = deref(q2);
    q1 = deref(q1);
    if (q1 == q2) {
      return true;
    }
    do {
      TAG_T tag2 = tag_of(q2);
      if (tag2 == TAG_REF) {
        A* p2 = ptr_of<A>(q2);
        if (!p2->compare_exchange_strong(q2, q1)) {
          q2 = p2->load();
          continue;
        }
        return true;
      }
      TAG_T tag1 = tag_of(q1);
      if (tag1 == TAG_REF) {
        A* p1 = ptr_of<A>(q1);
        if (!p1->compare_exchange_strong(q1, q2)) {
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
        if (!p2->compare_exchange_strong(q2, q1)) {
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
        if (!p1->compare_exchange_strong(q1, q2)) {
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
};

class RuntimeError: public std::runtime_error {
 public:
  RuntimeError() : runtime_error("GHC runtime error") {
  }
};

#define MACRO_goal(pc, goal)                                     \
  ++vm->inference_count;                                         \
  vm->contexts.back().pc_goal = pc;                              \
  vm->in[0] = (goal);                                            \
  if (vm->is_log_info()) {                                       \
    log_info(vm, std::setw(5) << pc << ": GOAL: "                \
             << vm->space()                                      \
             << goal_str_of(vm->in));                            \
    if (vm->is_log_trace()) {                                    \
      vm->dump();                                                \
    }                                                            \
  }

#define MACRO_requires(n)                                 \
  log_trace(vm, vm->pc << ": requires(" << n << ")");     \
  vm->require(n);                                         \
  vm->contexts.back().push_pos = n + 1
#define MACRO_fail vm->fail(); continue
#define MACRO_wait(Ai)                                \
  log_trace(vm, vm->pc << ": wait(" << Ai << ")");    \
  {                                                   \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);       \
    const TAG_T t = tag_of(q);                        \
    if (t == TAG_REF || t == TAG_SUS) {               \
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
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);   \
    const TAG_T t = tag_of(q);                    \
    if (t == TAG_REF || t == TAG_SUS) {           \
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
  vm->contexts.back().pc_on_error = -2
#define MACRO_otherwise                      \
  log_trace(vm, vm->pc << ": otherwise");    \
  if (!vm->wait_list.empty()) {              \
    vm->contexts.back().pc_on_error = -2;    \
    vm->fail();                              \
    continue;                                \
  }

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
#define MACRO_par(N)                              \
  log_trace(vm, vm->pc << ": par(" << N << ")");  \
  vm->create_new_window(N)

// 新しいコンテストの実行開始位置を start_from に設定する。
// 新しいコンテキストをコンテキストキューに投入する。
#define MACRO_spawn(target, return_pc)                          \
  log_trace(vm, vm->pc                                         \
            <<": spawn(" << target <<"," << return_pc << ")");  \
  vm->switch_next_window(target, return_pc);                   \
  continue

// jump 呼び出しに備えて out レジスタ位置を設定する。
#define MACRO_tail(N)                             \
  log_trace(vm, vm->pc << ": tail(" << N << ")"); \
  vm->out = &vm->in[N]
// out レジスタの内容を in レジスタにコピーし、
// 制御を jump_to に移す。
#define MACRO_execute(jump_to, arity)                       \
  log_trace(vm, vm->pc << ": execute(" << jump_to << ")");  \
  for (int i = 1; i <= (arity); ++i) {                      \
    vm->in[i] = vm->out[i];                                 \
  }                                                         \
  vm->pc = (jump_to);                                       \
  vm->contexts.back().pc_continue = -1;                     \
  vm->contexts.back().status =                              \
    (vm->contexts.back().status != ST_ACTIVE)               \
    ? ST_SUBGOAL_IN_GUARD : ST_IN_GUARD;                    \
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
  vm->pc = vm->contexts.back().pc_continue;     \
  continue

#define MACRO_set_variable(Ai)                  \
  {                                             \
    const size_t h = vm->heap_publishing(1);    \
    const Q q = tagptr<TAG_REF>(&vm->heap[h]);  \
    vm->heap[h].store(q);                       \
    vm->in[Ai] = q;                             \
    vm->heap_published(1);                      \
  }                                             \
  log_trace(vm, vm->pc                          \
            << ": set_variable(" << Ai << ")"); \
  if (vm->is_log_trace()) {                     \
    vm->dump_register(Ai);                      \
  }

#define MACRO_set_value(Vn, Ai)                             \
  log_trace(vm, vm->pc                                      \
            << ": set_value(" << Vn << "," << Ai << ")");   \
  {                                                         \
    const Q q = deref(vm->in[Vn]);                          \
    vm->in[Vn] = q;                                         \
    vm->in[Ai] = q;                                         \
  }                                                         \
  if (vm->is_log_trace()) {                                 \
    vm->dump_register(Vn);                                  \
    vm->dump_register(Ai);                                  \
  }
#define MACRO_set_constant(C, Ai)                           \
  log_trace(vm, vm->pc                                      \
            << ": set_constant(" << to_str(C) << "," << Ai  \
            << ")");                                        \
  vm->in[Ai] = C;                                           \
  if (vm->is_log_trace()) {                                 \
    vm->dump_register(Ai);                                  \
  }
#define MACRO_set_nil(Ai)                  \
  log_trace(vm, vm->pc                     \
            << ": set_nil(" << Ai << ")"); \
  vm->in[Ai] = tagptr<TAG_NIL, Q>(0);      \
  if (vm->is_log_trace()) {                \
    vm->dump_register(Ai);                 \
  }
#define MACRO_set_list(Ai)                          \
  log_trace(vm, vm->pc                              \
            << ": set_list(" << Ai << ")");         \
  {                                                 \
    const size_t h = vm->heap_publishing(2);        \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));    \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));    \
    const Q q = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
    vm->in[Ai] = q;                                 \
    vm->heap_published(2);                          \
    if (vm->is_log_trace()) {                       \
      vm->dump_register(Ai);                        \
      vm->dump_heap(h, 2);                          \
    }                                               \
  }
#define MACRO_set_structure(Fn, Ai)                               \
  log_trace(vm, vm->pc                                            \
            << ": set_structure("                                 \
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
  vm->out[Oi] = tagptr<TAG_NIL, Q>(0);           \
  if (vm->is_log_trace()) {                      \
    vm->dump_register_out(Oi);                   \
  }                                              \

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
      vm->dump_register_out(Oi);                 \
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
    vm->heap[h + 0].store(Fn);                                    \
    for (int i = arity; i > 0; --i) {                             \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
      log_trace(vm, "push: " << &vm->heap[h + i]);                \
    }                                                             \
    const Q q = tagptr<TAG_STR>(&vm->heap[h]);                    \
    vm->out[Oi] = q;                                              \
    vm->heap_published(1 + arity);                                \
    if (vm->is_log_trace()) {                                     \
      vm->dump_register_out(Oi);                                  \
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
    ptr_of<A>(q)->store(deref(vm->in[Vn]));         \
    if (vm->is_log_trace()) {                       \
      vm->dump_register(Vn);                        \
      vm->dump_heap(ptr_of<A>(q), 1);               \
    }                                               \
  }

#define MACRO_write_constant(C)                           \
  log_trace(vm, vm->pc                                    \
            << ": write_constant(" << to_str(C) << ")");  \
  {                                                       \
    const Q q = vm->pop();                                \
    A* p = ptr_of<A>(q);                                  \
    p->store(C);                                          \
    if (vm->is_log_trace()) {                             \
      vm->dump_heap(p, 1);                                \
    }                                                     \
  }
#define MACRO_write_nil                         \
  log_trace(vm, vm->pc << ": write_nil()");     \
  {                                             \
    const Q q = vm->pop();                      \
    A* p = ptr_of<A>(q);                        \
    p->store(tagptr<TAG_NIL, Q>(0));            \
    if (vm->is_log_trace()) {                   \
      vm->dump_heap(p, 1);                      \
    }                                           \
  }
#define MACRO_write_list                                          \
  log_trace(vm, vm->pc << ": write_list()");                      \
  {                                                               \
    const Q q = vm->pop();                                        \
    const size_t h = vm->heap_publishing(2);                      \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));                  \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));                  \
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
    const Q q = vm->pop();                                        \
    const int arity = atom_arity_of(Fn);                          \
    const size_t h = vm->heap_publishing(1 + arity);              \
    vm->heap[h].store(Fn);                                        \
    for (int i = arity; i > 0; --i) {                             \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
    }                                                             \
    A* p = ptr_of<A>(q);                                          \
    p->store(tagptr<TAG_STR>(&vm->heap[h]));                      \
    vm->heap_published(1 + arity);                                \
  }
#define MACRO_write_void                        \
  {                                             \
    const Q q = vm->pop();                      \
    A* p = ptr_of<A>(q);                        \
    p->store(q);                                \
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
#define MACRO_get_list(Ai)                                \
  log_trace(vm, vm->pc << ": get_list(" << Ai << ")");    \
  {                                                       \
    bool failed = false;                                  \
    do {                                                  \
      Q q = deref(vm->in[Ai]);                            \
      vm->in[Ai] = q;                                     \
      const TAG_T tag = tag_of(q);                        \
      if (tag == TAG_LIST) {                              \
        A* p = ptr_of<A>(q);                              \
        vm->push(p[1].load());                            \
        vm->push(p[0].load());                            \
        if (vm->is_log_trace()) {                         \
          vm->dump_register(Ai);                          \
          vm->dump_heap(p, 2);                            \
        }                                                 \
      } else if (tag == TAG_REF || tag == TAG_SUS) {      \
        A* p = ptr_of<A>(q);                              \
        const size_t h = vm->heap_publishing(2);          \
        Q q0 = tagptr<TAG_REF>(&vm->heap[h + 0]);         \
        Q q1 = tagptr<TAG_REF>(&vm->heap[h + 1]);         \
        vm->heap[h + 0].store(q0);                        \
        vm->heap[h + 1].store(q1);                        \
        Q lst = tagptr<TAG_LIST>(&vm->heap[h + 0]);       \
        if (!p->compare_exchange_strong(q, lst)) {        \
          failed = true;                                  \
          break;                                          \
        }                                                 \
        if (tag == TAG_SUS) {                             \
          vm->wake(q);                                    \
        }                                                 \
        vm->heap_published(2);                            \
        vm->push(q1);                                     \
        vm->push(q0);                                     \
        if (vm->is_log_trace()) {                         \
          vm->dump_register(Ai);                          \
          vm->dump_heap(h, 2);                            \
        }                                                 \
      } else {                                            \
        if (vm->is_log_trace()) {                         \
          vm->dump_register(Ai);                          \
        }                                                 \
        failed = true;                                    \
      }                                                   \
    } while (0);                                          \
    if (failed) {                                         \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_get_structure(Fn, Ai)                             \
  log_trace(vm, vm->pc                                          \
            << ": get_structure(" << Ai << ")");                \
  {                                                             \
    bool failed = false;                                        \
    do {                                                        \
      Q q = deref(vm->in[Ai]);                                  \
      vm->in[Ai] = q;                                           \
      const TAG_T tag = tag_of(q);                              \
      if (tag == TAG_STR) {                                     \
        A* p = ptr_of<A>(q);                                    \
        if (p[0].load() != Fn) {                                \
          failed = true;                                        \
          break;                                                \
        }                                                       \
        const int arity = atom_arity_of(Fn);                    \
        for (int i = arity; i > 0; --i) {                       \
          vm->push(p[i].load());                                \
        }                                                       \
        if (vm->is_log_trace()) {                               \
          vm->dump_register(Ai);                                \
          vm->dump_heap(p, 1 + arity);                          \
        }                                                       \
      } else if (tag == TAG_REF || tag == TAG_SUS) {            \
        A* p = ptr_of<A>(q);                                    \
        const int arity = atom_arity_of(Fn);                    \
        const size_t h = vm->heap_publishing(1 + arity);        \
        vm->heap[h + 0].store(Fn);                              \
        const Q structure = tagptr<TAG_STR>(&vm->heap[h + 0]);  \
        for (int i = arity; i > 0; --i) {                       \
          const Q q1 = tagptr<TAG_REF>(&vm->heap[h + i]);       \
          vm->heap[h + i] = q1;                                 \
          vm->push(q1);                                         \
        }                                                       \
        if (!p->compare_exchange_strong(q, structure)) {        \
          failed = true;                                        \
          break;                                                \
        }                                                       \
        if (tag == TAG_SUS) {                                   \
          vm->wake(q);                                          \
        }                                                       \
        vm->heap_published(1 + arity);                          \
        if (vm->is_log_trace()) {                               \
          vm->dump_register(Ai);                                \
          vm->dump_heap(h, 1 + arity);                          \
        }                                                       \
      } else {                                                  \
        if (vm->is_log_trace()) {                               \
          vm->dump_register(Ai);                                \
        }                                                       \
        failed = true;                                          \
        continue;                                               \
      }                                                         \
    } while (0);                                                \
    if (failed) {                                               \
      vm->fail();                                               \
      continue;                                                 \
    }                                                           \
  }

#define MACRO_unify_variable(Vn)                             \
  log_trace(vm, vm->pc << ": unify_variable(" << Vn << ")"); \
  {                                                          \
    const Q q = deref(vm->pop());                            \
    vm->in[Vn] = q;                                          \
    if (vm->is_log_trace()) {                                \
      vm->dump_register(Vn);                                 \
    }                                                        \
  }
#define MACRO_unify_value(Vn)                             \
  log_trace(vm, vm->pc << ": unify_value(" << Vn << ")"); \
  {                                                       \
    const Q q = vm->pop();                                \
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
    const Q q = vm->pop();                                \
    if (!vm->unify(C, q)) {                               \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_nil                                   \
  log_trace(vm, vm->pc << ": unify_nil" << ")");          \
  {                                                       \
    const Q q = deref(vm->pop());                         \
    if (!vm->unify(tagptr<TAG_NIL, Q>(0), q)) {           \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_list                                  \
  log_trace(vm, vm->pc << ": unify_list" << ")");         \
  {                                                       \
    bool failed = false;                                  \
    do {                                                  \
      Q q = deref(vm->pop());                             \
      const TAG_T tag = tag_of(q);                        \
      if (tag == TAG_LIST) {                              \
        A* p = ptr_of<A>(q);                              \
        vm->push(p[1].load());                            \
        vm->push(p[0].load());                            \
        if (vm->is_log_trace()) {                         \
          vm->dump_heap(p, 2);                            \
        }                                                 \
      } else if (tag == TAG_REF || tag == TAG_SUS) {      \
        A* p = ptr_of<A>(q);                              \
        if (vm->is_log_trace()) {                         \
          vm->dump_heap(p, 1);                            \
        }                                                 \
        const size_t h = vm->heap_publishing(2);          \
        const Q car = tagptr<TAG_REF>(&vm->heap[h + 0]);  \
        const Q cdr = tagptr<TAG_REF>(&vm->heap[h + 1]);  \
        vm->heap[h + 0] = car;                            \
        vm->heap[h + 1] = cdr;                            \
        const Q lst = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
        if (!p->compare_exchange_strong(q, lst)) {        \
          failed = true;                                  \
          break;                                          \
        }                                                 \
        if (tag == TAG_SUS) {                             \
          vm->wake(q);                                    \
        }                                                 \
        vm->push(cdr);                                    \
        vm->push(car);                                    \
        vm->heap_published(2);                            \
      } else {                                            \
        failed = true;                                    \
        break;                                            \
      }                                                   \
    } while (0);                                          \
    if (failed) {                                         \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }

#define MACRO_unify_structure(Fn)                                     \
  log_trace(vm, vm->pc                                                \
              << ": unify_structure("                                 \
              << atom_str_of(Fn) << "/" << atom_arity_of(Fn) << ")"); \
  {                                                                   \
    bool failed = false;                                              \
    do {                                                              \
      Q q = deref(vm->pop());                                         \
      const TAG_T tag = tag_of(q);                                    \
      if (tag == TAG_STR) {                                           \
        A* p = ptr_of<A>(q);                                          \
        if (p->load() != Fn) {                                        \
          failed = true;                                              \
          break;                                                      \
        }                                                             \
        const int arity = atom_arity_of(Fn);                          \
        for (int i = arity; i > 0; --i) {                             \
          vm->push(p[i].load());                                      \
        }                                                             \
        if (vm->is_log_trace()) {                                     \
          vm->dump_heap(p, arity + 1);                                \
        }                                                             \
      } else if (tag == TAG_REF || tag == TAG_SUS) {                  \
        A* p = ptr_of<A>(q);                                          \
        if (vm->is_log_trace()) {                                     \
          vm->dump_heap(p, 1);                                        \
        }                                                             \
        const int arity = atom_arity_of(Fn);                          \
        const size_t h = vm->heap_publishing(1 + arity);              \
        vm->heap[h + 0] = Fn;                                         \
        for (int i = arity; i > 0; --i) {                             \
          vm->heap[h + i] = tagptr<TAG_REF>(&vm->heap[h + i]);        \
          vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
        }                                                             \
        const Q s = tagptr<TAG_STR>(&vm->heap[h]);                    \
        if (!p->compare_exchange_strong(q, s)) {                      \
          failed = true;                                              \
          break;                                                      \
        }                                                             \
        if (tag == TAG_SUS) {                                         \
          vm->wake(q);                                                \
        }                                                             \
        vm->heap_published(1 + arity);                                \
        if (vm->is_log_trace()) {                                     \
          vm->dump_heap(p, 1);                                        \
          vm->dump_heap(h, arity + 1);                                \
        }                                                             \
      } else {                                                        \
        failed = true;                                                \
        break;                                                        \
      }                                                               \
    } while (0);                                                      \
    if (failed) {                                                     \
      vm->fail();                                                     \
      continue;                                                       \
    }                                                                 \
  }
#define MACRO_unify_void                        \
  vm->pop()

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
    if (q != C) {                                           \
      const TAG_T t = tag_of(q);                            \
      if (t == TAG_REF || t == TAG_SUS) {                   \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }

#define MACRO_check_nil(Ai)                                 \
  log_trace(vm, vm->pc << ": check_nil(" << Ai << ")");     \
  {                                                         \
    const Q q = vm->in[Ai] = deref(vm->in[Ai]);             \
    const TAG_T t = tag_of(q);                              \
    if (t != TAG_NIL) {                                     \
      if (t == TAG_REF || t == TAG_SUS) {                   \
        vm->add_wait_list(q);                               \
      }                                                     \
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
    if (t != TAG_LIST) {                          \
      if (t == TAG_REF || t == TAG_SUS) {         \
        vm->add_wait_list(q);                     \
      }                                           \
      vm->fail();                                 \
      continue;                                   \
    }                                             \
    A* p = ptr_of<A>(q);                          \
    vm->push(p[1].load());                        \
    vm->push(p[0].load());                        \
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
    if (t != TAG_STR) {                                    \
      if (t == TAG_REF || t == TAG_SUS) {                  \
        vm->add_wait_list(q);                              \
      }                                                    \
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
      vm->push(p[i].load());                               \
    }                                                      \
    if (vm->is_log_trace()) {                              \
      vm->dump_register(Ai);                               \
      vm->dump_heap(p, 1 + arity);                         \
    }                                                      \
  }

#define MACRO_read_variable(Vn)                               \
  {                                                           \
    const Q q = deref(vm->pop());                             \
    log_trace(vm, vm->pc << ": read_variable(" << Vn << ")"); \
    vm->in[Vn] = q;                                           \
  }

#define MACRO_read_value(Vn)                                \
  log_trace(vm, vm->pc << ": read_value(" << Vn << ")");    \
  {                                                         \
    const Q q = deref(vm->pop());                           \
    const Q q2 = deref(vm->in[Vn]);                         \
    if (q != q2) {                                          \
      const TAG_T t = tag_of(q);                            \
      if (t == TAG_REF || t == TAG_SUS) {                   \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_constant(C)                              \
  log_trace(vm, vm->pc << ": read_constant("                \
            << to_str(C) << ")");                           \
  {                                                         \
    const Q q = deref(vm->pop());                           \
    if (q != C) {                                           \
      const TAG_T t = tag_of(q);                            \
      if (t == TAG_REF || t == TAG_SUS) {                   \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_nil                                      \
  {                                                         \
    const Q q = deref(vm->pop());                           \
    log_trace(vm, vm->pc << ": read_nil" << to_str(q));     \
    const TAG_T t = tag_of(q);                              \
    if (t != TAG_NIL) {                                     \
      if (t == TAG_REF || t == TAG_SUS) {                   \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_list                                       \
  {                                                           \
    const Q q = deref(vm->pop());                             \
    log_trace(vm, vm->pc << ": read_list: " << to_str(q));    \
    const TAG_T t = tag_of(q);                                \
    if (t != TAG_LIST) {                                      \
      if (t == TAG_REF || t == TAG_SUS) {                     \
        vm->add_wait_list(q);                                 \
      }                                                       \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    A* p = ptr_of<A>(q);                                      \
    vm->push(p[1].load());                                    \
    vm->push(p[0].load());                                    \
    if (vm->is_log_trace()) {                                 \
      vm->dump_heap(p, 2);                                    \
    }                                                         \
  }
#define MACRO_read_structure(Fn)                    \
  throw std::runtime_error("fix me: read_structure")
#define MACRO_read_void                         \
  vm->pop();

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
