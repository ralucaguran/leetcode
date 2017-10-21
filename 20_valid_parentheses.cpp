#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;


class Solution {
    public:
        bool isValid(string s) {
            map<char,char> paranthesesMap;
            paranthesesMap['}'] = '{';
            paranthesesMap[']'] = '[';
            paranthesesMap[')'] = '(';
            stack<char> openParenthesesStack;
            for (char& c : s) {
                if (c == '{' || c == '[' || c == '(') {
                    openParenthesesStack.push(c);
                }
                if (c == '}' || c == ']' || c == ')') {
                    if (openParenthesesStack.empty()) {
                        return false;
                    }
                    else {
                        if (paranthesesMap[c] != openParenthesesStack.top()) {
                            return false;
                        }
                        else {
                            openParenthesesStack.pop();
                        }
                    }
                }
            }
            return openParenthesesStack.empty();
        }
};

int main() {
    Solution sol;
    //string s = "aaa()(ds;llfsdkf){ksdfjk}dklaskdl[dfgfd]sddflk";
    string s = "{";
    cout << sol.isValid(s) << endl;
    return 0;
}

