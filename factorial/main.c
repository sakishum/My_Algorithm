/**
 * @file main.c
 * @Synopsis  Example for factorial by recursion in C.
 *		许多问题是以递归的形式进行解释的，这只是因为它比非递归形式更为清晰。
 *		但是，这些问题的迭代实现往往比递归实现效率更高，虽然代码的可读性可能
 *		稍差一些。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-04-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long factorial(int n) {
	if (n <= 0) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

// (tail recursion) 尾递归
long long factorial_recursion(int n) {
	long long result = 1;
	while (n > 1) {
		result *= n;
		n -= 1;
	}
	return result;
}

#define TARGET 20
int main(void) {
	clock_t start, finish;
	double  duration;
	long long result = 0;
	start = clock();
	result = factorial(TARGET);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );	// 0.000003 seconds
	printf("result = %lld\n", result);

	start = clock();
	result = factorial_recursion(TARGET);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration ); // 0.000001 seconds
	printf("result = %lld\n", result);
	return EXIT_SUCCESS;
}
