/****************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : 21. Merge Two Sorted Lists 
****************************************************************/

#include <cstddef>

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0), *cur = head;

    //add l1 and l2 to the new linked list
    while(l1 && l2){
        if(l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
        }
        else {
            cur -> next = l2;
            l2 = l2 -> next;
        }
        cur = cur -> next;
    }
    
    //cur->next points to l1 when l1 is not NULL, or points to l2.
    cur -> next = l1 ? l1 : l2;

    return head -> next;
}

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    ListNode* res = mergeTwoLists(l1, l2); 
    return 0;
}