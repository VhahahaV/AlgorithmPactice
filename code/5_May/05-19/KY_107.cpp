//
// Created by CZQ on 2024/5/19.
//
#include "bits/stdc++.h"

using namespace std;
//kruskal 算法，对有所有的边排序，

const int MOD = 100000;
int roadNum = 0;
vector<int> father;

//最短路径好写，
//从在lsm中查找从0开始的最小长度需要时间思考
int findRoot(int u){
    if(father[u] != u){
        father[u] = findRoot(father[u]);
    }
    return father[u];
}

bool jointSet(int a , int b){
    int father1 = findRoot(a);
    int father2 = findRoot(b);
    if(father1!=father2){
        father[father2] = father1;
        roadNum++;
        return true;
    }
    return false;
}

void getAns(vector<vector<pair<int,int>>> &lsm,vector<int> &ans,int start,int preStart=-1){
    for (auto &[target,roadLen]:lsm[start]){
        if(target == preStart)
            continue;
        ans[target] = (ans[start]+roadLen)%MOD;
        getAns(lsm,ans,target,start);
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> maze;
    father.resize(n);
    for(int i = 0; i < n ; i++)
        father[i] = i;
    for(int k = 0 ,len=1;k<m;k++){
        int u,v;
        cin >> u >> v;
        maze.emplace_back(len, pair<int,int>(u,v));
        len*=2;len%=MOD;
    }
    vector<vector<pair<int,int>>> lsm(n);
    for(auto &it : maze){
        auto &[u,v] = it.second;
        if(jointSet(u,v)){
            lsm[u].emplace_back(v,it.first);
            lsm[v].emplace_back(u,it.first);
        }
        if(roadNum==n-1)
            break;
    }

    vector<int> ans(n);
    getAns(lsm,ans,0);
    for(int i = 1; i < ans.size();i++)
        cout << ans[i] << '\n';
    return 0;
}