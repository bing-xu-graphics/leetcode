#include "utils.h"
//最开始犯的错误是pass by value了, 只要没有指针, c++ 里面全都是deep copy
//另外学到了vector extend 的写法:
//                // res.reserve(res.size()+tmp_res.size());
                // res.insert(res.end(), tmp_res.begin(), tmp_res.end());
//想通了recursion 和iteration 的区别
//iteration是每次recursion 子任务只有一条分支,那么可以做iteration 的更新, 否则的化多条子任务的分支
//则一定要用recursion
//另外recursion一定要注意的是 写两部分
//1)写最底层  也就是终止条件
//2)写最外层,这个就是每层的一般情况, 如此就够了
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        combinationSum(candidates, 0, target, tmp_res, res);
        return res;
    }
    void combinationSum(vector<int>& candidates, int start, int target, vector<int>& tmp_res, vector<vector<int>>& res){
        if(start == candidates.size()){
            if(target==0){
                // res.reserve(res.size()+tmp_res.size());
                // res.insert(res.end(), tmp_res.begin(), tmp_res.end());
                vector<int> tmp = tmp_res;
                res.push_back(tmp);
            }
            return;
        }
        for(int cnt=(target/candidates[start]);cnt>=0;cnt--){
            for(int i=0; i<cnt; i++) tmp_res.push_back(candidates[start]);
            combinationSum(candidates, start+1, target-cnt*candidates[start],tmp_res,res);
            for(int i=0; i<cnt; i++) tmp_res.pop_back();
        }
    }

};