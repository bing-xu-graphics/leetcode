#include"utils.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeRecursive(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTreeRecursive(vector<int>& preorder, int low1, int high1, vector<int>& inorder, int low2, int high2){
        if(low1>high1 || low2>high2) return NULL;
        TreeNode* tree = new TreeNode(preorder[low1]);
        int root2;
        for(int i=low2;i<=high2; ++i){
            if(inorder[i]==preorder[low1]) root2 = i;
        }
        int left_tree_size = root2 - low2, right_tree_size = high2 - root2;
        if(left_tree_size ==0&& right_tree_size==0) return tree;
        TreeNode* left = buildTreeRecursive(preorder, low1+1, low1+left_tree_size, 
        inorder, low2, root2-1);
        TreeNode* right = buildTreeRecursive(preorder, low1+ left_tree_size+1, high1,
        inorder, root2+1, high2);
        tree->left = left;
        tree->right = right;
        return tree;
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
 *///稍微修改了一下代码, 看起来简洁一些
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeRecursive(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTreeRecursive(vector<int>& preorder, int low1, int high1, vector<int>& inorder, int low2, int high2){
        if(low1>high1 || low2>high2) return NULL;
        TreeNode* tree = new TreeNode(preorder[low1]);
        int root2;
        for(int i=low2;i<=high2; ++i){
            if(inorder[i]==preorder[low1]){
                root2 = i;
                break;
            } 
        }
        int left_tree_size = root2 - low2;
        // if(left_tree_size ==0&& right_tree_size==0) return tree;
        tree->left = buildTreeRecursive(preorder, low1+1, low1+left_tree_size, 
        inorder, low2, root2-1);
        tree->right = buildTreeRecursive(preorder, low1+ left_tree_size+1, high1,
        inorder, root2+1, high2);
        return tree;
    }
};