#include <string>
#include <array>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            std::array<std::pair<char,unsigned>,128> freqs{{}};
            for (char ch:s) {
                freqs[ch].first = ch;
                ++freqs[ch].second;
            }
            std::sort(freqs.begin(), freqs.end(), [](auto& x, auto& y) { 
                    return (x.second > y.second) || (x.second == y.second && x.first < y.first); 
                    });
            std::string sortedStr;
            for (auto it = freqs.begin(); it != freqs.end(); ++it) {
                if (it->first) {
                    sortedStr.append(it->second, it->first);
                }
                else {
                    break;
                }
            }
            return sortedStr;
        }
};

int main() {
    Solution sol;
    assert(sol.frequencySort("tree") == "eert");
    assert(sol.frequencySort("cccaaa") == "aaaccc");
    assert(sol.frequencySort("Aabb") == "bbAa");
    assert(sol.frequencySort("loveleetcode") == "eeeelloocdtv");
    assert(sol.frequencySort("Aazz") == "zzAa");
    assert(sol.frequencySort("2a554442f544asfasssffffasss") == "sssssssffffff44444aaaa55522");
    return 0;
}

