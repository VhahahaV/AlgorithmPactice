//
// Created by CZQ on 2024/4/21.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> father;
//prim算法
void findRoot(int child){
    if (child)
}
int main(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int,int>>> roads(n+1);
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        roads[u].emplace_back(make_pair(v,w));
        roads[v].emplace_back(make_pair(u,w));
    }
    return 0;
}