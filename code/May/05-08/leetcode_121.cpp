//
// Created by VhahahaV on 2024/5/8.
//
#include "bits/stdc++.h"
using namespace std;
//37min
class Solution {
public:
// F[i][j] = max(F[i+1][j].max-F[i+1][j].min , a[i] - F[i+1][j].min ,
//                  F[i][j-1].max-F[i][j-1].min , F[i][j-1].max-a[j-1],)
    int maxProfit(vector<int>& prices) {
        // using date = pair<int,int>;
        // int n = prices.size();
        // vector<vector<date>> F(n,vector<date>(n));
        // for(int i = 0 ;i < n ; i++)
        //     F[i][i].first = prices[i] , F[i][i].second = prices[i];
        // // ((n-1)-0)
        // for(int interval = 1; interval <= n-1;interval++)
        //     for(int start = 0; start+interval<=n-1;start++){
        //         int end = start+interval;
        //         auto &_f = F[start+1][end], &__f = F[start][end-1];
        //         auto &f =  F[start][end];
        //         f.first = min(_f.first,prices[start]);
        //         f.second = max(__f.second,prices[end]);
        //     }
        // return (F[0][n-1].second - F[0][n-1].first);
        int minPrice = 1e9,maxPro = 0;
        for(auto p : prices){
            maxPro = max(maxPro,p - minPrice);
            minPrice = min(p,minPrice);
        }
        return maxPro;
    }
};