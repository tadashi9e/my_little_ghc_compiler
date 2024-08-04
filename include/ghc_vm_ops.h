#ifndef GHC_VM_OPS_H_
#define GHC_VM_OPS_H_

#include <cassert>

#include "./ghc_vm.h"

#define MACRO_goal(pc, goal)                      \
  ++vm->inference_count;                          \
  vm->contexts.back().pc_goal = pc;               \
  if (vm->contexts.back().status == ST_ACTIVE) {  \
    vm->contexts.back().status = ST_IN_GUARD;     \
  }                                               \
  vm->in[0] = (goal)

#define MACRO_requires(n)                         \
  vm->require(n)
#define MACRO_fail vm->fail(); continue
#define MACRO_wait(Ai)                                    \
  {                                                       \
    const Q q = deref(vm->in[Ai]);                        \
    const TAG_T t = tag_of(q);                            \
    if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
      vm->add_wait_list(q);                               \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
    vm->in[Ai] = ref_of(q);                               \
  }
#define MACRO_wait_for(tag, Ai)                           \
  {                                                       \
    const Q q = deref(vm->in[Ai]);                        \
    const TAG_T t = tag_of(q);                            \
    if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
      vm->add_wait_list(q);                               \
      vm->fail();                                         \
      continue;                                           \
    } else if (t != tag) {                                \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
    vm->in[Ai] = ref_of(q);                               \
  }

#define MACRO_try_guard_else(jump_to)             \
  if (vm->contexts.back().status == ST_ACTIVE) {  \
    vm->contexts.back().status = ST_IN_GUARD;     \
  }                                               \
  vm->contexts.back().pc_on_error = (jump_to)
  
#define MACRO_try_guard_else_suspend              \
  if (vm->contexts.back().status == ST_ACTIVE) {  \
    vm->contexts.back().status = ST_IN_GUARD;     \
  }                                               \
  vm->contexts.back().pc_on_error = -2
  
#define MACRO_otherwise                             \
  if (vm->contexts.back().status == ST_ACTIVE) {    \
    vm->contexts.back().status = ST_IN_GUARD;       \
  }                                                 \
  if (!vm->wait_list.empty()) {                     \
    vm->contexts.back().pc_on_error = -2;           \
    vm->fail();                                     \
    continue;                                       \
  }

// call 呼び出しに備えて次レジスタウィンドウをセットアップする。
// out レジスタ位置を次レジスタウィンドウ上に設定する。
#define MACRO_seq(Arity, O)                     \
  vm->create_new_window(O)

// レジスタウィンドウを進め、target を呼びだす。
// このとき、return_pc を戻り先アドレスとする。
#define MACRO_call(target_pc, return_pc, goal)    \
  vm->out[0] = (goal);                            \
  vm->switch_next_window(target_pc, return_pc);   \
  continue

// spawn 呼び出しに備えて新しいコンテキストを生成する。
// out レジスタ位置を新しいコンテキスト上に設定する。
#define MACRO_par(Arity, O)                     \
  vm->create_new_window(O)

#if 1
// 新しいコンテストの実行開始位置を start_from に設定する。
// 新しいコンテキストをコンテキストキューに投入する。
#define MACRO_spawn(target_pc, return_pc, goal)   \
  vm->switch_next_window(target_pc, return_pc);   \
  continue
#else
#define MACRO_spawn(target_pc, return_pc, goal)     \
  vm->out[0] = (goal);                              \
  if (vm->contexts.back().status == ST_ACTIVE) {    \
    vm->spawn(target_pc, goal);                     \
    vm->pc = return_pc;                             \
  } else {                                          \
    vm->switch_next_window(target_pc, return_pc);   \
  }                                                 \
  continue
#endif

// jump 呼び出しに備えて out レジスタ位置を設定する。
#define MACRO_tail(Arity, O)                    \
  vm->out = &vm->in[O]
