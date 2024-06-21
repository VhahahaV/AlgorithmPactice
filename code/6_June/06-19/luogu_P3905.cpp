//
// Created by CZQ on 2024/6/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Road{
    int  end , len;
    Road(int e , int l):end(e),len(l){}
    bool operator< (const Road &other) const{
        return len > other.len;
    }
};
int main(){
    int n,m;
    cin >> n >> m;
//    vector<Road> roads(m,{0,0,0});
    vector<vector<Road>> roads(n+1);
    for(int i = 0 ; i < m ; i++){
        int s,e,t;
        cin >> s >> e >> t;
        roads[s].emplace_back({e,t});
        roads[e].emplace_back(s);
    }
    int d;
    cin >> d;
    vector<Road> destroyed;
    for(int i = 0 ; i < d ; i++){
        cin >> roads[i].start >> roads[i].end;
    }

    int A,B;
    cin >> A >> B;

    auto findRoad = [&]()->vector<Road>{
        priority_queue<Road> que;
        vector<bool> vis(n+1, false);
        que.emplace(A,A,0);
        while(!que.empty()){
            auto curNode = que.top();
            que.pop();
            if(vis[curNode.end]) continue;
            vis[curNode.end] = true;
            for(auto )
        }
    };
    return 0;
}