//
// Created by CZQ on 2024/5/7.
//
/**
 * Definition for a binary tree MemPage.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
// 需要序列化
    unordered_map<string,int> cnt;
    vector<TreeNode*> ans;
    string dfs(TreeNode *root){
        if(!root)
            return "";
        string cur = to_string(root->val);
        string left = dfs(root->left);
        string right = dfs(root->right);
        cur = cur + "(" + left + ")(" + right + ")";
        if(cnt.count(cur)){
            if(cnt[cur] == 1)
                ans.emplace_back(root);
            cnt[cur]++;
        }
        else
            cnt[cur] = 1;
        return cur;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};