#include "utils.h"
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        std::sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, tmp_res, res);
        return res;
    }
    void combinationSum2(vector<int>& candidates, int start, int target, vector<int>& tmp_res, vector<vector<int>>& res){
        if(start == candidates.size()){
            if(target == 0){
                vector<int> tmp = tmp_res;
                res.push_back(tmp);
            }
            return;
        }
        int count = 1;
        while((start+count)<candidates.size() && candidates[count+start]==candidates[start]) count++;
        int cnt_start = min(count, target/candidates[start]);
        // printf("num=%d, count=%d\n", candidates[start], count);
        for(int cnt = cnt_start; cnt>=0; cnt--){
            for(int i=0;i<cnt;i++) tmp_res.push_back(candidates[start]);
            combinationSum2(candidates, start+count, target-candidates[start]*cnt, tmp_res, res);
            for(int i=0;i<cnt;i++) tmp_res.pop_back();
        }
    }
};



// 加了一个 branch pruning, 因为已经排序过了,如果这个大于target, 那么后面的check没有必要进行了.
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        std::sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, tmp_res, res);
        return res;
    }
    void combinationSum2(vector<int>& candidates, int start, int target, vector<int>& tmp_res, vector<vector<int>>& res){
        if(start == candidates.size() || candidates[start]>target){
            if(target == 0){
                vector<int> tmp = tmp_res;
                res.push_back(tmp);
            }
            return;
        }
        int count = 1;
        while((start+count)<candidates.size() && candidates[count+start]==candidates[start]) count++;
        int cnt_start = min(count, target/candidates[start]);
        // printf("num=%d, count=%d\n", candidates[start], count);
        for(int cnt = cnt_start; cnt>=0; cnt--){
            for(int i=0;i<cnt;i++) tmp_res.push_back(candidates[start]);
            combinationSum2(candidates, start+count, target-candidates[start]*cnt, tmp_res, res);
            for(int i=0;i<cnt;i++) tmp_res.pop_back();
        }
    }
};