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
#include <vector>
#include <iostream>

// Insertion Sort Function for Ascending Order
void insertSort(char array[], unsigned int n) {
	unsigned int i = 0;
	unsigned int j = 0;
	int temp = 0;
	for (i = 1; i != n; ++i) {
		temp = array[i];								// store the original sorted array in temp
		for (j = i; j > 0 && temp < array[j-1]; --j) {	// *** compare the new array with temp(maybe -1 ?)
			array[j] = array[j-1]	;					// all larger elements are moved one pot to the right
		}
		array[j] = temp;								// put key into its proper location
		for (size_t z = 0; z != n; ++z) {
			printf("%d\t", array[z]);
		}
		printf("\n");
	}
	return;
}

template <typename T>
void insertSortVec(std::vector<T> &vec, int left, int right) {
	int j = 0;
	for (int i = left; i != right; ++i) {
		auto temp = vec[i];
		for (j = i; j > left && temp < vec[j-1]; --j) {
			vec[j] = vec[j-1];
		}
		vec[j] = temp;
	}
}

int main(void) {
	char array[] = {7, 3, 5, 2, 9, 1, 6, 4};
	printf("Before:\n");
	for (size_t i = 0; i != sizeof(array)/sizeof(char); ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
	printf("Process:\n");
	insertSort(array, sizeof(array)/sizeof(char));
	printf("After:\n");
	for (size_t i = 0; i != sizeof(array)/sizeof(char); ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");

	// 插入排序的 vector 模板实现
	std::vector<int> ivec = {7, 3, 5, 2, 9, 1, 6, 4};
	insertSortVec(ivec, 0, ivec.size());
	std::cout << "After insertSortVec:" << std::endl;
	for (int i : ivec) {
		std::cout << i << '\t';
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
