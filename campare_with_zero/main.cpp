#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <complex>		// std::abs 
#include <limits>		// std::numberic_limits

template<typename T>
bool is_zero(T num) {
	return std::abs(num) <= std::numeric_limits<T>::epsilon();
}

int main(int, char**) {
	int32_t a = 0;
	int64_t b = 0;
	float c = 0.0f;
	double d = 0.00001;
	if (is_zero(a)) { std::cout << "int32_t is zero." << std::endl; }
	if (is_zero(b)) { std::cout << "int64_t is zero." << std::endl; }
	if (is_zero(c)) { std::cout << "float is zero." << std::endl; }
	if (is_zero(d)) { std::cout << "double is zero." << std::endl; }
	exit(EXIT_SUCCESS);
}
