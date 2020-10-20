#include"utils.h"
/**
 * 	• 方法
		1. 刻画一个最优解的结构特征
		2. 递归地定义最优解的值
		3. 计算最优解的值, 通常采用自底向上的方法
		4. 利用计算出的信息构造一个最优解
**/



//Maximum subarray
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1) return -1;
        int dp = nums[0];
        int res = dp;
        for(int i=1;i<nums.size();i++){
            dp = max(dp+nums[i], nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};

/**
 * 分析:
 * 这里刻画最优解的结构特征 dp 表示 以当前num 为结束的一个continuous subarray,
 * dp[i] = max(dp[i-1]+nums[i], nums[i])
 * 然后这个特征的定义 其实需要遍历 所有的结果选出一个最优解, 那么通过维系一个running value 来在过程中记录max也可以.
 * 另外, 这里continuous 其实是很重要的, 所以有必要 以xx为结束的一个subarray, 不然不必须依赖于有这个数字,
 * 就像house robbery 题目中, 反而是可以不连续的
 * /

/**152. Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/**分析
 * 	• 方法
		1. 刻画一个最优解的结构特征
		2. 递归地定义最优解的值
		3. 计算最优解的值, 通常采用自底向上的方法
		4. 利用计算出的信息构造一个最优解

    1.在这里, 继续刻画一个最优解的结构特征.
    由于还是continuous的所以继续使用以dp[i] 表示以nums[i] 为结尾的解
    2. 递归地定义最优解的值
    dp[i] = max(nums[i],  max_dp[i-1]*nums[i], min_dp[i-1]*nums[i] 当nums[i]有可能是负数的时候)
    所以每次要保留max 和min
**/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<1) return -1;
        int smallest = nums[0];
        int largest = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();++i){
            int smallest_backup = smallest;
            int largest_backup = largest;
            smallest = min(min(largest_backup*nums[i], smallest_backup*nums[i]), nums[i]);
            largest = max(max(smallest_backup*nums[i], largest_backup*nums[i]), nums[i]);
            res = max(largest, res);
        }
        
        return res;
    }
};


/**
 *  !!!!!
 * 那么, 有时候除了这种max min 这种明显的最优解情况, 还有一些其他的条件 . 各种自定义的约束 ,
 * 比如sum 比K 大, 小啊 之类的. 然后并不是记录某个最优解, 而是所有的解法 
/**
 * 523. Continuous Subarray Sum
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

 

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 

Constraints:

The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
