#!/usr/bin/env swipl
% -*- mode: prolog; coding:utf-8 -*-
:- initialization(main, main).
:- initialization(consult('kvs.pl')).

%% main(+Argv)
% メイン述語。wam_to_cc/2 を起動する。
main(Argv) :-
    ( opt_parse(Argv, WamFiles, CcFile)
    ; format('invalid arguments: ~w~n', [Argv]), fail),
    wam_to_cc(WamFiles, CcFile).

%% opt_parse(+Argv, -WamFile, -CcFile)
% 与えられたコマンド引数を解釈する。
% -o に続く引数を CcFile として返す。
% それ以外を WamFile として返す。
% -o に続く引数がない、あるいはそれ以外の引数が複数あれば fail。
opt_parse(Argv, WamFiles, CcFile) :-
    opt_parse_ccfile(Argv - Argv2, CcFile),
    opt_parse_wamfiles(Argv2 - [], WamFiles).
opt_parse_ccfile(['-o', CcFile|Argv2] - Argv2, CcFile) :- !.
opt_parse_ccfile([A|Argv] - [A|Argv2], CcFile) :-
    opt_parse_ccfile(Argv - Argv2, CcFile).
opt_parse_wamfiles(WamFiles - [], WamFiles) :- !.

%% always_success(+P)
% P を実行して、失敗したらエラーとしてメッセージを表示する。
% P の第一引数が kvs(_) の場合には、その内容の表示は省略する。
always_success(P) :-
    ( call(P), !
    ; report_error(P) ).
report_error(P) :-
    !,
    ( P =.. [F, kvs(_) | Args ] ->
      P2 =.. [F, kvs | Args ],
      format('failed to execute: ~w~n', P2)
    ; format('failed to execute: ~w~n', P)).

%% wam_to_cc(+WamFiles, +CcFile)
% WamFile から中間コードを読み取り、C++ ソースコードに変換して
% CcFile に書き込む。
wam_to_cc(WamFiles, CcFile) :-
    wam_load_all_terms(WamFiles, Codes),
    create(Ctx),
    translate(Ctx, Codes, Ts),
    write_translated_cc(Ctx, CcFile, Ts).

%% wam_load_all_terms(+WamFile, -Codes)
% WamFile から中間コードを読み取り、Codes に返す。
wam_load_all_terms([], []) :- !.
wam_load_all_terms([WamFile|WamFiles], Codes) :-
    open(WamFile, read, Stream, [encoding(utf8)]),
    read_all_terms(Stream, Codes1),
    close(Stream),
    append(Codes1, Codes2, Codes),
    wam_load_all_terms(WamFiles, Codes2).
read_all_terms(Stream, Codes) :-
    read_term(Stream, Code, []),
    ( Code = end_of_file -> Codes = []
    ; Codes = [Code|Codes2], read_all_terms(Stream, Codes2)).

