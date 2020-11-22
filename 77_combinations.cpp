/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(n, k, 1, comb, res);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& comb, vector<vector<int>>& res){
        if(comb.size()==k){
            res.push_back(comb);
            return;
        }
        
        for(int i=start; i<=n-(k-comb.size())+1;++i){
            comb.push_back(i);
            backtrack(n, k, i+1, comb, res);
            comb.pop_back();
        }
    }
};