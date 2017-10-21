#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            std::unordered_map<int,int> numFrequencies;
            for (int num:nums) {
                numFrequencies[num]++;
            }

            auto comp = [](const std::pair<int,int>& left, const std::pair<int,int>& right) {
                return left.second > right.second;
            };
            std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(comp)> numFrequencyPrioQ{comp};

            for (auto numFreq:numFrequencies) {
                numFrequencyPrioQ.emplace(numFreq.first, numFreq.second);
                if (numFrequencyPrioQ.size() > k) {
                    numFrequencyPrioQ.pop();
                }
            }

            std::vector<int> topKFrequentArray;
            while (!numFrequencyPrioQ.empty()) {
                topKFrequentArray.emplace_back(numFrequencyPrioQ.top().first);
                numFrequencyPrioQ.pop();
            }
            std::reverse(topKFrequentArray.begin(), topKFrequentArray.end());
            return topKFrequentArray;
        }
};

int main() {
    std::vector<int> nums = {1,1,1,1,2,2,3,4,4,4,4,-3,-1,5,-3,-3,-1,-3,-3};
    Solution sol;
    std::vector<int> topK = sol.topKFrequent(nums, 1);
    for (int freq:topK) {
        std::cout << freq << std::endl;
    }
}

