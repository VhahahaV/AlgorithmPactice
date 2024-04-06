//
// Created by CZQ on 2024/4/6.
//
#include "bits/stdc++.h"
using ll = long long;
using namespace std;
int n,m;

bool isOk(int x ,const vector<int> &rooms ,const vector<vector<int>> &orders){
    vector<unsigned int> cf(n+2 , 0);
    for (int i = 0; i < x; ++i) {
        cf.at(orders.at(i).at(1)) += orders.at(i).at(0);

        cf.at(orders.at(i).at(2) + 1) -= orders.at(i).at(0);
    }
    unsigned int sum = 0;
    for (int i = 1; i <= n ; ++i) {
        sum+=cf.at(i);
        if (sum > rooms.at(i)){
            return false;
        }
    }
    return true;
}
int main(){
//AC 二分判断 + 差分计算sum
    cin >> n >> m;
    vector<int> rooms(n + 1);
    for (int i = 1; i <= n ; ++i) {
        cin >> rooms[i];
    }

    vector<vector<int>> orders(m,vector<int>(3));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> orders[i][j];
        }
    }
    if(isOk(m,rooms,orders))
    {
        cout<< 0;
        return 0;
    }

    int l = 1 , r = m;
    while (l < r){
        int  mid = (l + r) / 2;
        if (isOk(mid,rooms,orders))
            l = mid+1;
        else
            r = mid;
    }
    cout << -1<< endl << l;
    return 0;

//    暴力枚举，TML，拿了60分
//    int n,m;
//    cin >> n >> m;
//    vector<int> rooms(n+1);
//    for (int i = 1; i <= n ; ++i) {
//        cin >> rooms[i];
//    }
//
//    vector<vector<int>> orders(m,vector<int>(3));
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cin >> orders[i][j];
//        }
//    }
//    for(int index = 0 ; index < orders.size() ; index++){
//        int d = orders[index][0], s = orders[index][1],t = orders[index][2];
//        for (int i = s; i <=  t; ++i) {
//            if (rooms[i] >= d)
//                rooms[i] -= d;
//            else{
//                cout << -1 << endl << index+1;
//                return 0;
//            }
//        }
//    }
//    cout << 0;
//    return 0;
}