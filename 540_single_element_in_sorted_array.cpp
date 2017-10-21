#include <iostream>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int& num : nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,2,3,3,4,4,7,9,9,11,11};
    cout << sol.singleNonDuplicate(nums) << endl;
    return 0;
}

