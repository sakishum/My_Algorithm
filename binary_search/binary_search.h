/**
 * @file binary_search.h
 * @Synopsis  不适用递归方法的二分查找模板。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-05-15
 */
#ifndef BINARY_SEARCH_H__
#define BINARY_SEARCH_H__

#include <cstdio>
#include <cstdlib>
#include <assert.h>

template <typename T>
int binary_search_t(const T* array, size_t lower, size_t upper, T key) {
	assert(array);
	int result = -1;
	size_t mid = 0;
	while (lower <  upper) {
		mid = (lower + upper) / 2;
		if (array[mid] < key) {
			lower = mid + 1;
		} else if (array[mid] > key) {
			upper = mid - 1;
		} else {
			result = static_cast<int>(mid);
			return result;
		}
	}
	return result;
}

#endif  // BINARY_SEARCH_H__
