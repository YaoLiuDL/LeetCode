/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : 23. Merge k Sorted Lists 
********************************************************************/

#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*> pq;
    for(auto list : lists){
        pq.push(list);
    }

    // ListNode* head = pq.
}