/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : 23. Merge k Sorted Lists 
********************************************************************/

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode* newHead = new ListNode(0), *start = newHead;
    start -> next = head;
    ListNode* end = start, *cur, *last, *next, *end_next, *start_next;
    int i = 0;
    while(i++ < k && end){
        end = end -> next;
    }

    if(!end) return start -> next;

    while(end){
        end_next = end -> next;
        start_next = start -> next;
        last = start -> next;
        cur = last -> next;
        do{
            next = cur -> next;
            cur -> next = last;
            last = cur;
            cur = next;
        }while(cur != end_next);

        start -> next -> next = end_next;
        start -> next = end;
        
        start = start_next;
        end = start;
        i = 0;
        while(i++ < k && end){
            end = end -> next;
        }
    }

    return newHead -> next;
}

int main(){
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    ListNode* res = reverseKGroup(head, 3);
    return 0;
}