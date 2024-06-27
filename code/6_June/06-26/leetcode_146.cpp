//
// Created by VhahahaV on 2024/6/26.
//
#include <bits/stdc++.h>

using namespace std;

// class LRUCache {
//     map<int,int> mCache;
//     struct MemPage{
//         MemPage *last = nullptr;
//         MemPage *next = nullptr;
//         int key;
//         MemPage(MemPage *l ,MemPage *n , int k):last(l),next(n),key(k){}
//     };
//     map<int,*MemPage> nodeCache;
//     MemPage *lastestUseNode;
//     int mNums;
//     int mCap;
// public:
//     LRUCache(int capacity) {
//         mNums = 0;
//         mCap = capacity;
//         lastestUseNode = nullptr;
//     }

//     int get(int key) {
//         if(mCache.count(key)){
//             useKey(key);
//             return mCache[key];
//         }
//         else
//             return -1;
//     }

//     void put(int key, int value) {
//         if(!mCache.count(key))
//             mNums++;
//         useKey(key);
//         mCache[key] = value;
//     }

//     void useKey(int key){

//         if(!lastestUseNode){
//             lastestUseNode = new MemPage(nullptr,nullptr,key);
//         }
//         else{
//             auto cur = lastestUseNode;
//             lastestUseNode = new MemPage(cur,nullptr,key);
//             cur ->next = lastestUseNode;
//             if(mCache.count(key)){
//                 cur = lastestUseNode;
//                 while(cur->last){
//                     if(cur->last->key == key){
//                         auto rm = cur->last;
//                         cur->last = rm->last;
//                         if(rm->last)
//                             rm->last->next = cur;
//                         delete rm;
//                         break;
//                     }
//                     cur = cur->last;
//                 }
//             }
//         }

//         if(mNums > mCap){
//             auto cur = lastestUseNode;
//             while(cur->last != nullptr)
//                 cur = cur->last;
//             cur->next->last = nullptr;
//             auto rmKey = cur->key;
//             mCache.erase(rmKey);
//             delete cur;
//             mNums--;
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCache {
    map<int,int> mCache;
    struct node{
        node *last = nullptr;
        node *next = nullptr;
        int key;
        node(node *l ,node *n , int k):last(l),next(n),key(k){}
    };
    map<int,node*> nodeCache;
    node *lastestUseNode;
    int mNums;
    int mCap;
    int lastUsedKey;
public:
    LRUCache(int capacity) {
        lastUsedKey = -1;
        mNums = 0;
        mCap = capacity;
        lastestUseNode = nullptr;
    }

    int get(int key) {
        if(mCache.count(key)){
            useKey(key);
            return mCache[key];
        }
        else
            return -1;
    }

    void put(int key, int value) {
        if(!mCache.count(key))
            mNums++;
        useKey(key);
        mCache[key] = value;
    }

    void useKey(int key){

        if(!lastestUseNode){
            lastestUseNode = new node(nullptr,nullptr,key);
        }
        else{
            auto cur = lastestUseNode;
            lastestUseNode = new node(cur,nullptr,key);
            cur -> next = lastestUseNode;
            if(mCache.count(key)){
                auto rm = nodeCache[key];
                rm->next->last = rm->last;
                if(rm->last)
                    rm->last->next = rm->next;
                delete rm;
            }
        }
        nodeCache[key] = lastestUseNode;

        if(mNums > mCap){
            auto cur = lastestUseNode;
            while(cur->last != nullptr)
                cur = cur->last;
            cur->next->last = nullptr;
            auto rmKey = cur->key;
            mCache.erase(rmKey);
            delete cur;
            mNums--;
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */