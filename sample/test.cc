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
Q atom(18);  // atom_chars / 2
Q atom(19);  // __atom_to_chars__ / 2
Q atom(20);  // __chars_to_atom__ / 3
Q atom(21);  // atom_number / 2
Q atom(22);  // __atom_to_number__ / 2
Q atom(23);  // __number_to_atom__ / 2
Q atom(24);  // outstream / 1
Q atom(25);  // outstream / 2
Q atom(26);  // open / 3
Q atom(27);  // write / 2
Q atom(28);  // write / 1
Q atom(29);  // writeln / 2
Q atom(30);  // writeln / 1
Q atom(31);  // nl / 1
Q atom(32);  // nl / 0
Q atom(33);  // close / 1
Q atom(34);  // __open_opt_string_to_integer__ / 3
Q atom(35);  // __open_opt_string_to_integer__ / 5
Q atom(36);  // rdonly / 0
Q atom(37);  // wronly / 0
Q atom(38);  // rdwr / 0
Q atom(39);  // creat / 0
Q atom(40);  // excl / 0
Q atom(41);  // trunc / 0
Q atom(42);  // append / 0
Q atom(43);  // rusr / 0
Q atom(44);  // wusr / 0
Q atom(45);  // xusr / 0
Q atom(46);  // rgrp / 0
Q atom(47);  // wgrp / 0
Q atom(48);  // xgrp / 0
Q atom(49);  // roth / 0
Q atom(50);  // woth / 0
Q atom(51);  // xoth / 0
Q atom(52);  // __open__ / 4
Q atom(53);  // __close__ / 1
Q atom(54);  // __nl__ / 1
Q atom(55);  // __write__ / 2
Q atom(56);  // [] / 0
Q atom(57);  // [ / 0
Q atom(58);  // ] / 0
Q atom(59);  // __write_functor_args__ / 2
Q atom(60);  // ( / 0
Q atom(61);  // ) / 0
Q atom(62);  // __write_functor_args2__ / 2
Q atom(63);  // __write_functor_tail__ / 2
Q atom(64);  // , / 0
Q atom(65);  // __write_list_tail__ / 2
Q atom(66);  // | / 0
Q atom(67);  // __write_number__ / 2
Q atom(68);  // __write_atom__ / 2
Q atom(69);  // __write_var__ / 2
Q atom(70);  // integer / 1
Q atom(71);  // atom / 1
Q atom(72);  // var / 1
Q atom(73);  // is_functor / 1
Q atom(74);  // =.. / 2
Q atom(75);  // == / 2
Q atom(76);  // >= / 2
Q atom(77);  // =< / 2
Q atom(78);  // > / 2
Q atom(79);  // < / 2
Q atom(80);  // =:= / 2
Q atom(81);  // =\= / 2
Q atom(82);  // __not_equal__ / 2
Q atom(83);  // := / 2
Q atom(84);  // + / 2
Q atom(85);  // - / 2
Q atom(86);  // * / 2
Q atom(87);  // / / 2
Q atom(88);  // mod / 2
Q atom(89);  // - / 1
Q atom(90);  // __add__ / 3
Q atom(91);  // __sub__ / 3
Q atom(92);  // __mul__ / 3
Q atom(93);  // __div__ / 3
Q atom(94);  // __mod__ / 3
Q atom(95);  // __neg__ / 2
Q atom(96);  // __ineg__ / 2
Q atom(97);  // __iadd__ / 3
Q atom(98);  // __isub__ / 3
Q atom(99);  // __imul__ / 3
Q atom(100);  // __idiv__ / 3
Q atom(101);  // __imod__ / 3
Q atom(102);  // __inc__ / 2
Q atom(103);  // __dec__ / 2
Q atom(104);  // __iinc__ / 2
Q atom(105);  // __idec__ / 2
Q atom(106);  // append / 3
Q atom(107);  // reverse / 2
Q atom(108);  // __reverse__ / 3
Q atom(109);  // nth0 / 3
Q atom(110);  // __nth0__ / 3
Q atom(111);  // __nth0_rev__ / 4
Q atom(112);  // nth1 / 3
Q atom(113);  // inference_count / 1
Q atom(114);  // __inference_count__ / 1
Q atom(115);  // resume_count / 1
Q atom(116);  // __resume_count__ / 1
Q atom(117);  // dump_to_dot / 1
Q atom(118);  // __dump_to_dot__ / 1
Q atom(119);  // dump_to_dot / 2
Q atom(120);  // __dump_to_dot__ / 2
Q atom(121);  // test_otherwise / 0
Q atom(122);  // test_otherwise_aux / 1
Q atom(123);  // test failed / 0
Q atom(124);  // test success / 0
Q atom(125);  // test_write_var / 0
Q atom(126);  // test_write_atom / 0
Q atom(127);  // atom / 0
Q atom(128);  // test_write_list / 0
Q atom(129);  // test_write_structure / 0
Q atom(130);  // some / 3
Q atom(131);  // structure / 0
Q atom(132);  // and / 0
Q atom(133);  // arguments / 0
Q atom(134);  // test_get_structure / 0
Q atom(135);  // test_set_structure / 0
Q atom(136);  // test_get_list / 0
Q atom(137);  // test_set_list / 0
Q atom(138);  // test_check_constant / 0
Q atom(139);  // test_check_constant_aux / 1
Q atom(140);  // test failed(0) / 0
Q atom(141);  // test success(1) / 0
Q atom(142);  // test failed(otherwise) / 0
Q atom(143);  // test_check_list / 0
Q atom(144);  // a / 0
Q atom(145);  // b / 0
Q atom(146);  // test_check_list_aux / 1
Q atom(147);  // x / 0
Q atom(148);  // y / 0
Q atom(149);  // test failed([x,y]) / 0
Q atom(150);  // test success([a,b]) / 0
Q atom(151);  // test_check_nil / 0
Q atom(152);  // test_check_nil_aux / 1
Q atom(153);  // test failed([a,b]) / 0
Q atom(154);  // test success([]) / 0
Q atom(155);  // test_check_structure / 0
Q atom(156);  // fun / 2
Q atom(157);  // test_check_structure_aux / 1
Q atom(158);  // test failed(fun(x,y)) / 0
Q atom(159);  // test success(fun(a,b)) / 0
Q atom(160);  // test_wait_var / 0
Q atom(161);  // wait_var / 1
Q atom(162);  // write_var / 1
Q atom(163);  // fire / 0
Q atom(164);  // test_atom_concat / 0
Q atom(165);  // test_atom_concat_1 / 0
Q atom(166);  // abc / 0
Q atom(167);  // def / 0
Q atom(168);  // abc + def =  / 0
Q atom(169);  // test_atom_concat_2 / 0
Q atom(170);  // abcdef / 0
Q atom(171);  // abc + [ / 0
Q atom(172);  // ] = abcdef / 0
Q atom(173);  // test_atom_concat_3 / 0
Q atom(174);  // ] + def = abcdef / 0
Q atom(175);  // test_atom_chars / 0
Q atom(176);  // test_atom_chars1 / 0
Q atom(177);  // abcdefgあいうえお漢字☺🍺 / 0
Q atom(178);  //  ->  / 0
Q atom(179);  // test_atom_chars2 / 0
Q atom(180);  // c / 0
Q atom(181);  // d / 0
Q atom(182);  // e / 0
Q atom(183);  // f / 0
Q atom(184);  // g / 0
Q atom(185);  // あ / 0
Q atom(186);  // い / 0
Q atom(187);  // う / 0
Q atom(188);  // え / 0
Q atom(189);  // お / 0
Q atom(190);  // 漢 / 0
Q atom(191);  // 字 / 0
Q atom(192);  // ☺ / 0
Q atom(193);  // 🍺 / 0
Q atom(194);  //  <-  / 0
Q atom(195);  // test_atom_codes / 0
Q atom(196);  // test_atom_codes1 / 0
Q atom(197);  // test_atom_codes2 / 0
Q atom(198);  // test_append / 0
Q atom(199);  // test_append1 / 0
Q atom(200);  // + / 0
Q atom(201);  // =[ / 0
Q atom(202);  // test_append2 / 0
Q atom(203);  // ]= / 0
Q atom(204);  // test_append3 / 0
Q atom(205);  // ]+ / 0
Q atom(206);  // = / 0
Q atom(207);  // test_reverse / 0
Q atom(208);  // test_nth0 / 0
Q atom(209);  // test_nth0_ / 0
Q atom(210);  //  0: [ / 0
Q atom(211);  // ] 1: [ / 0
Q atom(212);  // ] 2: [ / 0
Q atom(213);  // ] 3: [ / 0
Q atom(214);  // ] 4: [ / 0
Q atom(215);  // ] 5: [ / 0
Q atom(216);  // test_nth0_rev_ / 0
Q atom(217);  //  [ / 0
Q atom(218);  // ]: a / 0
Q atom(219);  // ]: b / 0
Q atom(220);  // ]: c / 0
Q atom(221);  // ]: d / 0
Q atom(222);  // ]: e / 0
Q atom(223);  // ]: f / 0
Q atom(224);  // test_nth1 / 0
Q atom(225);  // test_nth1_ / 0
Q atom(226);  //  1: [ / 0
Q atom(227);  // test_nth1_rev_ / 0
Q atom(228);  // test_splice_suspension / 0
Q atom(229);  // dump/splice.dot / 0
Q atom(230);  // test_splice_suspension1 / 1
Q atom(231);  // test_calc / 0
Q atom(232);  // xxx0 / 0
Q atom(233);  // xxx1 / 0
Q atom(234);  // dump/calc.dot / 0
Q atom(235);  // xxx / 0
Q atom(236);  // do_test / 1
Q atom(237);  // :  / 0
Q atom(238);  // main / 1
Q atom(239);  // total_inferences= / 0
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
      MACRO_call(150,13);  // call(atom/1)
    case 13:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(150,14);  // call(atom/1)
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
      MACRO_call(150,16);  // call(atom/1)
    case 16:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(150,17);  // call(atom/1)
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
      MACRO_call(150,19);  // call(atom/1)
    case 19:  // return_from_call(atom/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(150,20);  // call(atom/1)
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
    vm->unify(c, vm->in[3]);
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
    vm->unify(c, vm->in[2]);
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
    vm->unify(c, vm->in[1]);
  }
  MACRO_proceed;
    case 24:  // atom_codes/2
      MACRO_goal(24,atom(13));
      MACRO_requires(8);
      MACRO_try_guard_else(26);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,25);  // call(atom/1)
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
    vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2]);
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
      MACRO_call(149,30);  // call(integer/1)
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
    vm->unify(to_atom(s.c_str(), 0), vm->in[3]);
  }
  MACRO_proceed;
    case 33:  // atom_chars/2
      MACRO_goal(33,atom(18));
      MACRO_requires(8);
      MACRO_try_guard_else(35);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,34);  // call(atom/1)
    case 34:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(36,2);  // execute(__atom_to_chars__/2)
    case 35:  // atom_chars/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(3),reg::out(3));
      MACRO_execute(37,3);  // execute(__chars_to_atom__/3)
    case 36:  // __atom_to_chars__/2
      MACRO_goal(36,atom(19));
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
    vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2]);
  }
  MACRO_proceed;
    case 37:  // __chars_to_atom__/3
      MACRO_goal(37,atom(20));
      MACRO_requires(9);
      MACRO_try_guard_else(38);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(1));
      MACRO_proceed;
    case 38:  // __chars_to_atom__/3-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(5));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(12,39);  // spawn(atom_concat/3)
    case 39:  // return_from_spawn(atom_concat/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_execute(37,3);  // execute(__chars_to_atom__/3)
    case 40:  // atom_number/2
      MACRO_goal(40,atom(21));
      MACRO_requires(5);
      MACRO_try_guard_else(42);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,41);  // call(atom/1)
    case 41:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(44,2);  // execute(__atom_to_number__/2)
    case 42:  // atom_number/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,43);  // call(integer/1)
    case 43:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(45,2);  // execute(__number_to_atom__/2)
    case 44:  // __atom_to_number__/2
      MACRO_goal(44,atom(22));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_get_constant(tagvalue<TAG_INT>(i), reg::in(2));
  }
  MACRO_proceed;
    case 45:  // __number_to_atom__/2
      MACRO_goal(45,atom(23));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q = vm->in[2];
    const int64_t i = value_of<int64_t>(q);
    const std::string s = std::to_string(i);
    MACRO_get_constant(to_atom(s.c_str(), 0), reg::in(1));
  }
  MACRO_proceed;
    case 46:  // outstream/1
      MACRO_goal(46,atom(24));
      MACRO_requires(6);
      MACRO_try_guard_else(47);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_proceed;
    case 47:  // outstream/1-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_variable(reg::x(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(48,2);  // execute(outstream/2)
    case 48:  // outstream/2
      MACRO_goal(48,atom(25));
      MACRO_requires(9);
      MACRO_try_guard_else(50);
      MACRO_check_structure(atom(26),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(62,49);  // spawn(open/3)
    case 49:  // return_from_spawn(open/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 50:  // outstream/2-2
      MACRO_try_guard_else(52);
      MACRO_check_structure(atom(27),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(109,51);  // spawn(write/2)
    case 51:  // return_from_spawn(write/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 52:  // outstream/2-3
      MACRO_try_guard_else(54);
      MACRO_check_structure(atom(28),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,53);  // spawn(write/1)
    case 53:  // return_from_spawn(write/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 54:  // outstream/2-4
      MACRO_try_guard_else(56);
      MACRO_check_structure(atom(29),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_spawn(102,55);  // spawn(writeln/2)
    case 55:  // return_from_spawn(writeln/2)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 56:  // outstream/2-5
      MACRO_try_guard_else(58);
      MACRO_check_structure(atom(30),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(100,57);  // spawn(writeln/1)
    case 57:  // return_from_spawn(writeln/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 58:  // outstream/2-6
      MACRO_try_guard_else(60);
      MACRO_check_structure(atom(31),reg::in(1));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(105,59);  // spawn(nl/1)
    case 59:  // return_from_spawn(nl/1)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 60:  // outstream/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_constant(atom(32),reg::in(1));
      MACRO_activate;
      MACRO_par(6);
      MACRO_spawn(104,61);  // spawn(nl/0)
    case 61:  // return_from_spawn(nl/0)
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_execute(46,1);  // execute(outstream/1)
    case 62:  // open/3
      MACRO_goal(62,atom(26));
      MACRO_requires(10);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_variable(reg::x(5),reg::out(3));
      MACRO_spawn(65,63);  // spawn(__open_opt_string_to_integer__/3)
    case 63:  // return_from_spawn(__open_opt_string_to_integer__/3)
      MACRO_tail(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_out_value(reg::in(3),reg::out(4));
      MACRO_execute(98,4);  // execute(__open__/4)
    case 64:  // close/1
      MACRO_goal(64,atom(33));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(99,1);  // execute(__close__/1)
    case 65:  // __open_opt_string_to_integer__/3
      MACRO_goal(65,atom(34));
      MACRO_requires(9);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 66:  // __open_opt_string_to_integer__/5
      MACRO_goal(66,atom(35));
      MACRO_requires(13);
      MACRO_try_guard_else(67);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(2));
      MACRO_get_value(reg::in(5),reg::in(3));
      MACRO_proceed;
    case 67:  // __open_opt_string_to_integer__/5-2
      MACRO_try_guard_else(68);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(36));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_tail(7);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 68:  // __open_opt_string_to_integer__/5-3
      MACRO_try_guard_else(70);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(37));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(214,69);  // call(__inc__/2)
    case 69:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 70:  // __open_opt_string_to_integer__/5-4
      MACRO_try_guard_else(72);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(38));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,71);  // call(__add__/3)
    case 71:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 72:  // __open_opt_string_to_integer__/5-5
      MACRO_try_guard_else(74);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(39));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,73);  // call(__add__/3)
    case 73:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 74:  // __open_opt_string_to_integer__/5-6
      MACRO_try_guard_else(76);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(40));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,75);  // call(__add__/3)
    case 75:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 76:  // __open_opt_string_to_integer__/5-7
      MACRO_try_guard_else(78);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(41));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,77);  // call(__add__/3)
    case 77:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 78:  // __open_opt_string_to_integer__/5-8
      MACRO_try_guard_else(80);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(42));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,79);  // call(__add__/3)
    case 79:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(7),reg::out(4));
      MACRO_out_value(reg::in(5),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 80:  // __open_opt_string_to_integer__/5-9
      MACRO_try_guard_else(82);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(43));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,81);  // call(__add__/3)
    case 81:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 82:  // __open_opt_string_to_integer__/5-10
      MACRO_try_guard_else(84);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(44));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,83);  // call(__add__/3)
    case 83:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 84:  // __open_opt_string_to_integer__/5-11
      MACRO_try_guard_else(86);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(45));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,85);  // call(__add__/3)
    case 85:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 86:  // __open_opt_string_to_integer__/5-12
      MACRO_try_guard_else(88);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(46));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,87);  // call(__add__/3)
    case 87:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 88:  // __open_opt_string_to_integer__/5-13
      MACRO_try_guard_else(90);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(47));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,89);  // call(__add__/3)
    case 89:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 90:  // __open_opt_string_to_integer__/5-14
      MACRO_try_guard_else(92);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(48));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,91);  // call(__add__/3)
    case 91:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 92:  // __open_opt_string_to_integer__/5-15
      MACRO_try_guard_else(94);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(49));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,93);  // call(__add__/3)
    case 93:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 94:  // __open_opt_string_to_integer__/5-16
      MACRO_try_guard_else(96);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(50));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(7),reg::out(3));
      MACRO_call(174,95);  // call(__add__/3)
    case 95:  // return_from_call(__add__/3)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 96:  // __open_opt_string_to_integer__/5-17
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(51));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_value(reg::in(5),reg::out(1));
      MACRO_out_variable(reg::x(7),reg::out(2));
      MACRO_call(214,97);  // call(__inc__/2)
    case 97:  // return_from_call(__inc__/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 98:  // __open__/4
      MACRO_goal(98,atom(52));
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
      vm->unify(to_atom("error", 0), vm->in[4]);
    } else {
      vm->unify(tagvalue<TAG_INT>(fd), vm->in[4]);
    }
  }
  MACRO_proceed;
    case 99:  // __close__/1
      MACRO_goal(99,atom(53));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
  }
  MACRO_proceed;
    case 100:  // writeln/1
      MACRO_goal(100,atom(30));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(108,101);  // call(write/1)
    case 101:  // return_from_call(write/1)
      MACRO_tail(3);
      MACRO_execute(104,0);  // execute(nl/0)
    case 102:  // writeln/2
      MACRO_goal(102,atom(29));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(109,103);  // spawn(write/2)
    case 103:  // return_from_spawn(write/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(105,1);  // execute(nl/1)
    case 104:  // nl/0
      MACRO_goal(104,atom(32));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(105,1);  // execute(nl/1)
    case 105:  // nl/1
      MACRO_goal(105,atom(31));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,106);  // call(integer/1)
    case 106:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(107,1);  // execute(__nl__/1)
    case 107:  // __nl__/1
      MACRO_goal(107,atom(54));
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
    case 108:  // write/1
      MACRO_goal(108,atom(28));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(109,2);  // execute(write/2)
    case 109:  // write/2
      MACRO_goal(109,atom(27));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,110);  // call(integer/1)
    case 110:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 111:  // __write__/2
      MACRO_goal(111,atom(55));
      MACRO_requires(7);
      MACRO_try_guard_else(113);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(150,112);  // call(atom/1)
    case 112:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(147,2);  // execute(__write_atom__/2)
    case 113:  // __write__/2-2
      MACRO_try_guard_else(115);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,114);  // call(var/1)
    case 114:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(148,2);  // execute(__write_var__/2)
    case 115:  // __write__/2-3
      MACRO_try_guard_else(117);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,116);  // call(integer/1)
    case 116:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(146,2);  // execute(__write_number__/2)
    case 117:  // __write__/2-4
      MACRO_try_guard_else(118);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(56),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 118:  // __write__/2-5
      MACRO_try_guard_else(122);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(57),reg::out(2));
      MACRO_call(111,119);  // call(__write__/2)
    case 119:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,120);  // call(__write__/2)
    case 120:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_call(137,121);  // call(__write_list_tail__/2)
    case 121:  // return_from_call(__write_list_tail__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(58),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 122:  // __write__/2-6
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(152,123);  // call(is_functor/1)
    case 123:  // return_from_call(is_functor/1)
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_list(reg::out(2));
      MACRO_write_variable(reg::x(4));
      MACRO_write_variable(reg::x(3));
      MACRO_call(153,124);  // call((=..)/2)
    case 124:  // return_from_call((=..)/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,125);  // call(__write__/2)
    case 125:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(126,2);  // execute(__write_functor_args__/2)
    case 126:  // __write_functor_args__/2
      MACRO_goal(126,atom(59));
      MACRO_requires(5);
      MACRO_try_guard_else(127);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 127:  // __write_functor_args__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(60),reg::out(2));
      MACRO_call(111,128);  // call(__write__/2)
    case 128:  // return_from_call(__write__/2)
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(130,129);  // call(__write_functor_args2__/2)
    case 129:  // return_from_call(__write_functor_args2__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(61),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 130:  // __write_functor_args2__/2
      MACRO_goal(130,atom(62));
      MACRO_requires(7);
      MACRO_try_guard_else(131);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 131:  // __write_functor_args2__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,132);  // call(__write__/2)
    case 132:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(133,2);  // execute(__write_functor_tail__/2)
    case 133:  // __write_functor_tail__/2
      MACRO_goal(133,atom(63));
      MACRO_requires(7);
      MACRO_try_guard_else(134);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 134:  // __write_functor_tail__/2-2
      MACRO_try_guard_else_suspend;
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(64),reg::out(2));
      MACRO_call(111,135);  // call(__write__/2)
    case 135:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,136);  // call(__write__/2)
    case 136:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(133,2);  // execute(__write_functor_tail__/2)
    case 137:  // __write_list_tail__/2
      MACRO_goal(137,atom(65));
      MACRO_requires(7);
      MACRO_try_guard_else(140);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,138);  // call(var/1)
    case 138:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(66),reg::out(2));
      MACRO_call(111,139);  // call(__write__/2)
    case 139:  // return_from_call(__write__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 140:  // __write_list_tail__/2-2
      MACRO_try_guard_else(141);
      MACRO_check_nil(reg::in(2));
      MACRO_activate;
      MACRO_proceed;
    case 141:  // __write_list_tail__/2-3
      MACRO_try_guard_else(144);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(64),reg::out(2));
      MACRO_call(111,142);  // call(__write__/2)
    case 142:  // return_from_call(__write__/2)
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_call(111,143);  // call(__write__/2)
    case 143:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(3),reg::out(2));
      MACRO_execute(137,2);  // execute(__write_list_tail__/2)
    case 144:  // __write_list_tail__/2-4
      MACRO_otherwise;
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(66),reg::out(2));
      MACRO_call(111,145);  // call(__write__/2)
    case 145:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 146:  // __write_number__/2
      MACRO_goal(146,atom(67));
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
    case 147:  // __write_atom__/2
      MACRO_goal(147,atom(68));
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
    case 148:  // __write_var__/2
      MACRO_goal(148,atom(69));
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
    case 149:  // integer/1
      MACRO_goal(149,atom(70));
      MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
    case 150:  // atom/1
      MACRO_goal(150,atom(71));
      MACRO_requires(3);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
    case 151:  // var/1
      MACRO_goal(151,atom(72));
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
    case 152:  // is_functor/1
      MACRO_goal(152,atom(73));
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
    case 153:  // (=..)/2
      MACRO_goal(153,atom(74));
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
    vm->unify(tagptr<TAG_LIST>(&vm->heap[h]), vm->in[2]);
  }
  MACRO_proceed;
    case 154:  // (==)/2
      MACRO_goal(154,atom(75));
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
    case 155:  // (>=)/2
      MACRO_goal(155,atom(76));
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
    case 156:  // (=<)/2
      MACRO_goal(156,atom(77));
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
    case 157:  // (>)/2
      MACRO_goal(157,atom(78));
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
    case 158:  // (<)/2
      MACRO_goal(158,atom(79));
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
    case 159:  // (=:=)/2
      MACRO_goal(159,atom(80));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,160);  // spawn((:=)/2)
    case 160:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,161);  // spawn((:=)/2)
    case 161:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(154,2);  // execute((==)/2)
    case 162:  // (=\=)/2
      MACRO_goal(162,atom(81));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,163);  // spawn((:=)/2)
    case 163:  // return_from_spawn((:=)/2)
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,164);  // spawn((:=)/2)
    case 164:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_execute(165,2);  // execute(__not_equal__/2)
    case 165:  // __not_equal__/2
      MACRO_goal(165,atom(82));
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
    case 166:  // (:=)/2
      MACRO_goal(166,atom(83));
      MACRO_requires(8);
      MACRO_try_guard_else(168);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,167);  // call(integer/1)
    case 167:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
    case 168:  // (:=)/2-2
      MACRO_try_guard_else(169);
      MACRO_check_structure(atom(84),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(174,3);  // execute(__add__/3)
    case 169:  // (:=)/2-3
      MACRO_try_guard_else(170);
      MACRO_check_structure(atom(85),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(180,3);  // execute(__sub__/3)
    case 170:  // (:=)/2-4
      MACRO_try_guard_else(171);
      MACRO_check_structure(atom(86),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(186,3);  // execute(__mul__/3)
    case 171:  // (:=)/2-5
      MACRO_try_guard_else(172);
      MACRO_check_structure(atom(87),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(192,3);  // execute(__div__/3)
    case 172:  // (:=)/2-6
      MACRO_try_guard_else(173);
      MACRO_check_structure(atom(88),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(198,3);  // execute(__mod__/3)
    case 173:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_check_structure(atom(89),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(204,2);  // execute(__neg__/2)
    case 174:  // __add__/3
      MACRO_goal(174,atom(90));
      MACRO_requires(9);
      MACRO_try_guard_else(177);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,175);  // call(integer/1)
    case 175:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,176);  // call(integer/1)
    case 176:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(209,3);  // execute(__iadd__/3)
    case 177:  // __add__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,178);  // spawn((:=)/2)
    case 178:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,179);  // spawn((:=)/2)
    case 179:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(209,3);  // execute(__iadd__/3)
    case 180:  // __sub__/3
      MACRO_goal(180,atom(91));
      MACRO_requires(9);
      MACRO_try_guard_else(183);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,181);  // call(integer/1)
    case 181:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,182);  // call(integer/1)
    case 182:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(210,3);  // execute(__isub__/3)
    case 183:  // __sub__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,184);  // spawn((:=)/2)
    case 184:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,185);  // spawn((:=)/2)
    case 185:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(210,3);  // execute(__isub__/3)
    case 186:  // __mul__/3
      MACRO_goal(186,atom(92));
      MACRO_requires(9);
      MACRO_try_guard_else(189);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,187);  // call(integer/1)
    case 187:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,188);  // call(integer/1)
    case 188:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(211,3);  // execute(__imul__/3)
    case 189:  // __mul__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,190);  // spawn((:=)/2)
    case 190:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,191);  // spawn((:=)/2)
    case 191:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(211,3);  // execute(__imul__/3)
    case 192:  // __div__/3
      MACRO_goal(192,atom(93));
      MACRO_requires(9);
      MACRO_try_guard_else(195);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,193);  // call(integer/1)
    case 193:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,194);  // call(integer/1)
    case 194:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(212,3);  // execute(__idiv__/3)
    case 195:  // __div__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,196);  // spawn((:=)/2)
    case 196:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,197);  // spawn((:=)/2)
    case 197:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(212,3);  // execute(__idiv__/3)
    case 198:  // __mod__/3
      MACRO_goal(198,atom(94));
      MACRO_requires(9);
      MACRO_try_guard_else(201);
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,199);  // call(integer/1)
    case 199:  // return_from_call(integer/1)
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,200);  // call(integer/1)
    case 200:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__imod__/3)
    case 201:  // __mod__/3-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,202);  // spawn((:=)/2)
    case 202:  // return_from_spawn((:=)/2)
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_spawn(166,203);  // spawn((:=)/2)
    case 203:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(213,3);  // execute(__imod__/3)
    case 204:  // __neg__/2
      MACRO_goal(204,atom(95));
      MACRO_requires(6);
      MACRO_try_guard_else(206);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,205);  // call(integer/1)
    case 205:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(208,2);  // execute(__ineg__/2)
    case 206:  // __neg__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,207);  // spawn((:=)/2)
    case 207:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(208,2);  // execute(__ineg__/2)
    case 208:  // __ineg__/2
      MACRO_goal(208,atom(96));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 209:  // __iadd__/3
      MACRO_goal(209,atom(97));
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
    case 210:  // __isub__/3
      MACRO_goal(210,atom(98));
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
    case 211:  // __imul__/3
      MACRO_goal(211,atom(99));
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
    case 212:  // __idiv__/3
      MACRO_goal(212,atom(100));
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
    case 213:  // __imod__/3
      MACRO_goal(213,atom(101));
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
    case 214:  // __inc__/2
      MACRO_goal(214,atom(102));
      MACRO_requires(6);
      MACRO_try_guard_else(216);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,215);  // call(integer/1)
    case 215:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(222,2);  // execute(__iinc__/2)
    case 216:  // __inc__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,217);  // spawn((:=)/2)
    case 217:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(222,2);  // execute(__iinc__/2)
    case 218:  // __dec__/2
      MACRO_goal(218,atom(103));
      MACRO_requires(6);
      MACRO_try_guard_else(220);
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(149,219);  // call(integer/1)
    case 219:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(223,2);  // execute(__idec__/2)
    case 220:  // __dec__/2-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_spawn(166,221);  // spawn((:=)/2)
    case 221:  // return_from_spawn((:=)/2)
      MACRO_tail(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(223,2);  // execute(__idec__/2)
    case 222:  // __iinc__/2
      MACRO_goal(222,atom(104));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 223:  // __idec__/2
      MACRO_goal(223,atom(105));
      MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  }
  MACRO_proceed;
    case 224:  // append/3
      MACRO_goal(224,atom(106));
      MACRO_requires(9);
      MACRO_try_guard_else(225);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 225:  // append/3-2
      MACRO_try_guard_else(226);
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
      MACRO_execute(224,3);  // execute(append/3)
    case 226:  // append/3-3
      MACRO_try_guard_else(227);
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
      MACRO_execute(224,3);  // execute(append/3)
    case 227:  // append/3-4
      MACRO_try_guard_else_suspend;
      MACRO_seq(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,228);  // call(var/1)
    case 228:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_spawn(232,229);  // spawn(reverse/2)
    case 229:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_spawn(232,230);  // spawn(reverse/2)
    case 230:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(224,231);  // spawn(append/3)
    case 231:  // return_from_spawn(append/3)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(232,2);  // execute(reverse/2)
    case 232:  // reverse/2
      MACRO_goal(232,atom(107));
      MACRO_requires(6);
      MACRO_try_guard_else(234);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,233);  // call(var/1)
    case 233:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(236,3);  // execute(__reverse__/3)
    case 234:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,235);  // call(var/1)
    case 235:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(236,3);  // execute(__reverse__/3)
    case 236:  // __reverse__/3
      MACRO_goal(236,atom(108));
      MACRO_requires(10);
      MACRO_try_guard_else(237);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 237:  // __reverse__/3-2
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
      MACRO_execute(236,3);  // execute(__reverse__/3)
    case 238:  // nth0/3
      MACRO_goal(238,atom(109));
      MACRO_requires(8);
      MACRO_try_guard_else(240);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(151,239);  // call(var/1)
    case 239:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(242,3);  // execute(__nth0__/3)
    case 240:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,241);  // call(var/1)
    case 241:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(245,4);  // execute(__nth0_rev__/4)
    case 242:  // __nth0__/3
      MACRO_goal(242,atom(110));
      MACRO_requires(9);
      MACRO_try_guard_else(243);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 243:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_call(218,244);  // call(__dec__/2)
    case 244:  // return_from_call(__dec__/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(242,3);  // execute(__nth0__/3)
    case 245:  // __nth0_rev__/4
      MACRO_goal(245,atom(111));
      MACRO_requires(11);
      MACRO_try_guard_else(246);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 246:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(7);
      MACRO_out_value(reg::in(4),reg::out(1));
      MACRO_out_variable(reg::x(6),reg::out(2));
      MACRO_call(214,247);  // call(__inc__/2)
    case 247:  // return_from_call(__inc__/2)
      MACRO_tail(7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(6),reg::out(4));
      MACRO_execute(245,4);  // execute(__nth0_rev__/4)
    case 248:  // nth1/3
      MACRO_goal(248,atom(112));
      MACRO_requires(9);
      MACRO_try_guard_else(251);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(151,249);  // call(var/1)
    case 249:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_call(218,250);  // call(__dec__/2)
    case 250:  // return_from_call(__dec__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(242,3);  // execute(__nth0__/3)
    case 251:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,252);  // call(var/1)
    case 252:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(245,253);  // spawn(__nth0_rev__/4)
    case 253:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(214,2);  // execute(__inc__/2)
    case 254:  // inference_count/1
      MACRO_goal(254,atom(113));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(255,1);  // execute(__inference_count__/1)
    case 255:  // __inference_count__/1
      MACRO_goal(255,atom(114));
      MACRO_requires(3);
  MACRO_activate;
  vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1]);
  MACRO_proceed;
    case 256:  // resume_count/1
      MACRO_goal(256,atom(115));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(257,1);  // execute(__resume_count__/1)
    case 257:  // __resume_count__/1
      MACRO_goal(257,atom(116));
      MACRO_requires(3);
  MACRO_activate;
  vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1]);
  MACRO_proceed;
    case 258:  // dump_to_dot/1
      MACRO_goal(258,atom(117));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,259);  // call(atom/1)
    case 259:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(260,1);  // execute(__dump_to_dot__/1)
    case 260:  // __dump_to_dot__/1
      MACRO_goal(260,atom(118));
      MACRO_requires(3);
  MACRO_activate;
  {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  }
  MACRO_proceed;
    case 261:  // dump_to_dot/2
      MACRO_goal(261,atom(119));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,262);  // call(atom/1)
    case 262:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(263,2);  // execute(__dump_to_dot__/2)
    case 263:  // __dump_to_dot__/2
      MACRO_goal(263,atom(120));
      MACRO_requires(5);
  MACRO_activate;
  {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  }
  MACRO_proceed;
    case 264:  // test_otherwise/0
      MACRO_goal(264,atom(121));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(266,265);  // spawn(test_otherwise_aux/1)
    case 265:  // return_from_spawn(test_otherwise_aux/1)
      MACRO_get_constant(tagvalue<TAG_INT>(1),reg::x(1));
      MACRO_proceed;
    case 266:  // test_otherwise_aux/1
      MACRO_goal(266,atom(122));
      MACRO_requires(3);
      MACRO_try_guard_else(267);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(123),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 267:  // test_otherwise_aux/1-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(124),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 268:  // test_write_var/0
      MACRO_goal(268,atom(125));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 269:  // test_write_atom/0
      MACRO_goal(269,atom(126));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(atom(127),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 270:  // test_write_list/0
      MACRO_goal(270,atom(128));
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
      MACRO_execute(100,1);  // execute(writeln/1)
    case 271:  // test_write_structure/0
      MACRO_goal(271,atom(129));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(130),reg::out(1));
      MACRO_write_constant(atom(131));
      MACRO_write_constant(atom(132));
      MACRO_write_constant(atom(133));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 272:  // test_get_structure/0
      MACRO_goal(272,atom(134));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_structure(atom(84),reg::x(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 273:  // test_set_structure/0
      MACRO_goal(273,atom(135));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_structure(atom(84),reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_get_variable(reg::x(2),reg::x(1));
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 274:  // test_get_list/0
      MACRO_goal(274,atom(136));
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
      MACRO_execute(100,1);  // execute(writeln/1)
    case 275:  // test_set_list/0
      MACRO_goal(275,atom(137));
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
      MACRO_execute(100,1);  // execute(writeln/1)
    case 276:  // test_check_constant/0
      MACRO_goal(276,atom(138));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(277,1);  // execute(test_check_constant_aux/1)
    case 277:  // test_check_constant_aux/1
      MACRO_goal(277,atom(139));
      MACRO_requires(3);
      MACRO_try_guard_else(278);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(140),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 278:  // test_check_constant_aux/1-2
      MACRO_try_guard_else(279);
      MACRO_check_constant(tagvalue<TAG_INT>(1),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(141),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 279:  // test_check_constant_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(142),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 280:  // test_check_list/0
      MACRO_goal(280,atom(143));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_list(reg::out(1));
      MACRO_write_constant(atom(144));
      MACRO_write_list;
      MACRO_write_constant(atom(145));
      MACRO_write_nil;
      MACRO_execute(281,1);  // execute(test_check_list_aux/1)
    case 281:  // test_check_list_aux/1
      MACRO_goal(281,atom(146));
      MACRO_requires(3);
      MACRO_try_guard_else(282);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(147));
      MACRO_read_list;
      MACRO_read_constant(atom(148));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(149),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 282:  // test_check_list_aux/1-2
      MACRO_try_guard_else(283);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(144));
      MACRO_read_list;
      MACRO_read_constant(atom(145));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(150),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 283:  // test_check_list_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(142),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 284:  // test_check_nil/0
      MACRO_goal(284,atom(151));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_nil(reg::out(1));
      MACRO_execute(285,1);  // execute(test_check_nil_aux/1)
    case 285:  // test_check_nil_aux/1
      MACRO_goal(285,atom(152));
      MACRO_requires(3);
      MACRO_try_guard_else(286);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(144));
      MACRO_read_list;
      MACRO_read_constant(atom(145));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(153),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 286:  // test_check_nil_aux/1-2
      MACRO_try_guard_else(287);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 287:  // test_check_nil_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(142),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 288:  // test_check_structure/0
      MACRO_goal(288,atom(155));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(156),reg::out(1));
      MACRO_write_constant(atom(144));
      MACRO_write_constant(atom(145));
      MACRO_execute(289,1);  // execute(test_check_structure_aux/1)
    case 289:  // test_check_structure_aux/1
      MACRO_goal(289,atom(157));
      MACRO_requires(3);
      MACRO_try_guard_else(290);
      MACRO_check_structure(atom(156),reg::in(1));
      MACRO_read_constant(atom(147));
      MACRO_read_constant(atom(148));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(158),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 290:  // test_check_structure_aux/1-2
      MACRO_try_guard_else(291);
      MACRO_check_structure(atom(156),reg::in(1));
      MACRO_read_constant(atom(144));
      MACRO_read_constant(atom(145));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(159),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 291:  // test_check_structure_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(142),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 292:  // test_wait_var/0
      MACRO_goal(292,atom(160));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(294,293);  // spawn(wait_var/1)
    case 293:  // return_from_spawn(wait_var/1)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(295,1);  // execute(write_var/1)
    case 294:  // wait_var/1
      MACRO_goal(294,atom(161));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 295:  // write_var/1
      MACRO_goal(295,atom(162));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_constant(atom(163),reg::in(1));
      MACRO_proceed;
    case 296:  // test_atom_concat/0
      MACRO_goal(296,atom(164));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(299,297);  // spawn(test_atom_concat_1/0)
    case 297:  // return_from_spawn(test_atom_concat_1/0)
      MACRO_par(2);
      MACRO_spawn(304,298);  // spawn(test_atom_concat_2/0)
    case 298:  // return_from_spawn(test_atom_concat_2/0)
      MACRO_tail(2);
      MACRO_execute(308,0);  // execute(test_atom_concat_3/0)
    case 299:  // test_atom_concat_1/0
      MACRO_goal(299,atom(165));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(166),reg::out(1));
      MACRO_out_constant(atom(167),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(12,300);  // spawn(atom_concat/3)
    case 300:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(168),reg::out(1));
      MACRO_spawn(108,301);  // spawn(write/1)
    case 301:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_constant(atom(57),reg::out(1));
      MACRO_spawn(108,302);  // spawn(write/1)
    case 302:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,303);  // spawn(write/1)
    case 303:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 304:  // test_atom_concat_2/0
      MACRO_goal(304,atom(169));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(166),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(170),reg::out(3));
      MACRO_spawn(12,305);  // spawn(atom_concat/3)
    case 305:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(171),reg::out(1));
      MACRO_spawn(108,306);  // spawn(write/1)
    case 306:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,307);  // spawn(write/1)
    case 307:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(172),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 308:  // test_atom_concat_3/0
      MACRO_goal(308,atom(173));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_out_constant(atom(167),reg::out(2));
      MACRO_out_constant(atom(170),reg::out(3));
      MACRO_spawn(12,309);  // spawn(atom_concat/3)
    case 309:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(57),reg::out(1));
      MACRO_spawn(108,310);  // spawn(write/1)
    case 310:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,311);  // spawn(write/1)
    case 311:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(174),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 312:  // test_atom_chars/0
      MACRO_goal(312,atom(175));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(314,313);  // spawn(test_atom_chars1/0)
    case 313:  // return_from_spawn(test_atom_chars1/0)
      MACRO_tail(2);
      MACRO_execute(318,0);  // execute(test_atom_chars2/0)
    case 314:  // test_atom_chars1/0
      MACRO_goal(314,atom(176));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(177),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(33,315);  // spawn(atom_chars/2)
    case 315:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,316);  // spawn(write/1)
    case 316:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(178),reg::out(1));
      MACRO_spawn(108,317);  // spawn(write/1)
    case 317:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 318:  // test_atom_chars2/0
      MACRO_goal(318,atom(179));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_spawn(33,319);  // spawn(atom_chars/2)
    case 319:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,320);  // spawn(write/1)
    case 320:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(194),reg::out(1));
      MACRO_spawn(108,321);  // spawn(write/1)
    case 321:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 322:  // test_atom_codes/0
      MACRO_goal(322,atom(195));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(324,323);  // spawn(test_atom_codes1/0)
    case 323:  // return_from_spawn(test_atom_codes1/0)
      MACRO_tail(2);
      MACRO_execute(328,0);  // execute(test_atom_codes2/0)
    case 324:  // test_atom_codes1/0
      MACRO_goal(324,atom(196));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(177),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(24,325);  // spawn(atom_codes/2)
    case 325:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,326);  // spawn(write/1)
    case 326:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(178),reg::out(1));
      MACRO_spawn(108,327);  // spawn(write/1)
    case 327:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 328:  // test_atom_codes2/0
      MACRO_goal(328,atom(197));
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
      MACRO_spawn(24,329);  // spawn(atom_codes/2)
    case 329:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,330);  // spawn(write/1)
    case 330:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(194),reg::out(1));
      MACRO_spawn(108,331);  // spawn(write/1)
    case 331:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 332:  // test_append/0
      MACRO_goal(332,atom(198));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(335,333);  // spawn(test_append1/0)
    case 333:  // return_from_spawn(test_append1/0)
      MACRO_par(2);
      MACRO_spawn(342,334);  // spawn(test_append2/0)
    case 334:  // return_from_spawn(test_append2/0)
      MACRO_tail(2);
      MACRO_execute(349,0);  // execute(test_append3/0)
    case 335:  // test_append1/0
      MACRO_goal(335,atom(199));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_variable(reg::x(3),reg::out(3));
      MACRO_spawn(224,336);  // spawn(append/3)
    case 336:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,337);  // spawn(write/1)
    case 337:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(200),reg::out(1));
      MACRO_spawn(108,338);  // spawn(write/1)
    case 338:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,339);  // spawn(write/1)
    case 339:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(201),reg::out(1));
      MACRO_spawn(108,340);  // spawn(write/1)
    case 340:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,341);  // spawn(write/1)
    case 341:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 342:  // test_append2/0
      MACRO_goal(342,atom(202));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_value(reg::x(1),reg::out(3));
      MACRO_spawn(224,343);  // spawn(append/3)
    case 343:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,344);  // spawn(write/1)
    case 344:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(200),reg::out(1));
      MACRO_spawn(108,345);  // spawn(write/1)
    case 345:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(57),reg::out(1));
      MACRO_spawn(108,346);  // spawn(write/1)
    case 346:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,347);  // spawn(write/1)
    case 347:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(203),reg::out(1));
      MACRO_spawn(108,348);  // spawn(write/1)
    case 348:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 349:  // test_append3/0
      MACRO_goal(349,atom(204));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
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
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_value(reg::x(2),reg::out(3));
      MACRO_spawn(224,350);  // spawn(append/3)
    case 350:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_constant(atom(57),reg::out(1));
      MACRO_spawn(108,351);  // spawn(write/1)
    case 351:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,352);  // spawn(write/1)
    case 352:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(205),reg::out(1));
      MACRO_spawn(108,353);  // spawn(write/1)
    case 353:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,354);  // spawn(write/1)
    case 354:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(206),reg::out(1));
      MACRO_spawn(108,355);  // spawn(write/1)
    case 355:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 356:  // test_reverse/0
      MACRO_goal(356,atom(207));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(232,357);  // spawn(reverse/2)
    case 357:  // return_from_spawn(reverse/2)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 358:  // test_nth0/0
      MACRO_goal(358,atom(208));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(360,359);  // spawn(test_nth0_/0)
    case 359:  // return_from_spawn(test_nth0_/0)
      MACRO_tail(2);
      MACRO_execute(379,0);  // execute(test_nth0_rev_/0)
    case 360:  // test_nth0_/0
      MACRO_goal(360,atom(209));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,361);  // spawn(nth0/3)
    case 361:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(210),reg::out(1));
      MACRO_spawn(108,362);  // spawn(write/1)
    case 362:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,363);  // spawn(write/1)
    case 363:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,364);  // spawn(nth0/3)
    case 364:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(211),reg::out(1));
      MACRO_spawn(108,365);  // spawn(write/1)
    case 365:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,366);  // spawn(write/1)
    case 366:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,367);  // spawn(nth0/3)
    case 367:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(212),reg::out(1));
      MACRO_spawn(108,368);  // spawn(write/1)
    case 368:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,369);  // spawn(write/1)
    case 369:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,370);  // spawn(nth0/3)
    case 370:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,371);  // spawn(write/1)
    case 371:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,372);  // spawn(write/1)
    case 372:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,373);  // spawn(nth0/3)
    case 373:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(214),reg::out(1));
      MACRO_spawn(108,374);  // spawn(write/1)
    case 374:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,375);  // spawn(write/1)
    case 375:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(238,376);  // spawn(nth0/3)
    case 376:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(215),reg::out(1));
      MACRO_spawn(108,377);  // spawn(write/1)
    case 377:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,378);  // spawn(write/1)
    case 378:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 379:  // test_nth0_rev_/0
      MACRO_goal(379,atom(216));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(144),reg::out(3));
      MACRO_spawn(238,380);  // spawn(nth0/3)
    case 380:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,381);  // spawn(write/1)
    case 381:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,382);  // spawn(write/1)
    case 382:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(218),reg::out(1));
      MACRO_spawn(108,383);  // spawn(write/1)
    case 383:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(145),reg::out(3));
      MACRO_spawn(238,384);  // spawn(nth0/3)
    case 384:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,385);  // spawn(write/1)
    case 385:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,386);  // spawn(write/1)
    case 386:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(219),reg::out(1));
      MACRO_spawn(108,387);  // spawn(write/1)
    case 387:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(180),reg::out(3));
      MACRO_spawn(238,388);  // spawn(nth0/3)
    case 388:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,389);  // spawn(write/1)
    case 389:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,390);  // spawn(write/1)
    case 390:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(220),reg::out(1));
      MACRO_spawn(108,391);  // spawn(write/1)
    case 391:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(181),reg::out(3));
      MACRO_spawn(238,392);  // spawn(nth0/3)
    case 392:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,393);  // spawn(write/1)
    case 393:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,394);  // spawn(write/1)
    case 394:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(221),reg::out(1));
      MACRO_spawn(108,395);  // spawn(write/1)
    case 395:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(182),reg::out(3));
      MACRO_spawn(238,396);  // spawn(nth0/3)
    case 396:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,397);  // spawn(write/1)
    case 397:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,398);  // spawn(write/1)
    case 398:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(222),reg::out(1));
      MACRO_spawn(108,399);  // spawn(write/1)
    case 399:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(183),reg::out(3));
      MACRO_spawn(238,400);  // spawn(nth0/3)
    case 400:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,401);  // spawn(write/1)
    case 401:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,402);  // spawn(write/1)
    case 402:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(223),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 403:  // test_nth1/0
      MACRO_goal(403,atom(224));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(405,404);  // spawn(test_nth1_/0)
    case 404:  // return_from_spawn(test_nth1_/0)
      MACRO_tail(2);
      MACRO_execute(421,0);  // execute(test_nth1_rev_/0)
    case 405:  // test_nth1_/0
      MACRO_goal(405,atom(225));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(248,406);  // spawn(nth1/3)
    case 406:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(226),reg::out(1));
      MACRO_spawn(108,407);  // spawn(write/1)
    case 407:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,408);  // spawn(write/1)
    case 408:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(248,409);  // spawn(nth1/3)
    case 409:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(212),reg::out(1));
      MACRO_spawn(108,410);  // spawn(write/1)
    case 410:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,411);  // spawn(write/1)
    case 411:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(248,412);  // spawn(nth1/3)
    case 412:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,413);  // spawn(write/1)
    case 413:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,414);  // spawn(write/1)
    case 414:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(248,415);  // spawn(nth1/3)
    case 415:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(214),reg::out(1));
      MACRO_spawn(108,416);  // spawn(write/1)
    case 416:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,417);  // spawn(write/1)
    case 417:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(248,418);  // spawn(nth1/3)
    case 418:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(215),reg::out(1));
      MACRO_spawn(108,419);  // spawn(write/1)
    case 419:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,420);  // spawn(write/1)
    case 420:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 421:  // test_nth1_rev_/0
      MACRO_goal(421,atom(227));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(144));
      MACRO_unify_list;
      MACRO_unify_constant(atom(145));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_list;
      MACRO_unify_constant(atom(181));
      MACRO_unify_list;
      MACRO_unify_constant(atom(182));
      MACRO_unify_list;
      MACRO_unify_constant(atom(183));
      MACRO_unify_list;
      MACRO_unify_constant(atom(184));
      MACRO_unify_list;
      MACRO_unify_constant(atom(185));
      MACRO_unify_list;
      MACRO_unify_constant(atom(186));
      MACRO_unify_list;
      MACRO_unify_constant(atom(187));
      MACRO_unify_list;
      MACRO_unify_constant(atom(188));
      MACRO_unify_list;
      MACRO_unify_constant(atom(189));
      MACRO_unify_list;
      MACRO_unify_constant(atom(190));
      MACRO_unify_list;
      MACRO_unify_constant(atom(191));
      MACRO_unify_list;
      MACRO_unify_constant(atom(192));
      MACRO_unify_list;
      MACRO_unify_constant(atom(193));
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(144),reg::out(3));
      MACRO_spawn(248,422);  // spawn(nth1/3)
    case 422:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,423);  // spawn(write/1)
    case 423:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,424);  // spawn(write/1)
    case 424:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(218),reg::out(1));
      MACRO_spawn(108,425);  // spawn(write/1)
    case 425:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(145),reg::out(3));
      MACRO_spawn(248,426);  // spawn(nth1/3)
    case 426:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,427);  // spawn(write/1)
    case 427:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,428);  // spawn(write/1)
    case 428:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(219),reg::out(1));
      MACRO_spawn(108,429);  // spawn(write/1)
    case 429:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(180),reg::out(3));
      MACRO_spawn(248,430);  // spawn(nth1/3)
    case 430:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,431);  // spawn(write/1)
    case 431:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,432);  // spawn(write/1)
    case 432:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(220),reg::out(1));
      MACRO_spawn(108,433);  // spawn(write/1)
    case 433:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(181),reg::out(3));
      MACRO_spawn(248,434);  // spawn(nth1/3)
    case 434:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,435);  // spawn(write/1)
    case 435:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,436);  // spawn(write/1)
    case 436:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(221),reg::out(1));
      MACRO_spawn(108,437);  // spawn(write/1)
    case 437:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(182),reg::out(3));
      MACRO_spawn(248,438);  // spawn(nth1/3)
    case 438:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,439);  // spawn(write/1)
    case 439:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,440);  // spawn(write/1)
    case 440:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(222),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 441:  // test_splice_suspension/0
      MACRO_goal(441,atom(228));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(446,442);  // spawn(test_splice_suspension1/1)
    case 442:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(446,443);  // spawn(test_splice_suspension1/1)
    case 443:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_spawn(446,444);  // spawn(test_splice_suspension1/1)
    case 444:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_get_value(reg::x(2),reg::x(1));
      MACRO_get_value(reg::x(3),reg::x(2));
      MACRO_par(4);
      MACRO_out_constant(atom(229),reg::out(1));
      MACRO_spawn(258,445);  // spawn(dump_to_dot/1)
    case 445:  // return_from_spawn(dump_to_dot/1)
      MACRO_get_constant(atom(228),reg::x(1));
      MACRO_proceed;
    case 446:  // test_splice_suspension1/1
      MACRO_goal(446,atom(230));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 447:  // test_calc/0
      MACRO_goal(447,atom(231));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(232),reg::out(1));
      MACRO_spawn(100,448);  // spawn(writeln/1)
    case 448:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_call(180,449);  // call(__sub__/3)
    case 449:  // return_from_call(__sub__/3)
      MACRO_par(3);
      MACRO_out_constant(atom(233),reg::out(1));
      MACRO_spawn(100,450);  // spawn(writeln/1)
    case 450:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_structure(atom(83),reg::out(1));
      MACRO_write_value(reg::x(2));
      MACRO_write_structure(atom(85));
      MACRO_write_value(reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(100,451);  // spawn(writeln/1)
    case 451:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_constant(atom(234),reg::out(1));
      MACRO_spawn(258,452);  // spawn(dump_to_dot/1)
    case 452:  // return_from_spawn(dump_to_dot/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_call(174,453);  // call(__add__/3)
    case 453:  // return_from_call(__add__/3)
      MACRO_par(3);
      MACRO_out_structure(atom(83),reg::out(1));
      MACRO_write_value(reg::x(2));
      MACRO_write_structure(atom(84));
      MACRO_write_value(reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(100,454);  // spawn(writeln/1)
    case 454:  // return_from_spawn(writeln/1)
      MACRO_par(3);
      MACRO_out_constant(atom(235),reg::out(1));
      MACRO_spawn(100,455);  // spawn(writeln/1)
    case 455:  // return_from_spawn(writeln/1)
      MACRO_get_constant(tagvalue<TAG_INT>(10),reg::x(1));
      MACRO_proceed;
    case 456:  // do_test/1
      MACRO_goal(456,atom(236));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(108,457);  // call(write/1)
    case 457:  // return_from_call(write/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(237),reg::out(1));
      MACRO_call(100,458);  // call(writeln/1)
    case 458:  // return_from_call(writeln/1)
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(4,1);  // execute(time/1)
    case 459:  // main/1
      MACRO_goal(459,atom(238));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_constant(atom(121),reg::out(1));
      MACRO_call(456,460);  // call(do_test/1)
    case 460:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(125),reg::out(1));
      MACRO_call(456,461);  // call(do_test/1)
    case 461:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(126),reg::out(1));
      MACRO_call(456,462);  // call(do_test/1)
    case 462:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(128),reg::out(1));
      MACRO_call(456,463);  // call(do_test/1)
    case 463:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(129),reg::out(1));
      MACRO_call(456,464);  // call(do_test/1)
    case 464:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(134),reg::out(1));
      MACRO_call(456,465);  // call(do_test/1)
    case 465:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(135),reg::out(1));
      MACRO_call(456,466);  // call(do_test/1)
    case 466:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(136),reg::out(1));
      MACRO_call(456,467);  // call(do_test/1)
    case 467:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(137),reg::out(1));
      MACRO_call(456,468);  // call(do_test/1)
    case 468:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_call(456,469);  // call(do_test/1)
    case 469:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(143),reg::out(1));
      MACRO_call(456,470);  // call(do_test/1)
    case 470:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(151),reg::out(1));
      MACRO_call(456,471);  // call(do_test/1)
    case 471:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(155),reg::out(1));
      MACRO_call(456,472);  // call(do_test/1)
    case 472:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(160),reg::out(1));
      MACRO_call(456,473);  // call(do_test/1)
    case 473:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(164),reg::out(1));
      MACRO_call(456,474);  // call(do_test/1)
    case 474:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(175),reg::out(1));
      MACRO_call(456,475);  // call(do_test/1)
    case 475:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(195),reg::out(1));
      MACRO_call(456,476);  // call(do_test/1)
    case 476:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(198),reg::out(1));
      MACRO_call(456,477);  // call(do_test/1)
    case 477:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(207),reg::out(1));
      MACRO_call(456,478);  // call(do_test/1)
    case 478:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(208),reg::out(1));
      MACRO_call(456,479);  // call(do_test/1)
    case 479:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(224),reg::out(1));
      MACRO_call(456,480);  // call(do_test/1)
    case 480:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(228),reg::out(1));
      MACRO_call(456,481);  // call(do_test/1)
    case 481:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(231),reg::out(1));
      MACRO_call(456,482);  // call(do_test/1)
    case 482:  // return_from_call(do_test/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(254,483);  // spawn(inference_count/1)
    case 483:  // return_from_spawn(inference_count/1)
      MACRO_par(3);
      MACRO_out_constant(atom(239),reg::out(1));
      MACRO_spawn(108,484);  // spawn(write/1)
    case 484:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
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
  atom(18) = to_atom("atom_chars", 2);
  atom(19) = to_atom("__atom_to_chars__", 2);
  atom(20) = to_atom("__chars_to_atom__", 3);
  atom(21) = to_atom("atom_number", 2);
  atom(22) = to_atom("__atom_to_number__", 2);
  atom(23) = to_atom("__number_to_atom__", 2);
  atom(24) = to_atom("outstream", 1);
  atom(25) = to_atom("outstream", 2);
  atom(26) = to_atom("open", 3);
  atom(27) = to_atom("write", 2);
  atom(28) = to_atom("write", 1);
  atom(29) = to_atom("writeln", 2);
  atom(30) = to_atom("writeln", 1);
  atom(31) = to_atom("nl", 1);
  atom(32) = to_atom("nl", 0);
  atom(33) = to_atom("close", 1);
  atom(34) = to_atom("__open_opt_string_to_integer__", 3);
  atom(35) = to_atom("__open_opt_string_to_integer__", 5);
  atom(36) = to_atom("rdonly", 0);
  atom(37) = to_atom("wronly", 0);
  atom(38) = to_atom("rdwr", 0);
  atom(39) = to_atom("creat", 0);
  atom(40) = to_atom("excl", 0);
  atom(41) = to_atom("trunc", 0);
  atom(42) = to_atom("append", 0);
  atom(43) = to_atom("rusr", 0);
  atom(44) = to_atom("wusr", 0);
  atom(45) = to_atom("xusr", 0);
  atom(46) = to_atom("rgrp", 0);
  atom(47) = to_atom("wgrp", 0);
  atom(48) = to_atom("xgrp", 0);
  atom(49) = to_atom("roth", 0);
  atom(50) = to_atom("woth", 0);
  atom(51) = to_atom("xoth", 0);
  atom(52) = to_atom("__open__", 4);
  atom(53) = to_atom("__close__", 1);
  atom(54) = to_atom("__nl__", 1);
  atom(55) = to_atom("__write__", 2);
  atom(56) = to_atom("[]", 0);
  atom(57) = to_atom("[", 0);
  atom(58) = to_atom("]", 0);
  atom(59) = to_atom("__write_functor_args__", 2);
  atom(60) = to_atom("(", 0);
  atom(61) = to_atom(")", 0);
  atom(62) = to_atom("__write_functor_args2__", 2);
  atom(63) = to_atom("__write_functor_tail__", 2);
  atom(64) = to_atom(",", 0);
  atom(65) = to_atom("__write_list_tail__", 2);
  atom(66) = to_atom("|", 0);
  atom(67) = to_atom("__write_number__", 2);
  atom(68) = to_atom("__write_atom__", 2);
  atom(69) = to_atom("__write_var__", 2);
  atom(70) = to_atom("integer", 1);
  atom(71) = to_atom("atom", 1);
  atom(72) = to_atom("var", 1);
  atom(73) = to_atom("is_functor", 1);
  atom(74) = to_atom("=..", 2);
  atom(75) = to_atom("==", 2);
  atom(76) = to_atom(">=", 2);
  atom(77) = to_atom("=<", 2);
  atom(78) = to_atom(">", 2);
  atom(79) = to_atom("<", 2);
  atom(80) = to_atom("=:=", 2);
  atom(81) = to_atom("=\\=", 2);
  atom(82) = to_atom("__not_equal__", 2);
  atom(83) = to_atom(":=", 2);
  atom(84) = to_atom("+", 2);
  atom(85) = to_atom("-", 2);
  atom(86) = to_atom("*", 2);
  atom(87) = to_atom("/", 2);
  atom(88) = to_atom("mod", 2);
  atom(89) = to_atom("-", 1);
  atom(90) = to_atom("__add__", 3);
  atom(91) = to_atom("__sub__", 3);
  atom(92) = to_atom("__mul__", 3);
  atom(93) = to_atom("__div__", 3);
  atom(94) = to_atom("__mod__", 3);
  atom(95) = to_atom("__neg__", 2);
  atom(96) = to_atom("__ineg__", 2);
  atom(97) = to_atom("__iadd__", 3);
  atom(98) = to_atom("__isub__", 3);
  atom(99) = to_atom("__imul__", 3);
  atom(100) = to_atom("__idiv__", 3);
  atom(101) = to_atom("__imod__", 3);
  atom(102) = to_atom("__inc__", 2);
  atom(103) = to_atom("__dec__", 2);
  atom(104) = to_atom("__iinc__", 2);
  atom(105) = to_atom("__idec__", 2);
  atom(106) = to_atom("append", 3);
  atom(107) = to_atom("reverse", 2);
  atom(108) = to_atom("__reverse__", 3);
  atom(109) = to_atom("nth0", 3);
  atom(110) = to_atom("__nth0__", 3);
  atom(111) = to_atom("__nth0_rev__", 4);
  atom(112) = to_atom("nth1", 3);
  atom(113) = to_atom("inference_count", 1);
  atom(114) = to_atom("__inference_count__", 1);
  atom(115) = to_atom("resume_count", 1);
  atom(116) = to_atom("__resume_count__", 1);
  atom(117) = to_atom("dump_to_dot", 1);
  atom(118) = to_atom("__dump_to_dot__", 1);
  atom(119) = to_atom("dump_to_dot", 2);
  atom(120) = to_atom("__dump_to_dot__", 2);
  atom(121) = to_atom("test_otherwise", 0);
  atom(122) = to_atom("test_otherwise_aux", 1);
  atom(123) = to_atom("test failed", 0);
  atom(124) = to_atom("test success", 0);
  atom(125) = to_atom("test_write_var", 0);
  atom(126) = to_atom("test_write_atom", 0);
  atom(127) = to_atom("atom", 0);
  atom(128) = to_atom("test_write_list", 0);
  atom(129) = to_atom("test_write_structure", 0);
  atom(130) = to_atom("some", 3);
  atom(131) = to_atom("structure", 0);
  atom(132) = to_atom("and", 0);
  atom(133) = to_atom("arguments", 0);
  atom(134) = to_atom("test_get_structure", 0);
  atom(135) = to_atom("test_set_structure", 0);
  atom(136) = to_atom("test_get_list", 0);
  atom(137) = to_atom("test_set_list", 0);
  atom(138) = to_atom("test_check_constant", 0);
  atom(139) = to_atom("test_check_constant_aux", 1);
  atom(140) = to_atom("test failed(0)", 0);
  atom(141) = to_atom("test success(1)", 0);
  atom(142) = to_atom("test failed(otherwise)", 0);
  atom(143) = to_atom("test_check_list", 0);
  atom(144) = to_atom("a", 0);
  atom(145) = to_atom("b", 0);
  atom(146) = to_atom("test_check_list_aux", 1);
  atom(147) = to_atom("x", 0);
  atom(148) = to_atom("y", 0);
  atom(149) = to_atom("test failed([x,y])", 0);
  atom(150) = to_atom("test success([a,b])", 0);
  atom(151) = to_atom("test_check_nil", 0);
  atom(152) = to_atom("test_check_nil_aux", 1);
  atom(153) = to_atom("test failed([a,b])", 0);
  atom(154) = to_atom("test success([])", 0);
  atom(155) = to_atom("test_check_structure", 0);
  atom(156) = to_atom("fun", 2);
  atom(157) = to_atom("test_check_structure_aux", 1);
  atom(158) = to_atom("test failed(fun(x,y))", 0);
  atom(159) = to_atom("test success(fun(a,b))", 0);
  atom(160) = to_atom("test_wait_var", 0);
  atom(161) = to_atom("wait_var", 1);
  atom(162) = to_atom("write_var", 1);
  atom(163) = to_atom("fire", 0);
  atom(164) = to_atom("test_atom_concat", 0);
  atom(165) = to_atom("test_atom_concat_1", 0);
  atom(166) = to_atom("abc", 0);
  atom(167) = to_atom("def", 0);
  atom(168) = to_atom("abc + def = ", 0);
  atom(169) = to_atom("test_atom_concat_2", 0);
  atom(170) = to_atom("abcdef", 0);
  atom(171) = to_atom("abc + [", 0);
  atom(172) = to_atom("] = abcdef", 0);
  atom(173) = to_atom("test_atom_concat_3", 0);
  atom(174) = to_atom("] + def = abcdef", 0);
  atom(175) = to_atom("test_atom_chars", 0);
  atom(176) = to_atom("test_atom_chars1", 0);
  atom(177) = to_atom("abcdefgあいうえお漢字☺🍺", 0);
  atom(178) = to_atom(" -> ", 0);
  atom(179) = to_atom("test_atom_chars2", 0);
  atom(180) = to_atom("c", 0);
  atom(181) = to_atom("d", 0);
  atom(182) = to_atom("e", 0);
  atom(183) = to_atom("f", 0);
  atom(184) = to_atom("g", 0);
  atom(185) = to_atom("あ", 0);
  atom(186) = to_atom("い", 0);
  atom(187) = to_atom("う", 0);
  atom(188) = to_atom("え", 0);
  atom(189) = to_atom("お", 0);
  atom(190) = to_atom("漢", 0);
  atom(191) = to_atom("字", 0);
  atom(192) = to_atom("☺", 0);
  atom(193) = to_atom("🍺", 0);
  atom(194) = to_atom(" <- ", 0);
  atom(195) = to_atom("test_atom_codes", 0);
  atom(196) = to_atom("test_atom_codes1", 0);
  atom(197) = to_atom("test_atom_codes2", 0);
  atom(198) = to_atom("test_append", 0);
  atom(199) = to_atom("test_append1", 0);
  atom(200) = to_atom("+", 0);
  atom(201) = to_atom("=[", 0);
  atom(202) = to_atom("test_append2", 0);
  atom(203) = to_atom("]=", 0);
  atom(204) = to_atom("test_append3", 0);
  atom(205) = to_atom("]+", 0);
  atom(206) = to_atom("=", 0);
  atom(207) = to_atom("test_reverse", 0);
  atom(208) = to_atom("test_nth0", 0);
  atom(209) = to_atom("test_nth0_", 0);
  atom(210) = to_atom(" 0: [", 0);
  atom(211) = to_atom("] 1: [", 0);
  atom(212) = to_atom("] 2: [", 0);
  atom(213) = to_atom("] 3: [", 0);
  atom(214) = to_atom("] 4: [", 0);
  atom(215) = to_atom("] 5: [", 0);
  atom(216) = to_atom("test_nth0_rev_", 0);
  atom(217) = to_atom(" [", 0);
  atom(218) = to_atom("]: a", 0);
  atom(219) = to_atom("]: b", 0);
  atom(220) = to_atom("]: c", 0);
  atom(221) = to_atom("]: d", 0);
  atom(222) = to_atom("]: e", 0);
  atom(223) = to_atom("]: f", 0);
  atom(224) = to_atom("test_nth1", 0);
  atom(225) = to_atom("test_nth1_", 0);
  atom(226) = to_atom(" 1: [", 0);
  atom(227) = to_atom("test_nth1_rev_", 0);
  atom(228) = to_atom("test_splice_suspension", 0);
  atom(229) = to_atom("dump/splice.dot", 0);
  atom(230) = to_atom("test_splice_suspension1", 1);
  atom(231) = to_atom("test_calc", 0);
  atom(232) = to_atom("xxx0", 0);
  atom(233) = to_atom("xxx1", 0);
  atom(234) = to_atom("dump/calc.dot", 0);
  atom(235) = to_atom("xxx", 0);
  atom(236) = to_atom("do_test", 1);
  atom(237) = to_atom(": ", 0);
  atom(238) = to_atom("main", 1);
  atom(239) = to_atom("total_inferences=", 0);
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
  prog->add_entry_point(atom(18), 33);  // atom_chars / 2
  prog->add_entry_point(atom(19), 36);  // __atom_to_chars__ / 2
  prog->add_entry_point(atom(20), 37);  // __chars_to_atom__ / 3
  prog->add_entry_point(atom(21), 40);  // atom_number / 2
  prog->add_entry_point(atom(22), 44);  // __atom_to_number__ / 2
  prog->add_entry_point(atom(23), 45);  // __number_to_atom__ / 2
  prog->add_entry_point(atom(24), 46);  // outstream / 1
  prog->add_entry_point(atom(25), 48);  // outstream / 2
  prog->add_entry_point(atom(26), 62);  // open / 3
  prog->add_entry_point(atom(33), 64);  // close / 1
  prog->add_entry_point(atom(34), 65);  // __open_opt_string_to_integer__ / 3
  prog->add_entry_point(atom(35), 66);  // __open_opt_string_to_integer__ / 5
  prog->add_entry_point(atom(52), 98);  // __open__ / 4
  prog->add_entry_point(atom(53), 99);  // __close__ / 1
  prog->add_entry_point(atom(30), 100);  // writeln / 1
  prog->add_entry_point(atom(29), 102);  // writeln / 2
  prog->add_entry_point(atom(32), 104);  // nl / 0
  prog->add_entry_point(atom(31), 105);  // nl / 1
  prog->add_entry_point(atom(54), 107);  // __nl__ / 1
  prog->add_entry_point(atom(28), 108);  // write / 1
  prog->add_entry_point(atom(27), 109);  // write / 2
  prog->add_entry_point(atom(55), 111);  // __write__ / 2
  prog->add_entry_point(atom(59), 126);  // __write_functor_args__ / 2
  prog->add_entry_point(atom(62), 130);  // __write_functor_args2__ / 2
  prog->add_entry_point(atom(63), 133);  // __write_functor_tail__ / 2
  prog->add_entry_point(atom(65), 137);  // __write_list_tail__ / 2
  prog->add_entry_point(atom(67), 146);  // __write_number__ / 2
  prog->add_entry_point(atom(68), 147);  // __write_atom__ / 2
  prog->add_entry_point(atom(69), 148);  // __write_var__ / 2
  prog->add_entry_point(atom(70), 149);  // integer / 1
  prog->add_entry_point(atom(71), 150);  // atom / 1
  prog->add_entry_point(atom(72), 151);  // var / 1
  prog->add_entry_point(atom(73), 152);  // is_functor / 1
  prog->add_entry_point(atom(74), 153);  // =.. / 2
  prog->add_entry_point(atom(75), 154);  // == / 2
  prog->add_entry_point(atom(76), 155);  // >= / 2
  prog->add_entry_point(atom(77), 156);  // =< / 2
  prog->add_entry_point(atom(78), 157);  // > / 2
  prog->add_entry_point(atom(79), 158);  // < / 2
  prog->add_entry_point(atom(80), 159);  // =:= / 2
  prog->add_entry_point(atom(81), 162);  // =\= / 2
  prog->add_entry_point(atom(82), 165);  // __not_equal__ / 2
  prog->add_entry_point(atom(83), 166);  // := / 2
  prog->add_entry_point(atom(90), 174);  // __add__ / 3
  prog->add_entry_point(atom(91), 180);  // __sub__ / 3
  prog->add_entry_point(atom(92), 186);  // __mul__ / 3
  prog->add_entry_point(atom(93), 192);  // __div__ / 3
  prog->add_entry_point(atom(94), 198);  // __mod__ / 3
  prog->add_entry_point(atom(95), 204);  // __neg__ / 2
  prog->add_entry_point(atom(96), 208);  // __ineg__ / 2
  prog->add_entry_point(atom(97), 209);  // __iadd__ / 3
  prog->add_entry_point(atom(98), 210);  // __isub__ / 3
  prog->add_entry_point(atom(99), 211);  // __imul__ / 3
  prog->add_entry_point(atom(100), 212);  // __idiv__ / 3
  prog->add_entry_point(atom(101), 213);  // __imod__ / 3
  prog->add_entry_point(atom(102), 214);  // __inc__ / 2
  prog->add_entry_point(atom(103), 218);  // __dec__ / 2
  prog->add_entry_point(atom(104), 222);  // __iinc__ / 2
  prog->add_entry_point(atom(105), 223);  // __idec__ / 2
  prog->add_entry_point(atom(106), 224);  // append / 3
  prog->add_entry_point(atom(107), 232);  // reverse / 2
  prog->add_entry_point(atom(108), 236);  // __reverse__ / 3
  prog->add_entry_point(atom(109), 238);  // nth0 / 3
  prog->add_entry_point(atom(110), 242);  // __nth0__ / 3
  prog->add_entry_point(atom(111), 245);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(112), 248);  // nth1 / 3
  prog->add_entry_point(atom(113), 254);  // inference_count / 1
  prog->add_entry_point(atom(114), 255);  // __inference_count__ / 1
  prog->add_entry_point(atom(115), 256);  // resume_count / 1
  prog->add_entry_point(atom(116), 257);  // __resume_count__ / 1
  prog->add_entry_point(atom(117), 258);  // dump_to_dot / 1
  prog->add_entry_point(atom(118), 260);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(119), 261);  // dump_to_dot / 2
  prog->add_entry_point(atom(120), 263);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(121), 264);  // test_otherwise / 0
  prog->add_entry_point(atom(122), 266);  // test_otherwise_aux / 1
  prog->add_entry_point(atom(125), 268);  // test_write_var / 0
  prog->add_entry_point(atom(126), 269);  // test_write_atom / 0
  prog->add_entry_point(atom(128), 270);  // test_write_list / 0
  prog->add_entry_point(atom(129), 271);  // test_write_structure / 0
  prog->add_entry_point(atom(134), 272);  // test_get_structure / 0
  prog->add_entry_point(atom(135), 273);  // test_set_structure / 0
  prog->add_entry_point(atom(136), 274);  // test_get_list / 0
  prog->add_entry_point(atom(137), 275);  // test_set_list / 0
  prog->add_entry_point(atom(138), 276);  // test_check_constant / 0
  prog->add_entry_point(atom(139), 277);  // test_check_constant_aux / 1
  prog->add_entry_point(atom(143), 280);  // test_check_list / 0
  prog->add_entry_point(atom(146), 281);  // test_check_list_aux / 1
  prog->add_entry_point(atom(151), 284);  // test_check_nil / 0
  prog->add_entry_point(atom(152), 285);  // test_check_nil_aux / 1
  prog->add_entry_point(atom(155), 288);  // test_check_structure / 0
  prog->add_entry_point(atom(157), 289);  // test_check_structure_aux / 1
  prog->add_entry_point(atom(160), 292);  // test_wait_var / 0
  prog->add_entry_point(atom(161), 294);  // wait_var / 1
  prog->add_entry_point(atom(162), 295);  // write_var / 1
  prog->add_entry_point(atom(164), 296);  // test_atom_concat / 0
  prog->add_entry_point(atom(165), 299);  // test_atom_concat_1 / 0
  prog->add_entry_point(atom(169), 304);  // test_atom_concat_2 / 0
  prog->add_entry_point(atom(173), 308);  // test_atom_concat_3 / 0
  prog->add_entry_point(atom(175), 312);  // test_atom_chars / 0
  prog->add_entry_point(atom(176), 314);  // test_atom_chars1 / 0
  prog->add_entry_point(atom(179), 318);  // test_atom_chars2 / 0
  prog->add_entry_point(atom(195), 322);  // test_atom_codes / 0
  prog->add_entry_point(atom(196), 324);  // test_atom_codes1 / 0
  prog->add_entry_point(atom(197), 328);  // test_atom_codes2 / 0
  prog->add_entry_point(atom(198), 332);  // test_append / 0
  prog->add_entry_point(atom(199), 335);  // test_append1 / 0
  prog->add_entry_point(atom(202), 342);  // test_append2 / 0
  prog->add_entry_point(atom(204), 349);  // test_append3 / 0
  prog->add_entry_point(atom(207), 356);  // test_reverse / 0
  prog->add_entry_point(atom(208), 358);  // test_nth0 / 0
  prog->add_entry_point(atom(209), 360);  // test_nth0_ / 0
  prog->add_entry_point(atom(216), 379);  // test_nth0_rev_ / 0
  prog->add_entry_point(atom(224), 403);  // test_nth1 / 0
  prog->add_entry_point(atom(225), 405);  // test_nth1_ / 0
  prog->add_entry_point(atom(227), 421);  // test_nth1_rev_ / 0
  prog->add_entry_point(atom(228), 441);  // test_splice_suspension / 0
  prog->add_entry_point(atom(230), 446);  // test_splice_suspension1 / 1
  prog->add_entry_point(atom(231), 447);  // test_calc / 0
  prog->add_entry_point(atom(236), 456);  // do_test / 1
  prog->add_entry_point(atom(238), 459);  // main / 1
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
