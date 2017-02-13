#include <cstdlib>
#include <iostream>

// You could either initialize largest and second to an appropriate lower bound, 
// or to the first two items in the list(check which one is bigger, and don't forget
// to check if the list has least two items).
// O(n)

int find_second(int array[], int len) {
	if (len <= 0) {
		return -1;
	}
	if (len < 2) {
		return array[0];
	}
	int large = 0;
	int second = 0;
	int count = 0;
	// O(n)
	for (int i = 0; i != len; ++i) {
		if (array[i] > large) {
			second = large;
			large = array[i];
		} else if(array[i] > second) {
			second = array[i];
		}
		std::cout << "large: " << large << ", second: " << second << std::endl;
		++count;
	}
	std::cout << "len: " << len << ", i: " << count << std::endl;
	return second;
}

int main(void) {
	int array[] = {4,2,5,3,8,6,9,1,0,7};
	//int array[] = {3};
	std::cout << "second largest element is " << find_second(array, sizeof(array)/sizeof(array[0])) << std::endl;
	return EXIT_SUCCESS;
}
