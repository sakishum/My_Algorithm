/**
 * @file main.cpp
 * @Synopsis  输入一个表示十六进制的字符串，转换为十进制的整数输出。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-01-22
 */

#include <cstdio>
#include <cstdlib>

/**
 * @Synopsis  exchange0xTo10 
 *			  十六进制字符串转十进制整数
 *			  (注意需要考虑字符的大小写)
 *			  e.g.
 *			  0x4567=（（4*16+5）*16+6）*16+7
 * @Param str	十六进制字符串
 * @Param len	字符串长度
 *
 * @Returns   十进制整数
 */
int exchange0xTo10(char* str) {
	int data = 0;
	int temp = 0;
	/// 注意字符串最后为 '\0'
	for (size_t i = 0; str[i] != '\0'; ++i) {
		printf("%c\n", str[i]);
		if (str[i] >= 'a' && str[i] <= 'f') { 
			temp = str[i] - 'a' + 10;
		} else if (str[i] >= 'A' && str[i] <= 'F') {
			temp = str[i] - 'A' + 10;
		} else if (str[i] >= '0' && str[i] <= '9') {
			temp = str[i] - '0';
		} 
		data = data * 16 + temp;
	}
	return data;
}

int32_t hex2des(char a[]) {
	int32_t data = 0;
	int32_t one = 0;
	for (int32_t i = 0; a[i] != '\0'; ++i) {
		if (a[i] >= '0' && a[i] <= '9') {
			one = a[i] - '0';
		} else if (a[i] >= 'a' && a[i] <= 'f') {
			one = a[i] -'a' + 10;
		} else if (a[i] >= 'A' && a[i] <= 'F') {
			one = a[i] - 'A' + 10;
		}
		data = data * 16 + one;
	}
	return data;
}

int main(int, char**) {
	char num[] = "AA";
	printf("Result: %d\n", exchange0xTo10(num));
	printf("Result: %d\n", hex2des(num));
	return EXIT_SUCCESS;
}

