#include "utils.h"
/**
 * Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode res;
        ListNode* prev = &res;
        // prev->next = head;

        while(ptr1!=nullptr && ptr2!= nullptr){
            ListNode* tmp = ptr2->next;
            ptr2->next = ptr1;
            ptr1->next = tmp;
            prev->next = ptr2;
            prev = ptr1;
            ptr1 = tmp;
            if(ptr1!=nullptr)ptr2 = tmp->next;
        }
        return res.next;
    }
};