//
// Created by CZQ on 2024/4/18.
//
#include "bits/stdc++.h"

using namespace std;

void dfs(int maxD,int start,vector<int> &maxDist,const vector<vector<int>> &maps){
    if (maxDist[start])
        return ;
    maxDist[start] = maxD;
    for(auto end : maps[start]){
        dfs(maxD,end,maxDist,maps);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> maps(N+1);
//    反向建立边
    for (int i = 1; i <= M; ++i) {
        int start,end;
        cin >> start>>end;
        maps[end].emplace_back(start);
    }
    vector<int> maxDis(N+1);
    for(int i = N;i > 0;i--){
        if (!maxDis[i]){
            dfs(i,i,maxDis,maps);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << maxDis[i] << " ";
    }
    return 0;
}