#include "utils.h"
//最开始是用0作为一个特殊的情况, 然后被各种case 卡住,重新换了一个思路, 没有以0 作为特殊例子, 
//而是坚持traverse 完了整个vector
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2) return true;
        int needed_min = 1;
        bool ans = true;
        for(int i=nums.size()-2; i>=0; --i){
            if(nums[i]>=needed_min){
                ans = true;
                needed_min = 1;
            } 
            else{
                ans = false;
                needed_min++;
            }
        }
        return ans;
    }
};