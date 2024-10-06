#!/usr/bin/env swipl
% -*- mode: prolog; coding:utf-8 -*-
:- initialization(main, main).
:- initialization(consult('kvs.pl')).

%% main(+Argv)
% メイン述語。ghc_to_wam/2 を起動する。
main(Argv) :-
    ( opt_parse(Argv, SourceFiles, WamFile)
    ; format('invalid arguments: ~w~n', [Argv]), fail),
    ghc_to_wam(SourceFiles, WamFile).

%% opt_parse(+Argv, -SourceFiles, -WamFile)
% 与えられたコマンド引数を解釈する。
% -o に続く引数を WamFile として返す。
% それ以外を SourceFiles として返す。
% -o に続く引数がない場合は fail。
opt_parse(Argv, SourceFiles, WamFile) :-
    opt_parse_wamfile(Argv - Argv2, WamFile),
    opt_parse_sourcefiles(Argv2 - [], SourceFiles).
opt_parse_wamfile(['-o', WamFile|Argv2] - Argv2, WamFile) :- !.
opt_parse_wamfile([A|Argv] - [A|Argv2], WamFile) :-
    opt_parse_wamfile(Argv - Argv2, WamFile).
opt_parse_sourcefiles(SourceFiles - [], SourceFiles) :- !.

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

%% ghc_to_wam(+SourceFiles, +WamFile)
% SourceFiles からすべての述語定義を読み取り、GHC ソースコードとして
% 解釈した結果をWAM 風中間コードとして WamFile に書き込む。
ghc_to_wam(SourceFiles, WamFile) :-
    create(VarKvs),
    ghc_load_all_terms(SourceFiles, Source, VarKvs)
    -> ghc_compile(Source, WamFile, VarKvs).

%% ghc_load_all_terms(+SourceFiles, -Source)
% 与えられたファイル SourceFiles からすべての項を出現順に読み取り、
% GHC ソースコード Source として返す。
ghc_load_all_terms([], [], _) :- !.
ghc_load_all_terms([SourceFile|SourceFiles], Source, VarKvs) :-
    open(SourceFile, read, Stream, [encoding(utf8)]),
    ghc_read_all_terms(Stream, Ss, VarKvs),
    close(Stream),
    append(Ss, Ss2, Source),
    ghc_load_all_terms(SourceFiles, Ss2, VarKvs).
ghc_read_all_terms(Stream, Source, VarKvs) :-
    read_term(Stream, Term,
              [variable_names(Vars), singletons(Singletons)]),
    report_singletons(Term, Vars, Singletons, Singletons),
    ( Term = end_of_file -> Source = []
    ; Source = [Term|Source2],
      ( get(VarKvs, vars, Vars0),
        append(Vars0, Vars, Vars2),
        put(VarKvs, vars, Vars2)
      ; put(VarKvs, vars, Vars) ),
      ( get(VarKvs, singletons, Singletons0),
        append(Singletons0, Singletons, Singletons2),
        put(VarKvs, singletons, Singletons2)
      ; put(VarKvs, singletons, Singletons) ),
      ghc_read_all_terms(Stream, Source2, VarKvs)).

%% report_singletons(+Term +Vars, +Singletons, +Singletons)
report_singletons(_, _, _, []) :- !.
report_singletons(Term, Vars, Singletons,
                  [Singleton = _ | RestSingletons]) :-
    atom_chars(Singleton, SCs),
    ( SCs = ['_'|_] -> true
    ; format('warning: Singleton ~w in ', [Singleton]),
      report_term(Term, Vars, Singletons) ),
    report_singletons(Term, Vars, Singletons, RestSingletons).
report_term(Term, Vars, Singletons) :-
    ( unify_var_vals(Vars),
      unify_var_vals(Singletons),
      format('~w~n', [Term]),
      fail  % rollback unify_var_vals
    ; !, true ).
unify_var_vals([]) :- !.
unify_var_vals([V=V|Vs]) :-
    unify_var_vals(Vs).

%% ghc_compile(+Source, +WamFile)
% GHC ソースコード Source を WAM 風中間コードにコンパイルして
% OFile に書き込む。
ghc_compile(Source, WamFile, VarKvs) :-
    ghc_collect_goals(Source, Goals),
    open(WamFile, write, OStream, [create([write]), encoding(utf8)]),
    always_success(ghc_compile_goals(Goals, Source, OStream, VarKvs)),
    close(OStream).

%% ghc_collect_goals(+Source, -Goals)
% GHC ソースコード Source に含まれる述語すべてのヘッドを検索し、
% ゴール名とアリティのペアとして Goals に返す。
ghc_collect_goals(Source, Goals) :-
    ghc_collect_goals(Source, Goals, []).
ghc_collect_goals([], Goals, Goals) :- !.
% otherwise は単に無視する。
ghc_collect_goals([otherwise|NextCodes], Goals, Gs) :-
    !,
    ghc_collect_goals(NextCodes, Goals, Gs).
ghc_collect_goals([(Head :- _)|NextCodes], Goals, Gs) :-
    functor(Head, G, N),
    !,
    ( member(goal(G, N), Gs)
    -> ghc_collect_goals(NextCodes, Goals, Gs)
    ; append(Gs, [goal(G, N)], Gs2),
      ghc_collect_goals(NextCodes, Goals, Gs2) ).
ghc_collect_goals([Head|NextCodes], Goals, Gs) :-
    functor(Head, G, N),
    !,
    ( member(goal(G, N), Gs)
    -> ghc_collect_goals(NextCodes, Goals, Gs)
    ; append(Gs, [goal(G, N)], Gs2),
      ghc_collect_goals(NextCodes, Goals, Gs2) ).
ghc_collect_goal([Head|_], _, _) :-
    write('not a goal: '), write(Head), nl, fail.

