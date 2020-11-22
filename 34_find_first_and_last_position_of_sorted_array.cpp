#include "utils.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()<1) return vector<int>{-1,-1};
        int min_idx=nums.size(), max_idx = -1;
        int low=0, high =nums.size()-1;
        searchRange(nums,target, low, high, min_idx, max_idx);
        if(max_idx == -1) return vector<int>{-1,-1};
        else if(min_idx == max_idx) return vector<int>{min_idx, min_idx};
        else return vector<int>{min_idx, max_idx};
    }

public:
    void searchRange(vector<int>& nums, int target, int low, int high, int& min_idx, int& max_idx){
        while(low<high){
            
            int median = (low+high)>>1;
            printf("low=%d, high=%d, median=%d, ",low, high, median);
            if(nums[median]<target) low = median+1;
            else if(nums[median]>target) high = median -1;
            else{
                searchRange(nums, target, low, median-1, min_idx,max_idx);
                min_idx = min(min_idx, median);
                searchRange(nums,target, median+1,high, min_idx, max_idx);
                max_idx = max(max_idx, median);
                return; //最开始居然忘记了这个return
            }
        }
        if(nums[low]==target){
            min_idx = min(min_idx, low);
            max_idx = max(max_idx, low);
        }   
        return;
    }
    
};