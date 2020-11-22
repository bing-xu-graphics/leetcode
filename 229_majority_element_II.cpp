#include "utils.h"
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<1)  return {};
        vector<int> res;
        int count1 = 1,count2 = 0;
        int num1 = nums[0], num2;
        for(int i=1; i<nums.size();++i){
            if(count1==0 && num2!=nums[i]){ //一开始没有这个num2!=nums[i] 的条件就不对
                count1++;
                num1 = nums[i];
            }
            else if(nums[i]==num1) count1++;
            else if(count2==0){
                count2++;
                num2 = nums[i];
            }
            else if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
            else {// not num1 or num2
                count1--;
                count2--;
            }
        }
        printf("num1=%d, count1=%d, num2=%d, count2=%d",num1,count1,num2, count2);
        if(count1>0){
            count1 = 0;
            for(int i=0; i<nums.size();++i){
                if(nums[i]==num1) count1++;
            }
            if(count1>nums.size()/3) res.push_back(num1);
        }
        if(count2>0){
            count2 = 0;
            for(int i=0; i<nums.size();++i){
                if(nums[i]==num2) count2++;
            }
            if(count2>nums.size()/3) res.push_back(num2);
        }
        
        return res;
    }

};