/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
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


//method 1
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* noLessHead = new ListNode(0);
        ListNode* noless = noLessHead;
        while(head){
            if(head->val < x){
                less->next = new ListNode(head->val);
                less = less->next;
            }else{
                noless->next = new ListNode(head->val);
                noless = noless->next;
            }
            head = head->next;
        }
        less->next = noLessHead->next;
        return lessHead->next;
    }
};

//method 2  这是一个类似于数组的partition, 这个是无法保证order的, 所以不对.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = head;
        ListNode* mover = head;
        while(mover){
            if(mover->val >=x){
                mover = mover->next;
                continue;
            }else{
                int tmp = left->val;
                left->val = mover->val;
                mover->val = tmp;
                mover = mover->next;
                left = left->next;
            }
        }
        return head;
    }
};

//把后面的那个小的插入到前面来
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* left = prev;
        ListNode* mover = head;
        while(mover){
            if(mover->val >=x){
                mover = mover->next;
                continue;
            }else{
                
                ListNode* tempNext = mover->next;
                ListNode* newNode = new ListNode(mover->val);
                newNode->next = left->next;
                left->next = newNode;
                if(!tempNext){
                    printf("%d \n", mover->val); //这个错误在这里, 由于没有mover 前面一个node 所以无法把mover 去掉
                    mover = nullptr;
                } 
                else{
                    mover->val = tempNext->val;
                    mover->next = mover->next->next;
                    mover = mover->next;
                }
                left = left->next;
            }
        }
        return prev->next; //why this cannot be head
    }
};

//method3 于是这里记录前面的一个
//不用新的一个new ListNode, 而是把后面的node 移动到前面来. 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* left = prev;
        ListNode* mover = prev;
        while(mover->next){
            if(mover->next->val >=x){
                mover = mover->next;
                continue;
            }else{
                if(left->next == mover->next){
                    left = left->next;
                    mover = mover->next;
                    continue;
                }
                //这里不应该swap , 应该全部后移动
                ListNode* tempNext = mover->next->next;
                mover->next->next = left->next;
                left->next = mover->next;
                mover->next = tempNext;
                left = left->next;
            }
        }
        return prev->next; //why this cannot be head
    }
};