%% find_goal_source(+Goal, +Source, -GoalSource)
% GHC ソースコード Source を検索し、与えられたゴール名、アリティペア
% (Goal) に一致するヘッドを持つ述語すべてを出現順に GoalSource に
% リストとして返す。
find_goal_source(_, [], []) :- !.
find_goal_source(goal(G, N),
                 [(Head :- Body), otherwise|NextCodes],
                 [(Head :- Body), otherwise|GoalSource]) :-
    functor(Head, G, N) -> find_goal_source(goal(G, N), NextCodes, GoalSource).
find_goal_source(goal(G, N),
                 [(Head :- Body)|NextCodes],
                 [(Head :- Body)|GoalSource]) :-
    functor(Head, G, N) -> find_goal_source(goal(G, N), NextCodes, GoalSource).
find_goal_source(goal(G, N),
                 [Head|NextCodes],
                 [Head|GoalSource]) :-
    functor(Head, G, N) -> find_goal_source(goal(G, N), NextCodes, GoalSource).
find_goal_source(Goal,
                 [_|NextCodes],
                 GoalSource) :-
    find_goal_source(Goal, NextCodes, GoalSource).
%% ghc_compile_goals(+Goals, +Source, +OStreeam)
% ゴールリスト Goals にある順序に従って、GHC ソースコード Source を
% WAM 風中間コードにコンパイルして OStream に出力する。
ghc_compile_goals([], _, _, _) :- !.
ghc_compile_goals([Goal|Goals], Source, OStream, VarKvs) :-
    find_goal_source(Goal, Source, GoalSource),
    always_success(ghc_preprocess(GoalSource, PreProcessedGoalSource)),
    create(Ctx),
    get(VarKvs, vars, Vars), put(Ctx, vars, Vars),
    get(VarKvs, singletons, Singletons), put(Ctx, singletons, Singletons),
    write_goal_entry_point(Ctx, Goal),
    put(Ctx, goal, Goal),
    always_success(
        ( ghc_compile_inline(Ctx, Goal, PreProcessedGoalSource)
        ; ghc_compile_goal_pred(Ctx, [], Goal, PreProcessedGoalSource) )),
    assign_labels(Ctx),
    max_register_index(Ctx, in, MaxReg_in),
    max_register_index(Ctx, y, MaxReg_y),
    max_register_index(Ctx, x, MaxReg_x),
    max_seq_par_tail(Ctx, MaxSeqParTail),
    max([MaxReg_in, MaxReg_y, MaxReg_x, MaxSeqParTail], MaxReg),
    get(Ctx, max_reg, MaxReg),
    flush_source(Ctx, OStream),
    always_success(ghc_compile_goals(Goals, Source, OStream, VarKvs)).

max(List, Max) :- max_aux(List, Max, 0).
max_aux([], Max, Max).
max_aux([N|Ns], Max, Ac) :-
    ( N > Ac -> max_aux(Ns, Max, N)
    ; max_aux(Ns, Max, Ac) ).

%% ghc_preprocess(+GoalSource, -PreProcessedGoalSource)
ghc_preprocess([], []) :- !.
ghc_preprocess([Goal|Goals], [Goal2|Goals2]) :-
    ghc_preprocess_goal(Goal, Goal2),
    ghc_preprocess(Goals, Goals2).

%% ghc_preprocess(+Goal, -PreProcessedGoal)
ghc_preprocess_goal(Head :- Guard | Body, Head :- PreProcessedGuard | PreProcessedBody) :-
    tuple_list(Guard, GuardList),
    always_success(phrase(ghc_preprocess_eval_polynomial(GuardList), PreProcessedGuardList, [])),
    tuple_list(PreProcessedGuard, PreProcessedGuardList),
    tuple_list(Body, BodyList),
    always_success(phrase(ghc_preprocess_eval_polynomial(BodyList), PreProcessedBodyList, [])),
    tuple_list(PreProcessedBody, PreProcessedBodyList).
ghc_preprocess_goal(Head :- Body, Head :- PreProcessedBody) :-
    tuple_list(Body, BodyList),
    always_success(phrase(ghc_preprocess_eval_polynomial(BodyList), PreProcessedBodyList, [])),
    tuple_list(PreProcessedBody, PreProcessedBodyList).
ghc_preprocess_goal(Goal, Goal).

tuple_list(Tuple, List) :- comma_list(Tuple, List).

%% ghc_preprocess_eval_polynomial(+OriginalGoals, -GoalsHead, -GoalsTail)
ghc_preprocess_eval_polynomial([]) --> {!}.
ghc_preprocess_eval_polynomial([V := X|Gs]) -->
    { integer(X), !, V = X },
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([V := X|Gs]) -->
    [V := X],
    { var(X), ! },
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([V := P|Gs]) -->
    { ! },
    ghc_optimize_polynomial(P, V),
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =:= Y|Gs]) -->
    { var(X), var(Y), ! },
    [X =:= Y],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =:= Y|Gs]) -->
    { var(X), ! },
    ghc_optimize_polynomial(Y, Y1),
    [X1 := X, X1 == Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =:= Y|Gs]) -->
    { var(Y), ! },
    ghc_optimize_polynomial(X, X1),
    [Y1 := Y, X1 == Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =:= Y|Gs]) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 == Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =\= Y|Gs]) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 =\= Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X > Y|Gs]) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 > Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X >= Y|Gs]) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 >= Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X < Y]|Gs) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 < Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([X =< Y|Gs]) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    [X1 =< Y1],
    ghc_preprocess_eval_polynomial(Gs).
ghc_preprocess_eval_polynomial([G|Gs]) -->
    [G], ghc_preprocess_eval_polynomial(Gs).

%% ghc_optimize_polynomial(+Polynomial, +Value, -GoalsHead, -GoalsTail)
ghc_optimize_polynomial(X, X) -->
    { var(X), !}.
ghc_optimize_polynomial(X, X) -->
    { integer(X), !}.
ghc_optimize_polynomial(X + Y, V) -->
    { Y == 1, ! },
    ghc_optimize_polynomial(X, X1),
    ['__inc__'(X1, V)].
