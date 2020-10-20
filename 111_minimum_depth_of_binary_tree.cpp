#include "utils.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root==nullptr) return 0;
        qu.push(root);
        int ancestor = 1;
        int level = 0;
        while(!qu.empty()){
            int current = 0;
            for(int i=0;i<ancestor;i++){
                TreeNode* node = qu.front(); qu.pop();
                if(node->left==nullptr && node->right==nullptr) return level+1;
                if(node->left){
                    qu.push(node->left); 
                    current++;
                } 
                if(node->right){
                    qu.push(node->right);
                    current++;
                } 
            }
            ancestor = current;
            level++;
        }
        return level;
    }
};




//DFS
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
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode* node){
        if(node==nullptr) return 0;
        if(!node->left && !node->right) return 1;
        if(node->left && !node->right) return dfs(node->left)+1;
        if(!node->left && node->right) return dfs(node->right)+1;
        return min(dfs(node->left), dfs(node->right))+1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//wrong method  理解错题目了, 注意什么才算leaf node

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root==nullptr) return 0;
        qu.push(root);
        int level = 0;
        while(!qu.empty()){
            // printf("level=%d %d\n", level, 2^level);
            for(int i=0;i<pow(2,level);i++){
                TreeNode* node = qu.front(); qu.pop();
                // printf("node->val=%d\n", node->val);
                if(node->left==nullptr && node->right==nullptr) return level+1;
                if(node->left==nullptr||node->right==nullptr) return level+2;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            level++;
        }
        return level;
    }
};