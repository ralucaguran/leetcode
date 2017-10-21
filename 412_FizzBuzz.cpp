#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> res;
            string s;
            for (int i=1; i<=n; ++i) {
                s = "";
                bool fizzOrBuzz = false;
                if (i%3 == 0) {
                    s += "Fizz";
                    fizzOrBuzz = true;
                }
                if (i%5 == 0) {
                    s += "Buzz";
                    fizzOrBuzz = true;
                }
                if (!fizzOrBuzz) {
                    s = to_string(i);
                }
                res.push_back(s);
            }
            return res;
        }
};

int main() {
    Solution sol;
    sol.fizzBuzz(15);
    return 0;
}

