#include "utils.h"
/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//有很多特殊情况, 卡掉了好几次, 这个题目挺不错的

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<3) return true;
        int n = nums.size();
        int pos = 0;
        while(pos<=n-2 && nums[pos]<=nums[pos+1]) pos++;
        if(pos == n-1) return true;

        if(pos>0 && nums[pos-1]<=nums[pos+1]){
            ;
        }else if(pos>0 && pos+2<=n-1 && nums[pos]<=nums[pos+2]){
            pos++;
        }else if(pos>0 && pos+2 <=n-1){
            return false;
        }
        pos++;
        while(pos<=n-2 && nums[pos]<=nums[pos+1]) pos++;
        if(pos != n-1) return false;
        return true;
    }
};