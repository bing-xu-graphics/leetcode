#include "utils.h"
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low<high){
            int median = low + (high - low)/2;
            int less=0, more = 0;
            for(int i=0;i<nums.size();i++){
                if(low<=nums[i]&&nums[i]<=median) less++;
                else if(nums[i]<=high && nums[i]>median) more++;
            }
            // printf("median = %d, less=%d, more=%d\n", median, less, more);
            if(more>(high-low+1)/2) low = median+1;
            else if(less>(high-low+1)/2) high = median;
            else return median;
            // else if(median_cnt>1) return median;
        }
        return low;
    }
};