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

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* start = new ListNode(0), *slow = start, *fast = start;
    start -> next = head;

    for(int i = 0; i < k; i++){
        if(!fast) return head;
        fast = fast -> next;
    }

    if(!fast) return head;

    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }

    if(slow == start) return head;
    fast -> next = head;
    head = slow -> next;
    slow -> next = NULL;

    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    ListNode* res = rotateRight(head, 2);
    return 0;
}