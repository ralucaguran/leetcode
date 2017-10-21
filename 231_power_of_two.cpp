#include <iostream>
#include <climits>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n%2) return false;
        unsigned powerOfTwo = 1;
        for (unsigned i = 0; i < 8*sizeof(int); i++) {
            if (n == powerOfTwo) {
                return true;
            }
            powerOfTwo <<= 1;
        }
        return false;
    }
};

int main() {
    std::cout << INT_MAX << std::endl;
    std::cout << Solution().isPowerOfTwo(INT_MAX) << std::endl;
    std::cout << Solution().isPowerOfTwo(1024) << std::endl;
    std::cout << Solution().isPowerOfTwo(256) << std::endl;
    return 0;
}

