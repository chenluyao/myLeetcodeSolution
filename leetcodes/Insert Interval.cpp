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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval>::iterator iter;
        for(iter = intervals.begin(); iter!= intervals.end(); ++iter)
        {
            if((*iter).start<= newInterval.start && (*iter).end >= newInterval.start)
            {
                newInterval.start = (*iter).start;
            }
            if((*iter).start<= newInterval.end && (*iter).end >= newInterval.end)
            {
                newInterval.end = (*iter).end;
            }
        }
        bool inserted = false;
        for(iter = intervals.begin(); iter!= intervals.end(); ++iter)
        {
            if((*iter).start>= newInterval.start && inserted == false)
            {
                iter = intervals.insert(iter,newInterval);
                inserted = true;
            }
            else if((*iter).start>= newInterval.start && (*iter).end <= newInterval.end)
            {
                iter = intervals.erase(iter);
                iter--;
            }
        }
        if(inserted == false)
        {
            intervals.push_back(newInterval);
        }
        return intervals;
    }
};