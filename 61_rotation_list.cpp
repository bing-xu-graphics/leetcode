/**
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
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
//method1  好多特殊情况 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 ) return head;
        ListNode* newHead = head;
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        if(k%n==0) return head;
        int cnt = n - k%n;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        while(cnt>0){
            newHead = newHead->next;
            prev = prev->next;
            cnt--;
        }
        tail->next = head;
        prev->next = nullptr;
        return newHead;
    }
};

//method2 稍微简化掉一点点
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 ) return head;
        ListNode* newHead = head;
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        if(k%n==0) return head;
        int cnt = n - k%n -1;
        // ListNode* prev = new ListNode(0);
        // prev->next = head;
        while(cnt>0){
            newHead = newHead->next;
            // prev = prev->next;
            cnt--;
        }
        ListNode* res = newHead->next;
        tail->next = head;
        newHead->next = nullptr;
        return res;
    }
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 ) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int len=1;
        while(fast->next){
            fast = fast->next;
            len ++;
        }
        fast->next = head;
        int t = len - k%len -1;
        for(int i=0;i<t;++i){
            slow = slow->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        return newHead;
    }
};