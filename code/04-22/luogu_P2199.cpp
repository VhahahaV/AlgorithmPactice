//
// Created by CZQ on 2024/4/22.
//
#include "bits/stdc++.h"

//58min 36points
//a不了，e了
using namespace std;
using loc_t = pair<int,int>;
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> maze(N*M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <M; ++j) {
            char x;
            while(x = getchar()){
                if (x == 'O'){
                    maze[i*M+j] = 1;
                    break;
                }
                else if (x == 'X')
                    break;
                else
                    continue;
            }

        }
    }
    auto lookAt = [&](const int &x0, const int &y0,const int &x1,const int &y1)->bool{
        if (x0 == x1 && y0 == y1)
            return true;
        else if(x0 == x1 || y0 == y1 || abs(y1-y0) == abs(x1-x0)){
            if (x0==x1){
                int miny = min(y0,y1);
                int maxy = max(y0,y1);
                for (int i = miny+1; i < maxy; ++i) {
                    if (!maze[x0*M+i])
                        return false;
                }
                return true;
            }
            else if(y0==y1){
                int minx = min(x0,x1);
                int maxx = max(x0,x1);
                for (int i = minx+1; i < maxx; ++i) {
                    if (!maze[i*M+y0])
                        return false;
                }
                return true;
            }
            else{
                int minx = min(x0,x1);
                int k = (y1-y0) / (x1-x0);
                int starty = (minx == x0) ? y0 : y1;
                int dx = abs(x0-x1);
                for (int i = 1; i <= dx; ++i) {
                    if (!maze[(minx+i)*M+starty+i*k])
                        return false;
                }
                return true;
            }
        }
        return false;
    };
    vector<loc_t > dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    while (true){
        int initX,initY,endX,endY;
        cin >> initX >> initY >> endX >> endY;
        if (!initX)
            break;
        initX--,initY--,endX--,endY--;
        vector<int> steps(N*M,-1);
        auto BFS = [&](int x0, int y0,const int &x1,const int &y1)->int {
            queue<pair<loc_t,int>> queue1;
            queue1.emplace(loc_t {x0,y0},0);
            while (!queue1.empty()){
                auto [cur,pStep] = queue1.front();
                int curx =  cur.first,cury = cur.second;
                queue1.pop();
                if (steps[curx*M+cury] != -1)
                    continue;
                steps[curx*M+cury] = pStep;
                if (lookAt(curx,cury,x1,y1))
                    return pStep;
                for (auto dir : dirs) {
                    int dx = curx + dir.first,dy = cury + dir.second;
                    if (dx<0 || dx>=N || dy<0 || dy>=M || !maze[dx*M+dy])
                        continue;
                    else{
                        queue1.emplace(loc_t {dx,dy},pStep+1);
                    }
                }
            }
            return -1;
        };
        int res = BFS(initX,initY,endX,endY);
        if (res == -1)
            cout << "Poor Harry\n";
        else
            cout << res << '\n';
    }
    return 0;
}