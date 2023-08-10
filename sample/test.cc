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
Q atom(38);  // + / 2
Q atom(39);  // rdwr / 0
Q atom(40);  // creat / 0
Q atom(41);  // excl / 0
Q atom(42);  // trunc / 0
Q atom(43);  // append / 0
Q atom(44);  // rusr / 0
Q atom(45);  // wusr / 0
Q atom(46);  // xusr / 0
Q atom(47);  // rgrp / 0
Q atom(48);  // wgrp / 0
Q atom(49);  // xgrp / 0
Q atom(50);  // roth / 0
Q atom(51);  // woth / 0
Q atom(52);  // xoth / 0
Q atom(53);  // __open__ / 4
Q atom(54);  // __close__ / 1
Q atom(55);  // __nl__ / 1
Q atom(56);  // __write__ / 2
Q atom(57);  // [] / 0
Q atom(58);  // [ / 0
Q atom(59);  // ] / 0
Q atom(60);  // __write_functor_args__ / 2
Q atom(61);  // ( / 0
Q atom(62);  // ) / 0
Q atom(63);  // __write_functor_args2__ / 2
Q atom(64);  // __write_functor_tail__ / 2
Q atom(65);  // , / 0
Q atom(66);  // __write_list_tail__ / 2
Q atom(67);  // | / 0
Q atom(68);  // __write_number__ / 2
Q atom(69);  // __write_atom__ / 2
Q atom(70);  // __write_var__ / 2
Q atom(71);  // integer / 1
Q atom(72);  // atom / 1
Q atom(73);  // var / 1
Q atom(74);  // is_functor / 1
Q atom(75);  // =.. / 2
Q atom(76);  // == / 2
Q atom(77);  // >= / 2
Q atom(78);  // =< / 2
Q atom(79);  // > / 2
Q atom(80);  // < / 2
Q atom(81);  // =:= / 2
Q atom(82);  // =\= / 2
Q atom(83);  // __not_equal__ / 2
Q atom(84);  // := / 2
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
Q atom(102);  // append / 3
Q atom(103);  // reverse / 2
Q atom(104);  // __reverse__ / 3
Q atom(105);  // nth0 / 3
Q atom(106);  // __nth0__ / 3
Q atom(107);  // __nth0_rev__ / 4
Q atom(108);  // nth1 / 3
Q atom(109);  // inference_count / 1
Q atom(110);  // __inference_count__ / 1
Q atom(111);  // resume_count / 1
Q atom(112);  // __resume_count__ / 1
Q atom(113);  // dump_to_dot / 1
Q atom(114);  // __dump_to_dot__ / 1
Q atom(115);  // dump_to_dot / 2
Q atom(116);  // __dump_to_dot__ / 2
Q atom(117);  // test_otherwise / 0
Q atom(118);  // test_otherwise_aux / 1
Q atom(119);  // test failed / 0
Q atom(120);  // test success / 0
Q atom(121);  // test_write_var / 0
Q atom(122);  // test_write_atom / 0
Q atom(123);  // atom / 0
Q atom(124);  // test_write_list / 0
Q atom(125);  // test_write_structure / 0
Q atom(126);  // some / 3
Q atom(127);  // structure / 0
Q atom(128);  // and / 0
Q atom(129);  // arguments / 0
Q atom(130);  // test_get_structure / 0
Q atom(131);  // test_set_structure / 0
Q atom(132);  // test_get_list / 0
Q atom(133);  // test_set_list / 0
Q atom(134);  // test_check_constant / 0
Q atom(135);  // test_check_constant_aux / 1
Q atom(136);  // test failed(0) / 0
Q atom(137);  // test success(1) / 0
Q atom(138);  // test failed(otherwise) / 0
Q atom(139);  // test_check_list / 0
Q atom(140);  // a / 0
Q atom(141);  // b / 0
Q atom(142);  // test_check_list_aux / 1
Q atom(143);  // x / 0
Q atom(144);  // y / 0
Q atom(145);  // test failed([x,y]) / 0
Q atom(146);  // test success([a,b]) / 0
Q atom(147);  // test_check_nil / 0
Q atom(148);  // test_check_nil_aux / 1
Q atom(149);  // test failed([a,b]) / 0
Q atom(150);  // test success([]) / 0
Q atom(151);  // test_check_structure / 0
Q atom(152);  // fun / 2
Q atom(153);  // test_check_structure_aux / 1
Q atom(154);  // test failed(fun(x,y)) / 0
Q atom(155);  // test success(fun(a,b)) / 0
Q atom(156);  // test_wait_var / 0
Q atom(157);  // wait_var / 1
Q atom(158);  // write_var / 1
Q atom(159);  // fire / 0
Q atom(160);  // test_atom_concat / 0
Q atom(161);  // test_atom_concat_1 / 0
Q atom(162);  // abc / 0
Q atom(163);  // def / 0
Q atom(164);  // abc + def =  / 0
Q atom(165);  // test_atom_concat_2 / 0
Q atom(166);  // abcdef / 0
Q atom(167);  // abc + [ / 0
Q atom(168);  // ] = abcdef / 0
Q atom(169);  // test_atom_concat_3 / 0
Q atom(170);  // ] + def = abcdef / 0
Q atom(171);  // test_atom_chars / 0
Q atom(172);  // test_atom_chars1 / 0
Q atom(173);  // abcdefgあいうえお漢字☺🍺 / 0
Q atom(174);  //  ->  / 0
Q atom(175);  // test_atom_chars2 / 0
Q atom(176);  // c / 0
Q atom(177);  // d / 0
Q atom(178);  // e / 0
Q atom(179);  // f / 0
Q atom(180);  // g / 0
Q atom(181);  // あ / 0
Q atom(182);  // い / 0
Q atom(183);  // う / 0
Q atom(184);  // え / 0
Q atom(185);  // お / 0
Q atom(186);  // 漢 / 0
Q atom(187);  // 字 / 0
Q atom(188);  // ☺ / 0
Q atom(189);  // 🍺 / 0
Q atom(190);  //  <-  / 0
Q atom(191);  // test_atom_codes / 0
Q atom(192);  // test_atom_codes1 / 0
Q atom(193);  // test_atom_codes2 / 0
Q atom(194);  // test_append / 0
Q atom(195);  // test_append1 / 0
Q atom(196);  // + / 0
Q atom(197);  // =[ / 0
Q atom(198);  // test_append2 / 0
Q atom(199);  // ]= / 0
Q atom(200);  // test_append3 / 0
Q atom(201);  // ]+ / 0
Q atom(202);  // = / 0
Q atom(203);  // test_reverse / 0
Q atom(204);  // test_nth0 / 0
Q atom(205);  // test_nth0_ / 0
Q atom(206);  //  0: [ / 0
Q atom(207);  // ] 1: [ / 0
Q atom(208);  // ] 2: [ / 0
Q atom(209);  // ] 3: [ / 0
Q atom(210);  // ] 4: [ / 0
Q atom(211);  // ] 5: [ / 0
Q atom(212);  // test_nth0_rev_ / 0
Q atom(213);  //  [ / 0
Q atom(214);  // ]: a / 0
Q atom(215);  // ]: b / 0
Q atom(216);  // ]: c / 0
Q atom(217);  // ]: d / 0
Q atom(218);  // ]: e / 0
Q atom(219);  // ]: f / 0
Q atom(220);  // test_nth1 / 0
Q atom(221);  // test_nth1_ / 0
Q atom(222);  //  1: [ / 0
Q atom(223);  // test_nth1_rev_ / 0
Q atom(224);  // test_splice_suspension / 0
Q atom(225);  // dump/splice.dot / 0
Q atom(226);  // test_splice_suspension1 / 1
Q atom(227);  // do_test / 1
Q atom(228);  // :  / 0
Q atom(229);  // main / 1
Q atom(230);  // total_inferences= / 0
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
{
  MACRO_wait(reg::in(1));
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
      MACRO_wait(1);
      MACRO_activate;
      MACRO_tail(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(3),reg::out(2));
      MACRO_out_value(reg::in(4),reg::out(3));
      MACRO_execute(11,3);  // execute(__time_post__/3)
    case 10:  // __time_pre__/3
      MACRO_goal(10,atom(7));
      MACRO_requires(7);
{
  MACRO_activate;
  const int64_t istart = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
  MACRO_get_constant(tagvalue<TAG_INT>(istart), reg::in(1));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->inference_count), reg::in(2));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->resume_count), reg::in(3));
  MACRO_proceed;
}
    case 11:  // __time_post__/3
      MACRO_goal(11,atom(8));
      MACRO_requires(7);
{
  MACRO_activate;
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
  MACRO_proceed;
}
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
{
  MACRO_activate;
  const Q q1 = vm->in[1];
  const Q q2 = vm->in[2];
  const std::string s1 = atom_str_of(q1);
  const std::string s2 = atom_str_of(q2);
  const std::string s = s1 + s2;
  const Q c = to_atom(s.c_str(), 0);
  vm->unify(c, vm->in[3]);
  MACRO_proceed;
}
    case 22:  // __atom_concat_2__/3
      MACRO_goal(22,atom(11));
      MACRO_requires(7);
{
  MACRO_activate;
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
  MACRO_proceed;
}
    case 23:  // __atom_concat_3__/3
      MACRO_goal(23,atom(12));
      MACRO_requires(7);
{
  MACRO_activate;
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
  MACRO_proceed;
}
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
{
  MACRO_activate;
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
  MACRO_proceed;
}
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
{
  MACRO_activate;
  const Q q1 = vm->in[1];
  const Q q2 = vm->in[2];
  std::string s = atom_str_of(q1);
  const unsigned char c = value_of<char>(q2);
  s += c;
  vm->unify(to_atom(s.c_str(), 0), vm->in[3]);
  MACRO_proceed;
}
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
{
  MACRO_activate;
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
  MACRO_proceed;
}
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
{
  MACRO_activate;
  const Q q = vm->in[1];
  const std::string s = atom_str_of(q);
  const int64_t i = std::stoll(s);
  MACRO_get_constant(tagvalue<TAG_INT>(i), reg::in(2));
  MACRO_proceed;
}
    case 45:  // __number_to_atom__/2
      MACRO_goal(45,atom(23));
      MACRO_requires(5);
{
  MACRO_activate;
  const Q q = vm->in[2];
  const int64_t i = value_of<int64_t>(q);
  const std::string s = std::to_string(i);
  MACRO_get_constant(to_atom(s.c_str(), 0), reg::in(1));
  MACRO_proceed;
}
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
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(166,69);  // spawn((:=)/2)
    case 69:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(39));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_spawn(166,71);  // spawn((:=)/2)
    case 71:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(40));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(64));
      MACRO_spawn(166,73);  // spawn((:=)/2)
    case 73:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(41));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(128));
      MACRO_spawn(166,75);  // spawn((:=)/2)
    case 75:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(42));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(512));
      MACRO_spawn(166,77);  // spawn((:=)/2)
    case 77:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(43));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(1024));
      MACRO_spawn(166,79);  // spawn((:=)/2)
    case 79:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(44));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(256));
      MACRO_spawn(166,81);  // spawn((:=)/2)
    case 81:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(45));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(128));
      MACRO_spawn(166,83);  // spawn((:=)/2)
    case 83:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(46));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(64));
      MACRO_spawn(166,85);  // spawn((:=)/2)
    case 85:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(47));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(32));
      MACRO_spawn(166,87);  // spawn((:=)/2)
    case 87:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(48));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(16));
      MACRO_spawn(166,89);  // spawn((:=)/2)
    case 89:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(49));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(8));
      MACRO_spawn(166,91);  // spawn((:=)/2)
    case 91:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(50));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(4));
      MACRO_spawn(166,93);  // spawn((:=)/2)
    case 93:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(51));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_spawn(166,95);  // spawn((:=)/2)
    case 95:  // return_from_spawn((:=)/2)
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
      MACRO_read_constant(atom(52));
      MACRO_read_variable(reg::x(6));
      MACRO_activate;
      MACRO_par(8);
      MACRO_out_variable(reg::x(7),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(5));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(166,97);  // spawn((:=)/2)
    case 97:  // return_from_spawn((:=)/2)
      MACRO_tail(8);
      MACRO_out_value(reg::x(6),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::in(4),reg::out(4));
      MACRO_out_value(reg::x(7),reg::out(5));
      MACRO_execute(66,5);  // execute(__open_opt_string_to_integer__/5)
    case 98:  // __open__/4
      MACRO_goal(98,atom(53));
      MACRO_requires(9);
{
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_wait_for(TAG_INT, reg::in(3));
  MACRO_activate;
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
  MACRO_proceed;
}
    case 99:  // __close__/1
      MACRO_goal(99,atom(54));
      MACRO_requires(3);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  const int fd = tagvalue<TAG_INT>(vm->in[1]);
  close(fd);
}
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
      MACRO_goal(107,atom(55));
      MACRO_requires(3);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
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
  MACRO_proceed;
}
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
      MACRO_goal(111,atom(56));
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
      MACRO_out_constant(atom(57),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 118:  // __write__/2-5
      MACRO_try_guard_else(122);
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(58),reg::out(2));
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
      MACRO_out_constant(atom(59),reg::out(2));
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
      MACRO_goal(126,atom(60));
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
      MACRO_out_constant(atom(61),reg::out(2));
      MACRO_call(111,128);  // call(__write__/2)
    case 128:  // return_from_call(__write__/2)
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_call(130,129);  // call(__write_functor_args2__/2)
    case 129:  // return_from_call(__write_functor_args2__/2)
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(62),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 130:  // __write_functor_args2__/2
      MACRO_goal(130,atom(63));
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
      MACRO_goal(133,atom(64));
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
      MACRO_out_constant(atom(65),reg::out(2));
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
      MACRO_goal(137,atom(66));
      MACRO_requires(7);
      MACRO_try_guard_else(140);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,138);  // call(var/1)
    case 138:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_constant(atom(67),reg::out(2));
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
      MACRO_out_constant(atom(65),reg::out(2));
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
      MACRO_out_constant(atom(67),reg::out(2));
      MACRO_call(111,145);  // call(__write__/2)
    case 145:  // return_from_call(__write__/2)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(111,2);  // execute(__write__/2)
    case 146:  // __write_number__/2
      MACRO_goal(146,atom(68));
      MACRO_requires(5);
{
  MACRO_activate;
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
  MACRO_proceed;
}
    case 147:  // __write_atom__/2
      MACRO_goal(147,atom(69));
      MACRO_requires(5);
{
  MACRO_activate;
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
  MACRO_proceed;
}
    case 148:  // __write_var__/2
      MACRO_goal(148,atom(70));
      MACRO_requires(5);
{
  MACRO_activate;
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
  MACRO_proceed;
}
    case 149:  // integer/1
      MACRO_goal(149,atom(71));
      MACRO_requires(3);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
}
    case 150:  // atom/1
      MACRO_goal(150,atom(72));
      MACRO_requires(3);
{
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
}
    case 151:  // var/1
      MACRO_goal(151,atom(73));
      MACRO_requires(3);
{
  const Q q = vm->in[1] = deref(vm->in[1]);
  const TAG_T tag = tag_of(q);
  if (tag != TAG_REF && tag != TAG_SUS) {
    vm->fail();
    continue;
  }
  MACRO_return;
}
    case 152:  // is_functor/1
      MACRO_goal(152,atom(74));
      MACRO_requires(3);
{
  MACRO_wait_for(TAG_STR, reg::in(1));
  const Q q = vm->in[1];
  const TAG_T tag = tag_of(q);
  if (tag != TAG_STR) {
    vm->fail();
    continue;
  }
  MACRO_return;
}
    case 153:  // (=..)/2
      MACRO_goal(153,atom(75));
      MACRO_requires(5);
{
  MACRO_wait_for(TAG_STR, reg::in(1));
  MACRO_activate;
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
  MACRO_proceed;
}
    case 154:  // (==)/2
      MACRO_goal(154,atom(76));
      MACRO_requires(5);
{
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  Q q1 = vm->in[1];
  Q q2 = vm->in[2];
  if (!(q1 == q2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 155:  // (>=)/2
      MACRO_goal(155,atom(77));
      MACRO_requires(5);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  if (!(v1 >= v2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 156:  // (=<)/2
      MACRO_goal(156,atom(78));
      MACRO_requires(5);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  if (!(v1 <= v2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 157:  // (>)/2
      MACRO_goal(157,atom(79));
      MACRO_requires(5);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  if (!(v1 > v2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 158:  // (<)/2
      MACRO_goal(158,atom(80));
      MACRO_requires(5);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  if (!(v1 < v2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 159:  // (=:=)/2
      MACRO_goal(159,atom(81));
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
      MACRO_goal(162,atom(82));
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
      MACRO_goal(165,atom(83));
      MACRO_requires(5);
{
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  Q q1 = vm->in[1];
  Q q2 = vm->in[2];
  if (!(q1 != q2)) {
    MACRO_fail;
  }
  MACRO_return;
}
    case 166:  // (:=)/2
      MACRO_goal(166,atom(84));
      MACRO_requires(8);
      MACRO_try_guard_else(167);
      MACRO_check_structure(atom(38),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(174,3);  // execute(__add__/3)
    case 167:  // (:=)/2-2
      MACRO_try_guard_else(168);
      MACRO_check_structure(atom(85),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(180,3);  // execute(__sub__/3)
    case 168:  // (:=)/2-3
      MACRO_try_guard_else(169);
      MACRO_check_structure(atom(86),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(186,3);  // execute(__mul__/3)
    case 169:  // (:=)/2-4
      MACRO_try_guard_else(170);
      MACRO_check_structure(atom(87),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(192,3);  // execute(__div__/3)
    case 170:  // (:=)/2-5
      MACRO_try_guard_else(171);
      MACRO_check_structure(atom(88),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(1),reg::out(3));
      MACRO_execute(198,3);  // execute(__mod__/3)
    case 171:  // (:=)/2-6
      MACRO_try_guard_else(172);
      MACRO_check_structure(atom(89),reg::in(2));
      MACRO_read_variable(reg::x(3));
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(204,2);  // execute(__neg__/2)
    case 172:  // (:=)/2-7
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(149,173);  // call(integer/1)
    case 173:  // return_from_call(integer/1)
      MACRO_activate;
      MACRO_get_value(reg::in(1),reg::in(2));
      MACRO_proceed;
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
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  const int64_t v = -value_of<int64_t>(reg::in(1));
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(2));
  MACRO_proceed;
}
    case 209:  // __iadd__/3
      MACRO_goal(209,atom(97));
      MACRO_requires(7);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  const int64_t v = v1 + v2;
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  MACRO_proceed;
}
    case 210:  // __isub__/3
      MACRO_goal(210,atom(98));
      MACRO_requires(7);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  const int64_t v = v1 - v2;
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  MACRO_proceed;
}
    case 211:  // __imul__/3
      MACRO_goal(211,atom(99));
      MACRO_requires(7);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  const int64_t v = v1 * v2;
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  MACRO_proceed;
}
    case 212:  // __idiv__/3
      MACRO_goal(212,atom(100));
      MACRO_requires(7);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  const int64_t v = v1 / v2;
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  MACRO_proceed;
}
    case 213:  // __imod__/3
      MACRO_goal(213,atom(101));
      MACRO_requires(7);
{
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
  const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
  const int64_t v = v1 % v2;
  MACRO_get_constant(tagvalue<TAG_INT>(v), reg::in(3));
  MACRO_proceed;
}
    case 214:  // append/3
      MACRO_goal(214,atom(102));
      MACRO_requires(9);
      MACRO_try_guard_else(215);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(2),reg::in(3));
      MACRO_proceed;
    case 215:  // append/3-2
      MACRO_try_guard_else(216);
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
      MACRO_execute(214,3);  // execute(append/3)
    case 216:  // append/3-3
      MACRO_try_guard_else(217);
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
      MACRO_execute(214,3);  // execute(append/3)
    case 217:  // append/3-4
      MACRO_try_guard_else_suspend;
      MACRO_seq(6);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,218);  // call(var/1)
    case 218:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_spawn(222,219);  // spawn(reverse/2)
    case 219:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_out_variable(reg::x(5),reg::out(2));
      MACRO_spawn(222,220);  // spawn(reverse/2)
    case 220:  // return_from_spawn(reverse/2)
      MACRO_par(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_variable(reg::x(4),reg::out(2));
      MACRO_out_value(reg::x(5),reg::out(3));
      MACRO_spawn(214,221);  // spawn(append/3)
    case 221:  // return_from_spawn(append/3)
      MACRO_tail(6);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_execute(222,2);  // execute(reverse/2)
    case 222:  // reverse/2
      MACRO_goal(222,atom(103));
      MACRO_requires(6);
      MACRO_try_guard_else(224);
      MACRO_seq(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_call(151,223);  // call(var/1)
    case 223:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(226,3);  // execute(__reverse__/3)
    case 224:  // reverse/2-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,225);  // call(var/1)
    case 225:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(2),reg::out(1));
      MACRO_out_value(reg::in(1),reg::out(2));
      MACRO_out_nil(reg::out(3));
      MACRO_execute(226,3);  // execute(__reverse__/3)
    case 226:  // __reverse__/3
      MACRO_goal(226,atom(104));
      MACRO_requires(10);
      MACRO_try_guard_else(227);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_get_value(reg::in(3),reg::in(2));
      MACRO_proceed;
    case 227:  // __reverse__/3-2
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
      MACRO_execute(226,3);  // execute(__reverse__/3)
    case 228:  // nth0/3
      MACRO_goal(228,atom(105));
      MACRO_requires(8);
      MACRO_try_guard_else(230);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(151,229);  // call(var/1)
    case 229:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(232,3);  // execute(__nth0__/3)
    case 230:  // nth0/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,231);  // call(var/1)
    case 231:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_execute(235,4);  // execute(__nth0_rev__/4)
    case 232:  // __nth0__/3
      MACRO_goal(232,atom(106));
      MACRO_requires(9);
      MACRO_try_guard_else(233);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_check_list(reg::in(2));
      MACRO_read_variable(reg::x(4));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::x(4),reg::in(3));
      MACRO_proceed;
    case 233:  // __nth0__/3-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(4));
      MACRO_activate;
      MACRO_par(6);
      MACRO_out_variable(reg::x(5),reg::out(1));
      MACRO_out_structure(atom(85),reg::out(2));
      MACRO_write_value(reg::in(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(166,234);  // spawn((:=)/2)
    case 234:  // return_from_spawn((:=)/2)
      MACRO_tail(6);
      MACRO_out_value(reg::x(5),reg::out(1));
      MACRO_out_value(reg::x(4),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(232,3);  // execute(__nth0__/3)
    case 235:  // __nth0_rev__/4
      MACRO_goal(235,atom(107));
      MACRO_requires(11);
      MACRO_try_guard_else(236);
      MACRO_check_list(reg::in(2));
      MACRO_read_value(reg::in(3));
      MACRO_read_void;
      MACRO_activate;
      MACRO_get_value(reg::in(4),reg::in(1));
      MACRO_proceed;
    case 236:  // __nth0_rev__/4-2
      MACRO_otherwise;
      MACRO_check_list(reg::in(2));
      MACRO_read_void;
      MACRO_read_variable(reg::x(5));
      MACRO_activate;
      MACRO_par(7);
      MACRO_out_variable(reg::x(6),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::in(4));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(166,237);  // spawn((:=)/2)
    case 237:  // return_from_spawn((:=)/2)
      MACRO_tail(7);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::x(5),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_value(reg::x(6),reg::out(4));
      MACRO_execute(235,4);  // execute(__nth0_rev__/4)
    case 238:  // nth1/3
      MACRO_goal(238,atom(108));
      MACRO_requires(9);
      MACRO_try_guard_else(241);
      MACRO_seq(5);
      MACRO_out_value(reg::in(3),reg::out(1));
      MACRO_call(151,239);  // call(var/1)
    case 239:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_structure(atom(85),reg::out(2));
      MACRO_write_value(reg::in(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_spawn(166,240);  // spawn((:=)/2)
    case 240:  // return_from_spawn((:=)/2)
      MACRO_tail(5);
      MACRO_out_value(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_execute(232,3);  // execute(__nth0__/3)
    case 241:  // nth1/3-2
      MACRO_try_guard_else_suspend;
      MACRO_seq(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(151,242);  // call(var/1)
    case 242:  // return_from_call(var/1)
      MACRO_activate;
      MACRO_par(5);
      MACRO_out_variable(reg::x(4),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_out_value(reg::in(3),reg::out(3));
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
      MACRO_spawn(235,243);  // spawn(__nth0_rev__/4)
    case 243:  // return_from_spawn(__nth0_rev__/4)
      MACRO_tail(5);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_structure(atom(38),reg::out(2));
      MACRO_write_value(reg::x(4));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_execute(166,2);  // execute((:=)/2)
    case 244:  // inference_count/1
      MACRO_goal(244,atom(109));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(245,1);  // execute(__inference_count__/1)
    case 245:  // __inference_count__/1
      MACRO_goal(245,atom(110));
      MACRO_requires(3);
{
  MACRO_activate;
  vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1]);
  MACRO_proceed;
}
    case 246:  // resume_count/1
      MACRO_goal(246,atom(111));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(247,1);  // execute(__resume_count__/1)
    case 247:  // __resume_count__/1
      MACRO_goal(247,atom(112));
      MACRO_requires(3);
{
  MACRO_activate;
  vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1]);
  MACRO_proceed;
}
    case 248:  // dump_to_dot/1
      MACRO_goal(248,atom(113));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,249);  // call(atom/1)
    case 249:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(250,1);  // execute(__dump_to_dot__/1)
    case 250:  // __dump_to_dot__/1
      MACRO_goal(250,atom(114));
      MACRO_requires(3);
{
  const Q q = vm->in[1];
  const std::string s = atom_str_of(q);
  MACRO_activate;
  vm->dump_to_dot(s);
  MACRO_proceed;
}
    case 251:  // dump_to_dot/2
      MACRO_goal(251,atom(115));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_seq(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(150,252);  // call(atom/1)
    case 252:  // return_from_call(atom/1)
      MACRO_activate;
      MACRO_tail(4);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_out_value(reg::in(2),reg::out(2));
      MACRO_execute(253,2);  // execute(__dump_to_dot__/2)
    case 253:  // __dump_to_dot__/2
      MACRO_goal(253,atom(116));
      MACRO_requires(5);
{
  const Q q1 = vm->in[1];
  const Q q2 = vm->in[2];
  const std::string s = atom_str_of(q1);
  MACRO_activate;
  vm->dump_to_dot(s, q2);
  MACRO_proceed;
}
    case 254:  // test_otherwise/0
      MACRO_goal(254,atom(117));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(256,255);  // spawn(test_otherwise_aux/1)
    case 255:  // return_from_spawn(test_otherwise_aux/1)
      MACRO_get_constant(tagvalue<TAG_INT>(1),reg::x(1));
      MACRO_proceed;
    case 256:  // test_otherwise_aux/1
      MACRO_goal(256,atom(118));
      MACRO_requires(3);
      MACRO_try_guard_else(257);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(119),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 257:  // test_otherwise_aux/1-2
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(120),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 258:  // test_write_var/0
      MACRO_goal(258,atom(121));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 259:  // test_write_atom/0
      MACRO_goal(259,atom(122));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(atom(123),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 260:  // test_write_list/0
      MACRO_goal(260,atom(124));
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
    case 261:  // test_write_structure/0
      MACRO_goal(261,atom(125));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(126),reg::out(1));
      MACRO_write_constant(atom(127));
      MACRO_write_constant(atom(128));
      MACRO_write_constant(atom(129));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 262:  // test_get_structure/0
      MACRO_goal(262,atom(130));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_structure(atom(38),reg::x(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(1));
      MACRO_unify_constant(tagvalue<TAG_INT>(2));
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 263:  // test_set_structure/0
      MACRO_goal(263,atom(131));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_structure(atom(38),reg::x(1));
      MACRO_write_constant(tagvalue<TAG_INT>(1));
      MACRO_write_constant(tagvalue<TAG_INT>(2));
      MACRO_get_variable(reg::x(2),reg::x(1));
      MACRO_tail(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 264:  // test_get_list/0
      MACRO_goal(264,atom(132));
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
    case 265:  // test_set_list/0
      MACRO_goal(265,atom(133));
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
    case 266:  // test_check_constant/0
      MACRO_goal(266,atom(134));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_execute(267,1);  // execute(test_check_constant_aux/1)
    case 267:  // test_check_constant_aux/1
      MACRO_goal(267,atom(135));
      MACRO_requires(3);
      MACRO_try_guard_else(268);
      MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(136),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 268:  // test_check_constant_aux/1-2
      MACRO_try_guard_else(269);
      MACRO_check_constant(tagvalue<TAG_INT>(1),reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(137),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 269:  // test_check_constant_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 270:  // test_check_list/0
      MACRO_goal(270,atom(139));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_list(reg::out(1));
      MACRO_write_constant(atom(140));
      MACRO_write_list;
      MACRO_write_constant(atom(141));
      MACRO_write_nil;
      MACRO_execute(271,1);  // execute(test_check_list_aux/1)
    case 271:  // test_check_list_aux/1
      MACRO_goal(271,atom(142));
      MACRO_requires(3);
      MACRO_try_guard_else(272);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(143));
      MACRO_read_list;
      MACRO_read_constant(atom(144));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(145),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 272:  // test_check_list_aux/1-2
      MACRO_try_guard_else(273);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(140));
      MACRO_read_list;
      MACRO_read_constant(atom(141));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(146),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 273:  // test_check_list_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 274:  // test_check_nil/0
      MACRO_goal(274,atom(147));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_nil(reg::out(1));
      MACRO_execute(275,1);  // execute(test_check_nil_aux/1)
    case 275:  // test_check_nil_aux/1
      MACRO_goal(275,atom(148));
      MACRO_requires(3);
      MACRO_try_guard_else(276);
      MACRO_check_list(reg::in(1));
      MACRO_read_constant(atom(140));
      MACRO_read_list;
      MACRO_read_constant(atom(141));
      MACRO_read_nil;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(149),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 276:  // test_check_nil_aux/1-2
      MACRO_try_guard_else(277);
      MACRO_check_nil(reg::in(1));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(150),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 277:  // test_check_nil_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 278:  // test_check_structure/0
      MACRO_goal(278,atom(151));
      MACRO_requires(2);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_tail(2);
      MACRO_out_structure(atom(152),reg::out(1));
      MACRO_write_constant(atom(140));
      MACRO_write_constant(atom(141));
      MACRO_execute(279,1);  // execute(test_check_structure_aux/1)
    case 279:  // test_check_structure_aux/1
      MACRO_goal(279,atom(153));
      MACRO_requires(3);
      MACRO_try_guard_else(280);
      MACRO_check_structure(atom(152),reg::in(1));
      MACRO_read_constant(atom(143));
      MACRO_read_constant(atom(144));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(154),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 280:  // test_check_structure_aux/1-2
      MACRO_try_guard_else(281);
      MACRO_check_structure(atom(152),reg::in(1));
      MACRO_read_constant(atom(140));
      MACRO_read_constant(atom(141));
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(155),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 281:  // test_check_structure_aux/1-3
      MACRO_otherwise;
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_constant(atom(138),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 282:  // test_wait_var/0
      MACRO_goal(282,atom(156));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(284,283);  // spawn(wait_var/1)
    case 283:  // return_from_spawn(wait_var/1)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(285,1);  // execute(write_var/1)
    case 284:  // wait_var/1
      MACRO_goal(284,atom(157));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(1);
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 285:  // write_var/1
      MACRO_goal(285,atom(158));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_get_constant(atom(159),reg::in(1));
      MACRO_proceed;
    case 286:  // test_atom_concat/0
      MACRO_goal(286,atom(160));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(289,287);  // spawn(test_atom_concat_1/0)
    case 287:  // return_from_spawn(test_atom_concat_1/0)
      MACRO_par(2);
      MACRO_spawn(294,288);  // spawn(test_atom_concat_2/0)
    case 288:  // return_from_spawn(test_atom_concat_2/0)
      MACRO_tail(2);
      MACRO_execute(298,0);  // execute(test_atom_concat_3/0)
    case 289:  // test_atom_concat_1/0
      MACRO_goal(289,atom(161));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(162),reg::out(1));
      MACRO_out_constant(atom(163),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(12,290);  // spawn(atom_concat/3)
    case 290:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(164),reg::out(1));
      MACRO_spawn(108,291);  // spawn(write/1)
    case 291:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_spawn(108,292);  // spawn(write/1)
    case 292:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,293);  // spawn(write/1)
    case 293:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(59),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 294:  // test_atom_concat_2/0
      MACRO_goal(294,atom(165));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_constant(atom(162),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(166),reg::out(3));
      MACRO_spawn(12,295);  // spawn(atom_concat/3)
    case 295:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(167),reg::out(1));
      MACRO_spawn(108,296);  // spawn(write/1)
    case 296:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,297);  // spawn(write/1)
    case 297:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(168),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 298:  // test_atom_concat_3/0
      MACRO_goal(298,atom(169));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_out_constant(atom(163),reg::out(2));
      MACRO_out_constant(atom(166),reg::out(3));
      MACRO_spawn(12,299);  // spawn(atom_concat/3)
    case 299:  // return_from_spawn(atom_concat/3)
      MACRO_par(2);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_spawn(108,300);  // spawn(write/1)
    case 300:  // return_from_spawn(write/1)
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,301);  // spawn(write/1)
    case 301:  // return_from_spawn(write/1)
      MACRO_tail(2);
      MACRO_out_constant(atom(170),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 302:  // test_atom_chars/0
      MACRO_goal(302,atom(171));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(304,303);  // spawn(test_atom_chars1/0)
    case 303:  // return_from_spawn(test_atom_chars1/0)
      MACRO_tail(2);
      MACRO_execute(308,0);  // execute(test_atom_chars2/0)
    case 304:  // test_atom_chars1/0
      MACRO_goal(304,atom(172));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(173),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(33,305);  // spawn(atom_chars/2)
    case 305:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,306);  // spawn(write/1)
    case 306:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(174),reg::out(1));
      MACRO_spawn(108,307);  // spawn(write/1)
    case 307:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 308:  // test_atom_chars2/0
      MACRO_goal(308,atom(175));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_spawn(33,309);  // spawn(atom_chars/2)
    case 309:  // return_from_spawn(atom_chars/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,310);  // spawn(write/1)
    case 310:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(190),reg::out(1));
      MACRO_spawn(108,311);  // spawn(write/1)
    case 311:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 312:  // test_atom_codes/0
      MACRO_goal(312,atom(191));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(314,313);  // spawn(test_atom_codes1/0)
    case 313:  // return_from_spawn(test_atom_codes1/0)
      MACRO_tail(2);
      MACRO_execute(318,0);  // execute(test_atom_codes2/0)
    case 314:  // test_atom_codes1/0
      MACRO_goal(314,atom(192));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_constant(atom(173),reg::x(2));
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(24,315);  // spawn(atom_codes/2)
    case 315:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,316);  // spawn(write/1)
    case 316:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(174),reg::out(1));
      MACRO_spawn(108,317);  // spawn(write/1)
    case 317:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 318:  // test_atom_codes2/0
      MACRO_goal(318,atom(193));
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
      MACRO_spawn(24,319);  // spawn(atom_codes/2)
    case 319:  // return_from_spawn(atom_codes/2)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,320);  // spawn(write/1)
    case 320:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(190),reg::out(1));
      MACRO_spawn(108,321);  // spawn(write/1)
    case 321:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 322:  // test_append/0
      MACRO_goal(322,atom(194));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(325,323);  // spawn(test_append1/0)
    case 323:  // return_from_spawn(test_append1/0)
      MACRO_par(2);
      MACRO_spawn(332,324);  // spawn(test_append2/0)
    case 324:  // return_from_spawn(test_append2/0)
      MACRO_tail(2);
      MACRO_execute(339,0);  // execute(test_append3/0)
    case 325:  // test_append1/0
      MACRO_goal(325,atom(195));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
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
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_value(reg::x(2),reg::out(2));
      MACRO_out_variable(reg::x(3),reg::out(3));
      MACRO_spawn(214,326);  // spawn(append/3)
    case 326:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,327);  // spawn(write/1)
    case 327:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(196),reg::out(1));
      MACRO_spawn(108,328);  // spawn(write/1)
    case 328:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,329);  // spawn(write/1)
    case 329:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(197),reg::out(1));
      MACRO_spawn(108,330);  // spawn(write/1)
    case 330:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,331);  // spawn(write/1)
    case 331:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_constant(atom(59),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 332:  // test_append2/0
      MACRO_goal(332,atom(198));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
      MACRO_unify_list;
      MACRO_unify_constant(atom(180));
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_out_variable(reg::x(3),reg::out(2));
      MACRO_out_value(reg::x(1),reg::out(3));
      MACRO_spawn(214,333);  // spawn(append/3)
    case 333:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,334);  // spawn(write/1)
    case 334:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(196),reg::out(1));
      MACRO_spawn(108,335);  // spawn(write/1)
    case 335:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_spawn(108,336);  // spawn(write/1)
    case 336:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,337);  // spawn(write/1)
    case 337:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(199),reg::out(1));
      MACRO_spawn(108,338);  // spawn(write/1)
    case 338:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 339:  // test_append3/0
      MACRO_goal(339,atom(200));
      MACRO_requires(7);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
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
      MACRO_unify_nil;
      MACRO_set_variable(reg::x(2));
      MACRO_get_list(reg::x(2));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_value(reg::x(2),reg::out(3));
      MACRO_spawn(214,340);  // spawn(append/3)
    case 340:  // return_from_spawn(append/3)
      MACRO_par(4);
      MACRO_out_constant(atom(58),reg::out(1));
      MACRO_spawn(108,341);  // spawn(write/1)
    case 341:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(3),reg::out(1));
      MACRO_spawn(108,342);  // spawn(write/1)
    case 342:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(201),reg::out(1));
      MACRO_spawn(108,343);  // spawn(write/1)
    case 343:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,344);  // spawn(write/1)
    case 344:  // return_from_spawn(write/1)
      MACRO_par(4);
      MACRO_out_constant(atom(202),reg::out(1));
      MACRO_spawn(108,345);  // spawn(write/1)
    case 345:  // return_from_spawn(write/1)
      MACRO_tail(4);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 346:  // test_reverse/0
      MACRO_goal(346,atom(203));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_out_variable(reg::x(1),reg::out(2));
      MACRO_spawn(222,347);  // spawn(reverse/2)
    case 347:  // return_from_spawn(reverse/2)
      MACRO_tail(2);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 348:  // test_nth0/0
      MACRO_goal(348,atom(204));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(350,349);  // spawn(test_nth0_/0)
    case 349:  // return_from_spawn(test_nth0_/0)
      MACRO_tail(2);
      MACRO_execute(369,0);  // execute(test_nth0_rev_/0)
    case 350:  // test_nth0_/0
      MACRO_goal(350,atom(205));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(228,351);  // spawn(nth0/3)
    case 351:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(206),reg::out(1));
      MACRO_spawn(108,352);  // spawn(write/1)
    case 352:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,353);  // spawn(write/1)
    case 353:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(228,354);  // spawn(nth0/3)
    case 354:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(207),reg::out(1));
      MACRO_spawn(108,355);  // spawn(write/1)
    case 355:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,356);  // spawn(write/1)
    case 356:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(228,357);  // spawn(nth0/3)
    case 357:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(208),reg::out(1));
      MACRO_spawn(108,358);  // spawn(write/1)
    case 358:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,359);  // spawn(write/1)
    case 359:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(228,360);  // spawn(nth0/3)
    case 360:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(209),reg::out(1));
      MACRO_spawn(108,361);  // spawn(write/1)
    case 361:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,362);  // spawn(write/1)
    case 362:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(228,363);  // spawn(nth0/3)
    case 363:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(210),reg::out(1));
      MACRO_spawn(108,364);  // spawn(write/1)
    case 364:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,365);  // spawn(write/1)
    case 365:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(228,366);  // spawn(nth0/3)
    case 366:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(211),reg::out(1));
      MACRO_spawn(108,367);  // spawn(write/1)
    case 367:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,368);  // spawn(write/1)
    case 368:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(59),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 369:  // test_nth0_rev_/0
      MACRO_goal(369,atom(212));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(140),reg::out(3));
      MACRO_spawn(228,370);  // spawn(nth0/3)
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
      MACRO_out_constant(atom(214),reg::out(1));
      MACRO_spawn(108,373);  // spawn(write/1)
    case 373:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(141),reg::out(3));
      MACRO_spawn(228,374);  // spawn(nth0/3)
    case 374:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,375);  // spawn(write/1)
    case 375:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,376);  // spawn(write/1)
    case 376:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(215),reg::out(1));
      MACRO_spawn(108,377);  // spawn(write/1)
    case 377:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(176),reg::out(3));
      MACRO_spawn(228,378);  // spawn(nth0/3)
    case 378:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,379);  // spawn(write/1)
    case 379:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,380);  // spawn(write/1)
    case 380:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(216),reg::out(1));
      MACRO_spawn(108,381);  // spawn(write/1)
    case 381:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(177),reg::out(3));
      MACRO_spawn(228,382);  // spawn(nth0/3)
    case 382:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,383);  // spawn(write/1)
    case 383:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,384);  // spawn(write/1)
    case 384:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,385);  // spawn(write/1)
    case 385:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(178),reg::out(3));
      MACRO_spawn(228,386);  // spawn(nth0/3)
    case 386:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,387);  // spawn(write/1)
    case 387:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,388);  // spawn(write/1)
    case 388:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(218),reg::out(1));
      MACRO_spawn(108,389);  // spawn(write/1)
    case 389:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(179),reg::out(3));
      MACRO_spawn(228,390);  // spawn(nth0/3)
    case 390:  // return_from_spawn(nth0/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,391);  // spawn(write/1)
    case 391:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,392);  // spawn(write/1)
    case 392:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(219),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 393:  // test_nth1/0
      MACRO_goal(393,atom(220));
      MACRO_requires(1);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_spawn(395,394);  // spawn(test_nth1_/0)
    case 394:  // return_from_spawn(test_nth1_/0)
      MACRO_tail(2);
      MACRO_execute(411,0);  // execute(test_nth1_rev_/0)
    case 395:  // test_nth1_/0
      MACRO_goal(395,atom(221));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,396);  // spawn(nth1/3)
    case 396:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(222),reg::out(1));
      MACRO_spawn(108,397);  // spawn(write/1)
    case 397:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,398);  // spawn(write/1)
    case 398:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,399);  // spawn(nth1/3)
    case 399:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(208),reg::out(1));
      MACRO_spawn(108,400);  // spawn(write/1)
    case 400:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,401);  // spawn(write/1)
    case 401:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(3),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,402);  // spawn(nth1/3)
    case 402:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(209),reg::out(1));
      MACRO_spawn(108,403);  // spawn(write/1)
    case 403:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,404);  // spawn(write/1)
    case 404:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(2),reg::out(3));
      MACRO_spawn(238,405);  // spawn(nth1/3)
    case 405:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(210),reg::out(1));
      MACRO_spawn(108,406);  // spawn(write/1)
    case 406:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,407);  // spawn(write/1)
    case 407:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(tagvalue<TAG_INT>(5),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_variable(reg::x(1),reg::out(3));
      MACRO_spawn(238,408);  // spawn(nth1/3)
    case 408:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(211),reg::out(1));
      MACRO_spawn(108,409);  // spawn(write/1)
    case 409:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(1),reg::out(1));
      MACRO_spawn(108,410);  // spawn(write/1)
    case 410:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(59),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 411:  // test_nth1_rev_/0
      MACRO_goal(411,atom(223));
      MACRO_requires(6);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_set_variable(reg::x(1));
      MACRO_get_list(reg::x(1));
      MACRO_unify_constant(atom(140));
      MACRO_unify_list;
      MACRO_unify_constant(atom(141));
      MACRO_unify_list;
      MACRO_unify_constant(atom(176));
      MACRO_unify_list;
      MACRO_unify_constant(atom(177));
      MACRO_unify_list;
      MACRO_unify_constant(atom(178));
      MACRO_unify_list;
      MACRO_unify_constant(atom(179));
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
      MACRO_unify_nil;
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(140),reg::out(3));
      MACRO_spawn(238,412);  // spawn(nth1/3)
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
      MACRO_out_constant(atom(214),reg::out(1));
      MACRO_spawn(108,415);  // spawn(write/1)
    case 415:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(141),reg::out(3));
      MACRO_spawn(238,416);  // spawn(nth1/3)
    case 416:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,417);  // spawn(write/1)
    case 417:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,418);  // spawn(write/1)
    case 418:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(215),reg::out(1));
      MACRO_spawn(108,419);  // spawn(write/1)
    case 419:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(176),reg::out(3));
      MACRO_spawn(238,420);  // spawn(nth1/3)
    case 420:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,421);  // spawn(write/1)
    case 421:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,422);  // spawn(write/1)
    case 422:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(216),reg::out(1));
      MACRO_spawn(108,423);  // spawn(write/1)
    case 423:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(177),reg::out(3));
      MACRO_spawn(238,424);  // spawn(nth1/3)
    case 424:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,425);  // spawn(write/1)
    case 425:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,426);  // spawn(write/1)
    case 426:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_constant(atom(217),reg::out(1));
      MACRO_spawn(108,427);  // spawn(write/1)
    case 427:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_out_value(reg::x(1),reg::out(2));
      MACRO_out_constant(atom(178),reg::out(3));
      MACRO_spawn(238,428);  // spawn(nth1/3)
    case 428:  // return_from_spawn(nth1/3)
      MACRO_par(3);
      MACRO_out_constant(atom(213),reg::out(1));
      MACRO_spawn(108,429);  // spawn(write/1)
    case 429:  // return_from_spawn(write/1)
      MACRO_par(3);
      MACRO_out_value(reg::x(2),reg::out(1));
      MACRO_spawn(108,430);  // spawn(write/1)
    case 430:  // return_from_spawn(write/1)
      MACRO_tail(3);
      MACRO_out_constant(atom(218),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 431:  // test_splice_suspension/0
      MACRO_goal(431,atom(224));
      MACRO_requires(5);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_par(2);
      MACRO_out_variable(reg::x(1),reg::out(1));
      MACRO_spawn(436,432);  // spawn(test_splice_suspension1/1)
    case 432:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(436,433);  // spawn(test_splice_suspension1/1)
    case 433:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_par(4);
      MACRO_out_variable(reg::x(3),reg::out(1));
      MACRO_spawn(436,434);  // spawn(test_splice_suspension1/1)
    case 434:  // return_from_spawn(test_splice_suspension1/1)
      MACRO_get_value(reg::x(2),reg::x(1));
      MACRO_get_value(reg::x(3),reg::x(2));
      MACRO_par(4);
      MACRO_out_constant(atom(225),reg::out(1));
      MACRO_spawn(248,435);  // spawn(dump_to_dot/1)
    case 435:  // return_from_spawn(dump_to_dot/1)
      MACRO_get_constant(atom(224),reg::x(1));
      MACRO_proceed;
    case 436:  // test_splice_suspension1/1
      MACRO_goal(436,atom(226));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_wait(1);
      MACRO_activate;
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(100,1);  // execute(writeln/1)
    case 437:  // do_test/1
      MACRO_goal(437,atom(227));
      MACRO_requires(3);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_call(108,438);  // call(write/1)
    case 438:  // return_from_call(write/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(228),reg::out(1));
      MACRO_call(100,439);  // call(writeln/1)
    case 439:  // return_from_call(writeln/1)
      MACRO_tail(3);
      MACRO_out_value(reg::in(1),reg::out(1));
      MACRO_execute(4,1);  // execute(time/1)
    case 440:  // main/1
      MACRO_goal(440,atom(229));
      MACRO_requires(4);
      MACRO_try_guard_else_suspend;
      MACRO_activate;
      MACRO_seq(3);
      MACRO_out_constant(atom(117),reg::out(1));
      MACRO_call(437,441);  // call(do_test/1)
    case 441:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(121),reg::out(1));
      MACRO_call(437,442);  // call(do_test/1)
    case 442:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(122),reg::out(1));
      MACRO_call(437,443);  // call(do_test/1)
    case 443:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(124),reg::out(1));
      MACRO_call(437,444);  // call(do_test/1)
    case 444:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(125),reg::out(1));
      MACRO_call(437,445);  // call(do_test/1)
    case 445:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(130),reg::out(1));
      MACRO_call(437,446);  // call(do_test/1)
    case 446:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(131),reg::out(1));
      MACRO_call(437,447);  // call(do_test/1)
    case 447:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(132),reg::out(1));
      MACRO_call(437,448);  // call(do_test/1)
    case 448:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(133),reg::out(1));
      MACRO_call(437,449);  // call(do_test/1)
    case 449:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(134),reg::out(1));
      MACRO_call(437,450);  // call(do_test/1)
    case 450:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(139),reg::out(1));
      MACRO_call(437,451);  // call(do_test/1)
    case 451:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(147),reg::out(1));
      MACRO_call(437,452);  // call(do_test/1)
    case 452:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(151),reg::out(1));
      MACRO_call(437,453);  // call(do_test/1)
    case 453:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(156),reg::out(1));
      MACRO_call(437,454);  // call(do_test/1)
    case 454:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(160),reg::out(1));
      MACRO_call(437,455);  // call(do_test/1)
    case 455:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(171),reg::out(1));
      MACRO_call(437,456);  // call(do_test/1)
    case 456:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(191),reg::out(1));
      MACRO_call(437,457);  // call(do_test/1)
    case 457:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(194),reg::out(1));
      MACRO_call(437,458);  // call(do_test/1)
    case 458:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(203),reg::out(1));
      MACRO_call(437,459);  // call(do_test/1)
    case 459:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(204),reg::out(1));
      MACRO_call(437,460);  // call(do_test/1)
    case 460:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(220),reg::out(1));
      MACRO_call(437,461);  // call(do_test/1)
    case 461:  // return_from_call(do_test/1)
      MACRO_seq(3);
      MACRO_out_constant(atom(224),reg::out(1));
      MACRO_call(437,462);  // call(do_test/1)
    case 462:  // return_from_call(do_test/1)
      MACRO_par(3);
      MACRO_out_variable(reg::x(2),reg::out(1));
      MACRO_spawn(244,463);  // spawn(inference_count/1)
    case 463:  // return_from_spawn(inference_count/1)
      MACRO_par(3);
      MACRO_out_constant(atom(230),reg::out(1));
      MACRO_spawn(108,464);  // spawn(write/1)
    case 464:  // return_from_spawn(write/1)
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
  atom(38) = to_atom("+", 2);
  atom(39) = to_atom("rdwr", 0);
  atom(40) = to_atom("creat", 0);
  atom(41) = to_atom("excl", 0);
  atom(42) = to_atom("trunc", 0);
  atom(43) = to_atom("append", 0);
  atom(44) = to_atom("rusr", 0);
  atom(45) = to_atom("wusr", 0);
  atom(46) = to_atom("xusr", 0);
  atom(47) = to_atom("rgrp", 0);
  atom(48) = to_atom("wgrp", 0);
  atom(49) = to_atom("xgrp", 0);
  atom(50) = to_atom("roth", 0);
  atom(51) = to_atom("woth", 0);
  atom(52) = to_atom("xoth", 0);
  atom(53) = to_atom("__open__", 4);
  atom(54) = to_atom("__close__", 1);
  atom(55) = to_atom("__nl__", 1);
  atom(56) = to_atom("__write__", 2);
  atom(57) = to_atom("[]", 0);
  atom(58) = to_atom("[", 0);
  atom(59) = to_atom("]", 0);
  atom(60) = to_atom("__write_functor_args__", 2);
  atom(61) = to_atom("(", 0);
  atom(62) = to_atom(")", 0);
  atom(63) = to_atom("__write_functor_args2__", 2);
  atom(64) = to_atom("__write_functor_tail__", 2);
  atom(65) = to_atom(",", 0);
  atom(66) = to_atom("__write_list_tail__", 2);
  atom(67) = to_atom("|", 0);
  atom(68) = to_atom("__write_number__", 2);
  atom(69) = to_atom("__write_atom__", 2);
  atom(70) = to_atom("__write_var__", 2);
  atom(71) = to_atom("integer", 1);
  atom(72) = to_atom("atom", 1);
  atom(73) = to_atom("var", 1);
  atom(74) = to_atom("is_functor", 1);
  atom(75) = to_atom("=..", 2);
  atom(76) = to_atom("==", 2);
  atom(77) = to_atom(">=", 2);
  atom(78) = to_atom("=<", 2);
  atom(79) = to_atom(">", 2);
  atom(80) = to_atom("<", 2);
  atom(81) = to_atom("=:=", 2);
  atom(82) = to_atom("=\\=", 2);
  atom(83) = to_atom("__not_equal__", 2);
  atom(84) = to_atom(":=", 2);
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
  atom(102) = to_atom("append", 3);
  atom(103) = to_atom("reverse", 2);
  atom(104) = to_atom("__reverse__", 3);
  atom(105) = to_atom("nth0", 3);
  atom(106) = to_atom("__nth0__", 3);
  atom(107) = to_atom("__nth0_rev__", 4);
  atom(108) = to_atom("nth1", 3);
  atom(109) = to_atom("inference_count", 1);
  atom(110) = to_atom("__inference_count__", 1);
  atom(111) = to_atom("resume_count", 1);
  atom(112) = to_atom("__resume_count__", 1);
  atom(113) = to_atom("dump_to_dot", 1);
  atom(114) = to_atom("__dump_to_dot__", 1);
  atom(115) = to_atom("dump_to_dot", 2);
  atom(116) = to_atom("__dump_to_dot__", 2);
  atom(117) = to_atom("test_otherwise", 0);
  atom(118) = to_atom("test_otherwise_aux", 1);
  atom(119) = to_atom("test failed", 0);
  atom(120) = to_atom("test success", 0);
  atom(121) = to_atom("test_write_var", 0);
  atom(122) = to_atom("test_write_atom", 0);
  atom(123) = to_atom("atom", 0);
  atom(124) = to_atom("test_write_list", 0);
  atom(125) = to_atom("test_write_structure", 0);
  atom(126) = to_atom("some", 3);
  atom(127) = to_atom("structure", 0);
  atom(128) = to_atom("and", 0);
  atom(129) = to_atom("arguments", 0);
  atom(130) = to_atom("test_get_structure", 0);
  atom(131) = to_atom("test_set_structure", 0);
  atom(132) = to_atom("test_get_list", 0);
  atom(133) = to_atom("test_set_list", 0);
  atom(134) = to_atom("test_check_constant", 0);
  atom(135) = to_atom("test_check_constant_aux", 1);
  atom(136) = to_atom("test failed(0)", 0);
  atom(137) = to_atom("test success(1)", 0);
  atom(138) = to_atom("test failed(otherwise)", 0);
  atom(139) = to_atom("test_check_list", 0);
  atom(140) = to_atom("a", 0);
  atom(141) = to_atom("b", 0);
  atom(142) = to_atom("test_check_list_aux", 1);
  atom(143) = to_atom("x", 0);
  atom(144) = to_atom("y", 0);
  atom(145) = to_atom("test failed([x,y])", 0);
  atom(146) = to_atom("test success([a,b])", 0);
  atom(147) = to_atom("test_check_nil", 0);
  atom(148) = to_atom("test_check_nil_aux", 1);
  atom(149) = to_atom("test failed([a,b])", 0);
  atom(150) = to_atom("test success([])", 0);
  atom(151) = to_atom("test_check_structure", 0);
  atom(152) = to_atom("fun", 2);
  atom(153) = to_atom("test_check_structure_aux", 1);
  atom(154) = to_atom("test failed(fun(x,y))", 0);
  atom(155) = to_atom("test success(fun(a,b))", 0);
  atom(156) = to_atom("test_wait_var", 0);
  atom(157) = to_atom("wait_var", 1);
  atom(158) = to_atom("write_var", 1);
  atom(159) = to_atom("fire", 0);
  atom(160) = to_atom("test_atom_concat", 0);
  atom(161) = to_atom("test_atom_concat_1", 0);
  atom(162) = to_atom("abc", 0);
  atom(163) = to_atom("def", 0);
  atom(164) = to_atom("abc + def = ", 0);
  atom(165) = to_atom("test_atom_concat_2", 0);
  atom(166) = to_atom("abcdef", 0);
  atom(167) = to_atom("abc + [", 0);
  atom(168) = to_atom("] = abcdef", 0);
  atom(169) = to_atom("test_atom_concat_3", 0);
  atom(170) = to_atom("] + def = abcdef", 0);
  atom(171) = to_atom("test_atom_chars", 0);
  atom(172) = to_atom("test_atom_chars1", 0);
  atom(173) = to_atom("abcdefgあいうえお漢字☺🍺", 0);
  atom(174) = to_atom(" -> ", 0);
  atom(175) = to_atom("test_atom_chars2", 0);
  atom(176) = to_atom("c", 0);
  atom(177) = to_atom("d", 0);
  atom(178) = to_atom("e", 0);
  atom(179) = to_atom("f", 0);
  atom(180) = to_atom("g", 0);
  atom(181) = to_atom("あ", 0);
  atom(182) = to_atom("い", 0);
  atom(183) = to_atom("う", 0);
  atom(184) = to_atom("え", 0);
  atom(185) = to_atom("お", 0);
  atom(186) = to_atom("漢", 0);
  atom(187) = to_atom("字", 0);
  atom(188) = to_atom("☺", 0);
  atom(189) = to_atom("🍺", 0);
  atom(190) = to_atom(" <- ", 0);
  atom(191) = to_atom("test_atom_codes", 0);
  atom(192) = to_atom("test_atom_codes1", 0);
  atom(193) = to_atom("test_atom_codes2", 0);
  atom(194) = to_atom("test_append", 0);
  atom(195) = to_atom("test_append1", 0);
  atom(196) = to_atom("+", 0);
  atom(197) = to_atom("=[", 0);
  atom(198) = to_atom("test_append2", 0);
  atom(199) = to_atom("]=", 0);
  atom(200) = to_atom("test_append3", 0);
  atom(201) = to_atom("]+", 0);
  atom(202) = to_atom("=", 0);
  atom(203) = to_atom("test_reverse", 0);
  atom(204) = to_atom("test_nth0", 0);
  atom(205) = to_atom("test_nth0_", 0);
  atom(206) = to_atom(" 0: [", 0);
  atom(207) = to_atom("] 1: [", 0);
  atom(208) = to_atom("] 2: [", 0);
  atom(209) = to_atom("] 3: [", 0);
  atom(210) = to_atom("] 4: [", 0);
  atom(211) = to_atom("] 5: [", 0);
  atom(212) = to_atom("test_nth0_rev_", 0);
  atom(213) = to_atom(" [", 0);
  atom(214) = to_atom("]: a", 0);
  atom(215) = to_atom("]: b", 0);
  atom(216) = to_atom("]: c", 0);
  atom(217) = to_atom("]: d", 0);
  atom(218) = to_atom("]: e", 0);
  atom(219) = to_atom("]: f", 0);
  atom(220) = to_atom("test_nth1", 0);
  atom(221) = to_atom("test_nth1_", 0);
  atom(222) = to_atom(" 1: [", 0);
  atom(223) = to_atom("test_nth1_rev_", 0);
  atom(224) = to_atom("test_splice_suspension", 0);
  atom(225) = to_atom("dump/splice.dot", 0);
  atom(226) = to_atom("test_splice_suspension1", 1);
  atom(227) = to_atom("do_test", 1);
  atom(228) = to_atom(": ", 0);
  atom(229) = to_atom("main", 1);
  atom(230) = to_atom("total_inferences=", 0);
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
  prog->add_entry_point(atom(53), 98);  // __open__ / 4
  prog->add_entry_point(atom(54), 99);  // __close__ / 1
  prog->add_entry_point(atom(30), 100);  // writeln / 1
  prog->add_entry_point(atom(29), 102);  // writeln / 2
  prog->add_entry_point(atom(32), 104);  // nl / 0
  prog->add_entry_point(atom(31), 105);  // nl / 1
  prog->add_entry_point(atom(55), 107);  // __nl__ / 1
  prog->add_entry_point(atom(28), 108);  // write / 1
  prog->add_entry_point(atom(27), 109);  // write / 2
  prog->add_entry_point(atom(56), 111);  // __write__ / 2
  prog->add_entry_point(atom(60), 126);  // __write_functor_args__ / 2
  prog->add_entry_point(atom(63), 130);  // __write_functor_args2__ / 2
  prog->add_entry_point(atom(64), 133);  // __write_functor_tail__ / 2
  prog->add_entry_point(atom(66), 137);  // __write_list_tail__ / 2
  prog->add_entry_point(atom(68), 146);  // __write_number__ / 2
  prog->add_entry_point(atom(69), 147);  // __write_atom__ / 2
  prog->add_entry_point(atom(70), 148);  // __write_var__ / 2
  prog->add_entry_point(atom(71), 149);  // integer / 1
  prog->add_entry_point(atom(72), 150);  // atom / 1
  prog->add_entry_point(atom(73), 151);  // var / 1
  prog->add_entry_point(atom(74), 152);  // is_functor / 1
  prog->add_entry_point(atom(75), 153);  // =.. / 2
  prog->add_entry_point(atom(76), 154);  // == / 2
  prog->add_entry_point(atom(77), 155);  // >= / 2
  prog->add_entry_point(atom(78), 156);  // =< / 2
  prog->add_entry_point(atom(79), 157);  // > / 2
  prog->add_entry_point(atom(80), 158);  // < / 2
  prog->add_entry_point(atom(81), 159);  // =:= / 2
  prog->add_entry_point(atom(82), 162);  // =\= / 2
  prog->add_entry_point(atom(83), 165);  // __not_equal__ / 2
  prog->add_entry_point(atom(84), 166);  // := / 2
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
  prog->add_entry_point(atom(102), 214);  // append / 3
  prog->add_entry_point(atom(103), 222);  // reverse / 2
  prog->add_entry_point(atom(104), 226);  // __reverse__ / 3
  prog->add_entry_point(atom(105), 228);  // nth0 / 3
  prog->add_entry_point(atom(106), 232);  // __nth0__ / 3
  prog->add_entry_point(atom(107), 235);  // __nth0_rev__ / 4
  prog->add_entry_point(atom(108), 238);  // nth1 / 3
  prog->add_entry_point(atom(109), 244);  // inference_count / 1
  prog->add_entry_point(atom(110), 245);  // __inference_count__ / 1
  prog->add_entry_point(atom(111), 246);  // resume_count / 1
  prog->add_entry_point(atom(112), 247);  // __resume_count__ / 1
  prog->add_entry_point(atom(113), 248);  // dump_to_dot / 1
  prog->add_entry_point(atom(114), 250);  // __dump_to_dot__ / 1
  prog->add_entry_point(atom(115), 251);  // dump_to_dot / 2
  prog->add_entry_point(atom(116), 253);  // __dump_to_dot__ / 2
  prog->add_entry_point(atom(117), 254);  // test_otherwise / 0
  prog->add_entry_point(atom(118), 256);  // test_otherwise_aux / 1
  prog->add_entry_point(atom(121), 258);  // test_write_var / 0
  prog->add_entry_point(atom(122), 259);  // test_write_atom / 0
  prog->add_entry_point(atom(124), 260);  // test_write_list / 0
  prog->add_entry_point(atom(125), 261);  // test_write_structure / 0
  prog->add_entry_point(atom(130), 262);  // test_get_structure / 0
  prog->add_entry_point(atom(131), 263);  // test_set_structure / 0
  prog->add_entry_point(atom(132), 264);  // test_get_list / 0
  prog->add_entry_point(atom(133), 265);  // test_set_list / 0
  prog->add_entry_point(atom(134), 266);  // test_check_constant / 0
  prog->add_entry_point(atom(135), 267);  // test_check_constant_aux / 1
  prog->add_entry_point(atom(139), 270);  // test_check_list / 0
  prog->add_entry_point(atom(142), 271);  // test_check_list_aux / 1
  prog->add_entry_point(atom(147), 274);  // test_check_nil / 0
  prog->add_entry_point(atom(148), 275);  // test_check_nil_aux / 1
  prog->add_entry_point(atom(151), 278);  // test_check_structure / 0
  prog->add_entry_point(atom(153), 279);  // test_check_structure_aux / 1
  prog->add_entry_point(atom(156), 282);  // test_wait_var / 0
  prog->add_entry_point(atom(157), 284);  // wait_var / 1
  prog->add_entry_point(atom(158), 285);  // write_var / 1
  prog->add_entry_point(atom(160), 286);  // test_atom_concat / 0
  prog->add_entry_point(atom(161), 289);  // test_atom_concat_1 / 0
  prog->add_entry_point(atom(165), 294);  // test_atom_concat_2 / 0
  prog->add_entry_point(atom(169), 298);  // test_atom_concat_3 / 0
  prog->add_entry_point(atom(171), 302);  // test_atom_chars / 0
  prog->add_entry_point(atom(172), 304);  // test_atom_chars1 / 0
  prog->add_entry_point(atom(175), 308);  // test_atom_chars2 / 0
  prog->add_entry_point(atom(191), 312);  // test_atom_codes / 0
  prog->add_entry_point(atom(192), 314);  // test_atom_codes1 / 0
  prog->add_entry_point(atom(193), 318);  // test_atom_codes2 / 0
  prog->add_entry_point(atom(194), 322);  // test_append / 0
  prog->add_entry_point(atom(195), 325);  // test_append1 / 0
  prog->add_entry_point(atom(198), 332);  // test_append2 / 0
  prog->add_entry_point(atom(200), 339);  // test_append3 / 0
  prog->add_entry_point(atom(203), 346);  // test_reverse / 0
  prog->add_entry_point(atom(204), 348);  // test_nth0 / 0
  prog->add_entry_point(atom(205), 350);  // test_nth0_ / 0
  prog->add_entry_point(atom(212), 369);  // test_nth0_rev_ / 0
  prog->add_entry_point(atom(220), 393);  // test_nth1 / 0
  prog->add_entry_point(atom(221), 395);  // test_nth1_ / 0
  prog->add_entry_point(atom(223), 411);  // test_nth1_rev_ / 0
  prog->add_entry_point(atom(224), 431);  // test_splice_suspension / 0
  prog->add_entry_point(atom(226), 436);  // test_splice_suspension1 / 1
  prog->add_entry_point(atom(227), 437);  // do_test / 1
  prog->add_entry_point(atom(229), 440);  // main / 1
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
