#include "utils.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();//
        int k=0;
        for(int i=1; i<nums.size(); i++){
            if(k!=0 && nums[i]!=nums[i-1]){
                nums[k] = nums[i];
                k++;
            }else if(k==0 && nums[i]==nums[i-1]) k=i;
        }
        return k==0?nums.size():k;
    }
};