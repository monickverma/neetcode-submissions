/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
    return a.start < b.start;
});

        priority_queue<int, vector<int>, greater<int>> q;
        for(auto&interval:intervals){
            int start=interval.start;
            int end=interval.end;

            if(!q.empty() && q.top()<=start){
                q.pop();
            }

            q.push(end);
        }
        return q.size();
        
    }
};
