#include "utils.h"
/**
 * Given an array of linked-lists lists, each linked list is sorted in ascending order.

Merge all the linked-lists into one sort linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
       ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 /**
  * 这里可以学到的就是:
  * 1) 如何实现min heap 和 max_heap
  * max_heap 可以天生用 std::priority_queue<int> 来实现
  * min_heap 则可以用  std::priority_queue<int, vector<int>, std::greater<int>> 来实现
  * 
  * 2), 就是, 如何保留head
  * ListNode head;
  * ListNode* tail = &head;
  * 后面只要不断地构造tail = new ListNode(val); tail = tail->next;
  * 然后返回  head.next 就可以
  * 
  * 3) 想改变 一个queue 即pop push 之类的, 一定要记得 copy by reference ,一开始这里就错了.
  */ 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode res;
        ListNode* mover = &res;
        if(lists.size()<1) return nullptr;
        unordered_map<int, queue<int>> value_2_list_idx;
        priority_queue<int, vector<int>, std::greater<int>> min_heap;
        int n = lists.size();
        
        for(int i=0;i<n; ++i){
            if(lists[i]!=nullptr){
                min_heap.push(lists[i]->val);
                if(value_2_list_idx.find(lists[i]->val)== value_2_list_idx.end()){
                    queue<int> vec; vec.push(i);
                    value_2_list_idx[lists[i]->val] = vec;
                }else{
                    value_2_list_idx[lists[i]->val].push(i);
                }
                
                lists[i] = lists[i]->next;
            }
        }
        // printf("lalala min_heap.size()=%d \n", min_heap.size());
        int original_length = min_heap.size();
        while(!min_heap.empty()){
            int min_value = min_heap.top();
            // if(mover==nullptr){
            //     mover = new ListNode(min_value);
            //     printf("add new value = %d\n", min_value);
            // } 
            // else{
                mover->next = new ListNode(min_value);
                // printf("add new value = %d\n", min_value);
            // }
            mover = mover->next;
            min_heap.pop();
            queue<int>& vec = value_2_list_idx[min_value];
            int list_idx = vec.front(); vec.pop();
            if(lists[list_idx]!=nullptr){
                int val = lists[list_idx]->val;
                min_heap.push(val);
                lists[list_idx] = lists[list_idx]->next;
                //insert the new mapping
                if(value_2_list_idx.find(val)== value_2_list_idx.end()){
                    queue<int> vec; vec.push(list_idx);
                    value_2_list_idx[val] = vec;
                }else{
                    value_2_list_idx[val].push(list_idx);
                }
            }
        }

        return res.next;
    }
};


//官方解答:::  居然自己造出了一个数据结构, 然后这么简单!!!!
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
