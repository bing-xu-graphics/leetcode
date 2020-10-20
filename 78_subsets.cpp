#include "utils.h"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        subsets_recursive(nums, 0, res, tmp_res);
        // sort(res.begin(), res.end());
        return res;
    }
    void subsets_recursive(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& tmp_res){
        if(start==nums.size()){
            res.push_back(tmp_res);
            return;
        }
        subsets_recursive(nums, start+1, res, tmp_res);
        tmp_res.push_back(nums[start]);
        subsets_recursive(nums, start+1, res, tmp_res);
        tmp_res.pop_back();
        
    }
};