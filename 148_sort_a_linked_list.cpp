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
#include "utils.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* end = head;
        while(end->next) end = end->next;
        quicksort(head, end);
        return head;
    }

    void quicksort(ListNode* head, ListNode* end){
        if(!head || head==end) return;
        ListNode* pivot = partition(head, end);
        // printf("pivot->val = %d\n", pivot->val);
        // printList(head);
        ListNode* prev_end = head;
        if(head!= pivot){
            while(prev_end->next != pivot) prev_end = prev_end->next;
            quicksort(head, prev_end);
        }
        if(end!=pivot){
            quicksort(pivot->next, end);
        }
        
    }
    ListNode* partition(ListNode* head, ListNode* end){
        if(!head || head == end) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=end && fast->next!=end){
            slow = slow->next;
            fast = fast->next->next;
        }
        int _tmp = slow->val;
        slow->val = end->val;
        end->val = _tmp;
        ListNode* pivot = end;
        // while(pivot->next) pivot = pivot->next; 
        ListNode* smaller = head;
        ListNode* mover = head;
        while(mover!=end){
            if(mover->val<=pivot->val){
                int tmp = smaller->val;
                smaller->val = mover->val;
                mover->val = tmp;
                smaller = smaller->next;
            }
            mover = mover->next;
        }
        int tmp = smaller->val;
        smaller->val = pivot->val;
        pivot->val = tmp;
        return smaller;
    }
    void printList(ListNode* head){
        while(head){
            printf("%d->", head->val);
            head = head->next;
        }
    }
};