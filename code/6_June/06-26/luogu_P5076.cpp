//
// Created by VhahahaV on 2024/6/26.
//
#include <iostream>
#include <vector>

using namespace std;

struct node{
    node *left, *right;
    int size;
    int prio;
    int val;
    node ( int v) :left(nullptr),right(nullptr),val(v),prio(rand()),size(1){}
};
struct Treap{
    node *mHead = nullptr;
    pair<node *,node *> split(node *r , int key){
        if(!r) return make_pair(nullptr, nullptr);
        if(r->val > key){
            auto res = split(r->left,key);
            r->left = res.second;
            updateSize(r);
            return make_pair(res.first,r);
        }
        else{
            auto res = split(r->right,key);
            r->right = res.first;
            updateSize(r);
            return make_pair(r,res.second);
        }
    }
    void updateSize(node *r){
        int res = 1;
        if(r->left)
            res+=r->left->size;
        if(r->right)
            res+=r->right->size;
        r->size = res;
    }

    node* merge(node *u, node *v){
        if(u == nullptr) return v;
        if(v == nullptr) return u;
        if(u -> prio < v -> prio){
            u -> right = merge(u -> right, v);
            updateSize(u);
            return u;
        }else{
            v -> left = merge(u, v -> left);
            updateSize(v);
            return v;
        }
    }

    void insert( node *x ){
        auto key1 = x->val;
        auto res = split(mHead,key1);
        res.first = merge(res.first,x);
        mHead = merge(res.first,res.second);
    }

    int getRank( int key){
        auto res = split(mHead,key);
        int ans = res.first->size;
        merge(res.first,res.second);
        return ans;
    }

    int getNumByRank(int rank){
        auto cur = mHead;
        while(cur){
            int curRank=1;
            if(cur->left)
                curRank+=cur->left->size;
            if(curRank < rank){
                cur = cur->right;
                rank -= curRank;
            }
            else if(curRank > rank){
                cur = cur -> left;
            }
            else
                break;
        }
        if(cur)
            return cur->val;
        else
            return -1;
    }

    int getPre(int key){
        auto res = split(mHead,key-1);
        int ans;
        auto leftTrees = res.first;
        if(leftTrees){
            while (leftTrees->right)
                leftTrees = leftTrees->right;
            ans =  leftTrees->val;
        }
        else
            ans =  -2147483647;
        merge(res.first,res.second);
        return ans;
    }

    int getPost( int key){
        auto res = split(mHead,key);
        int ans;
        auto rightTrees = res.second;
        if(rightTrees){
            while (rightTrees->left)
                rightTrees = rightTrees->left;
            ans = rightTrees->val;
        }
        else
            ans = 2147483647;
        merge(res.first,res.second);
        return ans;
    }

};

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n ;
    cin >>n;
    Treap treap;
    while (n--){
        int op,x;
        cin >>op >>x;
        switch(op){
            case 1:
                cout << treap.getRank(x)<< '\n';
                break;
            case 2:
                cout << treap.getNumByRank(x)<< '\n';
                break;
            case 3:
                cout << treap.getPre(x)<< '\n';
                break;
            case 4:
                cout << treap.getPost(x) << '\n';
                break;
            case 5:
                treap.insert(new node(x));
                break;
        }
    }
    return 0;
}