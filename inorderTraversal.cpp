/********************************
Copyright : CNIC
Author ; LiuYao
Date : 2017-8-23
Description : inorder traversal without recursive
********************************/

#include <vector>
#include <stack>

using std::vector；
using std::stack;

//Tree Node struct
struct TreeNode {
    int val;                         //node value
    TreeNode *left;                  //left child pointer
    TreeNode *right;                 //right child pointer
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  //construct
};
 

//Summary : inorder traversal
//Parameters : 
//  root : root node
//Return : inorder traversal vector
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode *> s;
    //initail the stack
    while(root != NULL) {
        s.push(root);
        root = root -> left;
    }

    //while the stack is not empty, pop the stack top to visit
    while(!s.empty()){
        TreeNode* top = s.top(); 
        s.pop();
        res.push_back(top -> val);
        //when popping the top element, add the right child of the top element
        //and add the left child of the right child of top element until the left child is null.
        TreeNode* cur = top -> right;
        while(cur != NULL){
            s.push(cur);
            cur = cur -> left;
        }
    }

    return res;
}