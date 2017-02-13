/**
 * @file main.cpp
 * @Synopsis  Example for quicksort in CPP by Jon Bentley.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-01-08
 */

#include <cstdlib>
#include <cstdio>
#include <algorithm>    // std::swap
#include <ctime>  
#include <cmath>
#include <iostream>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 实现randint(l,a)，返回[l,a]范围内的一个随机整数  
int randint(int l,int a) {  
  int temp;  
  srand((unsigned)time(NULL));  
  temp = floor(l + (1.0*rand()/RAND_MAX)*(a - l + 1 ));  
  return temp;  
}  

void print(int a[], int n) {
	for (int i = 0; i != n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int partition(int a[], int low, int high) {
	int privotKey = a[low];				// 基准排序
	while (low < high) {				// 从表的两端交替地向中间扫描
		// 从 high 所指的位置向前搜索，至多到 low -1 位置。将比基准元素小的交换到低端
		while (low < high && a[high] >= privotKey) {
			--high;
		}
		swap(&a[low], &a[high]);
		while (low < high && a[low] <= privotKey) {
			++low;
		}
		swap(&a[low], &a[high]);
	}
	print(a, 8);
	std::cout << a[low] << std::endl;
	return low;
}

// QuickSort 的递归实现
// 空间复杂度 O(log2n)
// 平均时间复杂度 O(nlog2n)，最坏(不当的 pivot 选择)时间复杂度 O(n^2)， 怎样证明？
void quicksort(int l, int h, int a[]) {
	// 注意这一句:
	if (l >= h) {
		return;
	}
	int privotLoc = partition(a, l, h);	// 将表一分为二
	quicksort(l, privotLoc-1, a);		// 递归对低子表递归排序
	quicksort(privotLoc+1, h, a);		// 递归对高子表递归排序
}

// 堆排序与快速排序的平均时间复杂度都是 O(NlogN), 但就平均表现而言
// 堆排序却比快速排序慢了 2~5 倍。但堆排序有一点却比快速排序要好很
// 多：最坏情况下它的复杂度仍然会保持 O(NlogN)。

int main(void) {
	int array[8] = {49, 38, 65, 97, 76, 13, 27, 52};
	print(array, 8);
	std::cout << "开始" << std::endl;
	quicksort(0, sizeof(array)/sizeof(array[0])-1, array);
	std::cout << "结束" << std::endl;
	print(array, 8);
	return EXIT_SUCCESS;
}

