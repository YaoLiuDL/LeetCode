/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-9-3
Description : leetcode 147. Insertion Sort List  
********************************************************************/

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if(!head || !head -> next) return head;
    ListNode* newHead = new ListNode(0);
    newHead -> next = head;
    ListNode* p1 = newHead -> next, *p2 = head -> next, *last = newHead, *candinate = p2;
    head -> next = NULL;
    while(p2){
        while(p1){
            if(p1 -> val > candinate -> val) break;
            last = p1;
            p1 = p1 -> next;
        }
        last -> next = candinate;
        p2 = p2 -> next;
        candinate -> next = p1;
        
        candinate = p2;
        p1 = newHead -> next;
        last = newHead;
    }

    return newHead -> next;
}

int main(){
    ListNode* head = new ListNode(3);
    head -> next = new ListNode(4);
    head -> next -> next = new ListNode(1);
    insertionSortList(head);
    return 0;
}