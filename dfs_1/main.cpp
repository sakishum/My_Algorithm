#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#define MAXIN 10

int N = 0;

int history[MAXIN];
int count = 0;

void dfs(int i) {
	int j, k;
	if (i == N) {
		++count;
		for (j = 0; j < N; ++j) {
			printf("%d ", history[j]);
		}
		printf("\n");
	}

	for (k = i; k <= N; ++k) {
		int ok = 1;
		for (j = 0; j < i; ++j) {
			if (history[j] == k) {
				ok = 0;
			}
		}

		if (ok) {
			history[i] = k;
			dfs(i + 1);
		}
	}
}

auto main(int32_t argc, char* argv[]) -> int32_t {
	if (argc != 2) {
		exit(EXIT_FAILURE);
	} 
	dfs(atoi(argv[1]));
	exit(EXIT_SUCCESS);
}
