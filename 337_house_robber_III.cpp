#include "utils.h"
/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * 这个解法是对的, 但是超时了.
 * 因为这个是一个backtracking  没有进行DP 优化memorization
 */
class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        //if not rob this 
        int not_rob =  dfs(root->left) + dfs(root->right);
        int rob = 0;
        if(root->val>0){
            //rob
            if(root->left) root->left->val *= -1;
            if(root->right) root->right->val *= -1;
            rob = root->val + dfs(root->left)+dfs(root->right);
            if(root->left) root->left->val *= -1;
            if(root->right) root->right->val *= -1;
        }
        return max(not_rob,rob);

    }
};

//method2  通过,   进行了一个存储. 回忆house rob I 只是换了一下存储的方法 不能bottom-up 只能top down with memorization. 
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return dfs(root, memo);
    }
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& memo){
        if(root==nullptr) return 0;
        if(memo.find(root)!=memo.end()) return memo[root];
        //if not rob this house
        int not_rob =  dfs(root->left, memo) + dfs(root->right, memo);
        //if rob this house
        int rob = root->val;
        if(root->left) rob += dfs(root->left->left, memo) + dfs(root->left->right, memo);
        if(root->right) rob += dfs(root->right->left, memo) + dfs(root->right->right, memo);
        int max_money = max(not_rob, rob);
        memo[root] = max_money;
        return max_money;
    }
};