#include <vector>
#include <iostream>

using namespace std;


class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            size_t size = temperatures.size();
            std::vector<int> res(size,0);
            if (size == 0 || size == 1) {
                return res;
            }
            unsigned i = 0, j = 1;
            while (j<size) {
                if (temperatures[j]>temperatures[i]) {
                    res[i] = j-i;
                    ++i;
                    j = i+1;
                }
                else {
                    j++;
                    if (j==size && i<size-1) {
                        ++i;
                        j = i+1;
                    }
                }
            }
            return res;
        }
};

int main() {
    Solution sol;
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    //std::vector<int> temperatures = {1,2,3,1,1,1,1,1,100,5,5,5,5,1,1,101};
    //std::vector<int> temperatures = {55,38,53,81,61,93,97,32,43,78};
    auto res = sol.dailyTemperatures(temperatures);
    for (auto& val:res) {
        std::cout << val << std::endl;
    }
    return 0;
}

