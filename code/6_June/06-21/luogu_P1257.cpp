//
// Created by CZQ on 2024/6/21.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
//四舍五入保留  4 位小数。
using namespace std;
//using ull = unsigned long long;
//甚至不用优化
using loc = pair<int,int>;

double getDis(int x1 , int y1,int x2 , int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int main(){
     int n;
     cin >> n;
     vector<loc> maze(n);
     for(int i = 0 ; i < n; i++)
         cin >> maze[i].first >> maze[i].second;

    sort(maze.begin(),maze.end());
    double res = INT_MAX;
    for(int i = 0 ; i < n ; i++){
//        unsure
//        double curMinDis = INT_MAX;
        for(int j = i+1; j < n ; j++){
            res = min(res, getDis(maze[i].first,maze[i].second,maze[j].first,maze[j].second));
        }
    }



    cout << fixed << setprecision(4) << res;
    return 0;
}