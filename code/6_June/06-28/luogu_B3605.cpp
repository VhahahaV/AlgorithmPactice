//
// Created by VhahahaV on 2024/6/28.
//
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x7fffffff;
int E;
vector<int> level;
int nl,nr ,m;

struct Dinic
{
    int c = 0;
    int f = 0;
};
vector<vector<Dinic>> edge;

bool dinic_bfs()      //bfs方法构造层次网络
{
    queue<int> q;
    level.clear();
    level.resize(nr+nl+3,0);
    q.push(1);
    level[1] = 1;
    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (v = 1; v <= E; v++) {
            if (!level[v] && edge[u][v].c>edge[u][v].f) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[E] != 0;                //question: so it must let the sink node is the Mth?/the way of yj is give the sink node's id
}

int dinic_dfs(int u, int cp) {           //use dfs to augment the flow
    int tmp = cp;
    int v, t;
    if (u == E)
        return cp;
    for (v = 1; v <= E&&tmp; v++) {
        if (level[u] + 1 == level[v]) {
            if (edge[u][v].c>edge[u][v].f) {
                t = dinic_dfs(v, min(tmp, edge[u][v].c - edge[u][v].f));
                edge[u][v].f += t;
                edge[v][u].f -= t;
                tmp -= t;
            }
        }
    }
    return cp - tmp;
}
int dinic() {
    int sum=0, tf=0;
    while (dinic_bfs()) {
        while (tf = dinic_dfs(1, INF))
            sum += tf;
    }
    return sum;
}

int main() {
    cin >>nl >> nr >> m;
    edge.resize(nl+nr+3,vector<Dinic>(nl+nr+3));
    for(int i = 1 ; i <= nl ;i++)
        edge[1][i+1].c = 1;
    for(int i = 1 ; i <= nr ;i++)
        edge[1+i+nl][nl+nr+2].c = 1;
    for(int i = 0 ; i < m ;i++){
        int u,v;
        cin >> u >> v;
        edge[u+1][1+v+nl].c = 1;
    }
    E = nl+nr+2;

    int ans = dinic();
    cout << ans;

    return 0;
}
