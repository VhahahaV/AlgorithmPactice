//
// Created by CZQ on 2024/5/7.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode *ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return false;
        bool l = dfs(root->left,p,q);
        bool r = dfs(root->right,p,q);
        if((l&&r) || ((root->val==p->val) || (root->val==q->val))&&(l||r) )
            ans = root;
        return l ||r || (root->val==p->val) || (root->val==q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};