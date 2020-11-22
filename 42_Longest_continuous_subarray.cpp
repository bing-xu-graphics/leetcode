#include "utils.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int max_sum = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();++i){
            sum = max(sum+nums[i], nums[i]);
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};