/**
 * @file main.cpp
 * @Synopsis  每次将一个待排序的数据，插入到前面已经排好序的序列之中，直到全部数据插入完成。
 *		The insertion sort, unlike the other sorts, passes through the array only once.  
 *		就像扑克发牌后，按花色大小整理手中的扑克一个意思。
 *		The insertion sort is commonly compared to organizing a handful of playing cards.
 *		You pick up the random cards one at a time.  As you pick up each card, you insert
 *		it into its correct position in your hand of organized cards.  
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-01-19
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

void print(char a[], size_t len) {
	for (size_t i = 0; i != len; ++i) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

// Insertion Sort Function for Ascending Order
// 从第二个元素开始逐个遍历之后的元素;
// 将元素跟之前排好序的比较，插入适当位置.
// 时间复杂度最好:O(n) 最坏:O(n^2) 平均:O(n^2) 
// 空间复杂度O(1) 
// 稳定性: 稳定
void insertSort(char array[], int n) {
	unsigned int j = 0;
	int target = 0;
	for (int i = 1; i != n; ++i) {
		target = array[i];									// store the original sorted array in temp
		for (j = i; j > 0 && target < array[j-1]; --j) {	// *** compare the new array with temp(maybe -1 ?)
			array[j] = array[j-1]	;						// all larger elements are moved one pot to the right
		}
		array[j] = target;									// put key into its proper location
		print(array, n);
	}
	return;
}

// 插入排序比较适合用于“少量元素的数组”。
// 插入排序的平均时间复杂度为 O(n^2)，最好的情况下为 O(n)，最坏情况为 O(n^2)。
template<typename T>
void insertSortDx(T arr[], int len) {
	int32_t j = 0;
	T temp;
	for (int32_t i = 1; i < len; ++i) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; --j) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

auto main(int, char**) -> int32_t {
	char array[] = {7, 3, 5, 2, 9, 1, 6, 4};
	printf("Before:\n");
	print(array, sizeof(array)/sizeof(array[0]));
	printf("Process:\n");
	insertSort(array, sizeof(array)/sizeof(char));
	//insertSortDx(array, sizeof(array)/sizeof(char));
	printf("After:\n");
	print(array, sizeof(array)/sizeof(array[0]));
	return EXIT_SUCCESS;
}
