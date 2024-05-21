//
// Created by CZQ on 2024/5/21.
//
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
using edge = pair<int,int>;

int main() {
    int i , j;
    map<int,vector<int>> maze;
    set<int> nodes;
    int nodeNum = 0;
    while(cin >> i >> j){
        maze[i].emplace_back(j);
        maze[j].emplace_back(i);
        nodes.insert(i);nodes.insert(j);
        nodeNum++;
    }
    int ans = 0;
    while (nodes.size() != 0) {
        int head = *nodes.begin();
        queue<int> touched;
        touched.push(head);
        while (!touched.empty()) {
            int cur = touched.front();touched.pop();
            if (!nodes.count(cur)) {
                continue;
            }
            else {
                nodes.erase(cur);
            }
            auto &nexts = maze[cur];
            for(int next : nexts){
                if(nodes.count(next)){
                    touched.emplace(next);
                }
            }
        }
        ans++;
    }
    cout << ans;
}
// 64 位输出请用 printf("%lld")