%% write_translated_cc(?Ctx, +CcFile, +Ts)
% C++ ソースコード列 Ts を Ccfile に書き込む。
write_translated_cc(Ctx, CcFile, Ts) :-
    open(CcFile, write, OStream, [create([write]), encoding(utf8)]),
    writeln(OStream, '# include "./ghc.h"'),
    always_success(dump_atom_defs(Ctx, OStream)),
    writeln(OStream, 'void module(VM::ptr vm, Program* prog, bool setup) {'),
    writeln(OStream, '  if (setup) {'),
    writeln(OStream, '    // setup atom constants'),
    always_success(dump_atom_values(Ctx, OStream)),
    writeln(OStream, '    // setup entry points'),
    always_success(dump_goals(Ctx, OStream)),
    writeln(OStream, '    vm->FAIL = &&LFAIL;'),
    writeln(OStream, '    vm->FAIL2 = &&LFAIL2;'),
    writeln(OStream, '    vm->NO_MORE_GOALS = &&LNO_MORE_GOALS;'),
    writeln(OStream, '    return;'),
    writeln(OStream, '  }'),
    writeln(OStream, '  goto *(vm->pc);'),
    writeln(OStream, ' LFAIL:'),
    writeln(OStream, '  throw RuntimeError();'),
    writeln(OStream, ' LFAIL2:'),
    writeln(OStream, '  throw RuntimeError();'),
    always_success(dump(Ts, OStream)),
    writeln(OStream, ' LNO_MORE_GOALS:'),
    writeln(OStream, '  return;'),
    writeln(OStream, '}'),
    writeln(OStream, 'int'),
    writeln(OStream, 'main(int argc, char* argv[]) {'),
    writeln(OStream, '  Program prog;'),
    writeln(OStream, '  std::vector<VM::ptr> vms;'),
    writeln(OStream, '  vms.push_back(std::make_shared<VM>());'),
    writeln(OStream, '  VM::ptr vm = vms[0];'),
    writeln(OStream, '  module(vm, &prog, true);'),
    writeln(OStream, '  void* pc = prog.query_entry_point(to_atom("main", 1));'),
    writeln(OStream, '  if (!pc) {'),
    writeln(OStream, '    std::cerr << "failed to find main/1 predicate" << std::endl;'),
    writeln(OStream, '    return 1;'),
    writeln(OStream, '  }'),
    writeln(OStream, '  vm->pc = pc;'),
    writeln(OStream, '  vm->failed = false;'),
    writeln(OStream, '  A* head = NULL;'),
    writeln(OStream, '  A* prev_tail = NULL;'),
    writeln(OStream, '  for (int i = 0; i < argc; ++i) {'),
    writeln(OStream, '    const size_t h = vm->heap_publishing(2);'),
    writeln(OStream, '    if (!head) {'),
    writeln(OStream, '      head = &vm->heap[h];'),
    writeln(OStream, '    }'),
    writeln(OStream, '    if (prev_tail) {'),
    writeln(OStream, '      prev_tail->store(tagptr<TAG_LIST>(&vm->heap[h]));'),
    writeln(OStream, '    }'),
    writeln(OStream, '    vm->heap[h] = to_atom(argv[i], 0);'),
    writeln(OStream, '    vm->heap[h + 1].store(tagptr<TAG_REF>(&vm->heap[h + 1]));'),
    writeln(OStream, '    prev_tail = &vm->heap[h + 1];'),
    writeln(OStream, '    vm->heap_published(2);'),
    writeln(OStream, '  }'),
    writeln(OStream, '  prev_tail->store(tagptr<TAG_NIL, Q>(NULL));'),
    writeln(OStream, '  const size_t h = vm->heap_publishing(6);'),
    writeln(OStream, '  vm->heap[h + 0].store(tagptr<TAG_REF>(&vm->heap[h + 0]));'),
    writeln(OStream, '  vm->heap[h + 1].store(tagptr<TAG_REF>(&vm->heap[h + 2]));'),
    writeln(OStream, '  vm->heap[h + 2].store(tagvalue<TAG_INT>(0));'),
    writeln(OStream, '  vm->heap[h + 3].store(reinterpret_cast<intptr_t>(pc));'),
    writeln(OStream, '  vm->heap[h + 4].store(to_atom("main", 1));'),
    writeln(OStream, '  vm->heap[h + 5].store(tagptr<TAG_LIST, A>(head));'),
    writeln(OStream, '  vm->heap_published(6);'),
    writeln(OStream, '  A* lst = &vm->heap[h + 0];'),
    writeln(OStream, '  Scheduler::getInstance().enqueue_list(lst);'),
    writeln(OStream, '  vm->run(module, &prog);'),
    writeln(OStream, '}'),
    close(OStream).

%% translate(?Ctx, +Codes, -Ts)
% WAM 風中間コード Codes を C++ ソースコードに変換して
% Ts に書き込む。
translate(Ctx, Codes, Ts) :-
    translate(Ctx, Codes, Ts, 0).
