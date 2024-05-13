//
// Created by CZQ on 2024/5/12.
//
#include "bits/stdc++.h"
using namespace std;

//超时了
//
class Solution {
public:
// dp[i] =  dp[i+1]+1 , dp[i*2]+1 , dp[3*i]+1
    int minDays(int n) {
        vector<int> dp(n+1,INT32_MAX);
        dp[n] = 0;
        for(int i = n-1;i>=1;i--){
            int d1 = dp[i+1]+1;
            int d2 = INT32_MAX,d3 = INT32_MAX;
            if(2*i <= n )
                d2 = dp[2*i]+1;
            if(3*i <= n)
                d3 = dp[3*i]+1;
            dp[i] = min(min(dp[i],d1),min(d2,d3));
        }
        return dp[1]+1;
    }
};

int main(){
    Solution solution;
    solution.minDays(10);
    return 0;
}