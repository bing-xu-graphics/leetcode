#include "utils.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int last = 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[last]) last = i;
            else return last;
        }
        return last;
    }
};