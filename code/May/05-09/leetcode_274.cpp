//
// Created by VhahahaV on 2024/5/9.
//
//8min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
// 有 h 个 数字 大于等于 h
// 二分？bushi
    bool check(int h , const vector<int>& citations){
        if(!h) return true;
        return citations[h-1] >= h;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int ans;
        for(int h = citations.size();h>=0;h--)
            if(check(h,citations)){
                ans = h;
                break;
            }

        return ans;
    }
};