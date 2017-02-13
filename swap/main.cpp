/* Copyright(C)
 * For free
 * All right reserved
 */
/**
 * @file main.cpp
 * @Synopsis  Example for swap in CPP.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-04-19
 */

#include <cstdio>
#include <cstdlib>

void iswap(int &a, int &b) {
	int temp = a;
	a = b; 
	b = temp;
}

int main(void) {
	int a = 10;
	int b = 15;
	iswap(a, b);
	printf("a=%d, b=%d\n", a, b);
	return EXIT_SUCCESS;
}
