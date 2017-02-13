#include <cstdio>
#include <cstdlib>
//     X  Y
// A: 123 45
// A = XY 
// (XY)T = YTXT
// -> YX

// 这种方法需要对每个位置写入两次
void revese(int arr[], int start, int end) {
	int temp;
	for (int i = start, j = end - 1; i < j; ++i, --j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void ror(int arr[], int len, int k) {
	k = k % len;
	if (k == 0) {
		return;
	}

	revese(arr, 0, len);
	printf("1\n");
	for (int i = 0; i != len; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	revese(arr, 0, k);
	printf("2\n");
	for (int i = 0; i != len; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	revese(arr, k, len);
	printf("3\n");
	for (int i = 0; i != len; ++i)
		printf("%d, ", arr[i]);
	printf("\n");
}

int main(int, char**) {
	int arr[] = {1,2,3,4,5};
	const int k = 3;
	for (int i = 0; i != sizeof(arr)/sizeof(arr[0]); ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	ror(arr,  sizeof(arr)/sizeof(arr[0]), k);
	printf("After:\n");
	for (int i = 0; i != sizeof(arr)/sizeof(arr[0]); ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
