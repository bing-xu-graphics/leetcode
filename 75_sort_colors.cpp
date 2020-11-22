#include "utils.h"

/*
这种sorting的区别就在于, 数字的总数是非常有限的. 所以可以用一遍遍历swap的形式.

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?



*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos1 = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==0){
                swap(nums, i, pos0++);
                if(nums[i]==1) swap(nums, i, pos0+pos1-1);
            } 
            else if(nums[i]==1){
                swap(nums, i, pos0+pos1++);
            }
            // for(int j=0; j<nums.size(); ++j) printf("%d ", nums[j]);
            // printf("\n");
        }

    }

private:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }    
};