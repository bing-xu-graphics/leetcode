//this is the same as the 206
/**
 * Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // return revereseList_iterative(head);
        return revereseList_recursive(head);
    }

    ListNode* revereseList_iterative(ListNode* head){
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
    ListNode* revereseList_recursive(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* node = revereseList_recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};