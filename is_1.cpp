#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#define MAXLEN(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

void isort(int arr[], int len) {
	int key = 0;
	int j = 0;
	for (int i = 1; i != len; ++i) {
		key = arr[i];
		for (j = i; j > 0 && arr[j - 1] > key; --j) {
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
}

// 排序后使用
// 时间复杂度为 O(log n) (n 代表集合中元素的个数)
int bs(int arr[], int low, int high, int key) {
	int mid = 0;
	int result = -1;
	while (low <= high) {
		mid = (low + high) / 2; 
		printf("mid : %d, arr[mid] : %d\n", mid, arr[mid]);
		if (arr[mid] > key) {
			high = mid - 1;
		} else if (arr[mid] < key) {
			low = mid + 1;
		} else {
			result = mid;
			break;
		}
	}
	return result;
}

class PrintElement {
public:
	void operator()(int elem) {
		std::cout << elem << ", ";		
	}
};

int main(int argc, char *argv[]) {
	int arr[] = {6, 8, 2, 4, 1, 5, 9, 3, 7};
	isort(arr, MAXLEN(arr));
	std::cout << bs(arr, 0, MAXLEN(arr) - 1, 4) << std::endl;
	std::vector<int> ivec(arr, arr + MAXLEN(arr));
	std::cout << "size of ivec : " << ivec.size() << std::endl;
	std::for_each(ivec.begin(), ivec.end(), PrintElement());
	exit(EXIT_SUCCESS);	
}