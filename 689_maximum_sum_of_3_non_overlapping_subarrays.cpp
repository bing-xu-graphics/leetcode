#include "utils.h"
/**
 * In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:

Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 

Note:

nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums(nums.size()-k+1, 0);
        for(int i=0;i<k;++i){
            sums[0] +=nums[i];
        }
        for(int i=1;i<nums.size()-k+1;++i){
            sums[i] = sums[i-1]-nums[i-1]+nums[i+k-1];
        }
        vector<int> maxSumTillPosFromLeft(sums.size(),0);
        maxSumTillPosFromLeft[0] = sums[0];
        for(int i=1; i<sums.size();++i){
            maxSumTillPosFromLeft[i] = max(sums[i], maxSumTillPosFromLeft[i-1]);
        }
        vector<int> maxSumTillPosFromRight(sums.size(),0);
        maxSumTillPosFromRight[sums.size()-1] = sums[sums.size()-1];
        for(int i=sums.size()-2;i>=0;--i){
            maxSumTillPosFromRight[i] = max(sums[i], maxSumTillPosFromRight[i+1]);
        }
        // for(int i=0;i<sums.size();++i){
        //     printf("%d ", maxSumTillPosFromLeft[i]);
        // }
        // printf("\n");
        // for(int i=0;i<sums.size();++i){
        //     printf("%d ", maxSumTillPosFromRight[i]);
        // }
        // printf("\n");
        int middleStartPos = k;
        int maxSumTotal = 0;
        vector<int> res(3,0);
        for(int middleStartPos=k; middleStartPos<sums.size()-k; ++middleStartPos){
            int currentThreeSum = sums[middleStartPos]+ maxSumTillPosFromLeft[middleStartPos-k] + maxSumTillPosFromRight[middleStartPos+k];
            if(maxSumTotal<currentThreeSum){
                maxSumTotal = currentThreeSum;
                res[0] = maxSumTillPosFromLeft[middleStartPos-k];
                res[1] = middleStartPos;
                res[2] = maxSumTillPosFromRight[middleStartPos+k];
            }
        }
        // printf("%d,%d, %d\n", res[0],res[1],res[2]);
        for(int i=0;i<sums.size();++i){
            if(sums[i]==res[0]){
                res[0] = i;
                break;
            }
        }
        for(int i=res[1]+k; i<sums.size();++i){
            if(sums[i]==res[2]){
                res[2] = i;
                break;
            }
        }
        return res;

    }
};