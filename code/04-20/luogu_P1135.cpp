//
// Created by CZQ on 2024/4/20.
//

#include "bits/stdc++.h"

using namespace std;

//用时19min
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    vector<int> floor(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> floor[i];
    }
    vector<int> ans(N+1);
    auto bfs = [&](int start,int end)->int {
        if (start ==  end)
            return 0;
        queue<int> nodes;
        nodes.push(start);
        while(!nodes.empty() && !ans[end]){
            int cur = nodes.front();
            nodes.pop();
            int up = cur + floor[cur],down  = cur - floor[cur];
            if (up > 0 && up <= N && !ans[up]){
                nodes.push(up);
                ans[up] = ans[cur] + 1;
            }
            if (down > 0 && down <= N && !ans[down]){
                nodes.push(down);
                ans[down] = ans[cur] + 1;
            }
        }
        if (ans[end])
            return ans[end];
        else
            return -1;
    };
    cout << bfs(A,B);
    return 0;
}