#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        bool twoSum(vector<int>& numbers, int target) {
            for (int& n:numbers) {
                if (binary_search(numbers.begin(), numbers.end(), target-n)) {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    cout << sol.twoSum(numbers, target) << endl;
    return 0;
}

