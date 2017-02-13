/**
 * @file main.c
 * @Synopsis  Example for fibonacci by recursion in C.
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

long long fibonacci(int n) {
	if (n <= 2) {
		return 1;
	} 
	return fibonacci(n -1)  + fibonacci(n - 2);
}

// (tail recursion) 尾递归
long long fibonacci_recursion(int n) {
	long long result = 0;
	long long previous_result = 0;
	long long next_older_result = 0;
	result = previous_result = 1;

	while (n > 2) {
		n -= 1;
		next_older_result = previous_result;
		previous_result = result;
		result = previous_result + next_older_result;
	}
	return result;
}

#define TARGET 30
int main(void) {
	clock_t start, finish;
	double  duration;
	long long result = 0;
	start = clock();
	result = fibonacci(TARGET);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );	// 0.009642 seconds
	printf("result = %lld\n", result);

	start = clock();
	result = fibonacci_recursion(TARGET);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration ); // 0.000001 seconds
	printf("result = %lld\n", result);
	return EXIT_SUCCESS;
}
