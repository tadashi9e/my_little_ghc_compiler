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
    ghc_load_all_terms(SourceFiles, Source)
    -> ghc_compile(Source, WamFile).

%% ghc_load_all_terms(+SourceFiles, -Source)
% 与えられたファイル SourceFiles からすべての項を出現順に読み取り、
% GHC ソースコード Source として返す。
ghc_load_all_terms([], []) :- !.
ghc_load_all_terms([SourceFile|SourceFiles], Source) :-
    open(SourceFile, read, Stream, [encoding(utf8)]),
    ghc_read_all_terms(Stream, Ss),
    close(Stream),
    append(Ss, Ss2, Source),
    ghc_load_all_terms(SourceFiles, Ss2).
ghc_read_all_terms(Stream, Source) :-
    read_term(Stream, Term, []),
    ( Term = end_of_file -> Source = []
    ; Source = [Term|Source2],
      ghc_read_all_terms(Stream, Source2)).

%% ghc_compile(+Source, +OFile)
% GHC ソースコード Source を WAM 風中間コードにコンパイルして
% OFile に書き込む。
ghc_compile(Source, WamFile) :-
    ghc_collect_goals(Source, Goals),
    open(WamFile, write, OStream, [create([write]), encoding(utf8)]),
    always_success(ghc_compile_goals(Goals, Source, OStream)),
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
ghc_compile_goals([], _, _) :- !.
ghc_compile_goals([Goal|Goals], Source, OStream) :-
    find_goal_source(Goal, Source, GoalSource),
    create(Ctx),
    write_goal_entry_point(Ctx, Goal),
    put(Ctx, goal, Goal),
    always_success(
        ( ghc_compile_inline(Ctx, Goal, GoalSource)
        ; ghc_compile_goal(Ctx, [], Goal, GoalSource) )),
    assign_labels(Ctx),
    max_register_index(Ctx, x, MaxReg_x),
    max_register_index(Ctx, out, MaxReg_out),
    MaxReg is MaxReg_x + MaxReg_out,
    get(Ctx, max_reg, MaxReg),
    flush_source(Ctx, OStream),
    always_success(ghc_compile_goals(Goals, Source, OStream)).

%% write_goal_entry_point(?Ctx, +Goal)
% Ctx に ghc_source の値として格納しているコンパイルコードに
% ゴール先頭部分のコードを追加する。
% 1. ゴール処理開始位置ラベル: label(ゴール名 / アリティ)
% 2. 実行トレース用情報: goal(ゴール名 / アリティ)
% 3. 消費レジスタサイズヒント: requires(最大使用レジスタ数)
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

%% ghc_compile_goal(?Ctx, ?Label, +Goal, +GoalSource)
% ゴール Goal に対応するソースコード GoalSource を元に
% WAM 風中間コードを生成し、Ctx に ghc_source の値として格納する。
ghc_compile_goal(Ctx, Label, Goal, GoalSource) :-
    ghc_compile_goal(Ctx, Label, Goal, 1, GoalSource).
ghc_compile_goal(_, _, _, _, []) :- !.
ghc_compile_goal(Ctx, Label, goal(G, N), PredNo, [(Head :- Body)|GoalSource]) :-
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
    always_success(assign_registers(Ctx, N)),
    PredNo1 is PredNo + 1,
    always_success(ghc_compile_goal(Ctx, NextLabel, goal(G, N), PredNo1, GoalSource)).
ghc_compile_goal(Ctx, Label, goal(G, N), PredNo, [Head|GoalSource]) :-
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
    always_success(assign_registers(Ctx, N)),
    PredNo1 is PredNo + 1,
    always_success(ghc_compile_goal(Ctx, NextLabel, goal(G, N), PredNo1, GoalSource)).

%% ghc_compile_head_args(?Ctx, +Head)
% GHC ソースコードのヘッド部 Head に対応する WAM 風中間コードを生成し、
% Ctx に ghc_source の値として格納する。
ghc_compile_head_args(Ctx, Head) :-
    write_source(Ctx, comment(head(Head))),
    Head =.. [_|Args],
    ghc_compile_head_args(Ctx, Args, 1).
