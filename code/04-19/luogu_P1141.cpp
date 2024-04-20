//
// Created by CZQ on 2024/4/19.
//
#include "bits/stdc++.h"

using namespace std;
using loc_t = pair<int, int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> maze(n);
    vector<vector<int>> ans(n);
    map<int, int> max_count;
    vector<loc_t> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int tag = 0;
//    tag记录了一个全联通分量
    auto get_ans = [&](int i, int j)->int{
        if(ans[i][j] != -1){
            return max_count.at(ans[i][j]);
        }
        int count = 0;
        queue<loc_t> q;
        q.emplace(i, j);
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(ans[x][y] != -1) continue;
            ans[x][y] = tag;
            count += 1;
            for(auto d: dxy){
                int new_x = x+d.first;
                int new_y = y+d.second;
                if(new_x < 0 || new_y<0 || new_x>=n || new_y>= n)
                    continue;
                if(maze[new_x][new_y] ^ maze[x][y]){
                    q.emplace(new_x, new_y);
                }
            }
        }
        tag++;
        return max_count[ans[i][j]] = count;
    };
    for(int i=0; i<n; i++){
        maze[i].reserve(n);
        ans[i].resize(n, -1);
        for(int j=0; j<n; j++) {
            char c = ' ';
            while (c = getchar()) {
                if (isdigit(c)) {
                    break;
                }
            }
            maze[i].emplace_back(c - '0');
        }
    }
    while(m--){
        int i, j;
        cin >> i >> j; i--; j--;
        cout << get_ans(i, j) << endl;
    }
    return 0;
}