/********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-30
Description : 23. Merge k Sorted Lists 
********************************************************************/

#include <vector>
#include <queue>
#include <cstddef>

using std::vector;
using std::priority_queue;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct compartor{
    bool operator()(const ListNode* l, const ListNode* r){
        return l -> val < r -> val;
    }
};



ListNode* mergeKLists(vector<ListNode*>& lists) {
    //a min heap of k size
    priority_queue<ListNode*, vector<ListNode*>, compartor> pq;
    //put the head nodes of all lists in the max heap
    for(auto list : lists){
        if(list) pq.push(list);
    }

    if(pq.empty()) return NULL;
    ListNode* head = pq.top();
    pq.pop();

    if(head -> next) pq.push(head -> next);

    ListNode* cur = head;

    while(!pq.empty()){
        cur -> next = pq.top();
        cur = cur -> next;
        pq.pop();
        if(cur -> next)
            pq.push(cur ->  next);
    }

    return head;
}

int main(){
    ListNode* head = new ListNode(0);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(5);
    vector<ListNode*> lists = {head};
    ListNode* res = mergeKLists(lists);
    return 0;
}