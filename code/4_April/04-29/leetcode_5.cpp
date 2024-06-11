//
// Created by VhahahaV on 2024/4/29.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:

// F[i][j] = F[i+1][j-1] & (Si == Sj)
//19min
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<bool>> dp(n , vector<bool>(n,false));
        for(int i = 0; i < dp.size() ; i++)
            dp[i][i] = true;
        for(int len = 2; len <= n ; len++){
            for(int i = 0 ; i + len - 1< n ; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len == 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];

                    if(dp[i][j] && len > maxLen){
                        maxLen = len;
                        begin = i;
                    }
                }

            }
        }

        return s.substr(begin, maxLen);
    }
};