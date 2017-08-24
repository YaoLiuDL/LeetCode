/********************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-24
Description : deep copy of a special linked list
********************************************************/
#include <unordered_map>

using std::unordered_map;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode{
    int label;
    RandomListNode * next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Method 1 : 
 * use a hasttable to store the mapping from old node to new node, the space complexity is O(n),
 * and it needs two rounds.
 */
RandomListNode *copyRandomList1(RandomListNode *head) {
    //if the old linked list is empty, return NULL
    if(!head) return NULL;
    //store the mapping from the pointer of old linked list to the pointer of new linked list 
    unordered_map<RandomListNode*, RandomListNode*> map;
    RandomListNode* newHead = new RandomListNode(head -> label);
    map[head] = newHead;
    RandomListNode* next = head -> next, *node = newHead;
    // first step : generate all nodes and store the mapping from old pointer to new pointer
    while(next != NULL){
        RandomListNode* nextNode = new RandomListNode(next -> label);
        map[next] = nextNode;
        node -> next = nextNode;
        node = nextNode;
        next = next -> next;
    }

    // second step : assign to the random pointer of all new nodes by find up the mapping
    RandomListNode* oldNode = head;
    node = newHead;
    while(oldNode != NULL){
        node -> random = map[oldNode -> random];
        node = node -> next;
        oldNode = oldNode -> next; 
    }

    return newHead;
}

/**
 * Method 2 : 
 * link the new node to the old node, the space complexity is O(1),
 * and it needs three rounds.
 */
RandomListNode *copyRandomList2(RandomListNode *head) {
    RandomListNode* node = head;

    // First round :
    // copy all nodes and insert them into their source node
    while(node != NULL){
        RandomListNode* copy = new RandomListNode(node -> label);
        copy -> next = node -> next;
        node -> next = copy;
        node = copy ->next;
    }

    // Second round : 
    // assign the random pointer to the new linked list
    node = head;
    while(node != NULL){
        if(!node -> random) node -> next -> random = NULL;
        else node -> next -> random = node -> random -> next;
        node = node -> next -> next;
    }

    // Third round : 
    // remove the link between the source node and the copy node
    RandomListNode* newHead = new RandomListNode(0), *newNode = newHead;
    node = head;
    while(node != NULL){
        newNode -> next = node -> next;
        node -> next = node -> next -> next;
        node = node -> next;
        newNode = newNode -> next;
    }

    return newHead -> next;
}

/**
 * program entry
 */
int main(){
    RandomListNode* head = new RandomListNode(-1);
    RandomListNode* newHead = copyRandomList2(head);
    return 0;
}