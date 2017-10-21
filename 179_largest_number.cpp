#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            std::function<bool(int, int)> comp = [](int x, int y) { return std::to_string(x) + std::to_string(y) > std::to_string(y) + std::to_string(x); };
            std::sort(nums.begin(), nums.end(), comp);
            if (nums[0] == 0) {
                return "0";
            }
            string bigNum;
            for (int num:nums) {
                bigNum += std::to_string(num);
            }
            return bigNum;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    //vector<int> nums = {0, 0, 0, 0};
    cout << sol.largestNumber(nums) << endl;
    return 0;
}

