#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int, int> rests;
            for(int i = 0; i < nums.size(); i++) {
                int rest = target - nums[i];
                if(rests.find(nums[i]) != rests.end()) {
                    res.push_back(rests[nums[i]]);
                    res.push_back(i);
                    return res;
                }
                rests[rest] = i;
            }
        }
};


int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> sol;
    sol = s.twoSum(nums, 9);
    for(const int& n:sol) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

