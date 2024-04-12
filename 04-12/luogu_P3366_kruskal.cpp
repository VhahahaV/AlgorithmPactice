//
// Created by CZQ on 2024/4/12.
//

//Kruskal算法
//先对边集合进行排序
//使用并查集来判定是否成环，如果添加边的时候两个节点本来就在一个集合中，则这条边肯定成环

#include "bits/stdc++.h"

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
};

bool comp(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}

//建立并查集
vector<int> father;

int findRoot(int child){
    if (child != father[child])
        father[child] = findRoot(father[child]);
    return father[child];
}

bool joint(int child1, int child2){
    int root1 = findRoot(child1);
    int root2 = findRoot(child2);

    if(root2 == root1){
        return false;
    }
//    joint
    father[root2] = root1;
    return true;
}
int main(){
    int N,M;
    cin >> N >> M;

    vector<Edge> edge(M);
    father.resize(N+1);
    for (int i = 0; i < M; ++i) {
        cin >> edge[i].start >> edge[i].end >> edge[i].weight;
    }
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
    }
    sort(edge.begin(),edge.end(),comp);
    int setNum = N;
    long long sum = 0;
    for (auto e : edge) {
        if (setNum==1)
            break;
        int node1 = e.start,node2 = e.end,weight = e.weight;
        if (joint(node1,node2)){
            sum += weight;
            setNum--;
        }
    }
    if (setNum==1)
        cout << sum;
    else
        cout << "orz";

}