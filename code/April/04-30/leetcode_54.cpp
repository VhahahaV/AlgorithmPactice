//
// Created by VhahahaV on 2024/4/30.
//
#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sum = matrix.size() * matrix[0].size();
        int i  = 0,j = 0;
        int flag = 0;
        vector<int> ans;

        const int nRows = matrix.size(), nCols = matrix[0].size();
        auto shouldTurn = [&](int i , int j, int flag)->bool {
            int round = flag / 4;
            int curRows = nRows - round;
            int curCols = nCols - round;
            int dir = flag % 4;
            if (dir == 0 && j == curCols-1)
                return true;
            if(dir == 1 && i == curRows-1)
                return true;
            if(dir == 2 && j == round)
                return true;
            if(dir == 3 && i==round+1)
                return true;
            return false;
        };

        vector<pair<int,int>> dxys = { {0,1}, {1,0},{0,-1},{-1,0}};
        for (int step = 0; step < sum; ++step) {
            ans.emplace_back(matrix[i][j]);
//            turn
            if(shouldTurn(i,j,flag)){
                flag++;
            }
            auto dxy = dxys[flag%4];
            i += dxy.first;
            j += dxy.second;
        }
        return ans;
    }
};
