#include"utils.h"
//解法1 超时
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<int(nums.size())-1;++i){ //这里没有int 就会陷入一直循环. 
            int end = nums.size()-1 < (i+k)?nums.size()-1 : (i+k);
            for(int j=i+1;j<=end;++j){
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
    }
};