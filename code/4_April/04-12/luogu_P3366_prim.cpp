//
// Created by CZQ on 2024/4/12.
//
#include "bits/stdc++.h"

using namespace std;
//prim算法，需要维护一个最小堆储存 已经构成最小生成树的节点所延伸出去的边，每次pop出最小的一条边

//https://blog.csdn.net/LOOKQAQ/article/details/81304637
//参考链式前向星来存图：
//基本概念：
//维护一个 weight（边权重），end（边的尾节点），next（下一条同样起始点的边索引）
// 维护head数组来储存 i为起点的边再数组edge中所存的第一个位置，

struct Graph{
    vector<int> next;
    vector<int> end;
    vector<int> weight;
    vector<int> head;
    int size = 1;

public:
    Graph(int size){
        next.resize(size+1);
        head.resize(size+1);

        weight.resize(size+1);

        end.resize(size+1);
    }
    void add(int u,int v, int w){
        end[size] = v;
        weight[size] = w;
        next[size] = head[u];
        head[u] = size++;
    }
};

struct Edge{
    int start;
    int end;
    int weight;
    Edge() = default;
    Edge(int u,int v,int w): start(u),end(v),weight(w){}
    friend bool operator<(Edge x, Edge y){return x.weight > y.weight;};
};

int main(){
    int N ,M;
    priority_queue<Edge> heaps;
    cin >> N>>M;

//    链式前向星写晕了
    Graph graph(2*M+1);
    for(int i = 0 ; i < M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph.add(u,v,w);
        graph.add(v,u,w);
    }

    for (int i = graph.head[1]; i != 0 ; i = graph.next[i]) {
        heaps.emplace(1,graph.end[i],graph.weight[i]);
    }
    int edge_cnt = 0;
    long long sum = 0;
    vector<bool> inLsm(N+1,false);
    inLsm[1] = true;
    while (!heaps.empty() && edge_cnt != N-1){
        Edge edge = heaps.top();
        heaps.pop();
//        已经在Lsm中了
        if (inLsm[edge.end])
            continue;
//        不在Lsm中
        else{
            sum += edge.weight;
            edge_cnt++;
            inLsm[edge.end] = true;
            for (int i = graph.head[edge.end]; i != 0 ; i = graph.next[i]) {
                heaps.emplace(edge.end,graph.end[i],graph.weight[i]);
            }
        }
    }
    if (edge_cnt==N-1)
        cout << sum;
    else
        cout << "orz";




    return 0;
}