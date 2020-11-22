#include "utils.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()<1) return {};
        vector<string> res;
        int start = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>(nums[i-1]+1)){
                if(start!=nums[i-1]){
                    res.push_back(std::to_string(start)+"->"+std::to_string(nums[i-1]));
                }else{
                    res.push_back(std::to_string(start));
                }
                start = nums[i];
            }
        }
        if(start!=nums[nums.size()-1]){
            res.push_back(std::to_string(start)+"->"+std::to_string(nums[nums.size()-1]));
        }else{
            res.push_back(std::to_string(start));
        }
        return res;
    }
};