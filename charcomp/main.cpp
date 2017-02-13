#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charcmp(const void *x, const void *y) {
	return (*(char*)x - *(char*)y);
}

#define WORDMAX 100

int main(void) {
	char word[WORDMAX] = {0};
	char sig[WORDMAX] = {0};

	while (scanf("%s", word) != EOF) {
		strcpy(sig, word);
		// 待排序数组，数组长度，每个待排序项的字节数以及比较两个项的函数名
		qsort(sig, strlen(sig), sizeof(char), charcmp);
		printf("%s %s\n", sig, word);
	}
	return EXIT_SUCCESS;
}
