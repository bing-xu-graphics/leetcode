#include "utils.h"
//Solution1 超时.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            sums[i+1] = sum;
        }
        int res = 0;
        for(int left =0; left<sums.size();++left){
            for(int right=left+1; right<sums.size();++right){
                if(sums[right]-sums[left]==k) res++;
            }
        }
        return res;
        
    }
};

//use the hash table to save all the nums.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        map<int, vector<int>> sum_index;
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            sums[i+1] = sum;
            if(sum_index.find(sum)!=sum_index.end()){
                sum_index[sum].push_back(i+1);
            }else{
                vector<int> vec={i+1};
                sum_index[sum] = vec;
            }
        }
        if(sum_index.find(0)!=sum_index.end()) sum_index[0].push_back(0);
        else sum_index[0].push_back(0);
        
        int res = 0;
        for(int right=1;right<sums.size();++right){
            if(sum_index.find(sums[right]-k)==sum_index.end()) continue;
            vector<int> index_list = sum_index[sums[right]-k];
            for(auto iter=index_list.begin();iter!=index_list.end();++iter){
                if(*iter<right) res++;
            }
        }
        return res;
    }
};

//solution3, 如果只看前面的index的化可以合在一个loop里面进行
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        map<int, int> sum_frequency;
        int sum = 0;
        sum_frequency[0] = 1;
        int res = 0;
        for(int right=1;right<sums.size();++right){
            sum+=nums[right-1];
            if(sum_frequency.find(sum-k)!=sum_frequency.end()){
                res+=sum_frequency[sum-k];
            }
            if(sum_frequency.find(sum)!=sum_frequency.end()){
                sum_frequency[sum]++;
            }else{
                sum_frequency[sum] = 1;
            }

        }
        return res;
    }
};