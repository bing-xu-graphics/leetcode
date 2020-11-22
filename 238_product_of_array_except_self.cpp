#include "utils.h"
//solve in O(n) and should 
/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size(), 1);
        vector<int> right_product(nums.size(), 1);
        for(int i=1; i<nums.size();++i){
            left_product[i] = left_product[i-1]* nums[i-1];
        }
        for(int j=nums.size()-2; j>=0; --j){
            right_product[j] = right_product[j+1]*nums[j+1];
        }
        vector<int> res(nums.size(),1);
        for(int k=0; k<nums.size();++k){
            res[k] = left_product[k]*right_product[k];
        }
        return res;
    }
};


/**
 * Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_product(nums.size(), 1);
        // vector<int> right_product(nums.size(), 1);
        for(int i=1; i<nums.size();++i){
            left_product[i] = left_product[i-1]* nums[i-1];
        }
        int right_product = 1;
        for(int j=nums.size()-2; j>=0; --j){
            right_product *= nums[j+1];
            left_product[j] *= right_product;
        }

       
        return left_product;
    }
};