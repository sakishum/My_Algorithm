#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iostream>
// 200 位的正整数相加
#define BIGINT_RADIX 10000 // 10^4
#define REDIX_LEN 4
#define MAX_LEN (200/REDIX_LEN+1)

char a[MAX_LEN * REDIX_LEN], b[MAX_LEN * REDIX_LEN];
int32_t x[MAX_LEN], y[MAX_LEN], z[MAX_LEN];

void bigint_print(const int32_t x[], int32_t len) {
	bool start_output = false;
	for (int32_t i = len - 1; i >= 0; --i) {
		if (start_output) {
			printf("%04d", x[i]);
		} else if (x[i] > 0) {
			printf("%d", x[i]);
			start_output = true;
		}
	}
	if (!start_output) {
		printf("0");
	}
}

void bigint_input(const char s[], int32_t x[]) {
	const int32_t len = strlen(s);
	printf("len = %d\n", len);
	for (int32_t i = 0; i != MAX_LEN; ++i) {
		x[i] = 0;
	}

	int32_t k = 0;
	for (int i = len; i > 0; i -= REDIX_LEN) {
		int32_t one = 0;
		const int32_t low = i - REDIX_LEN > 0 ? i - REDIX_LEN : 0;

		printf("low = %d\n", low);
		for (int32_t j = low; j < i; ++j) {
			one = one * 10 + s[j] - '0';
		}
		printf("one = %d\n", one);
		printf("k = %d\n", k);
		x[k++] = one;
	}
}

void bigint_add(const int32_t x[], const int32_t y[], int32_t z[]) {
	for (int32_t i = 0; i != MAX_LEN; ++i) {
		z[i] = 0;
	}

	for (int32_t i = 0; i != MAX_LEN; ++i) {
		z[i] += x[i] + y[i];
		if (z[i] >= BIGINT_RADIX) {
			z[i] -= BIGINT_RADIX;
			z[i + 1] ++;
		}
	}
}

#define PRINT(num) printf("%d", x[num]);
int32_t main(int32_t, char**) {
	strncpy(a, "2227222", strlen("2227222"));
	strncpy(b, "3333433", strlen("3333433"));
	printf("MAX_LEN = %d\n", MAX_LEN);
	bigint_input(a, x);
	bigint_input(b, y);
	bigint_add(x, y, z);
	for (int i = MAX_LEN -1; i >= 0; --i) {
		printf("%d, ", x[i]);
	}
	printf("\n");
	for (int i = MAX_LEN -1; i >= 0; --i) {
		printf("%d, ", y[i]);
	}
	printf("\n");
	for (int i = MAX_LEN -1; i >= 0; --i) {
		printf("%d, ", z[i]);
	}
	printf("\n");
	bigint_print(z, MAX_LEN);
	exit(EXIT_SUCCESS);
}

