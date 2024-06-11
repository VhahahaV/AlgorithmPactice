//
// Created by CZQ on 2024/5/18.
//
#include<iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
//12min
int main(){
    ull M;
    cin >> M;
    vector<pair<int,int>> ans;
    for(ull right = 2,left = 1;right <= M/2+1;right++){
        ull sum = (right+left)*(right-left+1)/2;
        while (sum > M){
            sum-=left;
            left++;
        }
        if(sum==M)
            ans.emplace_back(left,right);

    }
    for(auto &[l,r]:ans){
        cout << l << " "<< r << '\n';
    }

    return 0;
}