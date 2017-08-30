/********************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : leetcode 19. Remove Nth Node From End of List 
********************************************************/

#include <vector>
#include <cstddef>

using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Method 1 : 
 * Use a vector to store the n + 1 pointers
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    //use a vector to store the n + 1 pointer from current pointer to back
    vector<ListNode *> pointers(n + 1, NULL);
    ListNode* cur = head;
    //traverse the linked list to get the n + 1 pointers from the end to back
    int idx = 0;
    while(cur){
        pointers[idx++ % (n + 1)] = cur;
        cur = cur -> next;
    }

    //pointers[idx] points to the (n + 1)th pointer from the end, 
    //pointers[idx + 2] points to the (n - 1)th pointer from the end
    if(!pointers[idx % (n + 1)]) return head -> next;
    pointers[idx % (n + 1)] -> next = pointers[(idx + 1) % (n + 1)] -> next;
    return head;
}

/**
 * Method 2: 
 * Use two pointers to mesure the length n
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode(0), *end = start, *newHead = start;
    start -> next = head;
    //let the length from start pointer to end pointer be n + 1 
    for(int i = 0; i < n; i++) end = end -> next;

    //when end -> next pointer equals to NULL, start pointer points 
    //to the (n + 1)th pointer from the end of the linked list
    while(end -> next){
        start = start -> next;
        end = end -> next;
    }

    //Remove the element which start next pointer points to.
    start -> next = start -> next -> next;
    return newHead -> next;
}

int main(){
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    ListNode* res = removeNthFromEnd(head, 1);
    return 0;
}