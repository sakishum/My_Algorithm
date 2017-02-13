-module(insert_sort).
-compile(export_all).

%%% 每次将一个待排序的数据，插入到前面已经排好序的序列之中，直到全部数据插入完成。

%%% 1> L = [9,7,2,4,1,5,6,8].
%%% [9,7,2,4,1,5,6,8]
%%% 2> insert_sort:sort(L).
%%% [1,2,4,5,6,7,8,9]

%%% foldl(Fun, Acc0, List) -> Acc1
%%% Fun这个函数有两个参数:
%%% 第一个参数是List中的元素，第二个参数是Fun函数执行完后的返回值，这个参数第一次执行时,就是Acc0
sort(L) when length(L) =< 1 -> L;
sort(L) -> lists:foldl(fun insert/2, [], L).

insert(X, []) -> [X];
insert(X, L=[H|_]) when X =< H -> [X|L];
insert(X, [H|T]) -> [H|insert(X, T)].

