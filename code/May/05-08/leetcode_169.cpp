//
// Created by VhahahaV on 2024/5/8.
//
//4min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> cnt;
        for(auto n : nums){
            if(!cnt.count(n))
                cnt[n] = 1;
            else
                cnt[n] += 1;
        }
        int len = nums.size(),ans;
        for(auto &[k,v] : cnt)
            if(v > len/2)
                ans = k;
        return ans;
    }
};