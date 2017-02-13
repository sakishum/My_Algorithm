-module(quick_sort).
-compile(export_all).
% quick_sort:test().

%%% 简单地说就是随便选一个中间值，然后把数组分成三块，一块是比这个中间值小的值，
%%% 一块是比这个中间值大的值，最后一块就是这个中间值。然后把得到的元素数大于二个
%%% 的数组再重复以上操作直到排序完毕。
%%% 快速排序在最差情况下的代价是n^2， 平均情况下是nlogn

quick_sort(L) when length(L) =< 1 -> L;
quick_sort([]) -> [];
quick_sort([Head|Rest]) ->
	quick_sort([X||X<-Rest, X<Head]) ++ [Head] ++ quick_sort([X||X<-Rest, X>=Head]).

quicksort(L) when length(L) =< 1 -> L;
quicksort([Pivot|T]) ->
	quicksort([X||X<-T, X<Pivot]) ++ [Pivot] ++ quicksort([X||X<-T, X>=Pivot]);
quicksort([]) -> [].

-include_lib("eunit/include/eunit.hrl").
% 不能放在头部，要紧接着_test or _test_
first_test() ->
	% （注：这里使用=:=进行判断，因此assertEqual(3, 3.0)不会测试通过）
	[?assertEqual(1, 1),
	 ?assertEqual(quick_sort([]), [])
	].

fist_test() ->
	?assertEqual(2,2).

main() ->
	L = [8,2,5,1,7,3,9,4,6],
	io:format("~p~n", [quicksort(L)]).

