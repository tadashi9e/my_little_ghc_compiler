# include "./ghc.h"
#define atom(N) atom_ ## N
Q atom(1);  // fail / 0
Q atom(2);  // call / 1
Q atom(3);  // __call__ / 1
Q atom(4);  // call / 3
Q atom(5);  // __call__ / 3
Q atom(6);  // time / 1
Q atom(7);  // wait_time / 1
Q atom(8);  // __wait_time__ / 4
Q atom(9);  // __time_pre__ / 3
Q atom(10);  // __time_post__ / 3
Q atom(11);  // atom_concat / 3
Q atom(12);  // __atom_concat_1__ / 3
Q atom(13);  // __atom_concat_2__ / 3
Q atom(14);  // __atom_concat_3__ / 3
Q atom(15);  // atom_codes / 2
Q atom(16);  //  / 0
Q atom(17);  // __atom_to_codes__ / 2
Q atom(18);  // __codes_to_atom__ / 3
Q atom(19);  // __atom_code_concat__ / 3
Q atom(20);  // inline / 1
Q atom(21);  //   MACRO_proceed; / 0
Q atom(22);  // atom_chars / 2
Q atom(23);  // __atom_to_chars__ / 2
Q atom(24);  // __chars_to_atom__ / 3
Q atom(25);  // atom_number / 2
Q atom(26);  // __atom_to_number__ / 2
Q atom(27);  // __number_to_atom__ / 2
Q atom(28);  // outstream / 1
Q atom(29);  // outstream / 2
Q atom(30);  // open / 3
Q atom(31);  // write / 2
Q atom(32);  // write / 1
Q atom(33);  // writeln / 2
Q atom(34);  // writeln / 1
Q atom(35);  // nl / 1
Q atom(36);  // nl / 0
Q atom(37);  // close / 1
Q atom(38);  // __open_opt_string_to_integer__ / 3
Q atom(39);  // __open_opt_string_to_integer__ / 5
Q atom(40);  // rdonly / 0
Q atom(41);  // wronly / 0
Q atom(42);  // rdwr / 0
Q atom(43);  // creat / 0
Q atom(44);  // excl / 0
Q atom(45);  // trunc / 0
Q atom(46);  // append / 0
Q atom(47);  // rusr / 0
Q atom(48);  // wusr / 0
Q atom(49);  // xusr / 0
Q atom(50);  // rgrp / 0
Q atom(51);  // wgrp / 0
Q atom(52);  // xgrp / 0
Q atom(53);  // roth / 0
Q atom(54);  // woth / 0
Q atom(55);  // xoth / 0
Q atom(56);  // __open__ / 4
Q atom(57);  // __close__ / 1
Q atom(58);  // __nl__ / 1
Q atom(59);  // __write__ / 2
Q atom(60);  // [] / 0
Q atom(61);  // [ / 0
Q atom(62);  // ] / 0
Q atom(63);  // __write_functor_args__ / 2
Q atom(64);  // ( / 0
Q atom(65);  // ) / 0
Q atom(66);  // __write_functor_args2__ / 2
Q atom(67);  // __write_functor_tail__ / 2
Q atom(68);  // , / 0
Q atom(69);  // __write_list_tail__ / 2
Q atom(70);  // | / 0
Q atom(71);  // __write_number__ / 2
Q atom(72);  // __write_atom__ / 2
Q atom(73);  // __write_var__ / 2
Q atom(74);  // integer / 1
Q atom(75);  // atom / 1
Q atom(76);  // var / 1
Q atom(77);  // is_functor / 1
Q atom(78);  // =.. / 2
Q atom(79);  // == / 2
Q atom(80);  // >= / 2
Q atom(81);  // =< / 2
Q atom(82);  // > / 2
Q atom(83);  // < / 2
Q atom(84);  // =:= / 2
Q atom(85);  // =\= / 2
Q atom(86);  // __not_equal__ / 2
Q atom(87);  // := / 2
Q atom(88);  // + / 2
Q atom(89);  // - / 2
Q atom(90);  // * / 2
Q atom(91);  // / / 2
Q atom(92);  // mod / 2
Q atom(93);  // - / 1
Q atom(94);  // __add__ / 3
Q atom(95);  // __sub__ / 3
Q atom(96);  // __mul__ / 3
Q atom(97);  // __div__ / 3
Q atom(98);  // __mod__ / 3
Q atom(99);  // __neg__ / 2
Q atom(100);  // __ineg__ / 2
Q atom(101);  // __iadd__ / 3
Q atom(102);  // __isub__ / 3
Q atom(103);  // __imul__ / 3
Q atom(104);  // __idiv__ / 3
Q atom(105);  // __imod__ / 3
Q atom(106);  // __inc__ / 2
Q atom(107);  // __dec__ / 2
Q atom(108);  // __iinc__ / 2
Q atom(109);  // __idec__ / 2
Q atom(110);  // append / 3
Q atom(111);  // reverse / 2
Q atom(112);  // __reverse__ / 3
Q atom(113);  // nth0 / 3
Q atom(114);  // __nth0__ / 3
Q atom(115);  // __nth0_rev__ / 4
Q atom(116);  // nth1 / 3
Q atom(117);  // inference_count / 1
Q atom(118);  // __inference_count__ / 1
Q atom(119);  // resume_count / 1
Q atom(120);  // __resume_count__ / 1
Q atom(121);  // dump_to_dot / 1
Q atom(122);  // __dump_to_dot__ / 1
Q atom(123);  // dump_to_dot / 2
Q atom(124);  // __dump_to_dot__ / 2
Q atom(125);  // test_call3 / 0
Q atom(126);  // test_call3 / 1
Q atom(127);  // a / 0
Q atom(128);  // b / 0
Q atom(129);  // c / 0
Q atom(130);  // test_call3 / 3
Q atom(131);  // test_call3 / 2
Q atom(132);  // done / 0
Q atom(133);  // test_otherwise / 0
Q atom(134);  // test_otherwise_aux / 1
Q atom(135);  // test failed / 0
Q atom(136);  // test success / 0
Q atom(137);  // test_write_var / 0
Q atom(138);  // test_write_atom / 0
Q atom(139);  // atom / 0
Q atom(140);  // test_write_list / 0
Q atom(141);  // test_write_structure / 0
Q atom(142);  // some / 3
Q atom(143);  // structure / 0
Q atom(144);  // and / 0
Q atom(145);  // arguments / 0
Q atom(146);  // test_get_structure / 0
Q atom(147);  // test_set_structure / 0
Q atom(148);  // test_get_list / 0
Q atom(149);  // test_set_list / 0
Q atom(150);  // test_check_constant / 0
Q atom(151);  // test_check_constant_aux / 1
Q atom(152);  // test failed(0) / 0
Q atom(153);  // test success(1) / 0
Q atom(154);  // test failed(otherwise) / 0
Q atom(155);  // test_check_list / 0
Q atom(156);  // test_check_list_aux / 1
Q atom(157);  // x / 0
Q atom(158);  // y / 0
Q atom(159);  // test failed([x,y]) / 0
Q atom(160);  // test success([a,b]) / 0
Q atom(161);  // test_check_nil / 0
Q atom(162);  // test_check_nil_aux / 1
Q atom(163);  // test failed([a,b]) / 0
Q atom(164);  // test success([]) / 0
Q atom(165);  // test_check_structure / 0
Q atom(166);  // fun / 2
Q atom(167);  // test_check_structure_aux / 1
Q atom(168);  // test failed(fun(x,y)) / 0
Q atom(169);  // test success(fun(a,b)) / 0
Q atom(170);  // test_wait_var / 0
Q atom(171);  // wait_var / 1
Q atom(172);  // write_var / 1
Q atom(173);  // fire / 0
Q atom(174);  // test_atom_concat / 0
Q atom(175);  // test_atom_concat_1 / 0
Q atom(176);  // abc / 0
Q atom(177);  // def / 0
Q atom(178);  // abc + def =  / 0
Q atom(179);  // test_atom_concat_2 / 0
Q atom(180);  // abcdef / 0
Q atom(181);  // abc + [ / 0
Q atom(182);  // ] = abcdef / 0
Q atom(183);  // test_atom_concat_3 / 0
Q atom(184);  // ] + def = abcdef / 0
Q atom(185);  // test_atom_chars / 0
Q atom(186);  // test_atom_chars1 / 0
Q atom(187);  // abcdefgあいうえお漢字☺🍺 / 0
Q atom(188);  //  ->  / 0
Q atom(189);  // test_atom_chars2 / 0
Q atom(190);  // d / 0
Q atom(191);  // e / 0
Q atom(192);  // f / 0
Q atom(193);  // g / 0
Q atom(194);  // あ / 0
Q atom(195);  // い / 0
Q atom(196);  // う / 0
Q atom(197);  // え / 0
Q atom(198);  // お / 0
Q atom(199);  // 漢 / 0
Q atom(200);  // 字 / 0
Q atom(201);  // ☺ / 0
Q atom(202);  // 🍺 / 0
Q atom(203);  //  <-  / 0
Q atom(204);  // test_atom_codes / 0
Q atom(205);  // test_atom_codes1 / 0
Q atom(206);  // test_atom_codes2 / 0
Q atom(207);  // test_append / 0
Q atom(208);  // test_append1 / 0
Q atom(209);  // + / 0
Q atom(210);  // =[ / 0
Q atom(211);  // test_append2 / 0
Q atom(212);  // ]= / 0
Q atom(213);  // test_append3 / 0
Q atom(214);  // ]+ / 0
Q atom(215);  // = / 0
Q atom(216);  // test_reverse / 0
Q atom(217);  // test_nth0 / 0
Q atom(218);  // test_nth0_ / 0
Q atom(219);  //  0: [ / 0
Q atom(220);  // ] 1: [ / 0
Q atom(221);  // ] 2: [ / 0
Q atom(222);  // ] 3: [ / 0
Q atom(223);  // ] 4: [ / 0
Q atom(224);  // ] 5: [ / 0
Q atom(225);  // test_nth0_rev_ / 0
Q atom(226);  //  [ / 0
Q atom(227);  // ]: a / 0
Q atom(228);  // ]: b / 0
Q atom(229);  // ]: c / 0
Q atom(230);  // ]: d / 0
Q atom(231);  // ]: e / 0
Q atom(232);  // ]: f / 0
Q atom(233);  // test_nth1 / 0
Q atom(234);  // test_nth1_ / 0
Q atom(235);  //  1: [ / 0
Q atom(236);  // test_nth1_rev_ / 0
Q atom(237);  // test_splice_suspension / 0
Q atom(238);  // dump/splice.dot / 0
Q atom(239);  // test_splice_suspension1 / 1
Q atom(240);  // test_calc / 0
Q atom(241);  // xxx0 / 0
Q atom(242);  // xxx1 / 0
Q atom(243);  // dump/calc.dot / 0
Q atom(244);  // xxx / 0
Q atom(245);  // do_test / 1
Q atom(246);  // :  / 0
Q atom(247);  // main / 1
Q atom(248);  // total_inferences= / 0
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
      MACRO_tail(2);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_execute(pc, arity);
    } else {
      MACRO_fail;
    }
  }
    case 4:  // call/3
      MACRO_goal(4,atom(4));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(5,3);  // execute(__call__/3)
    case 5:  // __call__/3
      MACRO_goal(5,atom(5));
      MACRO_requires(7);
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
      MACRO_tail(4);
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
      MACRO_tail(2);
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
    case 6:  // time/1
      MACRO_goal(6,atom(6));
      MACRO_requires(8);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_variable(reg::x(4),reg::out(3));
      MACRO_call(12,7);  // call(__time_pre__/3)
    case 7:  // return_from_call(__time_pre__/3)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(2,8);  // call(call/1)
    case 8:  // return_from_call(call/1)
      MACRO_tail(5);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_out_value(reg::x(4),reg::out(3));
      MACRO_execute(13,3);  // execute(__time_post__/3)
    case 9:  // wait_time/1
      MACRO_goal(9,atom(7));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_variable(reg::x(4),reg::out(3));
      MACRO_spawn(12,10);  // spawn(__time_pre__/3)
    case 10:  // return_from_spawn(__time_pre__/3)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_out_value(reg::x(4),reg::out(4));
      MACRO_execute(11,4);  // execute(__wait_time__/4)
    case 11:  // __wait_time__/4
      MACRO_goal(11,atom(8));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(3),reg::out(2));
      MACRO_out_value(reg::in(4),reg::out(3));
      MACRO_execute(13,3);  // execute(__time_post__/3)
    case 12:  // __time_pre__/3
      MACRO_goal(12,atom(9));
      MACRO_requires(7);
  MACRO_activate;
  {
    const int64_t istart = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
    MACRO_get_constant(tagvalue<TAG_INT>(istart), reg::in(1));
  }
  MACRO_get_constant(tagvalue<TAG_INT>(vm->inference_count), reg::in(2));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->resume_count), reg::in(3));
  MACRO_proceed;
    case 13:  // __time_post__/3
      MACRO_goal(13,atom(10));
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
    case 14:  // atom_concat/3
      MACRO_goal(14,atom(11));
      MACRO_requires(7);
      MACRO_try_guard_else(17);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,15);  // call(atom/1)
    case 15:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(154,16);  // call(atom/1)
    case 16:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(23,3);  // execute(__atom_concat_1__/3)
    case 17:  // atom_concat/3-2
      MACRO_try_guard_else(20);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,18);  // call(atom/1)
    case 18:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(154,19);  // call(atom/1)
    case 19:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(24,3);  // execute(__atom_concat_2__/3)
    case 20:  // atom_concat/3-3
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(154,21);  // call(atom/1)
    case 21:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(154,22);  // call(atom/1)
    case 22:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(25,3);  // execute(__atom_concat_3__/3)
    case 23:  // __atom_concat_1__/3
      MACRO_goal(23,atom(12));
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
    case 24:  // __atom_concat_2__/3
      MACRO_goal(24,atom(13));
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
    case 25:  // __atom_concat_3__/3
      MACRO_goal(25,atom(14));
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
    case 26:  // atom_codes/2
      MACRO_goal(26,atom(15));
      MACRO_requires(8);
      MACRO_try_guard_else(28);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,27);  // call(atom/1)
    case 27:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(29,2);  // execute(__atom_to_codes__/2)
    case 28:  // atom_codes/2-2
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
      MACRO_out_constant(atom(16),reg::out(3));
      MACRO_execute(30,3);  // execute(__codes_to_atom__/3)
    case 29:  // __atom_to_codes__/2
      MACRO_goal(29,atom(17));
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
    case 30:  // __codes_to_atom__/3
      MACRO_goal(30,atom(18));
      MACRO_requires(9);
      MACRO_try_guard_else(31);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 31:  // __codes_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_seq(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_call(153,32);  // call(integer/1)
    case 32:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(34,33);  // spawn(__atom_code_concat__/3)
    case 33:  // return_from_spawn(__atom_code_concat__/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(30,3);  // execute(__codes_to_atom__/3)
    case 34:  // __atom_code_concat__/3
      MACRO_goal(34,atom(19));
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
    case 35:  // inline/1
      MACRO_goal(35,atom(20));
      MACRO_requires(3);
      MACRO_try_guard_else(36);
      MACRO_check_constant(atom(21),reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 36:  // inline/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(21),reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 37:  // atom_chars/2
      MACRO_goal(37,atom(22));
      MACRO_requires(8);
      MACRO_try_guard_else(39);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,38);  // call(atom/1)
    case 38:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(40,2);  // execute(__atom_to_chars__/2)
    case 39:  // atom_chars/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_execute(41,3);  // execute(__chars_to_atom__/3)
    case 40:  // __atom_to_chars__/2
      MACRO_goal(40,atom(23));
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
    case 41:  // __chars_to_atom__/3
      MACRO_goal(41,atom(24));
      MACRO_requires(9);
      MACRO_try_guard_else(42);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 42:  // __chars_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(14,43);  // spawn(atom_concat/3)
    case 43:  // return_from_spawn(atom_concat/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(41,3);  // execute(__chars_to_atom__/3)
    case 44:  // atom_number/2
      MACRO_goal(44,atom(25));
      MACRO_requires(5);
      MACRO_try_guard_else(46);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,45);  // call(atom/1)
    case 45:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(48,2);  // execute(__atom_to_number__/2)
    case 46:  // atom_number/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,47);  // call(integer/1)
    case 47:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(49,2);  // execute(__number_to_atom__/2)
    case 48:  // __atom_to_number__/2
      MACRO_goal(48,atom(26));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_get_constant(tagvalue<TAG_INT>(i), reg::in(2));
  }
  MACRO_proceed;
    case 49:  // __number_to_atom__/2
      MACRO_goal(49,atom(27));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[2];
    const int64_t i = value_of<int64_t>(q);
    const std::string s = std::to_string(i);
    MACRO_get_constant(to_atom(s.c_str(), 0), reg::in(1));
  }
  MACRO_proceed;
    case 50:  // outstream/1
      MACRO_goal(50,atom(28));
      MACRO_requires(6);
      MACRO_try_guard_else(51);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 51:  // outstream/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(52,2);  // execute(outstream/2)
    case 52:  // outstream/2
      MACRO_goal(52,atom(29));
      MACRO_requires(9);
      MACRO_try_guard_else(54);
      MACRO_check_structure(atom(30),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(66,53);  // spawn(open/3)
    case 53:  // return_from_spawn(open/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 54:  // outstream/2-2
      MACRO_try_guard_else(56);
      MACRO_check_structure(atom(31),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(113,55);  // spawn(write/2)
    case 55:  // return_from_spawn(write/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 56:  // outstream/2-3
      MACRO_try_guard_else(58);
      MACRO_check_structure(atom(32),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(112,57);  // spawn(write/1)
    case 57:  // return_from_spawn(write/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 58:  // outstream/2-4
      MACRO_try_guard_else(60);
      MACRO_check_structure(atom(33),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(106,59);  // spawn(writeln/2)
    case 59:  // return_from_spawn(writeln/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 60:  // outstream/2-5
      MACRO_try_guard_else(62);
      MACRO_check_structure(atom(34),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(104,61);  // spawn(writeln/1)
    case 61:  // return_from_spawn(writeln/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 62:  // outstream/2-6
      MACRO_try_guard_else(64);
      MACRO_check_structure(atom(35),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(109,63);  // spawn(nl/1)
    case 63:  // return_from_spawn(nl/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 64:  // outstream/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(36),reg::in(1));
      MACRO_activate;
      MACRO_par(6);
      MACRO_spawn(108,65);  // spawn(nl/0)
    case 65:  // return_from_spawn(nl/0)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(50,1);  // execute(outstream/1)
    case 66:  // open/3
      MACRO_goal(66,atom(30));
      MACRO_requires(10);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(69,67);  // spawn(__open_opt_string_to_integer__/3)
    case 67:  // return_from_spawn(__open_opt_string_to_integer__/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_out_value(reg::in(3),reg::out(4));
      MACRO_execute(102,4);  // execute(__open__/4)
    case 68:  // close/1
      MACRO_goal(68,atom(37));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(103,1);  // execute(__close__/1)
    case 69:  // __open_opt_string_to_integer__/3
      MACRO_goal(69,atom(38));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 70:  // __open_opt_string_to_integer__/5
      MACRO_goal(70,atom(39));
      MACRO_requires(13);
      MACRO_try_guard_else(71);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(2));
      MACRO_get_value(reg::in(5),reg::in(3));
      MACRO_proceed;
    case 71:  // __open_opt_string_to_integer__/5-2
      MACRO_try_guard_else(72);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(40));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_tail(7);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 72:  // __open_opt_string_to_integer__/5-3
      MACRO_try_guard_else(74);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(41));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(218,73);  // call(__inc__/2)
    case 73:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 74:  // __open_opt_string_to_integer__/5-4
      MACRO_try_guard_else(76);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(42));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,75);  // call(__add__/3)
    case 75:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 76:  // __open_opt_string_to_integer__/5-5
      MACRO_try_guard_else(78);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(43));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,77);  // call(__add__/3)
    case 77:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 78:  // __open_opt_string_to_integer__/5-6
      MACRO_try_guard_else(80);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(44));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,79);  // call(__add__/3)
    case 79:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 80:  // __open_opt_string_to_integer__/5-7
      MACRO_try_guard_else(82);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(45));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,81);  // call(__add__/3)
    case 81:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 82:  // __open_opt_string_to_integer__/5-8
      MACRO_try_guard_else(84);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(46));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,83);  // call(__add__/3)
    case 83:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 84:  // __open_opt_string_to_integer__/5-9
      MACRO_try_guard_else(86);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(47));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,85);  // call(__add__/3)
    case 85:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 86:  // __open_opt_string_to_integer__/5-10
      MACRO_try_guard_else(88);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(48));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,87);  // call(__add__/3)
    case 87:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 88:  // __open_opt_string_to_integer__/5-11
      MACRO_try_guard_else(90);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(49));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,89);  // call(__add__/3)
    case 89:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 90:  // __open_opt_string_to_integer__/5-12
      MACRO_try_guard_else(92);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(50));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,91);  // call(__add__/3)
    case 91:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 92:  // __open_opt_string_to_integer__/5-13
      MACRO_try_guard_else(94);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(51));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,93);  // call(__add__/3)
    case 93:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 94:  // __open_opt_string_to_integer__/5-14
      MACRO_try_guard_else(96);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(52));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,95);  // call(__add__/3)
    case 95:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 96:  // __open_opt_string_to_integer__/5-15
      MACRO_try_guard_else(98);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(53));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,97);  // call(__add__/3)
    case 97:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 98:  // __open_opt_string_to_integer__/5-16
      MACRO_try_guard_else(100);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(54));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(178,99);  // call(__add__/3)
    case 99:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 100:  // __open_opt_string_to_integer__/5-17
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(55));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(218,101);  // call(__inc__/2)
    case 101:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(70,5);  // execute(__open_opt_string_to_integer__/5)
    case 102:  // __open__/4
      MACRO_goal(102,atom(56));
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
    case 103:  // __close__/1
      MACRO_goal(103,atom(57));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
  }
  MACRO_proceed;
    case 104:  // writeln/1
      MACRO_goal(104,atom(34));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(112,105);  // call(write/1)
    case 105:  // return_from_call(write/1)
      MACRO_tail(3);
      MACRO_execute(108,0);  // execute(nl/0)
    case 106:  // writeln/2
      MACRO_goal(106,atom(33));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(113,107);  // spawn(write/2)
    case 107:  // return_from_spawn(write/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(109,1);  // execute(nl/1)
    case 108:  // nl/0
      MACRO_goal(108,atom(36));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(109,1);  // execute(nl/1)
    case 109:  // nl/1
      MACRO_goal(109,atom(35));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,110);  // call(integer/1)
    case 110:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(111,1);  // execute(__nl__/1)
    case 111:  // __nl__/1
      MACRO_goal(111,atom(58));
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
    case 112:  // write/1
      MACRO_goal(112,atom(32));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(113,2);  // execute(write/2)
    case 113:  // write/2
      MACRO_goal(113,atom(31));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,114);  // call(integer/1)
    case 114:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 115:  // __write__/2
      MACRO_goal(115,atom(59));
      MACRO_requires(7);
      MACRO_try_guard_else(117);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(154,116);  // call(atom/1)
    case 116:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(151,2);  // execute(__write_atom__/2)
    case 117:  // __write__/2-2
      MACRO_try_guard_else(119);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(155,118);  // call(var/1)
    case 118:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(152,2);  // execute(__write_var__/2)
    case 119:  // __write__/2-3
      MACRO_try_guard_else(121);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,120);  // call(integer/1)
    case 120:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(150,2);  // execute(__write_number__/2)
    case 121:  // __write__/2-4
      MACRO_try_guard_else(122);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(60),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 122:  // __write__/2-5
      MACRO_try_guard_else(126);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(61),reg::out(2));
      MACRO_call(115,123);  // call(__write__/2)
    case 123:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(115,124);  // call(__write__/2)
    case 124:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_call(141,125);  // call(__write_list_tail__/2)
    case 125:  // return_from_call(__write_list_tail__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(62),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 126:  // __write__/2-6
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(156,127);  // call(is_functor/1)
    case 127:  // return_from_call(is_functor/1)
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_list(reg::out(2));
      MACRO_write_variable(reg::x(4));
      MACRO_write_variable(reg::x(3));
      MACRO_call(157,128);  // call((=..)/2)
    case 128:  // return_from_call((=..)/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(115,129);  // call(__write__/2)
    case 129:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(130,2);  // execute(__write_functor_args__/2)
    case 130:  // __write_functor_args__/2
      MACRO_goal(130,atom(63));
      MACRO_requires(5);
      MACRO_try_guard_else(131);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 131:  // __write_functor_args__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(64),reg::out(2));
      MACRO_call(115,132);  // call(__write__/2)
    case 132:  // return_from_call(__write__/2)
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(134,133);  // call(__write_functor_args2__/2)
    case 133:  // return_from_call(__write_functor_args2__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(65),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 134:  // __write_functor_args2__/2
      MACRO_goal(134,atom(66));
      MACRO_requires(7);
      MACRO_try_guard_else(135);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 135:  // __write_functor_args2__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(115,136);  // call(__write__/2)
    case 136:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(137,2);  // execute(__write_functor_tail__/2)
    case 137:  // __write_functor_tail__/2
      MACRO_goal(137,atom(67));
      MACRO_requires(7);
      MACRO_try_guard_else(138);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 138:  // __write_functor_tail__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(68),reg::out(2));
      MACRO_call(115,139);  // call(__write__/2)
    case 139:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(115,140);  // call(__write__/2)
    case 140:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(137,2);  // execute(__write_functor_tail__/2)
    case 141:  // __write_list_tail__/2
      MACRO_goal(141,atom(69));
      MACRO_requires(7);
      MACRO_try_guard_else(144);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(155,142);  // call(var/1)
    case 142:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(70),reg::out(2));
      MACRO_call(115,143);  // call(__write__/2)
    case 143:  // return_from_call(__write__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 144:  // __write_list_tail__/2-2
      MACRO_try_guard_else(145);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 145:  // __write_list_tail__/2-3
      MACRO_try_guard_else(148);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(68),reg::out(2));
      MACRO_call(115,146);  // call(__write__/2)
    case 146:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(115,147);  // call(__write__/2)
    case 147:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(141,2);  // execute(__write_list_tail__/2)
    case 148:  // __write_list_tail__/2-4
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(70),reg::out(2));
      MACRO_call(115,149);  // call(__write__/2)
    case 149:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(115,2);  // execute(__write__/2)
    case 150:  // __write_number__/2
      MACRO_goal(150,atom(71));
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
    case 151:  // __write_atom__/2
      MACRO_goal(151,atom(72));
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
    case 152:  // __write_var__/2
      MACRO_goal(152,atom(73));
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
    case 153:  // integer/1
      MACRO_goal(153,atom(74));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
    case 154:  // atom/1
      MACRO_goal(154,atom(75));
      MACRO_requires(3);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
    case 155:  // var/1
      MACRO_goal(155,atom(76));
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
    case 156:  // is_functor/1
      MACRO_goal(156,atom(77));
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
    case 157:  // (=..)/2
      MACRO_goal(157,atom(78));
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
    case 158:  // (==)/2
      MACRO_goal(158,atom(79));
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
    case 159:  // (>=)/2
      MACRO_goal(159,atom(80));
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
    case 160:  // (=<)/2
      MACRO_goal(160,atom(81));
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
    case 161:  // (>)/2
      MACRO_goal(161,atom(82));
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
    case 162:  // (<)/2
      MACRO_goal(162,atom(83));
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
    case 163:  // (=:=)/2
      MACRO_goal(163,atom(84));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,164);  // spawn((:=)/2)
    case 164:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,165);  // spawn((:=)/2)
    case 165:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(158,2);  // execute((==)/2)
    case 166:  // (=\=)/2
      MACRO_goal(166,atom(85));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,167);  // spawn((:=)/2)
    case 167:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,168);  // spawn((:=)/2)
    case 168:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(169,2);  // execute(__not_equal__/2)
    case 169:  // __not_equal__/2
      MACRO_goal(169,atom(86));
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
    case 170:  // (:=)/2
      MACRO_goal(170,atom(87));
      MACRO_requires(8);
      MACRO_try_guard_else(172);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,171);  // call(integer/1)
    case 171:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
    case 172:  // (:=)/2-2
      MACRO_try_guard_else(173);
      MACRO_check_structure(atom(88),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(178,3);  // execute(__add__/3)
    case 173:  // (:=)/2-3
      MACRO_try_guard_else(174);
      MACRO_check_structure(atom(89),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(184,3);  // execute(__sub__/3)
    case 174:  // (:=)/2-4
      MACRO_try_guard_else(175);
      MACRO_check_structure(atom(90),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(190,3);  // execute(__mul__/3)
    case 175:  // (:=)/2-5
      MACRO_try_guard_else(176);
      MACRO_check_structure(atom(91),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(196,3);  // execute(__div__/3)
    case 176:  // (:=)/2-6
      MACRO_try_guard_else(177);
      MACRO_check_structure(atom(92),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(202,3);  // execute(__mod__/3)
    case 177:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_structure(atom(93),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(208,2);  // execute(__neg__/2)
    case 178:  // __add__/3
      MACRO_goal(178,atom(94));
      MACRO_requires(9);
      MACRO_try_guard_else(181);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,179);  // call(integer/1)
    case 179:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,180);  // call(integer/1)
    case 180:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__iadd__/3)
    case 181:  // __add__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,182);  // spawn((:=)/2)
    case 182:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,183);  // spawn((:=)/2)
    case 183:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__iadd__/3)
    case 184:  // __sub__/3
      MACRO_goal(184,atom(95));
      MACRO_requires(9);
      MACRO_try_guard_else(187);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,185);  // call(integer/1)
    case 185:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,186);  // call(integer/1)
    case 186:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__isub__/3)
    case 187:  // __sub__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,188);  // spawn((:=)/2)
    case 188:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,189);  // spawn((:=)/2)
    case 189:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__isub__/3)
    case 190:  // __mul__/3
      MACRO_goal(190,atom(96));
      MACRO_requires(9);
      MACRO_try_guard_else(193);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,191);  // call(integer/1)
    case 191:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,192);  // call(integer/1)
    case 192:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__imul__/3)
    case 193:  // __mul__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,194);  // spawn((:=)/2)
    case 194:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,195);  // spawn((:=)/2)
    case 195:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__imul__/3)
    case 196:  // __div__/3
      MACRO_goal(196,atom(97));
      MACRO_requires(9);
      MACRO_try_guard_else(199);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,197);  // call(integer/1)
    case 197:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,198);  // call(integer/1)
    case 198:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(216,3);  // execute(__idiv__/3)
    case 199:  // __div__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,200);  // spawn((:=)/2)
    case 200:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,201);  // spawn((:=)/2)
    case 201:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(216,3);  // execute(__idiv__/3)
    case 202:  // __mod__/3
      MACRO_goal(202,atom(98));
      MACRO_requires(9);
      MACRO_try_guard_else(205);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,203);  // call(integer/1)
    case 203:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(153,204);  // call(integer/1)
    case 204:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(217,3);  // execute(__imod__/3)
    case 205:  // __mod__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,206);  // spawn((:=)/2)
    case 206:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(170,207);  // spawn((:=)/2)
    case 207:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(217,3);  // execute(__imod__/3)
    case 208:  // __neg__/2
      MACRO_goal(208,atom(99));
      MACRO_requires(6);
      MACRO_try_guard_else(210);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,209);  // call(integer/1)
    case 209:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(212,2);  // execute(__ineg__/2)
    case 210:  // __neg__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,211);  // spawn((:=)/2)
    case 211:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(212,2);  // execute(__ineg__/2)
    case 212:  // __ineg__/2
      MACRO_goal(212,atom(100));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 213:  // __iadd__/3
      MACRO_goal(213,atom(101));
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
    case 214:  // __isub__/3
      MACRO_goal(214,atom(102));
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
    case 215:  // __imul__/3
      MACRO_goal(215,atom(103));
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
    case 216:  // __idiv__/3
      MACRO_goal(216,atom(104));
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
    case 217:  // __imod__/3
      MACRO_goal(217,atom(105));
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
    case 218:  // __inc__/2
      MACRO_goal(218,atom(106));
      MACRO_requires(6);
      MACRO_try_guard_else(220);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,219);  // call(integer/1)
    case 219:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(226,2);  // execute(__iinc__/2)
    case 220:  // __inc__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,221);  // spawn((:=)/2)
    case 221:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(226,2);  // execute(__iinc__/2)
    case 222:  // __dec__/2
      MACRO_goal(222,atom(107));
      MACRO_requires(6);
      MACRO_try_guard_else(224);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(153,223);  // call(integer/1)
    case 223:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(227,2);  // execute(__idec__/2)
    case 224:  // __dec__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(170,225);  // spawn((:=)/2)
    case 225:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(227,2);  // execute(__idec__/2)
    case 226:  // __iinc__/2
      MACRO_goal(226,atom(108));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 227:  // __idec__/2
      MACRO_goal(227,atom(109));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 228:  // append/3
      MACRO_goal(228,atom(110));
      MACRO_requires(9);
      MACRO_try_guard_else(229);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 229:  // append/3-2
      MACRO_try_guard_else(230);
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
      MACRO_execute(228,3);  // execute(append/3)
    case 230:  // append/3-3
      MACRO_try_guard_else(231);
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
      MACRO_execute(228,3);  // execute(append/3)
    case 231:  // append/3-4
      MACRO_try_guard_else_suspend;
      MACRO_seq(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(155,232);  // call(var/1)
    case 232:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_spawn(236,233);  // spawn(reverse/2)
    case 233:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_spawn(236,234);  // spawn(reverse/2)
    case 234:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(228,235);  // spawn(append/3)
    case 235:  // return_from_spawn(append/3)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(236,2);  // execute(reverse/2)
    case 236:  // reverse/2
      MACRO_goal(236,atom(111));
      MACRO_requires(6);
      MACRO_try_guard_else(238);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(155,237);  // call(var/1)
    case 237:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(240,3);  // execute(__reverse__/3)
    case 238:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(155,239);  // call(var/1)
    case 239:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(240,3);  // execute(__reverse__/3)
    case 240:  // __reverse__/3
      MACRO_goal(240,atom(112));
      MACRO_requires(10);
      MACRO_try_guard_else(241);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 241:  // __reverse__/3-2
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
      MACRO_execute(240,3);  // execute(__reverse__/3)
    case 242:  // nth0/3
      MACRO_goal(242,atom(113));
      MACRO_requires(8);
      MACRO_try_guard_else(244);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(155,243);  // call(var/1)
    case 243:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(246,3);  // execute(__nth0__/3)
    case 244:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(155,245);  // call(var/1)
    case 245:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(249,4);  // execute(__nth0_rev__/4)
    case 246:  // __nth0__/3
      MACRO_goal(246,atom(114));
      MACRO_requires(9);
      MACRO_try_guard_else(247);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 247:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_call(222,248);  // call(__dec__/2)
    case 248:  // return_from_call(__dec__/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(246,3);  // execute(__nth0__/3)
    case 249:  // __nth0_rev__/4
      MACRO_goal(249,atom(115));
      MACRO_requires(11);
      MACRO_try_guard_else(250);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 250:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(7);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(6),reg::out(2));
      MACRO_call(218,251);  // call(__inc__/2)
    case 251:  // return_from_call(__inc__/2)
      MACRO_tail(7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(6),reg::out(4));
      MACRO_execute(249,4);  // execute(__nth0_rev__/4)
    case 252:  // nth1/3
      MACRO_goal(252,atom(116));
      MACRO_requires(9);
      MACRO_try_guard_else(255);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(155,253);  // call(var/1)
    case 253:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_call(222,254);  // call(__dec__/2)
    case 254:  // return_from_call(__dec__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(246,3);  // execute(__nth0__/3)
    case 255:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(155,256);  // call(var/1)
    case 256:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(249,257);  // spawn(__nth0_rev__/4)
    case 257:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(218,2);  // execute(__inc__/2)
    case 258:  // inference_count/1
      MACRO_goal(258,atom(117));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(259,1);  // execute(__inference_count__/1)
    case 259:  // __inference_count__/1
      MACRO_goal(259,atom(118));
      MACRO_requires(3);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 260:  // resume_count/1
      MACRO_goal(260,atom(119));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(261,1);  // execute(__resume_count__/1)
    case 261:  // __resume_count__/1
      MACRO_goal(261,atom(120));
      MACRO_requires(3);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 262:  // dump_to_dot/1
      MACRO_goal(262,atom(121));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,263);  // call(atom/1)
    case 263:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(264,1);  // execute(__dump_to_dot__/1)
    case 264:  // __dump_to_dot__/1
      MACRO_goal(264,atom(122));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  }
  MACRO_proceed;
    case 265:  // dump_to_dot/2
      MACRO_goal(265,atom(123));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(154,266);  // call(atom/1)
    case 266:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(267,2);  // execute(__dump_to_dot__/2)
    case 267:  // __dump_to_dot__/2
      MACRO_goal(267,atom(124));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  }
  MACRO_proceed;
    case 268:  // test_call3/0
      MACRO_goal(268,atom(125));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3);
      MACRO_out_structure(atom(126),reg::out(1));
      MACRO_write_constant(atom(127));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(4,269);  // spawn(call/3)
    case 269:  // return_from_spawn(call/3)
      MACRO_par(3);
      MACRO_out_structure(atom(126),reg::out(1));
      MACRO_write_constant(atom(128));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(4,270);  // spawn(call/3)
    case 270:  // return_from_spawn(call/3)
      MACRO_par(3);
      MACRO_out_structure(atom(126),reg::out(1));
      MACRO_write_constant(atom(129));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(4,271);  // spawn(call/3)
    case 271:  // return_from_spawn(call/3)
      MACRO_par(3);
      MACRO_out_constant(atom(125),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_spawn(4,272);  // spawn(call/3)
    case 272:  // return_from_spawn(call/3)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 273:  // test_call3/3
      MACRO_goal(273,atom(130));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_value(reg::in(1));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 274:  // test_call3/2
      MACRO_goal(274,atom(131));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_constant(atom(132));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 275:  // test_otherwise/0
      MACRO_goal(275,atom(133));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(277,276);  // spawn(test_otherwise_aux/1)
    case 276:  // return_from_spawn(test_otherwise_aux/1)
      MACRO_get_constant(tagvalue<TAG_INT>(1),reg::x(1));
      MACRO_proceed;
    case 277:  // test_otherwise_aux/1
      MACRO_goal(277,atom(134));
      MACRO_requires(3);
      MACRO_try_guard_else(278);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(135),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 278:  // test_otherwise_aux/1-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(136),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 279:  // test_write_var/0
      MACRO_goal(279,atom(137));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 280:  // test_write_atom/0
      MACRO_goal(280,atom(138));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(atom(139),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 281:  // test_write_list/0
      MACRO_goal(281,atom(140));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_list(reg::out(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(3));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(4));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(5));
      MACRO_write_void;
      MACRO_execute(104,1);  // execute(writeln/1)
    case 282:  // test_write_structure/0
      MACRO_goal(282,atom(141));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(142),reg::out(1));
      MACRO_write_constant(atom(143));
      MACRO_write_constant(atom(144));
      MACRO_write_constant(atom(145));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 283:  // test_get_structure/0
      MACRO_goal(283,atom(146));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_structure(atom(88),reg::x(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 284:  // test_set_structure/0
      MACRO_goal(284,atom(147));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_structure(atom(88),reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_get_variable(reg::x(2),reg::x(1));
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 285:  // test_get_list/0
      MACRO_goal(285,atom(148));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(3));
      MACRO_unify_nil;
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 286:  // test_set_list/0
      MACRO_goal(286,atom(149));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_list(reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(3));
      MACRO_write_nil;
      MACRO_get_variable(reg::x(2),reg::x(1));
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 287:  // test_check_constant/0
      MACRO_goal(287,atom(150));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(288,1);  // execute(test_check_constant_aux/1)
    case 288:  // test_check_constant_aux/1
      MACRO_goal(288,atom(151));
      MACRO_requires(3);
      MACRO_try_guard_else(289);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(152),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 289:  // test_check_constant_aux/1-2
      MACRO_try_guard_else(290);
      MACRO_check_constant(tagvalue<TAG_INT>(1),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(153),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 290:  // test_check_constant_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 291:  // test_check_list/0
      MACRO_goal(291,atom(155));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_list(reg::out(1));
      MACRO_write_constant(atom(127));
      MACRO_write_list;
      MACRO_write_constant(atom(128));
      MACRO_write_nil;
      MACRO_execute(292,1);  // execute(test_check_list_aux/1)
    case 292:  // test_check_list_aux/1
      MACRO_goal(292,atom(156));
      MACRO_requires(3);
      MACRO_try_guard_else(293);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(157));
      MACRO_read_list;
      MACRO_read_constant(atom(158));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(159),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 293:  // test_check_list_aux/1-2
      MACRO_try_guard_else(294);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(127));
      MACRO_read_list;
      MACRO_read_constant(atom(128));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(160),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 294:  // test_check_list_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 295:  // test_check_nil/0
      MACRO_goal(295,atom(161));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_nil(reg::out(1));
      MACRO_execute(296,1);  // execute(test_check_nil_aux/1)
    case 296:  // test_check_nil_aux/1
      MACRO_goal(296,atom(162));
      MACRO_requires(3);
      MACRO_try_guard_else(297);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(127));
      MACRO_read_list;
      MACRO_read_constant(atom(128));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(163),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 297:  // test_check_nil_aux/1-2
      MACRO_try_guard_else(298);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(164),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 298:  // test_check_nil_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 299:  // test_check_structure/0
      MACRO_goal(299,atom(165));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(166),reg::out(1));
      MACRO_write_constant(atom(127));
      MACRO_write_constant(atom(128));
      MACRO_execute(300,1);  // execute(test_check_structure_aux/1)
    case 300:  // test_check_structure_aux/1
      MACRO_goal(300,atom(167));
      MACRO_requires(3);
      MACRO_try_guard_else(301);
      MACRO_check_structure(atom(166),reg::in(1));
      MACRO_read_constant(atom(157));
      MACRO_read_constant(atom(158));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(168),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 301:  // test_check_structure_aux/1-2
      MACRO_try_guard_else(302);
      MACRO_check_structure(atom(166),reg::in(1));
      MACRO_read_constant(atom(127));
      MACRO_read_constant(atom(128));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(169),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 302:  // test_check_structure_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 303:  // test_wait_var/0
      MACRO_goal(303,atom(170));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(305,304);  // spawn(wait_var/1)
    case 304:  // return_from_spawn(wait_var/1)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(306,1);  // execute(write_var/1)
    case 305:  // wait_var/1
      MACRO_goal(305,atom(171));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 306:  // write_var/1
      MACRO_goal(306,atom(172));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_constant(atom(173),reg::in(1));
      MACRO_proceed;
    case 307:  // test_atom_concat/0
      MACRO_goal(307,atom(174));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(310,308);  // spawn(test_atom_concat_1/0)
    case 308:  // return_from_spawn(test_atom_concat_1/0)
      MACRO_par(2);
      MACRO_spawn(315,309);  // spawn(test_atom_concat_2/0)
    case 309:  // return_from_spawn(test_atom_concat_2/0)
      MACRO_tail(2);
      MACRO_execute(319,0);  // execute(test_atom_concat_3/0)
    case 310:  // test_atom_concat_1/0
      MACRO_goal(310,atom(175));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(176),reg::out(1));
      MACRO_out_constant(atom(177),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(14,311);  // spawn(atom_concat/3)
    case 311:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(178),reg::out(1));
      MACRO_spawn(112,312);  // spawn(write/1)
    case 312:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_constant(atom(61),reg::out(1));
      MACRO_spawn(112,313);  // spawn(write/1)
    case 313:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,314);  // spawn(write/1)
    case 314:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(62),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 315:  // test_atom_concat_2/0
      MACRO_goal(315,atom(179));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(176),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(180),reg::out(3));
      MACRO_spawn(14,316);  // spawn(atom_concat/3)
    case 316:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(181),reg::out(1));
      MACRO_spawn(112,317);  // spawn(write/1)
    case 317:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,318);  // spawn(write/1)
    case 318:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(182),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 319:  // test_atom_concat_3/0
      MACRO_goal(319,atom(183));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_out_constant(atom(177),reg::out(2));
      MACRO_out_constant(atom(180),reg::out(3));
      MACRO_spawn(14,320);  // spawn(atom_concat/3)
    case 320:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(61),reg::out(1));
      MACRO_spawn(112,321);  // spawn(write/1)
    case 321:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,322);  // spawn(write/1)
    case 322:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(184),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 323:  // test_atom_chars/0
      MACRO_goal(323,atom(185));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(325,324);  // spawn(test_atom_chars1/0)
    case 324:  // return_from_spawn(test_atom_chars1/0)
      MACRO_tail(2);
      MACRO_execute(329,0);  // execute(test_atom_chars2/0)
    case 325:  // test_atom_chars1/0
      MACRO_goal(325,atom(186));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(187),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(37,326);  // spawn(atom_chars/2)
    case 326:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,327);  // spawn(write/1)
    case 327:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(188),reg::out(1));
      MACRO_spawn(112,328);  // spawn(write/1)
    case 328:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 329:  // test_atom_chars2/0
      MACRO_goal(329,atom(189));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_spawn(37,330);  // spawn(atom_chars/2)
    case 330:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,331);  // spawn(write/1)
    case 331:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(203),reg::out(1));
      MACRO_spawn(112,332);  // spawn(write/1)
    case 332:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 333:  // test_atom_codes/0
      MACRO_goal(333,atom(204));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(335,334);  // spawn(test_atom_codes1/0)
    case 334:  // return_from_spawn(test_atom_codes1/0)
      MACRO_tail(2);
      MACRO_execute(339,0);  // execute(test_atom_codes2/0)
    case 335:  // test_atom_codes1/0
      MACRO_goal(335,atom(205));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(187),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(26,336);  // spawn(atom_codes/2)
    case 336:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,337);  // spawn(write/1)
    case 337:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(188),reg::out(1));
      MACRO_spawn(112,338);  // spawn(write/1)
    case 338:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 339:  // test_atom_codes2/0
      MACRO_goal(339,atom(206));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(97));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(98));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(99));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(100));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(101));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(102));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(103));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(227));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(129));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(130));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(227));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(129));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(132));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(227));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(129));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(134));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(227));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(129));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(136));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(227));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(129));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(138));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(230));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(188));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(162));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(229));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(173));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(151));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(226));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(152));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(186));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(240));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(159));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(141));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(186));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_spawn(26,340);  // spawn(atom_codes/2)
    case 340:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,341);  // spawn(write/1)
    case 341:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(203),reg::out(1));
      MACRO_spawn(112,342);  // spawn(write/1)
    case 342:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 343:  // test_append/0
      MACRO_goal(343,atom(207));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(346,344);  // spawn(test_append1/0)
    case 344:  // return_from_spawn(test_append1/0)
      MACRO_par(2);
      MACRO_spawn(353,345);  // spawn(test_append2/0)
    case 345:  // return_from_spawn(test_append2/0)
      MACRO_tail(2);
      MACRO_execute(360,0);  // execute(test_append3/0)
    case 346:  // test_append1/0
      MACRO_goal(346,atom(208));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_variable(reg::x(3),reg::out(3));
      MACRO_spawn(228,347);  // spawn(append/3)
    case 347:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,348);  // spawn(write/1)
    case 348:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(209),reg::out(1));
      MACRO_spawn(112,349);  // spawn(write/1)
    case 349:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,350);  // spawn(write/1)
    case 350:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(210),reg::out(1));
      MACRO_spawn(112,351);  // spawn(write/1)
    case 351:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(112,352);  // spawn(write/1)
    case 352:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_constant(atom(62),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 353:  // test_append2/0
      MACRO_goal(353,atom(211));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_value(reg::x(1),reg::out(3));
      MACRO_spawn(228,354);  // spawn(append/3)
    case 354:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,355);  // spawn(write/1)
    case 355:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(209),reg::out(1));
      MACRO_spawn(112,356);  // spawn(write/1)
    case 356:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(61),reg::out(1));
      MACRO_spawn(112,357);  // spawn(write/1)
    case 357:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(112,358);  // spawn(write/1)
    case 358:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(212),reg::out(1));
      MACRO_spawn(112,359);  // spawn(write/1)
    case 359:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 360:  // test_append3/0
      MACRO_goal(360,atom(213));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_value(reg::x(2),reg::out(3));
      MACRO_spawn(228,361);  // spawn(append/3)
    case 361:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_constant(atom(61),reg::out(1));
      MACRO_spawn(112,362);  // spawn(write/1)
    case 362:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(112,363);  // spawn(write/1)
    case 363:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(214),reg::out(1));
      MACRO_spawn(112,364);  // spawn(write/1)
    case 364:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,365);  // spawn(write/1)
    case 365:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(215),reg::out(1));
      MACRO_spawn(112,366);  // spawn(write/1)
    case 366:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 367:  // test_reverse/0
      MACRO_goal(367,atom(216));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(236,368);  // spawn(reverse/2)
    case 368:  // return_from_spawn(reverse/2)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 369:  // test_nth0/0
      MACRO_goal(369,atom(217));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(371,370);  // spawn(test_nth0_/0)
    case 370:  // return_from_spawn(test_nth0_/0)
      MACRO_tail(2);
      MACRO_execute(390,0);  // execute(test_nth0_rev_/0)
    case 371:  // test_nth0_/0
      MACRO_goal(371,atom(218));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(242,372);  // spawn(nth0/3)
    case 372:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(219),reg::out(1));
      MACRO_spawn(112,373);  // spawn(write/1)
    case 373:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,374);  // spawn(write/1)
    case 374:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(242,375);  // spawn(nth0/3)
    case 375:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(220),reg::out(1));
      MACRO_spawn(112,376);  // spawn(write/1)
    case 376:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,377);  // spawn(write/1)
    case 377:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(242,378);  // spawn(nth0/3)
    case 378:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(221),reg::out(1));
      MACRO_spawn(112,379);  // spawn(write/1)
    case 379:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,380);  // spawn(write/1)
    case 380:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(242,381);  // spawn(nth0/3)
    case 381:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(222),reg::out(1));
      MACRO_spawn(112,382);  // spawn(write/1)
    case 382:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,383);  // spawn(write/1)
    case 383:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(242,384);  // spawn(nth0/3)
    case 384:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(223),reg::out(1));
      MACRO_spawn(112,385);  // spawn(write/1)
    case 385:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,386);  // spawn(write/1)
    case 386:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(242,387);  // spawn(nth0/3)
    case 387:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(224),reg::out(1));
      MACRO_spawn(112,388);  // spawn(write/1)
    case 388:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,389);  // spawn(write/1)
    case 389:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(62),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 390:  // test_nth0_rev_/0
      MACRO_goal(390,atom(225));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(127),reg::out(3));
      MACRO_spawn(242,391);  // spawn(nth0/3)
    case 391:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,392);  // spawn(write/1)
    case 392:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,393);  // spawn(write/1)
    case 393:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(227),reg::out(1));
      MACRO_spawn(112,394);  // spawn(write/1)
    case 394:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(128),reg::out(3));
      MACRO_spawn(242,395);  // spawn(nth0/3)
    case 395:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,396);  // spawn(write/1)
    case 396:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,397);  // spawn(write/1)
    case 397:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(228),reg::out(1));
      MACRO_spawn(112,398);  // spawn(write/1)
    case 398:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(129),reg::out(3));
      MACRO_spawn(242,399);  // spawn(nth0/3)
    case 399:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,400);  // spawn(write/1)
    case 400:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,401);  // spawn(write/1)
    case 401:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(229),reg::out(1));
      MACRO_spawn(112,402);  // spawn(write/1)
    case 402:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(190),reg::out(3));
      MACRO_spawn(242,403);  // spawn(nth0/3)
    case 403:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,404);  // spawn(write/1)
    case 404:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,405);  // spawn(write/1)
    case 405:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(230),reg::out(1));
      MACRO_spawn(112,406);  // spawn(write/1)
    case 406:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(191),reg::out(3));
      MACRO_spawn(242,407);  // spawn(nth0/3)
    case 407:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,408);  // spawn(write/1)
    case 408:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,409);  // spawn(write/1)
    case 409:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(231),reg::out(1));
      MACRO_spawn(112,410);  // spawn(write/1)
    case 410:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(192),reg::out(3));
      MACRO_spawn(242,411);  // spawn(nth0/3)
    case 411:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,412);  // spawn(write/1)
    case 412:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,413);  // spawn(write/1)
    case 413:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(232),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 414:  // test_nth1/0
      MACRO_goal(414,atom(233));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(416,415);  // spawn(test_nth1_/0)
    case 415:  // return_from_spawn(test_nth1_/0)
      MACRO_tail(2);
      MACRO_execute(432,0);  // execute(test_nth1_rev_/0)
    case 416:  // test_nth1_/0
      MACRO_goal(416,atom(234));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(252,417);  // spawn(nth1/3)
    case 417:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(235),reg::out(1));
      MACRO_spawn(112,418);  // spawn(write/1)
    case 418:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,419);  // spawn(write/1)
    case 419:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(252,420);  // spawn(nth1/3)
    case 420:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(221),reg::out(1));
      MACRO_spawn(112,421);  // spawn(write/1)
    case 421:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,422);  // spawn(write/1)
    case 422:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(252,423);  // spawn(nth1/3)
    case 423:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(222),reg::out(1));
      MACRO_spawn(112,424);  // spawn(write/1)
    case 424:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,425);  // spawn(write/1)
    case 425:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(252,426);  // spawn(nth1/3)
    case 426:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(223),reg::out(1));
      MACRO_spawn(112,427);  // spawn(write/1)
    case 427:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,428);  // spawn(write/1)
    case 428:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(252,429);  // spawn(nth1/3)
    case 429:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(224),reg::out(1));
      MACRO_spawn(112,430);  // spawn(write/1)
    case 430:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(112,431);  // spawn(write/1)
    case 431:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(62),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 432:  // test_nth1_rev_/0
      MACRO_goal(432,atom(236));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(127));
      MACRO_unify_list;
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_list;
      MACRO_unify_constant(atom(196));
      MACRO_unify_list;
      MACRO_unify_constant(atom(197));
      MACRO_unify_list;
      MACRO_unify_constant(atom(198));
      MACRO_unify_list;
      MACRO_unify_constant(atom(199));
      MACRO_unify_list;
      MACRO_unify_constant(atom(200));
      MACRO_unify_list;
      MACRO_unify_constant(atom(201));
      MACRO_unify_list;
      MACRO_unify_constant(atom(202));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(127),reg::out(3));
      MACRO_spawn(252,433);  // spawn(nth1/3)
    case 433:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,434);  // spawn(write/1)
    case 434:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,435);  // spawn(write/1)
    case 435:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(227),reg::out(1));
      MACRO_spawn(112,436);  // spawn(write/1)
    case 436:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(128),reg::out(3));
      MACRO_spawn(252,437);  // spawn(nth1/3)
    case 437:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,438);  // spawn(write/1)
    case 438:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,439);  // spawn(write/1)
    case 439:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(228),reg::out(1));
      MACRO_spawn(112,440);  // spawn(write/1)
    case 440:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(129),reg::out(3));
      MACRO_spawn(252,441);  // spawn(nth1/3)
    case 441:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,442);  // spawn(write/1)
    case 442:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,443);  // spawn(write/1)
    case 443:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(229),reg::out(1));
      MACRO_spawn(112,444);  // spawn(write/1)
    case 444:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(190),reg::out(3));
      MACRO_spawn(252,445);  // spawn(nth1/3)
    case 445:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,446);  // spawn(write/1)
    case 446:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,447);  // spawn(write/1)
    case 447:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(230),reg::out(1));
      MACRO_spawn(112,448);  // spawn(write/1)
    case 448:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(191),reg::out(3));
      MACRO_spawn(252,449);  // spawn(nth1/3)
    case 449:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(112,450);  // spawn(write/1)
    case 450:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(112,451);  // spawn(write/1)
    case 451:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(231),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 452:  // test_splice_suspension/0
      MACRO_goal(452,atom(237));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(457,453);  // spawn(test_splice_suspension1/1)
    case 453:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(457,454);  // spawn(test_splice_suspension1/1)
    case 454:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_spawn(457,455);  // spawn(test_splice_suspension1/1)
    case 455:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_get_value(reg::x(2),reg::x(1));
      MACRO_get_value(reg::x(3),reg::x(2));
      MACRO_par(4);
      MACRO_out_constant(atom(238),reg::out(1));
      MACRO_spawn(262,456);  // spawn(dump_to_dot/1)
    case 456:  // return_from_spawn(dump_to_dot/1)
      MACRO_get_constant(atom(237),reg::x(1));
      MACRO_proceed;
    case 457:  // test_splice_suspension1/1
      MACRO_goal(457,atom(239));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
    case 458:  // test_calc/0
      MACRO_goal(458,atom(240));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(241),reg::out(1));
      MACRO_spawn(104,459);  // spawn(writeln/1)
    case 459:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_call(184,460);  // call(__sub__/3)
    case 460:  // return_from_call(__sub__/3)
      MACRO_par(3);
      MACRO_out_constant(atom(242),reg::out(1));
      MACRO_spawn(104,461);  // spawn(writeln/1)
    case 461:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_structure(atom(87),reg::out(1));
      MACRO_write_value(reg::x(2));
      MACRO_write_structure(atom(89));
      MACRO_write_value(reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(104,462);  // spawn(writeln/1)
    case 462:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_constant(atom(243),reg::out(1));
      MACRO_spawn(262,463);  // spawn(dump_to_dot/1)
    case 463:  // return_from_spawn(dump_to_dot/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_call(178,464);  // call(__add__/3)
    case 464:  // return_from_call(__add__/3)
      MACRO_par(3);
      MACRO_out_structure(atom(87),reg::out(1));
      MACRO_write_value(reg::x(2));
      MACRO_write_structure(atom(88));
      MACRO_write_value(reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(104,465);  // spawn(writeln/1)
    case 465:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_constant(atom(244),reg::out(1));
      MACRO_spawn(104,466);  // spawn(writeln/1)
    case 466:  // return_from_spawn(writeln/1)
      MACRO_get_constant(tagvalue<TAG_INT>(10),reg::x(1));
      MACRO_proceed;
    case 467:  // do_test/1
      MACRO_goal(467,atom(245));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(112,468);  // call(write/1)
    case 468:  // return_from_call(write/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(246),reg::out(1));
      MACRO_call(104,469);  // call(writeln/1)
    case 469:  // return_from_call(writeln/1)
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(6,1);  // execute(time/1)
    case 470:  // main/1
      MACRO_goal(470,atom(247));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_constant(atom(125),reg::out(1));
      MACRO_call(467,471);  // call(do_test/1)
    case 471:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(133),reg::out(1));
      MACRO_call(467,472);  // call(do_test/1)
    case 472:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(137),reg::out(1));
      MACRO_call(467,473);  // call(do_test/1)
    case 473:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_call(467,474);  // call(do_test/1)
    case 474:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(140),reg::out(1));
      MACRO_call(467,475);  // call(do_test/1)
    case 475:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(141),reg::out(1));
      MACRO_call(467,476);  // call(do_test/1)
    case 476:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(146),reg::out(1));
      MACRO_call(467,477);  // call(do_test/1)
    case 477:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(147),reg::out(1));
      MACRO_call(467,478);  // call(do_test/1)
    case 478:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(148),reg::out(1));
      MACRO_call(467,479);  // call(do_test/1)
    case 479:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(149),reg::out(1));
      MACRO_call(467,480);  // call(do_test/1)
    case 480:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(150),reg::out(1));
      MACRO_call(467,481);  // call(do_test/1)
    case 481:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(155),reg::out(1));
      MACRO_call(467,482);  // call(do_test/1)
    case 482:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(161),reg::out(1));
      MACRO_call(467,483);  // call(do_test/1)
    case 483:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(165),reg::out(1));
      MACRO_call(467,484);  // call(do_test/1)
    case 484:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(170),reg::out(1));
      MACRO_call(467,485);  // call(do_test/1)
    case 485:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(174),reg::out(1));
      MACRO_call(467,486);  // call(do_test/1)
    case 486:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(185),reg::out(1));
      MACRO_call(467,487);  // call(do_test/1)
    case 487:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(204),reg::out(1));
      MACRO_call(467,488);  // call(do_test/1)
    case 488:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(207),reg::out(1));
      MACRO_call(467,489);  // call(do_test/1)
    case 489:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(216),reg::out(1));
      MACRO_call(467,490);  // call(do_test/1)
    case 490:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_call(467,491);  // call(do_test/1)
    case 491:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(233),reg::out(1));
      MACRO_call(467,492);  // call(do_test/1)
    case 492:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(237),reg::out(1));
      MACRO_call(467,493);  // call(do_test/1)
    case 493:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(240),reg::out(1));
      MACRO_call(467,494);  // call(do_test/1)
    case 494:  // return_from_call(do_test/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(258,495);  // spawn(inference_count/1)
    case 495:  // return_from_spawn(inference_count/1)
      MACRO_par(3);
      MACRO_out_constant(atom(248),reg::out(1));
      MACRO_spawn(112,496);  // spawn(write/1)
    case 496:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(104,1);  // execute(writeln/1)
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
  atom(4) = to_atom("call", 3);
  atom(5) = to_atom("__call__", 3);
  atom(6) = to_atom("time", 1);
  atom(7) = to_atom("wait_time", 1);
  atom(8) = to_atom("__wait_time__", 4);
  atom(9) = to_atom("__time_pre__", 3);
  atom(10) = to_atom("__time_post__", 3);
  atom(11) = to_atom("atom_concat", 3);
  atom(12) = to_atom("__atom_concat_1__", 3);
  atom(13) = to_atom("__atom_concat_2__", 3);
  atom(14) = to_atom("__atom_concat_3__", 3);
  atom(15) = to_atom("atom_codes", 2);
  atom(16) = to_atom("", 0);
  atom(17) = to_atom("__atom_to_codes__", 2);
  atom(18) = to_atom("__codes_to_atom__", 3);
  atom(19) = to_atom("__atom_code_concat__", 3);
  atom(20) = to_atom("inline", 1);
  atom(21) = to_atom("  MACRO_proceed;", 0);
  atom(22) = to_atom("atom_chars", 2);
  atom(23) = to_atom("__atom_to_chars__", 2);
  atom(24) = to_atom("__chars_to_atom__", 3);
  atom(25) = to_atom("atom_number", 2);
  atom(26) = to_atom("__atom_to_number__", 2);
  atom(27) = to_atom("__number_to_atom__", 2);
  atom(28) = to_atom("outstream", 1);
  atom(29) = to_atom("outstream", 2);
  atom(30) = to_atom("open", 3);
  atom(31) = to_atom("write", 2);
  atom(32) = to_atom("write", 1);
  atom(33) = to_atom("writeln", 2);
  atom(34) = to_atom("writeln", 1);
  atom(35) = to_atom("nl", 1);
  atom(36) = to_atom("nl", 0);
  atom(37) = to_atom("close", 1);
  atom(38) = to_atom("__open_opt_string_to_integer__", 3);
  atom(39) = to_atom("__open_opt_string_to_integer__", 5);
  atom(40) = to_atom("rdonly", 0);
  atom(41) = to_atom("wronly", 0);
  atom(42) = to_atom("rdwr", 0);
  atom(43) = to_atom("creat", 0);
  atom(44) = to_atom("excl", 0);
  atom(45) = to_atom("trunc", 0);
  atom(46) = to_atom("append", 0);
  atom(47) = to_atom("rusr", 0);
  atom(48) = to_atom("wusr", 0);
  atom(49) = to_atom("xusr", 0);
  atom(50) = to_atom("rgrp", 0);
  atom(51) = to_atom("wgrp", 0);
  atom(52) = to_atom("xgrp", 0);
  atom(53) = to_atom("roth", 0);
  atom(54) = to_atom("woth", 0);
  atom(55) = to_atom("xoth", 0);
  atom(56) = to_atom("__open__", 4);
  atom(57) = to_atom("__close__", 1);
  atom(58) = to_atom("__nl__", 1);
  atom(59) = to_atom("__write__", 2);
  atom(60) = to_atom("[]", 0);
  atom(61) = to_atom("[", 0);
  atom(62) = to_atom("]", 0);
  atom(63) = to_atom("__write_functor_args__", 2);
  atom(64) = to_atom("(", 0);
  atom(65) = to_atom(")", 0);
  atom(66) = to_atom("__write_functor_args2__", 2);
  atom(67) = to_atom("__write_functor_tail__", 2);
  atom(68) = to_atom(",", 0);
  atom(69) = to_atom("__write_list_tail__", 2);
  atom(70) = to_atom("|", 0);
  atom(71) = to_atom("__write_number__", 2);
  atom(72) = to_atom("__write_atom__", 2);
  atom(73) = to_atom("__write_var__", 2);
  atom(74) = to_atom("integer", 1);
  atom(75) = to_atom("atom", 1);
  atom(76) = to_atom("var", 1);
  atom(77) = to_atom("is_functor", 1);
  atom(78) = to_atom("=..", 2);
  atom(79) = to_atom("==", 2);
  atom(80) = to_atom(">=", 2);
  atom(81) = to_atom("=<", 2);
  atom(82) = to_atom(">", 2);
  atom(83) = to_atom("<", 2);
  atom(84) = to_atom("=:=", 2);
  atom(85) = to_atom("=\\=", 2);
  atom(86) = to_atom("__not_equal__", 2);
  atom(87) = to_atom(":=", 2);
  atom(88) = to_atom("+", 2);
  atom(89) = to_atom("-", 2);
  atom(90) = to_atom("*", 2);
  atom(91) = to_atom("/", 2);
  atom(92) = to_atom("mod", 2);
  atom(93) = to_atom("-", 1);
  atom(94) = to_atom("__add__", 3);
  atom(95) = to_atom("__sub__", 3);
  atom(96) = to_atom("__mul__", 3);
  atom(97) = to_atom("__div__", 3);
  atom(98) = to_atom("__mod__", 3);
  atom(99) = to_atom("__neg__", 2);
  atom(100) = to_atom("__ineg__", 2);
  atom(101) = to_atom("__iadd__", 3);
  atom(102) = to_atom("__isub__", 3);
  atom(103) = to_atom("__imul__", 3);
  atom(104) = to_atom("__idiv__", 3);
  atom(105) = to_atom("__imod__", 3);
  atom(106) = to_atom("__inc__", 2);
  atom(107) = to_atom("__dec__", 2);
  atom(108) = to_atom("__iinc__", 2);
  atom(109) = to_atom("__idec__", 2);
  atom(110) = to_atom("append", 3);
  atom(111) = to_atom("reverse", 2);
  atom(112) = to_atom("__reverse__", 3);
  atom(113) = to_atom("nth0", 3);
  atom(114) = to_atom("__nth0__", 3);
  atom(115) = to_atom("__nth0_rev__", 4);
  atom(116) = to_atom("nth1", 3);
  atom(117) = to_atom("inference_count", 1);
  atom(118) = to_atom("__inference_count__", 1);
  atom(119) = to_atom("resume_count", 1);
  atom(120) = to_atom("__resume_count__", 1);
  atom(121) = to_atom("dump_to_dot", 1);
  atom(122) = to_atom("__dump_to_dot__", 1);
  atom(123) = to_atom("dump_to_dot", 2);
  atom(124) = to_atom("__dump_to_dot__", 2);
  atom(125) = to_atom("test_call3", 0);
  atom(126) = to_atom("test_call3", 1);
  atom(127) = to_atom("a", 0);
  atom(128) = to_atom("b", 0);
  atom(129) = to_atom("c", 0);
  atom(130) = to_atom("test_call3", 3);
  atom(131) = to_atom("test_call3", 2);
  atom(132) = to_atom("done", 0);
  atom(133) = to_atom("test_otherwise", 0);
  atom(134) = to_atom("test_otherwise_aux", 1);
  atom(135) = to_atom("test failed", 0);
  atom(136) = to_atom("test success", 0);
  atom(137) = to_atom("test_write_var", 0);
  atom(138) = to_atom("test_write_atom", 0);
  atom(139) = to_atom("atom", 0);
  atom(140) = to_atom("test_write_list", 0);
  atom(141) = to_atom("test_write_structure", 0);
  atom(142) = to_atom("some", 3);
  atom(143) = to_atom("structure", 0);
  atom(144) = to_atom("and", 0);
  atom(145) = to_atom("arguments", 0);
  atom(146) = to_atom("test_get_structure", 0);
  atom(147) = to_atom("test_set_structure", 0);
  atom(148) = to_atom("test_get_list", 0);
  atom(149) = to_atom("test_set_list", 0);
  atom(150) = to_atom("test_check_constant", 0);
  atom(151) = to_atom("test_check_constant_aux", 1);
  atom(152) = to_atom("test failed(0)", 0);
  atom(153) = to_atom("test success(1)", 0);
  atom(154) = to_atom("test failed(otherwise)", 0);
  atom(155) = to_atom("test_check_list", 0);
  atom(156) = to_atom("test_check_list_aux", 1);
  atom(157) = to_atom("x", 0);
  atom(158) = to_atom("y", 0);
  atom(159) = to_atom("test failed([x,y])", 0);
  atom(160) = to_atom("test success([a,b])", 0);
  atom(161) = to_atom("test_check_nil", 0);
  atom(162) = to_atom("test_check_nil_aux", 1);
  atom(163) = to_atom("test failed([a,b])", 0);
  atom(164) = to_atom("test success([])", 0);
  atom(165) = to_atom("test_check_structure", 0);
  atom(166) = to_atom("fun", 2);
  atom(167) = to_atom("test_check_structure_aux", 1);
  atom(168) = to_atom("test failed(fun(x,y))", 0);
  atom(169) = to_atom("test success(fun(a,b))", 0);
  atom(170) = to_atom("test_wait_var", 0);
  atom(171) = to_atom("wait_var", 1);
  atom(172) = to_atom("write_var", 1);
  atom(173) = to_atom("fire", 0);
  atom(174) = to_atom("test_atom_concat", 0);
  atom(175) = to_atom("test_atom_concat_1", 0);
  atom(176) = to_atom("abc", 0);
  atom(177) = to_atom("def", 0);
  atom(178) = to_atom("abc + def = ", 0);
  atom(179) = to_atom("test_atom_concat_2", 0);
  atom(180) = to_atom("abcdef", 0);
  atom(181) = to_atom("abc + [", 0);
  atom(182) = to_atom("] = abcdef", 0);
  atom(183) = to_atom("test_atom_concat_3", 0);
  atom(184) = to_atom("] + def = abcdef", 0);
  atom(185) = to_atom("test_atom_chars", 0);
  atom(186) = to_atom("test_atom_chars1", 0);
  atom(187) = to_atom("abcdefgあいうえお漢字☺🍺", 0);
  atom(188) = to_atom(" -> ", 0);
  atom(189) = to_atom("test_atom_chars2", 0);
  atom(190) = to_atom("d", 0);
  atom(191) = to_atom("e", 0);
  atom(192) = to_atom("f", 0);
  atom(193) = to_atom("g", 0);
  atom(194) = to_atom("あ", 0);
  atom(195) = to_atom("い", 0);
  atom(196) = to_atom("う", 0);
  atom(197) = to_atom("え", 0);
  atom(198) = to_atom("お", 0);
  atom(199) = to_atom("漢", 0);
  atom(200) = to_atom("字", 0);
  atom(201) = to_atom("☺", 0);
  atom(202) = to_atom("🍺", 0);
  atom(203) = to_atom(" <- ", 0);
  atom(204) = to_atom("test_atom_codes", 0);
  atom(205) = to_atom("test_atom_codes1", 0);
  atom(206) = to_atom("test_atom_codes2", 0);
  atom(207) = to_atom("test_append", 0);
  atom(208) = to_atom("test_append1", 0);
  atom(209) = to_atom("+", 0);
  atom(210) = to_atom("=[", 0);
  atom(211) = to_atom("test_append2", 0);
  atom(212) = to_atom("]=", 0);
  atom(213) = to_atom("test_append3", 0);
  atom(214) = to_atom("]+", 0);
  atom(215) = to_atom("=", 0);
  atom(216) = to_atom("test_reverse", 0);
  atom(217) = to_atom("test_nth0", 0);
  atom(218) = to_atom("test_nth0_", 0);
  atom(219) = to_atom(" 0: [", 0);
  atom(220) = to_atom("] 1: [", 0);
  atom(221) = to_atom("] 2: [", 0);
  atom(222) = to_atom("] 3: [", 0);
  atom(223) = to_atom("] 4: [", 0);
  atom(224) = to_atom("] 5: [", 0);
  atom(225) = to_atom("test_nth0_rev_", 0);
  atom(226) = to_atom(" [", 0);
  atom(227) = to_atom("]: a", 0);
  atom(228) = to_atom("]: b", 0);
  atom(229) = to_atom("]: c", 0);
  atom(230) = to_atom("]: d", 0);
  atom(231) = to_atom("]: e", 0);
  atom(232) = to_atom("]: f", 0);
  atom(233) = to_atom("test_nth1", 0);
  atom(234) = to_atom("test_nth1_", 0);
  atom(235) = to_atom(" 1: [", 0);
  atom(236) = to_atom("test_nth1_rev_", 0);
  atom(237) = to_atom("test_splice_suspension", 0);
  atom(238) = to_atom("dump/splice.dot", 0);
  atom(239) = to_atom("test_splice_suspension1", 1);
  atom(240) = to_atom("test_calc", 0);
  atom(241) = to_atom("xxx0", 0);
  atom(242) = to_atom("xxx1", 0);
  atom(243) = to_atom("dump/calc.dot", 0);
  atom(244) = to_atom("xxx", 0);
  atom(245) = to_atom("do_test", 1);
  atom(246) = to_atom(": ", 0);
  atom(247) = to_atom("main", 1);
  atom(248) = to_atom("total_inferences=", 0);
  // setup entry points
  prog->add_entry_point(atom(1), 1);  // fail / 0
  prog->add_entry_point(atom(2), 2);  // call / 1
  prog->add_entry_point(atom(3), 3);  // __call__ / 1
  prog->add_entry_point(atom(4), 4);  // call / 3
  prog->add_entry_point(atom(5), 5);  // __call__ / 3
  prog->add_entry_point(atom(6), 6);  // time / 1
  prog->add_entry_point(atom(7), 9);  // wait_time / 1
  prog->add_entry_point(atom(8), 11);  // __wait_time__ / 4
  prog->add_entry_point(atom(9), 12);  // __time_pre__ / 3
  prog->add_entry_point(atom(10), 13);  // __time_post__ / 3
  prog->add_entry_point(atom(11), 14);  // atom_concat / 3
  prog->add_entry_point(atom(12), 23);  // __atom_concat_1__ / 3
  prog->add_entry_point(atom(13), 24);  // __atom_concat_2__ / 3
  prog->add_entry_point(atom(14), 25);  // __atom_concat_3__ / 3
  prog->add_entry_point(atom(15), 26);  // atom_codes / 2
  prog->add_entry_point(atom(17), 29);  // __atom_to_codes__ / 2
  prog->add_entry_point(atom(18), 30);  // __codes_to_atom__ / 3
  prog->add_entry_point(atom(19), 34);  // __atom_code_concat__ / 3
  prog->add_entry_point(atom(20), 35);  // inline / 1
  prog->add_entry_point(atom(22), 37);  // atom_chars / 2
  prog->add_entry_point(atom(23), 40);  // __atom_to_chars__ / 2
  prog->add_entry_point(atom(24), 41);  // __chars_to_atom__ / 3
  prog->add_entry_point(atom(25), 44);  // atom_number / 2
  prog->add_entry_point(atom(26), 48);  // __atom_to_number__ / 2
  prog->add_entry_point(atom(27), 49);  // __number_to_atom__ / 2
  prog->add_entry_point(atom(28), 50);  // outstream / 1
  prog->add_entry_point(atom(29), 52);  // outstream / 2
  prog->add_entry_point(atom(30), 66);  // open / 3
  prog->add_entry_point(atom(37), 68);  // close / 1
  prog->add_entry_point(atom(38), 69);  // __open_opt_string_to_integer__ / 3
  prog->add_entry_point(atom(39), 70);  // __open_opt_string_to_integer__ / 5
  prog->add_entry_point(atom(56), 102);  // __open__ / 4
  prog->add_entry_point(atom(57), 103);  // __close__ / 1
  prog->add_entry_point(atom(34), 104);  // writeln / 1
  prog->add_entry_point(atom(33), 106);  // writeln / 2
  prog->add_entry_point(atom(36), 108);  // nl / 0
  prog->add_entry_point(atom(35), 109);  // nl / 1
  prog->add_entry_point(atom(58), 111);  // __nl__ / 1
  prog->add_entry_point(atom(32), 112);  // write / 1
  prog->add_entry_point(atom(31), 113);  // write / 2
  prog->add_entry_point(atom(59), 115);  // __write__ / 2
  prog->add_entry_point(atom(63), 130);  // __write_functor_args__ / 2
  prog->add_entry_point(atom(66), 134);  // __write_functor_args2__ / 2
  prog->add_entry_point(atom(67), 137);  // __write_functor_tail__ / 2
  prog->add_entry_point(atom(69), 141);  // __write_list_tail__ / 2
  prog->add_entry_point(atom(71), 150);  // __write_number__ / 2
  prog->add_entry_point(atom(72), 151);  // __write_atom__ / 2
  prog->add_entry_point(atom(73), 152);  // __write_var__ / 2
  prog->add_entry_point(atom(74), 153);  // integer / 1
  prog->add_entry_point(atom(75), 154);  // atom / 1
  prog->add_entry_point(atom(76), 155);  // var / 1
  prog->add_entry_point(atom(77), 156);  // is_functor / 1
  prog->add_entry_point(atom(78), 157);  // =.. / 2
  prog->add_entry_point(atom(79), 158);  // == / 2
  prog->add_entry_point(atom(80), 159);  // >= / 2
  prog->add_entry_point(atom(81), 160);  // =< / 2
  prog->add_entry_point(atom(82), 161);  // > / 2
  prog->add_entry_point(atom(83), 162);  // < / 2
  prog->add_entry_point(atom(84), 163);  // =:= / 2
  prog->add_entry_point(atom(85), 166);  // =\= / 2
  prog->add_entry_point(atom(86), 169);  // __not_equal__ / 2
  prog->add_entry_point(atom(87), 170);  // := / 2
  prog->add_entry_point(atom(94), 178);  // __add__ / 3
  prog->add_entry_point(atom(95), 184);  // __sub__ / 3
  prog->add_entry_point(atom(96), 190);  // __mul__ / 3
  prog->add_entry_point(atom(97), 196);  // __div__ / 3
  prog->add_entry_point(atom(98), 202);  // __mod__ / 3
  prog->add_entry_point(atom(99), 208);  // __neg__ / 2
  prog->add_entry_point(atom(100), 212);  // __ineg__ / 2
  prog->add_entry_point(atom(101), 213);  // __iadd__ / 3
  prog->add_entry_point(atom(102), 214);  // __isub__ / 3
  prog->add_entry_point(atom(103), 215);  // __imul__ / 3
  prog->add_entry_point(atom(104), 216);  // __idiv__ / 3
  prog->add_entry_point(atom(105), 217);  // __imod__ / 3
  prog->add_entry_point(atom(106), 218);  // __inc__ / 2
  prog->add_entry_point(atom(107), 222);  // __dec__ / 2
  prog->add_entry_point(atom(108), 226);  // __iinc__ / 2
  prog->add_entry_point(atom(109), 227);  // __idec__ / 2
  prog->add_entry_point(atom(110), 228);  // append / 3
  prog->add_entry_point(atom(111), 236);  // reverse / 2
  prog->add_entry_point(atom(112), 240);  // __reverse__ / 3
  prog->add_entry_point(atom(113), 242);  // nth0 / 3
  prog->add_entry_point(atom(114), 246);  // __nth0__ / 3
  prog->add_entry_point(atom(115), 249);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(116), 252);  // nth1 / 3
  prog->add_entry_point(atom(117), 258);  // inference_count / 1
  prog->add_entry_point(atom(118), 259);  // __inference_count__ / 1
  prog->add_entry_point(atom(119), 260);  // resume_count / 1
  prog->add_entry_point(atom(120), 261);  // __resume_count__ / 1
  prog->add_entry_point(atom(121), 262);  // dump_to_dot / 1
  prog->add_entry_point(atom(122), 264);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(123), 265);  // dump_to_dot / 2
  prog->add_entry_point(atom(124), 267);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(125), 268);  // test_call3 / 0
  prog->add_entry_point(atom(130), 273);  // test_call3 / 3
  prog->add_entry_point(atom(131), 274);  // test_call3 / 2
  prog->add_entry_point(atom(133), 275);  // test_otherwise / 0
  prog->add_entry_point(atom(134), 277);  // test_otherwise_aux / 1
  prog->add_entry_point(atom(137), 279);  // test_write_var / 0
  prog->add_entry_point(atom(138), 280);  // test_write_atom / 0
  prog->add_entry_point(atom(140), 281);  // test_write_list / 0
  prog->add_entry_point(atom(141), 282);  // test_write_structure / 0
  prog->add_entry_point(atom(146), 283);  // test_get_structure / 0
  prog->add_entry_point(atom(147), 284);  // test_set_structure / 0
  prog->add_entry_point(atom(148), 285);  // test_get_list / 0
  prog->add_entry_point(atom(149), 286);  // test_set_list / 0
  prog->add_entry_point(atom(150), 287);  // test_check_constant / 0
  prog->add_entry_point(atom(151), 288);  // test_check_constant_aux / 1
  prog->add_entry_point(atom(155), 291);  // test_check_list / 0
  prog->add_entry_point(atom(156), 292);  // test_check_list_aux / 1
  prog->add_entry_point(atom(161), 295);  // test_check_nil / 0
  prog->add_entry_point(atom(162), 296);  // test_check_nil_aux / 1
  prog->add_entry_point(atom(165), 299);  // test_check_structure / 0
  prog->add_entry_point(atom(167), 300);  // test_check_structure_aux / 1
  prog->add_entry_point(atom(170), 303);  // test_wait_var / 0
  prog->add_entry_point(atom(171), 305);  // wait_var / 1
  prog->add_entry_point(atom(172), 306);  // write_var / 1
  prog->add_entry_point(atom(174), 307);  // test_atom_concat / 0
  prog->add_entry_point(atom(175), 310);  // test_atom_concat_1 / 0
  prog->add_entry_point(atom(179), 315);  // test_atom_concat_2 / 0
  prog->add_entry_point(atom(183), 319);  // test_atom_concat_3 / 0
  prog->add_entry_point(atom(185), 323);  // test_atom_chars / 0
  prog->add_entry_point(atom(186), 325);  // test_atom_chars1 / 0
  prog->add_entry_point(atom(189), 329);  // test_atom_chars2 / 0
  prog->add_entry_point(atom(204), 333);  // test_atom_codes / 0
  prog->add_entry_point(atom(205), 335);  // test_atom_codes1 / 0
  prog->add_entry_point(atom(206), 339);  // test_atom_codes2 / 0
  prog->add_entry_point(atom(207), 343);  // test_append / 0
  prog->add_entry_point(atom(208), 346);  // test_append1 / 0
  prog->add_entry_point(atom(211), 353);  // test_append2 / 0
  prog->add_entry_point(atom(213), 360);  // test_append3 / 0
  prog->add_entry_point(atom(216), 367);  // test_reverse / 0
  prog->add_entry_point(atom(217), 369);  // test_nth0 / 0
  prog->add_entry_point(atom(218), 371);  // test_nth0_ / 0
  prog->add_entry_point(atom(225), 390);  // test_nth0_rev_ / 0
  prog->add_entry_point(atom(233), 414);  // test_nth1 / 0
  prog->add_entry_point(atom(234), 416);  // test_nth1_ / 0
  prog->add_entry_point(atom(236), 432);  // test_nth1_rev_ / 0
  prog->add_entry_point(atom(237), 452);  // test_splice_suspension / 0
  prog->add_entry_point(atom(239), 457);  // test_splice_suspension1 / 1
  prog->add_entry_point(atom(240), 458);  // test_calc / 0
  prog->add_entry_point(atom(245), 467);  // do_test / 1
  prog->add_entry_point(atom(247), 470);  // main / 1
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
