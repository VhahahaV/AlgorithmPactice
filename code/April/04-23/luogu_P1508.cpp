//
// Created by VhahahaV on 2024/4/23.
//

#include "bits/stdc++.h"

using namespace std;

// F[i][j] = max( F[i+1][j] , F[i+1][j-1] , F[i+1][j+1] ) + a[i][j]
//a[i][j]代表位置为i,j的点的食物的能量值，F[i][j]为吃到 位置为 i,j的时候能得到的最大能量值

//19min
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> maze(N+1,vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> F(N,vector<int>(M,INT32_MIN));
    F[N-1][M/2] = maze[N-1][M/2];
    F[N-1][M/2-1] = maze[N-1][M/2-1];
    F[N-1][M/2+1] = maze[N-1][M/2+1];
    for (int i = N-2; i >= 0 ; i--) {
        for (int j = 0; j < M; ++j) {
            int preMax = INT32_MIN;
            if (j-1 < 0)
                preMax = max(F[i+1][j],F[i+1][j+1]);
            else if (j+1 >= M)
                preMax = max(F[i+1][j],F[i+1][j-1]);
            else{
                preMax = max(F[i+1][j],F[i+1][j+1]);
                preMax = max(preMax,F[i+1][j-1]);
            }
            if (preMax == INT32_MIN)
                continue;
            else
                F[i][j] = preMax + maze[i][j];
        }
    }
    int ans = INT32_MIN;
    for (int j = 0; j < M; ++j) {
        ans = max(ans,F[0][j]);
    }
    cout << ans;
    return 0;
}