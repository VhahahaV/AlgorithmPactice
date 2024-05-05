//
// Created by VhahahaV on 2024/4/27.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        // if(grid == nullptr)
        //     return nullptr;
        int col_size = grid[0].size();
        vector<int> ans(col_size);
        for(auto &row : grid){
            for(int i = 0; i < col_size;i++)
                ans[i] = max(ans[i],getLen(row[i]));
        }
        return ans;
    }
    int getLen(int x){
        int len = 0;
        if(!x)
            return 1;
        else if(x < 0){
            len = 1;
            x *= -1;
        }
        while(x){
            len++;
            x /= 10;
        }
        return len;
    }
};