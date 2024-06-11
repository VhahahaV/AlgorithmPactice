//
// Created by VhahahaV on 2024/5/9.
//
//10min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
// dp ： dp[num] = (for i <= num && dp[num] = true
//                              dp[i] + step[i] can reach num)
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int cur = 0 ; cur < n ; cur++){
            if(dp[cur]){
                int maxdis = cur + nums[cur];
                int i = cur;
                while(i<n && i<=maxdis)
                    dp[i++] = true;
            }
        }
        return dp[n-1];
    }
};