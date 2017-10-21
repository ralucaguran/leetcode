#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int allOnceXor = 0;
            int allOnceOr = 0;
            for (auto& num:nums) {
                allOnceXor ^= num;
                allOnceOr |= num;
            }
            return allOnceXor ^ allOnceOr;
        }
};

int main() {
    vector<int> nums = {5,3,5,1,2,3,3,2,5,2};
    std::cout << Solution().singleNumber(nums) << std::endl;
    return 0;
}

