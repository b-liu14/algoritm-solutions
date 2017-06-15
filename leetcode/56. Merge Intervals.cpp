/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct {
    bool operator()(Interval a, Interval b)
    {
        return a.start < b.start;
    }
} customLess;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), customLess);
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;

        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > cur.end) {
                ans.push_back(cur);
                cur = intervals[i];
            }
            else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};