translate(_, [], [], _).
translate(Ctx, Codes, Ts, Lno) :-
    ( Codes = [Code |Codes2],
      ( translate1(Ctx, Code, TCode), Lno1 = Lno, Ts = [TCode |Ts2]
      ; translate2(Ctx, Code, TCode, Lno, Lno1), Ts = [TCode |Ts2] )
    ; Codes = [ call(F / N) |Codes1]
      -> Label = label(F / N), ( get(Ctx, Label, L) ; put(Ctx, Label, L) ),
         ( Codes1 = [ Label1 | Codes2], Label1 =.. [label|_]
           -> ( get(Ctx, Label1, Lno1) ; put(Ctx, Label1, Lno1) ),
              Lno1 is Lno + 1,
              Ts = [call(L, Lno1, F / N),
                    label(Lno1, return_from_call(F / N)) | Ts2]
         ; Codes2 = Codes1,
           Lno1 is Lno + 1,
           Ts = [call(L, Lno1, F / N),
                 label(Lno1, return_from_call(F / N)) | Ts2])
    ; Codes = [ spawn(F / N) |Codes1]
      -> Label = label(F / N), ( get(Ctx, Label, L) ; put(Ctx, Label, L) ),
         ( Codes1 = [ Label1 | Codes2], Label1 =.. [label|_]
           -> ( get(Ctx, Label1, Lno1) ; put(Ctx, Label1, Lno1) ),
              Lno1 is Lno + 1,
              Ts = [spawn(L, Lno1, F / N),
                    label(Lno1, return_from_spawn(F / N)) | Ts2]
         ; Codes2 = Codes1,
           Lno1 is Lno + 1,
           Ts = [spawn(L, Lno1, F / N),
                 label(Lno1, return_from_spawn(F / N)) | Ts2])
    ),
    always_success(translate(Ctx, Codes2, Ts2, Lno1)).

translate2(Ctx, label(Label), label(Lno1, Label), Lno, Lno1) :-
    !,
    Lno1 is Lno + 1,
    ( get(Ctx, label(Label), L) -> L = Lno1 ; put(Ctx, label(Label), Lno1) ).
translate2(_, inline(Inline), inline(Inline), Lno, Lno).
translate1(Ctx, goal(G / N), goal(L, atom(AtomID))) :-
    !,
    ( get(Ctx, label(G / N), L) ; put(Ctx, label(G / N), L) ),
    append_atom(Ctx, G / N, AtomID),
    append_goal(Ctx, goal(L, G / N)).
translate1(_, requires(N), requires(N)).
translate1(Ctx, try_guard_else(Label), try_guard_else(L)) :-
    ( get(Ctx, Label, L) ; put(Ctx, Label, L) ).
%translate1(Ctx, spawn(F / N), spawn(L, F / N)) :-
%    Label = label(F / N), ( get(Ctx, Label, L) ; put(Ctx, Label, L) ).
translate1(Ctx, execute(F / N), execute(L, F / N)) :-
    Label = label(F / N), ( get(Ctx, Label, L) ; put(Ctx, Label, L) ).
translate1(_, try_guard_else_suspend, try_guard_else_suspend).
translate1(_, otherwise, otherwise).
translate1(_, trust_me, trust_me).
translate1(_, activate, activate).
translate1(_, proceed, proceed).
translate1(_, seq(N), seq(N)).
translate1(_, par(N), par(N)).
translate1(_, tail(N), tail(N)).
translate1(_, wait(Ai), wait(A)) :- to_reg(Ai, A).
translate1(Ctx, check_structure(F / N, Ai), check_structure(atom(AtomID), A)) :-
    append_atom(Ctx, F / N, AtomID), to_reg(Ai, A).
translate1(Ctx, out_structure(F / N, Ai), out_structure(atom(AtomID), A)) :-
    append_atom(Ctx, F / N, AtomID), to_reg(Ai, A).
translate1(Ctx, set_structure(F / N, Ai), set_structure(atom(AtomID), A)) :-
    append_atom(Ctx, F / N, AtomID), to_reg(Ai, A).
translate1(Ctx, get_structure(F / N, Ai), get_structure(atom(AtomID), A)) :-
    append_atom(Ctx, F / N, AtomID), to_reg(Ai, A).
translate1(_, check_list(Ai), check_list(A)) :- to_reg(Ai, A).
translate1(_, out_list(Ai), out_list(A)) :- to_reg(Ai, A).
translate1(_, set_list(Ai), set_list(A)) :- to_reg(Ai, A).
translate1(_, get_list(Ai), get_list(A)) :- to_reg(Ai, A).
translate1(_, check_nil(Ai), check_nil(A)) :- to_reg(Ai, A).
translate1(_, out_nil(Ai), out_nil(A)) :- to_reg(Ai, A).
translate1(_, set_nil(Ai), set_nil(A)) :- to_reg(Ai, A).
translate1(_, get_nil(Ai), get_nil(A)) :- to_reg(Ai, A).
translate1(_, check_variable(Vn, Ai), check_variable(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, out_variable(Vn, Ai), out_variable(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, set_variable(Ai), set_variable(A)) :-
    to_reg(Ai, A).
translate1(_, get_variable(Vn, Ai), get_variable(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, check_value(Vn, Ai), check_value(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, out_value(Vn, Ai), out_value(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, set_value(Vn, Ai), set_value(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(_, get_value(Vn, Ai), get_value(V, A)) :-
    to_reg(Vn, V), to_reg(Ai, A).
translate1(Ctx, check_constant(C, Ai), check_constant(Cc, A)) :-
    always_success(to_constant(Ctx, C, Cc)), to_reg(Ai, A).
translate1(Ctx, out_constant(C, Ai), out_constant(Cc, A)) :-
    always_success(to_constant(Ctx, C, Cc)), to_reg(Ai, A).
translate1(Ctx, set_constant(C, Ai), set_constant(Cc, A)) :-
    always_success(to_constant(Ctx, C, Cc)), to_reg(Ai, A).
translate1(Ctx, get_constant(C, Ai), get_constant(Cc, A)) :-
    always_success(to_constant(Ctx, C, Cc)), to_reg(Ai, A).
translate1(_, check_nil(Ai), check_nil(A)) :- to_reg(Ai, A).
translate1(_, out_nil(Ai), out_nil(A)) :- to_reg(Ai, A).
translate1(_, set_nil(Ai), set_nil(A)) :- to_reg(Ai, A).
translate1(_, get_nil(Ai), get_nil(A)) :- to_reg(Ai, A).
translate1(Ctx, read_structure(F / N), read_structure(atom(AtomID))) :-
    append_atom(Ctx, F / N, AtomID).
translate1(Ctx, write_structure(F / N), write_structure(atom(AtomID))) :-
    append_atom(Ctx, F / N, AtomID).
translate1(Ctx, unify_structure(F / N), unify_structure(atom(AtomID))) :-
    append_atom(Ctx, F / N, AtomID).
translate1(_, read_list, read_list).
translate1(_, write_list, write_list).
translate1(_, unify_list, unify_list).
translate1(_, read_nil, read_nil).
translate1(_, write_nil, write_nil).
translate1(_, unify_nil, unify_nil).
translate1(_, read_variable(Vn), read_variable(V)) :- to_reg(Vn, V).
translate1(_, write_variable(Vn), write_variable(V)) :- to_reg(Vn, V).
translate1(_, unify_variable(Vn), unify_variable(V)) :- to_reg(Vn, V).
translate1(_, read_value(Vn), read_value(V)) :- to_reg(Vn, V).
translate1(_, write_value(Vn), write_value(V)) :- to_reg(Vn, V).
translate1(_, unify_value(Vn), unify_value(V)) :- to_reg(Vn, V).
translate1(_, read_void, read_void).
translate1(_, write_void, write_void).
translate1(_, unify_void, unify_void).
translate1(Ctx, read_constant(C), read_constant(Cc)) :-
    always_success(to_constant(Ctx, C, Cc)).
translate1(Ctx, write_constant(C), write_constant(Cc)) :-
    always_success(to_constant(Ctx, C, Cc)).
translate1(Ctx, unify_constant(C), unify_constant(Cc)) :-
    always_success(to_constant(Ctx, C, Cc)).

to_reg(reg(R, N), Rn) :-
    format(atom(A), 'reg::~w', [R]),
    Rn =.. [A, N].

%to_cstring(C, S) :- format(atom(S), '"~w"', [C]).
escape([], []) :- !.
escape([C|Cs], [C,C|Cs2]) :- C = '\\' -> escape(Cs, Cs2).
escape([C|Cs], [C|Cs2]) :- escape(Cs, Cs2).
to_cstring(C, S) :-
    atom_chars(C, Cs),
    escape(Cs, Cs2),
    atom_chars(C2, Cs2),
    format(atom(S), '"~w"', [C2]).

to_constant(Ctx, C, A) :-
    ( number(C) -> A = 'tagvalue<TAG_INT>'(C)
    ; atom(C) -> append_atom(Ctx, C / 0, AtomID), A = atom(AtomID)
    ; fail).
to_functor(F / N, Fun) :-
    to_cstring(F, S),
    Fun = atom(S, N).

dump([], _) :- !.
dump([label(Lno, Label)|Ts], OStream) :-
    format(OStream, " L~d:  // ~w~n", [Lno, Label]),
    % format(OStream, '  std::cerr << "~w" << std::endl;~n', [Label]),
    always_success(dump(Ts, OStream)).
dump([inline(Inline)|Ts], OStream) :-
    format(OStream, '~w~n', [Inline]),
    always_success(dump(Ts, OStream)).
dump([Code|Ts], OStream) :-
    % format(OStream, '  std::cerr << "~w" << std::endl;~n', [Code]),
    ( Code = goal(L, G) ->
      % goal(L, atom(S, N))
      format(OStream, '  MACRO_goal(L~w, ~w);~n', [L, G])
    ; Code = call(L, Link, Fun) ->
      ( var(L) -> format('error: predicate not found: ~w~n', [Fun]) ; true ),
      % call(L, Link)
      format(OStream, '  MACRO_call(L~w, L~w);  // call(~w)~n',
             [L, Link, Fun])
    ; Code = spawn(L, Link, Fun) ->
      ( var(L) -> format('error: predicate not found: ~w~n', [Fun]); true),
      % spawn(L, Link)
      format(OStream, '  MACRO_spawn(L~w, L~w);  // spawn(~w)~n',
             [L, Link, Fun])
    ; Code = execute(L, Fun) ->
      ( var(L) -> format('error: predicate not found: ~w~n', [Fun]); true),
      Fun = _ / Arity,
      % execute(L, Arity)
      format(OStream, '  MACRO_execute(L~w, ~w);  // execute(~w)~n',
             [L, Arity, Fun])
    ; Code = try_guard_else(L) ->
      format(OStream, '  MACRO_try_guard_else(L~w);~n',
             [L])
    ; format(OStream, '  MACRO_~w;~n', [Code]) ),
    always_success(dump(Ts, OStream)).

append_atom(Ctx, Atom, AtomID) :-
    ( get(Ctx, Atom, atom(Atom, AtomID))
    ; put(Ctx, Atom, atom(Atom, AtomID)),
      ( get(Ctx, atom_list, AtomIDList) ; AtomIDList = [] ),
      append(AtomIDList, [atom(Atom, AtomID)], AtomIDList2),
      put(Ctx, atom_list, AtomIDList2) ).
dump_atom_defs(Ctx, OStream) :-
    get(Ctx, atom_list, AtomIDList),
    writeln(OStream, '#define atom(N) atom_ ## N'),
    dump_atom_defs(Ctx, OStream, AtomIDList, 1).
dump_atom_defs(_, _, [], _) :- !.
dump_atom_defs(Ctx, OStream, [atom(F / N, ID)|AtomIDList], ID) :-
    format(OStream, 'Q ~w;  // ~w / ~d~n', [atom(ID), F, N]),
    ID1 is ID + 1,
    dump_atom_defs(Ctx, OStream, AtomIDList, ID1).
dump_atom_values(Ctx, OStream) :-
    get(Ctx, atom_list, AtomIDList),
    dump_atom_values(Ctx, OStream, AtomIDList, 1).
dump_atom_values(_, _, [], _) :- !.
dump_atom_values(Ctx, OStream, [atom(F / N, ID)|AtomIDList], ID) :-
    to_cstring(F, S),
    format(OStream, '    ~w = to_atom(~w, ~d);~n', [atom(ID), S, N]),
    ID1 is ID + 1,
    dump_atom_values(Ctx, OStream, AtomIDList, ID1).

append_goal(Ctx, Goal) :-
    ( get(Ctx, goals, Goals) ; Goals = [] )
    -> append(Goals, [Goal], Goals2),
       put(Ctx, goals, Goals2).
dump_goals(Ctx, OStream) :-
    ( get(Ctx, goals, Goals) ; Goals = [] )
    -> always_success(dump_goals(Ctx, Goals, OStream)).
dump_goals(_, [], _) :- !.
dump_goals(Ctx, [goal(L, G / N)|Gs], OStream) :-
    get(Ctx, G / N, atom(_, AtomID)),
    format(OStream,
           '    prog->add_entry_point(atom(~d), &&L~d);  // ~w / ~d~n',
           [AtomID, L, G, N]),
%    to_cstring(G, S),
%    format(OStream,
%           '  prog->add_entry_point(to_atom(~w, ~d), ~d);~n',
%           [S, N, L]),
    dump_goals(Ctx, Gs, OStream).
