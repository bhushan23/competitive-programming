/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        vector<Interval> ans;
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start > newInterval.start)
                break;
        }
        int j = 0;
        while(j < i) {
            ans.push_back(intervals[j++]);
        }
        
        if (j == 0) { // Interting at first position
             ans.push_back(newInterval);
        } else if (ans[j-1].end < newInterval.start) {
            ans.push_back(newInterval);
        } else {
            ans[ans.size()-1].end = max(ans[ans.size()-1].end, newInterval.end);
        }
        
        while (i < intervals.size() && ans[ans.size()-1].end >= intervals[i].start) {
            ans[ans.size()-1].end = max(ans[ans.size()-1].end, intervals[i].end);
            i++;
        }

        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
