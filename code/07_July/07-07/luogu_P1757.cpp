//
// Created by VhahahaV on 2024/7/7.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int m , n;
    cin >> m >>n;
    vector<vector<pair<int,int>>> parts(101);

    for(int i = 1 ; i <= n ;i++){
        int w,v,p;
        cin>>w >> v >> p;
        parts[p].emplace_back(w,v);
    }
    vector<int> dp(m+1);
    for(const auto &p : parts){
        for(int j = m ; j >= 0 ; j--){
            for(auto &[weight , val] : p){
                if(j >= weight){
                    dp[j] = max(dp[j] , dp[j-weight]+val);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}