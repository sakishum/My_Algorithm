/**
 * @file main.cpp
 * @Synopsis  Given a non-negative number represented as an array of digits, plus one to the number.
 *			  The digits are stored such that the most significant digit is at the head of the list.
 *			  加法进位问题.
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
	static std::vector<int32_t> plusOne(std::vector<int32_t> &digits) {
		std::vector<int32_t> res(digits.size(), 0);
		int32_t sum = 0;
		int32_t one = 1;
		for (int32_t i = digits.size() - 1; i >= 0; --i) {
			sum = one + digits[i];
			one = sum / 10;
			res[i] = sum % 10;
		}

		if (one > 0) {
			res.insert(res.begin(), one);
		}
		return res;
	}
};

auto main(int, char**) -> int32_t {
	std::vector<int32_t> digits = {1, 5, 6, 9, 9, 9};
	for (auto &iter : digits) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;

	std::vector<int32_t> res = Solution::plusOne(digits);
	for (auto &iter : res) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}
