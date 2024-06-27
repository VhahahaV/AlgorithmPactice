//
// Created by VhahahaV on 2024/4/21.
//
//  Definition for a binary tree MemPage.
//22min
#include "bits/stdc++.h"

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len == 1)
            return new TreeNode(preorder[0]);
        if (len == 0)
            return nullptr;
        vector<int> left_in;
        vector<int> left_pre;
        int i = 0;
        int val_ = preorder[0];
        while(inorder[i] != val_){
            left_in.emplace_back(inorder[i]);
            left_pre.emplace_back(preorder[i+1]);
            i++;
        }
        i++;
        vector<int> right_in;
        vector<int> right_pre;
        while(i < len){
            right_in.emplace_back(inorder[i]);
            right_pre.emplace_back(preorder[i]);
            i++;
        }
        TreeNode *node = new TreeNode(val_,buildTree(left_pre,left_in),buildTree(right_pre,right_in));
        return node;
    }

};

int main(){
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    Solution solution;
    solution.buildTree(preorder,inorder);
    return 0;
}