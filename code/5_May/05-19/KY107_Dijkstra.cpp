//
// Created by CZQ on 2024/5/19.
//
#include "bits/stdc++.h"

using namespace std;
const int MOD = 100000;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> maze(n,vector<int>(n));
    for(int i =0 ,len=1;i < m ; i++){
        int u,v;
        cin >> u >> v;
        maze[u][v]=len;
        maze[v][u]=len;
        len*=2;len%=MOD;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minDis;
    vector<int> ans(n);
    for(int i = 1 ; i < n ;i++){
        if(maze[0][i])
            minDis.push(pair<int,int>(maze[0][i],i));
    }
    int findNode = 0;
    while(findNode!=n-1 && !minDis.empty()){
        findNode++;
        auto [curLen,v] = minDis.top();
        minDis.pop();
        ans[v] = curLen;
        for(int i = 1;i<n;i++){
            if(maze[v][i] && ans[i] == 0)
                minDis.push(pair<int,int>((maze[v][i]+ans[v])%MOD,i));
        }
    }
    for(int i = 1 ; i < n;i++)
        cout << ans[i] << '\n';
    return 0;
}