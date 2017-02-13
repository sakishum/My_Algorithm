#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

typedef std::vector<int32_t> apvector;

// Insertion Sort Function for Descending Order
void insertionSort(apvector &num) {
	int32_t key;
	// j 不可以为 unsigned int ，因为会永远 j >= 0 
	int32_t j = 0, numlen = num.size();
	for (int32_t i = 1; i != numlen; ++i) {
		key = num[i];
		for (j = i - 1; j >= 0 && num[j] < key; --j) {
			std::cout << "j:" << j << ", num[j+1]: " << num[j+1] << ", num[j]: " << num[j] << std::endl;
			num[j+1] = num[j];	
		}
		num[j+1] = key;
		for (int32_t value : num) {
			std::cout << value << "\t";
		}
		std::cout << std::endl;
	}
	return;
}

int main(void) {
	apvector avc = {7, 3, 5, 2, 9, 1, 6, 4};
	insertionSort(avc);
	for (int32_t value : avc) {
		std::cout << value << "\t";
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
