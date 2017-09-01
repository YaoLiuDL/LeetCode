/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-9-1
Description : leetcode 82. Remove Duplicates from Sorted List II 
********************************************************************/

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return head;
    ListNode* newHead = new ListNode(0);
    newHead -> next = head;
    ListNode* cur = newHead, *next = newHead;
    while(cur){
        next = cur -> next;
        if(!next) return newHead -> next;
        int val = next -> val;
        bool flags =false;
        while(next -> next && next -> next -> val == val){
            next = next -> next;
            cur -> next = next -> next;
            flags = true;
        }
        cur = flags ? cur : cur -> next;
    }
    return newHead -> next;
}