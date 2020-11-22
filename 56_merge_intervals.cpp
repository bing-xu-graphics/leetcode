#include "utils.h"
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());
        int i = 0, j=1,high=intervals[0][1];//, low=intervals[0][0];
        while(i<j && j<intervals.size()){
            if(high>=intervals[j][0]){
                high = max(intervals[j][1], high);
                ++j;
            }else{
                res.push_back({intervals[i][0],high});
                i = j++;
                high = intervals[i][1];
            }
        }
        res.push_back({intervals[i][0],high});
        return res;

    }
};