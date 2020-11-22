/**
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
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

//method1 use reversing

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reversed_l1 = reverseList(l1);
        ListNode* reversed_l2 = reverseList(l2);
        ListNode head;
        ListNode* mover = &head;
        int add = 0, remain = 0;
        while(reversed_l1 && reversed_l2){
            int sum = reversed_l1->val + reversed_l2->val + add;
            add = sum / 10;
            remain = sum % 10;
            mover->next = new ListNode(remain);
            mover = mover->next;
            reversed_l1 = reversed_l1->next;
            reversed_l2 = reversed_l2->next;
        }
        while(reversed_l1){
            int sum = reversed_l1->val + add;
            add = sum / 10;
            remain = sum % 10;
            mover->next = new ListNode(remain);
            mover = mover->next;
            reversed_l1 = reversed_l1->next;
        }
        while(reversed_l2){
            int sum = reversed_l2->val + add;
            add = sum / 10;
            remain = sum % 10;
            mover->next = new ListNode(remain);
            mover = mover->next;
            reversed_l2 = reversed_l2->next;
        }
        if(add!=0){
            mover->next = new ListNode(add);
        }
        ListNode* res = reverseList(head.next);
        return res;
    }

    ListNode* reverseList(ListNode* head){
        if(!head) return head;
        ListNode* current = nullptr;
        ListNode* next = head;
        while(next){
            ListNode* node = next->next;
            next->next = current;
            current = next;
            next = node;
        }
        return current;
    }
};

//method 2 using stack

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st_l1;
        stack<int> st_l2;
        while(l1){
            st_l1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st_l2.push(l2->val);
            l2 = l2->next;
        }
        
        int add = 0, remain = 0;
        ListNode* prev = nullptr;
        // ListNode head;
        // ListNode* head_ptr = &head;
        while(!st_l1.empty() && !st_l2.empty()){
            int sum = st_l1.top() + st_l2.top() + add;
            add = sum/10;
            remain = sum % 10;
            ListNode* node = new ListNode(remain);
            node->next = prev;
            prev = node;
            st_l1.pop();
            st_l2.pop();
        }
        while(!st_l1.empty()){
             int sum = st_l1.top()  + add;
            add = sum/10;
            remain = sum % 10;
            ListNode* node = new ListNode(remain);
            node->next = prev;
            prev = node;
            st_l1.pop();
        }
        while(!st_l2.empty()){
            int sum = st_l2.top() + add;
            add = sum/10;
            remain = sum % 10;
            ListNode* node = new ListNode(remain);
            node->next = prev;
            prev = node;
            st_l2.pop();
        }
        if(add!=0){
            ListNode* node = new ListNode(add);
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};