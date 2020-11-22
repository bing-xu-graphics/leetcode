#include "utils.h"
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int prev = 0, post = nums.size()-1;
        while(prev<nums.size() && nums[prev]==tmp[prev]) prev++;
        while(prev<post && nums[post]==tmp[post]) post--;
        return post-prev+1; 
    }
};



///solution2 dont use extra space O(4n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2) return 0; 
        int min_value=std::numeric_limits<int>::max(), max_value=std::numeric_limits<int>::min();
        for(int left =1; left<nums.size();++left){
            if(nums[left]>=nums[left-1]) continue;
            min_value = min(min_value, nums[left]);
        }
        for(int right=nums.size()-2;right>=0; --right){
            if(nums[right]<=nums[right+1]) continue;
            max_value = max(max_value, nums[right]);
        }
        int l=0,r=0;
        for(l=0;l<nums.size();++l){
            if(nums[l]>min_value) break;
        }
        for(r=nums.size()-1;r>=0;--r){
            if(nums[r]<max_value)break;
        }
        if(r<l) return 0;
        return r-l+1;
    }
};