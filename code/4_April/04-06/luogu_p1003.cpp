//
// Created by CZQ on 2024/4/6.
//
#include "bits/stdc++.h"

using namespace std;

int main(){
    int maxY = 0,maxX = 0;
    int num;
    cin >> num;
    vector<vector<int>> rugs;

    rugs.resize(num);
    for (int i = 0; i < num; ++i) {
        int tmp;
        for (int j = 0; j < 4; ++j) {
            cin >> tmp;
            if (j == 2)
                tmp = tmp+rugs[i][0];
            if (j == 3)
                tmp = tmp+rugs[i][1];
            rugs[i].emplace_back(tmp);
        }
    }
   

    int x,y;
    cin >> x >> y;
    int flag = false;
    for (int i = num-1; i >= 0; --i) {
        int x1 = rugs[i][0],y1 = rugs[i][1],x2 = rugs[i][2],y2 = rugs[i][3];
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2){
            cout << i+1;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << -1;

}