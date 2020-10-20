#include "utils.h"
/**
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_length = 0;
        if(nums.size()<1) return 0;
        int length = 1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]) length++;
            else{
                if(length> max_length) max_length = length;
                length = 1;
            }
        }
        if(length> max_length) max_length = length;
        return max_length;
    }
};