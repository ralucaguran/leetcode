#include <stdint.h>
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned short bitCount = 0;
        for (unsigned short i=0; i<8*sizeof(n); i++) {
            if (n & (1<<i)) {
                ++bitCount;
            }
        }
        return bitCount;
    }
};

int main() {
    std::cout << Solution().hammingWeight(11) << std::endl;
    return 0;
}

