/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> currentPath;
        dfs(root, res, currentPath, sum);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& currentPath, int sum){
        if(!root) return;
        if(!root->left && !root->right){
            currentPath.push_back(root->val);
            int currentSum = accumulate(currentPath.begin(), currentPath.end(),0);
            if(currentSum==sum) res.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        currentPath.push_back(root->val);
        dfs(root->left, res, currentPath, sum);
        dfs(root->right, res, currentPath, sum);
        currentPath.pop_back();
    }
};