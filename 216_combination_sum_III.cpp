#include "utils.h"
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        combinationSum3_recursive(k, 1, n, res, tmp_res);
        return res;
    }
    void combinationSum3_recursive(int k, int start_k, int remain, vector<vector<int>>& res, vector<int>& tmp_res){
        if(tmp_res.size()==k && remain==0){
            res.push_back(tmp_res);
            return;
        }
        if(tmp_res.size()>=k) return;
        if(start_k>remain||start_k>9) return;

        combinationSum3_recursive(k, start_k+1, remain, res, tmp_res);
        tmp_res.push_back(start_k);
        combinationSum3_recursive(k, start_k+1,remain-start_k, res, tmp_res);
        tmp_res.pop_back();
    }
};


        // int most = remain/start_k;
        // most = min(most, k);
        // for(int i=0; i<=most;++i){
        //     for(int ii=0;ii<i;++ii)tmp_res.push_back(start_k);
        //     combinationSum3_recursive(k, start_k+1, remain-i*start_k, res, tmp_res);
        //     for(int ii=0;ii<i;++ii)tmp_res.pop_back();
        // }


    ///一开始没有理解提议, 上面是允许duplicates 的解法