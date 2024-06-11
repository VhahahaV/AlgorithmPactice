//
// Created by VhahahaV on 2024/5/18.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        auto getNum = [&](int a)->int{
            int res = 0;
            for(auto it:nums){
                if(it%a==0) res++;
            }
            return res;
        };
        int maxNum = 0;
        int ans=INT32_MAX;
        for(auto divisor:divisors){
            int num = getNum(divisor);
            if(maxNum < num){
                maxNum=num;ans=divisor;
            }
            else if(maxNum==num)
                ans = min(divisor,ans);
        }
        return ans;
    }
};