/**
 * @file main.cpp
 * @Synopsis	Merge Sorted Array.
 *				Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *				Note: You may assume that A has enough space (size that is greater or equal 
 *				to m + n) to hold additional elements from B. The number of elements 
 *				initialized in A and B are m and n respectively.
 *
 *				因为A有足够的空间容纳A + B，我们使用游标i指向m + n - 1，也就是最大数值存放的
 *				地方，从后往前遍历A，B，谁大就放到i这里，同时递减i。
 *
 *				Merge two given sorted integer array A and B into a new sorted integer array.
 *				Example
 *				A=[1,2,3,4]
 *				B=[2,4,5,6]
 *				return [1,2,2,3,4,4,5,6]
 *				Challenge
 *				How can you optimize your algorithm if one array is very large and the other is very small?
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-08-30
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static std::vector<int32_t> merge(vector<int32_t>& A, vector<int32_t>& B) {
		// 自尾部向首部逐个比较两个数组内的元素，取较大的置于新数组尾部元素中。
		if (A.empty()) {
			return B;
		}

		if (B.empty()) {
			return A;
		}
		std::vector<int32_t>::size_type sizeoA = A.size();
		std::vector<int32_t>::size_type sizeoB = B.size();
		std::vector<int32_t>::size_type sizeoC = sizeoA + sizeoB;
		std::vector<int32_t> C(sizeoC);
		// 分三种情况遍历比较。实际上在能确定最后返回的数组时，只需要分两次遍历即可。
		// 最坏情况下需要遍历两个数组中所有元素，时间复杂度为 O(n). 空间复杂度 O(1).
		while (sizeoA > 0 && sizeoB > 0) {
			if (A[sizeoA - 1] > B[sizeoB - 1]) {
				C[--sizeoC] = A[--sizeoA];
			} else {
				C[--sizeoC] = B[--sizeoB];
			}
		}

		while (sizeoA > 0) {
			C[--sizeoC] = A[--sizeoA];
		}

		while (sizeoB > 0) {
			C[--sizeoC] = A[--sizeoB];
		}
		// 两个倒排列表，一个特别大，一个特别小，如何 Merge？此时应该考虑用一个二分法插入小的，即内存拷贝。
		return C;
	}
};

auto main(int32_t, char**) -> int32_t {
	std::vector<int32_t> A = {1, 2, 3, 4};
	std::vector<int32_t> B = {2, 4, 5, 6};
	std::vector<int32_t> C = Solution::merge(A, B);

	for (auto &iter : C) {
		std::cout << iter << ", ";
	}
	std::cout << std::endl;

	exit(EXIT_SUCCESS);
}

