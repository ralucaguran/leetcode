#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<pair<int, int>>& points) {
            if (points.size() == 0 || points.size() == 1) {
                return points.size();
            }

            std::sort(points.begin(), points.end());
            std::vector<std::pair<int,int>> targets = {};
            auto ref = points[0];
            auto var = points[1];
            unsigned i = 0;
            while (true) {
                while (i < points.size() && var.first <= ref.second) {
                    ref = {var.first, std::min(ref.second, var.second)};
                    var = points[++i];
                }
                targets.push_back(ref);
                if (i == points.size()) {
                    break;
                }
                ref = var;
            }
            return targets.size();
        }
};

int main() {
    Solution sol;
    std::vector<std::pair<int,int>> points = {{10,16},{2,8},{1,6},{7,12}};
    assert(sol.findMinArrowShots(points) == 2);
    points = {{1,4},{3,7},{7,8},{8,11},{12,25}};
    assert(sol.findMinArrowShots(points) == 3);
    points = {};
    assert(sol.findMinArrowShots(points) == 0);
    points = {{1,7}};
    assert(sol.findMinArrowShots(points) == 1);
    points = {{8,29},{1,7},{7,9}};
    assert(sol.findMinArrowShots(points) == 2);
    return 0;
}

