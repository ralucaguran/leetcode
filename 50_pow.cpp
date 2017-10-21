#include <iostream>
#include <climits>


class Solution {
    public:
        double myPow(double x, int n) {
            if (n == INT_MIN) return 1/x*myPow(x, n+1);
    //        if (n == INT_MAX) return x*myPow(x, n-1);
            if (n < 0) return 1/myPow(x, -n);
            if (n == 0) return 1;
            if (n == 1) return x;
            if (n == 2) return x*x;
            double ndiv2Pow = myPow(x, n/2);
            if (n%2) return ndiv2Pow*ndiv2Pow*x;
            else return ndiv2Pow*ndiv2Pow;
        }
};

int main() {
    Solution sol;
    std::cout << sol.myPow(2, 11) << std::endl;
    std::cout << sol.myPow(2, -3) << std::endl;
    std::cout << sol.myPow(1.0, -2147483648) << std::endl;
    std::cout << sol.myPow(1.0, 2147483648) << std::endl;
    return 0;
}

