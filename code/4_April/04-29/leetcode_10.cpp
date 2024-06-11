//
// Created by VhahahaV on 2024/4/29.
//

#include "bits/stdc++.h"
using namespace std;
//1h+
class Solution {
    // 二维DP
    // f[i][j]代表 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配。
    /* f[i][j] = {
        if(p[j] != '*'){
            f[i-1][j-1]     match(s[i],p[j])
            false           mismatch(s[i],p[j])
        }
        else{
            f[i-1][j] || f[i][j-2]      match(s[i],p[j])
            f[i][j-2]                   mismatch(s[i],p[j])
        }
    }
    */

public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;

        for(int i = 0 ; i <= s.size(); i++){
            for(int j = 1 ; j <= p.size(); j++){
                int pj = j-1, si = i-1;
                if(p[pj] != '*'){
                    if(i || p[pj] == s[si] || p[pj] == '.')
                        dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(i || p[pj-1] == s[si] || p[pj-1] == '.')
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main(){
    Solution solution;
    cout << solution.isMatch("aa","a");

    return 0;
}