#ifndef GHC_DUMPDOT_H_
#define GHC_DUMPDOT_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include "./ghc_tagutils.h"

inline std::string upper(const char* s) {
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
inline std::string esc(const std::string& s0) {
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
    case TAG_LREF:
      break;
    case TAG_REF:  // fall thgourh
    case TAG_LIST:  // fall thgourh
    case TAG_STR:  // fall thgourh
    case TAG_SUS:  // fall thgourh
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

#endif  // GHC_DUMPDOT_H_
