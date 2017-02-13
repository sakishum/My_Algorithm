#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>

void reuerse(void) {
	char ch;
	std::cin.get(ch);
	if (ch != '\n') {
		reuerse();
		std::cout.put(ch);
	}
}

void recuerse_dx(void) {
	char ch;
	std::cin.get(ch);
	if (ch != '\n') {
		recuerse_dx();
	}
	std::cout.put(ch);
}

void recuerse_ex(void) {
	static char ch;
	std::cin.get(ch);
	if (ch != '\n') {
		recuerse_ex();
	}
	std::cout.put(ch);
}

int32_t main(int32_t, char**) {
	//reuerse();
	//recuerse_dx();
	recuerse_ex();
	exit(EXIT_SUCCESS);
}
