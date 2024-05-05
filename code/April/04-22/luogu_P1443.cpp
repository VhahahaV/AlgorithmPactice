//
// Created by CZQ on 2024/4/22.
//

#include "bits/stdc++.h"

using namespace std;
using loc_t = pair<int,int>;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> res(n+1,vector<int>(m+1,-1));
    vector<loc_t> dxy = {{-1,2},{1,2},{-1,-2},{1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
    auto BFS = [&res, &dxy, m, n](loc_t x0) -> void {
        queue<pair<loc_t ,int>> que;
        vector<bool> vis((n+1)*(m+1),false);
        que.emplace(x0,0);

        while (!que.empty()){
            auto [p,pStep] = que.front();
            que.pop();
            if (vis[p.first*(m+1) + p.second])
                continue;
            vis[p.first*(m+1) + p.second] = true;
            res[p.first][p.second] = pStep;
            for (auto d : dxy) {
                int dx = p.first+d.first,dy = p.second+d.second;
                if (dx <= 0 || dx > n || dy <= 0 || dy > m)
                    continue;
                que.emplace(loc_t{dx,dy},pStep+1);
            }
        }

    };

    BFS(loc_t {x,y});
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}