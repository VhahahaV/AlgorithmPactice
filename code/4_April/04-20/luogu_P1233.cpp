//
// Created by CZQ on 2024/4/20.
//
#include "bits/stdc++.h"

using namespace std;
using stick = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<stick> sticks(n+1);
    for (int i = 1; i <=  n; ++i) {
        cin >> sticks[i].first >> sticks[i].second;
    }
    stable_sort(sticks.begin()+1,sticks.end(),
         [](stick x,stick y)->bool {return x.first < y.first;});
    vector<int> dp(n+1,-1);
    for(auto it : sticks){
        *(lower_bound(dp.begin()+1,dp.end(),it.second,greater<int>())) = it.second;
    }
    cout << lower_bound(dp.begin()+1,dp.end(),-1,greater<int>()) - dp.begin() - 1;
    return 0;
}