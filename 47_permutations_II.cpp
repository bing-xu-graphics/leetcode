/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        map<int, int> occurances;
        for(auto& num:nums) occurances[num]++;
        vector<int> unique_nums(nums);
        sort(unique_nums.begin(), unique_nums.end());
        auto unique_iter = unique(unique_nums.begin(), unique_nums.end());
        unique_nums.erase( unique_iter, unique_nums.end());
        vector<int> current;
        vector<vector<int>> res;
        backtrack(unique_nums, occurances, res, current, n);
        return res;
    }
    void backtrack(vector<int>& unique_nums, map<int, int>& occurances,vector<vector<int>>& res, vector<int>& current, int n){
        if(current.size()==n){
            res.push_back(current);
            return;
        }
        for(int i=0;i<unique_nums.size();++i){
            if(occurances[unique_nums[i]]>0){
                current.push_back(unique_nums[i]);
                occurances[unique_nums[i]]--;
                backtrack(unique_nums, occurances, res, current, n);
                occurances[unique_nums[i]]++;
                current.pop_back();
            }
        }
    }
};