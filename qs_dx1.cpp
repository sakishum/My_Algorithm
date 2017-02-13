#include <iostream>
#include <algorithm>
#include <vector>

#define ARRLEN(x) (sizeof(x)/sizeof(x[0]))

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int getpos(int arr[], int low, int high) {
	int key = arr[low];
	std::cout << "key: " << key << std::endl;
	while (low < high) {
		while (low < high && arr[high] >= key) {
			--high;
		}
		swap(&arr[low], &arr[high]);
		while (low < high && arr[low] <= key) {
			++low;
		}
		swap(&arr[low], &arr[high]);
	}
	return low;
}

// Best  : O(nlogn)
// Avg   : O(nlogn)
// Worst : O(n^2)
void qs(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int pos = getpos(arr, low, high);
	std::cout << "pos: " << pos << std::endl;
	qs(arr, low, pos - 1);
	qs(arr, pos + 1, high);
}

class PrintElem {
public:
	// functor
	void operator()(int elem) {
		std::cout << elem << " "; 
	}
};

using namespace std;
int main(int argc, char *argv[]) {
	int arr[] = {7,3,5,1,6,9,8,4,2};
	std::cout << ARRLEN(arr) << std::endl;
	qs(arr, 0, ARRLEN(arr) - 1);
	std::vector<int> ivec(arr, arr + ARRLEN(arr));
	std::for_each(ivec.begin(), ivec.end(), PrintElem());
	exit(EXIT_SUCCESS);
}