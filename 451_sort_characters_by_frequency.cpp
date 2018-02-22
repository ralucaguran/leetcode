#include <string>
#include <array>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            const unsigned char N = 128;
            std::array<std::pair<char,unsigned>,N> freqs{{}};
            for (unsigned char i=0; i<N; i++) {
                freqs[i].first = i;
            }
            for (char ch:s) {
                ++freqs[ch].second;
            }
            std::sort(freqs.begin(), freqs.end(), [](const auto& x, const auto& y) { 
                    return (x.second > y.second) || (x.second == y.second && x.first < y.first); 
                    });
            std::string sortedStr{};
            sortedStr.reserve(s.length());
            for (auto it = freqs.begin(); it->second; ++it) {
                sortedStr.append(it->second, it->first);
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

