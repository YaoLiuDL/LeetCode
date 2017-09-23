#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct Node{
    string name;
    Node * left = NULL;
    Node * right = NULL;
    Node(string name):name(name){}
};


void find(Node* node, int& num){
    if(node -> left) {
        num++;
        find(node -> left, num);
    }
    if(node -> right) {
        num++;
        find(node -> right, num);
    }
}

int main(){
    int m, n, count=0;
    cin >> m >> n;
    string name;
    vector<Node*> nodes;
    unordered_map<string, int> map;
    while(cin >> name){
        // if(name == "") break;
        Node* node, *left, *right;
        if(map.find(name) != map.end()){
            node = nodes[map[name]];
        }
        else {
            map[name] = count++;
            node = new Node(name);
            nodes.push_back(node);
        }
        cin >> name;
        if(map.find(name) != map.end()){
            left = nodes[map[name]];
        }
        else{
            map[name] = count++;
            left = new Node(name); 
            nodes.push_back(left);
        }
        node -> left = left;
        cin >> name;
        if(name != "*"){
            if(map.find(name) != map.end()){
                right = nodes[map[name]];
            }
            else{
                map[name] = count++;
                right = new Node(name);
                nodes.push_back(right);
            }
            node -> right = right;
        }
    }

    count = 0;
    int num = 0;
    vector<string> res;
    for(auto node : nodes){
        num = 0;
        find(node, num);
        if(num >= n) {
            cout << node -> name << ' ';
            res.push_back(node -> name);
        }
    }

    return 0;
}
