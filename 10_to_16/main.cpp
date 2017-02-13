#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iostream>

//进制转换，将一个 d 进制整数转化为 10 进制, d <= 16.
int32_t convert(const char data[64], int32_t d) {
	int32_t result = 0;
	int32_t one = 0;
	if (nullptr == data) {
		return result;
	}
	for (int i = 0; data[i] != '\0'; ++i) {
		if (data[i] >= '0' && data[i] <= '9') {
			one = data[i] - '0';		
		} else if (data[i] >= 'A' && data[i] <= 'F') {
			one = data[i] - 'A' + 10;
		} else if (data[i] >= 'a' && data[i] <= 'f') {
			one = data[i] - 'a' + 10;
		}
		result = result*d + one;
	}
	return result;
}

//一个超长字符串表示的十进制数（大于2^32)，转化为十六进制的字符串？
void cnv(const char src[], char dest[]) {
	if (nullptr == src || nullptr == dest) {
		return;
	}
	
	const char hextable[] = "0123456789ABCDEF";
	int i = 0;
	int one = 0;
	int data = 0;
	
	for (int32_t i = 0; src[i] != '\0'; ++i) {
		if (src[i] >= '0' && src[i] <= '9') {
			one = src[i] - '0';	
		}
		data = data*10 + one;
	} 

	//sprintf(dest, "0x%X", data);
	printf("i = %d\n", i);
	dest[i++] = '0';
	dest[i++] = 'x';
	while (data != 0) {
		dest[i++] = hextable[data%16];
		data /= 16;
	}
	dest[i] = '\0';
}

auto main(int, char**) -> int32_t {
	char hex[256] = {0} ;
	std::cout << "FF = " << convert("FF", 16) << std::endl;
	cnv("32", hex);
	std::cout << "hex = " << hex << std::endl;
	exit(EXIT_SUCCESS);
}