ghc_compile_head_args(_, [], _) :- !.
ghc_compile_head_args(Ctx, [Arg|Args], N) :-
    ( var(Arg) -> put(Ctx, Arg, reg(in, N)) ; true),
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
      ( get(Ctx, X, reg(in, Ai)) ->
        write_source(Ctx, wait_value(Ai)) )
    ; Guard = (X = Y) ->
      ( get(Ctx, X, reg(in, Ai)) ->
        always_success(ghc_get_check(Ctx, reg(in, Ai), Y))
      ; get(Ctx, Y, reg(in, Ai)) ->
        always_success(ghc_get_check(Ctx, reg(in, Ai), X))
      ; format('warning: Guard may not be efficient: ~w~n', [Guard]),
        put(Ctx, _, reg(x, Xn)),
        always_success(ghc_put(Ctx, reg(x, Xn), X)),
        always_success(ghc_get_check(Ctx, reg(x, Xn), Y)))
    ; ghc_compile_call(Ctx, seq, Guard)
    ; format('error: invalid guard: ~w~n', [Guard]), fail).

%% ghc_put(?Ctx, +Register, +X)
% put 系命令およびそれに続く write 系命令列を生成する。
% - put_variable(Vn, Ai) は Vn := Ai := ref<&H[0]>, H += 1
%  つまり、ヒープ上に未実現引数を確保して Vn と Ai に代入する。
% - put_value(Vn, Ai) は Ai := Vn
%  つまり、Ai に Vn を代入する。
% - put_nil(Ai) は Ai := []
%  つまり、A[i] に [] を代入する。
% put_constant(C, Ai) は Ai := C
%  つまり、A[i] に C を代入する。
% - put_list(Ai) は
%  Ai := list<H>, push(&H[1]), push(&H[0]),
%  H += 2
%  つまり、CAR/CDRはヒープ上に領域だけ確保して設定は後続の write 系命令に委ねる。
% - put_structure(F / N, Ai) は
%  Ai := str<H>,
%  H[0] = F/N, push(&H[N]), push(&H[ref(N-1)]),.., push(&H[1]),
%  H += N
%  つまり、引数はヒープ上に領域だけ確保して設定は後続の write 命令に委ねる。
%
% put 系命令に続けて、引数の組み立てを継続する。
% - write_variable(Vn)/out_variable(Vn) は p = pop(), Vn := *p
%  つまり、スタックからポインタを取り出してその場所の値を Vn を代入する。
% - write_value(Vn)/out_value(Vn) は p = pop(), *p := Vn
%  つまり、スタックからポインタを取り出してその場所に Vn を代入する。
% - write_nil/out_nil は p = pop(), *p := []
%  つまり、スタックからポインタを取り出してその場所に [] を代入する。
% - write_constant(C)/out_constant(C) は p = pop(), *p := C
%  つまり、スタックからポインタを取り出してその場所に C を代入する。
% - write_list/out_list は
%  p = pop(), *p := list<&H[0]>,
%  push(&H[1]), push(&H[0]),
%  H += 2
%  つまり、新たに作るリストの CAR/CDR の場所をヒープ上に確保し、
%  スタックから取り出したポインタにその場所を書き込む。
%  また、CAR/CDR を処理継続のためにスタックにプッシュする。
% - write_structure(F / N)/out_structure(F / N) は
%  p = pop(), *p = str<&H[0]>,
%  H[0] = atm<F/N>, push(&H[N]), push(&H[N-1]),.., push(&H[1]), 
%  H += N
%  つまり、新たに作る構造体の場所をヒープ上に確保し、
%  スタックから取り出したポインタにその場所を書き込む。
%  また、構造体引数を処理継続のためにスタックにプッシュする。
%
ghc_put(Ctx, reg(x, Nreg), X) :-
    ghc_put(Ctx, reg(x, Nreg), X,
            [ put_variable, put_value,
              put_constant, put_nil,
              put_list, put_structure ]).
