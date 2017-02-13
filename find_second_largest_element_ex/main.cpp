#include <cstdlib>
#include <iostream>

// You could either initialize largest and second to an appropriate lower bound, 
// or to the first two items in the list(check which one is bigger, and don't forget
// to check if the list has least two items).
// O(n)

int find_second(int arr[], int len) {
	if (len <= 0) {
		return -1;
	}
	int max = arr[0] > arr[1] ? arr[0] : arr[1];
	int second = arr[0] + arr[1] - max;
	for (int i = 2; i != len; ++i) {
		if (arr[i] > max) {
			second = max;
			max = arr[i];
		// 排除元素小于最大而大于当前第二打的情况。
		} else if (max > arr[i] && second < arr[i]) {
			second = arr[i];
		}
	}
	return second;
}

int main(void) {
	int array[] = {4, 2, 3, 0};
	std::cout << "second largest element is " << find_second(array, sizeof(array)/sizeof(array[0])) << std::endl;
	return EXIT_SUCCESS;
}
