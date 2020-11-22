/**
 * Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
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

//这个是backtrack对的, 但是太慢了.
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root ){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(root->val==0){
                return 1;
            }else{
                return 0;
            }
        }else{//has immediate children
            if(root->val==0 ){
                // int original = root->val;
               //case1. rely on self.
                int minCameraNum = 0;
                root->val = 1;
                minCameraNum += 1;
                if(root->left){
                    root->left->val = -1;
                    minCameraNum  += dfs(root->left);
                    root->left->val = 0;
                } 
                if(root->right){
                    root->right->val = -1;
                    minCameraNum += dfs(root->right);
                    root->right->val = 0;
                }
                //case2 rely on kids
                root->val = 0;
                if(root->left && !root->right){
                    root->left->val = 1;
                    minCameraNum = min(minCameraNum, 1 + dfs(root->left));
                    root->left->val = 0;
                }else if(!root->left && root->right){
                    root->right->val = 1;
                    minCameraNum = min(minCameraNum, 1  + dfs(root->right));
                    root->right->val = 0;
                }else{

                    root->left->val = 1;
                    
                    minCameraNum = min(minCameraNum, 1 + dfs(root->left) + dfs(root->right));
                    root->left->val = 0;
                    root->right->val = 1;
                    minCameraNum = min(minCameraNum, 1 + dfs(root->left) + dfs(root->right));
                    root->right->val = 0;
                }
                return minCameraNum;

            }else if(root->val == -1){
                //case1. rely on self.
                int minCameraNum = 0;
                root->val = 1;
                minCameraNum += 1;
                if(root->left){
                    root->left->val = -1;
                    minCameraNum  += dfs(root->left);
                    root->left->val = 0;
                } 
                if(root->right){
                    root->right->val = -1;
                    minCameraNum += dfs(root->right);
                    root->right->val = 0;
                }
                root->val = -1;
                minCameraNum = min(minCameraNum, dfs(root->left)+dfs(root->right));
                return minCameraNum;
            }else{
                int minCameraNum = 0; //root->val = 1
                if(root->left){
                    root->left->val = -1;
                    minCameraNum+=dfs(root->left);
                    root->left->val = 0;
                } 
                if(root->right){
                    root->right->val = -1;
                    minCameraNum += dfs(root->right);
                    root->right->val = 0;
                } 
                return minCameraNum;
            }
        }
        // return 0;
    }
};