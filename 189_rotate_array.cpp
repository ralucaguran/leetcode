#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        unsigned n = nums.size();
        if (n <= k) {
            k %= n;
        }
        std::vector<int> revnums;
        for (int i = n-k; i < n; i++) {
            revnums.push_back(nums[i]);
        }
        for (int i = 0; i < n-k; i++) {
            revnums.push_back(nums[i]);
        }
        nums = revnums;
    }
};

int main() {
    std::vector<int> nums = {1,2,3,4,5,6,7};
    Solution sol;
    sol.rotate(nums, 4);
    for (int& num : nums) {
        std::cout << num << std::endl;
    }
    return 0;
}

