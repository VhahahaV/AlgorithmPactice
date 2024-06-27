//
// Created by CZQ on 2024/5/7.
//
//Definition for a binary tree MemPage.
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
//inorder : < left this right>
// postorder : < left right this>
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = 0,n = postorder.size();
        while(inorder[i] != postorder[n-1] && i+1 < n)
            i++;
        TreeNode *root = new TreeNode(inorder[i]);
        // 左闭右开
        if (i){
            vector<int> il(inorder.begin(),inorder.begin()+i);
            vector<int> pl(postorder.begin(),postorder.begin()+i);
            root->left = buildTree(il,pl);

        }
        if (i != n-1){
            vector<int> ir(inorder.begin()+i+1,inorder.end());
            vector<int> pr(postorder.begin()+i,postorder.end()-1);
            root->right = buildTree(ir,pr);
        }

        return root;

    }
};


int main(){
    vector<int> inorder{2,3,1}, postorder{3,2,1};
    Solution solution;
    TreeNode* root = solution.buildTree(inorder,postorder);
    return 0;
}