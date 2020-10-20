/**
 * Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
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
    int maxPathSum(TreeNode* root) {
        if(!root) return -1;
        int maxSum = root->val;
        dfs(root, maxSum);
        return maxSum;
    }

    int maxTreePathSum(TreeNode* root){
        if(!root) return 0;
        return max(0, root->val + max(maxTreePathSum(root->left), maxTreePathSum(root->right)));
    }

    void dfs(TreeNode* root, int& maxSum){
        if(!root) return;
        if(!root->left && !root->right){
            maxSum = max(maxSum, root->val);
            return;
        } 
        maxSum = max(maxSum, root->val + maxTreePathSum(root->left) + maxTreePathSum(root->right));
        dfs(root->left,maxSum);
        dfs(root->right,maxSum);
    }
};

//method 2  相当于把上面的两个步骤合并到一起了
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
    int maxPathSum(TreeNode* root) {
        if(!root) return -1;
        int maxSum = root->val;
        maxTreePathSum(root, maxSum);
        return maxSum;
    }

    int maxTreePathSum(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int leftSum = maxTreePathSum(root->left, maxSum);
        int rightSum = maxTreePathSum(root->right, maxSum);
        maxSum = max(maxSum, root->val + leftSum + rightSum);
        return max(0, root->val + max(leftSum, rightSum));
        
    }

};