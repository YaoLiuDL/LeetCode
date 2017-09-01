/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-9-1
Description : leetcode 86. Partition List 
********************************************************************/

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* newHead = new ListNode(0);
    newHead -> next = head;
    ListNode* l_end, *r_start, *cur = newHead;
    //find the first element greater than x,
    //store the l_end and r_start
    while(cur -> next && cur -> next -> val < x){
        cur = cur -> next;
    }
    if(!cur -> next) return newHead -> next;
    l_end = cur;
    r_start = cur -> next;

    //traverse the rest linked list,
    //if the element grater than x, insert it to the position 
    //between l_end and r_start, else continue.
    ListNode* slow = r_start, *fast = slow -> next;
    while(fast){
        if(fast -> val < x){
            slow -> next = fast -> next;
            l_end -> next = fast;
            fast -> next = r_start;
            l_end = fast;
        }else{
            slow = fast;
        }
        fast = slow -> next;
    }

    return newHead -> next;
}