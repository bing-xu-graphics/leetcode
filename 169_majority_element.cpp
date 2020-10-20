#include "utils.h"
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];   
    }
};


class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(!st.empty() && nums[i]!=st.top()) st.pop();
            else st.push(nums[i]);
        }
        return st.top();
    }
};