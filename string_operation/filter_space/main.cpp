#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// 去除字符串内的空格，并把空格个数输出
int filterSpace(char *str) {
	char *p = str; 
	int count = 0;
	while (*str != '\0') {
		if (*str != ' ') {
			*p++ = *str;
		} else {
			++count;
		}
		++str;
	}
	return count;
}

int main(int, char**) {
	char arr[] = "AA BB CC";
	int count = filterSpace(arr);
	printf("counr = %d, src = %s\n", count, arr);
	exit(EXIT_SUCCESS);
}
