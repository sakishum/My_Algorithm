/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 * It doesn't matter what you leave beyond the new length.
 * */

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
	 /**
      * @param A: a list of integers
      * @return : return an integer
     */ 
    static int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() < 3) {
			return nums.size();
		}

		int size = 0;
		int occurence = 1;
		for (std::vector<int>::size_type i = 1; i != nums.size(); ++i) {
			if (nums[size] != nums[i]) {
				nums[++size] = nums[i];
				occurence = 1;
			} else if (nums[size] == nums[i]) {
				if (occurence++ < 2) {
					nums[++size] = nums[i];
				}
			}
		}
		return ++size;
    }
};

auto main(int, char**) -> int32_t {
	std::vector<int> ivec = {1, 1, 1, 2, 2, 3, 3, 3, 3};
	int size = Solution::removeDuplicates(ivec);
	std::cout << "size: " << size << std::endl;
	for (int i = 0; i != size; ++i) {
		std::cout << ivec[i] << std::endl;
	}
	exit(EXIT_SUCCESS);
}
