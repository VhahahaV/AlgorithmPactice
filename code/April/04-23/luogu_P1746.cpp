//
// Created by VhahahaV on 2024/4/23.
//
#include "bits/stdc++.h"

using namespace std;
//18min,忘了 que.pop() ，de了六七分钟
using loc_t = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> road(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c ;
            while (c = getchar()){
                if (isdigit(c))
                    break;
            }
            road[i][j] = c - '0';
        }
    }
    int x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;
    x0--,y0--,x1--,y1--;
    vector<vector<int>> steps(n,vector<int>(n,-1));
    vector<loc_t > dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    auto bfs = [&](loc_t loc0,const loc_t &loc1)->int{
        queue<pair<loc_t,int>> que;
        que.emplace(loc0,0);
        while (!que.empty() && steps[x1][y1] == -1){
            auto [cur,step] = que.front();
            que.pop();
            int curx = cur.first,cury = cur.second;
            if (steps[curx][cury] != -1)
                continue;
            steps[curx][cury] = step;
//            cout << " cur : "<<curx << "  "<< cury << '\n';
            for (auto dir : dirs) {
                int dx = curx + dir.first,dy = cury + dir.second;
                if (dx<0 || dx>=n || dy<0 || dy>=n || road[dx][dy])
                    continue;
                else{
                    que.emplace(loc_t {dx,dy},step+1);
                }
            }
        }
        return steps[x1][y1];
    };

     cout << bfs(loc_t{x0,y0},loc_t{x1,y1});
    return 0;
}