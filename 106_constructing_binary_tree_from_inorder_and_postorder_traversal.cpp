#include "utils.h"

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder,int low1, int high1, vector<int>& postorder, int low2, int high2){
        if(low1>high1 || low2>high2) return NULL;
        int root_idx1;
        for(int i=low1; i<high1; ++i){
            if(inorder[i]==postorder[high2]){
                root_idx1 = i;
                break;
            }
        }
        int left_tree_size = root_idx1 - low1;
        TreeNode* tree = new TreeNode(postorder[high2]);
        tree->left = buildTree(inorder, low1, root_idx1-1, postorder, low2, low2+left_tree_size-1);
        tree->right = buildTree(inorder, root_idx1+1, high1, postorder, low2+left_tree_size, high2-1);
        return tree;
    }
};