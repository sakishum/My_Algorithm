#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define TEST 8

// 判断 num 是否是 2 的幂
bool ispow(int num) {
	bool ret = false;
	if ((num & (num-1)) == 0) {
		ret = true;
	}
	return ret;
}

int main(int, char**) {
	if (ispow(TEST)) {
		printf("Enter.\n");
	}
	exit(EXIT_SUCCESS);
}
