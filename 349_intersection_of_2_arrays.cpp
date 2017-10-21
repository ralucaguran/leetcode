#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> ref;
        for(const int& n:nums1) {
            ref.insert(n);
        }
        for(const int& n:nums2) {
            auto found = ref.find(n);
            if(found != ref.end()){
                res.push_back(n);
                ref.erase(found);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution sol;
    vector<int> intersection = sol.intersection(nums1, nums2);
    for(const int& n:intersection) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

