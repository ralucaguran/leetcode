#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int lines = matrix.size();
            int cols = matrix[0].size();
            if (lines == 0 || cols == 0) {
                return false;
            }

            auto posInMatrix = [cols](int posInArray) { return std::make_pair(posInArray/cols, posInArray%cols); };
            int left = 0;
            int right = lines*cols - 1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                auto midPosInMatrix = posInMatrix(mid);
                if (target < matrix[midPosInMatrix.first][midPosInMatrix.second]) {
                    right = mid - 1;
                }
                else if (target > matrix[midPosInMatrix.first][midPosInMatrix.second]) {
                    left = mid + 1;
                }
                else {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << sol.searchMatrix(matrix, 100) << endl;
    return 0;
}

