/**
 * @file main.cpp
 * @Synopsis   归并操作(merge)，也叫归并算法，指的是将两个已经
 *			   排序的序列合并成一个序列的操作。
 *			   分治法（divide and conquer）
 *			   实际应用:
 *			   问如何高效率将两个链表合并，并使之有序。
 *			   时间复杂度：O(nlogn)
 *			   空间复杂度：O(n)
 *			   稳定性：稳定
 *		速度仅次于 快速排序，为稳定的算法，一般用于对总体无序，
 *		但是各子项相对有序的数列。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-06-04
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

void print(int a[], int len) {
	for (int i = 0; i != len; ++i) {
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
}

void merge_array(int a[], int first, int mid, int last, int c[]) {
	int i = first, j = mid + 1, k = 0;
	// 元素排序，左右比较
	while (i <= mid && j <= last) {
		// 左元素小于右元素
		if (a[i] > a[j]) {
			// 将较小的赋值到结果
			c[k++] = a[j++];
		} else { // 左元素大于等于右元素
			// 将较小的赋值到结果
			c[k++] = a[i++];
		}
	}
	// 将最后一个元素赋值到结果
	while (i <= mid) {
		c[k++] = a[i++];
	}
	// 将最后一个元素赋值到结果
	while (j <= last) {
		c[k++] = a[j++];
	}
	for (int x = 0; x < k; ++x) {
		a[first + x] = c[x];
	}
	print(c, 7);
}

void merge_sort(int a[], int first, int last, int temp[]) {
	if (first < last) {
		// 取中间值
		int mid = (first + last)/2;
		// 递归拆分左数组
		merge_sort(a, first, mid, temp);
		// 递归拆分右数组
		merge_sort(a, mid+1, last, temp);
		// 排序并组合
		merge_array(a, first, mid, last, temp);
	}
}

int main(void) {
	int a[] = {6, 202, 100, 301, 38, 8, 1};
	int temp[7] = {0};
	std::cout << "Before:" << std::endl;
	print(a, sizeof(a)/sizeof(a[0]));
	merge_sort(a, 0, sizeof(a)/sizeof(a[0]) - 1, temp);
	std::cout << "After:" << std::endl;
	print(a, sizeof(a)/sizeof(a[0]));
	return EXIT_SUCCESS;
}
