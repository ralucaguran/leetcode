#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, unsigned> counter;
        for (int num:nums) {
            ++counter[num];
        }
        return std::max_element(counter.begin(), counter.end(), 
                [] (const pair<int,unsigned>& x, const pair<int,unsigned>& y) 
                { return x.second<y.second; }
                )->first;
    }
};

int main() {
	Solution sol;
    std::vector<int> nums = {5,2,1,2,2,2,1,1,3,2};
    assert(sol.majorityElement(nums)==2);
	return 0;
}
