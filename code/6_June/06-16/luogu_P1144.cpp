//
// Created by CZQ on 2024/6/16.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;
using ull = unsigned long long;
constexpr int MOD = 100003;
#define DEBUG //std::cout << "LINE " << __LINE__ << std::endl
//SPFA 维护一个队列，同时再维护一个每个节点是否被访问的bool数组，再维护一个距离数组来代表起始点到每一个节点的距离。
//SPFA 思路：每次从队列中出队一个节点u，然后将该节点对离开节点u所指向的节点v进行松弛，如果v点的最短路径估计值有所调整，其v点不在队列中，则将v入队。
//SPFA判断负环某个点如果入队的次数超过了N次，则会出现负环。！！！！
//该题：该题还需要再维护一个数组，来表示能到达该节点的最短路径条数。！！


//Dijkstra算法：维护一个priority队列（堆优化后的队列，根据距离进行排序），同时再维护一个每个节点是否被访问的bool数组，再维护一个距离数组来代表起始点到每一个节点的距离。
//每次出队一个节点，就对这个节点u所指向的节点v进行松弛，如果v点的最短路径估计值有所调整，其v点不在队列中，则将v入队。


//Dijkstra  VS SPFA
//Dijkstra中的代表访问的vis数组一旦置1后就不会再变化，所以是每个节点都是一次性入队，而SPFA算法当某个节点出队后，vis数组是会重新置零的
//Dijkstra算法不能处理负环和负数边的情况，SPFA可以。


struct Info {
    int mIndex;
    int mDistance;
    Info(int idx, int dis) : mIndex(idx), mDistance(dis) {}

    bool operator<(const Info &b) const { return this->mDistance > b.mDistance; }
};


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> maze(N + 1);
    vector<map<int, int>> mazeWithWeight(N + 1);
//    {distance , count}
    DEBUG;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        maze[u].emplace_back(v);
        maze[v].emplace_back(u);
    }
    DEBUG;

//    auto bfsSearch = [&]()->void {
//        queue<tuple<int,ull,ull>> nextNode;
////        {index , distance,weight}
//        nextNode.emplace(1,0,1);
//        while(!nextNode.empty()){
//            auto [mIndex,curDis,curWeight] = nextNode.front();
//            auto &[scrDis,scrCount] = ans[mIndex];
//            nextNode.pop();
//            if(curDis > scrDis)
//                continue;
//            else if(curDis < scrDis){
//                scrDis = curDis;
//                scrCount = curWeight;
//            }
//            else
//                scrCount = (scrCount+curWeight)%MOD;
//            for(auto [nex,weight] : maze[mIndex]){
//                if(nex == mIndex) continue;
//                nextNode.emplace(nex,curDis+1,weight*curWeight);
//            }
//        }
//    };

    auto SPFAsearch = [&]() -> vector<int> {
        vector<int> res(N + 1);
        vector<bool> vis(N + 1);
        vector<int> dis(N + 1, INT_MAX);
        dis[1] = 0;
        vis[1] = true;
        res[1] = 1;
        queue<int> nodes;
        nodes.emplace(1);
        while (!nodes.empty()) {
            int cur = nodes.front();
            nodes.pop();
            vis[cur] = false;
            for (auto nex: maze[cur]) {
                if (dis[nex] > dis[cur] + 1) {
                    res[nex] = res[cur];
                    dis[nex] = dis[cur] + 1;
                    if (!vis[nex]) {
                        nodes.emplace(nex);
                        vis[nex] = true;
                    }
                } else if (dis[nex] == dis[cur] + 1) {
                    res[nex] = (res[nex] + res[cur]) % MOD;
                }
            }
        }
        return res;

    };

    auto dijkstraSearch = [&]() {
        priority_queue<Info> nodes;
        vector<bool> vis(N + 1);
        vector<int> res(N + 1);
        vector<int> dis(N + 1, INT_MAX);

        nodes.emplace(1, 0);
        res[1] =1;
        dis[1] = 0;
        DEBUG;
        while (!nodes.empty()) {
            auto nodeInfo = nodes.top();
            int curIdx = nodeInfo.mIndex;
            nodes.pop();
            if (vis.at(curIdx))
                continue;
            vis[curIdx] = true;
            for (auto nex: maze[curIdx]) {
                if (dis[nex] > dis[curIdx] + 1) {
                    dis[nex] = dis[curIdx] + 1;
                    res[nex] = res[curIdx];
                    nodes.emplace(nex, dis[nex]);
                } else if (dis[nex] == dis[curIdx] + 1) {
                    res[nex] = (res[nex] + res[curIdx]) % MOD;
                }
            }

        }
        DEBUG;
        return res;
    };
    DEBUG;

//    bfsSearch();
    auto res = dijkstraSearch();
    for (int i = 1; i <= N; i++) {
        cout << res[i] % MOD << '\n';
    }
    DEBUG;
//profiler
    std::cout << __FILE__ <<"  "<<__func__<< '\n';
    return 0;
}