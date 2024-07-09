//
// Created by VhahahaV on 2024/7/7.
//
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;
    for(int i = 2; i <= n ; i++){
        if(i== 5 || i == 11)
            dp[i] = 1;
        else{
            int a = INT_MAX , b = INT_MAX;
            if(i>5)
                a = dp[i-5];
            if(i>11)
                b = dp[i-11];
            a = min(a , b);
            dp[i] = min(dp[i-1],a) +1 ;
        }
    }
    cout << dp[n];

    return 0;
}