//
// Created by VhahahaV on 2024/4/30.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // (0, nCols-1) = 1-nCols
        // (nRows-1, 0) = nRows-1
        int nRows = (int)mat.size();
        int nCols = (int)mat.front().size();
        vector<vector<int>> buckets(101);
        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                buckets.at(mat[i][j]).emplace_back(i-j);
            }
        }
        vector<int> idxs(nCols+nRows-1, 0);
        for(int val=0; val<buckets.size(); val++){
            for(auto i_sub_j: buckets[val]){
                // i-j = diagIdx
                auto& idx = idxs[i_sub_j+nCols-1];
                int i,j;
                if(i_sub_j >= 0){// i >= j
                    j = idx;
                    i = i_sub_j+j;
                } else {// i < j
                    i = idx;
                    j = i-i_sub_j;
                }
                idx++;
                mat[i][j] = val;
            }
        }
        return mat;
    }
};