//
// Created by VhahahaV on 2024/7/3.
//
#include <iostream>

#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct people{
    pair<int,int> pos;
    int infectTime = numeric_limits<int>::max();

};

int main(){
    int n , m , a , b;
    cin >> n >> m >> a >> b;
    vector<vector<people>> mat(n+1,vector<people>(m+1));
    queue<pair<int,int>> q;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= m ; j++)
            mat[i][j].pos = {i,j};
    for(int i = 0 ; i < a ; i++){
        int u,v;
        cin >> u >> v;
        mat[u][v].infectTime = 0;
        q.emplace(u,v);
    }
    vector<pair<int,int>> query;
    for(int i = 0 ; i < b ; i++){
        int u,v;
        cin >> u >> v;
        query.emplace_back(u,v);
    }

    auto getNextStep = [&](int i , int j)->vector<pair<int,int>>{
        vector<pair<int,int>> ans;
        vector<pair<int,int>> delta = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto d : delta){
            int nx = d.first+i , ny = d.second+j;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                ans.emplace_back(nx,ny);
        }
        return ans;
    };
    vector<vector<bool>> vis(n+1,vector<bool>(m+1, false));
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        if(vis[cur.first][cur.second])
            continue;
        else
            vis[cur.first][cur.second] = true;

        auto nextStep = getNextStep(cur.first,cur.second);

        for(auto &nex : nextStep){
            if(vis[nex.first][nex.second])
                continue;
            auto &nexNode = mat[nex.first][nex.second];
            if(nexNode.infectTime > mat[cur.first][cur.second].infectTime+1){
                nexNode.infectTime = mat[cur.first][cur.second].infectTime+1;
                q.emplace(nexNode.pos.first,nexNode.pos.second);
            }
        }
    }

    for(auto &[x,y] : query){
        cout << mat[x][y].infectTime << endl;
    }
    return 0;
}