#include "utils.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size(); 
        int last = nums[0], cnt = 1;
        if(nums[1] == nums[0]) cnt = 2;
        else{
            last = nums[1];
            cnt = 1;
        }
        
        int insert_pos = 2;
        for(int i=2; i<nums.size(); i++){
            if(cnt == 2 && nums[i]==last) continue;
            if(cnt == 1 && nums[i]==last){
                cnt++;
                nums[insert_pos++] = nums[i];
            }else if(nums[i]!=last){
                nums[insert_pos++] = nums[i];
                cnt = 1;
                last = nums[i];
            }
        }
        return insert_pos;
    }
};