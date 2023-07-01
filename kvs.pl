:- module(kvs, [create/1, put/3, get/3, remove/2, keys/2]).

%% create(-KVS)
% Key-Value-Store を作成する（未完成リストを作成する）
create(kvs(_)).

%% put(?KVS, +Key, +Value)
% KVS に Key-Value を登録する（未完成リスト末尾に編集履歴を追加する）
put(kvs(Kvs), Key, Value) :-
    append_to_last(Kvs, Key-put(Value)).

%% remove(?KVS, +Key)
% KVS から Key を削除する（未完成リスト末尾に編集履歴を追加する）
remove(kvs(Kvs), Key) :-
    append_to_last(Kvs, Key-remove).

%% get(?KVS, +Key, -Value)
% KVS から Key に対応する値を Value に取得する
% （未完成リスト上の編集履歴を辿っていって、最後の編集内容を返す）。
% なければ fail。
get(kvs(Kvs), Key, Value) :-
    find_last_entry(Kvs, Key-V) -> V = put(Value).

%% keys(?KVS, -Keys)
% KVS に含まれる全てのキーを返す。
keys(kvs(Kvs), Keys) :-
    list_all_keys(Kvs, Keys, []).
%% gc(+KVS, -KVS2)
% KVS の最新値のみを KVS2 にコピーする。
gc(kvs(Kvs), kvs(Kvs2)) :-
    list_all_keys(Kvs, Keys, []),
    copy_all(Keys, Kvs, Kvs2).

% 未完成リスト構造を保ったまま、末尾に Entry を追加する。
append_to_last([X|Xs], Entry) :-
    ( var(X) -> X = Entry
    ; append_to_last(Xs, Entry) ).
% 未完成リスト上の Key を検索し、最終要素の値あるいは none を返す。
find_last_entry(Kvs, Key-Value) :-
    find_last_entry(Kvs, Key-Value, none).
find_last_entry(Kvs, Key-Value, LastValue) :-
    ( var(Kvs) -> Value = LastValue
    ; Kvs = [K-V|Kvs2] ->
      ( K == Key -> find_last_entry(Kvs2, Key-Value, V)
      ; find_last_entry(Kvs2, Key-Value, LastValue) )).
% 未完成リスト上の Key を列挙して返す。
list_all_keys(Kvs, Keys, Ac) :-
    ( var(Kvs) -> Keys = Ac
    ; Kvs = [K-_|Kvs2] ->
      ( list_member(K, Ac)
      -> list_all_keys(Kvs2, Keys, Ac)
      ; append(Ac, [K], Ac2),
        list_all_keys(Kvs2, Keys, Ac2))).
% 未実現変数を含めて、リストに要素として含まれるかチェックする。
list_member(_, []) :- !, fail.
list_member(K, [L|Ls]) :-
    ( K == L -> true
    ; list_member(K, Ls) ).
% 与えられたキー一覧をもとに Kvs の内容を Kvs2 にコピーする。
copy_all([], _, _).
copy_all([Key|Ks], Kvs, Kvs2) :-
    find_last_entry(Kvs, Key-Entry),
    ( Entry = put(Value) -> append_to_last(Kvs2, Key-put(Value))
    ; true),
    copy_all(Ks, Kvs, Kvs2).
