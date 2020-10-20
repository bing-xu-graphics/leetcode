/**
 * Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        dfs(perms, nums, 0);
        return perms;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, int pos){
        if(pos==nums.size()){
            vector<int> tmp = nums;
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<nums.size();++i){
            swap(nums, pos, i);
            dfs(res, nums, pos+1);
            swap(nums, pos, i);
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};