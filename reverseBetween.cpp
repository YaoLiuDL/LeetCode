/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-9-1
Description : leetcode 92. Reverse Linked List II 
********************************************************************/

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* newHead = new ListNode(0);
    newHead -> next = head;
    ListNode* l_end = newHead, *m_start = NULL, *m_end = NULL, *r_start = NULL, *cur = newHead -> next, *last = newHead, *next;
    int idx = 1;
    while(cur){
        next = cur -> next;
        if(idx == m - 1) l_end = cur;
        if(idx == m) m_start = cur;
        if(idx > m && idx <= n){
            cur -> next = last;
        }
        if(idx == n) m_end = cur;
        if(idx == n + 1) r_start = cur;
        
        last = cur;
        cur = next;
        idx++;
    } 

    if(m_end)
        l_end -> next = m_end;
    if(m_start)
        m_start -> next = r_start;

    return newHead -> next;
}