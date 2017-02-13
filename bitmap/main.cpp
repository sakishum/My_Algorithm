/**
 * @file main.cpp
 * @Synopsis  i
 *	URL: http://blog.csdn.net/hackerwin7/article/details/17585257
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-09-19
 */
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int32_t a[1 + N/BITSPERWORD] = {0};
// set 设置所在的 bit 位位 1
// clr 初始化所有的 bit 位为 0
// test 测试所在的 bit 是否为 1

void set(int32_t i) {
	a[i>>SHIFT] |= (1<<(i & MASK));
}

void clr(int32_t i) {
	a[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int32_t i) {
	int ret = (a[i>>SHIFT] & (1<<(i & MASK)));
	if (ret) {
		printf("%X, %X, %d\n", a[i>>SHIFT], (1<<(i & MASK)), ret);
	}
	return ret;
}

auto main(int, char**) -> int32_t {
	int32_t i = 0;
	for (i = 0; i != N; ++i) {
		clr(i);
	}

	while (scanf("%d", &i) != EOF) {
		set(i);
	}

	for (i = 0; i != N; ++i) {
		if (test(i)) {
			printf("%d\n", i);
		}
	}
	exit(EXIT_SUCCESS);
}
