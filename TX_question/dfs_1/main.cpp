#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXIN 10
int N;
int count;
int history[MAXIN];

void dfs(int i) {
	int j, k;
	if (i == N) {
		count++;
		for (j = 0; j < N; ++j) {
			printf("%d ", history[j]);
		}
		printf("\n");
		return;
	}
	for (k = 1; k <= N; ++k) {
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

int main(void) {
	N = 123;
	dfs(0);
	exit(EXIT_SUCCESS);
}