ghc_optimize_polynomial(X + Y, V) -->
    { X == 1, ! },
    ghc_optimize_polynomial(Y, Y1),
    ['__inc__'(Y1, V)].
ghc_optimize_polynomial(X + Y, V) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    ['__add__'(X1, Y1, V)].

ghc_optimize_polynomial(X - Y, V) -->
    { Y == 1, ! },
    ghc_optimize_polynomial(X, X1),
    ['__dec__'(X1, V)].
ghc_optimize_polynomial(X - Y, V) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    ['__sub__'(X1, Y1, V)].
ghc_optimize_polynomial(X * Y, V) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    ['__mul__'(X1, Y1, V)].
ghc_optimize_polynomial(X / Y, V) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    ['__div__'(X1, Y1, V)].
ghc_optimize_polynomial(X mod Y, V) -->
    { ! },
    ghc_optimize_polynomial(X, X1),
    ghc_optimize_polynomial(Y, Y1),
    ['__mod__'(X1, Y1, V)].

%% write_goal_entry_point(?Ctx, +Goal)
% Ctx に ghc_source の値として格納しているコンパイルコードに
% ゴール先頭部分のコードを追加する。
% 1. ゴール処理開始位置ラベル: label(ゴール名 / アリティ)
% 2. 実行トレース用情報: goal(ゴール名 / アリティ)
% 3. 消費レジスタサイズ: requires(最大使用レジスタ数)
write_goal_entry_point(Ctx, goal(G, N)) :-
    % ジャンプ先として指定できるようにラベルを設定
    write_source(Ctx, label(G / N)),
    % 再実行に備えてプログラム上の位置を記録しておく
    write_source(Ctx, goal(G / N)),
    put(Ctx, max_reg, MaxReg),
    write_source(Ctx, requires(MaxReg)).

ghc_compile_inline(Ctx, _, [_ :- Body]) :-
    ghc_compile_inline_list(Ctx, Body).
ghc_compile_inline_list(Ctx, (inline(Inline), Is)) :-
    write_source(Ctx, inline(Inline)),
    ghc_compile_inline_list(Ctx, Is).
ghc_compile_inline_list(Ctx, inline(Inline)) :- !,
    write_source(Ctx, inline(Inline)).

%% ghc_compile_goal_pred(?Ctx, ?Label, +Goal, +GoalSource)
% ゴール Goal に対応するソースコード GoalSource を元に
% WAM 風中間コードを生成し、Ctx に ghc_source の値として格納する。
ghc_compile_goal_pred(Ctx, Label, Goal, GoalSource) :-
    ghc_compile_goal_pred(Ctx, Label, Goal, 1, GoalSource).
ghc_compile_goal_pred(_, _, _, _, []) :- !.
ghc_compile_goal_pred(Ctx, Label, goal(G, N), PredNo, [otherwise|GoalSource]) :-
    !,
    always_success(ghc_compile_otherwise(Ctx, Label, goal(G, N), PredNo, GoalSource)).
ghc_compile_goal_pred(Ctx, Label, goal(G, N), PredNo, [(Head :- Body)|GoalSource]) :-
    !,
    ( Label == [] -> true
    ; Label = label(G / N - PredNo), write_source(Ctx, Label) ),
    ( GoalSource == [] -> write_source(Ctx, try_guard_else_suspend),
                          NextLabel = []
    ; write_source(Ctx, try_guard_else(NextLabel)) ),
    always_success(ghc_compile_head_args(Ctx, Head)),
    always_success(ghc_compile_guard(Ctx, Body)),
    write_source(Ctx, activate),
    always_success(ghc_compile_goal_body(Ctx, Body)),
    always_success(allocate_registers(Ctx, N)),
    PredNo1 is PredNo + 1,
    always_success(ghc_compile_goal_pred(Ctx, NextLabel, goal(G, N), PredNo1, GoalSource)).
ghc_compile_goal_pred(Ctx, Label, goal(G, N), PredNo, [Head|GoalSource]) :-
    functor(Head, _, _),
    !,
    ( Label == [] -> true
    ; Label = label(G / N - PredNo), write_source(Ctx, Label) ),
    ( GoalSource == [] -> write_source(Ctx, try_guard_else_suspend),
                          NextLabel = []
    ; write_source(Ctx, try_guard_else(NextLabel)) ),
    always_success(ghc_compile_head_args(Ctx, Head)),
    write_source(Ctx, activate),
    write_source(Ctx, proceed),
    always_success(allocate_registers(Ctx, N)),
    PredNo1 is PredNo + 1,
    always_success(ghc_compile_goal_pred(Ctx, NextLabel, goal(G, N), PredNo1, GoalSource)).

ghc_compile_otherwise(Ctx, Label, goal(G, N), PredNo, [(Head :- Body)]) :-
    !,
    ( Label == [] -> true
    ; Label = label(G / N - PredNo), write_source(Ctx, Label) ),
    write_source(Ctx, otherwise),
    always_success(ghc_compile_head_args(Ctx, Head)),
    always_success(ghc_compile_guard(Ctx, Body)),
    write_source(Ctx, activate),
    always_success(ghc_compile_goal_body(Ctx, Body)),
    always_success(allocate_registers(Ctx, N)).
ghc_compile_otherwise(Ctx, Label, goal(G, N), PredNo, [Head]) :-
    functor(Head, _, _),
    !,
    ( Label == [] -> true
    ; Label = label(G / N - PredNo), write_source(Ctx, Label) ),
    write_source(Ctx, otherwise),
    always_success(ghc_compile_head_args(Ctx, Head)),
    write_source(Ctx, activate),
    write_source(Ctx, proceed),
    always_success(allocate_registers(Ctx, N)).

%% ghc_compile_head_args(?Ctx, +Head)
% GHC ソースコードのヘッド部 Head に対応する WAM 風中間コードを生成し、
% Ctx に ghc_source の値として格納する。
ghc_compile_head_args(Ctx, Head) :-
    write_source(Ctx, comment(head(Head))),
    Head =.. [_|Args],
    ghc_setup_head_args(Ctx, Args, 1),
    ghc_compile_head_args(Ctx, Args, 1).
% 予め引数を既知の変数として登録しておく
ghc_setup_head_args(_, [], _).
ghc_setup_head_args(Ctx, [Arg|Args], N) :-
    ( var(Arg) ->
      ( get(Ctx, Arg, reg(in, X)) ->
        % 重複する引数のパッシブユニフィケーション
        write_source(Ctx, check_value(reg(in, X), reg(in, N)))
      ; put(Ctx, Arg, reg(in, N))); true ),
    N1 is N + 1,
    ghc_setup_head_args(Ctx, Args, N1).
ghc_compile_head_args(_, [], _) :- !.
ghc_compile_head_args(Ctx, [Arg|Args], N) :-
    ghc_compile_head_arg(Ctx, Arg, N),
    N1 is N + 1,
    ghc_compile_head_args(Ctx, Args, N1).
ghc_compile_head_arg(Ctx, Arg, N) :-
    ( var(Arg) -> true
    ; ghc_get_check(Ctx, reg(in, N), Arg) ).
ghc_compile_head_arg(Ctx, [], N) :-
    write_source(Ctx, get_nil(reg(in, N))).

ghc_compile_guard(Ctx, (Guards|_)) :-
    !,
    write_source(Ctx, comment(guard(Guards))),
    ghc_compile_guard_list(Ctx, Guards).
ghc_compile_guard(Ctx, _) :-
    !,
    write_source(Ctx, comment(guard(true))).
ghc_compile_guard_list(Ctx, Guards) :-
    ( Guards = (G1, Gs) ->
      ghc_compile_guard1(Ctx, G1),
      ghc_compile_guard_list(Ctx, Gs)
    ; ghc_compile_guard1(Ctx, Guards)).
ghc_compile_guard1(Ctx, Guard) :-
    % writeln(Guard),
    ( Guard = true -> true
    ; Guard = wait(X) ->
      ( get(Ctx, X, Reg), Reg = reg(_, _) ->
        write_source(Ctx, wait(Reg)) )
    ; Guard = (X = Y) ->
      ( get(Ctx, X, reg(in, Ai)) ->
        always_success(ghc_get_check(Ctx, reg(in, Ai), Y))
      ; get(Ctx, Y, reg(in, Ai)) ->
        always_success(ghc_get_check(Ctx, reg(in, Ai), X))
      ; format('warning: Guard may not be efficient: ~w~n', [Guard]),
        always_success(ghc_set(Ctx, reg(x, Xn), X)),
        always_success(ghc_get_check(Ctx, reg(x, Xn), Y)))
    ; ghc_compile_call(Ctx, seq, Guard)
    ; format('error: invalid guard: ~w~n', [Guard]), fail).

%% ghc_out(?Ctx, +Register, +X)
% out 系命令およびそれに続く write 系命令列を生成する。
ghc_out(Ctx, reg(out, Nreg), X) :-
    UnifyOperations = [ write_variable, write_value,
                        write_constant, write_nil,
                        write_list, write_structure,
                        write_void ],
    ( var(X) ->
      ( get(Ctx, X, reg(R, N))
        ->
        Op =.. [out_value, reg(R, N), reg(out, Nreg)],
        write_source(Ctx, Op)
      ; put(Ctx, X, reg(y, N))
        ->
        Op =.. [out_variable, reg(y, N), reg(out, Nreg)],
        write_source(Ctx, Op) )
    ; X = []
      ->
      Op =.. [out_nil, reg(out, Nreg)],
      write_source(Ctx, Op)
    ; X = [Car|Cdr]
      ->
      Op =.. [out_list, reg(out, Nreg)],
      write_source(Ctx, Op),
      ghc_unify(Ctx, Car, UnifyOperations),
      ghc_unify(Ctx, Cdr, UnifyOperations)
    ; atomic(X)
      ->
      Op =.. [out_constant, X, reg(out, Nreg)],
      write_source(Ctx, Op)
    ; functor(X, F, Nf), X =.. [_|As]
      ->
      Op =.. [out_structure, F / Nf, reg(out, Nreg)],
      write_source(Ctx, Op),
      ghc_unify_structure_args(Ctx, As, UnifyOperations)
    ; fail).
