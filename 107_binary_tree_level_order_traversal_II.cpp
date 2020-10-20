/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        bfs(root, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void bfs(TreeNode* root, vector<vector<int>>& res){
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> level;
        int levelNum =1;
        int tmp_levelNUm = 0;
        while(!qu.empty()){
            while(levelNum>0){
                TreeNode* node = qu.front();
                qu.pop();
                level.push_back(node->val);
                if(node->left){
                    qu.push(node->left);
                    tmp_levelNUm++;
                } 
                if(node->right){
                    qu.push(node->right);
                    tmp_levelNUm++;
                } 
                levelNum--;
            }
            res.push_back(level);
            level.clear();
            levelNum = tmp_levelNUm;
            tmp_levelNUm = 0;
        }
    }
};

//method2  代码优化了一下, 然而看起来还反而更加慢了
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        bfs(root, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void bfs(TreeNode* root, vector<vector<int>>& res){
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> level;
        while(!qu.empty()){
            int levelNum = qu.size();
            while(levelNum>0){
                TreeNode* node = qu.front();
                qu.pop();
                level.push_back(node->val);
                if(node->left){
                    qu.push(node->left);
                } 
                if(node->right){
                    qu.push(node->right);
                } 
                levelNum--;
            }
            res.push_back(level);
            level.clear();
        }
    }
};