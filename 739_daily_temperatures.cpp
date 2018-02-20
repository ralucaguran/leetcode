#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            unsigned size = temperatures.size();
            if (size == 0) {
                return temperatures;
            }
            if (size == 1) {
                return std::vector<int>{0};
            }

            std::vector<int> rv(size);
            std::stack<unsigned> tempStack;
            tempStack.push(0);
            unsigned i = 1;
            while(i<size) {
                while (i<size && temperatures[i]>temperatures[tempStack.top()]) {
                    auto idx = tempStack.top();
                    rv[idx] = (temperatures[i]-temperatures[idx]);
                    tempStack.pop();
                    tempStack.push(i);
                    ++i;
                }
                auto refIdx = i-1;
                while (i<size && temperatures[i]<=temperatures[refIdx]) {
                    tempStack.push(i);
                    ++i;
                }
                while (!tempStack.empty()) {
                    auto idx = tempStack.top();
                    rv[idx] = temperatures[i]-temperatures[idx];
                    if (temperatures[i]-temperatures[idx]==0) {
                        rv[idx]=0;
                    }
                    tempStack.pop();
                }
                tempStack.push(temperatures[i]);
            }
            return rv;
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

