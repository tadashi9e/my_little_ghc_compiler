# include "./ghc.h"
#define atom(N) atom_ ## N
Q atom(1);  // fail / 0
Q atom(2);  // call / 1
Q atom(3);  // __call__ / 1
Q atom(4);  // time / 1
Q atom(5);  // wait_time / 1
Q atom(6);  // __wait_time__ / 4
Q atom(7);  // __time_pre__ / 3
Q atom(8);  // __time_post__ / 3
Q atom(9);  // atom_concat / 3
Q atom(10);  // __atom_concat_1__ / 3
Q atom(11);  // __atom_concat_2__ / 3
Q atom(12);  // __atom_concat_3__ / 3
Q atom(13);  // atom_codes / 2
Q atom(14);  //  / 0
Q atom(15);  // __atom_to_codes__ / 2
Q atom(16);  // __codes_to_atom__ / 3
Q atom(17);  // __atom_code_concat__ / 3
Q atom(18);  // inline / 1
Q atom(19);  //   MACRO_proceed; / 0
Q atom(20);  // atom_chars / 2
Q atom(21);  // __atom_to_chars__ / 2
Q atom(22);  // __chars_to_atom__ / 3
Q atom(23);  // atom_number / 2
Q atom(24);  // __atom_to_number__ / 2
Q atom(25);  // __number_to_atom__ / 2
Q atom(26);  // outstream / 1
Q atom(27);  // outstream / 2
Q atom(28);  // open / 3
Q atom(29);  // write / 2
Q atom(30);  // write / 1
Q atom(31);  // writeln / 2
Q atom(32);  // writeln / 1
Q atom(33);  // nl / 1
Q atom(34);  // nl / 0
Q atom(35);  // close / 1
Q atom(36);  // __open_opt_string_to_integer__ / 3
Q atom(37);  // __open_opt_string_to_integer__ / 5
Q atom(38);  // rdonly / 0
Q atom(39);  // wronly / 0
Q atom(40);  // rdwr / 0
Q atom(41);  // creat / 0
Q atom(42);  // excl / 0
Q atom(43);  // trunc / 0
Q atom(44);  // append / 0
Q atom(45);  // rusr / 0
Q atom(46);  // wusr / 0
Q atom(47);  // xusr / 0
Q atom(48);  // rgrp / 0
Q atom(49);  // wgrp / 0
Q atom(50);  // xgrp / 0
Q atom(51);  // roth / 0
Q atom(52);  // woth / 0
Q atom(53);  // xoth / 0
Q atom(54);  // __open__ / 4
Q atom(55);  // __close__ / 1
Q atom(56);  // __nl__ / 1
Q atom(57);  // __write__ / 2
Q atom(58);  // [] / 0
Q atom(59);  // [ / 0
Q atom(60);  // ] / 0
Q atom(61);  // __write_functor_args__ / 2
Q atom(62);  // ( / 0
Q atom(63);  // ) / 0
Q atom(64);  // __write_functor_args2__ / 2
Q atom(65);  // __write_functor_tail__ / 2
Q atom(66);  // , / 0
Q atom(67);  // __write_list_tail__ / 2
Q atom(68);  // | / 0
Q atom(69);  // __write_number__ / 2
Q atom(70);  // __write_atom__ / 2
Q atom(71);  // __write_var__ / 2
Q atom(72);  // integer / 1
Q atom(73);  // atom / 1
Q atom(74);  // var / 1
Q atom(75);  // is_functor / 1
Q atom(76);  // =.. / 2
Q atom(77);  // == / 2
Q atom(78);  // >= / 2
Q atom(79);  // =< / 2
Q atom(80);  // > / 2
Q atom(81);  // < / 2
Q atom(82);  // =:= / 2
Q atom(83);  // =\= / 2
Q atom(84);  // __not_equal__ / 2
Q atom(85);  // := / 2
Q atom(86);  // + / 2
Q atom(87);  // - / 2
Q atom(88);  // * / 2
Q atom(89);  // / / 2
Q atom(90);  // mod / 2
Q atom(91);  // - / 1
Q atom(92);  // __add__ / 3
Q atom(93);  // __sub__ / 3
Q atom(94);  // __mul__ / 3
Q atom(95);  // __div__ / 3
Q atom(96);  // __mod__ / 3
Q atom(97);  // __neg__ / 2
Q atom(98);  // __ineg__ / 2
Q atom(99);  // __iadd__ / 3
Q atom(100);  // __isub__ / 3
Q atom(101);  // __imul__ / 3
Q atom(102);  // __idiv__ / 3
Q atom(103);  // __imod__ / 3
Q atom(104);  // __inc__ / 2
Q atom(105);  // __dec__ / 2
Q atom(106);  // __iinc__ / 2
Q atom(107);  // __idec__ / 2
Q atom(108);  // append / 3
Q atom(109);  // reverse / 2
Q atom(110);  // __reverse__ / 3
Q atom(111);  // nth0 / 3
Q atom(112);  // __nth0__ / 3
Q atom(113);  // __nth0_rev__ / 4
Q atom(114);  // nth1 / 3
Q atom(115);  // inference_count / 1
Q atom(116);  // __inference_count__ / 1
Q atom(117);  // resume_count / 1
Q atom(118);  // __resume_count__ / 1
Q atom(119);  // dump_to_dot / 1
Q atom(120);  // __dump_to_dot__ / 1
Q atom(121);  // dump_to_dot / 2
Q atom(122);  // __dump_to_dot__ / 2
Q atom(123);  // main / 1
Q atom(124);  // Hello  / 0
Q atom(125);  // dump/hello.dot / 0
Q atom(126);  // writes / 2
Q atom(127);  //   / 0
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
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(3,1);  // execute(__call__/1)
    case 3:  // __call__/1
      MACRO_goal(3,atom(3));
      MACRO_requires(3);
  MACRO_wait(reg::in(1));
  {
    Q q = vm->in[1];
    const TAG_T tag = tag_of(q);
    if (tag == TAG_ATOM) {
      MACRO_activate;
      const int pc = prog->query_entry_point(q);
      MACRO_execute(pc, 0);
    } else if (tag == TAG_STR) {
      MACRO_activate;
      A* structure = ptr_of<A>(q);
      Q g = structure[0].load();
      const int pc = prog->query_entry_point(g);
      if (pc < 0) {
        vm->fail();
        continue;
      }
      const int arity = atom_arity_of(g);
      MACRO_tail(2);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_execute(pc, arity);
    } else {
      MACRO_fail;
    }
  }
    case 4:  // time/1
      MACRO_goal(4,atom(4));
      MACRO_requires(8);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_variable(reg::x(4),reg::out(3));
      MACRO_call(10,5);  // call(__time_pre__/3)
    case 5:  // return_from_call(__time_pre__/3)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(2,6);  // call(call/1)
    case 6:  // return_from_call(call/1)
      MACRO_tail(5);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_out_value(reg::x(4),reg::out(3));
      MACRO_execute(11,3);  // execute(__time_post__/3)
    case 7:  // wait_time/1
      MACRO_goal(7,atom(5));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_variable(reg::x(4),reg::out(3));
      MACRO_spawn(10,8);  // spawn(__time_pre__/3)
    case 8:  // return_from_spawn(__time_pre__/3)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_out_value(reg::x(4),reg::out(4));
      MACRO_execute(9,4);  // execute(__wait_time__/4)
    case 9:  // __wait_time__/4
      MACRO_goal(9,atom(6));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(3),reg::out(2));
      MACRO_out_value(reg::in(4),reg::out(3));
      MACRO_execute(11,3);  // execute(__time_post__/3)
    case 10:  // __time_pre__/3
      MACRO_goal(10,atom(7));
      MACRO_requires(7);
  MACRO_activate;
  {
    const int64_t istart = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
    MACRO_get_constant(tagvalue<TAG_INT>(istart), reg::in(1));
  }
  MACRO_get_constant(tagvalue<TAG_INT>(vm->inference_count), reg::in(2));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->resume_count), reg::in(3));
  MACRO_proceed;
    case 11:  // __time_post__/3
      MACRO_goal(11,atom(8));
      MACRO_requires(7);
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
    case 12:  // atom_concat/3
      MACRO_goal(12,atom(9));
      MACRO_requires(7);
      MACRO_try_guard_else(15);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,13);  // call(atom/1)
    case 13:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(152,14);  // call(atom/1)
    case 14:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(21,3);  // execute(__atom_concat_1__/3)
    case 15:  // atom_concat/3-2
      MACRO_try_guard_else(18);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,16);  // call(atom/1)
    case 16:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(152,17);  // call(atom/1)
    case 17:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(22,3);  // execute(__atom_concat_2__/3)
    case 18:  // atom_concat/3-3
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(152,19);  // call(atom/1)
    case 19:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(152,20);  // call(atom/1)
    case 20:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(23,3);  // execute(__atom_concat_3__/3)
    case 21:  // __atom_concat_1__/3
      MACRO_goal(21,atom(10));
      MACRO_requires(7);
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
    case 22:  // __atom_concat_2__/3
      MACRO_goal(22,atom(11));
      MACRO_requires(7);
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
    case 23:  // __atom_concat_3__/3
      MACRO_goal(23,atom(12));
      MACRO_requires(7);
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
    case 24:  // atom_codes/2
      MACRO_goal(24,atom(13));
      MACRO_requires(8);
      MACRO_try_guard_else(26);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,25);  // call(atom/1)
    case 25:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(27,2);  // execute(__atom_to_codes__/2)
    case 26:  // atom_codes/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_list(reg::out(2));
      MACRO_write_value(reg::x(3));
      MACRO_write_value(reg::x(4));
      MACRO_out_constant(atom(14),reg::out(3));
      MACRO_execute(28,3);  // execute(__codes_to_atom__/3)
    case 27:  // __atom_to_codes__/2
      MACRO_goal(27,atom(15));
      MACRO_requires(5);
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
    case 28:  // __codes_to_atom__/3
      MACRO_goal(28,atom(16));
      MACRO_requires(9);
      MACRO_try_guard_else(29);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 29:  // __codes_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_seq(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_call(151,30);  // call(integer/1)
    case 30:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(32,31);  // spawn(__atom_code_concat__/3)
    case 31:  // return_from_spawn(__atom_code_concat__/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(28,3);  // execute(__codes_to_atom__/3)
    case 32:  // __atom_code_concat__/3
      MACRO_goal(32,atom(17));
      MACRO_requires(7);
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
    case 33:  // inline/1
      MACRO_goal(33,atom(18));
      MACRO_requires(3);
      MACRO_try_guard_else(34);
      MACRO_check_constant(atom(19),reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 34:  // inline/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(19),reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 35:  // atom_chars/2
      MACRO_goal(35,atom(20));
      MACRO_requires(8);
      MACRO_try_guard_else(37);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,36);  // call(atom/1)
    case 36:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(38,2);  // execute(__atom_to_chars__/2)
    case 37:  // atom_chars/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_execute(39,3);  // execute(__chars_to_atom__/3)
    case 38:  // __atom_to_chars__/2
      MACRO_goal(38,atom(21));
      MACRO_requires(5);
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
    case 39:  // __chars_to_atom__/3
      MACRO_goal(39,atom(22));
      MACRO_requires(9);
      MACRO_try_guard_else(40);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 40:  // __chars_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(12,41);  // spawn(atom_concat/3)
    case 41:  // return_from_spawn(atom_concat/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(39,3);  // execute(__chars_to_atom__/3)
    case 42:  // atom_number/2
      MACRO_goal(42,atom(23));
      MACRO_requires(5);
      MACRO_try_guard_else(44);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,43);  // call(atom/1)
    case 43:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(46,2);  // execute(__atom_to_number__/2)
    case 44:  // atom_number/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,45);  // call(integer/1)
    case 45:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(47,2);  // execute(__number_to_atom__/2)
    case 46:  // __atom_to_number__/2
      MACRO_goal(46,atom(24));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_get_constant(tagvalue<TAG_INT>(i), reg::in(2));
  }
  MACRO_proceed;
    case 47:  // __number_to_atom__/2
      MACRO_goal(47,atom(25));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[2];
    const int64_t i = value_of<int64_t>(q);
    const std::string s = std::to_string(i);
    MACRO_get_constant(to_atom(s.c_str(), 0), reg::in(1));
  }
  MACRO_proceed;
    case 48:  // outstream/1
      MACRO_goal(48,atom(26));
      MACRO_requires(6);
      MACRO_try_guard_else(49);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 49:  // outstream/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(50,2);  // execute(outstream/2)
    case 50:  // outstream/2
      MACRO_goal(50,atom(27));
      MACRO_requires(9);
      MACRO_try_guard_else(52);
      MACRO_check_structure(atom(28),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(64,51);  // spawn(open/3)
    case 51:  // return_from_spawn(open/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 52:  // outstream/2-2
      MACRO_try_guard_else(54);
      MACRO_check_structure(atom(29),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(111,53);  // spawn(write/2)
    case 53:  // return_from_spawn(write/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 54:  // outstream/2-3
      MACRO_try_guard_else(56);
      MACRO_check_structure(atom(30),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(110,55);  // spawn(write/1)
    case 55:  // return_from_spawn(write/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 56:  // outstream/2-4
      MACRO_try_guard_else(58);
      MACRO_check_structure(atom(31),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(104,57);  // spawn(writeln/2)
    case 57:  // return_from_spawn(writeln/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 58:  // outstream/2-5
      MACRO_try_guard_else(60);
      MACRO_check_structure(atom(32),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(102,59);  // spawn(writeln/1)
    case 59:  // return_from_spawn(writeln/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 60:  // outstream/2-6
      MACRO_try_guard_else(62);
      MACRO_check_structure(atom(33),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(107,61);  // spawn(nl/1)
    case 61:  // return_from_spawn(nl/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 62:  // outstream/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(34),reg::in(1));
      MACRO_activate;
      MACRO_par(6);
      MACRO_spawn(106,63);  // spawn(nl/0)
    case 63:  // return_from_spawn(nl/0)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(48,1);  // execute(outstream/1)
    case 64:  // open/3
      MACRO_goal(64,atom(28));
      MACRO_requires(10);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(67,65);  // spawn(__open_opt_string_to_integer__/3)
    case 65:  // return_from_spawn(__open_opt_string_to_integer__/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_out_value(reg::in(3),reg::out(4));
      MACRO_execute(100,4);  // execute(__open__/4)
    case 66:  // close/1
      MACRO_goal(66,atom(35));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(101,1);  // execute(__close__/1)
    case 67:  // __open_opt_string_to_integer__/3
      MACRO_goal(67,atom(36));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 68:  // __open_opt_string_to_integer__/5
      MACRO_goal(68,atom(37));
      MACRO_requires(13);
      MACRO_try_guard_else(69);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(2));
      MACRO_get_value(reg::in(5),reg::in(3));
      MACRO_proceed;
    case 69:  // __open_opt_string_to_integer__/5-2
      MACRO_try_guard_else(70);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(38));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_tail(7);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 70:  // __open_opt_string_to_integer__/5-3
      MACRO_try_guard_else(72);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(39));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(216,71);  // call(__inc__/2)
    case 71:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 72:  // __open_opt_string_to_integer__/5-4
      MACRO_try_guard_else(74);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(40));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,73);  // call(__add__/3)
    case 73:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 74:  // __open_opt_string_to_integer__/5-5
      MACRO_try_guard_else(76);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(41));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,75);  // call(__add__/3)
    case 75:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 76:  // __open_opt_string_to_integer__/5-6
      MACRO_try_guard_else(78);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(42));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,77);  // call(__add__/3)
    case 77:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 78:  // __open_opt_string_to_integer__/5-7
      MACRO_try_guard_else(80);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(43));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,79);  // call(__add__/3)
    case 79:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 80:  // __open_opt_string_to_integer__/5-8
      MACRO_try_guard_else(82);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(44));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,81);  // call(__add__/3)
    case 81:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 82:  // __open_opt_string_to_integer__/5-9
      MACRO_try_guard_else(84);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(45));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,83);  // call(__add__/3)
    case 83:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 84:  // __open_opt_string_to_integer__/5-10
      MACRO_try_guard_else(86);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(46));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,85);  // call(__add__/3)
    case 85:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 86:  // __open_opt_string_to_integer__/5-11
      MACRO_try_guard_else(88);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(47));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,87);  // call(__add__/3)
    case 87:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 88:  // __open_opt_string_to_integer__/5-12
      MACRO_try_guard_else(90);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(48));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,89);  // call(__add__/3)
    case 89:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 90:  // __open_opt_string_to_integer__/5-13
      MACRO_try_guard_else(92);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(49));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,91);  // call(__add__/3)
    case 91:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 92:  // __open_opt_string_to_integer__/5-14
      MACRO_try_guard_else(94);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(50));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,93);  // call(__add__/3)
    case 93:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 94:  // __open_opt_string_to_integer__/5-15
      MACRO_try_guard_else(96);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(51));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,95);  // call(__add__/3)
    case 95:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 96:  // __open_opt_string_to_integer__/5-16
      MACRO_try_guard_else(98);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(52));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(176,97);  // call(__add__/3)
    case 97:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 98:  // __open_opt_string_to_integer__/5-17
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(53));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(216,99);  // call(__inc__/2)
    case 99:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(68,5);  // execute(__open_opt_string_to_integer__/5)
    case 100:  // __open__/4
      MACRO_goal(100,atom(54));
      MACRO_requires(9);
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
    case 101:  // __close__/1
      MACRO_goal(101,atom(55));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
  }
  MACRO_proceed;
    case 102:  // writeln/1
      MACRO_goal(102,atom(32));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(110,103);  // call(write/1)
    case 103:  // return_from_call(write/1)
      MACRO_tail(3);
      MACRO_execute(106,0);  // execute(nl/0)
    case 104:  // writeln/2
      MACRO_goal(104,atom(31));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(111,105);  // spawn(write/2)
    case 105:  // return_from_spawn(write/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(107,1);  // execute(nl/1)
    case 106:  // nl/0
      MACRO_goal(106,atom(34));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(107,1);  // execute(nl/1)
    case 107:  // nl/1
      MACRO_goal(107,atom(33));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,108);  // call(integer/1)
    case 108:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(109,1);  // execute(__nl__/1)
    case 109:  // __nl__/1
      MACRO_goal(109,atom(56));
      MACRO_requires(3);
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
    case 110:  // write/1
      MACRO_goal(110,atom(30));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(111,2);  // execute(write/2)
    case 111:  // write/2
      MACRO_goal(111,atom(29));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,112);  // call(integer/1)
    case 112:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 113:  // __write__/2
      MACRO_goal(113,atom(57));
      MACRO_requires(7);
      MACRO_try_guard_else(115);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(152,114);  // call(atom/1)
    case 114:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(149,2);  // execute(__write_atom__/2)
    case 115:  // __write__/2-2
      MACRO_try_guard_else(117);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,116);  // call(var/1)
    case 116:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(150,2);  // execute(__write_var__/2)
    case 117:  // __write__/2-3
      MACRO_try_guard_else(119);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,118);  // call(integer/1)
    case 118:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(148,2);  // execute(__write_number__/2)
    case 119:  // __write__/2-4
      MACRO_try_guard_else(120);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(58),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 120:  // __write__/2-5
      MACRO_try_guard_else(124);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(59),reg::out(2));
      MACRO_call(113,121);  // call(__write__/2)
    case 121:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(113,122);  // call(__write__/2)
    case 122:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_call(139,123);  // call(__write_list_tail__/2)
    case 123:  // return_from_call(__write_list_tail__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(60),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 124:  // __write__/2-6
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(154,125);  // call(is_functor/1)
    case 125:  // return_from_call(is_functor/1)
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_list(reg::out(2));
      MACRO_write_variable(reg::x(4));
      MACRO_write_variable(reg::x(3));
      MACRO_call(155,126);  // call((=..)/2)
    case 126:  // return_from_call((=..)/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(113,127);  // call(__write__/2)
    case 127:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(128,2);  // execute(__write_functor_args__/2)
    case 128:  // __write_functor_args__/2
      MACRO_goal(128,atom(61));
      MACRO_requires(5);
      MACRO_try_guard_else(129);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 129:  // __write_functor_args__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(62),reg::out(2));
      MACRO_call(113,130);  // call(__write__/2)
    case 130:  // return_from_call(__write__/2)
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(132,131);  // call(__write_functor_args2__/2)
    case 131:  // return_from_call(__write_functor_args2__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(63),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 132:  // __write_functor_args2__/2
      MACRO_goal(132,atom(64));
      MACRO_requires(7);
      MACRO_try_guard_else(133);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 133:  // __write_functor_args2__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(113,134);  // call(__write__/2)
    case 134:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(135,2);  // execute(__write_functor_tail__/2)
    case 135:  // __write_functor_tail__/2
      MACRO_goal(135,atom(65));
      MACRO_requires(7);
      MACRO_try_guard_else(136);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 136:  // __write_functor_tail__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(66),reg::out(2));
      MACRO_call(113,137);  // call(__write__/2)
    case 137:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(113,138);  // call(__write__/2)
    case 138:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(135,2);  // execute(__write_functor_tail__/2)
    case 139:  // __write_list_tail__/2
      MACRO_goal(139,atom(67));
      MACRO_requires(7);
      MACRO_try_guard_else(142);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,140);  // call(var/1)
    case 140:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(68),reg::out(2));
      MACRO_call(113,141);  // call(__write__/2)
    case 141:  // return_from_call(__write__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 142:  // __write_list_tail__/2-2
      MACRO_try_guard_else(143);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 143:  // __write_list_tail__/2-3
      MACRO_try_guard_else(146);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(66),reg::out(2));
      MACRO_call(113,144);  // call(__write__/2)
    case 144:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(113,145);  // call(__write__/2)
    case 145:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(139,2);  // execute(__write_list_tail__/2)
    case 146:  // __write_list_tail__/2-4
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(68),reg::out(2));
      MACRO_call(113,147);  // call(__write__/2)
    case 147:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(113,2);  // execute(__write__/2)
    case 148:  // __write_number__/2
      MACRO_goal(148,atom(69));
      MACRO_requires(5);
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
    case 149:  // __write_atom__/2
      MACRO_goal(149,atom(70));
      MACRO_requires(5);
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
    case 150:  // __write_var__/2
      MACRO_goal(150,atom(71));
      MACRO_requires(5);
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
    case 151:  // integer/1
      MACRO_goal(151,atom(72));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
    case 152:  // atom/1
      MACRO_goal(152,atom(73));
      MACRO_requires(3);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
    case 153:  // var/1
      MACRO_goal(153,atom(74));
      MACRO_requires(3);
  {
    const Q q = vm->in[1] = deref(vm->in[1]);
    const TAG_T tag = tag_of(q);
    if (tag != TAG_REF && tag != TAG_SUS) {
      vm->fail();
      continue;
    }
  }
  MACRO_return;
    case 154:  // is_functor/1
      MACRO_goal(154,atom(75));
      MACRO_requires(3);
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
    case 155:  // (=..)/2
      MACRO_goal(155,atom(76));
      MACRO_requires(5);
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
    case 156:  // (==)/2
      MACRO_goal(156,atom(77));
      MACRO_requires(5);
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
    case 157:  // (>=)/2
      MACRO_goal(157,atom(78));
      MACRO_requires(5);
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
    case 158:  // (=<)/2
      MACRO_goal(158,atom(79));
      MACRO_requires(5);
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
    case 159:  // (>)/2
      MACRO_goal(159,atom(80));
      MACRO_requires(5);
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
    case 160:  // (<)/2
      MACRO_goal(160,atom(81));
      MACRO_requires(5);
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
    case 161:  // (=:=)/2
      MACRO_goal(161,atom(82));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,162);  // spawn((:=)/2)
    case 162:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,163);  // spawn((:=)/2)
    case 163:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(156,2);  // execute((==)/2)
    case 164:  // (=\=)/2
      MACRO_goal(164,atom(83));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,165);  // spawn((:=)/2)
    case 165:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,166);  // spawn((:=)/2)
    case 166:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(167,2);  // execute(__not_equal__/2)
    case 167:  // __not_equal__/2
      MACRO_goal(167,atom(84));
      MACRO_requires(5);
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
    case 168:  // (:=)/2
      MACRO_goal(168,atom(85));
      MACRO_requires(8);
      MACRO_try_guard_else(170);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,169);  // call(integer/1)
    case 169:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
    case 170:  // (:=)/2-2
      MACRO_try_guard_else(171);
      MACRO_check_structure(atom(86),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(176,3);  // execute(__add__/3)
    case 171:  // (:=)/2-3
      MACRO_try_guard_else(172);
      MACRO_check_structure(atom(87),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(182,3);  // execute(__sub__/3)
    case 172:  // (:=)/2-4
      MACRO_try_guard_else(173);
      MACRO_check_structure(atom(88),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(188,3);  // execute(__mul__/3)
    case 173:  // (:=)/2-5
      MACRO_try_guard_else(174);
      MACRO_check_structure(atom(89),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(194,3);  // execute(__div__/3)
    case 174:  // (:=)/2-6
      MACRO_try_guard_else(175);
      MACRO_check_structure(atom(90),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(200,3);  // execute(__mod__/3)
    case 175:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_structure(atom(91),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(206,2);  // execute(__neg__/2)
    case 176:  // __add__/3
      MACRO_goal(176,atom(92));
      MACRO_requires(9);
      MACRO_try_guard_else(179);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,177);  // call(integer/1)
    case 177:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,178);  // call(integer/1)
    case 178:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(211,3);  // execute(__iadd__/3)
    case 179:  // __add__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,180);  // spawn((:=)/2)
    case 180:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,181);  // spawn((:=)/2)
    case 181:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(211,3);  // execute(__iadd__/3)
    case 182:  // __sub__/3
      MACRO_goal(182,atom(93));
      MACRO_requires(9);
      MACRO_try_guard_else(185);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,183);  // call(integer/1)
    case 183:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,184);  // call(integer/1)
    case 184:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(212,3);  // execute(__isub__/3)
    case 185:  // __sub__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,186);  // spawn((:=)/2)
    case 186:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,187);  // spawn((:=)/2)
    case 187:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(212,3);  // execute(__isub__/3)
    case 188:  // __mul__/3
      MACRO_goal(188,atom(94));
      MACRO_requires(9);
      MACRO_try_guard_else(191);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,189);  // call(integer/1)
    case 189:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,190);  // call(integer/1)
    case 190:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__imul__/3)
    case 191:  // __mul__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,192);  // spawn((:=)/2)
    case 192:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,193);  // spawn((:=)/2)
    case 193:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__imul__/3)
    case 194:  // __div__/3
      MACRO_goal(194,atom(95));
      MACRO_requires(9);
      MACRO_try_guard_else(197);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,195);  // call(integer/1)
    case 195:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,196);  // call(integer/1)
    case 196:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__idiv__/3)
    case 197:  // __div__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,198);  // spawn((:=)/2)
    case 198:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,199);  // spawn((:=)/2)
    case 199:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__idiv__/3)
    case 200:  // __mod__/3
      MACRO_goal(200,atom(96));
      MACRO_requires(9);
      MACRO_try_guard_else(203);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,201);  // call(integer/1)
    case 201:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,202);  // call(integer/1)
    case 202:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__imod__/3)
    case 203:  // __mod__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,204);  // spawn((:=)/2)
    case 204:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(168,205);  // spawn((:=)/2)
    case 205:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__imod__/3)
    case 206:  // __neg__/2
      MACRO_goal(206,atom(97));
      MACRO_requires(6);
      MACRO_try_guard_else(208);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,207);  // call(integer/1)
    case 207:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(210,2);  // execute(__ineg__/2)
    case 208:  // __neg__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,209);  // spawn((:=)/2)
    case 209:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(210,2);  // execute(__ineg__/2)
    case 210:  // __ineg__/2
      MACRO_goal(210,atom(98));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 211:  // __iadd__/3
      MACRO_goal(211,atom(99));
      MACRO_requires(7);
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
    case 212:  // __isub__/3
      MACRO_goal(212,atom(100));
      MACRO_requires(7);
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
    case 213:  // __imul__/3
      MACRO_goal(213,atom(101));
      MACRO_requires(7);
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
    case 214:  // __idiv__/3
      MACRO_goal(214,atom(102));
      MACRO_requires(7);
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
    case 215:  // __imod__/3
      MACRO_goal(215,atom(103));
      MACRO_requires(7);
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
    case 216:  // __inc__/2
      MACRO_goal(216,atom(104));
      MACRO_requires(6);
      MACRO_try_guard_else(218);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,217);  // call(integer/1)
    case 217:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(224,2);  // execute(__iinc__/2)
    case 218:  // __inc__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,219);  // spawn((:=)/2)
    case 219:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(224,2);  // execute(__iinc__/2)
    case 220:  // __dec__/2
      MACRO_goal(220,atom(105));
      MACRO_requires(6);
      MACRO_try_guard_else(222);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,221);  // call(integer/1)
    case 221:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(225,2);  // execute(__idec__/2)
    case 222:  // __dec__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(168,223);  // spawn((:=)/2)
    case 223:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(225,2);  // execute(__idec__/2)
    case 224:  // __iinc__/2
      MACRO_goal(224,atom(106));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 225:  // __idec__/2
      MACRO_goal(225,atom(107));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 226:  // append/3
      MACRO_goal(226,atom(108));
      MACRO_requires(9);
      MACRO_try_guard_else(227);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 227:  // append/3-2
      MACRO_try_guard_else(228);
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_check_list(reg::in(3));
      MACRO_read_value(reg::x(5));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(226,3);  // execute(append/3)
    case 228:  // append/3-3
      MACRO_try_guard_else(229);
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_get_list(reg::in(3));
      MACRO_unify_value(reg::x(5));
      MACRO_unify_variable(reg::x(5));
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(226,3);  // execute(append/3)
    case 229:  // append/3-4
      MACRO_try_guard_else_suspend;
      MACRO_seq(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,230);  // call(var/1)
    case 230:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_spawn(234,231);  // spawn(reverse/2)
    case 231:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_spawn(234,232);  // spawn(reverse/2)
    case 232:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(226,233);  // spawn(append/3)
    case 233:  // return_from_spawn(append/3)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(234,2);  // execute(reverse/2)
    case 234:  // reverse/2
      MACRO_goal(234,atom(109));
      MACRO_requires(6);
      MACRO_try_guard_else(236);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,235);  // call(var/1)
    case 235:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(238,3);  // execute(__reverse__/3)
    case 236:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,237);  // call(var/1)
    case 237:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(238,3);  // execute(__reverse__/3)
    case 238:  // __reverse__/3
      MACRO_goal(238,atom(110));
      MACRO_requires(10);
      MACRO_try_guard_else(239);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 239:  // __reverse__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(6));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_set_variable(reg::x(5));
      MACRO_get_list(reg::x(5));
      MACRO_unify_value(reg::x(6));
      MACRO_unify_value(reg::in(3));
      MACRO_tail(7);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(238,3);  // execute(__reverse__/3)
    case 240:  // nth0/3
      MACRO_goal(240,atom(111));
      MACRO_requires(8);
      MACRO_try_guard_else(242);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(153,241);  // call(var/1)
    case 241:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(244,3);  // execute(__nth0__/3)
    case 242:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,243);  // call(var/1)
    case 243:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(247,4);  // execute(__nth0_rev__/4)
    case 244:  // __nth0__/3
      MACRO_goal(244,atom(112));
      MACRO_requires(9);
      MACRO_try_guard_else(245);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 245:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_call(220,246);  // call(__dec__/2)
    case 246:  // return_from_call(__dec__/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(244,3);  // execute(__nth0__/3)
    case 247:  // __nth0_rev__/4
      MACRO_goal(247,atom(113));
      MACRO_requires(11);
      MACRO_try_guard_else(248);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 248:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(7);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(6),reg::out(2));
      MACRO_call(216,249);  // call(__inc__/2)
    case 249:  // return_from_call(__inc__/2)
      MACRO_tail(7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(6),reg::out(4));
      MACRO_execute(247,4);  // execute(__nth0_rev__/4)
    case 250:  // nth1/3
      MACRO_goal(250,atom(114));
      MACRO_requires(9);
      MACRO_try_guard_else(253);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(153,251);  // call(var/1)
    case 251:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_call(220,252);  // call(__dec__/2)
    case 252:  // return_from_call(__dec__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(244,3);  // execute(__nth0__/3)
    case 253:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,254);  // call(var/1)
    case 254:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(247,255);  // spawn(__nth0_rev__/4)
    case 255:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(216,2);  // execute(__inc__/2)
    case 256:  // inference_count/1
      MACRO_goal(256,atom(115));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(257,1);  // execute(__inference_count__/1)
    case 257:  // __inference_count__/1
      MACRO_goal(257,atom(116));
      MACRO_requires(3);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 258:  // resume_count/1
      MACRO_goal(258,atom(117));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(259,1);  // execute(__resume_count__/1)
    case 259:  // __resume_count__/1
      MACRO_goal(259,atom(118));
      MACRO_requires(3);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 260:  // dump_to_dot/1
      MACRO_goal(260,atom(119));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,261);  // call(atom/1)
    case 261:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(262,1);  // execute(__dump_to_dot__/1)
    case 262:  // __dump_to_dot__/1
      MACRO_goal(262,atom(120));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  }
  MACRO_proceed;
    case 263:  // dump_to_dot/2
      MACRO_goal(263,atom(121));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(152,264);  // call(atom/1)
    case 264:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(265,2);  // execute(__dump_to_dot__/2)
    case 265:  // __dump_to_dot__/2
      MACRO_goal(265,atom(122));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  }
  MACRO_proceed;
    case 266:  // main/1
      MACRO_goal(266,atom(123));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_void;
      MACRO_read_variable(reg::x(2));
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_list(reg::out(1));
      MACRO_write_structure(atom(30));
      MACRO_write_constant(atom(124));
      MACRO_write_variable(reg::x(3));
      MACRO_spawn(48,267);  // spawn(outstream/1)
    case 267:  // return_from_spawn(outstream/1)
      MACRO_par(4);
      MACRO_out_constant(atom(125),reg::out(1));
      MACRO_spawn(260,268);  // spawn(dump_to_dot/1)
    case 268:  // return_from_spawn(dump_to_dot/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(269,2);  // execute(writes/2)
    case 269:  // writes/2
      MACRO_goal(269,atom(126));
      MACRO_requires(7);
      MACRO_try_guard_else(270);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_constant(atom(34));
      MACRO_unify_nil;
      MACRO_proceed;
    case 270:  // writes/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(30));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(30));
      MACRO_unify_constant(atom(127));
      MACRO_unify_variable(reg::x(4));
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(269,2);  // execute(writes/2)
    default:
      throw RuntimeError();
    }
  }
}
void setup(Program* prog) {
  // setup atom constants
  atom(1) = to_atom("fail", 0);
  atom(2) = to_atom("call", 1);
  atom(3) = to_atom("__call__", 1);
  atom(4) = to_atom("time", 1);
  atom(5) = to_atom("wait_time", 1);
  atom(6) = to_atom("__wait_time__", 4);
  atom(7) = to_atom("__time_pre__", 3);
  atom(8) = to_atom("__time_post__", 3);
  atom(9) = to_atom("atom_concat", 3);
  atom(10) = to_atom("__atom_concat_1__", 3);
  atom(11) = to_atom("__atom_concat_2__", 3);
  atom(12) = to_atom("__atom_concat_3__", 3);
  atom(13) = to_atom("atom_codes", 2);
  atom(14) = to_atom("", 0);
  atom(15) = to_atom("__atom_to_codes__", 2);
  atom(16) = to_atom("__codes_to_atom__", 3);
  atom(17) = to_atom("__atom_code_concat__", 3);
  atom(18) = to_atom("inline", 1);
  atom(19) = to_atom("  MACRO_proceed;", 0);
  atom(20) = to_atom("atom_chars", 2);
  atom(21) = to_atom("__atom_to_chars__", 2);
  atom(22) = to_atom("__chars_to_atom__", 3);
  atom(23) = to_atom("atom_number", 2);
  atom(24) = to_atom("__atom_to_number__", 2);
  atom(25) = to_atom("__number_to_atom__", 2);
  atom(26) = to_atom("outstream", 1);
  atom(27) = to_atom("outstream", 2);
  atom(28) = to_atom("open", 3);
  atom(29) = to_atom("write", 2);
  atom(30) = to_atom("write", 1);
  atom(31) = to_atom("writeln", 2);
  atom(32) = to_atom("writeln", 1);
  atom(33) = to_atom("nl", 1);
  atom(34) = to_atom("nl", 0);
  atom(35) = to_atom("close", 1);
  atom(36) = to_atom("__open_opt_string_to_integer__", 3);
  atom(37) = to_atom("__open_opt_string_to_integer__", 5);
  atom(38) = to_atom("rdonly", 0);
  atom(39) = to_atom("wronly", 0);
  atom(40) = to_atom("rdwr", 0);
  atom(41) = to_atom("creat", 0);
  atom(42) = to_atom("excl", 0);
  atom(43) = to_atom("trunc", 0);
  atom(44) = to_atom("append", 0);
  atom(45) = to_atom("rusr", 0);
  atom(46) = to_atom("wusr", 0);
  atom(47) = to_atom("xusr", 0);
  atom(48) = to_atom("rgrp", 0);
  atom(49) = to_atom("wgrp", 0);
  atom(50) = to_atom("xgrp", 0);
  atom(51) = to_atom("roth", 0);
  atom(52) = to_atom("woth", 0);
  atom(53) = to_atom("xoth", 0);
  atom(54) = to_atom("__open__", 4);
  atom(55) = to_atom("__close__", 1);
  atom(56) = to_atom("__nl__", 1);
  atom(57) = to_atom("__write__", 2);
  atom(58) = to_atom("[]", 0);
  atom(59) = to_atom("[", 0);
  atom(60) = to_atom("]", 0);
  atom(61) = to_atom("__write_functor_args__", 2);
  atom(62) = to_atom("(", 0);
  atom(63) = to_atom(")", 0);
  atom(64) = to_atom("__write_functor_args2__", 2);
  atom(65) = to_atom("__write_functor_tail__", 2);
  atom(66) = to_atom(",", 0);
  atom(67) = to_atom("__write_list_tail__", 2);
  atom(68) = to_atom("|", 0);
  atom(69) = to_atom("__write_number__", 2);
  atom(70) = to_atom("__write_atom__", 2);
  atom(71) = to_atom("__write_var__", 2);
  atom(72) = to_atom("integer", 1);
  atom(73) = to_atom("atom", 1);
  atom(74) = to_atom("var", 1);
  atom(75) = to_atom("is_functor", 1);
  atom(76) = to_atom("=..", 2);
  atom(77) = to_atom("==", 2);
  atom(78) = to_atom(">=", 2);
  atom(79) = to_atom("=<", 2);
  atom(80) = to_atom(">", 2);
  atom(81) = to_atom("<", 2);
  atom(82) = to_atom("=:=", 2);
  atom(83) = to_atom("=\\=", 2);
  atom(84) = to_atom("__not_equal__", 2);
  atom(85) = to_atom(":=", 2);
  atom(86) = to_atom("+", 2);
  atom(87) = to_atom("-", 2);
  atom(88) = to_atom("*", 2);
  atom(89) = to_atom("/", 2);
  atom(90) = to_atom("mod", 2);
  atom(91) = to_atom("-", 1);
  atom(92) = to_atom("__add__", 3);
  atom(93) = to_atom("__sub__", 3);
  atom(94) = to_atom("__mul__", 3);
  atom(95) = to_atom("__div__", 3);
  atom(96) = to_atom("__mod__", 3);
  atom(97) = to_atom("__neg__", 2);
  atom(98) = to_atom("__ineg__", 2);
  atom(99) = to_atom("__iadd__", 3);
  atom(100) = to_atom("__isub__", 3);
  atom(101) = to_atom("__imul__", 3);
  atom(102) = to_atom("__idiv__", 3);
  atom(103) = to_atom("__imod__", 3);
  atom(104) = to_atom("__inc__", 2);
  atom(105) = to_atom("__dec__", 2);
  atom(106) = to_atom("__iinc__", 2);
  atom(107) = to_atom("__idec__", 2);
  atom(108) = to_atom("append", 3);
  atom(109) = to_atom("reverse", 2);
  atom(110) = to_atom("__reverse__", 3);
  atom(111) = to_atom("nth0", 3);
  atom(112) = to_atom("__nth0__", 3);
  atom(113) = to_atom("__nth0_rev__", 4);
  atom(114) = to_atom("nth1", 3);
  atom(115) = to_atom("inference_count", 1);
  atom(116) = to_atom("__inference_count__", 1);
  atom(117) = to_atom("resume_count", 1);
  atom(118) = to_atom("__resume_count__", 1);
  atom(119) = to_atom("dump_to_dot", 1);
  atom(120) = to_atom("__dump_to_dot__", 1);
  atom(121) = to_atom("dump_to_dot", 2);
  atom(122) = to_atom("__dump_to_dot__", 2);
  atom(123) = to_atom("main", 1);
  atom(124) = to_atom("Hello ", 0);
  atom(125) = to_atom("dump/hello.dot", 0);
  atom(126) = to_atom("writes", 2);
  atom(127) = to_atom(" ", 0);
  // setup entry points
  prog->add_entry_point(atom(1), 1);  // fail / 0
  prog->add_entry_point(atom(2), 2);  // call / 1
  prog->add_entry_point(atom(3), 3);  // __call__ / 1
  prog->add_entry_point(atom(4), 4);  // time / 1
  prog->add_entry_point(atom(5), 7);  // wait_time / 1
  prog->add_entry_point(atom(6), 9);  // __wait_time__ / 4
  prog->add_entry_point(atom(7), 10);  // __time_pre__ / 3
  prog->add_entry_point(atom(8), 11);  // __time_post__ / 3
  prog->add_entry_point(atom(9), 12);  // atom_concat / 3
  prog->add_entry_point(atom(10), 21);  // __atom_concat_1__ / 3
  prog->add_entry_point(atom(11), 22);  // __atom_concat_2__ / 3
  prog->add_entry_point(atom(12), 23);  // __atom_concat_3__ / 3
  prog->add_entry_point(atom(13), 24);  // atom_codes / 2
  prog->add_entry_point(atom(15), 27);  // __atom_to_codes__ / 2
  prog->add_entry_point(atom(16), 28);  // __codes_to_atom__ / 3
  prog->add_entry_point(atom(17), 32);  // __atom_code_concat__ / 3
  prog->add_entry_point(atom(18), 33);  // inline / 1
  prog->add_entry_point(atom(20), 35);  // atom_chars / 2
  prog->add_entry_point(atom(21), 38);  // __atom_to_chars__ / 2
  prog->add_entry_point(atom(22), 39);  // __chars_to_atom__ / 3
  prog->add_entry_point(atom(23), 42);  // atom_number / 2
  prog->add_entry_point(atom(24), 46);  // __atom_to_number__ / 2
  prog->add_entry_point(atom(25), 47);  // __number_to_atom__ / 2
  prog->add_entry_point(atom(26), 48);  // outstream / 1
  prog->add_entry_point(atom(27), 50);  // outstream / 2
  prog->add_entry_point(atom(28), 64);  // open / 3
  prog->add_entry_point(atom(35), 66);  // close / 1
  prog->add_entry_point(atom(36), 67);  // __open_opt_string_to_integer__ / 3
  prog->add_entry_point(atom(37), 68);  // __open_opt_string_to_integer__ / 5
  prog->add_entry_point(atom(54), 100);  // __open__ / 4
  prog->add_entry_point(atom(55), 101);  // __close__ / 1
  prog->add_entry_point(atom(32), 102);  // writeln / 1
  prog->add_entry_point(atom(31), 104);  // writeln / 2
  prog->add_entry_point(atom(34), 106);  // nl / 0
  prog->add_entry_point(atom(33), 107);  // nl / 1
  prog->add_entry_point(atom(56), 109);  // __nl__ / 1
  prog->add_entry_point(atom(30), 110);  // write / 1
  prog->add_entry_point(atom(29), 111);  // write / 2
  prog->add_entry_point(atom(57), 113);  // __write__ / 2
  prog->add_entry_point(atom(61), 128);  // __write_functor_args__ / 2
  prog->add_entry_point(atom(64), 132);  // __write_functor_args2__ / 2
  prog->add_entry_point(atom(65), 135);  // __write_functor_tail__ / 2
  prog->add_entry_point(atom(67), 139);  // __write_list_tail__ / 2
  prog->add_entry_point(atom(69), 148);  // __write_number__ / 2
  prog->add_entry_point(atom(70), 149);  // __write_atom__ / 2
  prog->add_entry_point(atom(71), 150);  // __write_var__ / 2
  prog->add_entry_point(atom(72), 151);  // integer / 1
  prog->add_entry_point(atom(73), 152);  // atom / 1
  prog->add_entry_point(atom(74), 153);  // var / 1
  prog->add_entry_point(atom(75), 154);  // is_functor / 1
  prog->add_entry_point(atom(76), 155);  // =.. / 2
  prog->add_entry_point(atom(77), 156);  // == / 2
  prog->add_entry_point(atom(78), 157);  // >= / 2
  prog->add_entry_point(atom(79), 158);  // =< / 2
  prog->add_entry_point(atom(80), 159);  // > / 2
  prog->add_entry_point(atom(81), 160);  // < / 2
  prog->add_entry_point(atom(82), 161);  // =:= / 2
  prog->add_entry_point(atom(83), 164);  // =\= / 2
  prog->add_entry_point(atom(84), 167);  // __not_equal__ / 2
  prog->add_entry_point(atom(85), 168);  // := / 2
  prog->add_entry_point(atom(92), 176);  // __add__ / 3
  prog->add_entry_point(atom(93), 182);  // __sub__ / 3
  prog->add_entry_point(atom(94), 188);  // __mul__ / 3
  prog->add_entry_point(atom(95), 194);  // __div__ / 3
  prog->add_entry_point(atom(96), 200);  // __mod__ / 3
  prog->add_entry_point(atom(97), 206);  // __neg__ / 2
  prog->add_entry_point(atom(98), 210);  // __ineg__ / 2
  prog->add_entry_point(atom(99), 211);  // __iadd__ / 3
  prog->add_entry_point(atom(100), 212);  // __isub__ / 3
  prog->add_entry_point(atom(101), 213);  // __imul__ / 3
  prog->add_entry_point(atom(102), 214);  // __idiv__ / 3
  prog->add_entry_point(atom(103), 215);  // __imod__ / 3
  prog->add_entry_point(atom(104), 216);  // __inc__ / 2
  prog->add_entry_point(atom(105), 220);  // __dec__ / 2
  prog->add_entry_point(atom(106), 224);  // __iinc__ / 2
  prog->add_entry_point(atom(107), 225);  // __idec__ / 2
  prog->add_entry_point(atom(108), 226);  // append / 3
  prog->add_entry_point(atom(109), 234);  // reverse / 2
  prog->add_entry_point(atom(110), 238);  // __reverse__ / 3
  prog->add_entry_point(atom(111), 240);  // nth0 / 3
  prog->add_entry_point(atom(112), 244);  // __nth0__ / 3
  prog->add_entry_point(atom(113), 247);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(114), 250);  // nth1 / 3
  prog->add_entry_point(atom(115), 256);  // inference_count / 1
  prog->add_entry_point(atom(116), 257);  // __inference_count__ / 1
  prog->add_entry_point(atom(117), 258);  // resume_count / 1
  prog->add_entry_point(atom(118), 259);  // __resume_count__ / 1
  prog->add_entry_point(atom(119), 260);  // dump_to_dot / 1
  prog->add_entry_point(atom(120), 262);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(121), 263);  // dump_to_dot / 2
  prog->add_entry_point(atom(122), 265);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(123), 266);  // main / 1
  prog->add_entry_point(atom(126), 269);  // writes / 2
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
