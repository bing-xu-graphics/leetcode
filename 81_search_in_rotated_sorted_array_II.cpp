#include "utils.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1) return false;
        // int low = 0, high = nums.size()-1;
        // while(low < high){
        //     int median = (low+high)>>1;
        //     if(nums[low]<= nums[median] && nums[median]<=nums[high]) break;
        //     else if(nums[low] <= nums[median] && nums[median] > nums[high]) low = median+1;
        //     else if(nums[low]> nums[median] && nums[median]<= nums[high]) high = median;
        // }
        // int offset = low;
        int offset = 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<nums[i-1]){
                offset = i;
                break;
            }
        }
        // printf("offset=%d\n", offset);
        int low = 0, high = nums.size();
        while(low < high){
            int median = (low+high)>>1;
            if(nums[(median + offset)%nums.size()]>=target) high = median;
            else low = median+1;
        }
        if(nums[(low+offset)%nums.size()]==target) return true;
        else return false;
    }
};


class Solution2 {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1) return false;
        int low = 0, high = nums.size();
        while(low < high){ // 最开始的时候 这里面一直没有写对. 其实只卡一遍就可以了.
            int median = (low+high)>>1;
            if(nums[low]==nums[median]){
                low++; //如果是的化, 就前进一个.
                continue;
            }else if(nums[low]<nums[median]) low = median; 
            else if(nums[low]>nums[median])high = median;
        }
        int offset = high;//或者low 是一样的
       
        // printf("offset=%d\n", offset);
        low = 0, high = nums.size();
        while(low < high){
            int median = (low+high)>>1;
            if(nums[(median + offset)%nums.size()]>=target) high = median;
            else low = median+1;
        }
        if(nums[(low+offset)%nums.size()]==target) return true;
        else return false;
    }
};




class Solution3{
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1) return false;
        int low = 0, high = nums.size();
        while(low < high){
            int median = (low+high)>>1;
            if(nums[median]==target) return true;
            if(nums[low]==nums[median]){
                low++;
                continue;
            }else if(nums[low]<nums[median]){
                if(nums[low]<=target && target<nums[median]) high = median;
                else low = median+1;
            } 
            else if(nums[low]>nums[median]){
                if(nums[median]<target<=nums[high-1]) low = median+1;
                else high = median;
            }
        }
        return false;
    }
};