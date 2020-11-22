#include "utils.h"
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp_res;
        subsets_recursive(nums, 0, tmp_res, res);
        return res;
    }

    void subsets_recursive(vector<int>& nums, int start, vector<int>& tmp_res, vector<vector<int>>& res){
        if(start==nums.size()){
            res.push_back(tmp_res);
            return;
        }
        int count = 1;
        while(start+count<nums.size() && nums[start+count]==nums[start]) count++;
        // printf("start = %d, %d\n", start, count);
        for(int cnt=0;cnt<=count;cnt++){
            for(int ii=0;ii<cnt;ii++) tmp_res.push_back(nums[start]);
            subsets_recursive(nums, start+count, tmp_res, res);
            for(int ii=0; ii<cnt;ii++) tmp_res.pop_back();   
        }
    }
};