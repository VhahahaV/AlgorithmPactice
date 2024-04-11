//
// Created by CZQ on 2024/4/11.
//
#include "bits/stdc++.h"

using namespace std;

struct Road{
    int v1,v2;
    int times;
};

vector<int> father;

int findRoot(int idx){
    if (idx != father[idx])
        father[idx] = findRoot(father[idx]);
    return father[idx];
}

bool comp(Road x,Road y){return (x.times<y.times);}


int main(){

    int N,M;
    cin >> N >> M;
    vector<Road> roads(M);
    father.resize(N+1);
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> roads[i].v1 >> roads[i].v2 >> roads[i].times;
    }
//    这句表达式有问题
//    sort(roads.begin(),roads.end(),[](Road x,Road y)->bool {return (x.times<y.times);});
    sort(roads.begin(),roads.end(), comp);
    int num = N;
    for (auto road : roads) {
        int root1 = findRoot(road.v2);
        int root2 = findRoot(road.v1);
        if (root1 == root2)
            continue;
        else{
//            joint the set
            father[root2] = root1;
            num--;
            if (num == 1){
                cout << road.times;
                return 0;
            }
        }
    }
    cout << -1;


    return 0;
}