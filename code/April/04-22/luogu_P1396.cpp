//
// Created by CZQ on 2024/4/21.
//

//kruskal算法求最小生成树,dfs遍历最小生成树找到在s->t路径下中最长的那条路径
//用时50min,复杂度控制在O(n)，思考dfs的思路比较久
#include "bits/stdc++.h"
using namespace std;

vector<int> father;
int num;
int n,m,s,t;

int findRoot(int child){
    if (child != father[child])
        father[child] = findRoot(father[child]);
    return father[child];
}

bool joint(int a, int b){
    int father1 = findRoot(a);
    int father2 = findRoot(b);
    if (father1 != father2){
        father[father1] = father[father2];
        num--;
        return true;
    }
    return false;
}

vector<bool> occ;
int res = INT32_MIN;
bool dfs(const vector<vector<pair<int,int>>> &lsm,int start){
    if (occ[start])
        return false;
    occ[start] = true;
    if (start == t)
        return true;
    for (int i = 0; i < lsm[start].size(); ++i) {
        bool find_t = dfs(lsm,lsm[start][i].first);
        if (find_t){
            res = max(res,lsm[start][i].second);
            return true;
        }
    }
    return false;
}

//搞清楚make_pair 和 make_tuple
using road = pair<int,int>;

int main(){
    cin >> n >> m >> s >> t;
    num = n;
    father.resize(n+1);
    occ.resize(n+1, false);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
    vector<pair<road ,int>> graph;
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        graph.emplace_back(make_pair(make_pair(u,v),w));

    }
    sort(graph.begin(),graph.end(),[](pair<road ,int> a, pair<road ,int> b) -> bool {
        return a.second < b.second;
    });
    vector<vector<pair<int,int>>> lsm(n+1);
    for (int i = 0; i < m  && num != 1; ++i) {
        auto r = graph[i];
        int start = r.first.first,end = r.first.second,weight = r.second;
        if (joint(start,end)){
            lsm[start].emplace_back(make_pair(end,weight));
            lsm[end].emplace_back(make_pair(start,weight));
        }
    }
    dfs(lsm,s);
    cout << res;
    return 0;
}