ghc_set(Ctx, reg(Reg, Nreg), X) :-
    UnifyOperations = [ write_variable, write_value,
                        write_constant, write_nil,
                        write_list, write_structure,
                        write_void ],
    ( get(Ctx, X, reg(Reg, Nreg))
      ->
      Op =.. [set_value, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; var(X)
      ->
      put(Ctx, X, reg(Reg, Nreg)),
      Op =.. [set_variable, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; X = []
      ->
      put(Ctx, X, reg(Reg, Nreg)),
      Op =.. [set_nil, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; X = [Car|Cdr]
      ->
      put(Ctx, X, reg(Reg, Nreg)),
      Op =.. [set_list, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify(Ctx, Car, UnifyOperations),
      ghc_unify(Ctx, Cdr, UnifyOperations)
    ; atomic(X)
      ->
      put(Ctx, X, reg(Reg, Nreg)),
      Op =.. [set_constant, X, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; functor(X, F, Nf), X =.. [_|As]
      ->
      put(Ctx, X, reg(Reg, Nreg)),
      Op =.. [set_structure, F / Nf, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify_structure_args(Ctx, As, UnifyOperations)
    ; fail).
ghc_unify(Ctx, Arg, UnifyOperations) :-
    UnifyOperations = [ UnifyVariable, UnifyValue,
                        UnifyConstant, UnifyNil,
                        UnifyList, UnifyStructure,
                        UnifyVoid ],
    ( var(Arg) ->
      ( is_singleton(Ctx, Arg)
        ->
        write_source(Ctx, UnifyVoid)
      ; get(Ctx, Arg, reg(Reg, Nreg))
        ->
        Op =.. [UnifyValue, reg(Reg, Nreg)],
        write_source(Ctx, Op)
      ; put(Ctx, Arg, reg(Reg, Nreg))
        ->
        Op =.. [UnifyVariable, reg(Reg, Nreg)],
        write_source(Ctx, Op) )
    ; Arg = []
      ->
      write_source(Ctx, UnifyNil)
    ; atomic(Arg)
      ->
      Op =.. [UnifyConstant, Arg],
      write_source(Ctx, Op)
    ; Arg = [Car|Cdr]
      ->
      write_source(Ctx, UnifyList),
      ghc_unify(Ctx, Car, UnifyOperations),
      ghc_unify(Ctx, Cdr, UnifyOperations)
    ; functor(Arg, F, Nf), Arg =.. [_|As]
      ->
      Op =.. [UnifyStructure, F / Nf],
      write_source(Ctx, Op),
      ghc_unify_structure_args(Ctx, As, UnifyOperations)
    ; fail).
ghc_unify_structure_args(_, [], _) :- !.
ghc_unify_structure_args(Ctx, [Arg|Args], UnifyOperations) :-
    ghc_unify(Ctx, Arg, UnifyOperations),
    ghc_unify_structure_args(Ctx, Args, UnifyOperations).

%% ghc_get_check(?Ctx, +Register, +X)
% パッシブモードでのガードチェック処理を生成する。
% ガードチェック処理は check 系命令と、それに続く read 系命令からなる。
ghc_get_check(Ctx, reg(Reg, Nreg), X) :-
    ghc_get(Ctx, reg(Reg, Nreg), X,
            [ check_variable, check_value,
              check_constant, check_nil,
              check_list, check_structure ],
            [ read_variable, read_value,
              read_constant, read_nil,
              read_list, read_structure,
              read_void ]).
%% ghc_get(?Ctx, +Register, +X)
% get 系命令およびそれに続く unify 系命令列を生成する。
ghc_get(Ctx, reg(Reg, Nreg), X) :-
    ghc_get(Ctx, reg(Reg, Nreg), X,
            [ get_variable, get_value,
              get_constant, get_nil,
              get_list, get_structure ],
            [ unify_variable, unify_value,
              unify_constant, unify_nil,
              unify_list, unify_structure,
              unify_void ]).

ghc_get(Ctx, reg(Reg, Nreg), X,
        [ GetVariable, GetValue,
          GetConstant, GetNil,
          GetList, GetStructure ],
        UnifyOperations) :-
    ( var(X) ->
      ( get(Ctx, X, reg(R, N))
        ->
        Op =.. [GetValue, reg(R, N), reg(Reg, Nreg)],
        write_source(Ctx, Op)
      ; put(Ctx, X, reg(R, N))
        ->
        Op =.. [GetVariable, reg(R, N), reg(Reg, Nreg)],
        write_source(Ctx, Op) )
    ; X = []
      ->
      Op =.. [GetNil, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; X = [Car|Cdr]
      ->
      Op =.. [GetList, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify(Ctx, Car, UnifyOperations),
      ghc_unify(Ctx, Cdr, UnifyOperations)
    ; atomic(X)
      ->
      Op =.. [GetConstant, X, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; functor(X, F, Nf), X =.. [_|As]
      ->
      Op =.. [GetStructure, F / Nf, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify_structure_args(Ctx, As, UnifyOperations)
    ; fail).

%% ghc_compile_call(?Ctx, +SeqPar, +Goal)
% サブゴール Goal の呼び出し処理をコンパイルする。
ghc_compile_call(Ctx, SeqPar, Goal) :-
    ( SeqPar = seq -> write_source(Ctx, seq(Nf, _))
    ; SeqPar = par -> write_source(Ctx, par(Nf, _))
    ; SeqPar = tail -> write_source(Ctx, tail(Nf, _)) ),
    functor(Goal, F, Nf), Goal =.. [_|Args],
    ghc_call_args(Ctx, Args, 1),
    ( SeqPar = seq -> write_source(Ctx, call(F / Nf))
    ; SeqPar = par -> write_source(Ctx, spawn(F / Nf))
    ; SeqPar = tail -> write_source(Ctx, execute(F / Nf)) ).
ghc_call_args(_, [], _) :- !.
ghc_call_args(Ctx, [Arg|Args], N) :-
    ghc_out(Ctx, reg(out, N), Arg),
    N1 is N + 1,
    ghc_call_args(Ctx, Args, N1).

%% ghc_compile_goal_body(?Ctx, +Body)
% ボディ部の処理をコンパイルする。
% '->' が含まれる場合、'->' の前の部分は逐次実行(seq)する。
% '->' が含まれない場合、あるいは '->' の後ろの部分は並列実行(par)する。
% 但し、並列実行の最後は末尾呼び出し最適化としてジャンプ(tail)に置き換える。
ghc_compile_goal_body(Ctx, (_|Body)) :- !,
    % write_source(Ctx, comment(body(Body))),
    always_success(ghc_flatten_goal_body(Ctx, par, Body, FlatBody)),
    ghc_compile_goal_list(Ctx, FlatBody).
ghc_compile_goal_body(Ctx, Body) :-
    % write_source(Ctx, comment(body(Body))),
    always_success(ghc_flatten_goal_body(Ctx, par, Body, FlatBody)),
    ghc_compile_goal_list(Ctx, FlatBody).
%% ghc_flatten_goal_body(?Ctx, SeqPar, Body, FlatBody)
% '->' を含むなどして木構造になっている可能性のある Body を
% 線形リスト FlatBody に書き換える。
% 同時に、'->' の前の部分に seq をマークする。
ghc_flatten_goal_body(Ctx, SeqPar, (B1,B2), FlatBody) :-
    !,
    ghc_flatten_goal_body(Ctx, SeqPar, B1, Body1),
    ghc_flatten_goal_body(Ctx, SeqPar, B2, Body2),
    append(Body1, Body2, FlatBody).
ghc_flatten_goal_body(Ctx, SeqPar, (B1->B2), FlatBody) :-
    !,
    ghc_flatten_goal_body(Ctx, seq, B1, Body1),
    ghc_flatten_goal_body(Ctx, SeqPar, B2, Body2),
    append(Body1, Body2, FlatBody).
ghc_flatten_goal_body(_, SeqPar, B, [body(SeqPar, B)]) :-
    !.

%% ghc_compile_goal_list(+Ctx, +FlatBody)
% ボディ部を WAM 風中間コードにコンパイルする。
ghc_compile_goal_list(Ctx, []) :-
    !, write_source(Ctx, proceed).
ghc_compile_goal_list(Ctx, [body(SeqPar, Goal)|Bodys]) :-
    ( Bodys == []
    ->
      always_success(ghc_compile_tail_call(Ctx, Goal))
    ; always_success(ghc_compile_goal_call(Ctx, SeqPar, Goal)),
      always_success(ghc_compile_goal_list(Ctx, Bodys)) ).
% サブゴール呼び出し処理
ghc_compile_goal_call(Ctx, SeqPar, Goal) :-
    write_source(Ctx, comment(body(Goal))),
    ( Goal == true -> true
    ; Goal = (X=Y)
      ->
      ( get(Ctx, X, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), Y)
      ; get(Ctx, Y, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), X)
      ; ghc_set(Ctx, reg(x, Nreg), X),
        ghc_get(Ctx, reg(x, Nreg), Y) )
    ; ghc_compile_call(Ctx, SeqPar, Goal)
    ; fail).
% 最後のサブゴール呼び出し処理。
% tail-call 呼び出しするか、さもなければ proceed を実行し
% seq-call 呼び出し元に戻るか、別のコンテキストに移るかする。
ghc_compile_tail_call(Ctx, Goal) :-
    write_source(Ctx, comment(body(Goal))),
    ( Goal == true
      ->
      write_source(Ctx, proceed)
    ; Goal = (X=Y)
      ->
      ( get(Ctx, X, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), Y)
      ; get(Ctx, Y, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), X)
      ; ghc_set(Ctx, reg(x, Nreg), X),
        ghc_get(Ctx, reg(x, Nreg), Y) ),
      write_source(Ctx, proceed)
    ; ghc_compile_call(Ctx, tail, Goal)
    ; fail).

%% allocate_registers(?Ctx, +N)
% 変数をレジスタスタック上の位置に割り付ける。
% 割り付けに使用しなかった領域は seq-call / tail-call 用に用いる。
allocate_registers(Ctx, N) :-
    get(Ctx, ghc_source, Source),
    always_success(allocate_registers_x(Ctx, Source, N, _)),
    N1 is N + 1,
    always_success(allocate_registers_out(Ctx, N1)).

allocate_registers_x(Ctx, Source, Vn, Vn2) :-
    always_success(correct_xy_vars(Ctx, Source, VarsKvs)),
    always_success(allocate_vars(VarsKvs, Vn, Vn2)).

correct_xy_vars(Ctx, Source, VarsKvs) :-
    create(VarsKvs),
    correct_xy_vars(Ctx, Source, 0, VarsKvs).
correct_xy_vars(_, [], _, _) :- !.
correct_xy_vars(Ctx, [S|Ss], N, Vars) :-
    N1 is N + 1,
    ( var(S) -> correct_xy_vars(Ctx, Ss, N1, Vars) 
    ; correct_xy_vars_in_term(Ctx, S, N1, Vars),
      correct_xy_vars(Ctx, Ss, N1, Vars) ).
correct_xy_vars_in_term(_, S, _, _) :-
    var(S), !.
correct_xy_vars_in_term(_, reg(x, NReg), N, Vars) :- !,
    ( get(Vars, NReg, (Start, _)) ->
      put(Vars, NReg, (Start, N))
    ; put(Vars, NReg, (N, N)) ) .
correct_xy_vars_in_term(_, reg(y, NReg), N, Vars) :- !,
    ( get(Vars, NReg, (Start, _)) ->
      put(Vars, NReg, (Start, 99999))
    ; put(Vars, NReg, (N, 99999)) ) .
correct_xy_vars_in_term(_, [], _, _) :- !.
correct_xy_vars_in_term(Ctx, [S|Ss], N, Vars) :- !,
    correct_xy_vars_in_term(Ctx, S, N, Vars),
    correct_xy_vars_in_term(Ctx, Ss, N, Vars).
correct_xy_vars_in_term(Ctx, S, N, Vars) :-
    S =.. [_|Args], !,
    correct_xy_vars_in_term(Ctx, Args, N, Vars).

allocate_vars(VarsKvs, Vn, Vn2) :-
    gc(VarsKvs, VarsKvs1),
    kvs_to_list(VarsKvs1, VarsList0),
    always_success(sort_vars_list(VarsList0, VarsList1)),
    always_success(assign_vars_list(VarsList1, Vn, Vn2)).

kvs_to_list(kvs(VarsKvs), VarsList) :-
    copy_list(VarsKvs, VarsList).
copy_list(V, []) :- var(V), !.
copy_list([H|T], [H|T2]) :-
    copy_list(T, T2).

sort_vars_list(Ls, Sorted) :-
    sort_vars_list(Ls, Sorted, []).
sort_vars_list([], Ac, Ac).
sort_vars_list([H|T], Sorted, Ac) :-
    insert_var_list(H, Ac, Ac2),
    sort_vars_list(T, Sorted, Ac2).
insert_var_list(X, [Y|T], [Y|T2]) :-
    X = _- put((Xs,Xe)),
    Y = _- put((Ys,Ye)),
    Xl is Xe - Xs,
    Yl is Ye - Ys,
    Xl =< Yl,
    insert_var_list(X, T, T2).
insert_var_list(X, [Y|T], [X,Y|T]) :-
    X = _- put((Xs,Xe)),
    Y = _- put((Ys,Ye)),
    Xl is Xe - Xs,
    Yl is Ye - Ys,
    Xl > Yl.
insert_var_list(X, [], [X]).

assign_vars_list(VarsList, Vn, Vn2) :-
    always_success(assign_vars_list(VarsList, VarsList, Vn, Vn2, Vn)).
assign_vars_list([], _, _, Vmax, Vmax) :- !.
assign_vars_list([Var|Vs], AllVars, Vmin, Vmax, Ac) :-
    always_success(assign_single_var(Var, AllVars, Vmin, Vn)),
    max([Vn, Ac], Ac2),
    always_success(assign_vars_list(Vs, AllVars, Vmin, Vmax, Ac2)).

assign_single_var(Var, AllVars, Vmin, Vmax) :-
    Var = V-put((_,_)),
    ( var(V) ->
      always_success(find_overwrap(Var, AllVars, Overwrap)),
      always_success(assign_non_overwrap(Var, Overwrap, Vmin)),
      Var = Vmax-put((_,_))
    ; Vmin = Vmax ).
    
not_assignable([O-_|Overwrap], Vn) :-
    ( O == Vn -> true
    ; not_assignable(Overwrap, Vn) ).
assign_non_overwrap(Var, Overwrap, Vn) :-
    Vn1 is Vn + 1, 
    ( not_assignable(Overwrap, Vn1) ->
      assign_non_overwrap(Var, Overwrap, Vn1)
    ; Var = Vn1-put((_,_)) ).

find_overwrap(Var, AllVars, Overwrap) :-
    find_overwrap(Var, AllVars, Overwrap, []).
find_overwrap(_-put((_,_)), [], Ac, Ac) :- !.
find_overwrap(Var, [Var2|Vars], Overwrap, Ac) :-
    Var = _-put((S,E)),
    Var2 = V2-put((S2,E2)),
    ( integer(V2), overwrap(S, E, S2, E2) ->
      find_overwrap(Var, Vars, Overwrap, [Var2|Ac])
    ; find_overwrap(Var, Vars, Overwrap, Ac) ).
overwrap(S, E, S2, _) :- S =< S2, S2 =< E.
overwrap(S, E, _, E2) :- S =< E2, E2 =< E.
overwrap(S, _, S2, E2) :- S2 =< S, S =< E2.
overwrap(_, E, S2, E2) :- S2 =< E, E =< E2.

% out レジスタ位置を割り当てる。
% call 実行までに使用しているレジスタを除外したうえで
% 最も低い位置の未使用レジスタ位置を out レジスタ位置とする。
allocate_registers_out(Ctx, N) :-
    get(Ctx, ghc_source, Source),
    allocate_registers_out(Ctx, Source, N, _).
allocate_registers_out(_, [], Vn, Vn) :- !.
allocate_registers_out(Ctx, [S|Ss], N, Vn) :-
    ( S = seq(_, Out)
      ->
      always_success(allocate_registers_out(Ctx, Ss, N, Out))
    ; S = par(_, Out)
      ->
      always_success(allocate_registers_out(Ctx, Ss, N, Out))
    ; S = tail(_, Out)
      ->
      always_success(allocate_registers_out(Ctx, Ss, N, Out))
    ; ( S =.. [call|_] ; S =.. [spawn|_] ; S =.. [execute|_] )
      ->
      Vn is N + 1,
      always_success(allocate_registers_out(Ctx, Ss, N, _))
    ; always_success(find_used_registers(Ctx, S, _, N, N1)),
      always_success(allocate_registers_out(Ctx, Ss, N1, Vn) )).
    
%% max_register_index(+Ctx, +Type, -Max)
% 現在のコンパイルコード（ゴール単位の断片）で使用している最大レジスタ位置を
% Max に返す。
% コンパイルコードは Ctx に ghc_source の値として格納されている。
max_register_index(Ctx, Type, Max) :-
    get(Ctx, goal, goal(_, Min0)),
    get(Ctx, ghc_source, Source),
    Min is Min0 + 1,
    max_register_index(Ctx, Source, Type, Min, Max).
max_register_index(_, [], _, Max, Max) :- !.
max_register_index(Ctx, [S|Ss], Type, N, Max) :-
    find_used_registers(Ctx, S, Type, N, N1),
    max_register_index(Ctx, Ss, Type, N1, Max).

%% find_used_registers(+Ctx, +A, +Type, +N, -N1)
% 使用しているレジスタ位置を N1 に返す。
% +A : 検査対象の項
% +N : これまでに使用したレジスタの最大位置
% -N1 : A を含めてこれまでに使用したレジスタの最大位置
find_used_registers(Ctx, A, Type, N, N1) :-
    ( var(A) -> N1 = N
    ; A == [] -> N1 = N
    ; A = [X|Xs]
    ->
      find_used_registers(Ctx, X, Type, N, N2),
      find_used_registers(Ctx, Xs, Type, N, N3),
      ( N2 > N3 -> N1 = N2 ; N1 = N3)
    ; A = reg(Type, X)
    ->
      ( X > N -> N1 = X ; N1 = N)
    ; A =.. [_|As]
    ->
      find_used_registers(Ctx, As, Type, N, N1) ).

%% max_seq_par_tail(+Ctx, -Max)
max_seq_par_tail(Ctx, Max) :-
    get(Ctx, ghc_source, Source),
    max_seq_par_tail_aux(Source, Max, 0).
max_seq_par_tail_aux([], Max, Max).
max_seq_par_tail_aux([seq(Arity, Seq)|Ss], Max, Ac) :-
    !,
    SeqArity is Seq + Arity,
    ( SeqArity < Ac -> max_seq_par_tail_aux(Ss, Max, Ac)
    ; max_seq_par_tail_aux(Ss, Max, SeqArity) ).
max_seq_par_tail_aux([par(Arity, Par)|Ss], Max, Ac) :-
    !,
    ParArity is Par + Arity,
    ( ParArity < Ac -> max_seq_par_tail_aux(Ss, Max, Ac)
    ; max_seq_par_tail_aux(Ss, Max, ParArity) ).
max_seq_par_tail_aux([tail(Arity, Tail)|Ss], Max, Ac) :-
    !,
    TailArity is Tail + Arity,
    ( TailArity < Ac -> max_seq_par_tail_aux(Ss, Max, Ac)
    ; max_seq_par_tail_aux(Ss, Max, TailArity) ).
max_seq_par_tail_aux([_|Ss], Max, Ac) :-
    !, max_seq_par_tail_aux(Ss, Max, Ac).

%% assign_labels(?Ctx)
% Ctx に ghc_source の値として格納されているコンパイルコード上の
% 名前が確定していないラベルに名前をつける。
assign_labels(Ctx) :-
    get(Ctx, goal, goal(G, N)),
    get(Ctx, ghc_source, Source),
    assign_labels(Ctx, G, N, 1, Source, 1).
assign_labels(_, _, _, _, [], _) :- !.
assign_labels(Ctx, G, N, PredNo, [S|Ss], I) :-
    !,
    ( S = label(G / N - PredNo2) ->
      assign_labels(Ctx, G, N, PredNo2, Ss, I)
    ; S = label(G / N - PredNo - I) ->
      I1 is I + 1, assign_labels(Ctx, G, N, PredNo, Ss, I1)
    ; assign_labels(Ctx, G, N, PredNo, Ss, I) ).

%% write_source(?Ctx, +Msg)
% Ctx に ghc_source の値として格納しているコンパイルコードに
% Msg を追加する。
write_source(Ctx, Msg) :-
    ( get(Ctx, ghc_source, Source)
    ->
    append(Source, [Msg], Source2),
    put(Ctx, ghc_source, Source2)
    ; put(Ctx, ghc_source, [Msg])).
%% flush_source(+Ctx, +OStream)
% Ctx に ghc_source の値として格納しているコンパイルコードを
% OStream に書き込む。
% このとき、ある程度見やすく整形する。
flush_source(Ctx, OStream) :-
    get(Ctx, ghc_source, Source),
    dump(Ctx, Source, OStream).
dump(_, [], _) :- !.
dump(Ctx, [S|Ss], OStream) :-
    ( S =.. [label|_] -> print(OStream, S)
    ; S = comment(C) ->
      get(Ctx, vars, Vars),
      translate_var_names(Vars, C, C2),
      indent(2, OStream), format(OStream, '% ~w', [C2])
    ; ( S =.. [set_variable|_] ; S =.. [set_value|_]
      ; S =.. [set_constant|_] ; S =.. [set_nil|_]
      ; S =.. [set_list|_] ; S =.. [set_structure|_]
      ; S =.. [out_variable|_] ; S =.. [out_value|_]
      ; S =.. [out_constant|_] ; S =.. [out_nil|_]
      ; S =.. [out_list|_] ; S =.. [out_structure|_]
      ; S =.. [get_variable|_] ; S =.. [get_value|_]
      ; S =.. [get_constant|_] ; S =.. [get_nil|_]
      ; S =.. [get_list|_] ; S =.. [get_structure|_]
      ; S =.. [check_variable|_] ; S =.. [check_value|_]
      ; S =.. [check_constant|_] ; S =.. [check_nil|_]
      ; S =.. [check_list|_] ; S =.. [check_structure|_]
      ; S =.. [call|_] ; S =.. [spawn|_] ; S =.. [execute|_] )
      ->  indent(4, OStream), print(OStream, S)
    ; ( S =.. [write_variable|_] ; S =.. [write_value|_]
      ; S =.. [write_constant|_] ; S =.. [write_nil|_]
      ; S =.. [write_list|_] ; S =.. [write_structure|_]
      ; S =.. [write_void|_]
      ; S =.. [unify_variable|_] ; S =.. [unify_value|_]
      ; S =.. [unify_constant|_] ; S =.. [unify_nil|_]
      ; S =.. [unify_list|_] ; S =.. [unify_structure|_]
      ; S =.. [unify_void|_]
      ; S =.. [read_variable|_] ; S =.. [read_value|_]
      ; S =.. [read_constant|_] ; S =.. [read_nil|_]
      ; S =.. [read_list|_] ; S =.. [read_structure|_]
      ; S =.. [read_void|_])
      ->  indent(6, OStream), print(OStream, S)
    ; indent(2, OStream), print(OStream, S)),
    writeln(OStream, '.'),
    dump(Ctx, Ss, OStream).
%% indent(+N, +OStream)
% N 個の空白を OStream に出力する。
indent(N, OStream) :-
    ( N =< 0 -> true
    ; write(OStream, ' '), N1 is N - 1, indent(N1, OStream) ).
is_singleton1([], _) :- !.
is_singleton1([_=Var|Vars], Arg) :-
    ( Var == Arg -> fail
    ; is_singleton1(Vars, Arg) ).
is_singleton(Ctx, Arg) :-
    get(Ctx, vars, Vars),
    is_singleton1(Vars, Arg).

translate_var_name1([], C, C) :- !.
translate_var_name1([Name=Var|Vars], C, C2) :-
    ( C == Var -> C2 = Name
    ; translate_var_name1(Vars, C, C2) ).
translate_var_names(Ctx, C, C2) :-
    var(C) -> translate_var_name1(Ctx, C, C2).
translate_var_names(_, [], []).
translate_var_names(Vars, [A|B], [A2|B2]) :-
    translate_var_names(Vars, A, A2),
    translate_var_names(Vars, B, B2).
translate_var_names(Vars, C, C2) :-
    C =.. [F|Args],
    translate_var_names(Vars, Args, Args2),
    C2 =.. [F|Args2].
