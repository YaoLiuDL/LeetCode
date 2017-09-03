/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-9-3
Description : 143. Reorder List 
********************************************************************/

#include <cstddef>
#include <unordered_map>

using std::unordered_map;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Method 1:
 * Use a map to store the mapping from the position to node pointer
 * time : O(n), space : O(n)
 */
void reorderList1(ListNode* head) {
    //the mapping from the position to node pointer
    unordered_map<int, ListNode*> map;
    int count = 0;
    ListNode* cur = head;
    while(cur){
        map[count++] = cur;
        cur = cur -> next;
    }

    int i = 1, j = count - 1;
    cur = head;
    while(i < j){
        cur -> next = map[j--];
        cur -> next -> next = map[i++];
        cur = cur -> next -> next;
    }
    if(j > -1) map[j] -> next = NULL;
}

/**
 * Method 2:
 * It needs two scan, first is to get the number of the nodes,
 * second is to  assgin.
 * time : O(n), space : O(1)
 */
 void reorderList2(ListNode* head) {
    if(!head) return ;
    ListNode* p1 = head, *p2 = head -> next;
    //get the middle node
    while(p2 && p2 -> next){
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }
    p2 = p1 -> next;
    p1 -> next = NULL;

    //reverse the second part
    ListNode* last = p2, *cur, *next;
    if(!p2) return;
    cur = p2 -> next;
    while(cur){
        next = cur -> next;
        cur -> next = last;
        last = cur;
        cur = next;
    }
    p2 -> next = NULL;
    

    //merge two linked list
    p1 = head;
    p2 = last;
    while(p1 && p2){
        ListNode* tmp = p1 -> next;
        p1 = p1 -> next = p2;
        p2 = tmp;
    }
}



int main(){
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    reorderList2(head);
    return 0;
}