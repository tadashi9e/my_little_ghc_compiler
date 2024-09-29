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
Q atom(88);  // =\= / 2
Q atom(89);  // __not_equal__ / 2
Q atom(90);  // := / 2
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
Q atom(126);  // test_call3 / 2
Q atom(127);  // test_call3_aux / 1
Q atom(128);  // a / 0
Q atom(129);  // b / 0
Q atom(130);  // c / 0
Q atom(131);  // test_call3_aux / 0
Q atom(132);  // test_call3_aux / 3
Q atom(133);  // test_call3_aux / 2
Q atom(134);  // done / 0
Q atom(135);  // test_otherwise / 2
Q atom(136);  // test_otherwise_aux / 3
Q atom(137);  // test failed / 0
Q atom(138);  // test success / 0
Q atom(139);  // test_write_var / 2
Q atom(140);  // test_write_atom / 2
Q atom(141);  // atom / 0
Q atom(142);  // test_write_list / 2
Q atom(143);  // test_write_structure / 2
Q atom(144);  // some / 3
Q atom(145);  // structure / 0
Q atom(146);  // and / 0
Q atom(147);  // arguments / 0
Q atom(148);  // test_get_structure / 2
Q atom(149);  // test_set_structure / 2
Q atom(150);  // test_get_list / 2
Q atom(151);  // test_set_list / 2
Q atom(152);  // test_check_constant / 2
Q atom(153);  // test_check_constant_aux / 3
Q atom(154);  // test failed(0) / 0
Q atom(155);  // test success(1) / 0
Q atom(156);  // test failed(otherwise) / 0
Q atom(157);  // test_check_list / 2
Q atom(158);  // test_check_list_aux / 3
Q atom(159);  // x / 0
Q atom(160);  // y / 0
Q atom(161);  // test failed([x,y]) / 0
Q atom(162);  // test success([a,b]) / 0
Q atom(163);  // test_check_nil / 2
Q atom(164);  // test_check_nil_aux / 3
Q atom(165);  // test failed([a,b]) / 0
Q atom(166);  // test success([]) / 0
Q atom(167);  // test_check_structure / 2
Q atom(168);  // fun / 2
Q atom(169);  // test_check_structure_aux / 3
Q atom(170);  // test failed(fun(x,y)) / 0
Q atom(171);  // test success(fun(a,b)) / 0
Q atom(172);  // test_wait_var / 2
Q atom(173);  // wait_var / 3
Q atom(174);  // write_var / 1
Q atom(175);  // fire / 0
Q atom(176);  // test_atom_concat / 2
Q atom(177);  // test_atom_concat_1 / 2
Q atom(178);  // test_atom_concat_2 / 2
Q atom(179);  // abc / 0
Q atom(180);  // def / 0
Q atom(181);  // abc + def =  / 0
Q atom(182);  // abcdef / 0
Q atom(183);  // abc + [ / 0
Q atom(184);  // ] = abcdef / 0
Q atom(185);  // test_atom_concat_3 / 2
Q atom(186);  // ] + def = abcdef / 0
Q atom(187);  // test_atom_chars / 2
Q atom(188);  // test_atom_chars1 / 2
Q atom(189);  // abcdefgあいうえお漢字☺🍺 / 0
Q atom(190);  //  ->  / 0
Q atom(191);  // test_atom_chars2 / 2
Q atom(192);  // d / 0
Q atom(193);  // e / 0
Q atom(194);  // f / 0
Q atom(195);  // g / 0
Q atom(196);  // あ / 0
Q atom(197);  // い / 0
Q atom(198);  // う / 0
Q atom(199);  // え / 0
Q atom(200);  // お / 0
Q atom(201);  // 漢 / 0
Q atom(202);  // 字 / 0
Q atom(203);  // ☺ / 0
Q atom(204);  // 🍺 / 0
Q atom(205);  //  <-  / 0
Q atom(206);  // test_atom_codes / 2
Q atom(207);  // test_atom_codes1 / 2
Q atom(208);  // test_atom_codes2 / 2
Q atom(209);  // test_append / 2
Q atom(210);  // test_append1 / 2
Q atom(211);  // test_append2 / 2
Q atom(212);  // + / 0
Q atom(213);  // =[ / 0
Q atom(214);  // ]= / 0
Q atom(215);  // test_append3 / 2
Q atom(216);  // ]+ / 0
Q atom(217);  // = / 0
Q atom(218);  // test_reverse / 2
Q atom(219);  // test_nth0 / 2
Q atom(220);  // test_nth0_ / 2
Q atom(221);  //  0: [ / 0
Q atom(222);  // ] 1: [ / 0
Q atom(223);  // ] 2: [ / 0
Q atom(224);  // ] 3: [ / 0
Q atom(225);  // ] 4: [ / 0
Q atom(226);  // ] 5: [ / 0
Q atom(227);  // test_nth0_rev_ / 2
Q atom(228);  //  [ / 0
Q atom(229);  // ]: a / 0
Q atom(230);  // ]: b / 0
Q atom(231);  // ]: c / 0
Q atom(232);  // ]: d / 0
Q atom(233);  // ]: e / 0
Q atom(234);  // ]: f / 0
Q atom(235);  // test_nth1 / 2
Q atom(236);  // test_nth1_ / 2
Q atom(237);  //  1: [ / 0
Q atom(238);  // test_nth1_rev_ / 2
Q atom(239);  // test_splice_suspension / 2
Q atom(240);  // test_splice_suspension1 / 3
Q atom(241);  // dump/splice.dot / 0
Q atom(242);  // test_splice_suspension / 0
Q atom(243);  // test_calc / 2
Q atom(244);  // test_calc_report / 4
Q atom(245);  // dump/calc.dot / 0
Q atom(246);  // do_test / 3
Q atom(247);  // :  / 0
Q atom(248);  // main / 1
Q atom(249);  // do_test / 1
Q atom(250);  // test_call3 / 0
Q atom(251);  // test_otherwise / 0
Q atom(252);  // test_write_var / 0
Q atom(253);  // test_write_atom / 0
Q atom(254);  // test_write_list / 0
Q atom(255);  // test_write_structure / 0
Q atom(256);  // test_get_structure / 0
Q atom(257);  // test_set_structure / 0
Q atom(258);  // test_get_list / 0
Q atom(259);  // test_set_list / 0
Q atom(260);  // test_check_constant / 0
Q atom(261);  // test_check_list / 0
Q atom(262);  // test_check_nil / 0
Q atom(263);  // test_check_structure / 0
Q atom(264);  // test_wait_var / 0
Q atom(265);  // test_atom_concat / 0
Q atom(266);  // test_atom_chars / 0
Q atom(267);  // test_atom_codes / 0
Q atom(268);  // test_append / 0
Q atom(269);  // test_reverse / 0
Q atom(270);  // test_nth0 / 0
Q atom(271);  // test_nth1 / 0
Q atom(272);  // test_calc / 0
Q atom(273);  // total_inferences= / 0
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
      MACRO_spawn(219,77,atom(43));  // spawn(__inc__/2)
    case 77:  // return_from_spawn(__inc__/2)
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
      MACRO_spawn(179,79,atom(45));  // spawn(__add__/3)
    case 79:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,81,atom(45));  // spawn(__add__/3)
    case 81:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,83,atom(45));  // spawn(__add__/3)
    case 83:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,85,atom(45));  // spawn(__add__/3)
    case 85:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,87,atom(45));  // spawn(__add__/3)
    case 87:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,89,atom(45));  // spawn(__add__/3)
    case 89:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,91,atom(45));  // spawn(__add__/3)
    case 91:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,93,atom(45));  // spawn(__add__/3)
    case 93:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,95,atom(45));  // spawn(__add__/3)
    case 95:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,97,atom(45));  // spawn(__add__/3)
    case 97:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,99,atom(45));  // spawn(__add__/3)
    case 99:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,101,atom(45));  // spawn(__add__/3)
    case 101:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(179,103,atom(45));  // spawn(__add__/3)
    case 103:  // return_from_spawn(__add__/3)
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
      MACRO_spawn(219,105,atom(43));  // spawn(__inc__/2)
    case 105:  // return_from_spawn(__inc__/2)
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
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(163,2);  // execute((==)/2)
    case 169:  // (=\=)/2
      MACRO_goal(169,atom(88));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(170,2);  // execute(__not_equal__/2)
    case 170:  // __not_equal__/2
      MACRO_goal(170,atom(89));
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
    case 171:  // (:=)/2
      MACRO_goal(171,atom(90));
      MACRO_requires(8);
      MACRO_try_guard_else(173);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,172,atom(21));  // call(integer/1)
    case 172:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
    case 173:  // (:=)/2-2
      MACRO_try_guard_else(174);
      MACRO_check_structure(atom(91),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(179,3);  // execute(__add__/3)
    case 174:  // (:=)/2-3
      MACRO_try_guard_else(175);
      MACRO_check_structure(atom(92),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(185,3);  // execute(__sub__/3)
    case 175:  // (:=)/2-4
      MACRO_try_guard_else(176);
      MACRO_check_structure(atom(93),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(191,3);  // execute(__mul__/3)
    case 176:  // (:=)/2-5
      MACRO_try_guard_else(177);
      MACRO_check_structure(atom(94),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(197,3);  // execute(__div__/3)
    case 177:  // (:=)/2-6
      MACRO_try_guard_else(178);
      MACRO_check_structure(atom(95),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(203,3);  // execute(__mod__/3)
    case 178:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_structure(atom(96),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(2,5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(209,2);  // execute(__neg__/2)
    case 179:  // __add__/3
      MACRO_goal(179,atom(45));
      MACRO_requires(9);
      MACRO_try_guard_else(182);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,180,atom(21));  // call(integer/1)
    case 180:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,181,atom(21));  // call(integer/1)
    case 181:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__iadd__/3)
    case 182:  // __add__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,183,atom(90));  // call((:=)/2)
    case 183:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(171,184,atom(90));  // call((:=)/2)
    case 184:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(214,3);  // execute(__iadd__/3)
    case 185:  // __sub__/3
      MACRO_goal(185,atom(97));
      MACRO_requires(9);
      MACRO_try_guard_else(188);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,186,atom(21));  // call(integer/1)
    case 186:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,187,atom(21));  // call(integer/1)
    case 187:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__isub__/3)
    case 188:  // __sub__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,189,atom(90));  // call((:=)/2)
    case 189:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(171,190,atom(90));  // call((:=)/2)
    case 190:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(215,3);  // execute(__isub__/3)
    case 191:  // __mul__/3
      MACRO_goal(191,atom(98));
      MACRO_requires(9);
      MACRO_try_guard_else(194);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,192,atom(21));  // call(integer/1)
    case 192:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,193,atom(21));  // call(integer/1)
    case 193:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(216,3);  // execute(__imul__/3)
    case 194:  // __mul__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,195,atom(90));  // call((:=)/2)
    case 195:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(171,196,atom(90));  // call((:=)/2)
    case 196:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(216,3);  // execute(__imul__/3)
    case 197:  // __div__/3
      MACRO_goal(197,atom(99));
      MACRO_requires(9);
      MACRO_try_guard_else(200);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,198,atom(21));  // call(integer/1)
    case 198:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,199,atom(21));  // call(integer/1)
    case 199:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(217,3);  // execute(__idiv__/3)
    case 200:  // __div__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,201,atom(90));  // call((:=)/2)
    case 201:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(171,202,atom(90));  // call((:=)/2)
    case 202:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(217,3);  // execute(__idiv__/3)
    case 203:  // __mod__/3
      MACRO_goal(203,atom(100));
      MACRO_requires(9);
      MACRO_try_guard_else(206);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,204,atom(21));  // call(integer/1)
    case 204:  // return_from_call(integer/1)
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(158,205,atom(21));  // call(integer/1)
    case 205:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(218,3);  // execute(__imod__/3)
    case 206:  // __mod__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,207,atom(90));  // call((:=)/2)
    case 207:  // return_from_call((:=)/2)
      MACRO_seq(2,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(171,208,atom(90));  // call((:=)/2)
    case 208:  // return_from_call((:=)/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(218,3);  // execute(__imod__/3)
    case 209:  // __neg__/2
      MACRO_goal(209,atom(101));
      MACRO_requires(6);
      MACRO_try_guard_else(211);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,210,atom(21));  // call(integer/1)
    case 210:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(213,2);  // execute(__ineg__/2)
    case 211:  // __neg__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,212,atom(90));  // call((:=)/2)
    case 212:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(213,2);  // execute(__ineg__/2)
    case 213:  // __ineg__/2
      MACRO_goal(213,atom(102));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 214:  // __iadd__/3
      MACRO_goal(214,atom(103));
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
    case 215:  // __isub__/3
      MACRO_goal(215,atom(104));
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
    case 216:  // __imul__/3
      MACRO_goal(216,atom(105));
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
    case 217:  // __idiv__/3
      MACRO_goal(217,atom(106));
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
    case 218:  // __imod__/3
      MACRO_goal(218,atom(107));
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
    case 219:  // __inc__/2
      MACRO_goal(219,atom(43));
      MACRO_requires(6);
      MACRO_try_guard_else(221);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(158,220,atom(21));  // call(integer/1)
    case 220:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(227,2);  // execute(__iinc__/2)
    case 221:  // __inc__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,222,atom(90));  // call((:=)/2)
    case 222:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(227,2);  // execute(__iinc__/2)
    case 223:  // __dec__/2
      MACRO_goal(223,atom(108));
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
      MACRO_execute(228,2);  // execute(__idec__/2)
    case 225:  // __dec__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(2,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_call(171,226,atom(90));  // call((:=)/2)
    case 226:  // return_from_call((:=)/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(228,2);  // execute(__idec__/2)
    case 227:  // __iinc__/2
      MACRO_goal(227,atom(109));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 228:  // __idec__/2
      MACRO_goal(228,atom(110));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 229:  // append/3
      MACRO_goal(229,atom(111));
      MACRO_requires(10);
      MACRO_try_guard_else(230);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 230:  // append/3-2
      MACRO_try_guard_else(231);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 231:  // append/3-3
      MACRO_try_guard_else(232);
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
      MACRO_execute(229,3);  // execute(append/3)
    case 232:  // append/3-4
      MACRO_try_guard_else(233);
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
      MACRO_execute(229,3);  // execute(append/3)
    case 233:  // append/3-5
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
      MACRO_call(237,234,atom(112));  // call(reverse/2)
    case 234:  // return_from_call(reverse/2)
      MACRO_seq(2,6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::y(5),reg::out(2));
      MACRO_call(237,235,atom(112));  // call(reverse/2)
    case 235:  // return_from_call(reverse/2)
      MACRO_seq(3,7);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_variable(reg::y(6),reg::out(2));
      MACRO_out_value(reg::y(5),reg::out(3));
      MACRO_call(229,236,atom(111));  // call(append/3)
    case 236:  // return_from_call(append/3)
      MACRO_tail(2,7);
      MACRO_out_value(reg::y(6),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(237,2);  // execute(reverse/2)
    case 237:  // reverse/2
      MACRO_goal(237,atom(112));
      MACRO_requires(7);
      MACRO_try_guard_else(239);
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(160,238,atom(65));  // call(var/1)
    case 238:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(241,3);  // execute(__reverse__/3)
    case 239:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,240,atom(65));  // call(var/1)
    case 240:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(241,3);  // execute(__reverse__/3)
    case 241:  // __reverse__/3
      MACRO_goal(241,atom(113));
      MACRO_requires(10);
      MACRO_try_guard_else(242);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 242:  // __reverse__/3-2
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
      MACRO_execute(241,3);  // execute(__reverse__/3)
    case 243:  // nth0/3
      MACRO_goal(243,atom(114));
      MACRO_requires(9);
      MACRO_try_guard_else(245);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(160,244,atom(65));  // call(var/1)
    case 244:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(247,3);  // execute(__nth0__/3)
    case 245:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,246,atom(65));  // call(var/1)
    case 246:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(250,4);  // execute(__nth0_rev__/4)
    case 247:  // __nth0__/3
      MACRO_goal(247,atom(115));
      MACRO_requires(9);
      MACRO_try_guard_else(248);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 248:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(2,6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_spawn(223,249,atom(108));  // spawn(__dec__/2)
    case 249:  // return_from_spawn(__dec__/2)
      MACRO_tail(3,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(247,3);  // execute(__nth0__/3)
    case 250:  // __nth0_rev__/4
      MACRO_goal(250,atom(116));
      MACRO_requires(11);
      MACRO_try_guard_else(251);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 251:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(2,7);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::y(5),reg::out(2));
      MACRO_spawn(219,252,atom(43));  // spawn(__inc__/2)
    case 252:  // return_from_spawn(__inc__/2)
      MACRO_tail(4,7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(6),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::y(5),reg::out(4));
      MACRO_execute(250,4);  // execute(__nth0_rev__/4)
    case 253:  // nth1/3
      MACRO_goal(253,atom(117));
      MACRO_requires(10);
      MACRO_try_guard_else(256);
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(160,254,atom(65));  // call(var/1)
    case 254:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(2,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_spawn(223,255,atom(108));  // spawn(__dec__/2)
    case 255:  // return_from_spawn(__dec__/2)
      MACRO_tail(3,5);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(247,3);  // execute(__nth0__/3)
    case 256:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(160,257,atom(65));  // call(var/1)
    case 257:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(4,6);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(250,258,atom(116));  // spawn(__nth0_rev__/4)
    case 258:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(2,6);
      MACRO_out_value(reg::y(5),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(219,2);  // execute(__inc__/2)
    case 259:  // inference_count/1
      MACRO_goal(259,atom(118));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(260,1);  // execute(__inference_count__/1)
    case 260:  // __inference_count__/1
      MACRO_goal(260,atom(119));
      MACRO_requires(2);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 261:  // resume_count/1
      MACRO_goal(261,atom(120));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(262,1);  // execute(__resume_count__/1)
    case 262:  // __resume_count__/1
      MACRO_goal(262,atom(121));
      MACRO_requires(2);
  MACRO_activate;
  if (!vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1])) {
    MACRO_fail;
  }
  MACRO_proceed;
    case 263:  // dump_to_dot/1
      MACRO_goal(263,atom(122));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,264,atom(13));  // call(atom/1)
    case 264:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(1,3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(265,1);  // execute(__dump_to_dot__/1)
    case 265:  // __dump_to_dot__/1
      MACRO_goal(265,atom(123));
      MACRO_requires(2);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  }
  MACRO_proceed;
    case 266:  // dump_to_dot/2
      MACRO_goal(266,atom(124));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_seq(1,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(159,267,atom(13));  // call(atom/1)
    case 267:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(268,2);  // execute(__dump_to_dot__/2)
    case 268:  // __dump_to_dot__/2
      MACRO_goal(268,atom(125));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  }
  MACRO_proceed;
    case 269:  // test_call3/2
      MACRO_goal(269,atom(126));
      MACRO_requires(10);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,5);
      MACRO_out_structure(atom(127),reg::out(1));
      MACRO_write_constant(atom(128));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(6,270,atom(5));  // spawn(call/3)
    case 270:  // return_from_spawn(call/3)
      MACRO_par(3,6);
      MACRO_out_structure(atom(127),reg::out(1));
      MACRO_write_constant(atom(129));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_out_variable(reg::y(5),reg::out(3));
      MACRO_spawn(6,271,atom(5));  // spawn(call/3)
    case 271:  // return_from_spawn(call/3)
      MACRO_par(3,7);
      MACRO_out_structure(atom(127),reg::out(1));
      MACRO_write_constant(atom(130));
      MACRO_out_value(reg::y(5),reg::out(2));
      MACRO_out_variable(reg::y(6),reg::out(3));
      MACRO_spawn(6,272,atom(5));  // spawn(call/3)
    case 272:  // return_from_spawn(call/3)
      MACRO_par(3,7);
      MACRO_out_constant(atom(131),reg::out(1));
      MACRO_out_value(reg::y(6),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_spawn(6,273,atom(5));  // spawn(call/3)
    case 273:  // return_from_spawn(call/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 274:  // test_call3_aux/3
      MACRO_goal(274,atom(132));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_value(reg::in(1));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 275:  // test_call3_aux/2
      MACRO_goal(275,atom(133));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_constant(atom(134));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 276:  // test_otherwise/2
      MACRO_goal(276,atom(135));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_spawn(278,277,atom(136));  // spawn(test_otherwise_aux/3)
    case 277:  // return_from_spawn(test_otherwise_aux/3)
      MACRO_get_constant(tagvalue<TAG_INT>(1),reg::y(3));
      MACRO_proceed;
    case 278:  // test_otherwise_aux/3
      MACRO_goal(278,atom(136));
      MACRO_requires(4);
      MACRO_try_guard_else(279);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(137));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 279:  // test_otherwise_aux/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(138));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 280:  // test_write_var/2
      MACRO_goal(280,atom(139));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_variable(reg::x(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 281:  // test_write_atom/2
      MACRO_goal(281,atom(140));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(141));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 282:  // test_write_list/2
      MACRO_goal(282,atom(142));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(3));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(4));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(5));
      MACRO_unify_void;
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 283:  // test_write_structure/2
      MACRO_goal(283,atom(143));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_structure(atom(144));
      MACRO_unify_constant(atom(145));
      MACRO_unify_constant(atom(146));
      MACRO_unify_constant(atom(147));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 284:  // test_get_structure/2
      MACRO_goal(284,atom(148));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(3));
      MACRO_get_structure(atom(91),reg::x(3));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 285:  // test_set_structure/2
      MACRO_goal(285,atom(149));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_structure(atom(91),reg::x(4));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_get_variable(reg::x(3),reg::x(4));
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 286:  // test_get_list/2
      MACRO_goal(286,atom(150));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(3));
      MACRO_get_list(reg::x(3));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_unify_list;
      MACRO_unify_constant(tagvalue<TAG_INT>(3));
      MACRO_unify_nil;
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 287:  // test_set_list/2
      MACRO_goal(287,atom(151));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_list(reg::x(3));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_write_list;
      MACRO_write_constant(tagvalue<TAG_INT>(3));
      MACRO_write_nil;
      MACRO_get_variable(reg::x(4),reg::x(3));
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 288:  // test_check_constant/2
      MACRO_goal(288,atom(152));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_execute(289,3);  // execute(test_check_constant_aux/3)
    case 289:  // test_check_constant_aux/3
      MACRO_goal(289,atom(153));
      MACRO_requires(4);
      MACRO_try_guard_else(290);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(154));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 290:  // test_check_constant_aux/3-2
      MACRO_try_guard_else(291);
      MACRO_check_constant(tagvalue<TAG_INT>(1),reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(155));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 291:  // test_check_constant_aux/3-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(156));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 292:  // test_check_list/2
      MACRO_goal(292,atom(157));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_list(reg::out(1));
      MACRO_write_constant(atom(128));
      MACRO_write_list;
      MACRO_write_constant(atom(129));
      MACRO_write_nil;
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_execute(293,3);  // execute(test_check_list_aux/3)
    case 293:  // test_check_list_aux/3
      MACRO_goal(293,atom(158));
      MACRO_requires(4);
      MACRO_try_guard_else(294);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(159));
      MACRO_read_list;
      MACRO_read_constant(atom(160));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(161));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 294:  // test_check_list_aux/3-2
      MACRO_try_guard_else(295);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(128));
      MACRO_read_list;
      MACRO_read_constant(atom(129));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(162));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 295:  // test_check_list_aux/3-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(156));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 296:  // test_check_nil/2
      MACRO_goal(296,atom(163));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_nil(reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_execute(297,3);  // execute(test_check_nil_aux/3)
    case 297:  // test_check_nil_aux/3
      MACRO_goal(297,atom(164));
      MACRO_requires(4);
      MACRO_try_guard_else(298);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(128));
      MACRO_read_list;
      MACRO_read_constant(atom(129));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(165));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 298:  // test_check_nil_aux/3-2
      MACRO_try_guard_else(299);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(166));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 299:  // test_check_nil_aux/3-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(156));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 300:  // test_check_structure/2
      MACRO_goal(300,atom(167));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3,4);
      MACRO_out_structure(atom(168),reg::out(1));
      MACRO_write_constant(atom(128));
      MACRO_write_constant(atom(129));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_execute(301,3);  // execute(test_check_structure_aux/3)
    case 301:  // test_check_structure_aux/3
      MACRO_goal(301,atom(169));
      MACRO_requires(4);
      MACRO_try_guard_else(302);
      MACRO_check_structure(atom(168),reg::in(1));
      MACRO_read_constant(atom(159));
      MACRO_read_constant(atom(160));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(170));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 302:  // test_check_structure_aux/3-2
      MACRO_try_guard_else(303);
      MACRO_check_structure(atom(168),reg::in(1));
      MACRO_read_constant(atom(128));
      MACRO_read_constant(atom(129));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(171));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 303:  // test_check_structure_aux/3-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(156));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 304:  // test_wait_var/2
      MACRO_goal(304,atom(172));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_spawn(306,305,atom(173));  // spawn(wait_var/3)
    case 305:  // return_from_spawn(wait_var/3)
      MACRO_tail(1,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_execute(307,1);  // execute(write_var/1)
    case 306:  // wait_var/3
      MACRO_goal(306,atom(173));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::in(1));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 307:  // write_var/1
      MACRO_goal(307,atom(174));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_constant(atom(175),reg::in(1));
      MACRO_proceed;
    case 308:  // test_atom_concat/2
      MACRO_goal(308,atom(176));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(311,309,atom(177));  // spawn(test_atom_concat_1/2)
    case 309:  // return_from_spawn(test_atom_concat_1/2)
      MACRO_par(2,5);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_spawn(313,310,atom(178));  // spawn(test_atom_concat_2/2)
    case 310:  // return_from_spawn(test_atom_concat_2/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(315,2);  // execute(test_atom_concat_3/2)
    case 311:  // test_atom_concat_1/2
      MACRO_goal(311,atom(177));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3,4);
      MACRO_out_constant(atom(179),reg::out(1));
      MACRO_out_constant(atom(180),reg::out(2));
      MACRO_out_variable(reg::y(3),reg::out(3));
      MACRO_call(18,312,atom(12));  // call(atom_concat/3)
    case 312:  // return_from_call(atom_concat/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(67));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(69));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 313:  // test_atom_concat_2/2
      MACRO_goal(313,atom(178));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3,4);
      MACRO_out_constant(atom(179),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_out_constant(atom(182),reg::out(3));
      MACRO_call(18,314,atom(12));  // call(atom_concat/3)
    case 314:  // return_from_call(atom_concat/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(184));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 315:  // test_atom_concat_3/2
      MACRO_goal(315,atom(185));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3,4);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_constant(atom(180),reg::out(2));
      MACRO_out_constant(atom(182),reg::out(3));
      MACRO_call(18,316,atom(12));  // call(atom_concat/3)
    case 316:  // return_from_call(atom_concat/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(67));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(186));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 317:  // test_atom_chars/2
      MACRO_goal(317,atom(187));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(319,318,atom(188));  // spawn(test_atom_chars1/2)
    case 318:  // return_from_spawn(test_atom_chars1/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(321,2);  // execute(test_atom_chars2/2)
    case 319:  // test_atom_chars1/2
      MACRO_goal(319,atom(188));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_constant(atom(189),reg::x(4));
      MACRO_seq(2,5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_call(40,320,atom(23));  // call(atom_chars/2)
    case 320:  // return_from_call(atom_chars/2)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 321:  // test_atom_chars2/2
      MACRO_goal(321,atom(191));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_list(reg::x(4));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(40,322,atom(23));  // call(atom_chars/2)
    case 322:  // return_from_call(atom_chars/2)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(205));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 323:  // test_atom_codes/2
      MACRO_goal(323,atom(206));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(325,324,atom(207));  // spawn(test_atom_codes1/2)
    case 324:  // return_from_spawn(test_atom_codes1/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(327,2);  // execute(test_atom_codes2/2)
    case 325:  // test_atom_codes1/2
      MACRO_goal(325,atom(207));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_constant(atom(189),reg::x(4));
      MACRO_seq(2,5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_call(30,326,atom(17));  // call(atom_codes/2)
    case 326:  // return_from_call(atom_codes/2)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 327:  // test_atom_codes2/2
      MACRO_goal(327,atom(208));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_list(reg::x(4));
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
      MACRO_seq(2,5);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(30,328,atom(17));  // call(atom_codes/2)
    case 328:  // return_from_call(atom_codes/2)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(205));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 329:  // test_append/2
      MACRO_goal(329,atom(209));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(332,330,atom(210));  // spawn(test_append1/2)
    case 330:  // return_from_spawn(test_append1/2)
      MACRO_par(2,5);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_variable(reg::y(4),reg::out(2));
      MACRO_spawn(334,331,atom(211));  // spawn(test_append2/2)
    case 331:  // return_from_spawn(test_append2/2)
      MACRO_tail(2,5);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(336,2);  // execute(test_append3/2)
    case 332:  // test_append1/2
      MACRO_goal(332,atom(210));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_list(reg::x(4));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(5));
      MACRO_get_list(reg::x(5));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::y(3),reg::out(3));
      MACRO_call(229,333,atom(111));  // call(append/3)
    case 333:  // return_from_call(append/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(212));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(5));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(213));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(69));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 334:  // test_append2/2
      MACRO_goal(334,atom(211));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_list(reg::x(4));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_list;
      MACRO_unify_constant(atom(194));
      MACRO_unify_list;
      MACRO_unify_constant(atom(195));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(5));
      MACRO_get_list(reg::x(5));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_call(229,335,atom(111));  // call(append/3)
    case 335:  // return_from_call(append/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(212));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(67));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(214));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(5));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 336:  // test_append3/2
      MACRO_goal(336,atom(215));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(4));
      MACRO_get_list(reg::x(4));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(5));
      MACRO_get_list(reg::x(5));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,6);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_call(229,337,atom(111));  // call(append/3)
    case 337:  // return_from_call(append/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(67));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(216));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::x(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(217));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::x(5));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 338:  // test_reverse/2
      MACRO_goal(338,atom(218));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(3));
      MACRO_get_list(reg::x(3));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(2,4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_call(237,339,atom(112));  // call(reverse/2)
    case 339:  // return_from_call(reverse/2)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 340:  // test_nth0/2
      MACRO_goal(340,atom(219));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(342,341,atom(220));  // spawn(test_nth0_/2)
    case 341:  // return_from_spawn(test_nth0_/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(349,2);  // execute(test_nth0_rev_/2)
    case 342:  // test_nth0_/2
      MACRO_goal(342,atom(220));
      MACRO_requires(12);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(8));
      MACRO_get_list(reg::x(8));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(3),reg::out(3));
      MACRO_call(243,343,atom(114));  // call(nth0/3)
    case 343:  // return_from_call(nth0/3)
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_call(243,344,atom(114));  // call(nth0/3)
    case 344:  // return_from_call(nth0/3)
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(5),reg::out(3));
      MACRO_call(243,345,atom(114));  // call(nth0/3)
    case 345:  // return_from_call(nth0/3)
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(6),reg::out(3));
      MACRO_call(243,346,atom(114));  // call(nth0/3)
    case 346:  // return_from_call(nth0/3)
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(7),reg::out(3));
      MACRO_call(243,347,atom(114));  // call(nth0/3)
    case 347:  // return_from_call(nth0/3)
      MACRO_seq(3,9);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_variable(reg::y(8),reg::out(3));
      MACRO_call(243,348,atom(114));  // call(nth0/3)
    case 348:  // return_from_call(nth0/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(221));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(222));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(223));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(5));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(224));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(6));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(225));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(7));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(226));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(8));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(69));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 349:  // test_nth0_rev_/2
      MACRO_goal(349,atom(227));
      MACRO_requires(13);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(9));
      MACRO_get_list(reg::x(9));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(128),reg::out(3));
      MACRO_call(243,350,atom(114));  // call(nth0/3)
    case 350:  // return_from_call(nth0/3)
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(129),reg::out(3));
      MACRO_call(243,351,atom(114));  // call(nth0/3)
    case 351:  // return_from_call(nth0/3)
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(130),reg::out(3));
      MACRO_call(243,352,atom(114));  // call(nth0/3)
    case 352:  // return_from_call(nth0/3)
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(6),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(192),reg::out(3));
      MACRO_call(243,353,atom(114));  // call(nth0/3)
    case 353:  // return_from_call(nth0/3)
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(7),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(193),reg::out(3));
      MACRO_call(243,354,atom(114));  // call(nth0/3)
    case 354:  // return_from_call(nth0/3)
      MACRO_seq(3,10);
      MACRO_out_variable(reg::y(8),reg::out(1));
      MACRO_out_value(reg::x(9),reg::out(2));
      MACRO_out_constant(atom(194),reg::out(3));
      MACRO_call(243,355,atom(114));  // call(nth0/3)
    case 355:  // return_from_call(nth0/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(229));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(230));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(5));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(231));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(6));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(232));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(7));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(233));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(8));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(234));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 356:  // test_nth1/2
      MACRO_goal(356,atom(235));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2,4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::y(3),reg::out(2));
      MACRO_spawn(358,357,atom(236));  // spawn(test_nth1_/2)
    case 357:  // return_from_spawn(test_nth1_/2)
      MACRO_tail(2,4);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(364,2);  // execute(test_nth1_rev_/2)
    case 358:  // test_nth1_/2
      MACRO_goal(358,atom(236));
      MACRO_requires(11);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(7));
      MACRO_get_list(reg::x(7));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,8);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(7),reg::out(2));
      MACRO_out_variable(reg::y(3),reg::out(3));
      MACRO_call(253,359,atom(117));  // call(nth1/3)
    case 359:  // return_from_call(nth1/3)
      MACRO_seq(3,8);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(7),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_call(253,360,atom(117));  // call(nth1/3)
    case 360:  // return_from_call(nth1/3)
      MACRO_seq(3,8);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(7),reg::out(2));
      MACRO_out_variable(reg::y(5),reg::out(3));
      MACRO_call(253,361,atom(117));  // call(nth1/3)
    case 361:  // return_from_call(nth1/3)
      MACRO_seq(3,8);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(7),reg::out(2));
      MACRO_out_variable(reg::y(6),reg::out(3));
      MACRO_call(253,362,atom(117));  // call(nth1/3)
    case 362:  // return_from_call(nth1/3)
      MACRO_seq(3,8);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(7),reg::out(2));
      MACRO_out_variable(reg::y(7),reg::out(3));
      MACRO_call(253,363,atom(117));  // call(nth1/3)
    case 363:  // return_from_call(nth1/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(237));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(223));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(224));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(5));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(225));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(6));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(226));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(7));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(69));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 364:  // test_nth1_rev_/2
      MACRO_goal(364,atom(238));
      MACRO_requires(12);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(8));
      MACRO_get_list(reg::x(8));
      MACRO_unify_constant(atom(128));
      MACRO_unify_list;
      MACRO_unify_constant(atom(129));
      MACRO_unify_list;
      MACRO_unify_constant(atom(130));
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
      MACRO_unify_list;
      MACRO_unify_constant(atom(203));
      MACRO_unify_list;
      MACRO_unify_constant(atom(204));
      MACRO_unify_nil;
      MACRO_seq(3,9);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_constant(atom(128),reg::out(3));
      MACRO_call(253,365,atom(117));  // call(nth1/3)
    case 365:  // return_from_call(nth1/3)
      MACRO_seq(3,9);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_constant(atom(129),reg::out(3));
      MACRO_call(253,366,atom(117));  // call(nth1/3)
    case 366:  // return_from_call(nth1/3)
      MACRO_seq(3,9);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_constant(atom(130),reg::out(3));
      MACRO_call(253,367,atom(117));  // call(nth1/3)
    case 367:  // return_from_call(nth1/3)
      MACRO_seq(3,9);
      MACRO_out_variable(reg::y(6),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_constant(atom(192),reg::out(3));
      MACRO_call(253,368,atom(117));  // call(nth1/3)
    case 368:  // return_from_call(nth1/3)
      MACRO_seq(3,9);
      MACRO_out_variable(reg::y(7),reg::out(1));
      MACRO_out_value(reg::x(8),reg::out(2));
      MACRO_out_constant(atom(193),reg::out(3));
      MACRO_call(253,369,atom(117));  // call(nth1/3)
    case 369:  // return_from_call(nth1/3)
      MACRO_get_list(reg::in(1));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(3));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(229));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(4));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(230));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(5));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(231));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(6));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(232));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(228));
      MACRO_unify_list;
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::y(7));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(233));
      MACRO_unify_value(reg::in(2));
      MACRO_proceed;
    case 370:  // test_splice_suspension/2
      MACRO_goal(370,atom(239));
      MACRO_requires(11);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,5);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(375,371,atom(240));  // spawn(test_splice_suspension1/3)
    case 371:  // return_from_spawn(test_splice_suspension1/3)
      MACRO_par(3,7);
      MACRO_out_variable(reg::y(5),reg::out(1));
      MACRO_out_value(reg::y(4),reg::out(2));
      MACRO_out_variable(reg::y(6),reg::out(3));
      MACRO_spawn(375,372,atom(240));  // spawn(test_splice_suspension1/3)
    case 372:  // return_from_spawn(test_splice_suspension1/3)
      MACRO_par(3,8);
      MACRO_out_variable(reg::y(7),reg::out(1));
      MACRO_out_value(reg::y(6),reg::out(2));
      MACRO_out_value(reg::in(2),reg::out(3));
      MACRO_spawn(375,373,atom(240));  // spawn(test_splice_suspension1/3)
    case 373:  // return_from_spawn(test_splice_suspension1/3)
      MACRO_get_value(reg::y(5),reg::y(3));
      MACRO_get_value(reg::y(7),reg::y(5));
      MACRO_par(1,8);
      MACRO_out_constant(atom(241),reg::out(1));
      MACRO_spawn(263,374,atom(122));  // spawn(dump_to_dot/1)
    case 374:  // return_from_spawn(dump_to_dot/1)
      MACRO_get_constant(atom(242),reg::y(3));
      MACRO_proceed;
    case 375:  // test_splice_suspension1/3
      MACRO_goal(375,atom(240));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::in(1));
      MACRO_unify_value(reg::in(3));
      MACRO_proceed;
    case 376:  // test_calc/2
      MACRO_goal(376,atom(243));
      MACRO_requires(11);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(3,5);
      MACRO_out_variable(reg::y(3),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::y(4),reg::out(3));
      MACRO_spawn(185,377,atom(97));  // spawn(__sub__/3)
    case 377:  // return_from_spawn(__sub__/3)
      MACRO_par(4,6);
      MACRO_out_value(reg::y(4),reg::out(1));
      MACRO_out_structure(atom(35),reg::out(2));
      MACRO_write_structure(atom(90));
      MACRO_write_value(reg::y(4));
      MACRO_write_structure(atom(92));
      MACRO_write_value(reg::y(3));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_out_variable(reg::y(5),reg::out(4));
      MACRO_spawn(382,378,atom(244));  // spawn(test_calc_report/4)
    case 378:  // return_from_spawn(test_calc_report/4)
      MACRO_par(1,6);
      MACRO_out_constant(atom(245),reg::out(1));
      MACRO_spawn(263,379,atom(122));  // spawn(dump_to_dot/1)
    case 379:  // return_from_spawn(dump_to_dot/1)
      MACRO_par(3,7);
      MACRO_out_value(reg::y(3),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::y(6),reg::out(3));
      MACRO_spawn(179,380,atom(45));  // spawn(__add__/3)
    case 380:  // return_from_spawn(__add__/3)
      MACRO_par(4,7);
      MACRO_out_value(reg::y(6),reg::out(1));
      MACRO_out_structure(atom(35),reg::out(2));
      MACRO_write_structure(atom(90));
      MACRO_write_value(reg::y(6));
      MACRO_write_structure(atom(91));
      MACRO_write_value(reg::y(3));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_out_value(reg::y(5),reg::out(3));
      MACRO_out_value(reg::in(2),reg::out(4));
      MACRO_spawn(382,381,atom(244));  // spawn(test_calc_report/4)
    case 381:  // return_from_spawn(test_calc_report/4)
      MACRO_get_constant(tagvalue<TAG_INT>(10),reg::y(3));
      MACRO_proceed;
    case 382:  // test_calc_report/4
      MACRO_goal(382,atom(244));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_get_list(reg::in(3));
      MACRO_unify_value(reg::in(2));
      MACRO_unify_value(reg::in(4));
      MACRO_proceed;
    case 383:  // do_test/3
      MACRO_goal(383,atom(246));
      MACRO_requires(8);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_list(reg::in(2));
      MACRO_unify_structure(atom(33));
      MACRO_unify_value(reg::in(1));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_constant(atom(247));
      MACRO_unify_variable(reg::x(4));
      MACRO_tail(3,5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(6,3);  // execute(call/3)
    case 384:  // main/1
      MACRO_goal(384,atom(248));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(1,3);
      MACRO_out_variable(reg::y(2),reg::out(1));
      MACRO_call(54,385,atom(29));  // call(outstream/1)
    case 385:  // return_from_call(outstream/1)
      MACRO_seq(3,4);
      MACRO_out_structure(atom(3),reg::out(1));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(250));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(251));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(252));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(253));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(254));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(255));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(256));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(257));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(258));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(259));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(260));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(261));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(262));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(263));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(264));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(265));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(266));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(267));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(268));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(269));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(270));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(271));
      MACRO_write_structure(atom(3));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(242));
      MACRO_write_structure(atom(249));
      MACRO_write_constant(atom(272));
      MACRO_out_value(reg::y(2),reg::out(2));
      MACRO_out_variable(reg::y(3),reg::out(3));
      MACRO_call(6,386,atom(5));  // call(call/3)
    case 386:  // return_from_call(call/3)
      MACRO_seq(1,5);
      MACRO_out_variable(reg::y(4),reg::out(1));
      MACRO_call(259,387,atom(118));  // call(inference_count/1)
    case 387:  // return_from_call(inference_count/1)
      MACRO_get_list(reg::y(3));
      MACRO_unify_structure(atom(33));
      MACRO_unify_constant(atom(273));
      MACRO_unify_list;
      MACRO_unify_structure(atom(35));
      MACRO_unify_value(reg::y(4));
      MACRO_unify_nil;
      MACRO_proceed;
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
  atom(88) = to_atom("=\\=", 2);
  atom(89) = to_atom("__not_equal__", 2);
  atom(90) = to_atom(":=", 2);
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
  atom(126) = to_atom("test_call3", 2);
  atom(127) = to_atom("test_call3_aux", 1);
  atom(128) = to_atom("a", 0);
  atom(129) = to_atom("b", 0);
  atom(130) = to_atom("c", 0);
  atom(131) = to_atom("test_call3_aux", 0);
  atom(132) = to_atom("test_call3_aux", 3);
  atom(133) = to_atom("test_call3_aux", 2);
  atom(134) = to_atom("done", 0);
  atom(135) = to_atom("test_otherwise", 2);
  atom(136) = to_atom("test_otherwise_aux", 3);
  atom(137) = to_atom("test failed", 0);
  atom(138) = to_atom("test success", 0);
  atom(139) = to_atom("test_write_var", 2);
  atom(140) = to_atom("test_write_atom", 2);
  atom(141) = to_atom("atom", 0);
  atom(142) = to_atom("test_write_list", 2);
  atom(143) = to_atom("test_write_structure", 2);
  atom(144) = to_atom("some", 3);
  atom(145) = to_atom("structure", 0);
  atom(146) = to_atom("and", 0);
  atom(147) = to_atom("arguments", 0);
  atom(148) = to_atom("test_get_structure", 2);
  atom(149) = to_atom("test_set_structure", 2);
  atom(150) = to_atom("test_get_list", 2);
  atom(151) = to_atom("test_set_list", 2);
  atom(152) = to_atom("test_check_constant", 2);
  atom(153) = to_atom("test_check_constant_aux", 3);
  atom(154) = to_atom("test failed(0)", 0);
  atom(155) = to_atom("test success(1)", 0);
  atom(156) = to_atom("test failed(otherwise)", 0);
  atom(157) = to_atom("test_check_list", 2);
  atom(158) = to_atom("test_check_list_aux", 3);
  atom(159) = to_atom("x", 0);
  atom(160) = to_atom("y", 0);
  atom(161) = to_atom("test failed([x,y])", 0);
  atom(162) = to_atom("test success([a,b])", 0);
  atom(163) = to_atom("test_check_nil", 2);
  atom(164) = to_atom("test_check_nil_aux", 3);
  atom(165) = to_atom("test failed([a,b])", 0);
  atom(166) = to_atom("test success([])", 0);
  atom(167) = to_atom("test_check_structure", 2);
  atom(168) = to_atom("fun", 2);
  atom(169) = to_atom("test_check_structure_aux", 3);
  atom(170) = to_atom("test failed(fun(x,y))", 0);
  atom(171) = to_atom("test success(fun(a,b))", 0);
  atom(172) = to_atom("test_wait_var", 2);
  atom(173) = to_atom("wait_var", 3);
  atom(174) = to_atom("write_var", 1);
  atom(175) = to_atom("fire", 0);
  atom(176) = to_atom("test_atom_concat", 2);
  atom(177) = to_atom("test_atom_concat_1", 2);
  atom(178) = to_atom("test_atom_concat_2", 2);
  atom(179) = to_atom("abc", 0);
  atom(180) = to_atom("def", 0);
  atom(181) = to_atom("abc + def = ", 0);
  atom(182) = to_atom("abcdef", 0);
  atom(183) = to_atom("abc + [", 0);
  atom(184) = to_atom("] = abcdef", 0);
  atom(185) = to_atom("test_atom_concat_3", 2);
  atom(186) = to_atom("] + def = abcdef", 0);
  atom(187) = to_atom("test_atom_chars", 2);
  atom(188) = to_atom("test_atom_chars1", 2);
  atom(189) = to_atom("abcdefgあいうえお漢字☺🍺", 0);
  atom(190) = to_atom(" -> ", 0);
  atom(191) = to_atom("test_atom_chars2", 2);
  atom(192) = to_atom("d", 0);
  atom(193) = to_atom("e", 0);
  atom(194) = to_atom("f", 0);
  atom(195) = to_atom("g", 0);
  atom(196) = to_atom("あ", 0);
  atom(197) = to_atom("い", 0);
  atom(198) = to_atom("う", 0);
  atom(199) = to_atom("え", 0);
  atom(200) = to_atom("お", 0);
  atom(201) = to_atom("漢", 0);
  atom(202) = to_atom("字", 0);
  atom(203) = to_atom("☺", 0);
  atom(204) = to_atom("🍺", 0);
  atom(205) = to_atom(" <- ", 0);
  atom(206) = to_atom("test_atom_codes", 2);
  atom(207) = to_atom("test_atom_codes1", 2);
  atom(208) = to_atom("test_atom_codes2", 2);
  atom(209) = to_atom("test_append", 2);
  atom(210) = to_atom("test_append1", 2);
  atom(211) = to_atom("test_append2", 2);
  atom(212) = to_atom("+", 0);
  atom(213) = to_atom("=[", 0);
  atom(214) = to_atom("]=", 0);
  atom(215) = to_atom("test_append3", 2);
  atom(216) = to_atom("]+", 0);
  atom(217) = to_atom("=", 0);
  atom(218) = to_atom("test_reverse", 2);
  atom(219) = to_atom("test_nth0", 2);
  atom(220) = to_atom("test_nth0_", 2);
  atom(221) = to_atom(" 0: [", 0);
  atom(222) = to_atom("] 1: [", 0);
  atom(223) = to_atom("] 2: [", 0);
  atom(224) = to_atom("] 3: [", 0);
  atom(225) = to_atom("] 4: [", 0);
  atom(226) = to_atom("] 5: [", 0);
  atom(227) = to_atom("test_nth0_rev_", 2);
  atom(228) = to_atom(" [", 0);
  atom(229) = to_atom("]: a", 0);
  atom(230) = to_atom("]: b", 0);
  atom(231) = to_atom("]: c", 0);
  atom(232) = to_atom("]: d", 0);
  atom(233) = to_atom("]: e", 0);
  atom(234) = to_atom("]: f", 0);
  atom(235) = to_atom("test_nth1", 2);
  atom(236) = to_atom("test_nth1_", 2);
  atom(237) = to_atom(" 1: [", 0);
  atom(238) = to_atom("test_nth1_rev_", 2);
  atom(239) = to_atom("test_splice_suspension", 2);
  atom(240) = to_atom("test_splice_suspension1", 3);
  atom(241) = to_atom("dump/splice.dot", 0);
  atom(242) = to_atom("test_splice_suspension", 0);
  atom(243) = to_atom("test_calc", 2);
  atom(244) = to_atom("test_calc_report", 4);
  atom(245) = to_atom("dump/calc.dot", 0);
  atom(246) = to_atom("do_test", 3);
  atom(247) = to_atom(": ", 0);
  atom(248) = to_atom("main", 1);
  atom(249) = to_atom("do_test", 1);
  atom(250) = to_atom("test_call3", 0);
  atom(251) = to_atom("test_otherwise", 0);
  atom(252) = to_atom("test_write_var", 0);
  atom(253) = to_atom("test_write_atom", 0);
  atom(254) = to_atom("test_write_list", 0);
  atom(255) = to_atom("test_write_structure", 0);
  atom(256) = to_atom("test_get_structure", 0);
  atom(257) = to_atom("test_set_structure", 0);
  atom(258) = to_atom("test_get_list", 0);
  atom(259) = to_atom("test_set_list", 0);
  atom(260) = to_atom("test_check_constant", 0);
  atom(261) = to_atom("test_check_list", 0);
  atom(262) = to_atom("test_check_nil", 0);
  atom(263) = to_atom("test_check_structure", 0);
  atom(264) = to_atom("test_wait_var", 0);
  atom(265) = to_atom("test_atom_concat", 0);
  atom(266) = to_atom("test_atom_chars", 0);
  atom(267) = to_atom("test_atom_codes", 0);
  atom(268) = to_atom("test_append", 0);
  atom(269) = to_atom("test_reverse", 0);
  atom(270) = to_atom("test_nth0", 0);
  atom(271) = to_atom("test_nth1", 0);
  atom(272) = to_atom("test_calc", 0);
  atom(273) = to_atom("total_inferences=", 0);
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
  prog->add_entry_point(atom(88), 169);  // =\= / 2
  prog->add_entry_point(atom(89), 170);  // __not_equal__ / 2
  prog->add_entry_point(atom(90), 171);  // := / 2
  prog->add_entry_point(atom(45), 179);  // __add__ / 3
  prog->add_entry_point(atom(97), 185);  // __sub__ / 3
  prog->add_entry_point(atom(98), 191);  // __mul__ / 3
  prog->add_entry_point(atom(99), 197);  // __div__ / 3
  prog->add_entry_point(atom(100), 203);  // __mod__ / 3
  prog->add_entry_point(atom(101), 209);  // __neg__ / 2
  prog->add_entry_point(atom(102), 213);  // __ineg__ / 2
  prog->add_entry_point(atom(103), 214);  // __iadd__ / 3
  prog->add_entry_point(atom(104), 215);  // __isub__ / 3
  prog->add_entry_point(atom(105), 216);  // __imul__ / 3
  prog->add_entry_point(atom(106), 217);  // __idiv__ / 3
  prog->add_entry_point(atom(107), 218);  // __imod__ / 3
  prog->add_entry_point(atom(43), 219);  // __inc__ / 2
  prog->add_entry_point(atom(108), 223);  // __dec__ / 2
  prog->add_entry_point(atom(109), 227);  // __iinc__ / 2
  prog->add_entry_point(atom(110), 228);  // __idec__ / 2
  prog->add_entry_point(atom(111), 229);  // append / 3
  prog->add_entry_point(atom(112), 237);  // reverse / 2
  prog->add_entry_point(atom(113), 241);  // __reverse__ / 3
  prog->add_entry_point(atom(114), 243);  // nth0 / 3
  prog->add_entry_point(atom(115), 247);  // __nth0__ / 3
  prog->add_entry_point(atom(116), 250);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(117), 253);  // nth1 / 3
  prog->add_entry_point(atom(118), 259);  // inference_count / 1
  prog->add_entry_point(atom(119), 260);  // __inference_count__ / 1
  prog->add_entry_point(atom(120), 261);  // resume_count / 1
  prog->add_entry_point(atom(121), 262);  // __resume_count__ / 1
  prog->add_entry_point(atom(122), 263);  // dump_to_dot / 1
  prog->add_entry_point(atom(123), 265);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(124), 266);  // dump_to_dot / 2
  prog->add_entry_point(atom(125), 268);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(126), 269);  // test_call3 / 2
  prog->add_entry_point(atom(132), 274);  // test_call3_aux / 3
  prog->add_entry_point(atom(133), 275);  // test_call3_aux / 2
  prog->add_entry_point(atom(135), 276);  // test_otherwise / 2
  prog->add_entry_point(atom(136), 278);  // test_otherwise_aux / 3
  prog->add_entry_point(atom(139), 280);  // test_write_var / 2
  prog->add_entry_point(atom(140), 281);  // test_write_atom / 2
  prog->add_entry_point(atom(142), 282);  // test_write_list / 2
  prog->add_entry_point(atom(143), 283);  // test_write_structure / 2
  prog->add_entry_point(atom(148), 284);  // test_get_structure / 2
  prog->add_entry_point(atom(149), 285);  // test_set_structure / 2
  prog->add_entry_point(atom(150), 286);  // test_get_list / 2
  prog->add_entry_point(atom(151), 287);  // test_set_list / 2
  prog->add_entry_point(atom(152), 288);  // test_check_constant / 2
  prog->add_entry_point(atom(153), 289);  // test_check_constant_aux / 3
  prog->add_entry_point(atom(157), 292);  // test_check_list / 2
  prog->add_entry_point(atom(158), 293);  // test_check_list_aux / 3
  prog->add_entry_point(atom(163), 296);  // test_check_nil / 2
  prog->add_entry_point(atom(164), 297);  // test_check_nil_aux / 3
  prog->add_entry_point(atom(167), 300);  // test_check_structure / 2
  prog->add_entry_point(atom(169), 301);  // test_check_structure_aux / 3
  prog->add_entry_point(atom(172), 304);  // test_wait_var / 2
  prog->add_entry_point(atom(173), 306);  // wait_var / 3
  prog->add_entry_point(atom(174), 307);  // write_var / 1
  prog->add_entry_point(atom(176), 308);  // test_atom_concat / 2
  prog->add_entry_point(atom(177), 311);  // test_atom_concat_1 / 2
  prog->add_entry_point(atom(178), 313);  // test_atom_concat_2 / 2
  prog->add_entry_point(atom(185), 315);  // test_atom_concat_3 / 2
  prog->add_entry_point(atom(187), 317);  // test_atom_chars / 2
  prog->add_entry_point(atom(188), 319);  // test_atom_chars1 / 2
  prog->add_entry_point(atom(191), 321);  // test_atom_chars2 / 2
  prog->add_entry_point(atom(206), 323);  // test_atom_codes / 2
  prog->add_entry_point(atom(207), 325);  // test_atom_codes1 / 2
  prog->add_entry_point(atom(208), 327);  // test_atom_codes2 / 2
  prog->add_entry_point(atom(209), 329);  // test_append / 2
  prog->add_entry_point(atom(210), 332);  // test_append1 / 2
  prog->add_entry_point(atom(211), 334);  // test_append2 / 2
  prog->add_entry_point(atom(215), 336);  // test_append3 / 2
  prog->add_entry_point(atom(218), 338);  // test_reverse / 2
  prog->add_entry_point(atom(219), 340);  // test_nth0 / 2
  prog->add_entry_point(atom(220), 342);  // test_nth0_ / 2
  prog->add_entry_point(atom(227), 349);  // test_nth0_rev_ / 2
  prog->add_entry_point(atom(235), 356);  // test_nth1 / 2
  prog->add_entry_point(atom(236), 358);  // test_nth1_ / 2
  prog->add_entry_point(atom(238), 364);  // test_nth1_rev_ / 2
  prog->add_entry_point(atom(239), 370);  // test_splice_suspension / 2
  prog->add_entry_point(atom(240), 375);  // test_splice_suspension1 / 3
  prog->add_entry_point(atom(243), 376);  // test_calc / 2
  prog->add_entry_point(atom(244), 382);  // test_calc_report / 4
  prog->add_entry_point(atom(246), 383);  // do_test / 3
  prog->add_entry_point(atom(248), 384);  // main / 1
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
