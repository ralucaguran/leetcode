#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            auto size = nums.size();
            switch (size) {
            case 1:
                return nums[0];
            case 2:
                return nums[0]*nums[1];
            case 3:
                return nums[0]*nums[1]*nums[2];
            }

            std::sort(nums.begin(), nums.end());
            return std::max(nums[size-1]*nums[0]*nums[1], nums[size-1]*nums[size-3]*nums[size-2]);
        }
};

int main() {
    std::vector<int> nums = {-7,-9,-1,-2,-3, 5, 9};
    Solution sol;
    std::cout << sol.maximumProduct(nums) << std::endl;
    return 0;
}

