#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int, int> rests;
            for(const int& num:nums) {
                int rest = target - num;
                if(rests.find(num) != rests.end()) {
                    res.push_back(rests[num]);
                    res.push_back(num);
                    return res;
                }
                rests[rest] = num;
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

