#include "utils.h"
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        if(timeSeries.size()<2) return timeSeries.size()*duration;
        for(int i=1;i<timeSeries.size();++i){
            if(timeSeries[i]>=timeSeries[i-1]+duration) total+= duration;
            else total+=(timeSeries[i]-timeSeries[i-1]);
        }
        return total+duration;
    }
};