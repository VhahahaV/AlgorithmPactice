//
// Created by CZQ on 2024/4/27.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    using edge = pair<int , bool>;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<edge>> graph(n);
        for(auto &e : connections){
            int a = e[0],b = e[1];
            graph[a].emplace_back(b,true);
            graph[b].emplace_back(a,false);
        }
        // bfs
        queue<int> queue1;
        int ans = 0;
        vector<bool> visited(n,false);
        queue1.emplace(0);
        visited[0] = true;
        while(!queue1.empty()){
            auto cur = queue1.front();
            queue1.pop();
            // if(!visited[cur])
            //     continue;
            visited[cur] = true;
            for(auto &e : graph[cur]){
                int next = e.first;
                if(!visited[next]){
                    queue1.emplace(next);
                    if(!e.second)
                        ans++;
                }
            }
        }
        return n-1-ans;
    }
};