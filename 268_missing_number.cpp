#include "utils.h"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high){
            int pivot = partion(nums, low, high);
            if(nums[pivot]>pivot) high = pivot-1;
            else low = pivot+1;
        }
        if(low>=nums.size())return nums.size();
        else if(high<0) return 0;
        else if(nums[low]==low)return low+1;
        else return low;
    }

    int partion(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int to_insert =low;
        for(int i=low; i<high;i++){
            if(nums[i]<=pivot) swap(nums, i, to_insert++);
        }
        swap(nums, to_insert, high);
        return to_insert;
    }
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }    
};