// out レジスタの内容を in レジスタにコピーし、
// 制御を jump_to に移す。
#define MACRO_execute(jump_to, arity)             \
  vm->copy_from_out_to_in(arity);                 \
  vm->pc = (jump_to);                             \
  vm->contexts.back().pc_continue = -1;           \
  vm->contexts.back().status =                    \
    (vm->contexts.back().status != ST_ACTIVE)     \
    ? ST_SUBGOAL_IN_GUARD : ST_IN_GUARD;          \
  continue

#define MACRO_activate                          \
  vm->activate()
#define MACRO_proceed                           \
  vm->proceed();                                \
  continue
#define MACRO_return                            \
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
  }

#define MACRO_set_value(Vn, Ai)                 \
  {                                             \
    const Q q = ref_of(deref(vm->in[Vn]));      \
    vm->in[Vn] = q;                             \
    vm->in[Ai] = q;                             \
  }
#define MACRO_set_constant(C, Ai)               \
  vm->in[Ai] = (C)
#define MACRO_set_nil(Ai)                  \
  vm->in[Ai] = tagptr<TAG_NIL, Q>(0)
#define MACRO_set_list(Ai)                          \
  {                                                 \
    const size_t h = vm->heap_publishing(2);        \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));    \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));    \
    const Q q = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
    vm->in[Ai] = q;                                 \
    vm->heap_published(2);                          \
  }
#define MACRO_set_structure(Fn, Ai)                               \
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
  }

#if 0
#define MACRO_out_variable(Vn, Oi)                \
  {                                               \
    const size_t h = vm->heap_publishing(1);      \
    const Q q = tagptr<TAG_REF>(&vm->heap[h]);    \
    vm->heap[h].store(q);                         \
    vm->out[Oi] = q;                              \
    vm->in[Vn] = q;                               \
    vm->heap_published(1);                        \
  }
#else
#define MACRO_out_variable(Yn, Oi)                \
  assert(&vm->in[Yn] < &vm->out[Oi]);             \
  {                                               \
    const Q q = tagptr<TAG_LREF>(&vm->in[Yn]);    \
    vm->in[Yn] = q;                               \
    vm->out[Oi] = q;                              \
  }
#endif
#define MACRO_out_value(Vn, Oi)                             \
  {                                                         \
    const Q q = ref_of(deref(vm->in[Vn]));                  \
    vm->in[Vn] = q;                                         \
    vm->out[Oi] = q;                                        \
  }
#define MACRO_out_constant(C, Oi)                           \
  vm->out[Oi] = (C)
#define MACRO_out_nil(Oi)                       \
  vm->out[Oi] = tagptr<TAG_NIL, Q>(0)

#define MACRO_out_list(Oi)                       \
  {                                              \
    const size_t h = vm->heap_publishing(2);     \
    const Q q = tagptr<TAG_LIST>(&vm->heap[h]);  \
    vm->out[Oi] = q;                             \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1])); \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0])); \
    vm->heap_published(2);                       \
  }

#define MACRO_out_structure(Fn, Oi)                               \
  {                                                               \
    const int arity = atom_arity_of(Fn);                          \
    const size_t h = vm->heap_publishing(1 + arity);              \
    vm->heap[h + 0].store(Fn);                                    \
    for (int i = arity; i > 0; --i) {                             \
      vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
    }                                                             \
    const Q q = tagptr<TAG_STR>(&vm->heap[h]);                    \
    vm->out[Oi] = q;                                              \
    vm->heap_published(1 + arity);                                \
  }

#define MACRO_write_variable(Vn)                                  \
  {                                                               \
    const Q q = vm->pop();                                        \
    A* p = ptr_of<A>(q);                                          \
    p->store(q);                                                  \
    vm->in[Vn] = q;                                               \
  }
#define MACRO_write_value(Vn)                       \
  {                                                 \
    const Q q = vm->pop();                          \
    ptr_of<A>(q)->store(ref_of(deref(vm->in[Vn]))); \
  }

