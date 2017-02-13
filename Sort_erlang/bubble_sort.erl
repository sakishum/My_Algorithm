-module(bubble_sort).
-compile(export_all).

bubble_sort([]) -> [];
bubble_sort(List) when length(List) =< 1 -> List;
bubble_sort(List) when is_list(List) ->
	bubble_sort(List, []).

bubble_sort([X], Sorted) -> [X|Sorted];
bubble_sort(List, Sorted) ->
	[Max | Rest] = bubble_move(List, []),
	bubble_sort(Rest, [Max | Sorted]).

bubble_move([X], Rest) -> [X|Rest];
bubble_move([X, Y | T], Rest) ->
	if X > Y -> 
			bubble_move([X|T], [Y|Rest]);
		true -> 
			bubble_move([Y|T], [X|Rest])
	end.

test() ->
	List = [8,2,6,1,3,9,4,5,7],
	bubble_sort(List).
