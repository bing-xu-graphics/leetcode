#include"utils.h"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0; i<nums.size();++i){
            while(nums[i]!=i+1 && nums[i]!=nums[nums[i]-1])
                swap(nums, i, nums[i]-1);
        }

        vector<int> res;
        for(int i=0; i<nums.size();++i){
            if(nums[i]!=i+1) res.push_back(i+1);
        }
        return res;
    }

    void swap(vector<int>& nums, int i, int j){
        if(i==j) return;
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
};