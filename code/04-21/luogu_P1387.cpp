//
// Created by CZQ on 2024/4/21.
//
#include "bits/stdc++.h"

using namespace std;
//F[i][j] 代表以坐标为 i , j的点为左下角 所能组成的正方向最大的长度
//状态方程  F[i][j] =  min(min(F(i-1,j),F(i,j-1)),F(i-1,j-1));
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> maxDis(n,vector<int>(m));
    auto F = [&](int i,int j){
        if (i<0 || i>=n || j < 0 || j>=m)
            return 0;
        return maxDis[i][j];
    };
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!mat[i][j])
                continue;
            maxDis[i][j] = min(min(F(i-1,j),F(i,j-1)),F(i-1,j-1))+1;
            res = max(maxDis[i][j],res);
        }
    }
    cout << res;
    return 0;
}