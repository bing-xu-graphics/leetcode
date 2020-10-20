#include "utils.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return -1;
        int history, now;
        int closest = nums[0]+nums[1]+nums[2];
        std::sort(nums.begin(), nums.end());
        int i,j;
        for(int k=0;k<nums.size()-2; k++){
            if(k>0 && nums[k]==nums[k-1]) continue;
            i = k+1;
            j = nums.size()-1;
            while(i<j){
                now = nums[k]+nums[i]+nums[j];
                if(now < target)i++;
                else if(now>target) j--;
                else return target;
                closest = abs(closest-target)< abs(target-now)? closest: now;
            }
        }
        return closest;
    }
};