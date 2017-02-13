/**
 * @file main.cpp
 * @Synopsis  Given an index k, return the kth row of the Pascal's triangle.
 *			  For example, given k = 3, Return [1,3,3,1].
 *			  仅需要得到的第k层的集合，但只能使用O(k)的空间。所以不能用二维
 *			  数组的方式，只能使用一位数组滚动计算。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-08-29
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
	//  0  1  2  3  4
	// [1, 1, 1, 1, 1]
	// [1, 1, 1, 1, 1]
	// [1, 2, 1, 1, 1]
	// [1, 3, 3, 1, 1]
	// [1, 4, 6, 4, 1]	-> 1. A[3] = A[3] + A[2]
	//					-> 2. A[2] = A[2] + A[1]
	//					-> 3. A[1] = A[1] + A[0]
	static std::vector<int32_t> getRow(int32_t rowIndex) {
		std::vector<int32_t> vals;
		vals.resize(rowIndex + 1, 1);	// 
		for (int32_t i = 0; i < rowIndex + 1; ++i) {
			for (int32_t j = i - 1; j >= 1; --j) {
				vals[j] = vals[j] + vals[j - 1];
			}
			// print the process
			for (auto &iter : vals) {
				std::cout << iter << ", ";
			}
			std::cout << "<-- loop " << i << std::endl;
		}
		return vals;
    }
};  // class Solution

auto main(int, char**) -> int32_t {
	std::vector<int32_t> vals = Solution::getRow(4);
	std::cout << "result:" << std::endl;
	for (auto &iter : vals) {
		std::cout << iter << ", ";
	}
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}

