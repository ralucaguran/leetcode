#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> prioqNums(nums.begin(), nums.end());
            for (int i = 0; i < k-1; i++) {
                prioqNums.pop();
            }
            return prioqNums.top();
        }
};

int main() {
    std::vector<int> nums = {3,2,1,5,6,4};
    Solution sol;
    std::cout << sol.findKthLargest(nums, 4) << std::endl;
    return 0;
}