ghc_put(Ctx, reg(out, Nreg), X) :-
    ghc_put(Ctx, reg(out, Nreg), X,
            [ out_variable, out_value,
              out_constant, out_nil,
              out_list, out_structure ]).
ghc_put(Ctx, reg(Reg, Nreg), X,
        PutOperations) :-
    PutOperations = [ PutVariable, PutValue,
                      PutConstant, PutNil,
                      PutList, PutStructure ],
    UnifyOperations = [ write_variable, write_value,
                        write_constant, write_nil,
                        write_list, write_structure ],
    ( var(X) ->
      ( get(Ctx, X, reg(R, N))
        ->
        Op =.. [PutValue, reg(R, N), reg(Reg, Nreg)],
        write_source(Ctx, Op)
      ; put(Ctx, X, reg(x, N))
        ->
        Op =.. [PutVariable, reg(x, N), reg(Reg, Nreg)],
        write_source(Ctx, Op) )
    ; X = []
      ->
      Op =.. [PutNil, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; X = [Car|Cdr]
      ->
      Op =.. [PutList, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify(Ctx, Car, UnifyOperations),
      ghc_unify(Ctx, Cdr, UnifyOperations)
    ; atomic(X)
      ->
      Op =.. [PutConstant, X, reg(Reg, Nreg)],
      write_source(Ctx, Op)
    ; functor(X, F, Nf), X =.. [_|As]
      ->
      Op =.. [PutStructure, F / Nf, reg(Reg, Nreg)],
      write_source(Ctx, Op),
      ghc_unify_structure_args(Ctx, As, UnifyOperations)
    ; fail).
ghc_unify(Ctx, Arg, UnifyOperations) :-
    UnifyOperations = [ UnifyVariable, UnifyValue,
                        UnifyConstant, UnifyNil,
                        UnifyList, UnifyStructure ],
    ( var(Arg) ->
      ( get(Ctx, Arg, reg(Reg, Nreg))
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
%
% - check_variable(Vn, Ai)
%  V[n] := A[i]
% - check_value(Vn, Ai)
%  A[i] が未実現なら実現待ち合わせリストに登録して fail。
%  実現済みなら V[n] の値と一致するか調べて、一致しなければ fail。
% - check_constant(C, Ai)
%  A[i] が未実現なら実現待ち合わせリストに登録して fail。
%  実現済みなら C と一致するか調べて、一致しなければ fail。
% - check_nil(Ai)
%  A[i] が未実現なら実現待ち合わせリストに登録して fail。
%  実現済みなら [] と一致するか調べて、一致しなければ fail。
% - check_list(Ai)
%  A[i] が未実現なら実現待ち合わせリストに登録して fail。
%  実現済みならリストか調べて、リストでなければ fail。
%  リストならその CAR/CDR をスタックにプッシュする。
% - check_structure(F / N, Ai)
%  A[i] が未実現なら実現待ち合わせリストに登録して fail。
%  実現済みなら構造体 F/N か調べて、構造体 F/N でなければ fail。
%  構造体 F/N なら N 個の引数すべてをスタックにプッシュする。
%
% check 系命令に続くガード処理は以下。
% - read_variable(Vn) は p = pop(), Vn := *p
% - read_value(Vn) は p = pop(), if (Vn != *p) then fail
% - read_nil は p = pop(), if ([] != *p) then fail
% - read_constant(C) は p = pop(), if (C != *p) then fail
% - read_list は
%  p = pop(),
%  if (*p is not list) then { fail }
%  else { push(&p[1] /* CDR */), push(&p[0] /* CAR */) }
% - read_structure(F / N) は
%  p = pop(),
%  if (*p is not F/N) then { fail }
%  else { push(&p[N]), push(&p[N-1]), ..., push(&p[1]) }
%
ghc_get_check(Ctx, reg(Reg, Nreg), X) :-
    ghc_get(Ctx, reg(Reg, Nreg), X,
            [ check_variable, check_value,
              check_constant, check_nil,
              check_list, check_structure ],
            [ read_variable, read_value,
              read_constant, read_nil,
              read_list, read_structure ]).
%% ghc_get(?Ctx, +Register, +X)
% get 系命令およびそれに続く unify 系命令列を生成する。
% - get_variable(Vn, Ai) は V[n] := A[i]
% - get_value(Vn, Ai) は unify(V[n], A[i])
% - get_constant(C, Ai) は unify(C, A[i])
% - get_nil(Ai) は unify([], A[i])
% - get_list(Ai) は unify([_|_], A[i])
% - get_structure(F / N, Ai) は unify(F/N, A[i])
%
% - unify_variable(Vn) は p = pop(), Vn := *p
% - unify_value(Vn) は p = pop(), unify(Vn, *p)
% - unify_constant(C) は p = pop(), unify(C, *p)
% - unify_nil は p = pop(), unify([], *p)
% - unify_list は
%  p = pop(), H[0] = ref<&H[0]>, H[1] = ref<&H[1]>,
%  unify(list<&H[0]>, *p), H += 2
% - unify_structure(F / N) は
%  p = pop(), 
%  push(&H[N]), push(&H[N-1]), ..., push(&H[1]),
%  unify(str<&H[0]>, *p), H += N
%
ghc_get(Ctx, reg(Reg, Nreg), X) :-
    ghc_get(Ctx, reg(Reg, Nreg), X,
            [ get_variable, get_value,
              get_constant, get_nil,
              get_list, get_structure ],
            [ unify_variable, unify_value,
              unify_constant, unify_nil,
              unify_list, unify_structure ]).

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
    ( SeqPar = seq -> write_source(Ctx, seq(_))
    ; SeqPar = par -> write_source(Ctx, par)
    ; SeqPar = tail -> write_source(Ctx, tail(_)) ),
    functor(Goal, F, Nf), Goal =.. [_|Args],
    ghc_call_args(Ctx, Args, 1),
    ( SeqPar = seq -> write_source(Ctx, call(F / Nf))
    ; SeqPar = par -> write_source(Ctx, spawn(F / Nf))
    ; SeqPar = tail -> write_source(Ctx, execute(F / Nf)) ).
ghc_call_args(_, [], _) :- !.
ghc_call_args(Ctx, [Arg|Args], N) :-
    ghc_put(Ctx, reg(out, N), Arg),
    N1 is N + 1,
    ghc_call_args(Ctx, Args, N1).

%% ghc_compile_goal_body(?Ctx, +Body)
% ボディ部の処理をコンパイルする。
% '->' が含まれる場合、'->' の前の部分はシーケンシャル実行(seq)する。
% '->' が含まれない場合、あるいは '->' の後ろの部分は並列実行(par)する。
% 但し、並列実行の最後は末尾呼び出し最適化としてジャンプ(tail)に置き換える。
ghc_compile_goal_body(Ctx, (_|Body)) :- !,
    %write_source(Ctx, comment(body(Body))),
    always_success(ghc_flatten_goal_body(Ctx, par, Body, FlatBody)),
    ghc_compile_goal_list(Ctx, FlatBody).
ghc_compile_goal_body(Ctx, Body) :-
    %write_source(Ctx, comment(body(Body))),
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
      write_source(Ctx, trust_me),
      ( get(Ctx, X, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), Y)
      ; get(Ctx, Y, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), X)
      ; put(Ctx, _, reg(x, Nreg)),
        ghc_put(Ctx, reg(x, Nreg), X),
        ghc_get(Ctx, reg(x, Nreg), Y) )
    ; write_source(Ctx, trust_me),
      ghc_compile_call(Ctx, SeqPar, Goal)
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
      write_source(Ctx, trust_me),
      ( get(Ctx, X, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), Y)
      ; get(Ctx, Y, reg(Reg, Nreg))
        -> ghc_get(Ctx, reg(Reg, Nreg), X)
      ; put(Ctx, _, reg(x, Nreg)),
        ghc_put(Ctx, reg(x, Nreg), X),
        ghc_get(Ctx, reg(x, Nreg), Y) ),
      write_source(Ctx, proceed)
    ; write_source(Ctx, trust_me),
      ghc_compile_call(Ctx, tail, Goal)
    ; fail).

