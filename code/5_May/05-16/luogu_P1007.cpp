//
// Created by CZQ on 2024/5/16.
//

#include "bits/stdc++.h"
using namespace std;

int main(){
    int len,num;
    cin >> len >> num;
    if(num == 0){
        cout << 0 << " "<< 0;
        return 0;
    }
    vector<int> pos(num);
    for(int i = 0 ; i < num; i++)
        cin >> pos[i];
    sort(pos.begin(),pos.end());
    auto midPlus = lower_bound(pos.begin(),pos.end(),len/2+1);
    auto midMinus = midPlus-1;
    int ansMin;
    if(midPlus == pos.end())
        ansMin = pos.back();
    else
        ansMin = max(*midMinus,len-*midPlus+1);
    int ansMax = max(pos.back(),len-pos.front()+1);
    cout << ansMin << " "<< ansMax;

    return 0;
}