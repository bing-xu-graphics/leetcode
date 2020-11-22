#include "utils.h"
/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return nums[0];
        int tmp0 = nums[0], tmp1 = nums[1];
        int max_sum = max(tmp0,tmp1);
        for(int i=2;i<nums.size();++i){
            int tmp = nums[i]+tmp0;
            tmp0 = max_sum;
            tmp1 = tmp;
            max_sum = max(tmp0,tmp1);
        }
        return max_sum;
    }
};


//dp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<nums.size();++i){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};

//因为只需要两个状态,所以可以进行简化

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return nums[0];
        int tmp0 = nums[0];
        int tmp1 = max(nums[0], nums[1]);
        for(int i=2;i<nums.size();++i){
            int tmp  = max(tmp1, tmp0+nums[i]);
            tmp0 = tmp1;
            tmp1 = tmp;
        }
        return tmp1;
    }
};