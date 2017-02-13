/*
 * Given a sorted array, remove the duplicates in place such that > each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 * */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

class Solution {
public:
	static int removeDuplicates(int A[], int n) {
		if (0 == n) {
			return 0;
		}
		
		int j = 0;
		for (int i = 1; i != n; ++i) {
			// 去除重复的元素
			if (A[j] != A[i]) {
				A[++j] = A[i];
			}
		}

		return ++j;
	}
};

auto main(int, char**) -> int32_t {
	int a[] = {1, 1, 2, 3};
	// 不额外申请空间，数组长度不会改变。
	int size = Solution::removeDuplicates(a, sizeof(a)/sizeof(a[0]));
	std::cout << "result: " << size << std::endl;
	for (int i = 0; i != size; ++i) {
		std::cout << a[i] << std::endl;
	}
	exit(EXIT_SUCCESS);
}

