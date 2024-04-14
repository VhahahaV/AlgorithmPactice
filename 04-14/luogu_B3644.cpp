//
// Created by CZQ on 2024/4/14.
//
#include "bits/stdc++.h"

using namespace std;

//拓扑排序，要维护一个 queue，存所有入度为0 的节点，挨个更新 节点的入度

int main(){
    int N;
    cin >> N;
    //入度
    vector<int> infiltration(N+1);
    vector<vector<int>> maps(N+1);
    for (int i = 1; i <= N; ++i) {
        int child;
        cin >> child;
        while (child){
            maps[i].emplace_back(child);
            infiltration[child]++;
            cin >> child;
        }
    }
    vector<int> ans;
    queue<int> peoples;
    for(int i = 0; i <= N ; i++){
        if (!infiltration[i])
            peoples.push(i);
    }
    while (!peoples.empty()){
        int man = peoples.front();
        ans.emplace_back(man);
        peoples.pop();
        for(auto child : maps[man]){
            if(!(--infiltration[child])){
                peoples.push(child);
            }
        }
    }
    for(int i = 1;i <= N;i++)
        cout << ans[i] << " ";



    return 0;
}