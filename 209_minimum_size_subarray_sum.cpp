#include "utils.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<1) return 0;
        int low = 0, high = 0;
        int res = nums.size()+1;
        int sum = nums[0];
        while(low<=high && high<nums.size()){
            if(sum<s){
                ++high;
                if(high<nums.size())sum += nums[high];
            }
            else{
                res = min(res, high-low+1);
                sum -=nums[low];
                ++low;
            }
        }
        if(sum>=s) res = min(res, high-low+1);
        return res==nums.size()+1?0:res;
    }
};