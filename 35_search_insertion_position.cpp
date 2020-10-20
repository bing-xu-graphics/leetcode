#include "utils.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        // if(nums.size()==1) return nums[0]==target? 0:(nums[0]<target?1:0);
        int low = 0, high = nums.size()-1;
        while(low<high){
            int median = (low+high)>>1;
            if(nums[median]<target) low = median + 1;
            else if(nums[median]>target) high = median-1;
            else return median;
        } 
        return nums[low]<target?low+1:low;
    }
};