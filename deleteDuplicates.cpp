/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-31
Description : leetcode 83. Remove Duplicates from Sorted List
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
    ListNode* cur = head, *last = head;
    while(cur = cur -> next){
        if(cur -> val == last -> val) {
            last -> next = cur -> next;
        }
        else {
            last = cur;
        }
        
    }
    return head;
}