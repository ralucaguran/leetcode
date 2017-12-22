#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        auto comp = [](Interval x, Interval y) { return x.start < y.start; };
        sort(intervals.begin(), intervals.end(), comp);

        int idx = 1;
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> mergedIntervals{};
        while (true) {
            while (intervals[idx].start <= end) {
                end = max(end, intervals[idx].end);
                ++idx;
                if (idx == intervals.size()) {
                    mergedIntervals.emplace_back(start, end);
                    return mergedIntervals;
                }
            }
            mergedIntervals.emplace_back(start, end);
            start = intervals[idx].start;
            end = intervals[idx].end;
        }
        return mergedIntervals;
    }
};

int main() {
    Solution sol;
    vector<Interval> intervals = {{5,5},{1,2},{2,4},{2,3},{4,4},{5,5},{2,3},{5,6},{0,0},{5,6}};
    vector<Interval> mergedIntervals = sol.merge(intervals);
    for (Interval i:mergedIntervals) {
        cout << "[" << i.start << "," << i.end << "]" << endl;
    }
    return 0;
}

