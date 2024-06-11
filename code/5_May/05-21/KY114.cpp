//
// Created by CZQ on 2024/5/21.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(),m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <=m ; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];

}
// 64 位输出请用 printf("%lld")