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
        if (intervals.size() == 0) {
            return intervals;
        }

        auto comp = [](Interval x, Interval y) { return x.start < y.start; };
        sort(intervals.begin(), intervals.end(), comp);

        int idx = 0;
        vector<Interval> mergedIntervals;
        do {
            int start = intervals[idx].start;
            int end = intervals[idx].end;
            while (intervals[++idx].start <= end) {
                end = max(end, intervals[idx].end);
            }
            mergedIntervals.push_back(Interval(start, end));
        } while (idx < intervals.size());
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

