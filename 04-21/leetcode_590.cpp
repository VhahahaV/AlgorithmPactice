//
// Created by VhahahaV on 2024/4/21.
//

// Definition for a Node.
#include "bits/stdc++.h"

using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> orders;
    vector<int> postorder(Node* root) {
        post(root);
        return orders;
    }

    void post(Node* root) {
        if(!root)
            return ;
        if(root->children.size() == 0){
            orders.emplace_back(root->val);
            return;
        }
        else{
            for(auto &node : root->children){
                postorder(node);
            }
            orders.emplace_back(root->val);
        }
    }
};