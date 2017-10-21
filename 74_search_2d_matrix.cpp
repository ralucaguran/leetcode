#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int lines = matrix.size();
            if (lines == 0) {
                return false;
            }
            int cols = matrix[0].size();
            if (cols == 0) {
                return false;
            } 
            int midBegin = 0;
            int midEnd = lines-1;
            while (midBegin <= midEnd) {
                int midLine = midBegin + (midEnd - midBegin)/2;
                int left = matrix[midLine][0];
                int right = matrix[midLine][cols-1];

                if (target < left) {
                   midEnd = midLine - 1;
                }
                else if (target > right) {
                    midBegin = midLine + 1;
                }
                else {
                    return std::binary_search(matrix[midLine].begin(), matrix[midLine].end(), target);
                }
            }
            return false;
        }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << sol.searchMatrix(matrix, 3) << endl;
    return 0;
}

