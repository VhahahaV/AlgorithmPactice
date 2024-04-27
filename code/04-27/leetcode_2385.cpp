//
// Created by CZQ on 2024/4/27.
//
#include "bits/stdc++.h"

using namespace std;

////unordered_map 和 unordered_set 的用法可以参考一下链接： https://blog.csdn.net/lzq8090/article/details/129788666

//Definition for a binary tree node.
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
    int valHeight,val;

    int amountOfTime(TreeNode* root, int start) {
//        val = start;
//        int rightHeight=0,leftHeight=0;
//        if(root->right)
//            rightHeight = getHeight(root->right);
//        if(root->left)
//            leftHeight = getHeight(root->left);
//        if(val == root->val)
//            valHeight = rightHeight;
//        return max(valHeight,(leftHeight+rightHeight)-valHeight);

        unordered_map<int,vector<int>> graph;

        ////如果指定了函数的类别，就可以使用递归调用dfs
        function<void(TreeNode *)> dfs = [&](TreeNode  *node) ->void {
            for(auto child : vector<TreeNode *>{node->right,node->left}){
                if (child != nullptr){
                    graph[node->val].push_back(child->val);
                    graph[child->val].push_back(node->val);
                    dfs(child);
                }
            }
        };
        dfs(root);
        queue<pair<int,int>> queue1;
        queue1.emplace(start,0);
        unordered_set<int> visited;
        visited.insert(start);
        int time = 0;
        while(!queue1.empty()){
            auto arr = queue1.front();
            queue1.pop();
            int nodeVal = arr.first;
            time = arr.second;
            for(auto childVal : graph[nodeVal]){
                 if(!visited.count(childVal)){
                     queue1.emplace(childVal,time+1);
                     visited.insert(childVal);
                 }
            }
        }
        return time;
    }

//  直接求两个树高来求差地解决方案没有考虑到数的拓扑结构，只能A 80%的案例
    int getHeight(TreeNode *root){
        if (!root)
            return 0;
        else{
            int res = max(getHeight(root->left),getHeight(root->right)) + 1;
            if(root->val == val)
                valHeight = res - 1;
            return res;
        }
    }


};

int main(){

    return 0;
}