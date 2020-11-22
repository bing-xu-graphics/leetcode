#include"utils.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int res = std::numeric_limits<int>::min();
        if(nums.size()<3){
            for(int i=0; i<nums.size();++i) res = max(res, nums[i]);
            return res;
        }
        vector<int> threeNums;
        threeNums.push_back(nums[0]);
        if(nums[1]!=nums[0]) threeNums.push_back(nums[1]);
        if(nums[2]!=nums[0] && nums[2]!= nums[1]) threeNums.push_back(nums[2]);
        sort(threeNums.begin(), threeNums.end());
        // printf("threeNums.size()=%d\n", (int)threeNums.size());
        // printf("%d,%d", threeNums[0], threeNums[1]);
        for(int i=3;i<nums.size();++i){
            if((int)threeNums.size()==1 && nums[i]!=threeNums[0]){
                threeNums.push_back(nums[i]);
                sort(threeNums.begin(), threeNums.end());
            } 
            else if((int)threeNums.size()==2 && nums[i]!=threeNums[0] && nums[i]!=threeNums[1]){
                threeNums.push_back(nums[i]);
                sort(threeNums.begin(), threeNums.end());
            } 
            else if((int)threeNums.size()==3){
                if(nums[i]<=threeNums[0]) continue;
                else if(nums[i]==threeNums[1]|| nums[i]==threeNums[2]) continue;
                else if(nums[i]>threeNums[2]){
                    threeNums[0] = threeNums[1];
                    threeNums[1] = threeNums[2];
                    threeNums[2] = nums[i];
                }else if(nums[i]>threeNums[1]){
                    threeNums[0] = threeNums[1];
                    threeNums[1] = nums[i];
                }else if(nums[i]>threeNums[0]){
                    threeNums[0] = nums[i];
                }
            }
            
        }
        // printf("%d,%d,%d\n", threeNums[0], threeNums[1], threeNums[2]);
        return threeNums.size()<3? *(threeNums.end()-1):threeNums[0];
    }
};