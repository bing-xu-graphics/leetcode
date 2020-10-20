#include "utils.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<1) return -1;
        // if(nums.size()==1) return nums[0];
        int low = 0, high = nums.size()-1;
        while(low<high){
            int median = (low+high)>>1;
            if(nums[median]==nums[high]) high--;
            else if(nums[median]>nums[high]) low = median+1;
            else high = median;
        }
        return nums[low];
    }
};