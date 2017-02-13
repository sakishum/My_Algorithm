/* Copyright(C)
 * For free
 * All right reserved
 */
/**
 * @file main.cpp
 * @Synopsis  Example for log2 in C/CPP.
 *		http://www.matrix67.com/blog/archives/3985
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-08-20
 */

#include <ctype.h>//调用atoi函数 
#include <cstdio>
#include <cstdlib>

/*
 * 其用来计算一个32位整数右边连续的0有多少个
 * 最牛逼的就是它用的那个整数0x077CB531U
 * 展开成2进制后比较牛逼
 * */

#define Uint32 unsigned int

static const int debruijn[32] = {
0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};

//  v & -v 的作用就是取出右起连续的 0 以及首次出现的 1, 当 v = 123 456 时， 
//  v & -v 就等于 64 ，即二进制的 1000000, 0x077CB531 本身的一个性质开始说起。
//  把这个常数写成 32 位二进制，可以得到 00000111011111001011010100110001,
//  这个 01 串有一个无比牛 B 的地方：如果把它看作是循环的，它正好包含了全部 
//  32 种可能的 5 位 01 串，既无重复，又无遗漏！
#define LOG2(X) (debruijn[((Uint32)(((X) & -(X)) * 0x077CB531U)) >> 27])

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Please input a number.\n");
		return EXIT_FAILURE;
	}
	int num = atoi(argv[1]);
	printf("%d\n", LOG2(num));
	return EXIT_SUCCESS;
}


