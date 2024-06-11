//
// Created by CZQ on 2024/5/16.
//
#include "bits/stdc++.h"
using namespace std;

int main(){
    int m,n,k,l,d;
    cin >> m>> n >> k >> l >> d;
    auto cmp = [](const pair<int,int> a, const pair<int,int> b)->bool {
        return a.second > b.second;
    };
    map<int,int> horizontal;
    map<int,int> vertical;
    for(int i = 0 ; i < d ; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(y1 == y2){
            horizontal[min(x1,x2)]++;
        }
        else{
            vertical[min(y1,y2)]++;
        }
    }
    vector<pair<int,int>> horizontal_vec;
    vector<pair<int,int>> vertical_vec;
    for(auto it : horizontal)
        horizontal_vec.emplace_back(it.first,it.second);
    for(auto it : vertical)
        vertical_vec.emplace_back(it.first,it.second);
    sort(horizontal_vec.begin(),horizontal_vec.end(),cmp);
    sort(vertical_vec.begin(),vertical_vec.end(),cmp);
    sort(horizontal_vec.begin(),horizontal_vec.begin()+k);
    sort(vertical_vec.begin(),vertical_vec.begin()+l);
    for(auto &[y,v] : horizontal_vec){
        if(!k--) break;
        cout << y << " ";
    }
    cout << '\n';
    for(auto &[x,v] : vertical_vec){
        if(!l--) break;
        cout << x<< " ";
    }
    return 0;
}