#include <iostream>
#include <stdlib.h>

using namespace std;


const int N = 5;

int guess(int num) {
    if (N > num) {
        return 1;
    }
    else if (N < num) {
        return -1;
    }
    else {
        return 0;
    }
}

class Solution {
    public:
        int guessNumber(int n) {
            int left = 1;
            int right = n;
            while (left <= right) {
                int mid = left + (right - left)/2;
                switch (guess(mid)) {
                    case 0:
                        return mid;
                    case -1:
                        right = mid-1;
                        break;
                    case 1:
                        left = mid+1;
                        break;
                }
            }
            return -1;
        }
};


int main(int argc, char** argv) {
    Solution sol;
    cout << sol.guessNumber(atoi(argv[1])) << endl;
    return 0;
}

