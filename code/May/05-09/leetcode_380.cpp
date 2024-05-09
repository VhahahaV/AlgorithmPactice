//
// Created by VhahahaV on 2024/5/9.
//
#include "bits/stdc++.h"
using namespace std;
class RandomizedSet {
public:
    unordered_map<int,int> random_set;
    vector<int> dArray;
    vector<bool> deleted;
    int nums=0;
    RandomizedSet() {
    }

    bool insert(int val) {
        if(random_set.count(val))
            return false;
        else{
            random_set.insert({val,nums++});
            dArray.emplace_back(val);
            deleted.emplace_back(false);
            return true;
        }
    }

    bool remove(int val) {
        if(random_set.count(val)){
            int index = random_set[val];
            random_set.erase(val);
            dArray.erase(find(dArray.begin(),dArray.end(),val));
            nums--;
            return true;
        }
        return false;
    }

    int getRandom() {
        int i = rand() % nums;
        auto it = dArray.begin();
        return *(it+i);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */