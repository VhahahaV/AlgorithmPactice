//
// Created by CZQ on 2024/6/24.
//
#include <iostream>
#include <vector>

#include <climits>
using namespace std;

//dp
// 26mins
int main(){
    int n;
    cin >> n;
    vector<vector<int>> maze(n , vector<int>(n));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> maze[i][j];
    int ans = INT_MIN;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            vector<vector<int>> dp(n+1 , vector<int>(n+1));
            dp[i][j] = maze[i][j];
            for(int k = i+1; k < n ; k++)
                dp[k][j] = dp[k-1][j] + maze[k][j];
            for(int l = j+1; l < n ; l++)
                dp[i][l] = dp[i][l-1] + maze[i][l];
            for(int k = i+1 ; k < n ; k++)
                for(int l = j+1 ; l < n ; l++)
                    dp[k][l] = dp[k-1][l] + dp[k][l-1] - dp[k-1][l-1] + maze[k][l];
            for(int k = i ; k < n ; k++)
                for(int l = j ; l < n ; l++)
                    ans = max(ans,dp[k][l]);
        }
    cout << ans;
    return 0;
}