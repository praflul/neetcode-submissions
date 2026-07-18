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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            if(a.start!=b.start) return a.start<b.start;
            return a.end<b.end;
        });
        int prevEnd=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            Interval interval=intervals[i];
            cout<<prevEnd<<" "<<interval.start<<" "<<interval.end<<"\n";
            if(interval.start<prevEnd) return false;
            prevEnd=interval.end;
        }
        return true;
    }
};
