/**
 * @file main.cpp
 * @Synopsis  将一个数组右移几位，比如数组为1 2 3 4，右移一位即为4 1 2 3 (时间复杂度为O(N))
 *			  在线性时间内实现右移操作, 原理： 转置矩阵
 *			  e.g. 假设原数组序列为abcd1234，要求变换成的数组序列为1234abcd，即循环右移了4位。
 *			  1、逆序排列abcd：abcd1234--->dcba1234；
 *			  2、逆序排列1234：dcba1234--->dcba4321；
 *			  3、全部逆序：	   dcba4321--->1234abcd。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-01-22
 */

#include <cstdio>
#include <cstdlib>

// 翻转数组
void reverse(int* pArr, int iBegin, int iEnd) {
	int iTemp = 0;
	for (; iBegin < iEnd; ++iBegin, --iEnd) {
		iTemp = pArr[iEnd];
		pArr[iEnd] = pArr[iBegin];
		pArr[iBegin] = iTemp;
	}
}

/**
 * @Synopsis  rightShift 
 *		右移数组N位。
 * @Param pArr		要操作的数组
 * @Param iLenth	数组长度
 * @Param iShift	右移次数
 */
void rightShift(int* pArr, int iLenth, int iShift) {
	printf("\nArrary length: %d, Right shift: %d\n", iLenth, iShift);
	iShift = iShift % iLenth;
	printf("shift: %d\n", iShift);
	reverse(pArr, 0, iLenth - iShift - 1);
	reverse(pArr, iLenth - iShift, iLenth - 1);
	reverse(pArr, 0, iLenth - 1);
}

void leftShift(int arr[], int len, int shift) {
	printf("\nArrary length: %d, Right shift: %d\n", len, shift);
	shift %= len;
	printf("shift: %d\n", shift);
	reverse(arr, 0, shift - 1);
	reverse(arr, shift, len - 1);
	reverse(arr, 0, len - 1);
}

void printArray(int* pArr, size_t nLen) {
	for (size_t i = 0; i != nLen; ++i) {
		printf("%d\t", pArr[i]);
	}
	printf("\n");
}

void reversearr(int32_t arr[], int32_t start, int32_t end) {
	int32_t temp = 0;
	for (int i = start, j = end; i < j; ++i, --j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int main(int, char**) {
	int arr[] = {5,6,7,8,1,2,3,4};
	size_t nSize = sizeof(arr)/sizeof(arr[0]);
	printf("start =============\n");
	printArray(arr, nSize);
	reversearr(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, nSize);
	printf("reverse=============\n");
	printArray(arr, nSize);
	rightShift(arr, nSize, 3);
	printArray(arr, nSize);
	leftShift(arr, nSize, 3);
	printArray(arr, nSize);
	printf("3 mod 8 = %d\n", (3 % 8));
	return EXIT_SUCCESS;
}
