#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
    public:
        bool isAnagram(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
};

int main() {
    Solution sol;
    string s = "rat";
    string t = "car";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}

