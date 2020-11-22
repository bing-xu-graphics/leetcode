#include "utils.h"
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest_length = 1;
        int tmp_length = 0;
        for(int start=0;start<nums.size();++start){
            tmp_length = 0;
            if(nums[start]==-1) continue;
            int current = start;
            while(current!=nums[current]){
                if(nums[current]==-1) break;
                int tmp = nums[current];
                nums[current] = -1;
                current = tmp;
                tmp_length++;
            }
            if(tmp_length>longest_length) longest_length = tmp_length;

        }
        return longest_length;
    }
};