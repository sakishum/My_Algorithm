
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
   static int removeElement(std::vector<int>& nums, int val) {
        int num = 0;
        for (auto iter = nums.begin(); iter != nums.end(); ) {
            if (*iter == val) {
                iter = nums.erase(iter);
                continue;
            }
            ++num;
            ++iter;
        }
        return num;
    }
};

int main(void) {
	std::vector<int32_t> ivec = {1,2,2,3,2,4};
	Solution::removeElement(ivec, 2);
	for (auto it : ivec) {
		std::cout << it << std::endl;
	} 
	exit(EXIT_SUCCESS);
}

