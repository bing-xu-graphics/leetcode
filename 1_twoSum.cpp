#include<vector>
#include<map>
using std::vector;
using std::map;
//Algorithm1
//quicksort first then do finding 
// time complexity nlogn, space complexity n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums;
        vector_sort(nums, 0, nums.size()-1);
        // for(int ii=0;ii<nums.size(); ii++){
        //     printf("%d ",nums[ii]);
        // }
        int i=0,j=nums.size()-1;
        while(nums[i]+nums[j]!= target){
            while((nums[i]+ nums[j])>target) j-=1;
            while((nums[i]+ nums[j])<target) i+=1;
        }
        // printf("%d %d %d %d",i, j, nums[i],nums[j]);
        vector<int> res;
        for(int ii=0;ii<nums.size(); ii++){
            if(copy[ii]==nums[i]|| copy[ii]==nums[j]) res.push_back(ii);
        }
        return res;
    }

private:
    void vector_sort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int pi = partition(nums, start, end);
        // printf("%d\n",pi);
        vector_sort(nums, start, pi-1);
        vector_sort(nums, pi+1, end);
    }   
private:
    int partition(vector<int>& nums, int start, int end){
        if(start>=end) return end;
        int pivot = nums[end];
        int i = start - 1;
        for(int j=start; j<=end-1;j++){
            if(nums[j]<pivot){
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i+1, end);
        return i+1;     
    }   
private:
void swap(vector<int>& nums, int i, int j){
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp; 
}          
};

//method2, 两遍hash
#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for(int i=0;i<nums.size(); i++){
            hash.emplace(nums[i], i);
        }
        for(int i=0;i<nums.size(); i++){
            int complement = target - nums[i];
            if(hash.find(complement)!= hash.end() && hash[complement]!=i){
                return vector<int>{i, hash[complement]};
            }
        }
        return {};
    }
};

//method 3 one-time hash
#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for(int i=0; i<nums.size(); i++){
            int another = target - nums[i];
            if(hash.find(another)!=hash.end()) 
                return vector<int>{hash[another], i};
            else
                hash[nums[i]] = i;    
        }
        return {};
    }
};