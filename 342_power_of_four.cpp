#include <climits>
#include <assert.h>

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        if (num%2) return false;
        unsigned powerOfFour = 1;
        for (unsigned i = 0; i < 8*sizeof(int); i++) {
            if (num == powerOfFour) {
                return true;
            }
            powerOfFour <<= 2;
        }
        return false;
    }
};

int main() {
    assert(Solution().isPowerOfFour(0) == false);
    assert(Solution().isPowerOfFour(1) == true);
    assert(Solution().isPowerOfFour(32) == false);
    assert(Solution().isPowerOfFour(1024) == true);
    assert(Solution().isPowerOfFour(INT_MAX) == false);
    return 0;
}

