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
    static bool comp(const Interval &l, const Interval &r)
    {
        return (l.start < r.start);
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> result;
        int m = intervals.size();
        if(m == 0)
        {
            return result;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int i;
        Interval iter = intervals[0];
        for(i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start <= iter.end)
            {
                if(intervals[i].end > iter.end)
                {
                    iter.end = intervals[i].end;
                }
            }
            else
            {
                result.push_back(iter);
                iter = intervals[i];
            }
        }
        result.push_back(iter);
        return result;
    }
};