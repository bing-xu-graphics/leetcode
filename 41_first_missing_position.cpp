#include "utils.h"
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 1;
        for(int i=0; i<n; i++){
            if(nums[i]==(i+1)) continue;
            if(nums[i]>=1 && nums[i]<=n) swapToPlace(nums, nums[i]);
        }

        for(int i=0; i<n;i++){
            if(nums[i]!=(i+1)) return i+1;
        }
        return n+1;
    }
private:
    void swapToPlace(vector<int>& nums, int target){
        while(target>=1 && target<=nums.size()){
            int tmp = nums[target-1];
            nums[target-1] = target;
            if(tmp==nums[target-1]) return; //一开始缺少了这一个return
            target = tmp;
        }
        return;
    }
};