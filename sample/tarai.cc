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
Q atom(123);  // tarai / 4
Q atom(124);  // report / 1
Q atom(125);  // main / 1
Q atom(126);  // dump/tarai.dot / 0
Q atom(127);  // usage:  / 0
Q atom(128);  //  X Y Z / 0
void module(VM::ptr vm, Program* prog, bool setup) {
  if (setup) {
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
    atom(123) = to_atom("tarai", 4);
    atom(124) = to_atom("report", 1);
    atom(125) = to_atom("main", 1);
    atom(126) = to_atom("dump/tarai.dot", 0);
    atom(127) = to_atom("usage: ", 0);
    atom(128) = to_atom(" X Y Z", 0);
    // setup entry points
    prog->add_entry_point(atom(1), &&L1);  // fail / 0
    prog->add_entry_point(atom(2), &&L2);  // call / 1
    prog->add_entry_point(atom(3), &&L3);  // __call__ / 1
    prog->add_entry_point(atom(4), &&L4);  // call / 3
    prog->add_entry_point(atom(5), &&L5);  // __call__ / 3
    prog->add_entry_point(atom(6), &&L6);  // time / 1
    prog->add_entry_point(atom(7), &&L9);  // wait_time / 1
    prog->add_entry_point(atom(8), &&L11);  // __wait_time__ / 4
    prog->add_entry_point(atom(9), &&L12);  // __time_pre__ / 3
    prog->add_entry_point(atom(10), &&L13);  // __time_post__ / 3
    prog->add_entry_point(atom(11), &&L14);  // atom_concat / 3
    prog->add_entry_point(atom(12), &&L23);  // __atom_concat_1__ / 3
    prog->add_entry_point(atom(13), &&L24);  // __atom_concat_2__ / 3
    prog->add_entry_point(atom(14), &&L25);  // __atom_concat_3__ / 3
    prog->add_entry_point(atom(15), &&L26);  // atom_codes / 2
    prog->add_entry_point(atom(17), &&L29);  // __atom_to_codes__ / 2
    prog->add_entry_point(atom(18), &&L30);  // __codes_to_atom__ / 3
    prog->add_entry_point(atom(19), &&L34);  // __atom_code_concat__ / 3
    prog->add_entry_point(atom(20), &&L35);  // atom_chars / 2
    prog->add_entry_point(atom(21), &&L38);  // __atom_to_chars__ / 2
    prog->add_entry_point(atom(22), &&L39);  // __chars_to_atom__ / 3
    prog->add_entry_point(atom(23), &&L42);  // atom_number / 2
    prog->add_entry_point(atom(24), &&L46);  // __atom_to_number__ / 2
    prog->add_entry_point(atom(25), &&L47);  // __number_to_atom__ / 2
    prog->add_entry_point(atom(26), &&L48);  // outstream / 1
    prog->add_entry_point(atom(27), &&L50);  // outstream / 2
    prog->add_entry_point(atom(28), &&L64);  // open / 3
    prog->add_entry_point(atom(35), &&L66);  // close / 1
    prog->add_entry_point(atom(36), &&L67);  // __open_opt_string_to_integer__ / 3
    prog->add_entry_point(atom(37), &&L68);  // __open_opt_string_to_integer__ / 5
    prog->add_entry_point(atom(54), &&L100);  // __open__ / 4
    prog->add_entry_point(atom(55), &&L101);  // __close__ / 1
    prog->add_entry_point(atom(32), &&L102);  // writeln / 1
    prog->add_entry_point(atom(31), &&L104);  // writeln / 2
    prog->add_entry_point(atom(34), &&L106);  // nl / 0
    prog->add_entry_point(atom(33), &&L107);  // nl / 1
    prog->add_entry_point(atom(56), &&L109);  // __nl__ / 1
    prog->add_entry_point(atom(30), &&L110);  // write / 1
    prog->add_entry_point(atom(29), &&L111);  // write / 2
    prog->add_entry_point(atom(57), &&L113);  // __write__ / 2
    prog->add_entry_point(atom(61), &&L128);  // __write_functor_args__ / 2
    prog->add_entry_point(atom(64), &&L132);  // __write_functor_args2__ / 2
    prog->add_entry_point(atom(65), &&L135);  // __write_functor_tail__ / 2
    prog->add_entry_point(atom(67), &&L139);  // __write_list_tail__ / 2
    prog->add_entry_point(atom(69), &&L148);  // __write_number__ / 2
    prog->add_entry_point(atom(70), &&L149);  // __write_atom__ / 2
    prog->add_entry_point(atom(71), &&L150);  // __write_var__ / 2
    prog->add_entry_point(atom(72), &&L151);  // integer / 1
    prog->add_entry_point(atom(73), &&L152);  // atom / 1
    prog->add_entry_point(atom(74), &&L153);  // var / 1
    prog->add_entry_point(atom(75), &&L154);  // is_functor / 1
    prog->add_entry_point(atom(76), &&L155);  // =.. / 2
    prog->add_entry_point(atom(77), &&L156);  // == / 2
    prog->add_entry_point(atom(78), &&L157);  // >= / 2
    prog->add_entry_point(atom(79), &&L158);  // =< / 2
    prog->add_entry_point(atom(80), &&L159);  // > / 2
    prog->add_entry_point(atom(81), &&L160);  // < / 2
    prog->add_entry_point(atom(82), &&L161);  // =:= / 2
    prog->add_entry_point(atom(83), &&L164);  // =\= / 2
    prog->add_entry_point(atom(84), &&L167);  // __not_equal__ / 2
    prog->add_entry_point(atom(85), &&L168);  // := / 2
    prog->add_entry_point(atom(92), &&L176);  // __add__ / 3
    prog->add_entry_point(atom(93), &&L182);  // __sub__ / 3
    prog->add_entry_point(atom(94), &&L188);  // __mul__ / 3
    prog->add_entry_point(atom(95), &&L194);  // __div__ / 3
    prog->add_entry_point(atom(96), &&L200);  // __mod__ / 3
    prog->add_entry_point(atom(97), &&L206);  // __neg__ / 2
    prog->add_entry_point(atom(98), &&L210);  // __ineg__ / 2
    prog->add_entry_point(atom(99), &&L211);  // __iadd__ / 3
    prog->add_entry_point(atom(100), &&L212);  // __isub__ / 3
    prog->add_entry_point(atom(101), &&L213);  // __imul__ / 3
    prog->add_entry_point(atom(102), &&L214);  // __idiv__ / 3
    prog->add_entry_point(atom(103), &&L215);  // __imod__ / 3
    prog->add_entry_point(atom(104), &&L216);  // __inc__ / 2
    prog->add_entry_point(atom(105), &&L220);  // __dec__ / 2
    prog->add_entry_point(atom(106), &&L224);  // __iinc__ / 2
    prog->add_entry_point(atom(107), &&L225);  // __idec__ / 2
    prog->add_entry_point(atom(108), &&L226);  // append / 3
    prog->add_entry_point(atom(109), &&L234);  // reverse / 2
    prog->add_entry_point(atom(110), &&L238);  // __reverse__ / 3
    prog->add_entry_point(atom(111), &&L240);  // nth0 / 3
    prog->add_entry_point(atom(112), &&L244);  // __nth0__ / 3
    prog->add_entry_point(atom(113), &&L247);  // __nth0_rev__ / 4
    prog->add_entry_point(atom(114), &&L250);  // nth1 / 3
    prog->add_entry_point(atom(115), &&L256);  // inference_count / 1
    prog->add_entry_point(atom(116), &&L257);  // __inference_count__ / 1
    prog->add_entry_point(atom(117), &&L258);  // resume_count / 1
    prog->add_entry_point(atom(118), &&L259);  // __resume_count__ / 1
    prog->add_entry_point(atom(119), &&L260);  // dump_to_dot / 1
    prog->add_entry_point(atom(120), &&L262);  // __dump_to_dot__ / 1
    prog->add_entry_point(atom(121), &&L263);  // dump_to_dot / 2
    prog->add_entry_point(atom(122), &&L265);  // __dump_to_dot__ / 2
    prog->add_entry_point(atom(123), &&L266);  // tarai / 4
    prog->add_entry_point(atom(124), &&L275);  // report / 1
    prog->add_entry_point(atom(125), &&L276);  // main / 1
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
 L4:  // call/3
  MACRO_goal(L4, atom(4));
  MACRO_requires(7);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L5, 3);  // execute(__call__/3)
 L5:  // __call__/3
  MACRO_goal(L5, atom(5));
  MACRO_requires(7);
  MACRO_wait(reg::in(1));
  do {
    const Q q = vm->in[1];
    const Q u = vm->in[2];
    const Q v = vm->in[3];
    const TAG_T tag = tag_of(q);
    if (tag == TAG_ATOM) {
      MACRO_activate;
      const std::string s = atom_str_of(q);
      const Q g = to_atom(s.c_str(), 2);
      void* pc = prog->query_entry_point(g);
      if (pc == NULL) {
        vm->fail();
        break;
      }
      MACRO_tail(4);
      MACRO_out_constant(u, reg::out(1));
      MACRO_out_constant(v, reg::out(2));
      MACRO_execute2(pc, 2);
      break;
    } else if (tag == TAG_STR) {
      MACRO_activate;
      A* structure = ptr_of<A>(q);
      Q g = structure[0].load();
      const std::string s = atom_str_of(g);
      const int arity = atom_arity_of(g);
      g = to_atom(s.c_str(), arity + 2);
      void* pc = prog->query_entry_point(g);
      if (pc == NULL) {
        vm->fail();
        break;
      }
      MACRO_tail(4);
      for (int i = 1; i <= arity; ++i) {
        MACRO_out_constant(structure[i].load(), reg::out(i));
      }
      MACRO_out_constant(u, reg::out(arity + 1));
      MACRO_out_constant(v, reg::out(arity + 2));
      MACRO_execute2(pc, arity + 2);
      break;
    } else {
      vm->fail();
      break;
    }
  } while(0);
  vm->failed = false;
  goto *(vm->pc);
 L6:  // time/1
  MACRO_goal(L6, atom(6));
  MACRO_requires(8);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_variable(reg::x(2),reg::out(1));
  MACRO_out_variable(reg::x(3),reg::out(2));
  MACRO_out_variable(reg::x(4),reg::out(3));
  MACRO_call(L12, L7);  // call(__time_pre__/3)
 L7:  // return_from_call(__time_pre__/3)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L2, L8);  // call(call/1)
 L8:  // return_from_call(call/1)
  MACRO_tail(5);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_out_value(reg::x(4),reg::out(3));
  MACRO_execute(L13, 3);  // execute(__time_post__/3)
 L9:  // wait_time/1
  MACRO_goal(L9, atom(7));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(2),reg::out(1));
  MACRO_out_variable(reg::x(3),reg::out(2));
  MACRO_out_variable(reg::x(4),reg::out(3));
  MACRO_spawn(L12, L10);  // spawn(__time_pre__/3)
 L10:  // return_from_spawn(__time_pre__/3)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(2),reg::out(2));
  MACRO_out_value(reg::x(3),reg::out(3));
  MACRO_out_value(reg::x(4),reg::out(4));
  MACRO_execute(L11, 4);  // execute(__wait_time__/4)
 L11:  // __wait_time__/4
  MACRO_goal(L11, atom(8));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_wait(reg::in(1));
  MACRO_activate;
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_value(reg::in(3),reg::out(2));
  MACRO_out_value(reg::in(4),reg::out(3));
  MACRO_execute(L13, 3);  // execute(__time_post__/3)
 L12:  // __time_pre__/3
  MACRO_goal(L12, atom(9));
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
 L13:  // __time_post__/3
  MACRO_goal(L13, atom(10));
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
 L14:  // atom_concat/3
  MACRO_goal(L14, atom(11));
  MACRO_requires(7);
  MACRO_try_guard_else(L17);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L15);  // call(atom/1)
 L15:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L152, L16);  // call(atom/1)
 L16:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L23, 3);  // execute(__atom_concat_1__/3)
 L17:  // atom_concat/3-2
  MACRO_try_guard_else(L20);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L18);  // call(atom/1)
 L18:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L152, L19);  // call(atom/1)
 L19:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L24, 3);  // execute(__atom_concat_2__/3)
 L20:  // atom_concat/3-3
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L152, L21);  // call(atom/1)
 L21:  // return_from_call(atom/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L152, L22);  // call(atom/1)
 L22:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L25, 3);  // execute(__atom_concat_3__/3)
 L23:  // __atom_concat_1__/3
  MACRO_goal(L23, atom(12));
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
 L24:  // __atom_concat_2__/3
  MACRO_goal(L24, atom(13));
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
 L25:  // __atom_concat_3__/3
  MACRO_goal(L25, atom(14));
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
 L26:  // atom_codes/2
  MACRO_goal(L26, atom(15));
  MACRO_requires(8);
  MACRO_try_guard_else(L28);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L27);  // call(atom/1)
 L27:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L29, 2);  // execute(__atom_to_codes__/2)
 L28:  // atom_codes/2-2
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
  MACRO_execute(L30, 3);  // execute(__codes_to_atom__/3)
 L29:  // __atom_to_codes__/2
  MACRO_goal(L29, atom(17));
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
 L30:  // __codes_to_atom__/3
  MACRO_goal(L30, atom(18));
  MACRO_requires(9);
  MACRO_try_guard_else(L31);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(1));
  MACRO_proceed;
 L31:  // __codes_to_atom__/3-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(5));
  MACRO_read_variable(reg::x(4));
  MACRO_seq(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_call(L151, L32);  // call(integer/1)
 L32:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L34, L33);  // spawn(__atom_code_concat__/3)
 L33:  // return_from_spawn(__atom_code_concat__/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_execute(L30, 3);  // execute(__codes_to_atom__/3)
 L34:  // __atom_code_concat__/3
  MACRO_goal(L34, atom(19));
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
 L35:  // atom_chars/2
  MACRO_goal(L35, atom(20));
  MACRO_requires(8);
  MACRO_try_guard_else(L37);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L36);  // call(atom/1)
 L36:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L38, 2);  // execute(__atom_to_chars__/2)
 L37:  // atom_chars/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(3),reg::out(3));
  MACRO_execute(L39, 3);  // execute(__chars_to_atom__/3)
 L38:  // __atom_to_chars__/2
  MACRO_goal(L38, atom(21));
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
 L39:  // __chars_to_atom__/3
  MACRO_goal(L39, atom(22));
  MACRO_requires(9);
  MACRO_try_guard_else(L40);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(1));
  MACRO_proceed;
 L40:  // __chars_to_atom__/3-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(5));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L14, L41);  // spawn(atom_concat/3)
 L41:  // return_from_spawn(atom_concat/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_execute(L39, 3);  // execute(__chars_to_atom__/3)
 L42:  // atom_number/2
  MACRO_goal(L42, atom(23));
  MACRO_requires(5);
  MACRO_try_guard_else(L44);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L43);  // call(atom/1)
 L43:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L46, 2);  // execute(__atom_to_number__/2)
 L44:  // atom_number/2-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L45);  // call(integer/1)
 L45:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L47, 2);  // execute(__number_to_atom__/2)
 L46:  // __atom_to_number__/2
  MACRO_goal(L46, atom(24));
  MACRO_requires(5);
  MACRO_activate;
  do {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    const int64_t i = std::stoll(s);
    MACRO_set_constant(tagvalue<TAG_INT>(i), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  MACRO_proceed;
 L47:  // __number_to_atom__/2
  MACRO_goal(L47, atom(25));
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
 L48:  // outstream/1
  MACRO_goal(L48, atom(26));
  MACRO_requires(6);
  MACRO_try_guard_else(L49);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_proceed;
 L49:  // outstream/1-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_variable(reg::x(2));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L50, 2);  // execute(outstream/2)
 L50:  // outstream/2
  MACRO_goal(L50, atom(27));
  MACRO_requires(9);
  MACRO_try_guard_else(L52);
  MACRO_check_structure(atom(28),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(5));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_spawn(L64, L51);  // spawn(open/3)
 L51:  // return_from_spawn(open/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L52:  // outstream/2-2
  MACRO_try_guard_else(L54);
  MACRO_check_structure(atom(29),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_spawn(L111, L53);  // spawn(write/2)
 L53:  // return_from_spawn(write/2)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L54:  // outstream/2-3
  MACRO_try_guard_else(L56);
  MACRO_check_structure(atom(30),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L110, L55);  // spawn(write/1)
 L55:  // return_from_spawn(write/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L56:  // outstream/2-4
  MACRO_try_guard_else(L58);
  MACRO_check_structure(atom(31),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_spawn(L104, L57);  // spawn(writeln/2)
 L57:  // return_from_spawn(writeln/2)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L58:  // outstream/2-5
  MACRO_try_guard_else(L60);
  MACRO_check_structure(atom(32),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L102, L59);  // spawn(writeln/1)
 L59:  // return_from_spawn(writeln/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L60:  // outstream/2-6
  MACRO_try_guard_else(L62);
  MACRO_check_structure(atom(33),reg::in(1));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_spawn(L107, L61);  // spawn(nl/1)
 L61:  // return_from_spawn(nl/1)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L62:  // outstream/2-7
  MACRO_try_guard_else_suspend;
  MACRO_check_constant(atom(34),reg::in(1));
  MACRO_activate;
  MACRO_par(6);
  MACRO_spawn(L106, L63);  // spawn(nl/0)
 L63:  // return_from_spawn(nl/0)
  MACRO_tail(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L64:  // open/3
  MACRO_goal(L64, atom(28));
  MACRO_requires(10);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_out_variable(reg::x(5),reg::out(3));
  MACRO_spawn(L67, L65);  // spawn(__open_opt_string_to_integer__/3)
 L65:  // return_from_spawn(__open_opt_string_to_integer__/3)
  MACRO_tail(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_out_value(reg::in(3),reg::out(4));
  MACRO_execute(L100, 4);  // execute(__open__/4)
 L66:  // close/1
  MACRO_goal(L66, atom(35));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L101, 1);  // execute(__close__/1)
 L67:  // __open_opt_string_to_integer__/3
  MACRO_goal(L67, atom(36));
  MACRO_requires(9);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L68:  // __open_opt_string_to_integer__/5
  MACRO_goal(L68, atom(37));
  MACRO_requires(13);
  MACRO_try_guard_else(L69);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(4),reg::in(2));
  MACRO_get_value(reg::in(5),reg::in(3));
  MACRO_proceed;
 L69:  // __open_opt_string_to_integer__/5-2
  MACRO_try_guard_else(L70);
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
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L70:  // __open_opt_string_to_integer__/5-3
  MACRO_try_guard_else(L72);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(39));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_variable(reg::x(7),reg::out(2));
  MACRO_call(L216, L71);  // call(__inc__/2)
 L71:  // return_from_call(__inc__/2)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L72:  // __open_opt_string_to_integer__/5-4
  MACRO_try_guard_else(L74);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(40));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L73);  // call(__add__/3)
 L73:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L74:  // __open_opt_string_to_integer__/5-5
  MACRO_try_guard_else(L76);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(41));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L75);  // call(__add__/3)
 L75:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L76:  // __open_opt_string_to_integer__/5-6
  MACRO_try_guard_else(L78);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(42));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L77);  // call(__add__/3)
 L77:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L78:  // __open_opt_string_to_integer__/5-7
  MACRO_try_guard_else(L80);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(43));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(512),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L79);  // call(__add__/3)
 L79:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L80:  // __open_opt_string_to_integer__/5-8
  MACRO_try_guard_else(L82);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(44));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(1024),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L81);  // call(__add__/3)
 L81:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(7),reg::out(4));
  MACRO_out_value(reg::in(5),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L82:  // __open_opt_string_to_integer__/5-9
  MACRO_try_guard_else(L84);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(45));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(256),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L83);  // call(__add__/3)
 L83:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L84:  // __open_opt_string_to_integer__/5-10
  MACRO_try_guard_else(L86);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(46));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(128),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L85);  // call(__add__/3)
 L85:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L86:  // __open_opt_string_to_integer__/5-11
  MACRO_try_guard_else(L88);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(47));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(64),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L87);  // call(__add__/3)
 L87:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L88:  // __open_opt_string_to_integer__/5-12
  MACRO_try_guard_else(L90);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(48));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(32),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L89);  // call(__add__/3)
 L89:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L90:  // __open_opt_string_to_integer__/5-13
  MACRO_try_guard_else(L92);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(49));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(16),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L91);  // call(__add__/3)
 L91:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L92:  // __open_opt_string_to_integer__/5-14
  MACRO_try_guard_else(L94);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(50));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(8),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L93);  // call(__add__/3)
 L93:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L94:  // __open_opt_string_to_integer__/5-15
  MACRO_try_guard_else(L96);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(51));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(4),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L95);  // call(__add__/3)
 L95:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L96:  // __open_opt_string_to_integer__/5-16
  MACRO_try_guard_else(L98);
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(52));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_constant(tagvalue<TAG_INT>(2),reg::out(2));
  MACRO_out_variable(reg::x(7),reg::out(3));
  MACRO_call(L176, L97);  // call(__add__/3)
 L97:  // return_from_call(__add__/3)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L98:  // __open_opt_string_to_integer__/5-17
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(1));
  MACRO_read_constant(atom(53));
  MACRO_read_variable(reg::x(6));
  MACRO_activate;
  MACRO_par(8);
  MACRO_out_value(reg::in(5),reg::out(1));
  MACRO_out_variable(reg::x(7),reg::out(2));
  MACRO_call(L216, L99);  // call(__inc__/2)
 L99:  // return_from_call(__inc__/2)
  MACRO_tail(8);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_out_value(reg::x(7),reg::out(5));
  MACRO_execute(L68, 5);  // execute(__open_opt_string_to_integer__/5)
 L100:  // __open__/4
  MACRO_goal(L100, atom(54));
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
 L101:  // __close__/1
  MACRO_goal(L101, atom(55));
  MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    const int fd = tagvalue<TAG_INT>(vm->in[1]);
    close(fd);
  } while (0);
  MACRO_proceed;
 L102:  // writeln/1
  MACRO_goal(L102, atom(32));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L110, L103);  // call(write/1)
 L103:  // return_from_call(write/1)
  MACRO_tail(3);
  MACRO_execute(L106, 0);  // execute(nl/0)
 L104:  // writeln/2
  MACRO_goal(L104, atom(31));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L111, L105);  // spawn(write/2)
 L105:  // return_from_spawn(write/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L107, 1);  // execute(nl/1)
 L106:  // nl/0
  MACRO_goal(L106, atom(34));
  MACRO_requires(2);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(2);
  MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
  MACRO_execute(L107, 1);  // execute(nl/1)
 L107:  // nl/1
  MACRO_goal(L107, atom(33));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L108);  // call(integer/1)
 L108:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L109, 1);  // execute(__nl__/1)
 L109:  // __nl__/1
  MACRO_goal(L109, atom(56));
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
  } while (0);
  MACRO_proceed;
 L110:  // write/1
  MACRO_goal(L110, atom(30));
  MACRO_requires(4);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_constant(tagvalue<TAG_INT>(1),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L111, 2);  // execute(write/2)
 L111:  // write/2
  MACRO_goal(L111, atom(29));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L112);  // call(integer/1)
 L112:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L113:  // __write__/2
  MACRO_goal(L113, atom(57));
  MACRO_requires(7);
  MACRO_try_guard_else(L115);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L152, L114);  // call(atom/1)
 L114:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L149, 2);  // execute(__write_atom__/2)
 L115:  // __write__/2-2
  MACRO_try_guard_else(L117);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L153, L116);  // call(var/1)
 L116:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L150, 2);  // execute(__write_var__/2)
 L117:  // __write__/2-3
  MACRO_try_guard_else(L119);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L118);  // call(integer/1)
 L118:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L148, 2);  // execute(__write_number__/2)
 L119:  // __write__/2-4
  MACRO_try_guard_else(L120);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(58),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L120:  // __write__/2-5
  MACRO_try_guard_else(L124);
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(59),reg::out(2));
  MACRO_call(L113, L121);  // call(__write__/2)
 L121:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L113, L122);  // call(__write__/2)
 L122:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_call(L139, L123);  // call(__write_list_tail__/2)
 L123:  // return_from_call(__write_list_tail__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(60),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L124:  // __write__/2-6
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L154, L125);  // call(is_functor/1)
 L125:  // return_from_call(is_functor/1)
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_list(reg::out(2));
  MACRO_write_variable(reg::x(4));
  MACRO_write_variable(reg::x(3));
  MACRO_call(L155, L126);  // call((=..)/2)
 L126:  // return_from_call((=..)/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L113, L127);  // call(__write__/2)
 L127:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L128, 2);  // execute(__write_functor_args__/2)
 L128:  // __write_functor_args__/2
  MACRO_goal(L128, atom(61));
  MACRO_requires(5);
  MACRO_try_guard_else(L129);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L129:  // __write_functor_args__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(62),reg::out(2));
  MACRO_call(L113, L130);  // call(__write__/2)
 L130:  // return_from_call(__write__/2)
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_call(L132, L131);  // call(__write_functor_args2__/2)
 L131:  // return_from_call(__write_functor_args2__/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(63),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L132:  // __write_functor_args2__/2
  MACRO_goal(L132, atom(64));
  MACRO_requires(7);
  MACRO_try_guard_else(L133);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L133:  // __write_functor_args2__/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L113, L134);  // call(__write__/2)
 L134:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L135, 2);  // execute(__write_functor_tail__/2)
 L135:  // __write_functor_tail__/2
  MACRO_goal(L135, atom(65));
  MACRO_requires(7);
  MACRO_try_guard_else(L136);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L136:  // __write_functor_tail__/2-2
  MACRO_try_guard_else_suspend;
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(66),reg::out(2));
  MACRO_call(L113, L137);  // call(__write__/2)
 L137:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L113, L138);  // call(__write__/2)
 L138:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L135, 2);  // execute(__write_functor_tail__/2)
 L139:  // __write_list_tail__/2
  MACRO_goal(L139, atom(67));
  MACRO_requires(7);
  MACRO_try_guard_else(L142);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L153, L140);  // call(var/1)
 L140:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(68),reg::out(2));
  MACRO_call(L113, L141);  // call(__write__/2)
 L141:  // return_from_call(__write__/2)
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L142:  // __write_list_tail__/2-2
  MACRO_try_guard_else(L143);
  MACRO_check_nil(reg::in(2));
  MACRO_activate;
  MACRO_proceed;
 L143:  // __write_list_tail__/2-3
  MACRO_try_guard_else(L146);
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(66),reg::out(2));
  MACRO_call(L113, L144);  // call(__write__/2)
 L144:  // return_from_call(__write__/2)
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_call(L113, L145);  // call(__write__/2)
 L145:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_execute(L139, 2);  // execute(__write_list_tail__/2)
 L146:  // __write_list_tail__/2-4
  MACRO_otherwise;
  MACRO_activate;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_constant(atom(68),reg::out(2));
  MACRO_call(L113, L147);  // call(__write__/2)
 L147:  // return_from_call(__write__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L113, 2);  // execute(__write__/2)
 L148:  // __write_number__/2
  MACRO_goal(L148, atom(69));
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
  } while (0);
  MACRO_proceed;
 L149:  // __write_atom__/2
  MACRO_goal(L149, atom(70));
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
  } while (0);
  MACRO_proceed;
 L150:  // __write_var__/2
  MACRO_goal(L150, atom(71));
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
  } while (0);
  MACRO_proceed;
 L151:  // integer/1
  MACRO_goal(L151, atom(72));
  MACRO_requires(3);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_return;
  goto *(vm->pc);
 L152:  // atom/1
  MACRO_goal(L152, atom(73));
  MACRO_requires(3);
  MACRO_wait_for(TAG_ATOM, reg::in(1));
  MACRO_return;
  goto *(vm->pc);
 L153:  // var/1
  MACRO_goal(L153, atom(74));
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
 L154:  // is_functor/1
  MACRO_goal(L154, atom(75));
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
 L155:  // (=..)/2
  MACRO_goal(L155, atom(76));
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
 L156:  // (==)/2
  MACRO_goal(L156, atom(77));
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
 L157:  // (>=)/2
  MACRO_goal(L157, atom(78));
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
 L158:  // (=<)/2
  MACRO_goal(L158, atom(79));
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
 L159:  // (>)/2
  MACRO_goal(L159, atom(80));
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
 L160:  // (<)/2
  MACRO_goal(L160, atom(81));
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
 L161:  // (=:=)/2
  MACRO_goal(L161, atom(82));
  MACRO_requires(7);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L162);  // spawn((:=)/2)
 L162:  // return_from_spawn((:=)/2)
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L163);  // spawn((:=)/2)
 L163:  // return_from_spawn((:=)/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_execute(L156, 2);  // execute((==)/2)
 L164:  // (=\=)/2
  MACRO_goal(L164, atom(83));
  MACRO_requires(7);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L165);  // spawn((:=)/2)
 L165:  // return_from_spawn((:=)/2)
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L166);  // spawn((:=)/2)
 L166:  // return_from_spawn((:=)/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_execute(L167, 2);  // execute(__not_equal__/2)
 L167:  // __not_equal__/2
  MACRO_goal(L167, atom(84));
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
 L168:  // (:=)/2
  MACRO_goal(L168, atom(85));
  MACRO_requires(8);
  MACRO_try_guard_else(L170);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L169);  // call(integer/1)
 L169:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_get_value(reg::in(1),reg::in(2));
  MACRO_proceed;
 L170:  // (:=)/2-2
  MACRO_try_guard_else(L171);
  MACRO_check_structure(atom(86),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L176, 3);  // execute(__add__/3)
 L171:  // (:=)/2-3
  MACRO_try_guard_else(L172);
  MACRO_check_structure(atom(87),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L182, 3);  // execute(__sub__/3)
 L172:  // (:=)/2-4
  MACRO_try_guard_else(L173);
  MACRO_check_structure(atom(88),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L188, 3);  // execute(__mul__/3)
 L173:  // (:=)/2-5
  MACRO_try_guard_else(L174);
  MACRO_check_structure(atom(89),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L194, 3);  // execute(__div__/3)
 L174:  // (:=)/2-6
  MACRO_try_guard_else(L175);
  MACRO_check_structure(atom(90),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_execute(L200, 3);  // execute(__mod__/3)
 L175:  // (:=)/2-7
  MACRO_try_guard_else_suspend;
  MACRO_check_structure(atom(91),reg::in(2));
  MACRO_read_variable(reg::x(3));
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L206, 2);  // execute(__neg__/2)
 L176:  // __add__/3
  MACRO_goal(L176, atom(92));
  MACRO_requires(9);
  MACRO_try_guard_else(L179);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L177);  // call(integer/1)
 L177:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L178);  // call(integer/1)
 L178:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L211, 3);  // execute(__iadd__/3)
 L179:  // __add__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L180);  // spawn((:=)/2)
 L180:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L181);  // spawn((:=)/2)
 L181:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L211, 3);  // execute(__iadd__/3)
 L182:  // __sub__/3
  MACRO_goal(L182, atom(93));
  MACRO_requires(9);
  MACRO_try_guard_else(L185);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L183);  // call(integer/1)
 L183:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L184);  // call(integer/1)
 L184:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L212, 3);  // execute(__isub__/3)
 L185:  // __sub__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L186);  // spawn((:=)/2)
 L186:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L187);  // spawn((:=)/2)
 L187:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L212, 3);  // execute(__isub__/3)
 L188:  // __mul__/3
  MACRO_goal(L188, atom(94));
  MACRO_requires(9);
  MACRO_try_guard_else(L191);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L189);  // call(integer/1)
 L189:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L190);  // call(integer/1)
 L190:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L213, 3);  // execute(__imul__/3)
 L191:  // __mul__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L192);  // spawn((:=)/2)
 L192:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L193);  // spawn((:=)/2)
 L193:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L213, 3);  // execute(__imul__/3)
 L194:  // __div__/3
  MACRO_goal(L194, atom(95));
  MACRO_requires(9);
  MACRO_try_guard_else(L197);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L195);  // call(integer/1)
 L195:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L196);  // call(integer/1)
 L196:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L214, 3);  // execute(__idiv__/3)
 L197:  // __div__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L198);  // spawn((:=)/2)
 L198:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L199);  // spawn((:=)/2)
 L199:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L214, 3);  // execute(__idiv__/3)
 L200:  // __mod__/3
  MACRO_goal(L200, atom(96));
  MACRO_requires(9);
  MACRO_try_guard_else(L203);
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L201);  // call(integer/1)
 L201:  // return_from_call(integer/1)
  MACRO_seq(5);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L151, L202);  // call(integer/1)
 L202:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L215, 3);  // execute(__imod__/3)
 L203:  // __mod__/3-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L204);  // spawn((:=)/2)
 L204:  // return_from_spawn((:=)/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_spawn(L168, L205);  // spawn((:=)/2)
 L205:  // return_from_spawn((:=)/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L215, 3);  // execute(__imod__/3)
 L206:  // __neg__/2
  MACRO_goal(L206, atom(97));
  MACRO_requires(6);
  MACRO_try_guard_else(L208);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L207);  // call(integer/1)
 L207:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L210, 2);  // execute(__ineg__/2)
 L208:  // __neg__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L209);  // spawn((:=)/2)
 L209:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L210, 2);  // execute(__ineg__/2)
 L210:  // __ineg__/2
  MACRO_goal(L210, atom(98));
  MACRO_requires(5);
  MACRO_wait_for(TAG_INT, reg::in(1));
  MACRO_activate;
  do {
    const int64_t v = -value_of<int64_t>(reg::in(1));
    MACRO_set_constant(tagvalue<TAG_INT>(v), reg::in(10));
  } while (0);
  MACRO_get_value(reg::in(10), reg::in(2));
  MACRO_proceed;
 L211:  // __iadd__/3
  MACRO_goal(L211, atom(99));
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
 L212:  // __isub__/3
  MACRO_goal(L212, atom(100));
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
 L213:  // __imul__/3
  MACRO_goal(L213, atom(101));
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
 L214:  // __idiv__/3
  MACRO_goal(L214, atom(102));
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
 L215:  // __imod__/3
  MACRO_goal(L215, atom(103));
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
 L216:  // __inc__/2
  MACRO_goal(L216, atom(104));
  MACRO_requires(6);
  MACRO_try_guard_else(L218);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L217);  // call(integer/1)
 L217:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L224, 2);  // execute(__iinc__/2)
 L218:  // __inc__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L219);  // spawn((:=)/2)
 L219:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L224, 2);  // execute(__iinc__/2)
 L220:  // __dec__/2
  MACRO_goal(L220, atom(105));
  MACRO_requires(6);
  MACRO_try_guard_else(L222);
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L151, L221);  // call(integer/1)
 L221:  // return_from_call(integer/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L225, 2);  // execute(__idec__/2)
 L222:  // __dec__/2-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(4);
  MACRO_out_variable(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_spawn(L168, L223);  // spawn((:=)/2)
 L223:  // return_from_spawn((:=)/2)
  MACRO_tail(4);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L225, 2);  // execute(__idec__/2)
 L224:  // __iinc__/2
  MACRO_goal(L224, atom(106));
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
 L225:  // __idec__/2
  MACRO_goal(L225, atom(107));
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
 L226:  // append/3
  MACRO_goal(L226, atom(108));
  MACRO_requires(9);
  MACRO_try_guard_else(L227);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(2),reg::in(3));
  MACRO_proceed;
 L227:  // append/3-2
  MACRO_try_guard_else(L228);
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
  MACRO_execute(L226, 3);  // execute(append/3)
 L228:  // append/3-3
  MACRO_try_guard_else(L229);
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
  MACRO_execute(L226, 3);  // execute(append/3)
 L229:  // append/3-4
  MACRO_try_guard_else_suspend;
  MACRO_seq(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L153, L230);  // call(var/1)
 L230:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_spawn(L234, L231);  // spawn(reverse/2)
 L231:  // return_from_spawn(reverse/2)
  MACRO_par(6);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_variable(reg::x(5),reg::out(2));
  MACRO_spawn(L234, L232);  // spawn(reverse/2)
 L232:  // return_from_spawn(reverse/2)
  MACRO_par(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_out_value(reg::x(5),reg::out(3));
  MACRO_spawn(L226, L233);  // spawn(append/3)
 L233:  // return_from_spawn(append/3)
  MACRO_tail(6);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L234, 2);  // execute(reverse/2)
 L234:  // reverse/2
  MACRO_goal(L234, atom(109));
  MACRO_requires(6);
  MACRO_try_guard_else(L236);
  MACRO_seq(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_call(L153, L235);  // call(var/1)
 L235:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_nil(reg::out(3));
  MACRO_execute(L238, 3);  // execute(__reverse__/3)
 L236:  // reverse/2-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L153, L237);  // call(var/1)
 L237:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_out_nil(reg::out(3));
  MACRO_execute(L238, 3);  // execute(__reverse__/3)
 L238:  // __reverse__/3
  MACRO_goal(L238, atom(110));
  MACRO_requires(10);
  MACRO_try_guard_else(L239);
  MACRO_check_nil(reg::in(1));
  MACRO_activate;
  MACRO_get_value(reg::in(3),reg::in(2));
  MACRO_proceed;
 L239:  // __reverse__/3-2
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
  MACRO_execute(L238, 3);  // execute(__reverse__/3)
 L240:  // nth0/3
  MACRO_goal(L240, atom(111));
  MACRO_requires(8);
  MACRO_try_guard_else(L242);
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L153, L241);  // call(var/1)
 L241:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L244, 3);  // execute(__nth0__/3)
 L242:  // nth0/3-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L153, L243);  // call(var/1)
 L243:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_tail(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_execute(L247, 4);  // execute(__nth0_rev__/4)
 L244:  // __nth0__/3
  MACRO_goal(L244, atom(112));
  MACRO_requires(9);
  MACRO_try_guard_else(L245);
  MACRO_check_constant(tagvalue<TAG_INT>(0),reg::in(1));
  MACRO_check_list(reg::in(2));
  MACRO_read_variable(reg::x(4));
  MACRO_read_void;
  MACRO_activate;
  MACRO_get_value(reg::x(4),reg::in(3));
  MACRO_proceed;
 L245:  // __nth0__/3-2
  MACRO_otherwise;
  MACRO_check_list(reg::in(2));
  MACRO_read_void;
  MACRO_read_variable(reg::x(4));
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_variable(reg::x(5),reg::out(2));
  MACRO_call(L220, L246);  // call(__dec__/2)
 L246:  // return_from_call(__dec__/2)
  MACRO_tail(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_out_value(reg::x(4),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L244, 3);  // execute(__nth0__/3)
 L247:  // __nth0_rev__/4
  MACRO_goal(L247, atom(113));
  MACRO_requires(11);
  MACRO_try_guard_else(L248);
  MACRO_check_list(reg::in(2));
  MACRO_read_value(reg::in(3));
  MACRO_read_void;
  MACRO_activate;
  MACRO_get_value(reg::in(4),reg::in(1));
  MACRO_proceed;
 L248:  // __nth0_rev__/4-2
  MACRO_otherwise;
  MACRO_check_list(reg::in(2));
  MACRO_read_void;
  MACRO_read_variable(reg::x(5));
  MACRO_activate;
  MACRO_par(7);
  MACRO_out_value(reg::in(4),reg::out(1));
  MACRO_out_variable(reg::x(6),reg::out(2));
  MACRO_call(L216, L249);  // call(__inc__/2)
 L249:  // return_from_call(__inc__/2)
  MACRO_tail(7);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::x(5),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_value(reg::x(6),reg::out(4));
  MACRO_execute(L247, 4);  // execute(__nth0_rev__/4)
 L250:  // nth1/3
  MACRO_goal(L250, atom(114));
  MACRO_requires(9);
  MACRO_try_guard_else(L253);
  MACRO_seq(5);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_call(L153, L251);  // call(var/1)
 L251:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_call(L220, L252);  // call(__dec__/2)
 L252:  // return_from_call(__dec__/2)
  MACRO_tail(5);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_execute(L244, 3);  // execute(__nth0__/3)
 L253:  // nth1/3-2
  MACRO_try_guard_else_suspend;
  MACRO_seq(5);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L153, L254);  // call(var/1)
 L254:  // return_from_call(var/1)
  MACRO_activate;
  MACRO_par(5);
  MACRO_out_variable(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_constant(tagvalue<TAG_INT>(0),reg::out(4));
  MACRO_spawn(L247, L255);  // spawn(__nth0_rev__/4)
 L255:  // return_from_spawn(__nth0_rev__/4)
  MACRO_tail(5);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_execute(L216, 2);  // execute(__inc__/2)
 L256:  // inference_count/1
  MACRO_goal(L256, atom(115));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L257, 1);  // execute(__inference_count__/1)
 L257:  // __inference_count__/1
  MACRO_goal(L257, atom(116));
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
 L258:  // resume_count/1
  MACRO_goal(L258, atom(117));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L259, 1);  // execute(__resume_count__/1)
 L259:  // __resume_count__/1
  MACRO_goal(L259, atom(118));
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
 L260:  // dump_to_dot/1
  MACRO_goal(L260, atom(119));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_seq(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L261);  // call(atom/1)
 L261:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_execute(L262, 1);  // execute(__dump_to_dot__/1)
 L262:  // __dump_to_dot__/1
  MACRO_goal(L262, atom(120));
  MACRO_requires(3);
  MACRO_activate;
  do {
    const Q q = vm->in[1];
    const std::string s = atom_str_of(q);
    vm->dump_to_dot(s);
  } while (0);
  MACRO_proceed;
 L263:  // dump_to_dot/2
  MACRO_goal(L263, atom(121));
  MACRO_requires(5);
  MACRO_try_guard_else_suspend;
  MACRO_seq(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_call(L152, L264);  // call(atom/1)
 L264:  // return_from_call(atom/1)
  MACRO_activate;
  MACRO_tail(4);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_execute(L265, 2);  // execute(__dump_to_dot__/2)
 L265:  // __dump_to_dot__/2
  MACRO_goal(L265, atom(122));
  MACRO_requires(5);
  MACRO_activate;
  do {
    const Q q1 = vm->in[1];
    const Q q2 = vm->in[2];
    const std::string s = atom_str_of(q1);
    vm->dump_to_dot(s, q2);
  } while (0);
  MACRO_proceed;
 L266:  // tarai/4
  MACRO_goal(L266, atom(123));
  MACRO_requires(12);
  MACRO_try_guard_else(L268);
  MACRO_seq(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_call(L158, L267);  // call((=<)/2)
 L267:  // return_from_call((=<)/2)
  MACRO_activate;
  MACRO_get_value(reg::in(2),reg::in(4));
  MACRO_proceed;
 L268:  // tarai/4-2
  MACRO_otherwise;
  MACRO_activate;
  MACRO_par(6);
  MACRO_out_value(reg::in(1),reg::out(1));
  MACRO_out_variable(reg::x(5),reg::out(2));
  MACRO_call(L220, L269);  // call(__dec__/2)
 L269:  // return_from_call(__dec__/2)
  MACRO_par(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_out_value(reg::in(2),reg::out(2));
  MACRO_out_value(reg::in(3),reg::out(3));
  MACRO_out_variable(reg::x(5),reg::out(4));
  MACRO_spawn(L266, L270);  // spawn(tarai/4)
 L270:  // return_from_spawn(tarai/4)
  MACRO_par(7);
  MACRO_out_value(reg::in(2),reg::out(1));
  MACRO_out_variable(reg::x(6),reg::out(2));
  MACRO_call(L220, L271);  // call(__dec__/2)
 L271:  // return_from_call(__dec__/2)
  MACRO_par(7);
  MACRO_out_value(reg::x(6),reg::out(1));
  MACRO_out_value(reg::in(3),reg::out(2));
  MACRO_out_value(reg::in(1),reg::out(3));
  MACRO_out_variable(reg::x(6),reg::out(4));
  MACRO_spawn(L266, L272);  // spawn(tarai/4)
 L272:  // return_from_spawn(tarai/4)
  MACRO_par(8);
  MACRO_out_value(reg::in(3),reg::out(1));
  MACRO_out_variable(reg::x(7),reg::out(2));
  MACRO_call(L220, L273);  // call(__dec__/2)
 L273:  // return_from_call(__dec__/2)
  MACRO_par(8);
  MACRO_out_value(reg::x(7),reg::out(1));
  MACRO_out_value(reg::in(1),reg::out(2));
  MACRO_out_value(reg::in(2),reg::out(3));
  MACRO_out_variable(reg::x(7),reg::out(4));
  MACRO_spawn(L266, L274);  // spawn(tarai/4)
 L274:  // return_from_spawn(tarai/4)
  MACRO_tail(8);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_out_value(reg::x(6),reg::out(2));
  MACRO_out_value(reg::x(7),reg::out(3));
  MACRO_out_value(reg::in(4),reg::out(4));
  MACRO_execute(L266, 4);  // execute(tarai/4)
 L275:  // report/1
  MACRO_goal(L275, atom(124));
  MACRO_requires(3);
  MACRO_try_guard_else_suspend;
  MACRO_wait(reg::in(1));
  MACRO_activate;
  MACRO_tail(3);
  MACRO_out_list(reg::out(1));
  MACRO_write_structure(atom(32));
  MACRO_write_value(reg::in(1));
  MACRO_write_nil;
  MACRO_execute(L48, 1);  // execute(outstream/1)
 L276:  // main/1
  MACRO_goal(L276, atom(125));
  MACRO_requires(10);
  MACRO_try_guard_else(L283);
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
  MACRO_par(5);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_variable(reg::x(2),reg::out(2));
  MACRO_spawn(L42, L277);  // spawn(atom_number/2)
 L277:  // return_from_spawn(atom_number/2)
  MACRO_par(5);
  MACRO_out_value(reg::x(3),reg::out(1));
  MACRO_out_variable(reg::x(3),reg::out(2));
  MACRO_spawn(L42, L278);  // spawn(atom_number/2)
 L278:  // return_from_spawn(atom_number/2)
  MACRO_par(5);
  MACRO_out_value(reg::x(4),reg::out(1));
  MACRO_out_variable(reg::x(4),reg::out(2));
  MACRO_spawn(L42, L279);  // spawn(atom_number/2)
 L279:  // return_from_spawn(atom_number/2)
  MACRO_par(6);
  MACRO_out_variable(reg::x(5),reg::out(1));
  MACRO_spawn(L275, L280);  // spawn(report/1)
 L280:  // return_from_spawn(report/1)
  MACRO_par(6);
  MACRO_out_value(reg::x(5),reg::out(1));
  MACRO_spawn(L9, L281);  // spawn(wait_time/1)
 L281:  // return_from_spawn(wait_time/1)
  MACRO_par(6);
  MACRO_out_value(reg::x(2),reg::out(1));
  MACRO_out_value(reg::x(3),reg::out(2));
  MACRO_out_value(reg::x(4),reg::out(3));
  MACRO_out_value(reg::x(5),reg::out(4));
  MACRO_spawn(L266, L282);  // spawn(tarai/4)
 L282:  // return_from_spawn(tarai/4)
  MACRO_tail(6);
  MACRO_out_constant(atom(126),reg::out(1));
  MACRO_execute(L260, 1);  // execute(dump_to_dot/1)
 L283:  // main/1-2
  MACRO_otherwise;
  MACRO_check_list(reg::in(1));
  MACRO_read_variable(reg::x(2));
  MACRO_read_nil;
  MACRO_activate;
  MACRO_tail(6);
  MACRO_out_list(reg::out(1));
  MACRO_write_structure(atom(30));
  MACRO_write_constant(atom(127));
  MACRO_write_list;
  MACRO_write_structure(atom(30));
  MACRO_write_value(reg::x(2));
  MACRO_write_list;
  MACRO_write_structure(atom(30));
  MACRO_write_constant(atom(128));
  MACRO_write_list;
  MACRO_write_constant(atom(34));
  MACRO_write_nil;
  MACRO_execute(L48, 1);  // execute(outstream/1)
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
