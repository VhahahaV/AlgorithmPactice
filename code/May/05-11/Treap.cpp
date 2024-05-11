//
// Created by VhahahaV on 2024/5/11.
//
#include "bits/stdc++.h"

using namespace std;

#include <bits/stdc++.h>

template<
        class Key,
        class T,
        class Compare = std::less<Key>
>
class Treap{
private:
    typedef pair<const Key, T> value_type;
    struct node{
        value_type key;
        int siz;
        int hei;
        int priority;
        node *lc , *rc;
        node(const value_type& key_):key(key_),priority(rand()),hei(1),siz(1){}
    };
    typedef pair<node*,node*> pii;

    node *root;
    Compare cmp;
public:
    int height(node *r){
        if (!r) return 0;
        return r->hei;
    }
    int size(node *r){
        if (!r) return 0;
        return r->siz;
    }
    node *loc(node *r,const Key &key) const {
        while(r){
            if (cmp(key, r->key->first)) r = r->lc;
            else if (cmp(r->key->first, key)) r = r->rc;
            else break;
        }
        return r;
    }
    pii split(node *r, const Key &key){
        if(r == nullptr)  return make_pair(nullptr, nullptr);
//        key < r->key.first)
        if(cmp(key,r->key.first)){
            pii res = split(r->lc,key);
            r->lc = res.second;
            return make_pair(res.first,r);
        }
//        key >= r->key.first)
        else{
            pii res = split(r->rc, key);
            r->rc = res.first;
            return mkp(r, res.second);
        }
    }
    node *merge(node *u, node *v){
        if(u == nullptr) return v;
        if(v == nullptr) return u;
        if(u -> priority < v -> priority){
            u -> rc = merge(u -> rc, v);
            return u;
        }else{
            v -> lc = merge(u, v -> lc);
            return v;
        }
    }
    bool insert(node *x){
        auto key1 = x->key.first;
        pii res = split(root, key1);
        auto key2 = res.first->key.first;
//        如果key本来存在树中，则res.first.key.first应该为key
        if(!cmp(key1,key2) && !cmp(key2,key1))
            return false;
        else
            res.first = merge(res.first, x);
//        if(!find(root , key)) res.first = merge(res.first, new node(key));
        root = merge(res.first, res.second);
    }
    void erase(node *x){
//        o的右子树的根节点为key
        auto key = x->key.first;
        pii o = split(root, key - 1);
        pii p = split(o.second, key);
        delete p.first;
        root = merge(o.first, p.second);
    }
    node* getmin(node *cur){
        node *ret = cur;
        for (; cur != nullptr; ret = cur, cur = cur->lc) ;
        return ret;
    }
    node *getmax(node *cur) const {
        node *ret = cur;
        for (; cur != nullptr; ret = cur, cur = cur->rc) ;
        return ret;
    }
    node *prv(node *r,node *cur) const {
        if (cur->lc != nullptr) return getmax(cur->lc);
        else {
            if (!r) return nullptr;
            node *ans;
            if(cmp(r->key.first,cur->key.first)){
                ans = prv(r->rc,cur);
                if (!ans)
                    ans = r;
            }
            else{
                ans = prv(r->lc,cur);
            }
            return ans;
        }
    }
    node *suf(node *r,node *cur) const {
        if (cur->lr != nullptr) return getmin(cur->lr);
        else {
            if (!r) return nullptr;
            node *ans;
            if(cmp(cur->key.first,r->key.first)){
                ans = suf(r->lc,cur);
                if (!ans)
                    ans = r;
            }
            else{
                ans = suf(r->rc,cur);
            }
            return ans;
        }
    }


};
