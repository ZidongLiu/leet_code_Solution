//
// Created by Zidong Liu on 8/22/18.
//


/// 16ms,
/// beat 14%

#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n= intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](Interval &a, Interval &b){
            return(a.start<b.start);
        });
        vector<Interval> ret_ved;
        Interval this_interval(intervals[0].start,intervals[0].end);
        for(int i=0;i<n;i++){
            if(this_interval.end>=intervals[i].start){
                this_interval.end = max(intervals[i].end,this_interval.end);
            }else{
                ret_ved.push_back(this_interval);
                this_interval = intervals[i];
            }
        }
        ret_ved.push_back(this_interval);
        return(ret_ved);
    }
};
