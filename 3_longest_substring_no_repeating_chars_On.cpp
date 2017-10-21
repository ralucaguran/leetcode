#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unsigned begin = 0, end = 0;
            unsigned slen = s.length();
            unsigned maxSubstrLen = 0;
            unordered_set<char> letters;
            while (begin < slen && end < slen) {
                if (letters.find(s[end]) == letters.end()) {
                    letters.insert(s[end++]);
                    maxSubstrLen = std::max(end-begin, maxSubstrLen);
                }
                else {
                    letters.erase(s[begin++]);
                }
            }
            return maxSubstrLen;
        }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("") << endl;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
    cout << sol.lengthOfLongestSubstring("abcadebb") << endl;
    return 0;
}

