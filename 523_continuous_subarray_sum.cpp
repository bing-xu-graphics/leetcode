#include "utils.h"
/**
 * Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

 

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
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size(),nums[0]);
        for(int i=1; i<nums.size();++i){
            sums[i] = sums[i-1] + nums[i];
        }
        int cnt = 0;
        for(int left = 0;left<nums.size();++left){
            for(int right=left+1; right<nums.size();++right){
                if(k==0 && sums[right]-sums[left]+nums[left] == 0) return true;
                else if(k==0) continue;
                if((sums[right]-sums[left]+nums[left]) % k ==0) return true;
            }
        }
        return false;

    }
};

//method 2 Hashmap
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if(k==0){
            for(int i=0;i<nums.size()-1;++i){
                if(nums[i]==0 &&nums[i+1]==0) return true;
            }
            return false;
        }

        
        unordered_map<int,int> residual;
        residual[nums[0]%k] = 0;
        int sum = nums[0];
        for(int i=1; i<nums.size();++i){
            sum += nums[i];
            // if(k==0 && sum==0) return true;
            // else if(k==0) continue; 
            // else if(sum==0) return true;
            int tmp = sum % k;
            if (tmp==0) return true;
            else if(residual.find(tmp)==residual.end()){
                residual[tmp] = i;
            }else{
                if(i - residual[tmp]>1)
                    return true;
            }
        }
        return false;
    }
};