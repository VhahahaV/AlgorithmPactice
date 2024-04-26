//
// Created by VhahahaV on 2024/4/26.
//


////最短路径问题，三驾马车：floyd(O(n^3))、dijkstra(O(nlogn))、SPFA(O(KE))
////Floyd：将所有节点的距离都存在一个数组里，由于要枚举所有的两两组合以及每一个组合的“中转点”，再进行松弛操作
//// Dijkstra是基于一种贪心的策略，首先用数组dis记录起点到每个结点的最短路径，再用一个数组保存已经找到最短路径的点,然后，从dis数组选择最小值，则该值就是源点s到该值对应的顶点的最短路径，并且把该点记为已经找到最短路

////priority_queue 默认是大顶堆，参考 https://blog.csdn.net/weixin_36888577/article/details/79937886

#include "bits/stdc++.h"

using namespace std;

struct edge{
    int u,v,w;
    bool  operator<(const edge& a){
        return w>a.w;
    }
};

void dijkstra(){

}

int main(){


    return 0;
}