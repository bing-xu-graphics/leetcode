/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
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
    void printLinkedList(ListNode* head){
        while(head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //check group number
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* segment_node = head;
        ListNode* segment_prev = res;
        while(segment_node){
            ListNode* tmp = segment_node;
            int i=0;
            while(i<k && tmp){
                tmp = tmp->next; i++;
            }
            
            if(i==k){ //reverse the group
                ListNode* current = segment_node;
                ListNode* prev = nullptr;
                for(int j=0;j<k;++j){
                    ListNode* tempNext = current->next;
                    current->next = prev;
                    prev = current;
                    current = tempNext;
                }
                // printLinkedList(res->next);
                segment_prev->next = prev;
                segment_node->next = current;
                segment_prev = segment_node;
                segment_node = current;
                // printLinkedList(res->next);
                // printf("seg_prev=%d, seg_node=%d, prev=%d, current=%d\n", segment_prev->val, segment_node->val, prev->val, current->val);
            }else{//return
                return res->next;
            }
        }
        return res->next;
    }
};