#define MACRO_write_constant(C)                           \
  {                                                       \
    const Q q = vm->pop();                                \
    A* p = ptr_of<A>(q);                                  \
    p->store(C);                                          \
  }
#define MACRO_write_nil                         \
  {                                             \
    const Q q = vm->pop();                      \
    A* p = ptr_of<A>(q);                        \
    p->store(tagptr<TAG_NIL, Q>(0));            \
  }
#define MACRO_write_list                                          \
  {                                                               \
    const Q q = vm->pop();                                        \
    const size_t h = vm->heap_publishing(2);                      \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 1]));                  \
    vm->push(tagptr<TAG_REF>(&vm->heap[h + 0]));                  \
    A* p = ptr_of<A>(q);                                          \
    p->store(tagptr<TAG_LIST>(&vm->heap[h + 0]));                 \
    vm->heap_published(2);                                        \
  }
#define MACRO_write_structure(Fn)                                 \
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
  {                                                       \
    const Q q = ref_of(deref(vm->in[Ai]));                \
    vm->in[Ai] = q;                                       \
    vm->in[Vn] = q;                                       \
  }
#define MACRO_get_value(Vn, Ai)                           \
  if (!vm->unify(vm->in[Vn], vm->in[Ai])) {               \
    vm->fail();                                           \
    continue;                                             \
  }

#define MACRO_get_constant(C, Ai)                                   \
  if (!vm->unify(C, vm->in[Ai])) {                                  \
    vm->fail();                                                     \
    continue;                                                       \
  }

#define MACRO_get_nil(Ai)                               \
  if (!vm->unify(tagptr<TAG_NIL, Q>(0), vm->in[Ai])) {  \
    vm->fail();                                         \
    continue;                                           \
  }
