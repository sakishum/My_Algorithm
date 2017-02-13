#include <iostream>
#include <algorithm>
#include <vector>

#define MAXLEN(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

// O(logN)
int bs(int arr[], int low, int high, int key) {
	int mid = 0;
	int result = -1;				// <-- 注意
	while (low < high) {
		mid = (low + high) / 2;		// <-- 注意
		if (arr[mid] > key) {
			high = mid - 1;
		} else if (arr[mid] < key) {
			low = mid + 1;
		} else {
			result = mid;
			break;					// <-- 注意
		}
	}
	return result;
}

void is(int arr[], int low, int high) {
	int tmp = 0;
	int j = 0;
	for (int i = low + 1; i != high; ++i) {
		tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; --j) {
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
	
}

class PrintElements {
public:
	void operator()(int elem) {
		cout << elem << ", ";
	}
};

union BLending {
	short s;
	char c[2];
};

int main(int argc, char *argv[]) {
	int arr[] = {5, 4, 7, 9, 1, 8, 2, 3, 6};
	vector<int> ivec1(arr, arr + 9);
	for_each(ivec1.begin(), ivec1.end(), PrintElements());
	cout << endl;
	is(arr, 0, 9);
	vector<int> ivec2(arr, arr + 9);
	for_each(ivec2.begin(), ivec2.end(), PrintElements());
	cout << endl;
	std::cout << "The pos of 3 is " << bs(arr, 0, MAXLEN(arr) - 1, 3) << std::endl;
	
	BLending bl;
	bl.s = 0x0102;
	std::cout << bl.s << std::endl;
	std::cout << static_cast<int>(bl.c[0]) << ", " <<  static_cast<int>(bl.c[1]) << std::endl;
	if (bl.c[0] == 0x02 && bl.c[1] == 0x01) {
		std::cout << "Little ending." << std::endl;
	}
	exit(EXIT_SUCCESS);
}