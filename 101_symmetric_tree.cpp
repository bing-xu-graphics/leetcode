#include "utils.h"

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

  
 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);    
    }

    bool isSymmetric(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p!=nullptr && q!=nullptr){
            if(p->val != q->val) return false;
            return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
        }else return false;
    }


};


//method iterative way
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);    
    }

    bool isSymmetric(TreeNode* p, TreeNode* q){
        queue<TreeNode*> qu_p, qu_q;
        qu_p.push(p); qu_q.push(q);
        while(!qu_p.empty() &&!qu_q.empty()){
            TreeNode* node_p = qu_p.front(); 
            qu_p.pop();
            TreeNode * node_q = qu_q.front();
            qu_q.pop();
            if(node_p == nullptr && node_q == nullptr) continue; //注意这里要换成continue , 而不是return true;
            if(node_p == nullptr || node_q == nullptr) return false;
            if(node_p->val != node_q->val) return false;
            qu_p.push(node_p->left);
            qu_p.push(node_p->right);
            qu_q.push(node_q->right);
            qu_q.push(node_q->left);
        }
        if(!qu_p.empty() || !qu_q.empty()) return false;
        return true;
    }


};