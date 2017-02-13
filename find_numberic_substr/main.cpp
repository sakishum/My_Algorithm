#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int getNumbericSubstr(char *dest, const char *src) {
	int count = 0;
	int max = 0;
	const char *ptr = NULL;
	while (*src!='\0') {
		if (*src >= '0' && *src <= '9') {
			++count;
		} else {
			if (count > max) {
				max = count;
				ptr = src - max;
			}
			count = 0;
		}
		++src;
	}

	dest[max] = '\0';
	for (int i = 0; i != max; ++i) {
		*dest = *ptr;
		++dest;
		++ptr;
	}
	return max;
}

int main(int, char**) {
	char str[] = "abcd12345ed125ss123456789a";
	char num[100] = {0};
	printf("result = %d\n",getNumbericSubstr(num, str));
	printf("num : %s\n", num);
	exit(EXIT_SUCCESS);
}

