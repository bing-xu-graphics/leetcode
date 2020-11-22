#include<utils.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return;
        for(int i=nums.size()-2; i>=0;i--){
            int min_larger_number=std::numeric_limits<int>::max();
            int k = -1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i] && nums[j] < min_larger_number){
                    k = j;
                    min_larger_number = nums[j];
                }
            }
            if(k!=-1){
                nums[k] = nums[i];
                nums[i] = min_larger_number;
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
    }
};