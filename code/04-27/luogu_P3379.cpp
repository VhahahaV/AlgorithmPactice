//
// Created by VhahahaV on 2024/4/26.
//

///最最近公共祖先问题，LCA 需要使用倍增算法来优化
/// 倍增算法用空间换时间，在储存深度信息的基础之上，另外还存储了 第2^i个祖先
/// DP推导式： father[u][i] = father[father[u][i-1]][i-1];  father[u][i]代表第u节点的第 2^i个的祖先节点序号

#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> maze;
vector<vector<int>> father;
vector<int> depth;
#include "stdlib.h"
#include "cstdlib"

using namespace std;
void dfs(int u,int fa){
    depth[u] = depth[fa] + 1;
    father[u][0] = fa;
    for (int i = 1; (1 << i) <= depth[u]; ++i) {
        father[u][i] = father[father[u][i-1]][i-1];
    }
    auto &ends = maze[u];
    for(auto other : ends){
        if (other == fa)
            continue;
        dfs(other,u);
    }
}


int lca(int x ,int y){
    //假设 depth[y] > depth[x]
    if (depth[x] > depth[y])
        swap(x,y);

    ////从顶往上读,先找到最近的一个，然后再找到最近的下一个。
    for (int i = 20; i >= 0; --i) {
        if (depth[x] <= depth[y] - (1<<i))
            y = father[y][i];
    }
    if (x == y)
        return x;
     for(int i = 20 ; i >= 0;i--){
         if (father[x][i] == father[y][i])
             continue;
         else
             x = father[x][i],y = father[y][i];
     }
    return father[x][0];


}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int N,M,S;
    cin >> N >> M >> S;
    maze.resize(N+1);
    father.resize(N+1,vector<int>(21));
    depth.resize(N+1);
    for (int i = 0; i < N - 1; ++i) {
        int u,v;
        cin >> u >> v;
        maze[u].emplace_back(v);
        maze[v].emplace_back((u));
    }
    dfs(S,0);
    while (M--){
        int a , b;
        cin >> a >> b;
        cout << lca(a,b)<< ' ';
    }
    
    return 0;
}