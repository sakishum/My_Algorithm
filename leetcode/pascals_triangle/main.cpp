/**
 * @file main.cpp
 * @Synopsis  Given numRows, generate the first numRows of Pascal's triangle.
 *			  For example, given numRows = 5, Return'
 *			  [
 *			        [1],
 *			       [1,1],
 *			      [1,2,1],
 *			     [1,3,3,1],
 *			    [1,4,6,4,1]
 *			  ]
 *			  计算帕斯卡三角。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-08-29
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vals;
        vals.resize(numRows);

        for (int i = 0; i != numRows; ++i) {
            vals[i].resize(i + 1);				// 第k层有k个元素
            vals[i][0] = 1;						// 每层第一个以及最后一个元素值为1
            vals[i][vals[i].size() - 1] = 1;	
			// 对于第k（k > 2）层第n（n > 1 && n < k）个元素A[k][n]，A[k][n] = A[k-1][n-1] + A[k-1][n]
            for (size_t j = 1; j < vals[i].size() - 1; ++j) {
                vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
            }
        }

        return vals;
    }
};

auto main(int, char**) -> int32_t {
	std::vector<std::vector<int32_t>> vals = Solution::generate(5);
	std::cout << std::string(30, '-') << std::endl;
	for (auto &iter : vals) {
		auto it = iter.begin();
		while (it != iter.end()) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	exit(EXIT_SUCCESS);
}
