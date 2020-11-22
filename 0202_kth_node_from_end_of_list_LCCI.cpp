/**
 * Implement an algorithm to find the kth to last element of a singly linked list. Return the value of the element.

Note: This problem is slightly different from the original one in the book.

Example:

Input:  1->2->3->4->5 和 k = 2
Output:  4
Note:

k is always valid.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//method1  最简单的 先走一遍看有几个node
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        int n=0;
        ListNode* mover = head;
        while(mover){
            n++;
            mover = mover->next;
        }
        int m = n-k;
        for(int i=0;i<m;++i){
            head = head->next;
        }
        return head->val;
    }
};
//method2 用了一个stack 都先保存下来

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        while(k>1){
            st.pop();
            k--;
        }
        return st.top();
    }
};

//method3 two pointers, the distance is k  两个快慢指针之间是目标的一个距离
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(k>0){
           fast = fast->next;
           k--;
       } 
       while(fast){
           fast = fast->next;
           slow = slow->next;
       }
       return slow->val;

    }
};