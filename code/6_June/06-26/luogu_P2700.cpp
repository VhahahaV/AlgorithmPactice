// Created by CZQ on 2024/6/27.
//
#include <iostream>

#include <vector>
#include <set>
#include <queue>

using namespace std;

using ull = unsigned long long;
//并查集
//40min
vector<ull> fathers;
set<ull> enymis;

ull findRoot(ull key){
    if (fathers[key] != key){
        fathers[key] = findRoot(fathers[key]);
    }
    return fathers[key];
}

bool mergeSet(ull key1 , ull key2){
    auto father1 = findRoot(key1), father2 = findRoot(key2);
    if(enymis.count(father2) && enymis.count(father1))
        return false;
    if(father1!=father2){
        if(enymis.count(father2))
            fathers[father1] = father2;
        else
            fathers[father2] = father1;
        return true;
    }
    return false;
}

struct Road{
    int u,v;
    ull weight;
    Road(int a,int b,ull w):u(a),v(b),weight(w){}
    bool operator< (const Road &other) const{
        return weight < other.weight;
    }
};

int main(){
    int N, K;
    cin >> N >> K;
    fathers.resize(N+1);
    ull sumWeight = 0;
    for(int i=0 ;i < K ;i++){
        ull tmp;
        cin >> tmp;
        enymis.insert(tmp);

    }
    priority_queue<Road> roads;
    for (int i = 0; i < N-1; ++i) {
        fathers[i+1] = i+1;
        int u,v,w;
        cin >> u>>v>>w;
        roads.emplace(u,v,w);
        sumWeight+=w;
    }
    int addedRoadNum = 0;
//    最多为 N-1 - (K-1) = N-K
    while(!roads.empty() && addedRoadNum <= N-K){
        auto curRoad = roads.top();
        roads.pop();
        if(mergeSet(curRoad.v,curRoad.u)){
            sumWeight-=curRoad.weight;
            addedRoadNum++;
        }
    }
    cout << sumWeight;

}