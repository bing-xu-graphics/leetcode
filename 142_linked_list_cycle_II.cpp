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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast!=nullptr && slow!=fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast) return nullptr;
            fast = fast->next;
        }
        if(!fast) return nullptr;
        ListNode* node = head;
        while(node!=slow){
            node = node->next;
            slow = slow->next;
        }
        return node;

    }
};