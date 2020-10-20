/**
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
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
//method1 这个是可以一般化地作用域所有的binary tree , 而没有利用已经是binray search tree 的心得
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        vector<int> vals;
        dfs_find_vals(root, vals);
        sort(vals.begin(), vals.end());
        vector<int> larger_sum(vals.size(), 0);
        larger_sum[vals.size()-1] = vals[vals.size()-1];
        for(int i=vals.size()-2; i>=0;--i){
            larger_sum[i] = vals[i] + larger_sum[i+1];
        }
        dfs_get_results(root, vals,larger_sum);
        return root;

        
    }

    void dfs_find_vals(TreeNode* root ,vector<int>& vals){
        if(!root) return;
        vals.push_back(root->val);
        dfs_find_vals(root->left, vals);
        dfs_find_vals(root->right, vals);
    }

    void dfs_get_results(TreeNode* root, vector<int>& vals, vector<int>& larger_sum){
        if(!root) return;
        root->val = larger_sum[binary_search(vals, root->val)];
        dfs_get_results(root->left, vals, larger_sum);
        dfs_get_results(root->right, vals, larger_sum);
    }

    int binary_search(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};

//method2  直接利用BST 的性质, 
//先traverse right tree, then the node, then the left tree


class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        dfs(root, 0);
        return root;
    }

    int dfs(TreeNode* root, int add){
        //traverse right, root, then left
        if(!root) return 0;
        int sum = root->val;
        int right_sum = dfs(root->right, add);
        root->val += right_sum+add;
        int left_sum = dfs(root->left, root->val);
        return sum + right_sum + left_sum;
    }
};

//不用recursion, 用stack 进行反向的中序遍历

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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* node = root;
        stack<TreeNode*> st;
        int current_larger_sum = 0;
        while(node || !st.empty()){
            while(node){
                if(!node->right){
                    node->val += current_larger_sum;
                } 
                st.push(node);
                node = node->right;
            }
        
            node = st.top();
            st.pop();
            if(node->right){
                // node->val += node->right->val; //一开始是这里错误了
                node->val += current_larger_sum; 
            }
            
            current_larger_sum = node->val;
            node = node->left;
        }
        return root;
    }

    
};