#include "utils.h"
/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        //no first house
        int tmp0 = nums[1],tmp1 = max(nums[1], nums[2]);
        for(int i=3;i<nums.size();++i){
            int tmp = max(tmp1, tmp0+nums[i]);
            tmp0 = tmp1;
            tmp1 = tmp;
        }
        int ans = tmp1;
        //no last house
        tmp0 = nums[0], tmp1 = max(nums[0], nums[1]);
        for(int i=2;i<nums.size()-1;++i){
            int tmp = max(tmp1, tmp0+nums[i]);
            tmp0 = tmp1;
            tmp1 = tmp;
        }
        return max(tmp1, ans);
    }
};