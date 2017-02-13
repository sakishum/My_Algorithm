#include <stdio.h>
#include <stdlib.h>

// 有/无符号整型
int getAllOne(char data) {
	char a = 0x1;
	int count = 0;
	for (int i = 0; i != 8; ++i) {
		if (((data >> i) & a) == 1) {
			++count;
		}
	}
	return count;
}

// 只针对无符号整型
int getAllOneDx(char data) {
	unsigned char count  = 0;
	while (data > 0) {
		++count;
		data = data & (data - 1);
	}
	return count;
}

int getBit(long int a) {
	int count = 0;
	while (a>0) {
		a >>= 1;
		++count;
	}
	return count;
}

bool isPowerOfTwo(long int a) {
	bool ret = false;
	if ((a & (a-1)) == 0) {
		ret = true;
	}
	return ret;
}

int main(int, char**) {
	//  7 : 0000 0111
	// -7 : 1111 1001
	// -7 + 3:
	//  1111 1001
	// +0000 0011
	// ------------
	//  1111 1100
	// >1000 0011  +  1
	//  1000 0100 => -4
	//char data = 0x7;
	char data = 7;
	//int count = getAllOne(data);
	int count = getAllOneDx(data);
	printf("result = %d\n", count);
	printf("ret = %d\n", getBit(256));	// 9 位
	// 求是否是2的幂
	if (isPowerOfTwo(16)) {
		printf("Is Power Of 2.\n");
	}
	exit(EXIT_SUCCESS);
}

