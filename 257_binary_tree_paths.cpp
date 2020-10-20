/**
 * Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> currentPath;
        dfs(root, currentPath, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& currentPath, vector<string>&res ){
        if(!root) return;
        if(!root->left && !root->right){
            currentPath.push_back(root->val);
            res.push_back(anserParser(currentPath));
            currentPath.pop_back();
            return;
        }
        
        if(root->left){
            currentPath.push_back(root->val);
            dfs(root->left, currentPath, res);
            currentPath.pop_back();
        }
        if(root->right){
            currentPath.push_back(root->val);
            dfs(root->right, currentPath, res);
            currentPath.pop_back();
        }
    }

    string anserParser(vector<int>& path){
        string str;

        for(auto iter=path.begin(); iter!=path.end();++iter){
            str += to_string(*iter)+"->";
        }

        return str.substr(0,str.size()-2);
    }
};