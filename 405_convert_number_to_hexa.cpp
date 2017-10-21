#include <iostream>
#include <string>
#include <vector>

using namespace std;

const std::vector<char> HEX_SYMBOLS = {
    '0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f'
};

class Solution {
    public:
        string toHex(int num) {
            if (num == 0) {
                return "0";
            }

            unsigned uNum = num;
            int mask = 0b1111;
            std::string hexStr;
            while (uNum) {
                int hexDigit = uNum & mask;
                hexStr = HEX_SYMBOLS[hexDigit] + hexStr;
                uNum >>= 4;
            }
            return hexStr;
        }
};

int main() {
    Solution sol;
    std::cout << sol.toHex(26) << std::endl;
    std::cout << sol.toHex(0) << std::endl;
    std::cout << sol.toHex(-1) << std::endl;
    return 0;
}

