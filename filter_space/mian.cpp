#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void filterspace(char *str) {
	char *ptr = str;
	while (*str != '\0') {
		if (*str != ' ') {
			*ptr++ = *str;
		}
		++str;
	}
	*ptr = '\0';
}

int main(int, char**) {
	char str[] = "aabb cc dddd";
	printf("%s\n", str);
	filterspace(str);
	printf("%s\n", str);

	exit(EXIT_SUCCESS);
}

