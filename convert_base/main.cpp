#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

/**
 * @bbrief 进制转换，将一个 10 进制整数转化为 d 进制, d <= 16.
 * @param[in] n 整数 n
 * @param[in] d d 进制
 * @return 无
 */
void convert_base1(int n, const int d) {
	std::stack<int> s;
	int e = 0;

	while (n != 0) {
		e = n % d;
		s.push(e);
		n /= d;
	}

	while (!s.empty()) {
		e = s.top();
		s.pop();
		printf("%X", e);
	}
	printf("\n");
	return;
}

const int MAXN = 64; // 栈的最大长度
int stack[MAXN] = {0};
int top = -1;
/**
 * @bbrief 进制转换，将一个 10 进制整数转化为 d 进制, d <= 16.
 *
 * 如果是可以预估栈的最大空间，则用数组模拟栈，这是常用的技巧。
 * 这里，栈的最大长度是多少？假设 CPU 是 64 位，最大的整数则是
 * 2^64，由于数制最小是 2，在这个数制下，数的位数最长，这就是
 * 栈的最大长度，最长 64。
 *
 * @param[in] n 整数 n
 * @param[in] d d 进制
 * @return 无
 */
void convert_base2(int n, const int d) {
	int e = 0;
	while (n != 0) {
		e = n % d;
		stack[++top] = e;
		n /= d;
	}
	while (top >= 0) {
		e = stack[top--];
		printf("%X", e);
	}
	printf("\n");
}

/**
 * @bbrief 进制转换，将一个 d 进制整数转化为 10 进制, d <= 16.
 * @param[in] s d 进制整数
 * @param[in] d d 进制
 * @return 10 进制整数
 */
int restore(const char s[MAXN], const int d) {
	int result = 0;
	int one = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			one = s[i] - '0';	// 字符 0 的 ASCII 的值为 48
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			one = s[i] - 'A' + 10;
		} else {
			one = s[i] - 'a' + 10;
		}
		result = result * d + one;
	}
	return result;
}


int main(void) {
	convert_base1(12, 2);
	std::cout << std::string(30, '-') << std::endl;
	convert_base2(12, 2);
	std::cout << std::string(30, '-') << std::endl;
	printf("0x11 = %d\n", restore("11", 16));		// 17 

	exit(0);
}
