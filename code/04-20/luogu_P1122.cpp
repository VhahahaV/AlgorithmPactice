//
// Created by CZQ on 2024/4/20.
//

#include "bits/stdc++.h"

constexpr int Max =  2147483647;
using namespace std;
////1h
////dp 题， 不应该用并查集，节点与节点之间的关系无法表达出来
//int findRoot(int child){
//    if (child != father[child])
//        father[child] = findRoot(father[child]);
//    return father[child];
//
//}
//
//void jointNode(int x, int y){
//    int father1 = findRoot(x);
//    int father2 = findRoot(y);
//    if (father2 != father1){
//        father[father1] = father2;
//
//    }
//}

vector<int> maxCharm;
vector<int> flower;
vector<vector<int>> relations;
void dfs(int root, int father){
    maxCharm[root] = flower[root];
    for (int i = 0; i < relations[root].size(); ++i) {
        int child = relations[root][i];
        if (child == father)
            continue;
        dfs(child,root);
        if (maxCharm[child] >= 1)
            maxCharm[root] += maxCharm[child];
    }
}
int ans = INT32_MIN;
int getMax(int root, int father){
    int current = flower[root];
    for(auto child: relations[root]){
        if(child == father) continue;
        auto childSum = getMax(child, root);
        if(childSum > 0){
            current += childSum;
        }
    }
    ans = std::max(ans, current);
    return current;
}
int main(){
    int n;
    cin >> n;
    flower.resize(n+1);
//    maxCharm.resize(n+1);
    relations.resize(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> flower[i];
    }
    for (int i = 1; i < n; ++i) {
        int s,t;
        cin >> s >> t;
        relations[s].emplace_back(t);
        relations[t].emplace_back(s);
    }
    getMax(1, 0);
    cout << ans << endl;
//    int ans = -INT32_MAX;
//    dfs(1,0);
//    for (int i = 1; i <= n; ++i) {
//        ans = max(ans,maxCharm[i]);
//    }
//    cout << ans;
    return 0;
}