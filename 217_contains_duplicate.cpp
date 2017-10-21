#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        return numsSet.size() < nums.size() ? true : false;
    }
};

int main() {
    vector<int> nums = {3, 1, 7, 2, 3, 1};
    Solution sol;
    cout << sol.containsDuplicate(nums) << endl;
    return 0;
}

