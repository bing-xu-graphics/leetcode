#include"utils.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // if(nums.size()<1) return 0;
        int length = 0;
        int maxlength = length;
        for(int i=0; i<nums.size();++i){
            if(nums[i]==1) length++;
            else{
                maxlength = max(maxlength, length);
                length = 0;
            }
        }
        maxlength = max(maxlength, length);


        return maxlength;
    }
};