#define MACRO_get_list(Ai)                                \
  {                                                       \
    bool failed = false;                                  \
    do {                                                  \
      Q q = deref(vm->in[Ai]);                            \
      const TAG_T tag = tag_of(q);                        \
      if (tag == TAG_LIST) {                              \
        A* p = ptr_of<A>(q);                              \
        vm->push(p[1].load());                            \
        vm->push(p[0].load());                            \
      } else if (tag == TAG_LREF) {                       \
        Q* p = ptr_of<Q>(q);                              \
        const size_t h = vm->heap_publishing(2);          \
        const Q q0 = tagptr<TAG_REF>(&vm->heap[h + 0]);   \
        const Q q1 = tagptr<TAG_REF>(&vm->heap[h + 1]);   \
        vm->heap[h + 0].store(q0);                        \
        vm->heap[h + 1].store(q1);                        \
        const Q lst = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
        *p = lst;                                         \
        vm->heap_published(2);                            \
        vm->push(q1);                                     \
        vm->push(q0);                                     \
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
#define MACRO_get_structure(Fn, Ai)                             \
  {                                                             \
    bool failed = false;                                        \
    do {                                                        \
      Q q = deref(vm->in[Ai]);                                  \
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
      } else if (tag == TAG_LREF) {                             \
        Q* p = ptr_of<Q>(q);                                    \
        const int arity = atom_arity_of(Fn);                    \
        const size_t h = vm->heap_publishing(1 + arity);        \
        for (int i = arity; i > 0; --i) {                       \
          const Q q1 = tagptr<TAG_REF>(&vm->heap[h + i]);       \
          vm->heap[h + i] = q1;                                 \
          vm->push(q1);                                         \
        }                                                       \
        vm->heap[h + 0].store(Fn);                              \
        const Q structure = tagptr<TAG_STR>(&vm->heap[h + 0]);  \
        *p = structure;                                         \
        vm->heap_published(1 + arity);                          \
      } else if (tag == TAG_REF || tag == TAG_SUS) {            \
        A* p = ptr_of<A>(q);                                    \
        const int arity = atom_arity_of(Fn);                    \
        const size_t h = vm->heap_publishing(1 + arity);        \
        const Q structure = tagptr<TAG_STR>(&vm->heap[h + 0]);  \
        for (int i = arity; i > 0; --i) {                       \
          const Q q1 = tagptr<TAG_REF>(&vm->heap[h + i]);       \
          vm->heap[h + i] = q1;                                 \
          vm->push(q1);                                         \
        }                                                       \
        vm->heap[h + 0].store(Fn);                              \
        if (!p->compare_exchange_strong(q, structure)) {        \
          failed = true;                                        \
          break;                                                \
        }                                                       \
        if (tag == TAG_SUS) {                                   \
          vm->wake(q);                                          \
        }                                                       \
        vm->heap_published(1 + arity);                          \
      } else {                                                  \
        failed = true;                                          \
        break;                                                  \
      }                                                         \
    } while (0);                                                \
    if (failed) {                                               \
      vm->fail();                                               \
      continue;                                                 \
    }                                                           \
  }

#define MACRO_unify_variable(Vn)                             \
  {                                                          \
    const Q q = deref(vm->pop());                            \
    vm->in[Vn] = ref_of(q);                                  \
  }
#define MACRO_unify_value(Vn)                             \
  {                                                       \
    const Q q = vm->pop();                                \
    if (!vm->unify(q, vm->in[Vn])) {                      \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_constant(C)                           \
  {                                                       \
    const Q q = vm->pop();                                \
    if (!vm->unify(C, q)) {                               \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_nil                                   \
  {                                                       \
    const Q q = deref(vm->pop());                         \
    if (!vm->unify(tagptr<TAG_NIL, Q>(0), q)) {           \
      vm->fail();                                         \
      continue;                                           \
    }                                                     \
  }
#define MACRO_unify_list                                  \
  {                                                       \
    bool failed = false;                                  \
    do {                                                  \
      Q q = deref(vm->pop());                             \
      const TAG_T tag = tag_of(q);                        \
      if (tag == TAG_LIST) {                              \
        A* p = ptr_of<A>(q);                              \
        vm->push(p[1].load());                            \
        vm->push(p[0].load());                            \
      } else if (tag == TAG_LREF) {                       \
        const size_t h = vm->heap_publishing(2);          \
        const Q car = tagptr<TAG_REF>(&vm->heap[h + 0]);  \
        const Q cdr = tagptr<TAG_REF>(&vm->heap[h + 1]);  \
        vm->heap[h + 0] = car;                            \
        vm->heap[h + 1] = cdr;                            \
        const Q lst = tagptr<TAG_LIST>(&vm->heap[h + 0]); \
        *ptr_of<Q>(q) = lst;                              \
        vm->heap_published(2);                            \
      } else if (tag == TAG_REF || tag == TAG_SUS) {      \
        A* p = ptr_of<A>(q);                              \
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
      } else if (tag == TAG_LREF) {                                   \
        const int arity = atom_arity_of(Fn);                          \
        const size_t h = vm->heap_publishing(1 + arity);              \
        vm->heap[h + 0] = Fn;                                         \
        for (int i = arity; i > 0; --i) {                             \
          vm->heap[h + i] = tagptr<TAG_REF>(&vm->heap[h + i]);        \
          vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
        }                                                             \
        const Q structure = tagptr<TAG_STR>(&vm->heap[h]);            \
        *ptr_of<Q>(q) = structure;                                    \
        vm->heap_published(1 + arity);                                \
      } else if (tag == TAG_REF || tag == TAG_SUS) {                  \
        A* p = ptr_of<A>(q);                                          \
        const int arity = atom_arity_of(Fn);                          \
        const size_t h = vm->heap_publishing(1 + arity);              \
        vm->heap[h + 0] = Fn;                                         \
        for (int i = arity; i > 0; --i) {                             \
          vm->heap[h + i] = tagptr<TAG_REF>(&vm->heap[h + i]);        \
          vm->push(tagptr<TAG_REF>(&vm->heap[h + i]));                \
        }                                                             \
        const Q structure = tagptr<TAG_STR>(&vm->heap[h]);            \
        if (!p->compare_exchange_strong(q, structure)) {              \
          failed = true;                                              \
          break;                                                      \
        }                                                             \
        if (tag == TAG_SUS) {                                         \
          vm->wake(q);                                                \
        }                                                             \
        vm->heap_published(1 + arity);                                \
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
  {                                                  \
    vm->in[Vn] = ref_of(deref(vm->in[Ai]));          \
  }

#define MACRO_check_value(Vn, Ai)                    \
  {                                                  \
    if (!vm->equals(vm->in[Vn], vm->in[Ai])) {       \
      vm->fail();                                    \
      continue;                                      \
    }                                                \
  }

#define MACRO_check_constant(C, Ai)                         \
  {                                                         \
    const Q q = deref(vm->in[Ai]);                          \
    if (q != C) {                                           \
      const TAG_T t = tag_of(q);                            \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }

#define MACRO_check_nil(Ai)                                 \
  {                                                         \
    const Q q = deref(vm->in[Ai]);                          \
    const TAG_T t = tag_of(q);                              \
    if (t != TAG_NIL) {                                     \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_check_list(Ai)                                \
  {                                                         \
    const Q q = deref(vm->in[Ai]);                          \
    const TAG_T t = tag_of(q);                              \
    if (t != TAG_LIST) {                                    \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
    A* p = ptr_of<A>(q);                                    \
    vm->push(p[1].load());                                  \
    vm->push(p[0].load());                                  \
  }

#define MACRO_check_structure(Fn, Ai)                      \
  {                                                        \
    const Q q = deref(vm->in[Ai]);                         \
    const TAG_T t = tag_of(q);                             \
    if (t != TAG_STR) {                                    \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) { \
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
  }

#define MACRO_read_variable(Vn)                            \
  {                                                        \
    const Q q = deref(vm->pop());                          \
    vm->in[Vn] = ref_of(q);                                \
  }

#define MACRO_read_value(Vn)                                \
  {                                                         \
    if (!vm->equals(vm->pop(), vm->in[Vn])) {               \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_constant(C)                              \
  {                                                         \
    const Q q = deref(vm->pop());                           \
    if (q != C) {                                           \
      const TAG_T t = tag_of(q);                            \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_nil                                      \
  {                                                         \
    const Q q = deref(vm->pop());                           \
    const TAG_T t = tag_of(q);                              \
    if (t != TAG_NIL) {                                     \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                               \
      }                                                     \
      vm->fail();                                           \
      continue;                                             \
    }                                                       \
  }
#define MACRO_read_list                                       \
  {                                                           \
    const Q q = deref(vm->pop());                             \
    const TAG_T t = tag_of(q);                                \
    if (t != TAG_LIST) {                                      \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {  \
        vm->add_wait_list(q);                                 \
      }                                                       \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    A* p = ptr_of<A>(q);                                      \
    vm->push(p[1].load());                                    \
    vm->push(p[0].load());                                    \
  }
#define MACRO_read_structure(Fn)                              \
  {                                                           \
    const Q q = deref(vm->pop());                             \
    const TAG_T t = tag_of(q);                                \
    if (t != TAG_STR) {                                       \
      if (t == TAG_LREF || t == TAG_REF || t == TAG_SUS) {    \
        vm->add_wait_list(q);                                 \
      }                                                       \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    A* p = ptr_of<A>(q);                                      \
    if (p->load() != Fn) {                                    \
      vm->fail();                                             \
      continue;                                               \
    }                                                         \
    const int arity = atom_arity_of(Fn);                      \
    for (int i = arity; i > 0; --i) {                         \
      vm->push(p[i].load());                                  \
    }                                                         \
  }
#define MACRO_read_void                         \
  vm->pop();

#endif  // GHC_VM_OPS_H_
