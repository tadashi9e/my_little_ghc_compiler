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
Q atom(121);  // main / 1
Q atom(122);  // Hello  / 0
Q atom(123);  // writes / 2
Q atom(124);  //   / 0
void module(VM::ptr vm, Program* prog, bool setup) {
  if (setup) {
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
    atom(121) = to_atom("main", 1);
    atom(122) = to_atom("Hello ", 0);
    atom(123) = to_atom("writes", 2);
    atom(124) = to_atom(" ", 0);
    // setup entry points
    prog->add_entry_point(atom(1), &&L1);  // fail / 0
    prog->add_entry_point(atom(2), &&L2);  // call / 1
    prog->add_entry_point(atom(3), &&L3);  // __call__ / 1
    prog->add_entry_point(atom(4), &&L4);  // time / 1
    prog->add_entry_point(atom(5), &&L7);  // wait_time / 1
    prog->add_entry_point(atom(6), &&L9);  // __wait_time__ / 4
    prog->add_entry_point(atom(7), &&L10);  // __time_pre__ / 3
    prog->add_entry_point(atom(8), &&L11);  // __time_post__ / 3
    prog->add_entry_point(atom(9), &&L12);  // atom_concat / 3
    prog->add_entry_point(atom(10), &&L21);  // __atom_concat_1__ / 3
    prog->add_entry_point(atom(11), &&L22);  // __atom_concat_2__ / 3
    prog->add_entry_point(atom(12), &&L23);  // __atom_concat_3__ / 3
    prog->add_entry_point(atom(13), &&L24);  // atom_codes / 2
    prog->add_entry_point(atom(15), &&L27);  // __atom_to_codes__ / 2
    prog->add_entry_point(atom(16), &&L28);  // __codes_to_atom__ / 3
    prog->add_entry_point(atom(17), &&L32);  // __atom_code_concat__ / 3
    prog->add_entry_point(atom(18), &&L33);  // atom_chars / 2
    prog->add_entry_point(atom(19), &&L36);  // __atom_to_chars__ / 2
    prog->add_entry_point(atom(20), &&L37);  // __chars_to_atom__ / 3
    prog->add_entry_point(atom(21), &&L40);  // atom_number / 2
    prog->add_entry_point(atom(22), &&L44);  // __atom_to_number__ / 2
    prog->add_entry_point(atom(23), &&L45);  // __number_to_atom__ / 2
    prog->add_entry_point(atom(24), &&L46);  // outstream / 1
    prog->add_entry_point(atom(25), &&L48);  // outstream / 2
    prog->add_entry_point(atom(26), &&L62);  // open / 3
    prog->add_entry_point(atom(33), &&L64);  // close / 1
    prog->add_entry_point(atom(34), &&L65);  // __open_opt_string_to_integer__ / 3
    prog->add_entry_point(atom(35), &&L66);  // __open_opt_string_to_integer__ / 5
    prog->add_entry_point(atom(52), &&L98);  // __open__ / 4
    prog->add_entry_point(atom(53), &&L99);  // __close__ / 1
    prog->add_entry_point(atom(30), &&L100);  // writeln / 1
    prog->add_entry_point(atom(29), &&L102);  // writeln / 2
    prog->add_entry_point(atom(32), &&L104);  // nl / 0
    prog->add_entry_point(atom(31), &&L105);  // nl / 1
    prog->add_entry_point(atom(54), &&L107);  // __nl__ / 1
    prog->add_entry_point(atom(28), &&L108);  // write / 1
    prog->add_entry_point(atom(27), &&L109);  // write / 2
    prog->add_entry_point(atom(55), &&L111);  // __write__ / 2
    prog->add_entry_point(atom(59), &&L126);  // __write_functor_args__ / 2
    prog->add_entry_point(atom(62), &&L130);  // __write_functor_args2__ / 2
    prog->add_entry_point(atom(63), &&L133);  // __write_functor_tail__ / 2
    prog->add_entry_point(atom(65), &&L137);  // __write_list_tail__ / 2
    prog->add_entry_point(atom(67), &&L146);  // __write_number__ / 2
    prog->add_entry_point(atom(68), &&L147);  // __write_atom__ / 2
    prog->add_entry_point(atom(69), &&L148);  // __write_var__ / 2
    prog->add_entry_point(atom(70), &&L149);  // integer / 1
    prog->add_entry_point(atom(71), &&L150);  // atom / 1
    prog->add_entry_point(atom(72), &&L151);  // var / 1
    prog->add_entry_point(atom(73), &&L152);  // is_functor / 1
    prog->add_entry_point(atom(74), &&L153);  // =.. / 2
    prog->add_entry_point(atom(75), &&L154);  // == / 2
    prog->add_entry_point(atom(76), &&L155);  // >= / 2
    prog->add_entry_point(atom(77), &&L156);  // =< / 2
    prog->add_entry_point(atom(78), &&L157);  // > / 2
    prog->add_entry_point(atom(79), &&L158);  // < / 2
    prog->add_entry_point(atom(80), &&L159);  // =:= / 2
    prog->add_entry_point(atom(81), &&L162);  // =\= / 2
    prog->add_entry_point(atom(82), &&L165);  // __not_equal__ / 2
    prog->add_entry_point(atom(83), &&L166);  // := / 2
    prog->add_entry_point(atom(90), &&L174);  // __add__ / 3
    prog->add_entry_point(atom(91), &&L180);  // __sub__ / 3
    prog->add_entry_point(atom(92), &&L186);  // __mul__ / 3
    prog->add_entry_point(atom(93), &&L192);  // __div__ / 3
    prog->add_entry_point(atom(94), &&L198);  // __mod__ / 3
    prog->add_entry_point(atom(95), &&L204);  // __neg__ / 2
    prog->add_entry_point(atom(96), &&L208);  // __ineg__ / 2
    prog->add_entry_point(atom(97), &&L209);  // __iadd__ / 3
    prog->add_entry_point(atom(98), &&L210);  // __isub__ / 3
    prog->add_entry_point(atom(99), &&L211);  // __imul__ / 3
    prog->add_entry_point(atom(100), &&L212);  // __idiv__ / 3
    prog->add_entry_point(atom(101), &&L213);  // __imod__ / 3
    prog->add_entry_point(atom(102), &&L214);  // __inc__ / 2
    prog->add_entry_point(atom(103), &&L218);  // __dec__ / 2
    prog->add_entry_point(atom(104), &&L222);  // __iinc__ / 2
    prog->add_entry_point(atom(105), &&L223);  // __idec__ / 2
    prog->add_entry_point(atom(106), &&L224);  // append / 3
    prog->add_entry_point(atom(107), &&L232);  // reverse / 2
    prog->add_entry_point(atom(108), &&L236);  // __reverse__ / 3
    prog->add_entry_point(atom(109), &&L238);  // nth0 / 3
    prog->add_entry_point(atom(110), &&L242);  // __nth0__ / 3
    prog->add_entry_point(atom(111), &&L245);  // __nth0_rev__ / 4
    prog->add_entry_point(atom(112), &&L248);  // nth1 / 3
    prog->add_entry_point(atom(113), &&L254);  // inference_count / 1
    prog->add_entry_point(atom(114), &&L255);  // __inference_count__ / 1
    prog->add_entry_point(atom(115), &&L256);  // resume_count / 1
    prog->add_entry_point(atom(116), &&L257);  // __resume_count__ / 1
    prog->add_entry_point(atom(117), &&L258);  // dump_to_dot / 1
    prog->add_entry_point(atom(118), &&L260);  // __dump_to_dot__ / 1
    prog->add_entry_point(atom(119), &&L261);  // dump_to_dot / 2
    prog->add_entry_point(atom(120), &&L263);  // __dump_to_dot__ / 2
    prog->add_entry_point(atom(121), &&L264);  // main / 1
    prog->add_entry_point(atom(123), &&L266);  // writes / 2
    vm->FAIL = &&LFAIL;
    vm->FAIL2 = &&LFAIL2;
    vm->NO_MORE_GOALS = &&LNO_MORE_GOALS;
    return;
  }
  goto *(vm->pc);
 LFAIL:
  throw RuntimeError();
 LFAIL2:
  throw RuntimeError();
 L1:  // fail/0
  MACRO_goal(L1, atom(1));
  MACRO_requires(1);
  do {
    vm->fail();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L2:  // call/1
  MACRO_goal(L2, atom(2));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L3, 1);  // execute(__call__/1)
 L3:  // __call__/1
  MACRO_goal(L3, atom(3));
  MACRO_requires(3);
  MACRO_wait(reg::in(1));
  do {
    Q q = vm->in[1];
    const TAG_T tag = tag_of(q);
    if (tag == TAG_ATOM) {
      MACRO_activate;
      void* pc = prog->query_entry_point(q);
      if (pc == NULL) {
        vm->fail();
        break;
      }
      MACRO_execute2(pc, 0);
      break;
    } else if (tag == TAG_STR) {
      MACRO_activate;
      A* structure = ptr_of<A>(q);
      Q g = structure[0].load();
      void* pc = prog->query_entry_point(g);
      if (pc == NULL) {
        vm->fail();
        break;
      }
      const int arity = atom_arity_of(g);
      MACRO_tail(2);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_execute2(pc, arity);
      break;
    } else {
      vm->fail();
      break;
    }
  } while(0);
  vm->failed = false;
  goto *(vm->pc);
 L4:  // time/1
  MACRO_goal(L4, atom(4));
  MACRO_requires(8);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_variable(reg::x(2),reg::out(1));
  MACRO_out_variable(reg::x(3),reg::out(2));
  MACRO_out_variable(reg::x(4),reg::out(3));
  MACRO_call(L10, L5);  // call(__time_pre__/3)
 L5:  // return_from_call(__time_pre__/3)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L2, L6);  // call(call/1)
 L6:  // return_from_call(call/1)
  MACRO_tail(5);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_out_value(reg::x(4),reg::out(3));
  MACRO_execute(L11, 3);  // execute(__time_post__/3)
 L7:  // wait_time/1
  MACRO_goal(L7, atom(5));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(2),reg::out(1));
  MACRO_out_variable(reg::x(3),reg::out(2));
  MACRO_out_variable(reg::x(4),reg::out(3));
  MACRO_spawn(L10, L8);  // spawn(__time_pre__/3)
 L8:  // return_from_spawn(__time_pre__/3)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(2),reg::out(2));
  MACRO_out_value(reg::x(3),reg::out(3));
  MACRO_out_value(reg::x(4),reg::out(4));
  MACRO_execute(L9, 4);  // execute(__wait_time__/4)
 L9:  // __wait_time__/4
  MACRO_goal(L9, atom(6));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_wait(reg::in(1));
  MACRO_activate;
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_value(reg::in(3),reg::out(2));
  MACRO_out_value(reg::in(4),reg::out(3));
  MACRO_execute(L11, 3);  // execute(__time_post__/3)
 L10:  // __time_pre__/3
  MACRO_goal(L10, atom(7));
  MACRO_requires(7);
  do {
    MACRO_activate;
    const int64_t istart = static_cast<int64_t>(std::clock() * 1000000.0 / CLOCKS_PER_SEC);
    MACRO_set_constant(tagvalue<TAG_INT>(istart), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(1));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->inference_count), reg::in(2));
  MACRO_get_constant(tagvalue<TAG_INT>(vm->resume_count), reg::in(3));
  MACRO_proceed;
 L11:  // __time_post__/3
  MACRO_goal(L11, atom(8));
  MACRO_requires(7);
  MACRO_activate;
  do {
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
  } while(0);
  MACRO_proceed;
 L12:  // atom_concat/3
  MACRO_goal(L12, atom(9));
  MACRO_requires(7);
  MACRO_try_guard_else(L15);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L13);  // call(atom/1)
 L13:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L150, L14);  // call(atom/1)
 L14:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L21, 3);  // execute(__atom_concat_1__/3)
 L15:  // atom_concat/3-2
  MACRO_try_guard_else(L18);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L16);  // call(atom/1)
 L16:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L150, L17);  // call(atom/1)
 L17:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L22, 3);  // execute(__atom_concat_2__/3)
 L18:  // atom_concat/3-3
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L150, L19);  // call(atom/1)
 L19:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L150, L20);  // call(atom/1)
 L20:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L23, 3);  // execute(__atom_concat_3__/3)
 L21:  // __atom_concat_1__/3
  MACRO_goal(L21, atom(10));
  MACRO_requires(7);
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s1 = atom_str_of(q1);
    const std::string s2 = atom_str_of(q2);
    const std::string s = s1 + s2;
    const Q c = to_atom(s.c_str(), 0);
    if (!vm->unify(c, vm->in[3])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L22:  // __atom_concat_2__/3
  MACRO_goal(L22, atom(11));
  MACRO_requires(7);
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q3 = vm->in[3];
    const std::string s1 = atom_str_of(q1);
    const std::string s3 = atom_str_of(q3);
    if (s1.length() > s3.length()) {
      vm->fail();
      break;
    }
    const size_t i = s1.length();
    if (s3.substr(0, i) != s1) {
      vm->fail();
      break;
    }
    const std::string s2 = s3.substr(i);
    const Q c = to_atom(s2.c_str(), 0);
    if (!vm->unify(c, vm->in[2])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L23:  // __atom_concat_3__/3
  MACRO_goal(L23, atom(12));
  MACRO_requires(7);
  MACRO_activate;
  do {
    const Q q2 = vm->in[2];
    const Q q3 = vm->in[3];
    const std::string s2 = atom_str_of(q2);
    const std::string s3 = atom_str_of(q3);
    if (s2.length() > s3.length()) {
      vm->fail();
      break;
    }
    const size_t i = s2.length();
    if (s3.substr(i) != s2) {
      vm->fail();
      break;
    }
    const std::string s1 = s3.substr(0, i);
    const Q c = to_atom(s1.c_str(), 0);
    if (!vm->unify(c, vm->in[1])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L24:  // atom_codes/2
  MACRO_goal(L24, atom(13));
  MACRO_requires(8);
  MACRO_try_guard_else(L26);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L25);  // call(atom/1)
 L25:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L27, 2);  // execute(__atom_to_codes__/2)
 L26:  // atom_codes/2-2
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
  MACRO_execute(L28, 3);  // execute(__codes_to_atom__/3)
 L27:  // __atom_to_codes__/2
  MACRO_goal(L27, atom(15));
  MACRO_requires(5);
  MACRO_activate;
  do {
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
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L28:  // __codes_to_atom__/3
  MACRO_goal(L28, atom(16));
  MACRO_requires(9);
  MACRO_try_guard_else(L29);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(1));
  MACRO_proceed;
 L29:  // __codes_to_atom__/3-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(5));
  MACRO_read_variable(reg::x(4));
  MACRO_seq(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_call(L149, L30);  // call(integer/1)
 L30:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L32, L31);  // spawn(__atom_code_concat__/3)
 L31:  // return_from_spawn(__atom_code_concat__/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_execute(L28, 3);  // execute(__codes_to_atom__/3)
 L32:  // __atom_code_concat__/3
  MACRO_goal(L32, atom(17));
  MACRO_requires(7);
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    std::string s = atom_str_of(q1);
    const unsigned char c = value_of<char>(q2);
    s += c;
    if (!vm->unify(to_atom(s.c_str(), 0), vm->in[3])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L33:  // atom_chars/2
  MACRO_goal(L33, atom(18));
  MACRO_requires(8);
  MACRO_try_guard_else(L35);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L34);  // call(atom/1)
 L34:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L36, 2);  // execute(__atom_to_chars__/2)
 L35:  // atom_chars/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(3),reg::out(3));
  MACRO_execute(L37, 3);  // execute(__chars_to_atom__/3)
 L36:  // __atom_to_chars__/2
  MACRO_goal(L36, atom(19));
  MACRO_requires(5);
  MACRO_activate;
  do {
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
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L37:  // __chars_to_atom__/3
  MACRO_goal(L37, atom(20));
  MACRO_requires(9);
  MACRO_try_guard_else(L38);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(1));
  MACRO_proceed;
 L38:  // __chars_to_atom__/3-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(5));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L12, L39);  // spawn(atom_concat/3)
 L39:  // return_from_spawn(atom_concat/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_execute(L37, 3);  // execute(__chars_to_atom__/3)
 L40:  // atom_number/2
  MACRO_goal(L40, atom(21));
  MACRO_requires(5);
  MACRO_try_guard_else(L42);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L41);  // call(atom/1)
 L41:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L44, 2);  // execute(__atom_to_number__/2)
 L42:  // atom_number/2-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L43);  // call(integer/1)
 L43:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L45, 2);  // execute(__number_to_atom__/2)
 L44:  // __atom_to_number__/2
  MACRO_goal(L44, atom(22));
  MACRO_requires(5);
  MACRO_activate;
  do {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_set_constant(tagvalue<TAG_INT>(i), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  vm->proceed();
  goto *(vm->pc);
 L45:  // __number_to_atom__/2
  MACRO_goal(L45, atom(23));
  MACRO_requires(5);
  MACRO_activate;
  do {
    const Q q = vm->in[2];
    const int64_t i = value_of<int64_t>(q);
    const std::string s = std::to_string(i);
    MACRO_set_constant(to_atom(s.c_str(), 0), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(1));
  MACRO_proceed;
 L46:  // outstream/1
  MACRO_goal(L46, atom(24));
  MACRO_requires(6);
  MACRO_try_guard_else(L47);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_proceed;
 L47:  // outstream/1-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_variable(reg::x(2));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L48, 2);  // execute(outstream/2)
 L48:  // outstream/2
  MACRO_goal(L48, atom(25));
  MACRO_requires(9);
  MACRO_try_guard_else(L50);
  MACRO_check_structure(atom(26),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(5));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_spawn(L62, L49);  // spawn(open/3)
 L49:  // return_from_spawn(open/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L50:  // outstream/2-2
  MACRO_try_guard_else(L52);
  MACRO_check_structure(atom(27),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_spawn(L109, L51);  // spawn(write/2)
 L51:  // return_from_spawn(write/2)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L52:  // outstream/2-3
  MACRO_try_guard_else(L54);
  MACRO_check_structure(atom(28),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L108, L53);  // spawn(write/1)
 L53:  // return_from_spawn(write/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L54:  // outstream/2-4
  MACRO_try_guard_else(L56);
  MACRO_check_structure(atom(29),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_spawn(L102, L55);  // spawn(writeln/2)
 L55:  // return_from_spawn(writeln/2)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L56:  // outstream/2-5
  MACRO_try_guard_else(L58);
  MACRO_check_structure(atom(30),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L100, L57);  // spawn(writeln/1)
 L57:  // return_from_spawn(writeln/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L58:  // outstream/2-6
  MACRO_try_guard_else(L60);
  MACRO_check_structure(atom(31),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L105, L59);  // spawn(nl/1)
 L59:  // return_from_spawn(nl/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L60:  // outstream/2-7
  MACRO_try_guard_else_suspend;
  MACRO_check_constant(atom(32),reg::in(1));
  MACRO_activate;
  MACRO_par(6);
  MACRO_spawn(L104, L61);  // spawn(nl/0)
 L61:  // return_from_spawn(nl/0)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L46, 1);  // execute(outstream/1)
 L62:  // open/3
  MACRO_goal(L62, atom(26));
  MACRO_requires(10);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L65, L63);  // spawn(__open_opt_string_to_integer__/3)
 L63:  // return_from_spawn(__open_opt_string_to_integer__/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_out_value(reg::in(3),reg::out(4));
  MACRO_execute(L98, 4);  // execute(__open__/4)
 L64:  // close/1
  MACRO_goal(L64, atom(33));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L99, 1);  // execute(__close__/1)
 L65:  // __open_opt_string_to_integer__/3
  MACRO_goal(L65, atom(34));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L66:  // __open_opt_string_to_integer__/5
  MACRO_goal(L66, atom(35));
  MACRO_requires(13);
  MACRO_try_guard_else(L67);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(4),reg::in(2));
  MACRO_get_value(reg::in(5),reg::in(3));
  MACRO_proceed;
 L67:  // __open_opt_string_to_integer__/5-2
  MACRO_try_guard_else(L68);
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
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L68:  // __open_opt_string_to_integer__/5-3
  MACRO_try_guard_else(L70);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(37));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_variable(reg::x(7),reg::out(2));
  MACRO_call(L214, L69);  // call(__inc__/2)
 L69:  // return_from_call(__inc__/2)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L70:  // __open_opt_string_to_integer__/5-4
  MACRO_try_guard_else(L72);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(38));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L71);  // call(__add__/3)
 L71:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L72:  // __open_opt_string_to_integer__/5-5
  MACRO_try_guard_else(L74);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(39));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L73);  // call(__add__/3)
 L73:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L74:  // __open_opt_string_to_integer__/5-6
  MACRO_try_guard_else(L76);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(40));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L75);  // call(__add__/3)
 L75:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L76:  // __open_opt_string_to_integer__/5-7
  MACRO_try_guard_else(L78);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(41));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L77);  // call(__add__/3)
 L77:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L78:  // __open_opt_string_to_integer__/5-8
  MACRO_try_guard_else(L80);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(42));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L79);  // call(__add__/3)
 L79:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L80:  // __open_opt_string_to_integer__/5-9
  MACRO_try_guard_else(L82);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(43));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L81);  // call(__add__/3)
 L81:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L82:  // __open_opt_string_to_integer__/5-10
  MACRO_try_guard_else(L84);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(44));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L83);  // call(__add__/3)
 L83:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L84:  // __open_opt_string_to_integer__/5-11
  MACRO_try_guard_else(L86);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(45));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L85);  // call(__add__/3)
 L85:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L86:  // __open_opt_string_to_integer__/5-12
  MACRO_try_guard_else(L88);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(46));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L87);  // call(__add__/3)
 L87:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L88:  // __open_opt_string_to_integer__/5-13
  MACRO_try_guard_else(L90);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(47));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L89);  // call(__add__/3)
 L89:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L90:  // __open_opt_string_to_integer__/5-14
  MACRO_try_guard_else(L92);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(48));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L91);  // call(__add__/3)
 L91:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L92:  // __open_opt_string_to_integer__/5-15
  MACRO_try_guard_else(L94);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(49));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L93);  // call(__add__/3)
 L93:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L94:  // __open_opt_string_to_integer__/5-16
  MACRO_try_guard_else(L96);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(50));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L174, L95);  // call(__add__/3)
 L95:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L96:  // __open_opt_string_to_integer__/5-17
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(51));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_variable(reg::x(7),reg::out(2));
  MACRO_call(L214, L97);  // call(__inc__/2)
 L97:  // return_from_call(__inc__/2)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L66, 5);  // execute(__open_opt_string_to_integer__/5)
 L98:  // __open__/4
  MACRO_goal(L98, atom(52));
  MACRO_requires(9);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_wait_for(TAG_INT, reg::in(3));
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const Q q3 = vm->in[3];
    const std::string src = atom_str_of(q1);
    const int oflag = value_of<int>(q2);
    const int omode = value_of<int>(q3);
    const int fd = open(src.c_str(), oflag, omode);
    if (fd < 0) {
      if (!vm->unify(to_atom("error", 0), vm->in[4])) {
        vm->fail();
        break;
      }
    } else {
      if (!vm->unify(tagvalue<TAG_INT>(fd), vm->in[4])) {
        vm->fail();
        break;
      }
    }
    vm->proceed();
  } while (0);
    vm->failed = false;
  goto *(vm->pc);
 L99:  // __close__/1
  MACRO_goal(L99, atom(53));
  MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L100:  // writeln/1
  MACRO_goal(L100, atom(30));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L108, L101);  // call(write/1)
 L101:  // return_from_call(write/1)
  MACRO_tail(3);
  MACRO_execute(L104, 0);  // execute(nl/0)
 L102:  // writeln/2
  MACRO_goal(L102, atom(29));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L109, L103);  // spawn(write/2)
 L103:  // return_from_spawn(write/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L105, 1);  // execute(nl/1)
 L104:  // nl/0
  MACRO_goal(L104, atom(32));
  MACRO_requires(2);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(2);
  MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
  MACRO_execute(L105, 1);  // execute(nl/1)
 L105:  // nl/1
  MACRO_goal(L105, atom(31));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L106);  // call(integer/1)
 L106:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L107, 1);  // execute(__nl__/1)
 L107:  // __nl__/1
  MACRO_goal(L107, atom(54));
  MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
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
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L108:  // write/1
  MACRO_goal(L108, atom(28));
  MACRO_requires(4);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L109, 2);  // execute(write/2)
 L109:  // write/2
  MACRO_goal(L109, atom(27));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L110);  // call(integer/1)
 L110:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L111:  // __write__/2
  MACRO_goal(L111, atom(55));
  MACRO_requires(7);
  MACRO_try_guard_else(L113);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L150, L112);  // call(atom/1)
 L112:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L147, 2);  // execute(__write_atom__/2)
 L113:  // __write__/2-2
  MACRO_try_guard_else(L115);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L114);  // call(var/1)
 L114:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L148, 2);  // execute(__write_var__/2)
 L115:  // __write__/2-3
  MACRO_try_guard_else(L117);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L116);  // call(integer/1)
 L116:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L146, 2);  // execute(__write_number__/2)
 L117:  // __write__/2-4
  MACRO_try_guard_else(L118);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(56),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L118:  // __write__/2-5
  MACRO_try_guard_else(L122);
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(57),reg::out(2));
  MACRO_call(L111, L119);  // call(__write__/2)
 L119:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L111, L120);  // call(__write__/2)
 L120:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_call(L137, L121);  // call(__write_list_tail__/2)
 L121:  // return_from_call(__write_list_tail__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(58),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L122:  // __write__/2-6
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L152, L123);  // call(is_functor/1)
 L123:  // return_from_call(is_functor/1)
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_list(reg::out(2));
  MACRO_write_variable(reg::x(4));
  MACRO_write_variable(reg::x(3));
  MACRO_call(L153, L124);  // call((=..)/2)
 L124:  // return_from_call((=..)/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L111, L125);  // call(__write__/2)
 L125:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L126, 2);  // execute(__write_functor_args__/2)
 L126:  // __write_functor_args__/2
  MACRO_goal(L126, atom(59));
  MACRO_requires(5);
  MACRO_try_guard_else(L127);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L127:  // __write_functor_args__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(60),reg::out(2));
  MACRO_call(L111, L128);  // call(__write__/2)
 L128:  // return_from_call(__write__/2)
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_call(L130, L129);  // call(__write_functor_args2__/2)
 L129:  // return_from_call(__write_functor_args2__/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(61),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L130:  // __write_functor_args2__/2
  MACRO_goal(L130, atom(62));
  MACRO_requires(7);
  MACRO_try_guard_else(L131);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L131:  // __write_functor_args2__/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L111, L132);  // call(__write__/2)
 L132:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L133, 2);  // execute(__write_functor_tail__/2)
 L133:  // __write_functor_tail__/2
  MACRO_goal(L133, atom(63));
  MACRO_requires(7);
  MACRO_try_guard_else(L134);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L134:  // __write_functor_tail__/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(64),reg::out(2));
  MACRO_call(L111, L135);  // call(__write__/2)
 L135:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L111, L136);  // call(__write__/2)
 L136:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L133, 2);  // execute(__write_functor_tail__/2)
 L137:  // __write_list_tail__/2
  MACRO_goal(L137, atom(65));
  MACRO_requires(7);
  MACRO_try_guard_else(L140);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L138);  // call(var/1)
 L138:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(66),reg::out(2));
  MACRO_call(L111, L139);  // call(__write__/2)
 L139:  // return_from_call(__write__/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L140:  // __write_list_tail__/2-2
  MACRO_try_guard_else(L141);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L141:  // __write_list_tail__/2-3
  MACRO_try_guard_else(L144);
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(64),reg::out(2));
  MACRO_call(L111, L142);  // call(__write__/2)
 L142:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L111, L143);  // call(__write__/2)
 L143:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L137, 2);  // execute(__write_list_tail__/2)
 L144:  // __write_list_tail__/2-4
  MACRO_otherwise;
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(66),reg::out(2));
  MACRO_call(L111, L145);  // call(__write__/2)
 L145:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L111, 2);  // execute(__write__/2)
 L146:  // __write_number__/2
  MACRO_goal(L146, atom(67));
  MACRO_requires(5);
  MACRO_activate;
  do {
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
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L147:  // __write_atom__/2
  MACRO_goal(L147, atom(68));
  MACRO_requires(5);
  MACRO_activate;
  do {
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
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L148:  // __write_var__/2
  MACRO_goal(L148, atom(69));
  MACRO_requires(5);
  MACRO_activate;
  do {
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
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L149:  // integer/1
  MACRO_goal(L149, atom(70));
  MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
  goto *(vm->pc);
 L150:  // atom/1
  MACRO_goal(L150, atom(71));
  MACRO_requires(3);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
  goto *(vm->pc);
 L151:  // var/1
  MACRO_goal(L151, atom(72));
  MACRO_requires(3);
  do {
    const Q q = vm->in[1] = deref(vm->in[1]);
    const TAG_T tag = tag_of(q);
    if (tag != TAG_REF && tag != TAG_SUS) {
      vm->fail();
    } else {
      MACRO_return;
    }
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L152:  // is_functor/1
  MACRO_goal(L152, atom(73));
  MACRO_requires(3);
  MACRO_wait_for(TAG_STR, reg::in(1));
  do {
    const Q q = vm->in[1];
    const TAG_T tag = tag_of(q);
    if (tag != TAG_STR) {
      vm->fail();
    } else {
      MACRO_return;
    }
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L153:  // (=..)/2
  MACRO_goal(L153, atom(74));
  MACRO_requires(5);
  MACRO_wait_for(TAG_STR, reg::in(1));
  MACRO_activate;
  do {
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
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L154:  // (==)/2
  MACRO_goal(L154, atom(75));
  MACRO_requires(5);
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  do {
    Q q1 = vm->in[1];
    Q q2 = vm->in[2];
    if (!(q1 == q2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L155:  // (>=)/2
  MACRO_goal(L155, atom(76));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 >= v2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L156:  // (=<)/2
  MACRO_goal(L156, atom(77));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 <= v2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L157:  // (>)/2
  MACRO_goal(L157, atom(78));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 > v2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  goto *(vm->pc);
 L158:  // (<)/2
  MACRO_goal(L158, atom(79));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    if (!(v1 < v2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L159:  // (=:=)/2
  MACRO_goal(L159, atom(80));
  MACRO_requires(7);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L160);  // spawn((:=)/2)
 L160:  // return_from_spawn((:=)/2)
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L161);  // spawn((:=)/2)
 L161:  // return_from_spawn((:=)/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_execute(L154, 2);  // execute((==)/2)
 L162:  // (=\=)/2
  MACRO_goal(L162, atom(81));
  MACRO_requires(7);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L163);  // spawn((:=)/2)
 L163:  // return_from_spawn((:=)/2)
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L164);  // spawn((:=)/2)
 L164:  // return_from_spawn((:=)/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_execute(L165, 2);  // execute(__not_equal__/2)
 L165:  // __not_equal__/2
  MACRO_goal(L165, atom(82));
  MACRO_requires(5);
  MACRO_wait(reg::in(1));
  MACRO_wait(reg::in(2));
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    if (!(q1 != q2)) {
      vm->fail();
      break;
    }
    MACRO_return;
  } while (0);
  vm->failed = false;
  goto *(vm->pc);
 L166:  // (:=)/2
  MACRO_goal(L166, atom(83));
  MACRO_requires(8);
  MACRO_try_guard_else(L168);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L167);  // call(integer/1)
 L167:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_get_value(reg::in(1),reg::in(2));
  MACRO_proceed;
 L168:  // (:=)/2-2
  MACRO_try_guard_else(L169);
  MACRO_check_structure(atom(84),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L174, 3);  // execute(__add__/3)
 L169:  // (:=)/2-3
  MACRO_try_guard_else(L170);
  MACRO_check_structure(atom(85),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L180, 3);  // execute(__sub__/3)
 L170:  // (:=)/2-4
  MACRO_try_guard_else(L171);
  MACRO_check_structure(atom(86),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L186, 3);  // execute(__mul__/3)
 L171:  // (:=)/2-5
  MACRO_try_guard_else(L172);
  MACRO_check_structure(atom(87),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L192, 3);  // execute(__div__/3)
 L172:  // (:=)/2-6
  MACRO_try_guard_else(L173);
  MACRO_check_structure(atom(88),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L198, 3);  // execute(__mod__/3)
 L173:  // (:=)/2-7
  MACRO_try_guard_else_suspend;
  MACRO_check_structure(atom(89),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L204, 2);  // execute(__neg__/2)
 L174:  // __add__/3
  MACRO_goal(L174, atom(90));
  MACRO_requires(9);
  MACRO_try_guard_else(L177);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L175);  // call(integer/1)
 L175:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L176);  // call(integer/1)
 L176:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L209, 3);  // execute(__iadd__/3)
 L177:  // __add__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L178);  // spawn((:=)/2)
 L178:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L179);  // spawn((:=)/2)
 L179:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L209, 3);  // execute(__iadd__/3)
 L180:  // __sub__/3
  MACRO_goal(L180, atom(91));
  MACRO_requires(9);
  MACRO_try_guard_else(L183);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L181);  // call(integer/1)
 L181:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L182);  // call(integer/1)
 L182:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L210, 3);  // execute(__isub__/3)
 L183:  // __sub__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L184);  // spawn((:=)/2)
 L184:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L185);  // spawn((:=)/2)
 L185:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L210, 3);  // execute(__isub__/3)
 L186:  // __mul__/3
  MACRO_goal(L186, atom(92));
  MACRO_requires(9);
  MACRO_try_guard_else(L189);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L187);  // call(integer/1)
 L187:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L188);  // call(integer/1)
 L188:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L211, 3);  // execute(__imul__/3)
 L189:  // __mul__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L190);  // spawn((:=)/2)
 L190:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L191);  // spawn((:=)/2)
 L191:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L211, 3);  // execute(__imul__/3)
 L192:  // __div__/3
  MACRO_goal(L192, atom(93));
  MACRO_requires(9);
  MACRO_try_guard_else(L195);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L193);  // call(integer/1)
 L193:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L194);  // call(integer/1)
 L194:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L212, 3);  // execute(__idiv__/3)
 L195:  // __div__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L196);  // spawn((:=)/2)
 L196:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L197);  // spawn((:=)/2)
 L197:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L212, 3);  // execute(__idiv__/3)
 L198:  // __mod__/3
  MACRO_goal(L198, atom(94));
  MACRO_requires(9);
  MACRO_try_guard_else(L201);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L199);  // call(integer/1)
 L199:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L149, L200);  // call(integer/1)
 L200:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L213, 3);  // execute(__imod__/3)
 L201:  // __mod__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L202);  // spawn((:=)/2)
 L202:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L166, L203);  // spawn((:=)/2)
 L203:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L213, 3);  // execute(__imod__/3)
 L204:  // __neg__/2
  MACRO_goal(L204, atom(95));
  MACRO_requires(6);
  MACRO_try_guard_else(L206);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L205);  // call(integer/1)
 L205:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L208, 2);  // execute(__ineg__/2)
 L206:  // __neg__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L207);  // spawn((:=)/2)
 L207:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L208, 2);  // execute(__ineg__/2)
 L208:  // __ineg__/2
  MACRO_goal(L208, atom(96));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  MACRO_proceed;
 L209:  // __iadd__/3
  MACRO_goal(L209, atom(97));
  MACRO_requires(7);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 + v2;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(3));
  MACRO_proceed;
 L210:  // __isub__/3
  MACRO_goal(L210, atom(98));
  MACRO_requires(7);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 - v2;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(3));
  MACRO_proceed;
 L211:  // __imul__/3
  MACRO_goal(L211, atom(99));
  MACRO_requires(7);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 * v2;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(3));
  MACRO_proceed;
 L212:  // __idiv__/3
  MACRO_goal(L212, atom(100));
  MACRO_requires(7);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 / v2;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(3));
  MACRO_proceed;
 L213:  // __imod__/3
  MACRO_goal(L213, atom(101));
  MACRO_requires(7);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_wait_for(TAG_INT, reg::in(2));
  MACRO_activate;
  do {
    const int64_t v1 = value_of<int64_t>(vm->in[reg::in(1)]);
    const int64_t v2 = value_of<int64_t>(vm->in[reg::in(2)]);
    const int64_t v = v1 % v2;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(3));
  MACRO_proceed;
 L214:  // __inc__/2
  MACRO_goal(L214, atom(102));
  MACRO_requires(6);
  MACRO_try_guard_else(L216);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L215);  // call(integer/1)
 L215:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L222, 2);  // execute(__iinc__/2)
 L216:  // __inc__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L217);  // spawn((:=)/2)
 L217:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L222, 2);  // execute(__iinc__/2)
 L218:  // __dec__/2
  MACRO_goal(L218, atom(103));
  MACRO_requires(6);
  MACRO_try_guard_else(L220);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L149, L219);  // call(integer/1)
 L219:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L223, 2);  // execute(__idec__/2)
 L220:  // __dec__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L166, L221);  // spawn((:=)/2)
 L221:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L223, 2);  // execute(__idec__/2)
 L222:  // __iinc__/2
  MACRO_goal(L222, atom(104));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    ++v;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  MACRO_proceed;
 L223:  // __idec__/2
  MACRO_goal(L223, atom(105));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    int64_t v = value_of<int64_t>(vm->in[reg::in(1)]);
    --v;
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  MACRO_proceed;
 L224:  // append/3
  MACRO_goal(L224, atom(106));
  MACRO_requires(9);
  MACRO_try_guard_else(L225);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(2),reg::in(3));
  MACRO_proceed;
 L225:  // append/3-2
  MACRO_try_guard_else(L226);
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
  MACRO_execute(L224, 3);  // execute(append/3)
 L226:  // append/3-3
  MACRO_try_guard_else(L227);
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
  MACRO_execute(L224, 3);  // execute(append/3)
 L227:  // append/3-4
  MACRO_try_guard_else_suspend;
  MACRO_seq(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L228);  // call(var/1)
 L228:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_spawn(L232, L229);  // spawn(reverse/2)
 L229:  // return_from_spawn(reverse/2)
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_variable(reg::x(5),reg::out(2));
  MACRO_spawn(L232, L230);  // spawn(reverse/2)
 L230:  // return_from_spawn(reverse/2)
  MACRO_par(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_spawn(L224, L231);  // spawn(append/3)
 L231:  // return_from_spawn(append/3)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L232, 2);  // execute(reverse/2)
 L232:  // reverse/2
  MACRO_goal(L232, atom(107));
  MACRO_requires(6);
  MACRO_try_guard_else(L234);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L233);  // call(var/1)
 L233:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_nil(reg::out(3));
  MACRO_execute(L236, 3);  // execute(__reverse__/3)
 L234:  // reverse/2-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L235);  // call(var/1)
 L235:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_out_nil(reg::out(3));
  MACRO_execute(L236, 3);  // execute(__reverse__/3)
 L236:  // __reverse__/3
  MACRO_goal(L236, atom(108));
  MACRO_requires(10);
  MACRO_try_guard_else(L237);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(2));
  MACRO_proceed;
 L237:  // __reverse__/3-2
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
  MACRO_execute(L236, 3);  // execute(__reverse__/3)
 L238:  // nth0/3
  MACRO_goal(L238, atom(109));
  MACRO_requires(8);
  MACRO_try_guard_else(L240);
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L151, L239);  // call(var/1)
 L239:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L242, 3);  // execute(__nth0__/3)
 L240:  // nth0/3-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L241);  // call(var/1)
 L241:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_execute(L245, 4);  // execute(__nth0_rev__/4)
 L242:  // __nth0__/3
  MACRO_goal(L242, atom(110));
  MACRO_requires(9);
  MACRO_try_guard_else(L243);
  MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_void;
  MACRO_activate;
  MACRO_get_value(reg::x(4),reg::in(3));
  MACRO_proceed;
 L243:  // __nth0__/3-2
  MACRO_otherwise;
  MACRO_check_list(reg::in(2));
  MACRO_read_void;
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_variable(reg::x(5),reg::out(2));
  MACRO_call(L218, L244);  // call(__dec__/2)
 L244:  // return_from_call(__dec__/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L242, 3);  // execute(__nth0__/3)
 L245:  // __nth0_rev__/4
  MACRO_goal(L245, atom(111));
  MACRO_requires(11);
  MACRO_try_guard_else(L246);
  MACRO_check_list(reg::in(2));
  MACRO_read_value(reg::in(3));
  MACRO_read_void;
  MACRO_activate;
  MACRO_get_value(reg::in(4),reg::in(1));
  MACRO_proceed;
 L246:  // __nth0_rev__/4-2
  MACRO_otherwise;
  MACRO_check_list(reg::in(2));
  MACRO_read_void;
  MACRO_read_variable(reg::x(5));
  MACRO_activate;
  MACRO_par(7);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_variable(reg::x(6),reg::out(2));
  MACRO_call(L214, L247);  // call(__inc__/2)
 L247:  // return_from_call(__inc__/2)
  MACRO_tail(7);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(6),reg::out(4));
  MACRO_execute(L245, 4);  // execute(__nth0_rev__/4)
 L248:  // nth1/3
  MACRO_goal(L248, atom(112));
  MACRO_requires(9);
  MACRO_try_guard_else(L251);
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L151, L249);  // call(var/1)
 L249:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_call(L218, L250);  // call(__dec__/2)
 L250:  // return_from_call(__dec__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L242, 3);  // execute(__nth0__/3)
 L251:  // nth1/3-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L252);  // call(var/1)
 L252:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_spawn(L245, L253);  // spawn(__nth0_rev__/4)
 L253:  // return_from_spawn(__nth0_rev__/4)
  MACRO_tail(5);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L214, 2);  // execute(__inc__/2)
 L254:  // inference_count/1
  MACRO_goal(L254, atom(113));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L255, 1);  // execute(__inference_count__/1)
 L255:  // __inference_count__/1
  MACRO_goal(L255, atom(114));
  MACRO_requires(3);
  MACRO_activate;
  do {
    if (!vm->unify(tagvalue<TAG_INT>(vm->inference_count), vm->in[1])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L256:  // resume_count/1
  MACRO_goal(L256, atom(115));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L257, 1);  // execute(__resume_count__/1)
 L257:  // __resume_count__/1
  MACRO_goal(L257, atom(116));
  MACRO_requires(3);
  MACRO_activate;
  do {
    if (!vm->unify(tagvalue<TAG_INT>(vm->resume_count), vm->in[1])) {
      vm->fail();
      break;
    }
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L258:  // dump_to_dot/1
  MACRO_goal(L258, atom(117));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L259);  // call(atom/1)
 L259:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L260, 1);  // execute(__dump_to_dot__/1)
 L260:  // __dump_to_dot__/1
  MACRO_goal(L260, atom(118));
  MACRO_requires(3);
  MACRO_activate;
  do {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L261:  // dump_to_dot/2
  MACRO_goal(L261, atom(119));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L150, L262);  // call(atom/1)
 L262:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L263, 2);  // execute(__dump_to_dot__/2)
 L263:  // __dump_to_dot__/2
  MACRO_goal(L263, atom(120));
  MACRO_requires(5);
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
    vm->proceed();
  } while (0);
  goto *(vm->pc);
 L264:  // main/1
  MACRO_goal(L264, atom(121));
  MACRO_requires(6);
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_void;
  MACRO_read_variable(reg::x(2));
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_list(reg::out(1));
  MACRO_write_structure(atom(28));
  MACRO_write_constant(atom(122));
  MACRO_write_variable(reg::x(3));
  MACRO_spawn(L46, L265);  // spawn(outstream/1)
 L265:  // return_from_spawn(outstream/1)
  MACRO_tail(4);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L266, 2);  // execute(writes/2)
 L266:  // writes/2
  MACRO_goal(L266, atom(123));
  MACRO_requires(7);
  MACRO_try_guard_else(L267);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_list(reg::in(2));
  MACRO_unify_constant(atom(32));
  MACRO_unify_nil;
  MACRO_proceed;
 L267:  // writes/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_get_list(reg::in(2));
  MACRO_unify_structure(atom(28));
  MACRO_unify_value(reg::x(4));
  MACRO_unify_list;
  MACRO_unify_structure(atom(28));
  MACRO_unify_constant(atom(124));
  MACRO_unify_variable(reg::x(4));
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_execute(L266, 2);  // execute(writes/2)
 LNO_MORE_GOALS:
  return;
}
int
main(int argc, char* argv[]) {
  Program prog;
  std::vector<VM::ptr> vms;
  vms.push_back(std::make_shared<VM>());
  VM::ptr vm = vms[0];
  module(vm, &prog, true);
  void* pc = prog.query_entry_point(to_atom("main", 1));
  if (!pc) {
    std::cerr << "failed to find main/1 predicate" << std::endl;
    return 1;
  }
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
  vm->heap[h + 3].store(reinterpret_cast<intptr_t>(pc));
  vm->heap[h + 4].store(to_atom("main", 1));
  vm->heap[h + 5].store(tagptr<TAG_LIST, A>(head));
  vm->heap_published(6);
  A* lst = &vm->heap[h + 0];
  Scheduler::getInstance().enqueue_list(lst);
  vm->run(module, &prog);
}
