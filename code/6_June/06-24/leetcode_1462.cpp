//
// Created by CZQ on 2024/6/24.
//
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 拓扑排序
        vector<vector<int>> maps(numCourses);
        vector<int> rudu((numCourses));
        vector<bool> vis(numCourses,false);

        for(const auto &uv : prerequisites){
            maps[uv[0]].emplace_back(uv[1]);
            rudu[uv[1]]++;
        }
        vector<set<int>> pres(numCourses);
        queue<pair<int,set<int>>> que;
        for(int i = 0 ; i < numCourses ; i++){
            if(!rudu[i]){
                que.emplace(i,pres[i]);
                vis[i] = true;
            }
        }
        map<int,set<int>> sorted;
        while(!que.empty()){
            auto [cur,preclasses] = que.front();
            que.pop();
            sorted[cur] = preclasses;
            preclasses.insert(cur);

            for(auto nex : maps[cur]){
                for( auto it : preclasses)
                    pres[nex].insert(it);
                rudu[nex]--;
            }
            for(int i = 0 ; i < numCourses ; i++){
                if(!rudu[i] && !vis[i]){
                    que.emplace(i,pres[i]);
                    vis[i] = true;
                }
            }
        }

        vector<bool> flags;
        for(auto &uv : queries){
            if(sorted[uv[1]].count(uv[0]))
                flags.emplace_back(true);
            else
                flags.emplace_back(false);
        }
        return flags;
    }
};