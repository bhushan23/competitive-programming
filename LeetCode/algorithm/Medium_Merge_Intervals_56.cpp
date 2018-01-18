/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class lessThan {
   public:
    bool operator()(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> list;
        sort(intervals.begin(), intervals.end(), lessThan());
        if (intervals.size() == 0)
            return list;
        
        list.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (list[list.size()-1].end < intervals[i].start) {
                list.push_back(intervals[i]);
            } else {
                list[list.size()-1].end = max(list[list.size()-1].end, intervals[i].end);
            }
        }
        return list;
    }
};
