/**
 * @file main.cpp
 * @Synopsis  Count sort.
 *		T： O(n + k)
 *		S:  O(n + k)
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-06-08
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string.h>

void printElem(int a[], int len) {
	for (int i = 0; i != len; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// a 为输入数组，b 为输出数组，k 表示有所输入数字都介于 0 到 k 之间
void counttingSort(int a[], int len, int b[], int k) {
	int *c = new int[k];
	memset(c, 0, k*sizeof(int));
	// 检查每个输入元素，如果一个输入元素的值为a[i],那么c[a[i]]的值加1，此操作完成后，c[i]中存放了值为i的元素的个数  
	for (int i = 0; i != len; ++i) {
		++c[a[i]];
	}
	printElem(c, k);
	// 通过在c中记录计数和，c[i]中存放的是小于等于i元素的数字个数 
	for (int i = 1; i != k; ++i) {
		c[i] += c[i - 1];
	}
	printElem(c, k);
	// 把输入数组中的元素放在输出数组中对应的位置上  
	// 从后往前遍历 
	for (int i = len - 1; i >= 0; --i) {
		b[c[a[i]] - 1] = a[i];
		--c[a[i]];	// 该操作使得下一个值为input[i]的元素直接进入输出数组中input[i]的前一个位
	}
	delete [] c;
}

// 算法导论（二），第八章
#define LEN 8
int main(void) {
	int a[LEN] = {2, 5, 3, 0, 2, 3, 0, 3};
	int b[LEN] = {0};
	counttingSort(a, LEN, b, 9);	// O(k + n), 稳定的
	for (int i = 0; i != LEN; ++i) {
		printf("%d ", b[i]);
	}
	return EXIT_SUCCESS;
}
