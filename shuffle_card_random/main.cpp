#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>

// 洗牌
int random_type(int start, int end, int seed) {
	std::vector<int> ivec;
	for (int i = start; i != end; ++i) {
		ivec.push_back(i);
	}
	std::srand(static_cast<unsigned int>(time(NULL) + seed));
	std::random_shuffle(ivec.begin(), ivec.end());
	return ivec.front();
}

int main(int, char**) {
	int seed = 10000;
	int card = random_type(0, 12, seed);
	std::cout << "card: " << card << std::endl;
	exit(EXIT_SUCCESS);
}
