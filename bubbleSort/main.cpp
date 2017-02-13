#include <iostream>
#include "bubbleSort.h"
using namespace std;

/* Name: SK_BubbleSort
 * Desc: 冒泡排序算法(BubbleSort)的概念是:
 *		 依次相邻的两个数，将小的放在前面，大的放在后面。
 *		 可以修改升序，降序。
 *Input: 
 *		 int* r		需要排序的数组
 *		 int len	数组长度(length - 1)		
 *		 int start  排序起始位置
 */
void SK_BubbleSort(int*r, int len, int start) {
	int i, j, nTemp, exchange;
	for (i = start; i <= len -1; ++i) {
		exchange = 0;
		for (j = len - start; j >= i; --j)
		{
			if (r[j] > r[j-1])
			{
				nTemp = r[j];
				r[j] = r[j-1];
				r[j-1] = nTemp;
				exchange = 1;
			}
		}
	}
	if (exchange == 0) {
		return;
	}
}

int int_cmp(void* a, void* b) {
	return (int)a - (int)b;
}

int int_cmp_invert(void* a, void* b) {
	return (int)b - (int)a;
}

int main(void)
{	
	int i;
	int array[20] = {56, 12, 34, 86, 34, 51, 32, 16, 28, 63, 98, 46, 76, 1, 53, 36, 81, 35, 49, 40};
	int array_1[20] = {56, 12, 34, 86, 34, 51, 32, 16, 28, 63, 98, 46, 76, 1, 53, 36, 81, 35, 49, 40};

	SK_BubbleSort(array, sizeof(array)/sizeof(array[0])-1, 0);

	for (i = 0; i < 20; ++i)
	{
		cout<< array[i] << " "; 
	}
	cout<<"Next:"<<endl;
	bubble_sort((void**)array_1, sizeof(array_1), int_cmp_invert);	
	for (i = 0; i < 20; ++i)
	{
		cout<< array_1[i] << " "; 
	}
	cout<<endl;
	return 1;
}
