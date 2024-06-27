//
// Created by VhahahaV on 2024/6/27.
//

#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // val(left.size(),left,right.size(),right);

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string cur;
        cur+=to_string(root->val);
        cur.push_back('(');
        auto left = serialize(root->left);
        cur += to_string(left.size());
        cur.push_back(',');
        cur += left;
        cur.push_back(',');
        auto right = serialize(root->right);
        cur += to_string(right.size());
        cur.push_back(',');
        cur += right;
        cur.push_back(')');
        return cur;

    }
    pair<int,pair<string,string>> split(string data){
        // cout << "get data int split:" << data <<endl;
        int i = 0;
        string valStr="";
        int sign = 1;
        if(data[i] == '-'){
            sign = -1;
            i++;
        }
        int val= 0;
        while(isdigit(data[i])){
            // cout << "get i :" << i << endl;
            val = val*10 + (data[i++]-'0');
        }
        val*=sign;
        // cout << "get val: "<<val << endl;
        i++;
        string left,right;
        int leftLen=0,rightLen=0;
        while(isdigit(data[i])){
            leftLen = leftLen*10 + (data[i++]-'0');
        }
        i++;
        while(leftLen--){
            left.push_back(data[i++]);
        }
        // cout <<"get left : " <<left << endl;
        i++;
        while(isdigit(data[i])){
            rightLen = rightLen*10 + (data[i++]-'0');
        }
        i++;
        while(rightLen--){
            right.push_back(data[i++]);
        }
        // cout <<"get right : " <<right << endl;
        return make_pair(val,make_pair(left,right));
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        // cout << data << '\n';
        auto res = split(data);
        int val = res.first;
        string left = res.second.first,right = res.second.second;
        TreeNode* curNode = new TreeNode(val);
        if(!left.empty())
            curNode->left = deserialize(left);
        if(!right.empty())
            curNode->right = deserialize(right);
        return curNode;
    }
};
int main(){
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    head ->right -> right = new TreeNode(5);
    Codec codec;
    auto data=codec.serialize(head);
    auto newHead = codec.deserialize(data);

    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));