//
// Created by CZQ on 2024/6/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Time = std::pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<Time> times(n);
    for( int  i = 0 ; i < n ; i++){
        cin >> times[i].second >> times[i].first;
    }
    sort(times.begin(),times.end());
    int sum = 0;
    int curPlace = 0;
    for(auto &[e,s] : times){
        if(s >= curPlace){
            sum++;
            curPlace=e;
        }
    }
    cout << sum;
}