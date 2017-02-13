#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAXLEN(x) (sizeof(x)/sizeof(x[0]))
using namespace std;

template<typename T>
void myswap(T *a, T *b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

int getpos(int arr[], int low, int high) {
	int key = arr[low];
	while (low < high) {
		while (low < high && arr[high] > key) {
			--high;
		}
		myswap<int>(&arr[low], &arr[high]);
		while (low < high && arr[low] < key) {
			++low;
		}
		myswap<int>(&arr[low], &arr[high]);
	}
	return low;
}

// quick sort O(nlogn)
void qs(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int pos = getpos(arr, low, high);
	qs(arr, low, pos - 1);
	qs(arr, pos + 1, high);
}

// insert sort O(n^2)
void is(int arr[], int low, int high) {
	int key = 0;
	int j = 0;
	for (int i = low; i <= high; ++i) {
		key = arr[i];
		for (j = i; j > 0 && arr[j - 1] > key; --j) {
			arr[j] = arr[j - 1];
		}
		arr[j] = key;
	}
}

// binary search O(logn)
int binarysearch(int arr[], int low, int high, int key) {
	int result = -1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		//printf("mid: %d\n", mid);
		if (arr[mid] > key) {
			high = mid - 1;
		} else if(arr[mid] < key) {
			low = mid + 1;
		} else {
			result = mid;
			break;
		}
	}
	return result;
}

// Functor
template<typename T>
class Elements {
public:
	void operator() (T &elem) {
		cout << elem << " ";
	}
};

int main(int argc, char *argv[]) {
	int arr[] = {4, 6, 1, 3, 8, 5, 2, 9, 7};
	vector<int> ivec(arr, arr + MAXLEN(arr));
	for_each(ivec.begin(), ivec.end(), Elements<int>());
	std::cout << std::endl;
	cout << "After:" << std::endl;
	is(arr, 0, MAXLEN(arr) - 1);
	vector<int> ivec1(arr, arr + MAXLEN(arr));
	for_each(ivec1.begin(), ivec1.end(), Elements<int>());
	std::cout << std::endl;
	int ret = binarysearch(arr, 0, MAXLEN(arr) - 1, 3);
	cout << "result: " << ret << std::endl;
	exit(EXIT_SUCCESS);	
}