%% assign_registers(?Ctx, +N)
% 変数をレジスタスタック上の位置に割り付ける。
% - Y-レジスタは低位に置く（現状では Y-レジスタは存在しない）。
% - X-レジスタは高位に置く。
% 割り付けに使用しなかった領域は seq-call / tail-call 用に用いる。
assign_registers(Ctx, N) :-
    keys(Ctx, Keys),
    always_success(assign_registers_x(Ctx, Keys, N, _)),
    N1 is N + 1,
    always_success(assign_registers_out(Ctx, N1)).
assign_registers_x(_, [], N, N) :- !.
assign_registers_x(Ctx, [K|Ks], N, N2) :-
    ( var(K), N1 is N + 1, get(Ctx, K, reg(x, N1))
      -> remove(Ctx, K), assign_registers_x(Ctx, Ks, N1, N2)
    ; assign_registers_x(Ctx, Ks, N, N2)).
% out レジスタ位置を割り当てる。
% call 実行までに使用しているレジスタを除外したうえで
% 最も低い位置の未使用レジスタ位置を out レジスタ位置とする。
assign_registers_out(Ctx, N) :-
    get(Ctx, ghc_source, Source),
    assign_registers_out(Ctx, Source, N, _).
assign_registers_out(_, [], Vn, Vn) :- !.
assign_registers_out(Ctx, [S|Ss], N, Vn) :-
    ( S =.. [comment|_]
    -> always_success(assign_registers_out(Ctx, Ss, N, Vn))
    ; S =.. [label|_]
    -> always_success(assign_registers_out(Ctx, Ss, N, Vn))
    ; S = seq(Out)
      ->
      always_success(assign_registers_out(Ctx, Ss, N, Out))
    ; S = tail(Out)
      ->
      always_success(assign_registers_out(Ctx, Ss, N, Out))
    ; ( S =.. [call|_] ; S =.. [spawn|_] ; S =.. [execute|_] )
      ->
      Vn is N + 1,
      always_success(assign_registers_out(Ctx, Ss, N, _))
    ; always_success(find_used_registers(Ctx, S, x, N, N1)),
      always_success(assign_registers_out(Ctx, Ss, N1, Vn) )).
    
