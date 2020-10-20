#include "utils.h"
/**
 * Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

 

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 

Constraints:

The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//comment里面的去重方式是错误的, 没有考虑到相同的数字不挨着, [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]比如就是错误的
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<2) return res;
        vector<int> subsequence;
        int currentIdx = 0;
        dfs(nums, res, subsequence, currentIdx);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subsequence, int currentIdx){
        if(currentIdx>=nums.size()){
             if(subsequence.size()>1){ // && (res.empty()||subsequence!=res.back())
                res.push_back(subsequence);
                return;
             }
        }else{
            if(subsequence.size()<1 || nums[currentIdx]>= subsequence.back()){
                subsequence.push_back(nums[currentIdx]);
                dfs(nums, res, subsequence, currentIdx+1);
                subsequence.pop_back();
            }
            dfs(nums, res, subsequence, currentIdx+1);
        }

    }
};

/**
 * 用了一个set来去重就对了, 然后比较慢.
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> res_set;
        if(nums.size()<2) return res;
        vector<int> subsequence;
        int currentIdx = 0;
        dfs(nums, res, res_set, subsequence, currentIdx);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, set<vector<int>>& res_set, vector<int>& subsequence, int currentIdx){
        if(currentIdx>=nums.size()){
             if(subsequence.size()>1 && res_set.find(subsequence)==res_set.end()){ // && (res.empty()||subsequence!=res.back())
                res.push_back(subsequence);
                res_set.insert(subsequence);
                return;
             }
        }else{
            if(subsequence.size()<1 || nums[currentIdx]>= subsequence.back()){
                subsequence.push_back(nums[currentIdx]);
                dfs(nums, res, res_set,subsequence, currentIdx+1);
                subsequence.pop_back();
            }
            dfs(nums, res,res_set, subsequence, currentIdx+1);
        }

    }
};

//methd3 如何对选择和不选择做一些限定, 导致一定都是 如何和前面是重复的就不能不选, 必须选
/**
 * 那如何保证没有重复呢？我们需要给「不选择」做一个限定条件，只有当当前的元素不等于上一个选择的元素的时候，才考虑不选择当前元素，直接递归后面的元素。因为如果有两个相同的元素，我们会考虑这样四种情况：

前者被选择，后者被选择
前者被选择，后者不被选择
前者不被选择，后者被选择
前者不被选择，后者不被选择
其中第二种情况和第三种情况其实是等价的，我们这样限制之后，舍弃了第二种，保留了第三种，于是达到了去重的目的。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/increasing-subsequences/solution/di-zeng-zi-xu-lie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<2) return res;
        vector<int> subsequence;
        int currentIdx = 0;
        dfs(nums, res, subsequence, currentIdx);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subsequence, int currentIdx){
        if(currentIdx>=nums.size()){
            if(subsequence.size()>1 ){ 
            //  if(subsequence.size()>1 && res_set.find(subsequence)==res_set.end()){ // && (res.empty()||subsequence!=res.back())
                res.push_back(subsequence);
                return;
             }
        }else{
            if(subsequence.size()<1 || nums[currentIdx]>= subsequence.back()){
                subsequence.push_back(nums[currentIdx]);
                dfs(nums, res,subsequence, currentIdx+1);
                subsequence.pop_back();
            }
            if(subsequence.size()<1 ||nums[currentIdx]!=subsequence.back())dfs(nums, res, subsequence, currentIdx+1);
        }

    }
};