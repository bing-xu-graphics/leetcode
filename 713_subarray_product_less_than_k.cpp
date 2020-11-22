#include "utils.h"
/**
 * Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

//medthod1  overflow!!! 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> product;
        product.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            product.push_back(product[i-1]*nums[i]);
        }
        int cnt = 0;
        for(int left =0; left<nums.size();++left){
            for(int right=left;right<nums.size();++right){
                if(product[right]/product[left]*nums[left]<k) cnt++;
            }
        }
        return cnt;
    }
};

//这边对subarray类型的题目进行一个归纳吧
//method2  这与不会溢出, 但是超时了, 所以需要对ordered array 进行二分查找
// 注意 一般加和就会带来increasing sorted list
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<float> logs;
        for(int i = 0;i<nums.size();++i){
            logs.push_back(log((float)nums[i]));
        }
        vector<float> sums(nums.size(), 0);
        sums[0] = logs[0];
        for(int i=1; i<nums.size();++i){
            sums[i] = sums[i-1]+ logs[i];
        }
        int cnt = 0;
        for(int left=0;left<nums.size();++left){
            for(int right=left;right<nums.size();++right){
                if(sums[right]-sums[left]+logs[left]< log(k)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
   
};

//改成 二分法之后, 精度问题  float 不行, 同时还要减去一个1e-9
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<double> logs;
        for(int i = 0;i<nums.size();++i){
            logs.push_back(log((double)nums[i]));
        }
        vector<double> sums(nums.size(), 0);
        sums[0] = logs[0];
        for(int i=1; i<nums.size();++i){
            sums[i] = sums[i-1]+ logs[i];
        }
        int cnt = 0;
        for(int start=0;start<nums.size();++start){
            int left = start, right = nums.size();
            while(left<right){
                int mid = (left+right)/2;
                if(sums[mid] - sums[start]+logs[start]<log(k)- 1e-9) left = mid+1;
                else right = mid;
            }
            cnt += (left-1-start+1);
        }
        return cnt;
    }
   
};

//一定出现除法, 就有可能有精度问题, 一定要非常注意
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<1) return 0;
        int cnt = 0;
        int product = 1;
        int left = 0;
        for(int right = 0;right<nums.size();++right){
            while((double)nums[right]>=(double)k/product && left<=right){
                    product /= nums[left++];
                }
            // cnt++;
            product *= nums[right];
            cnt += (right-left+1);
            // product *= nums[right];
            // while(product>=k && left<=right) product /=nums[left++];
            // cnt += (right-left+1);
        }
        return cnt;
    }
   
};