//
// Created by CZQ on 2024/4/11.
//
#include "bits/stdc++.h"

using namespace std;

//kruskal算法 && Prim算法

//使用Prim算法

//还没A，明天再做，复杂度有点高

struct Node{
    bool deleted = false;
    vector<array<int,2>> out;
    vector<array<int,2>> in;
};
int main(){

    int N ,M;
    cin >> N >> M;
    vector<Node> nodes(N+1);

    for (int i = 1; i <= M; ++i) {
        int start,end,weight;
        cin >> start >> end >> weight;
        nodes.at(start).out.emplace_back(std::array<int,2>{end,weight});
        nodes.at(end).in.emplace_back(std::array<int,2>{start,weight});
    }

    long long lsmSum = 0;
    vector<int> lsmNode;
    lsmNode.emplace_back(1);

    while (lsmNode.size() != N){
        int minEdge = INT32_MAX;
        int outIndex = 0;
        for(auto nodeIndex:lsmNode){
            auto &node = nodes[nodeIndex];
            for(auto outNode : node.out){
                if (find(lsmNode.begin(),lsmNode.end(),outNode[0]) == lsmNode.end()){
                    if(minEdge>outNode[1]){
                        minEdge = outNode[1];
                        outIndex = outNode[0];
                    }
                }
            }
        }
        if (outIndex){
            lsmNode.push_back(outIndex);
            lsmSum += minEdge;
        }
        else{
            cout << "orz";
            return 0;
        }

    }

    cout << lsmSum;
    return 0;


}