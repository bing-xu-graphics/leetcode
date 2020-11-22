#include "utils.h"
/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* slow = head; ListNode* fast = head->next;
        bool duplicate_flag = false;
        while(fast){
            if(slow->val == fast->val){
                fast = fast->next;
                duplicate_flag = true;
            }else{
                if(duplicate_flag){
                    prev->next = fast;
                    slow = fast;
                    fast = slow->next;
                    duplicate_flag = false;
                }else{
                    prev = prev->next;
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        if(duplicate_flag)prev->next = fast;
        return newHead->next;


    }
};