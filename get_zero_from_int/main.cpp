#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

int32_t getZero(int32_t num) {
	int32_t temp = 0;
	while (num != 0) {
		if (num%10 == 0) {
			temp += 1;
		} 
		num /= 10;
	}
	return temp;
}

int main(int, char**) {
	int32_t integer = 10000020;
	std::cout << "Count : " << getZero(integer) << std::endl;
	exit(EXIT_SUCCESS);
}
