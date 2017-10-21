#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxOnes = 0;
            int consOnes = 0;
            for (int& num : nums) {
                if (num == 1) {
                    ++consOnes;
                }
                else {
                    if (consOnes > maxOnes) {
                        maxOnes = consOnes;
                    }
                    consOnes = 0;
                }
            }
            return consOnes > maxOnes ? consOnes : maxOnes;
        }
};

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    Solution s;
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}

