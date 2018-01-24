#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            unsigned len = nums.size();
            if (len == 0 || len == 1) {
                return;
            }

            unsigned idx = 0;
            while (nums[idx] != 0 && idx++ < len);
            if (idx == len-1) {
                return;
            }
            unsigned zeroIdx = idx++;
            while (idx < len) {
                if (nums[idx] != 0) {
                    nums[zeroIdx++] = nums[idx];
                    nums[idx] = 0;
                }
                ++idx;
            }
        }
};

int main() {
    Solution sol = Solution();
    std::vector<int> nums = {0,1,2,3,0,0,0,0,5,0,7,0,9,0,0,0,-1,0,0,0};
    sol.moveZeroes(nums);
    std::vector<int> result = {1,2,3,5,7,9,-1,0,0,0,0,0,0,0,0,0,0,0,0};
    assert(std::equal(nums.begin(), nums.end(), result.begin()));
    std::for_each(nums.begin(), nums.end(), [](const int x) {std::cout << x << " ";});
    std::cout << std::endl;
}

