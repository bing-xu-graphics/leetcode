#include "utils.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump_count = 0;
        int current_idx=0;
        while(current_idx<nums.size()-1){
            // printf("current_idx=%d\n", current_idx);
            jump(nums, current_idx);
            jump_count++;
        }
        return jump_count;
    }

    void jump(vector<int>& nums, int& idx){
        if(idx==nums.size()-1) return;
        int max_jump = nums[idx];
        int max_add = -1, jump = -1;
        for(int i=1; i<=max_jump;i++){
            if(idx+i==nums.size()-1){
                    idx+= i;
                    return;
                }
            if(idx+i<nums.size() && i + nums[idx+i]> max_add){
                max_add = i + nums[idx+i];
                jump = i;
            }
        }
        idx += jump;
    }
};