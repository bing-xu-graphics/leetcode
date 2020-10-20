#include "utils.h"
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            while(nums[i]!=i+1&&nums[i]!= nums[nums[i]-1]){
                // if(nums[i]==nums[nums[i]-1]) continue;
                swap(nums, i, nums[i]-1);
            }
        }
        vector<int> res;
        for(int i=0; i<nums.size();++i){
            if(nums[i]!=i+1) res.push_back(nums[i]);
        }
        return res;
    }

    void swap(vector<int>& nums, int i, int j){
        if(nums[i]==nums[j]) return;
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
};