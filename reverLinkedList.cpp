#include "utils.h"
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int v): val(v),next(nullptr){};
    ListNode(int v, ListNode* _next): val(v), next(_next){};
}

void reverseLinkedList(ListNode* node, int m , int n){
    if(!node || m>=n) return node;
    ListNode* head = node;
    for(int i=0;i<m-1;++i){
        if(!node) return head;
        node = node->next;
    }
    ListNode* prev = node;
    if(!node) return head;
    node = node->next;
    for(int i=m;i<n;++i){
        if(node==nullptr) return head;
        if(node->next==nullptr) return head;
        ListNode* tmp = node->next->next;
        node->next->next = node;
        prev->next = node->next;
        node->next = tmp;
        node = node->next;
    }
    


}

int main(){
    printf("Hello world\n");
    ListNode head;
    ListNode* node = & head;
    node->next = new ListNode(7);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    node->next = new ListNode(2);
    
    reverseLinkedList(head.next, 2, 3);
    ListNode* test = head.next;
    while(test!=nullptr){
        printf("%d ", test->val);
    }
    printf("Done here\n");
}