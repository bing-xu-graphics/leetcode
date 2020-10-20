#include "utils.h"


/**Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* res = &head;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr && l2!=nullptr){
                if(l1->val < l2->val){
                    res->next = new ListNode(l1->val);
                    l1 = l1->next;
                } 
                else{
                    res->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }else if(l1!=nullptr){
                res->next = new ListNode(l1->val);
                l1 = l1->next;
            }else if(l2!=nullptr){
                res->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            res = res->next;
        }
        return head.next;
    }
};