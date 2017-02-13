#include <cstdlib>
#include <iostream>

// You could either initialize largest and second to an appropriate lower bound, 
// or to the first two items in the list(check which one is bigger, and don't forget
// to check if the list has least two items).
// O(n)

int find_second(int array[], int len) {
	if (!len || len == 1) {
		return -1;
	}

	int count = 0;
	int maxVal = array[0] > array[1] ? array[0] : array[1];
	int smaxVal = array[0] + array[1] - maxVal;

	for (int i = 2; i != len; ++i) {
		if (array[i] > maxVal) {
			smaxVal = maxVal;
			maxVal = array[i];
		} else if (array[i] < maxVal && array[i] > smaxVal) {
			smaxVal = array[i];
		}
		++count;
		std::cout << "large: " << maxVal << ", second: " << smaxVal << std::endl;
	}
	std::cout << "len: " << len << ", i: " << count << std::endl;
	return smaxVal;
}

int main(void) {
	int array[] = {4,2,5,3,8,6,9,1,0,7};
	//int array[] = {3};
	for (int i = 0; i != sizeof(array)/sizeof(array[0]); ++i) {
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "second largest element is " << find_second(array, sizeof(array)/sizeof(array[0])) << std::endl;
	return EXIT_SUCCESS;
}
