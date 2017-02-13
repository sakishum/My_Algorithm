/**
 * @file main.cpp
 * @Synopsis  Example for binary search in CPP.
 *	折半搜索每次把搜索区域减少一半，时间复杂度为O(log n)。（log 底数为2, n代表集合中元素的个数）
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-07-09
 */

#include <iostream>
#include "./binary_search.h"

/*
 *	搜素过程从数组的中间元素开始，如果中间元素正好是要查找的元素，则搜素过程结束；
 *	如果某一特定元素大于或者小于中间元素，则在数组大于或小于中间元素的那一半中查找，
 *	而且跟开始一样从中间元素开始比较。如果在某一步骤数组为空，则代表找不到。
 *	这种搜索算法每一次比较都使搜索范围缩小一半。
 *
 *	时间复杂度:
 *		二分查找（折半查找）每次吧搜索范围减少一半，时间复杂度为O(log n)。(n代表集合中元素的个数)
 *	空间复杂度：
 *		O(1)。
 * */

/// 递归版本的二分查找
int binary_search(const int arr[], int low, int high, int key) {
	/// 不能随便使用(low+high)>>1, 因为这样的话low 与high 的值比较大的时候，其和可能溢出。
	int mid = (low + high) / 2;
	printf("mid = %d\n", mid);
	if (low > high) {
		return -1;
	} else {
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			return binary_search(arr, low, mid-1, key);
		} else {
			return binary_search(arr, low+1, high, key);
		}
	}
}

// 递归版本
int bs_diy(int arr[], int low, int high, int key) {
	int mid = (low + high)/2;
	if (low > high) {
		return -1;
	} else {
		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			return bs_diy(arr, low, mid -1, key);
		} else {
			return bs_diy(arr, mid + 1, high, key);
		}
	}
}

// 非递归版本
int bs_nr(int arr[], int low, int high, int key) {
	int result = -1;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;
		if (arr[mid] > key) {
			high = mid - 1;
		} else if (arr[mid] < key) {
			low = mid +1;
		} else {
			result = mid;
			break;
		}
	} 
	return result;
}

int main(void) {
	int array[21] = {2, 12, 34, 56, 71, 77, 84, 86, 87, 94, 98,
					102, 112, 142, 156, 174, 183, 196, 199, 201, 226};
	// 递归版本
	std::cout << "binary_search: " << binary_search(array, 0, sizeof(array)/sizeof(array[0]), 87) << std::endl;
	// 不是用递归的模板版本
	std::cout << "binary_search_t<int>: " << binary_search_t<int>(array, 0, sizeof(array)/sizeof(array[0]), 87) << std::endl;

	std::cout << "bs_diy: " << bs_diy(array, 0, sizeof(array)/sizeof(array[0]), 87) << std::endl;
	std::cout << "bs_nr: " << bs_nr(array, 0, sizeof(array)/sizeof(array[0]), 87) << std::endl;
	return 0;
}