%% max_register_index(+Ctx, +Type, -Max)
% 現在のコンパイルコード（ゴール単位の断片）で使用している最大レジスタ位置を
% Max に返す。
% コンパイルコードは Ctx に ghc_source の値として格納されている。
max_register_index(Ctx, Type, Max) :-
    get(Ctx, ghc_source, Source),
    max_register_index(Ctx, Source, Type, 0, Max).
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
    ; A =.. [comment|_] -> N1 = N
    ; A =.. [label|_] -> N1 = N
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
    dump(Source, OStream).
dump([], _) :- !.
dump([S|Ss], OStream) :-
    ( S =.. [label|_] -> print(OStream, S)
    ; S = comment(C) -> indent(2, OStream), format(OStream, '% ~w', [C])
    ; ( S =.. [put_variable|_] ; S =.. [put_value|_]
      ; S =.. [put_constant|_] ; S =.. [put_nil|_]
      ; S =.. [put_list|_] ; S =.. [put_structure|_]
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
      ; S =.. [unify_variable|_] ; S =.. [unify_value|_]
      ; S =.. [unify_constant|_] ; S =.. [unify_nil|_]
      ; S =.. [unify_list|_] ; S =.. [unify_structure|_]
      ; S =.. [read_variable|_] ; S =.. [read_value|_]
      ; S =.. [read_constant|_] ; S =.. [read_nil|_]
      ; S =.. [read_list|_] ; S =.. [read_structure|_] )
      ->  indent(6, OStream), print(OStream, S)
    ; indent(2, OStream), print(OStream, S)),
    writeln(OStream, '.'),
    dump(Ss, OStream).
%% indent(+N, +OStream)
% N 個の空白を OStream に出力する。
indent(N, OStream) :-
    ( N =< 0 -> true
    ; write(OStream, ' '), N1 is N - 1, indent(N1, OStream) ).
