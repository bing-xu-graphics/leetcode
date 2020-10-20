/**
 * Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
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
//method1 dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, max_depth, 0);
        return max_depth;
    }
    void dfs(TreeNode* root, int& max_depth, int current_depth){
        if(!root) return;
        if(!root->left && !root->right){
            max_depth = max(max_depth, current_depth+1);
            return;
        }
        if(root->left) dfs(root->left, max_depth, current_depth+1);
        if(root->right) dfs(root->right, max_depth, current_depth+1);
    }
};

//method2
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
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }

    int bfs(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while(!qu.empty()){
            level ++;
            int levelSize = qu.size();
            for(int i=0;i<levelSize; ++i){
                TreeNode* node = qu.front();
                qu.pop();
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }

        }
        return level;
        
    }
};

//method3 简化写一下dfs
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }

};