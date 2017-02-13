#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LEN(x) (sizeof(x)/sizeof(x[0]))

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int getPos(int arr[], int low, int high) {
	int key = arr[low];
	while (low < high) {
		while (low < high && arr[high] > key) {
			--high;
		}
		swap(&arr[low], &arr[high]);
		while (low < high && arr[low] < key) {
			++low;
		}
		swap(&arr[low], &arr[high]);
	}
	return low;
}

void qs(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int pos = getPos(arr, low, high);
	qs(arr, pos + 1, high);
	qs(arr, low, pos - 1);
}

// Functor
class PrintElemt {
public:
	void operator()(int &elemt) {
		std::cout << elemt << ", ";
	}
};

using namespace std;
int main(int argc, char *argv[]) {
	int arr[] = {3,9,2,8,1,5,6,7,4};
	qs(arr, 0, MAX_LEN(arr) - 1);
	std::cout << "max len:  " << MAX_LEN(arr) << std::endl;
	std::vector<int> ivec(arr, arr + MAX_LEN(arr));          // array => vector
	std::for_each(ivec.begin(), ivec.end(), PrintElemt());
	std::cout << std::endl;
}