#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            string substr = "";
            string maxSubstr = "";
            unordered_set<char> letters = {};
            for (unsigned i = 0; i < s.length(); i++) {
                unsigned k = i;
                while (k < s.length() && letters.find(s[k]) == letters.end()) {
                    substr += s[k];
                    letters.insert(s[k]);
                    k++;
                }
                if (substr.length() > maxSubstr.length()) {
                    maxSubstr = substr;
                }
                letters.clear();
                substr.clear();
            }
            return maxSubstr.length();
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

