/*******************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : leetcode 24. Swap Nodes in Pairs
*******************************************************/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* start = new ListNode(0), *cur = start;
    cur -> next = head;

    ListNode* first, *second;

    while(cur && (first = cur -> next) && (second = cur -> next -> next)){
        cur -> next = second;
        first -> next = second -> next;
        second -> next = first;
        cur = first;
    }
    
    return start -> next;
}