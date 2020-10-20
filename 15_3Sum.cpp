//n^2  exceeds time limit
#include "utils.h"

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return vector<vector<int>>{};
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> resList;
        map<int,vector<vector<int>>> twoSumMap;
        for(int i=0;i<nums.size(); i++){
            for(int j=i+1; j< nums.size(); j++){
                int twoSum = nums[i]+nums[j];
                if(twoSumMap.find(twoSum)==twoSumMap.end()){
                    vector<vector<int>> twoSumList;
                    twoSumList.push_back(vector<int>{i, j});
                    twoSumMap.emplace(twoSum, twoSumList);
                    // printf("[%d, %d]", nums[i],nums[j]);
                }else{
                    // printf("[%d, %d].... \n", nums[i],nums[j]);
                    auto last_iter = twoSumMap[twoSum].end()-1;
                    if(nums[i]==nums[(*last_iter)[0]] && nums[j]==nums[(*last_iter)[1]]){
                        (*last_iter) = vector<int>{i,j};
                    }else{
                        twoSumMap[twoSum].push_back(vector<int>{i, j});
                    }                    
                }
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            if(twoSumMap.find(-nums[i])!=twoSumMap.end()){
                vector<vector<int>> twoSumList = twoSumMap[-nums[i]];
                for(int ii=0;ii<twoSumList.size(); ii++){
                    // if(i==twoSumList[ii][0]||i==twoSumList[ii][1]) continue;
                    if(i>=twoSumList[ii][0]) continue;
                    vector<int> res = vector<int>{nums[i], nums[twoSumList[ii][0]], nums[twoSumList[ii][1]]};
                    // sort(res.begin(), res.end());
                    resList.push_back(res);
                }
            }
        }
        // printf("%d\n", resList.size());
        // printResList(resList);
        // std::sort(resList.begin(), resList.end());
        // resList.erase(std::unique(resList.begin(), resList.end()), resList.end());
        // printf("%d\n", resList.size());
        return resList;
    }

private:
void printResList(vector<vector<int>> res){
    printf("[");
    for(auto iter1=res.begin(); iter1!= res.end();++iter1){
        printf("[");
        for(auto iter2 = (*iter1).begin(); iter2!=(*iter1).end(); ++iter2){
            printf("%d,", *iter2);
        }
        printf("],");
    }
    printf("]");
}    
};


//这个题目的麻烦之处在于有很多的duplicates, 双指针对于有重复结果的解法
class TwoSum{
    public:
    vector<vector<int>> multipleTwoSum(vector<int> nums, int target){
        vector<vector<int>> res;
        if(nums.size()<2) return res;
        std::sort(nums.begin(), nums.end());
        int low = 0,  high = nums.size()-1;
        while(low<high){
            if(nums[low]+nums[high]<target) low++;
            else if(nums[low]+nums[high]>target) high--;
            else{
                auto iter_last = res.end() - 1;
                if(nums[low] != nums[(*iter_last)[0]])
                    res.push_back(vector<int>{low, high});
                    low++;
                    high--;
            }
        }
    }

};
//Method2 doulbe pointer method
//faster O(n^2) 直接想办法跳过会比之后再去重快很多.
//在最开始的时候就考虑排序是一个比较好的去重方法.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        int i,j;
        for(int k=0;k<nums.size()-2;k++){
            if(nums[k]>0) break;
            if(k>0 && nums[k]==nums[k-1]) continue;
            int target = -nums[k];
            i = k+1;
            j = nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]<target) i++;
                else if(nums[i]+nums[j]>target) j--;
                else{
                    // printf("%d, %d, %d,\n ",nums[k], nums[i], nums[j]);
                    if(res.size()<1){
                        res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    }else{
                        auto iter_last = res.end()-1;
                        if(!((nums[k]==(*iter_last)[0] && nums[i]==(*iter_last)[1]))){
                            res.push_back(vector<int>{ nums[k],nums[i], nums[j]}); 
                        }
                    }
                    i++;
                    j--;
                }
            }
        }
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

private:
void printResList(vector<vector<int>> res){
    printf("[");
    for(auto iter1=res.begin(); iter1!= res.end();++iter1){
        printf("[");
        for(auto iter2 = (*iter1).begin(); iter2!=(*iter1).end(); ++iter2){
            printf("%d,", *iter2);
        }
        printf("],");
    }
    printf("]");
}    
};
