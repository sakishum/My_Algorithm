/**
 * @file main.c
 * @Synopsis  Example for bit vector in C.
 *	url: http://www.cnblogs.com/wuyuegb2312/p/3136831.html
 *	位向量的实现方法大体是：多个位组成一个基本数据类型，基本数据类型组合成数组。
 *	i>>SHIFT指的是右移5位，也就是除以32，指的是该位存在于那个数组中
 *	i&MASK指的是i%32，剩下的数字为多少，1<<(i&MASK))表示1左移i&MASK位
 *	简介：
 *	位向量/位图是一个很有用的数据结构，在充分利用小空间存储大量数据方面非常具有优势，
 *	Linux内核中很多地方都是用了位图。同时，它不但基础，而且用到了很多编程语言的知识，
 *	以及对细节的把握，常常作为面试题出现。这里将要介绍它的实现、操作、应用。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-04-21
 */

#include <stdio.h>
#include <stdlib.h>

#define BITSPERWORD 32		// 一个整数包含的位数，Int为32位
#define SHIFT 5				// 位移（单次）
#define MASK 0x1f			// 2^5-1，用来取余数(掩码)
#define N 10000000
int a[1 + N/BITSPERWORD];	// 数组大小  

/*注意：(1<<(i&MASK))使用掩码留下i的低5位再左移动1位，相当于2向左移动除以32所得的余数。*/
/*因为第一是0，所以结果都需要左移动1位。结果中1所在的位表示i在该int数组成员的第几位上。*/

// 对于每个位的操作，有三种：设置为1、设置为0、读取当前值
/*功能：设置位数组中的从0开始的第i位为1*/
void set(int i) {
	/*将int型变量a的第(i&MASK)位置1*/
	a[i>>SHIFT] |= (1<<(i&MASK));
}

/*功能：设置位数组中的从0开始的第i位为0*/
void clr(int i) {
	/*将int型变量a的第(i&MASK)位清0*/
	a[i>>SHIFT] &= ~(1<<(i&MASK));
}

/*功能：取出从0开始的第i位的值，用于检测*/
int test(int i) {
	return a[i>>SHIFT] & (1<<(i&MASK));
}

/*使用位向量前对所有位进行初始化(复位)*/
void allclr(void) {
	int temp = N/BITSPERWORD + 1;
	size_t i = 0;
	for (i = 0; i < temp; ++i) {
		a[i] = 0;
	}
}

int main(void) {
	int i = 35;
	allclr();
	set(i);
	/*需要左移的位数*/
	printf("i>>SHIFT = %d\n", i>>SHIFT);	// 1
	printf("1<<(i&MASK) = %d\n", 1<<(i&MASK));	// 2^3 = 8
	printf("(i&MASK) = %d\n", (i&MASK));	// 3
	printf("a[1] = %d\n", a[1]);			// 8 : 0000 0000 0000 0000 0000 0000 0000 1000b
	printf("result = %d\n", test(i));		// 8
	// a[1] : 0000 1000  意思就是 a[1] 第3位为1，a[1] 表示32 ~ 64, 第3位即32 + 3 = 35
	return EXIT_SUCCESS;
}
