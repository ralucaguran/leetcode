#include <vector>
#include <array>
#include <limits>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            std::array<long long,3> max3;
            max3.fill(std::numeric_limits<long long>::min());
            for (int num:nums) {
                if (num == max3[0] || num == max3[1] || num == max3[2]) continue;
                if (num > max3[0]) {
                    max3[2] = max3[1];
                    max3[1] = max3[0];
                    max3[0] = num;
                }
                else if (num > max3[1]) {
                    max3[2] = max3[1];
                    max3[1] = num;
                }
                else if (num > max3[2]) {
                    max3[2] = num;
                }
            }
            return max3[2] != std::numeric_limits<long long>::min() ? max3[2] : max3[0];
        }
};

int main() {
    std::vector<int> nums = {1,1,-2147483648};
    Solution sol;
    std::cout << sol.thirdMax(nums) << std::endl;
    return 0;
}

