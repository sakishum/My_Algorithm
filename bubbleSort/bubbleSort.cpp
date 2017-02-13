/**
 * @file bubbleSort.cpp
 * @Synopsis  Bubble sort
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-02-06
 */
#include <iostream>
#include <assert.h>
#include "bubbleSort.h"
using namespace std;

Ret bubble_sort(void** array, size_t nr, DataCompareFunc cmp) {
	size_t i = 0;
	size_t max = 0;
	size_t right = 0;
	return_val_if_fail(array != NULL && cmp != NULL, RET_PARAMS);
	if (nr < 2) {
		return RET_OK;
	}

	for (right = nr - 1; right > 0; right--) {
		for (i = 1, max = 0; i < right; ++i) {
			if (cmp(array[i], array[max]) > 0) {
				max = i;
			}
		}

		if (cmp(array[max], array[right]) > 0) {
			void* data = array[right];
			array[right] = array[max];
			array[max] = data;
		}
	}

	return RET_OK;
}
