#ifndef GHC_H_
#define GHC_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <functional>
#include <stdio.h>
#include <thread>
#include <utility>

#include <iostream>

#include "./ghc_vm.h"
#include "./ghc_vm_ops.h"

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
