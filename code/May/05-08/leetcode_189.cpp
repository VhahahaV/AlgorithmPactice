//
// Created by VhahahaV on 2024/5/8.
//
//11min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(!k)
            return;
        vector<int> tmp(nums.begin()+n-k,nums.end());
        for(int i = n-1 ; i >= 0; i--){
            if(i < k)
                nums[i] = tmp[i];
            else
                nums[i] = nums[i-k];

        }
    }
};