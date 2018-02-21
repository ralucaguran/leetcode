#include <string>
#include <array>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            std::array<unsigned,128> freqs;
            freqs.fill(0);
            for (char ch:s) {
                ++freqs[ch];
            }
            std::sort(s.begin(), s.end(), [&freqs](char x, char y) { 
                    return (freqs[x] > freqs[y]) || (freqs[x] == freqs[y] && x < y); 
                    });
            return s;
        }
};

int main() {
    Solution sol;
    assert(sol.frequencySort("tree") == "eert");
    assert(sol.frequencySort("cccaaa") == "aaaccc");
    assert(sol.frequencySort("Aabb") == "bbAa");
    assert(sol.frequencySort("loveleetcode") == "eeeelloocdtv");
    return 0;
}

