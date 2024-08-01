# include "./ghc.h"
#define atom(N) atom_ ## N
Q atom(1);  // fail / 0
Q atom(2);  // call / 1
Q atom(3);  // , / 2
Q atom(4);  // __call__ / 1
Q atom(5);  // call / 3
Q atom(6);  // __call__ / 3
Q atom(7);  // time / 1
Q atom(8);  // __time_pre__ / 3
Q atom(9);  // wait_time / 1
Q atom(10);  // __wait_time__ / 4
Q atom(11);  // __time_post__ / 3
Q atom(12);  // atom_concat / 3
Q atom(13);  // atom / 1
Q atom(14);  // __atom_concat_1__ / 3
Q atom(15);  // __atom_concat_2__ / 3
Q atom(16);  // __atom_concat_3__ / 3
Q atom(17);  // atom_codes / 2
Q atom(18);  //  / 0
Q atom(19);  // __atom_to_codes__ / 2
Q atom(20);  // __codes_to_atom__ / 3
Q atom(21);  // integer / 1
Q atom(22);  // __atom_code_concat__ / 3
Q atom(23);  // atom_chars / 2
Q atom(24);  // __atom_to_chars__ / 2
Q atom(25);  // __chars_to_atom__ / 3
Q atom(26);  // atom_number / 2
Q atom(27);  // __atom_to_number__ / 2
Q atom(28);  // __number_to_atom__ / 2
Q atom(29);  // outstream / 1
Q atom(30);  // outstream / 2
Q atom(31);  // open / 3
Q atom(32);  // write / 2
Q atom(33);  // write / 1
Q atom(34);  // writeln / 2
Q atom(35);  // writeln / 1
Q atom(36);  // nl / 1
Q atom(37);  // nl / 0
Q atom(38);  // __open_opt_string_to_integer__ / 3
Q atom(39);  // close / 1
Q atom(40);  // __open_opt_string_to_integer__ / 5
Q atom(41);  // rdonly / 0
Q atom(42);  // wronly / 0
Q atom(43);  // __inc__ / 2
Q atom(44);  // rdwr / 0
Q atom(45);  // __add__ / 3
Q atom(46);  // creat / 0
Q atom(47);  // excl / 0
Q atom(48);  // trunc / 0
Q atom(49);  // append / 0
Q atom(50);  // rusr / 0
Q atom(51);  // wusr / 0
Q atom(52);  // xusr / 0
Q atom(53);  // rgrp / 0
Q atom(54);  // wgrp / 0
Q atom(55);  // xgrp / 0
Q atom(56);  // roth / 0
Q atom(57);  // woth / 0
Q atom(58);  // xoth / 0
Q atom(59);  // __open__ / 4
Q atom(60);  // inline / 1
Q atom(61);  //   MACRO_proceed; / 0
Q atom(62);  // __close__ / 1
Q atom(63);  // __nl__ / 1
Q atom(64);  // __write__ / 2
Q atom(65);  // var / 1
Q atom(66);  // [] / 0
Q atom(67);  // [ / 0
Q atom(68);  // __write_list_tail__ / 2
Q atom(69);  // ] / 0
Q atom(70);  // is_functor / 1
Q atom(71);  // =.. / 2
Q atom(72);  // __write_functor_args__ / 2
Q atom(73);  // ( / 0
Q atom(74);  // __write_functor_args2__ / 2
Q atom(75);  // ) / 0
Q atom(76);  // __write_functor_tail__ / 2
Q atom(77);  // , / 0
Q atom(78);  // | / 0
Q atom(79);  // __write_number__ / 2
Q atom(80);  // __write_atom__ / 2
Q atom(81);  // __write_var__ / 2
Q atom(82);  // == / 2
Q atom(83);  // >= / 2
Q atom(84);  // =< / 2
Q atom(85);  // > / 2
Q atom(86);  // < / 2
Q atom(87);  // =:= / 2
Q atom(88);  // := / 2
Q atom(89);  // =\= / 2
Q atom(90);  // __not_equal__ / 2
Q atom(91);  // + / 2
Q atom(92);  // - / 2
Q atom(93);  // * / 2
Q atom(94);  // / / 2
Q atom(95);  // mod / 2
Q atom(96);  // - / 1
Q atom(97);  // __sub__ / 3
Q atom(98);  // __mul__ / 3
Q atom(99);  // __div__ / 3
Q atom(100);  // __mod__ / 3
Q atom(101);  // __neg__ / 2
Q atom(102);  // __ineg__ / 2
Q atom(103);  // __iadd__ / 3
Q atom(104);  // __isub__ / 3
Q atom(105);  // __imul__ / 3
Q atom(106);  // __idiv__ / 3
Q atom(107);  // __imod__ / 3
Q atom(108);  // __dec__ / 2
Q atom(109);  // __iinc__ / 2
Q atom(110);  // __idec__ / 2
Q atom(111);  // append / 3
Q atom(112);  // reverse / 2
Q atom(113);  // __reverse__ / 3
Q atom(114);  // nth0 / 3
Q atom(115);  // __nth0__ / 3
Q atom(116);  // __nth0_rev__ / 4
Q atom(117);  // nth1 / 3
Q atom(118);  // inference_count / 1
Q atom(119);  // __inference_count__ / 1
Q atom(120);  // resume_count / 1
Q atom(121);  // __resume_count__ / 1
Q atom(122);  // dump_to_dot / 1
Q atom(123);  // __dump_to_dot__ / 1
Q atom(124);  // dump_to_dot / 2
Q atom(125);  // __dump_to_dot__ / 2
Q atom(126);  // tarai / 4
Q atom(127);  // tarai_aux / 5
Q atom(128);  // report / 1
Q atom(129);  // main / 1
Q atom(130);  // usage:  / 0
Q atom(131);  //  X Y Z / 0
void module(VM::ptr vm, Program* prog) {
  for (;;) {
    switch (vm->pc) {
    case -1:
      return;
    case 1:  // fail/0
      MACRO_goal(1,atom(1));
      MACRO_requires(1);
{
    MACRO_fail;
}
    case 2:  // call/1
      MACRO_goal(2,atom(2));
      MACRO_requires(5);
      MACRO_try_guard_else(4);
      MACRO_check_structure(atom(3),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(2));
      MACRO_activate;
      MACRO_par(1,4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(2,3,atom(2));  // spawn(call/1)
    case 3:  // return_from_spawn(call/1)
      MACRO_tail(1,4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(2,1);  // execute(call/1)
    case 4:  // call/1-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(5,1);  // execute(__call__/1)
    case 5:  // __call__/1
      MACRO_goal(5,atom(4));
      MACRO_requires(2);
  MACRO_wait(reg::in(1));
  {
    const Q q = vm->in[1];
    const TAG_T tag = tag_of(q);
    if (tag == TAG_ATOM) {
      MACRO_activate;
      const int pc = prog->query_entry_point(q);
      MACRO_execute(pc, 0);
    } else if (tag == TAG_STR) {
      MACRO_activate;
      A* structure = ptr_of<A>(q);
      const Q g = structure[0].load();
      const int pc = prog->query_entry_point(g);
      if (pc < 0) {
        vm->fail();
        continue;
      }
      const int arity = atom_arity_of(g);
      MACRO_tail(arity, 2);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_execute(pc, arity);
    } else {
      MACRO_fail;
    }
  }
    case 6:  // call/3
      MACRO_goal(6,atom(5));
      MACRO_requires(9);
      MACRO_try_guard_else(8);
      MACRO_check_structure(atom(3),reg::in(1));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(3,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(6,7,atom(5));  // spawn(call/3)
    case 7:  // return_from_spawn(call/3)
      MACRO_tail(3,6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(6,3);  // execute(call/3)
    case 8:  // call/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(9,3);  // execute(__call__/3)
    case 9:  // __call__/3
      MACRO_goal(9,atom(6));
      MACRO_requires(4);
  MACRO_wait(reg::in(1));
  {
    const Q q = vm->in[1];
    const Q u = vm->in[2];
    const Q v = vm->in[3];
    const TAG_T tag = tag_of(q);
    if (tag == TAG_ATOM) {
      MACRO_activate;
      const std::string s = atom_str_of(q);
      const Q g = to_atom(s.c_str(), 2);
      const int pc = prog->query_entry_point(g);
      MACRO_tail(2, 4);
      MACRO_out_constant(u, reg::out(1));
      MACRO_out_constant(v, reg::out(2));
      MACRO_execute(pc, 2);
    } else if (tag == TAG_STR) {
      MACRO_activate;
      A* structure = ptr_of<A>(q);
      Q g = structure[0].load();
      const std::string s = atom_str_of(g);
      const int arity = atom_arity_of(g);
      g = to_atom(s.c_str(), arity + 2);
      const int pc = prog->query_entry_point(g);
      if (pc < 0) {
        vm->fail();
        continue;
      }
      MACRO_tail(arity, 2);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_out_constant(u, reg::out(arity + 1));
      MACRO_out_constant(v, reg::out(arity + 2));
      MACRO_execute(pc, arity + 2);
    } else {
      MACRO_fail;
    }
  }
    case 10:  // time/1
      MACRO_goal(10,atom(7));
      MACRO_requires(8);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3,5);
      MACRO_out_variable(reg::y(2),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_call(16,11,atom(8));  // call(__time_pre__/3)
    case 11:  // return_from_call(__time_pre__/3)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(2,12,atom(2));  // call(call/1)
    case 12:  // return_from_call(call/1)
      MACRO_tail(3,5);
      MACRO_out_value(reg::y(2),reg::out(1));
      MACRO_out_value(reg::y(3),reg::out(2));
      MACRO_out_value(reg::y(4),reg::out(3));
      MACRO_execute(17,3);  // execute(__time_post__/3)
    case 13:  // wait_time/1
      MACRO_goal(13,atom(9));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,5);
      MACRO_out_variable(reg::y(2),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(16,14,atom(8));  // spawn(__time_pre__/3)
    case 14:  // return_from_spawn(__time_pre__/3)
      MACRO_tail(4,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::y(2),reg::out(2));
      MACRO_out_value(reg::y(3),reg::out(3));
      MACRO_out_value(reg::y(4),reg::out(4));
      MACRO_execute(15,4);  // execute(__wait_time__/4)
    case 15:  // __wait_time__/4
      MACRO_goal(15,atom(10));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(3,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(3),reg::out(2));
      MACRO_out_value(reg::in(4),reg::out(3));
      MACRO_execute(17,3);  // execute(__time_post__/3)
    case 16:  // __time_pre__/3
      MACRO_goal(16,atom(8));
      MACRO_requires(4);
  MACRO_activate;
  {
    const int64_t istart = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
    MACRO_get_constant(tagvalue<TAG_INT>(istart), reg::in(1));
  }
  MACRO_get_constant(tagvalue<TAG_INT>(vm->inference_count), reg::in(2));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->resume_count), reg::in(3));
  MACRO_proceed;
    case 17:  // __time_post__/3
      MACRO_goal(17,atom(11));
      MACRO_requires(4);
  MACRO_activate;
  {
    const int64_t iend = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
    const int64_t istart =
          value_of<int64_t>(vm->in[1]);
    const int64_t inferences =
          vm->inference_count - value_of<int64_t>(vm->in[2]);
    const int64_t resumes =
          vm->resume_count - value_of<int64_t>(vm->in[3]);
    const double seconds = (iend - istart) / 1000000.0;
    std::cout << "% " << inferences << " inferences("
              << resumes << " times resumed), "
              << seconds << " CPU seconds ("
              << std::fixed << (inferences / seconds) << " Lips)" << std::endl;
  }
  MACRO_proceed;
    case 18:  // atom_concat/3
      MACRO_goal(18,atom(12));
      MACRO_requires(8);
      MACRO_try_guard_else(21);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,19,atom(13));  // call(atom/1)
    case 19:  // return_from_call(atom/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(159,20,atom(13));  // call(atom/1)
    case 20:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(27,3);  // execute(__atom_concat_1__/3)
    case 21:  // atom_concat/3-2
      MACRO_try_guard_else(24);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,22,atom(13));  // call(atom/1)
    case 22:  // return_from_call(atom/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(159,23,atom(13));  // call(atom/1)
    case 23:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(28,3);  // execute(__atom_concat_2__/3)
    case 24:  // atom_concat/3-3
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(159,25,atom(13));  // call(atom/1)
    case 25:  // return_from_call(atom/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(159,26,atom(13));  // call(atom/1)
    case 26:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(29,3);  // execute(__atom_concat_3__/3)
    case 27:  // __atom_concat_1__/3
      MACRO_goal(27,atom(14));
      MACRO_requires(4);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s1 = atom_str_of(q1);
    const std::string s2 = atom_str_of(q2);
    const std::string s = s1 + s2;
    const Q c = to_atom(s.c_str(), 0);
    if (!vm->unify(c, vm->in[3])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 28:  // __atom_concat_2__/3
      MACRO_goal(28,atom(15));
      MACRO_requires(4);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q3 = vm->in[3];
    const std::string s1 = atom_str_of(q1);
    const std::string s3 = atom_str_of(q3);
    if (s1.length() > s3.length()) {
      vm->fail();
      continue;
    }
    const size_t i = s1.length();
    if (s3.substr(0, i) != s1) {
      vm->fail();
      continue;
    }
    const std::string s2 = s3.substr(i);
    const Q c = to_atom(s2.c_str(), 0);
    if (!vm->unify(c, vm->in[2])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 29:  // __atom_concat_3__/3
      MACRO_goal(29,atom(16));
      MACRO_requires(4);
  MACRO_activate;
  {
    const Q q2 = vm->in[2];
    const Q q3 = vm->in[3];
    const std::string s2 = atom_str_of(q2);
    const std::string s3 = atom_str_of(q3);
    if (s2.length() > s3.length()) {
      vm->fail();
      continue;
    }
    const size_t i = s2.length();
    if (s3.substr(i) != s2) {
      vm->fail();
      continue;
    }
    const std::string s1 = s3.substr(0, i);
    const Q c = to_atom(s1.c_str(), 0);
    if (!vm->unify(c, vm->in[1])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 30:  // atom_codes/2
      MACRO_goal(30,atom(17));
      MACRO_requires(7);
      MACRO_try_guard_else(32);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,31,atom(13));  // call(atom/1)
    case 31:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(33,2);  // execute(__atom_to_codes__/2)
    case 32:  // atom_codes/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_void;
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_constant(atom(18),reg::out(3));
      MACRO_execute(34,3);  // execute(__codes_to_atom__/3)
    case 33:  // __atom_to_codes__/2
      MACRO_goal(33,atom(19));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const size_t h = vm->heap_publishing(s.length() * 2);
    for (size_t i = 0; i < s.length(); ++i) {
      const unsigned char c = s.at(i);
      vm->heap[h + i * 2].store(tagvalue<TAG_INT>(c));
      vm->heap[h + i * 2 + 1].store(
              (i < s.length() - 1)
              ? tagptr<TAG_LIST>(&vm->heap[h + i * 2 + 2])
              : tagptr<TAG_NIL, Q>(0));
    }
    vm->heap_published(s.length() * 2);
    if (!vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 34:  // __codes_to_atom__/3
      MACRO_goal(34,atom(20));
      MACRO_requires(9);
      MACRO_try_guard_else(35);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 35:  // __codes_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_seq(1,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_call(158,36,atom(21));  // call(integer/1)
    case 36:  // return_from_call(integer/1)
      MACRO_seq(1,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(159,37,atom(13));  // call(atom/1)
    case 37:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_par(3,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(39,38,atom(22));  // spawn(__atom_code_concat__/3)
    case 38:  // return_from_spawn(__atom_code_concat__/3)
      MACRO_tail(3,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::y(4),reg::out(3));
      MACRO_execute(34,3);  // execute(__codes_to_atom__/3)
    case 39:  // __atom_code_concat__/3
      MACRO_goal(39,atom(22));
      MACRO_requires(4);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    std::string s = atom_str_of(q1);
    const unsigned char c = value_of<char>(q2);
    s += c;
    if (!vm->unify(to_atom(s.c_str(), 0), vm->in[3])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 40:  // atom_chars/2
      MACRO_goal(40,atom(23));
      MACRO_requires(8);
      MACRO_try_guard_else(42);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,41,atom(13));  // call(atom/1)
    case 41:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(43,2);  // execute(__atom_to_chars__/2)
    case 42:  // atom_chars/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_execute(44,3);  // execute(__chars_to_atom__/3)
    case 43:  // __atom_to_chars__/2
      MACRO_goal(43,atom(24));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const size_t h = vm->heap_publishing(s.length() * 2);
    size_t i = 0;
    for (size_t j = 0; j < s.length(); ++i) {
      const int c0 = s.at(j) & 0xff;
      int n = 1;
      if (c0 < 0x80) {
        n = 1;
      } else if (j + 2 <= s.length()) {
        const int c1 = s.at(j + 1) & 0xff;
        if (c0 - 0xc2 < 0x1e && c1 - 0x80 < 0x40) {
          n = 2;
        } else if (j + 3 <= s.length()) {
          const int c2 = s.at(j + 2) & 0xff;
          if (((c0 == 0xe0       && c1 - 0xa0 < 0x20) ||
               (c0 - 0xe1 < 0x0c && c1 - 0x80 < 0x40) ||
               (c0 == 0xed       && c1 - 0x80 < 0x20) ||
               (c0 - 0xee < 0x02 && c1 - 0x80 < 0x40)) && c2 - 0x80 < 0x40) {
            n = 3;
          } else if (j + 4 <= s.length()) {
            const int c3 = s.at(j + 3) & 0xff;
            if (((c0 == 0xf0       && c1 - 0x90 < 0x30) ||
                 (c0 - 0xf1 < 0x03 && c1 - 0x80 < 0x40) ||
                 (c0 == 0xf4       && c1 - 0x80 < 0x10)) && c2 - 0x80 < 0x40 && c3 - 0x80 < 0x40) {
              n = 4;
            }
          }
        }
      }
      const std::string s1 = (
              (j + n < s.length()) ? s.substr(j, n) : s.substr(j));
      j += n;
      vm->heap[h + i * 2].store(to_atom(s1.c_str(), 0));
      vm->heap[h + i * 2 + 1].store(
              (j < s.length() - 1)
              ? tagptr<TAG_LIST>(&vm->heap[h + i * 2 + 2])
              : tagptr<TAG_NIL, Q>(0));
    }
    vm->heap_published(i * 2);
    if (!vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 44:  // __chars_to_atom__/3
      MACRO_goal(44,atom(25));
      MACRO_requires(9);
      MACRO_try_guard_else(45);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 45:  // __chars_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_seq(1,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(159,46,atom(13));  // call(atom/1)
    case 46:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_par(3,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(18,47,atom(12));  // spawn(atom_concat/3)
    case 47:  // return_from_spawn(atom_concat/3)
      MACRO_tail(3,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::y(4),reg::out(3));
      MACRO_execute(44,3);  // execute(__chars_to_atom__/3)
    case 48:  // atom_number/2
      MACRO_goal(48,atom(26));
      MACRO_requires(6);
      MACRO_try_guard_else(50);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,49,atom(13));  // call(atom/1)
    case 49:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(52,2);  // execute(__atom_to_number__/2)
    case 50:  // atom_number/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,51,atom(21));  // call(integer/1)
    case 51:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(53,2);  // execute(__number_to_atom__/2)
    case 52:  // __atom_to_number__/2
      MACRO_goal(52,atom(27));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_get_constant(tagvalue<TAG_INT>(i), reg::in(2));
  }
  MACRO_proceed;
    case 53:  // __number_to_atom__/2
      MACRO_goal(53,atom(28));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[2];
    const int64_t i = value_of<int64_t>(q);
    const std::string s = std::to_string(i);
    MACRO_get_constant(to_atom(s.c_str(), 0), reg::in(1));
  }
  MACRO_proceed;
    case 54:  // outstream/1
      MACRO_goal(54,atom(29));
      MACRO_requires(6);
      MACRO_try_guard_else(55);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 55:  // outstream/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(56,2);  // execute(outstream/2)
    case 56:  // outstream/2
      MACRO_goal(56,atom(30));
      MACRO_requires(9);
      MACRO_try_guard_else(58);
      MACRO_check_structure(atom(31),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(3,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(70,57,atom(31));  // spawn(open/3)
    case 57:  // return_from_spawn(open/3)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 58:  // outstream/2-2
      MACRO_try_guard_else(60);
      MACRO_check_structure(atom(32),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_seq(2,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(118,59,atom(32));  // call(write/2)
    case 59:  // return_from_call(write/2)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 60:  // outstream/2-3
      MACRO_try_guard_else(62);
      MACRO_check_structure(atom(33),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(1,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_call(117,61,atom(33));  // call(write/1)
    case 61:  // return_from_call(write/1)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 62:  // outstream/2-4
      MACRO_try_guard_else(64);
      MACRO_check_structure(atom(34),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_seq(2,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,63,atom(34));  // call(writeln/2)
    case 63:  // return_from_call(writeln/2)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 64:  // outstream/2-5
      MACRO_try_guard_else(66);
      MACRO_check_structure(atom(35),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(1,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_call(109,65,atom(35));  // call(writeln/1)
    case 65:  // return_from_call(writeln/1)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 66:  // outstream/2-6
      MACRO_try_guard_else(68);
      MACRO_check_structure(atom(36),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(1,6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_call(114,67,atom(36));  // call(nl/1)
    case 67:  // return_from_call(nl/1)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 68:  // outstream/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(37),reg::in(1));
      MACRO_activate;
      MACRO_seq(0,6);
      MACRO_call(113,69,atom(37));  // call(nl/0)
    case 69:  // return_from_call(nl/0)
      MACRO_tail(1,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(54,1);  // execute(outstream/1)
    case 70:  // open/3
      MACRO_goal(70,atom(31));
      MACRO_requires(10);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_out_variable(reg::y(5),reg::out(3));
      MACRO_spawn(73,71,atom(38));  // spawn(__open_opt_string_to_integer__/3)
    case 71:  // return_from_spawn(__open_opt_string_to_integer__/3)
      MACRO_tail(4,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_out_value(reg::y(5),reg::out(3));
      MACRO_out_value(reg::in(3),reg::out(4));
      MACRO_execute(106,4);  // execute(__open__/4)
    case 72:  // close/1
      MACRO_goal(72,atom(39));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(108,1);  // execute(__close__/1)
    case 73:  // __open_opt_string_to_integer__/3
      MACRO_goal(73,atom(38));
      MACRO_requires(11);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 74:  // __open_opt_string_to_integer__/5
      MACRO_goal(74,atom(40));
      MACRO_requires(27);
      MACRO_try_guard_else(75);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(2));
      MACRO_get_value(reg::in(5),reg::in(3));
      MACRO_proceed;
    case 75:  // __open_opt_string_to_integer__/5-2
      MACRO_try_guard_else(76);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(41));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_tail(5,7);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 76:  // __open_opt_string_to_integer__/5-3
      MACRO_try_guard_else(78);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(42));
      MACRO_read_variable(reg::x(7));
      MACRO_activate;
      MACRO_par(2,8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::y(6),reg::out(2));
      MACRO_call(223,77,atom(43));  // call(__inc__/2)
    case 77:  // return_from_call(__inc__/2)
      MACRO_tail(5,8);
      MACRO_out_value(reg::x(7),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(6),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 78:  // __open_opt_string_to_integer__/5-4
      MACRO_try_guard_else(80);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(44));
      MACRO_read_variable(reg::x(8));
      MACRO_activate;
      MACRO_par(3,9);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::y(7),reg::out(3));
      MACRO_call(183,79,atom(45));  // call(__add__/3)
    case 79:  // return_from_call(__add__/3)
      MACRO_tail(5,9);
      MACRO_out_value(reg::x(8),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 80:  // __open_opt_string_to_integer__/5-5
      MACRO_try_guard_else(82);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(46));
      MACRO_read_variable(reg::x(9));
      MACRO_activate;
      MACRO_par(3,10);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::y(8),reg::out(3));
      MACRO_call(183,81,atom(45));  // call(__add__/3)
    case 81:  // return_from_call(__add__/3)
      MACRO_tail(5,10);
      MACRO_out_value(reg::x(9),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(8),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 82:  // __open_opt_string_to_integer__/5-6
      MACRO_try_guard_else(84);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(47));
      MACRO_read_variable(reg::x(10));
      MACRO_activate;
      MACRO_par(3,11);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::y(9),reg::out(3));
      MACRO_call(183,83,atom(45));  // call(__add__/3)
    case 83:  // return_from_call(__add__/3)
      MACRO_tail(5,11);
      MACRO_out_value(reg::x(10),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(9),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 84:  // __open_opt_string_to_integer__/5-7
      MACRO_try_guard_else(86);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(48));
      MACRO_read_variable(reg::x(11));
      MACRO_activate;
      MACRO_par(3,12);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
      MACRO_out_variable(reg::y(10),reg::out(3));
      MACRO_call(183,85,atom(45));  // call(__add__/3)
    case 85:  // return_from_call(__add__/3)
      MACRO_tail(5,12);
      MACRO_out_value(reg::x(11),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(10),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 86:  // __open_opt_string_to_integer__/5-8
      MACRO_try_guard_else(88);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(49));
      MACRO_read_variable(reg::x(12));
      MACRO_activate;
      MACRO_par(3,13);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
      MACRO_out_variable(reg::y(11),reg::out(3));
      MACRO_call(183,87,atom(45));  // call(__add__/3)
    case 87:  // return_from_call(__add__/3)
      MACRO_tail(5,13);
      MACRO_out_value(reg::x(12),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(11),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 88:  // __open_opt_string_to_integer__/5-9
      MACRO_try_guard_else(90);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(50));
      MACRO_read_variable(reg::x(13));
      MACRO_activate;
      MACRO_par(3,14);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
      MACRO_out_variable(reg::y(12),reg::out(3));
      MACRO_call(183,89,atom(45));  // call(__add__/3)
    case 89:  // return_from_call(__add__/3)
      MACRO_tail(5,14);
      MACRO_out_value(reg::x(13),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(12),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 90:  // __open_opt_string_to_integer__/5-10
      MACRO_try_guard_else(92);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(51));
      MACRO_read_variable(reg::x(14));
      MACRO_activate;
      MACRO_par(3,15);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::y(13),reg::out(3));
      MACRO_call(183,91,atom(45));  // call(__add__/3)
    case 91:  // return_from_call(__add__/3)
      MACRO_tail(5,15);
      MACRO_out_value(reg::x(14),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(13),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 92:  // __open_opt_string_to_integer__/5-11
      MACRO_try_guard_else(94);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(52));
      MACRO_read_variable(reg::x(15));
      MACRO_activate;
      MACRO_par(3,16);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::y(14),reg::out(3));
      MACRO_call(183,93,atom(45));  // call(__add__/3)
    case 93:  // return_from_call(__add__/3)
      MACRO_tail(5,16);
      MACRO_out_value(reg::x(15),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(14),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 94:  // __open_opt_string_to_integer__/5-12
      MACRO_try_guard_else(96);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(53));
      MACRO_read_variable(reg::x(16));
      MACRO_activate;
      MACRO_par(3,17);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
      MACRO_out_variable(reg::y(15),reg::out(3));
      MACRO_call(183,95,atom(45));  // call(__add__/3)
    case 95:  // return_from_call(__add__/3)
      MACRO_tail(5,17);
      MACRO_out_value(reg::x(16),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(15),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 96:  // __open_opt_string_to_integer__/5-13
      MACRO_try_guard_else(98);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(54));
      MACRO_read_variable(reg::x(17));
      MACRO_activate;
      MACRO_par(3,18);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
      MACRO_out_variable(reg::y(16),reg::out(3));
      MACRO_call(183,97,atom(45));  // call(__add__/3)
    case 97:  // return_from_call(__add__/3)
      MACRO_tail(5,18);
      MACRO_out_value(reg::x(17),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(16),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 98:  // __open_opt_string_to_integer__/5-14
      MACRO_try_guard_else(100);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(55));
      MACRO_read_variable(reg::x(18));
      MACRO_activate;
      MACRO_par(3,19);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
      MACRO_out_variable(reg::y(17),reg::out(3));
      MACRO_call(183,99,atom(45));  // call(__add__/3)
    case 99:  // return_from_call(__add__/3)
      MACRO_tail(5,19);
      MACRO_out_value(reg::x(18),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(17),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 100:  // __open_opt_string_to_integer__/5-15
      MACRO_try_guard_else(102);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(56));
      MACRO_read_variable(reg::x(19));
      MACRO_activate;
      MACRO_par(3,20);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
      MACRO_out_variable(reg::y(18),reg::out(3));
      MACRO_call(183,101,atom(45));  // call(__add__/3)
    case 101:  // return_from_call(__add__/3)
      MACRO_tail(5,20);
      MACRO_out_value(reg::x(19),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(18),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 102:  // __open_opt_string_to_integer__/5-16
      MACRO_try_guard_else(104);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(57));
      MACRO_read_variable(reg::x(20));
      MACRO_activate;
      MACRO_par(3,21);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::y(19),reg::out(3));
      MACRO_call(183,103,atom(45));  // call(__add__/3)
    case 103:  // return_from_call(__add__/3)
      MACRO_tail(5,21);
      MACRO_out_value(reg::x(20),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(19),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 104:  // __open_opt_string_to_integer__/5-17
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(58));
      MACRO_read_variable(reg::x(21));
      MACRO_activate;
      MACRO_par(2,22);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_variable(reg::y(20),reg::out(2));
      MACRO_call(223,105,atom(43));  // call(__inc__/2)
    case 105:  // return_from_call(__inc__/2)
      MACRO_tail(5,22);
      MACRO_out_value(reg::x(21),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::y(20),reg::out(5));
      MACRO_execute(74,5);  // execute(__open_opt_string_to_integer__/5)
    case 106:  // __open__/4
      MACRO_goal(106,atom(59));
      MACRO_requires(5);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_wait_for(TAG_INT, reg::in(3));
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const Q q3 = vm->in[3];
    const std::string src = atom_str_of(q1);
    const int oflag = value_of<int>(q2);
    const int omode = value_of<int>(q3);
    const int fd = open(src.c_str(), oflag, omode);
    if (fd < 0) {
      if (!vm->unify(to_atom("error", 0), vm->in[4])) {
        MACRO_fail;
      }
    } else {
      if (!vm->unify(tagvalue<TAG_INT>(fd), vm->in[4])) {
        MACRO_fail;
      }
    }
  }
    case 107:  // inline/1
      MACRO_goal(107,atom(60));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(61),reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 108:  // __close__/1
      MACRO_goal(108,atom(62));
      MACRO_requires(2);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
  }
  MACRO_proceed;
    case 109:  // writeln/1
      MACRO_goal(109,atom(35));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(117,110,atom(33));  // call(write/1)
    case 110:  // return_from_call(write/1)
      MACRO_tail(0,3);
      MACRO_execute(113,0);  // execute(nl/0)
    case 111:  // writeln/2
      MACRO_goal(111,atom(34));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(118,112,atom(32));  // call(write/2)
    case 112:  // return_from_call(write/2)
      MACRO_tail(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(114,1);  // execute(nl/1)
    case 113:  // nl/0
      MACRO_goal(113,atom(37));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(114,1);  // execute(nl/1)
    case 114:  // nl/1
      MACRO_goal(114,atom(36));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,115,atom(21));  // call(integer/1)
    case 115:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(116,1);  // execute(__nl__/1)
    case 116:  // __nl__/1
      MACRO_goal(116,atom(63));
      MACRO_requires(2);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const int fd = value_of<int>(q1);
    const std::string s = "\n";
    for (size_t offset = 0; offset <  s.size();) {
      const ssize_t n = write(fd, s.c_str() + offset, s.size() - offset);
      if (n <= 0) {
        break;
      }
      offset += n;
    }
  }
  MACRO_proceed;
    case 117:  // write/1
      MACRO_goal(117,atom(33));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2,3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(118,2);  // execute(write/2)
    case 118:  // write/2
      MACRO_goal(118,atom(32));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,119,atom(21));  // call(integer/1)
    case 119:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 120:  // __write__/2
      MACRO_goal(120,atom(64));
      MACRO_requires(7);
      MACRO_try_guard_else(122);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(159,121,atom(13));  // call(atom/1)
    case 121:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(156,2);  // execute(__write_atom__/2)
    case 122:  // __write__/2-2
      MACRO_try_guard_else(124);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(160,123,atom(65));  // call(var/1)
    case 123:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(157,2);  // execute(__write_var__/2)
    case 124:  // __write__/2-3
      MACRO_try_guard_else(126);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,125,atom(21));  // call(integer/1)
    case 125:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(155,2);  // execute(__write_number__/2)
    case 126:  // __write__/2-4
      MACRO_try_guard_else(127);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(66),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 127:  // __write__/2-5
      MACRO_try_guard_else(131);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(67),reg::out(2));
      MACRO_call(120,128,atom(64));  // call(__write__/2)
    case 128:  // return_from_call(__write__/2)
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(120,129,atom(64));  // call(__write__/2)
    case 129:  // return_from_call(__write__/2)
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_call(146,130,atom(68));  // call(__write_list_tail__/2)
    case 130:  // return_from_call(__write_list_tail__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(69),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 131:  // __write__/2-6
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(161,132,atom(70));  // call(is_functor/1)
    case 132:  // return_from_call(is_functor/1)
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_list(reg::out(2));
      MACRO_write_variable(reg::x(4));
      MACRO_write_variable(reg::x(3));
      MACRO_call(162,133,atom(71));  // call((=..)/2)
    case 133:  // return_from_call((=..)/2)
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(120,134,atom(64));  // call(__write__/2)
    case 134:  // return_from_call(__write__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(135,2);  // execute(__write_functor_args__/2)
    case 135:  // __write_functor_args__/2
      MACRO_goal(135,atom(72));
      MACRO_requires(6);
      MACRO_try_guard_else(136);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 136:  // __write_functor_args__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(73),reg::out(2));
      MACRO_call(120,137,atom(64));  // call(__write__/2)
    case 137:  // return_from_call(__write__/2)
      MACRO_seq(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(139,138,atom(74));  // call(__write_functor_args2__/2)
    case 138:  // return_from_call(__write_functor_args2__/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(75),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 139:  // __write_functor_args2__/2
      MACRO_goal(139,atom(74));
      MACRO_requires(7);
      MACRO_try_guard_else(140);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 140:  // __write_functor_args2__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(120,141,atom(64));  // call(__write__/2)
    case 141:  // return_from_call(__write__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(142,2);  // execute(__write_functor_tail__/2)
    case 142:  // __write_functor_tail__/2
      MACRO_goal(142,atom(76));
      MACRO_requires(7);
      MACRO_try_guard_else(143);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 143:  // __write_functor_tail__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(77),reg::out(2));
      MACRO_call(120,144,atom(64));  // call(__write__/2)
    case 144:  // return_from_call(__write__/2)
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(120,145,atom(64));  // call(__write__/2)
    case 145:  // return_from_call(__write__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(142,2);  // execute(__write_functor_tail__/2)
    case 146:  // __write_list_tail__/2
      MACRO_goal(146,atom(68));
      MACRO_requires(7);
      MACRO_try_guard_else(149);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(160,147,atom(65));  // call(var/1)
    case 147:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(78),reg::out(2));
      MACRO_call(120,148,atom(64));  // call(__write__/2)
    case 148:  // return_from_call(__write__/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 149:  // __write_list_tail__/2-2
      MACRO_try_guard_else(150);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 150:  // __write_list_tail__/2-3
      MACRO_try_guard_else(153);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(77),reg::out(2));
      MACRO_call(120,151,atom(64));  // call(__write__/2)
    case 151:  // return_from_call(__write__/2)
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(120,152,atom(64));  // call(__write__/2)
    case 152:  // return_from_call(__write__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(146,2);  // execute(__write_list_tail__/2)
    case 153:  // __write_list_tail__/2-4
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(78),reg::out(2));
      MACRO_call(120,154,atom(64));  // call(__write__/2)
    case 154:  // return_from_call(__write__/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(120,2);  // execute(__write__/2)
    case 155:  // __write_number__/2
      MACRO_goal(155,atom(79));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const int fd = value_of<int>(q1);
    const int64_t i = value_of<int64_t>(q2);
    const std::string s = std::to_string(i);
    for (size_t offset = 0; offset <  s.size();) {
      const ssize_t n = write(fd, s.c_str() + offset, s.size() - offset);
      if (n <= 0) {
        break;
      }
      offset += n;
    }
  }
  MACRO_proceed;
    case 156:  // __write_atom__/2
      MACRO_goal(156,atom(80));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const int fd = value_of<int>(q1);
    const std::string s = atom_str_of(q2);
    for (size_t offset = 0; offset <  s.size();) {
      const ssize_t n = write(fd, s.c_str() + offset, s.size() - offset);
      if (n <= 0) {
        break;
      }
      offset += n;
    }
  }
  MACRO_proceed;
    case 157:  // __write_var__/2
      MACRO_goal(157,atom(81));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const int fd = value_of<int>(q1);
    const A* a = ptr_of<A>(q2);
    std::stringstream ss;
    ss << a;
    const std::string s = ss.str();
    for (size_t offset = 0; offset <  s.size();) {
      const ssize_t n = write(fd, s.c_str() + offset, s.size() - offset);
      if (n <= 0) {
        break;
      }
      offset += n;
    }
  }
  MACRO_proceed;
    case 158:  // integer/1
      MACRO_goal(158,atom(21));
      MACRO_requires(2);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
    case 159:  // atom/1
      MACRO_goal(159,atom(13));
      MACRO_requires(2);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
    case 160:  // var/1
      MACRO_goal(160,atom(65));
      MACRO_requires(2);
  {
    const Q q = vm->in[1] = deref(vm->in[1]);
    const TAG_T tag = tag_of(q);
    if (tag != TAG_LREF && tag != TAG_REF && tag != TAG_SUS) {
      vm->fail();
      continue;
    }
  }
  MACRO_return;
    case 161:  // is_functor/1
      MACRO_goal(161,atom(70));
      MACRO_requires(2);
  MACRO_wait_for(TAG_STR, reg::in(1));
  {
    const Q q = vm->in[1];
    const TAG_T tag = tag_of(q);
    if (tag != TAG_STR) {
      vm->fail();
      continue;
    }
  }
  MACRO_return;
    case 162:  // (=..)/2
      MACRO_goal(162,atom(71));
      MACRO_requires(3);
  MACRO_wait_for(TAG_STR, reg::in(1));
  MACRO_activate;
  {
    const Q q = vm->in[1];
    A* p = ptr_of<A>(q);
    const Q Fun = p[0].load();
    const int arity = atom_arity_of(Fun);
    const size_t h = vm->heap_publishing((1 + arity) * 2);
    for (int i = 0; i <= arity; ++i) {
      vm->heap[h + i * 2].store(p[i].load());
      vm->heap[h + i * 2 + 1].store(
        (i < arity) ? tagptr<TAG_LIST>(&vm->heap[h + i * 2 + 2]) :
        tagptr<TAG_NIL, Q>(0));
    }
    vm->heap_published((1 + arity) * 2);
    if (!vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2])) {
      MACRO_fail;
    }
  }
  MACRO_proceed;
    case 163:  // (==)/2
      MACRO_goal(163,atom(82));
      MACRO_requires(3);
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    if (!(q1 == q2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 164:  // (>=)/2
      MACRO_goal(164,atom(83));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 >= v2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 165:  // (=<)/2
      MACRO_goal(165,atom(84));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 <= v2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 166:  // (>)/2
      MACRO_goal(166,atom(85));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 > v2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 167:  // (<)/2
      MACRO_goal(167,atom(86));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 < v2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 168:  // (=:=)/2
      MACRO_goal(168,atom(87));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(175,169,atom(88));  // spawn((:=)/2)
    case 169:  // return_from_spawn((:=)/2)
      MACRO_par(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(175,170,atom(88));  // spawn((:=)/2)
    case 170:  // return_from_spawn((:=)/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_execute(163,2);  // execute((==)/2)
    case 171:  // (=\=)/2
      MACRO_goal(171,atom(89));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(175,172,atom(88));  // spawn((:=)/2)
    case 172:  // return_from_spawn((:=)/2)
      MACRO_par(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(175,173,atom(88));  // spawn((:=)/2)
    case 173:  // return_from_spawn((:=)/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_execute(174,2);  // execute(__not_equal__/2)
    case 174:  // __not_equal__/2
      MACRO_goal(174,atom(90));
      MACRO_requires(3);
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    if (!(q1 != q2)) {
      MACRO_fail;
    }
  }
  MACRO_return;
    case 175:  // (:=)/2
      MACRO_goal(175,atom(88));
      MACRO_requires(8);
      MACRO_try_guard_else(177);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,176,atom(21));  // call(integer/1)
    case 176:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
    case 177:  // (:=)/2-2
      MACRO_try_guard_else(178);
      MACRO_check_structure(atom(91),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(183,3);  // execute(__add__/3)
    case 178:  // (:=)/2-3
      MACRO_try_guard_else(179);
      MACRO_check_structure(atom(92),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(189,3);  // execute(__sub__/3)
    case 179:  // (:=)/2-4
      MACRO_try_guard_else(180);
      MACRO_check_structure(atom(93),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(195,3);  // execute(__mul__/3)
    case 180:  // (:=)/2-5
      MACRO_try_guard_else(181);
      MACRO_check_structure(atom(94),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(201,3);  // execute(__div__/3)
    case 181:  // (:=)/2-6
      MACRO_try_guard_else(182);
      MACRO_check_structure(atom(95),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(207,3);  // execute(__mod__/3)
    case 182:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_structure(atom(96),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(2,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(213,2);  // execute(__neg__/2)
    case 183:  // __add__/3
      MACRO_goal(183,atom(45));
      MACRO_requires(9);
      MACRO_try_guard_else(186);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,184,atom(21));  // call(integer/1)
    case 184:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,185,atom(21));  // call(integer/1)
    case 185:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(218,3);  // execute(__iadd__/3)
    case 186:  // __add__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,187,atom(88));  // call((:=)/2)
    case 187:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(175,188,atom(88));  // call((:=)/2)
    case 188:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(218,3);  // execute(__iadd__/3)
    case 189:  // __sub__/3
      MACRO_goal(189,atom(97));
      MACRO_requires(9);
      MACRO_try_guard_else(192);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,190,atom(21));  // call(integer/1)
    case 190:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,191,atom(21));  // call(integer/1)
    case 191:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(219,3);  // execute(__isub__/3)
    case 192:  // __sub__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,193,atom(88));  // call((:=)/2)
    case 193:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(175,194,atom(88));  // call((:=)/2)
    case 194:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(219,3);  // execute(__isub__/3)
    case 195:  // __mul__/3
      MACRO_goal(195,atom(98));
      MACRO_requires(9);
      MACRO_try_guard_else(198);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,196,atom(21));  // call(integer/1)
    case 196:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,197,atom(21));  // call(integer/1)
    case 197:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(220,3);  // execute(__imul__/3)
    case 198:  // __mul__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,199,atom(88));  // call((:=)/2)
    case 199:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(175,200,atom(88));  // call((:=)/2)
    case 200:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(220,3);  // execute(__imul__/3)
    case 201:  // __div__/3
      MACRO_goal(201,atom(99));
      MACRO_requires(9);
      MACRO_try_guard_else(204);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,202,atom(21));  // call(integer/1)
    case 202:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,203,atom(21));  // call(integer/1)
    case 203:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(221,3);  // execute(__idiv__/3)
    case 204:  // __div__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,205,atom(88));  // call((:=)/2)
    case 205:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(175,206,atom(88));  // call((:=)/2)
    case 206:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(221,3);  // execute(__idiv__/3)
    case 207:  // __mod__/3
      MACRO_goal(207,atom(100));
      MACRO_requires(9);
      MACRO_try_guard_else(210);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,208,atom(21));  // call(integer/1)
    case 208:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,209,atom(21));  // call(integer/1)
    case 209:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(222,3);  // execute(__imod__/3)
    case 210:  // __mod__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,211,atom(88));  // call((:=)/2)
    case 211:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(175,212,atom(88));  // call((:=)/2)
    case 212:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(222,3);  // execute(__imod__/3)
    case 213:  // __neg__/2
      MACRO_goal(213,atom(101));
      MACRO_requires(6);
      MACRO_try_guard_else(215);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,214,atom(21));  // call(integer/1)
    case 214:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(217,2);  // execute(__ineg__/2)
    case 215:  // __neg__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,216,atom(88));  // call((:=)/2)
    case 216:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(217,2);  // execute(__ineg__/2)
    case 217:  // __ineg__/2
      MACRO_goal(217,atom(102));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 218:  // __iadd__/3
      MACRO_goal(218,atom(103));
      MACRO_requires(4);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 + v2;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  }
  MACRO_proceed;
    case 219:  // __isub__/3
      MACRO_goal(219,atom(104));
      MACRO_requires(4);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 - v2;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  }
  MACRO_proceed;
    case 220:  // __imul__/3
      MACRO_goal(220,atom(105));
      MACRO_requires(4);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 * v2;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  }
  MACRO_proceed;
    case 221:  // __idiv__/3
      MACRO_goal(221,atom(106));
      MACRO_requires(4);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 / v2;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  }
  MACRO_proceed;
    case 222:  // __imod__/3
      MACRO_goal(222,atom(107));
      MACRO_requires(4);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 % v2;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  }
  MACRO_proceed;
    case 223:  // __inc__/2
      MACRO_goal(223,atom(43));
      MACRO_requires(6);
      MACRO_try_guard_else(225);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,224,atom(21));  // call(integer/1)
    case 224:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(231,2);  // execute(__iinc__/2)
    case 225:  // __inc__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,226,atom(88));  // call((:=)/2)
    case 226:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(231,2);  // execute(__iinc__/2)
    case 227:  // __dec__/2
      MACRO_goal(227,atom(108));
      MACRO_requires(6);
      MACRO_try_guard_else(229);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,228,atom(21));  // call(integer/1)
    case 228:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(232,2);  // execute(__idec__/2)
    case 229:  // __dec__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(175,230,atom(88));  // call((:=)/2)
    case 230:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(232,2);  // execute(__idec__/2)
    case 231:  // __iinc__/2
      MACRO_goal(231,atom(109));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 232:  // __idec__/2
      MACRO_goal(232,atom(110));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 233:  // append/3
      MACRO_goal(233,atom(111));
      MACRO_requires(10);
      MACRO_try_guard_else(234);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 234:  // append/3-2
      MACRO_try_guard_else(235);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 235:  // append/3-3
      MACRO_try_guard_else(236);
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_check_list(reg::in(3));
      MACRO_read_value(reg::x(5));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_tail(3,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(233,3);  // execute(append/3)
    case 236:  // append/3-4
      MACRO_try_guard_else(237);
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_get_list(reg::in(3));
      MACRO_unify_value(reg::x(5));
      MACRO_unify_variable(reg::x(5));
      MACRO_tail(3,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(233,3);  // execute(append/3)
    case 237:  // append/3-5
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_void;
      MACRO_check_list(reg::in(3));
      MACRO_read_void;
      MACRO_read_void;
      MACRO_activate;
      MACRO_seq(2,6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_call(241,238,atom(112));  // call(reverse/2)
    case 238:  // return_from_call(reverse/2)
      MACRO_seq(2,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::y(5),reg::out(2));
      MACRO_call(241,239,atom(112));  // call(reverse/2)
    case 239:  // return_from_call(reverse/2)
      MACRO_seq(3,7);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_variable(reg::y(6),reg::out(2));
      MACRO_out_value(reg::y(5),reg::out(3));
      MACRO_call(233,240,atom(111));  // call(append/3)
    case 240:  // return_from_call(append/3)
      MACRO_tail(2,7);
      MACRO_out_value(reg::y(6),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(241,2);  // execute(reverse/2)
    case 241:  // reverse/2
      MACRO_goal(241,atom(112));
      MACRO_requires(7);
      MACRO_try_guard_else(243);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(160,242,atom(65));  // call(var/1)
    case 242:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(245,3);  // execute(__reverse__/3)
    case 243:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,244,atom(65));  // call(var/1)
    case 244:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(245,3);  // execute(__reverse__/3)
    case 245:  // __reverse__/3
      MACRO_goal(245,atom(113));
      MACRO_requires(10);
      MACRO_try_guard_else(246);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 246:  // __reverse__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(6));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_set_variable(reg::x(5));
      MACRO_get_list(reg::x(5));
      MACRO_unify_value(reg::x(6));
      MACRO_unify_value(reg::in(3));
      MACRO_tail(3,7);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(245,3);  // execute(__reverse__/3)
    case 247:  // nth0/3
      MACRO_goal(247,atom(114));
      MACRO_requires(9);
      MACRO_try_guard_else(249);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(160,248,atom(65));  // call(var/1)
    case 248:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(251,3);  // execute(__nth0__/3)
    case 249:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,250,atom(65));  // call(var/1)
    case 250:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(254,4);  // execute(__nth0_rev__/4)
    case 251:  // __nth0__/3
      MACRO_goal(251,atom(115));
      MACRO_requires(9);
      MACRO_try_guard_else(252);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 252:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(2,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_call(227,253,atom(108));  // call(__dec__/2)
    case 253:  // return_from_call(__dec__/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(251,3);  // execute(__nth0__/3)
    case 254:  // __nth0_rev__/4
      MACRO_goal(254,atom(116));
      MACRO_requires(11);
      MACRO_try_guard_else(255);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 255:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(2,7);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::y(5),reg::out(2));
      MACRO_call(223,256,atom(43));  // call(__inc__/2)
    case 256:  // return_from_call(__inc__/2)
      MACRO_tail(4,7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(6),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(5),reg::out(4));
      MACRO_execute(254,4);  // execute(__nth0_rev__/4)
    case 257:  // nth1/3
      MACRO_goal(257,atom(117));
      MACRO_requires(10);
      MACRO_try_guard_else(260);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(160,258,atom(65));  // call(var/1)
    case 258:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_call(227,259,atom(108));  // call(__dec__/2)
    case 259:  // return_from_call(__dec__/2)
      MACRO_tail(3,5);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(251,3);  // execute(__nth0__/3)
    case 260:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,261,atom(65));  // call(var/1)
    case 261:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(4,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(254,262,atom(116));  // spawn(__nth0_rev__/4)
    case 262:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(2,6);
      MACRO_out_value(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(223,2);  // execute(__inc__/2)
    case 263:  // inference_count/1
      MACRO_goal(263,atom(118));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(264,1);  // execute(__inference_count__/1)
    case 264:  // __inference_count__/1
      MACRO_goal(264,atom(119));
      MACRO_requires(2);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 265:  // resume_count/1
      MACRO_goal(265,atom(120));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(266,1);  // execute(__resume_count__/1)
    case 266:  // __resume_count__/1
      MACRO_goal(266,atom(121));
      MACRO_requires(2);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 267:  // dump_to_dot/1
      MACRO_goal(267,atom(122));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,268,atom(13));  // call(atom/1)
    case 268:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(269,1);  // execute(__dump_to_dot__/1)
    case 269:  // __dump_to_dot__/1
      MACRO_goal(269,atom(123));
      MACRO_requires(2);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  }
  MACRO_proceed;
    case 270:  // dump_to_dot/2
      MACRO_goal(270,atom(124));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,271,atom(13));  // call(atom/1)
    case 271:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(272,2);  // execute(__dump_to_dot__/2)
    case 272:  // __dump_to_dot__/2
      MACRO_goal(272,atom(125));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  }
  MACRO_proceed;
    case 273:  // tarai/4
      MACRO_goal(273,atom(126));
      MACRO_requires(11);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(4),reg::out(5));
      MACRO_execute(274,5);  // execute(tarai_aux/5)
    case 274:  // tarai_aux/5
      MACRO_goal(274,atom(127));
      MACRO_requires(17);
      MACRO_try_guard_else(277);
      MACRO_seq(1,7);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_call(160,275,atom(65));  // call(var/1)
    case 275:  // return_from_call(var/1)
      MACRO_seq(2,7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(165,276,atom(84));  // call((=<)/2)
    case 276:  // return_from_call((=<)/2)
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(4));
      MACRO_proceed;
    case 277:  // tarai_aux/5-2
      MACRO_try_guard_else(286);
      MACRO_seq(1,7);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_call(160,278,atom(65));  // call(var/1)
    case 278:  // return_from_call(var/1)
      MACRO_seq(2,7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(166,279,atom(85));  // call((>)/2)
    case 279:  // return_from_call((>)/2)
      MACRO_activate;
      MACRO_par(2,7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(6),reg::out(2));
      MACRO_call(227,280,atom(108));  // call(__dec__/2)
    case 280:  // return_from_call(__dec__/2)
      MACRO_par(5,8);
      MACRO_out_value(reg::y(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_variable(reg::y(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_spawn(274,281,atom(127));  // spawn(tarai_aux/5)
    case 281:  // return_from_spawn(tarai_aux/5)
      MACRO_par(2,9);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::y(8),reg::out(2));
      MACRO_call(227,282,atom(108));  // call(__dec__/2)
    case 282:  // return_from_call(__dec__/2)
      MACRO_par(5,10);
      MACRO_out_value(reg::y(8),reg::out(1));
      MACRO_out_value(reg::in(3),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_out_variable(reg::y(9),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_spawn(274,283,atom(127));  // spawn(tarai_aux/5)
    case 283:  // return_from_spawn(tarai_aux/5)
      MACRO_par(5,11);
      MACRO_out_value(reg::y(7),reg::out(1));
      MACRO_out_value(reg::y(9),reg::out(2));
      MACRO_out_variable(reg::y(10),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_spawn(274,284,atom(127));  // spawn(tarai_aux/5)
    case 284:  // return_from_spawn(tarai_aux/5)
      MACRO_par(2,12);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::y(11),reg::out(2));
      MACRO_call(227,285,atom(108));  // call(__dec__/2)
    case 285:  // return_from_call(__dec__/2)
      MACRO_tail(5,12);
      MACRO_out_value(reg::y(11),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_out_value(reg::y(10),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(274,5);  // execute(tarai_aux/5)
    case 286:  // tarai_aux/5-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_proceed;
    case 287:  // report/1
      MACRO_goal(287,atom(128));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_list(reg::out(1));
      MACRO_write_structure(atom(35));
      MACRO_write_value(reg::in(1));
      MACRO_write_nil;
      MACRO_execute(54,1);  // execute(outstream/1)
    case 288:  // main/1
      MACRO_goal(288,atom(129));
      MACRO_requires(10);
      MACRO_try_guard_else(294);
      MACRO_check_list(reg::in(1));
      MACRO_read_void;
      MACRO_read_list;
      MACRO_read_variable(reg::x(2));
      MACRO_read_list;
      MACRO_read_variable(reg::x(3));
      MACRO_read_list;
      MACRO_read_variable(reg::x(4));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_par(2,5);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::y(2),reg::out(2));
      MACRO_spawn(48,289,atom(26));  // spawn(atom_number/2)
    case 289:  // return_from_spawn(atom_number/2)
      MACRO_par(2,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(48,290,atom(26));  // spawn(atom_number/2)
    case 290:  // return_from_spawn(atom_number/2)
      MACRO_par(2,5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_spawn(48,291,atom(26));  // spawn(atom_number/2)
    case 291:  // return_from_spawn(atom_number/2)
      MACRO_par(1,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_spawn(287,292,atom(128));  // spawn(report/1)
    case 292:  // return_from_spawn(report/1)
      MACRO_par(1,6);
      MACRO_out_value(reg::y(5),reg::out(1));
      MACRO_spawn(13,293,atom(9));  // spawn(wait_time/1)
    case 293:  // return_from_spawn(wait_time/1)
      MACRO_tail(4,6);
      MACRO_out_value(reg::y(2),reg::out(1));
      MACRO_out_value(reg::y(3),reg::out(2));
      MACRO_out_value(reg::y(4),reg::out(3));
      MACRO_out_value(reg::y(5),reg::out(4));
      MACRO_execute(273,4);  // execute(tarai/4)
    case 294:  // main/1-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(6));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(1,7);
      MACRO_out_list(reg::out(1));
      MACRO_write_structure(atom(33));
      MACRO_write_constant(atom(130));
      MACRO_write_list;
      MACRO_write_structure(atom(33));
      MACRO_write_value(reg::x(6));
      MACRO_write_list;
      MACRO_write_structure(atom(33));
      MACRO_write_constant(atom(131));
      MACRO_write_list;
      MACRO_write_constant(atom(37));
      MACRO_write_nil;
      MACRO_execute(54,1);  // execute(outstream/1)
    default:
      throw RuntimeError();
    }
  }
}
void setup(Program* prog) {
  // setup atom constants
  atom(1) = to_atom("fail", 0);
  atom(2) = to_atom("call", 1);
  atom(3) = to_atom(",", 2);
  atom(4) = to_atom("__call__", 1);
  atom(5) = to_atom("call", 3);
  atom(6) = to_atom("__call__", 3);
  atom(7) = to_atom("time", 1);
  atom(8) = to_atom("__time_pre__", 3);
  atom(9) = to_atom("wait_time", 1);
  atom(10) = to_atom("__wait_time__", 4);
  atom(11) = to_atom("__time_post__", 3);
  atom(12) = to_atom("atom_concat", 3);
  atom(13) = to_atom("atom", 1);
  atom(14) = to_atom("__atom_concat_1__", 3);
  atom(15) = to_atom("__atom_concat_2__", 3);
  atom(16) = to_atom("__atom_concat_3__", 3);
  atom(17) = to_atom("atom_codes", 2);
  atom(18) = to_atom("", 0);
  atom(19) = to_atom("__atom_to_codes__", 2);
  atom(20) = to_atom("__codes_to_atom__", 3);
  atom(21) = to_atom("integer", 1);
  atom(22) = to_atom("__atom_code_concat__", 3);
  atom(23) = to_atom("atom_chars", 2);
  atom(24) = to_atom("__atom_to_chars__", 2);
  atom(25) = to_atom("__chars_to_atom__", 3);
  atom(26) = to_atom("atom_number", 2);
  atom(27) = to_atom("__atom_to_number__", 2);
  atom(28) = to_atom("__number_to_atom__", 2);
  atom(29) = to_atom("outstream", 1);
  atom(30) = to_atom("outstream", 2);
  atom(31) = to_atom("open", 3);
  atom(32) = to_atom("write", 2);
  atom(33) = to_atom("write", 1);
  atom(34) = to_atom("writeln", 2);
  atom(35) = to_atom("writeln", 1);
  atom(36) = to_atom("nl", 1);
  atom(37) = to_atom("nl", 0);
  atom(38) = to_atom("__open_opt_string_to_integer__", 3);
  atom(39) = to_atom("close", 1);
  atom(40) = to_atom("__open_opt_string_to_integer__", 5);
  atom(41) = to_atom("rdonly", 0);
  atom(42) = to_atom("wronly", 0);
  atom(43) = to_atom("__inc__", 2);
  atom(44) = to_atom("rdwr", 0);
  atom(45) = to_atom("__add__", 3);
  atom(46) = to_atom("creat", 0);
  atom(47) = to_atom("excl", 0);
  atom(48) = to_atom("trunc", 0);
  atom(49) = to_atom("append", 0);
  atom(50) = to_atom("rusr", 0);
  atom(51) = to_atom("wusr", 0);
  atom(52) = to_atom("xusr", 0);
  atom(53) = to_atom("rgrp", 0);
  atom(54) = to_atom("wgrp", 0);
  atom(55) = to_atom("xgrp", 0);
  atom(56) = to_atom("roth", 0);
  atom(57) = to_atom("woth", 0);
  atom(58) = to_atom("xoth", 0);
  atom(59) = to_atom("__open__", 4);
  atom(60) = to_atom("inline", 1);
  atom(61) = to_atom("  MACRO_proceed;", 0);
  atom(62) = to_atom("__close__", 1);
  atom(63) = to_atom("__nl__", 1);
  atom(64) = to_atom("__write__", 2);
  atom(65) = to_atom("var", 1);
  atom(66) = to_atom("[]", 0);
  atom(67) = to_atom("[", 0);
  atom(68) = to_atom("__write_list_tail__", 2);
  atom(69) = to_atom("]", 0);
  atom(70) = to_atom("is_functor", 1);
  atom(71) = to_atom("=..", 2);
  atom(72) = to_atom("__write_functor_args__", 2);
  atom(73) = to_atom("(", 0);
  atom(74) = to_atom("__write_functor_args2__", 2);
  atom(75) = to_atom(")", 0);
  atom(76) = to_atom("__write_functor_tail__", 2);
  atom(77) = to_atom(",", 0);
  atom(78) = to_atom("|", 0);
  atom(79) = to_atom("__write_number__", 2);
  atom(80) = to_atom("__write_atom__", 2);
  atom(81) = to_atom("__write_var__", 2);
  atom(82) = to_atom("==", 2);
  atom(83) = to_atom(">=", 2);
  atom(84) = to_atom("=<", 2);
  atom(85) = to_atom(">", 2);
  atom(86) = to_atom("<", 2);
  atom(87) = to_atom("=:=", 2);
  atom(88) = to_atom(":=", 2);
  atom(89) = to_atom("=\\=", 2);
  atom(90) = to_atom("__not_equal__", 2);
  atom(91) = to_atom("+", 2);
  atom(92) = to_atom("-", 2);
  atom(93) = to_atom("*", 2);
  atom(94) = to_atom("/", 2);
  atom(95) = to_atom("mod", 2);
  atom(96) = to_atom("-", 1);
  atom(97) = to_atom("__sub__", 3);
  atom(98) = to_atom("__mul__", 3);
  atom(99) = to_atom("__div__", 3);
  atom(100) = to_atom("__mod__", 3);
  atom(101) = to_atom("__neg__", 2);
  atom(102) = to_atom("__ineg__", 2);
  atom(103) = to_atom("__iadd__", 3);
  atom(104) = to_atom("__isub__", 3);
  atom(105) = to_atom("__imul__", 3);
  atom(106) = to_atom("__idiv__", 3);
  atom(107) = to_atom("__imod__", 3);
  atom(108) = to_atom("__dec__", 2);
  atom(109) = to_atom("__iinc__", 2);
  atom(110) = to_atom("__idec__", 2);
  atom(111) = to_atom("append", 3);
  atom(112) = to_atom("reverse", 2);
  atom(113) = to_atom("__reverse__", 3);
  atom(114) = to_atom("nth0", 3);
  atom(115) = to_atom("__nth0__", 3);
  atom(116) = to_atom("__nth0_rev__", 4);
  atom(117) = to_atom("nth1", 3);
  atom(118) = to_atom("inference_count", 1);
  atom(119) = to_atom("__inference_count__", 1);
  atom(120) = to_atom("resume_count", 1);
  atom(121) = to_atom("__resume_count__", 1);
  atom(122) = to_atom("dump_to_dot", 1);
  atom(123) = to_atom("__dump_to_dot__", 1);
  atom(124) = to_atom("dump_to_dot", 2);
  atom(125) = to_atom("__dump_to_dot__", 2);
  atom(126) = to_atom("tarai", 4);
  atom(127) = to_atom("tarai_aux", 5);
  atom(128) = to_atom("report", 1);
  atom(129) = to_atom("main", 1);
  atom(130) = to_atom("usage: ", 0);
  atom(131) = to_atom(" X Y Z", 0);
  // setup entry points
  prog->add_entry_point(atom(1), 1);  // fail / 0
  prog->add_entry_point(atom(2), 2);  // call / 1
  prog->add_entry_point(atom(4), 5);  // __call__ / 1
  prog->add_entry_point(atom(5), 6);  // call / 3
  prog->add_entry_point(atom(6), 9);  // __call__ / 3
  prog->add_entry_point(atom(7), 10);  // time / 1
  prog->add_entry_point(atom(9), 13);  // wait_time / 1
  prog->add_entry_point(atom(10), 15);  // __wait_time__ / 4
  prog->add_entry_point(atom(8), 16);  // __time_pre__ / 3
  prog->add_entry_point(atom(11), 17);  // __time_post__ / 3
  prog->add_entry_point(atom(12), 18);  // atom_concat / 3
  prog->add_entry_point(atom(14), 27);  // __atom_concat_1__ / 3
  prog->add_entry_point(atom(15), 28);  // __atom_concat_2__ / 3
  prog->add_entry_point(atom(16), 29);  // __atom_concat_3__ / 3
  prog->add_entry_point(atom(17), 30);  // atom_codes / 2
  prog->add_entry_point(atom(19), 33);  // __atom_to_codes__ / 2
  prog->add_entry_point(atom(20), 34);  // __codes_to_atom__ / 3
  prog->add_entry_point(atom(22), 39);  // __atom_code_concat__ / 3
  prog->add_entry_point(atom(23), 40);  // atom_chars / 2
  prog->add_entry_point(atom(24), 43);  // __atom_to_chars__ / 2
  prog->add_entry_point(atom(25), 44);  // __chars_to_atom__ / 3
  prog->add_entry_point(atom(26), 48);  // atom_number / 2
  prog->add_entry_point(atom(27), 52);  // __atom_to_number__ / 2
  prog->add_entry_point(atom(28), 53);  // __number_to_atom__ / 2
  prog->add_entry_point(atom(29), 54);  // outstream / 1
  prog->add_entry_point(atom(30), 56);  // outstream / 2
  prog->add_entry_point(atom(31), 70);  // open / 3
  prog->add_entry_point(atom(39), 72);  // close / 1
  prog->add_entry_point(atom(38), 73);  // __open_opt_string_to_integer__ / 3
  prog->add_entry_point(atom(40), 74);  // __open_opt_string_to_integer__ / 5
  prog->add_entry_point(atom(59), 106);  // __open__ / 4
  prog->add_entry_point(atom(60), 107);  // inline / 1
  prog->add_entry_point(atom(62), 108);  // __close__ / 1
  prog->add_entry_point(atom(35), 109);  // writeln / 1
  prog->add_entry_point(atom(34), 111);  // writeln / 2
  prog->add_entry_point(atom(37), 113);  // nl / 0
  prog->add_entry_point(atom(36), 114);  // nl / 1
  prog->add_entry_point(atom(63), 116);  // __nl__ / 1
  prog->add_entry_point(atom(33), 117);  // write / 1
  prog->add_entry_point(atom(32), 118);  // write / 2
  prog->add_entry_point(atom(64), 120);  // __write__ / 2
  prog->add_entry_point(atom(72), 135);  // __write_functor_args__ / 2
  prog->add_entry_point(atom(74), 139);  // __write_functor_args2__ / 2
  prog->add_entry_point(atom(76), 142);  // __write_functor_tail__ / 2
  prog->add_entry_point(atom(68), 146);  // __write_list_tail__ / 2
  prog->add_entry_point(atom(79), 155);  // __write_number__ / 2
  prog->add_entry_point(atom(80), 156);  // __write_atom__ / 2
  prog->add_entry_point(atom(81), 157);  // __write_var__ / 2
  prog->add_entry_point(atom(21), 158);  // integer / 1
  prog->add_entry_point(atom(13), 159);  // atom / 1
  prog->add_entry_point(atom(65), 160);  // var / 1
  prog->add_entry_point(atom(70), 161);  // is_functor / 1
  prog->add_entry_point(atom(71), 162);  // =.. / 2
  prog->add_entry_point(atom(82), 163);  // == / 2
  prog->add_entry_point(atom(83), 164);  // >= / 2
  prog->add_entry_point(atom(84), 165);  // =< / 2
  prog->add_entry_point(atom(85), 166);  // > / 2
  prog->add_entry_point(atom(86), 167);  // < / 2
  prog->add_entry_point(atom(87), 168);  // =:= / 2
  prog->add_entry_point(atom(89), 171);  // =\= / 2
  prog->add_entry_point(atom(90), 174);  // __not_equal__ / 2
  prog->add_entry_point(atom(88), 175);  // := / 2
  prog->add_entry_point(atom(45), 183);  // __add__ / 3
  prog->add_entry_point(atom(97), 189);  // __sub__ / 3
  prog->add_entry_point(atom(98), 195);  // __mul__ / 3
  prog->add_entry_point(atom(99), 201);  // __div__ / 3
  prog->add_entry_point(atom(100), 207);  // __mod__ / 3
  prog->add_entry_point(atom(101), 213);  // __neg__ / 2
  prog->add_entry_point(atom(102), 217);  // __ineg__ / 2
  prog->add_entry_point(atom(103), 218);  // __iadd__ / 3
  prog->add_entry_point(atom(104), 219);  // __isub__ / 3
  prog->add_entry_point(atom(105), 220);  // __imul__ / 3
  prog->add_entry_point(atom(106), 221);  // __idiv__ / 3
  prog->add_entry_point(atom(107), 222);  // __imod__ / 3
  prog->add_entry_point(atom(43), 223);  // __inc__ / 2
  prog->add_entry_point(atom(108), 227);  // __dec__ / 2
  prog->add_entry_point(atom(109), 231);  // __iinc__ / 2
  prog->add_entry_point(atom(110), 232);  // __idec__ / 2
  prog->add_entry_point(atom(111), 233);  // append / 3
  prog->add_entry_point(atom(112), 241);  // reverse / 2
  prog->add_entry_point(atom(113), 245);  // __reverse__ / 3
  prog->add_entry_point(atom(114), 247);  // nth0 / 3
  prog->add_entry_point(atom(115), 251);  // __nth0__ / 3
  prog->add_entry_point(atom(116), 254);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(117), 257);  // nth1 / 3
  prog->add_entry_point(atom(118), 263);  // inference_count / 1
  prog->add_entry_point(atom(119), 264);  // __inference_count__ / 1
  prog->add_entry_point(atom(120), 265);  // resume_count / 1
  prog->add_entry_point(atom(121), 266);  // __resume_count__ / 1
  prog->add_entry_point(atom(122), 267);  // dump_to_dot / 1
  prog->add_entry_point(atom(123), 269);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(124), 270);  // dump_to_dot / 2
  prog->add_entry_point(atom(125), 272);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(126), 273);  // tarai / 4
  prog->add_entry_point(atom(127), 274);  // tarai_aux / 5
  prog->add_entry_point(atom(128), 287);  // report / 1
  prog->add_entry_point(atom(129), 288);  // main / 1
}
int
main(int argc, char* argv[]) {
  Program prog;
  setup(&prog);
  std::vector<VM::ptr> vms;
  vms.push_back(std::make_shared<VM>());
  const int pc = prog.query_entry_point(to_atom("main", 1));
  if (pc < 0) {
    std::cerr << "failed to find main/1 predicate" << std::endl;
    return 1;
  }
  VM::ptr vm = vms[0];
  vm->pc = pc;
  vm->failed = false;
  A* head = NULL;
  A* prev_tail = NULL;
  for (int i = 0; i < argc; ++i) {
    const size_t h = vm->heap_publishing(2);
    if (!head) {
      head = &vm->heap[h];
    }
    if (prev_tail) {
      prev_tail->store(tagptr<TAG_LIST>(&vm->heap[h]));
    }
    vm->heap[h] = to_atom(argv[i], 0);
    vm->heap[h + 1].store(tagptr<TAG_REF>(&vm->heap[h + 1]));
    prev_tail = &vm->heap[h + 1];
    vm->heap_published(2);
  }
  prev_tail->store(tagptr<TAG_NIL, Q>(NULL));
  const size_t h = vm->heap_publishing(6);
  vm->heap[h + 0].store(tagptr<TAG_REF>(&vm->heap[h + 0]));
  vm->heap[h + 1].store(tagptr<TAG_REF>(&vm->heap[h + 2]));
  vm->heap[h + 2].store(tagvalue<TAG_INT>(0));
  vm->heap[h + 3].store(tagvalue<TAG_INT>(pc));
  vm->heap[h + 4].store(to_atom("main", 1));
  vm->heap[h + 5].store(tagptr<TAG_LIST, A>(head));
  vm->heap_published(6);
  A* lst = &vm->heap[h + 0];
  Scheduler::getInstance().enqueue_list(lst);
  vm->run(module, &prog);
}
