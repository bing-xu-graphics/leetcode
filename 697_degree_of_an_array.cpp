#include "utils.h"
/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 

Constraints:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> records;
        for(int i=0;i<nums.size();i++){
            if(records.find(nums[i])==records.end()){
                vector<int> times_and_two_ends(3,0);
                times_and_two_ends[0]++;
                times_and_two_ends[1] = i;
                times_and_two_ends[2] = i;
                records[nums[i]] = times_and_two_ends;
            }else{
                records[nums[i]][0]++;
                records[nums[i]][2] = i;
            }
        }

        int max_degree=0;
        for(auto iter = records.begin();iter!=records.end();++iter){
            if(iter->second[0]>max_degree) max_degree = iter->second[0];
        }
        int min_length = nums.size();
        for(auto iter = records.begin();iter!=records.end();++iter){
            if(iter->second[0] == max_degree && min_length> (iter->second[2]-iter->second[1]+1)) min_length = iter->second[2]-iter-> second[1]+1;
        }
        return max(0,min_length);
    }
};