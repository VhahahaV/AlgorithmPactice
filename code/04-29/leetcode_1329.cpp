//
// Created by VhahahaV on 2024/4/29.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    using loc_t = pair<int,int>;
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        for(int i = 0 ; i < mat.size(); i++){
            loc_t cur{i,0};
            vector<loc_t> elements = getAll(cur,mat);
            vector<int> vals;
            for(auto &cur : elements){
                vals.emplace_back(mat[cur.first][cur.second]);
            }
            sort(vals.begin(),vals.end());
            for(int j = 0 ; j < elements.size();j++){
                auto &cur = elements[j];
                mat[cur.first][cur.second] = vals[j];
            }
        }
        for(int i = 1 ; i < mat[0].size(); i++){
            loc_t cur{0,i};
            vector<loc_t> elements = getAll(cur,mat);
            vector<int> vals;
            for(auto &cur : elements){
                vals.emplace_back(mat[cur.first][cur.second]);
            }
            sort(vals.begin(),vals.end());
            for(int j = 0 ; j < elements.size();j++){
                auto &cur = elements[j];
                mat[cur.first][cur.second] = vals[j];
            }
        }
        return mat;
    }
    vector<loc_t> getAll(loc_t i,const vector<vector<int>>& mat){
        vector<loc_t> elements;
        auto &x = i.first, &y = i.second;
        int size_x = mat.size(),size_y = mat[0].size();
        while(x< size_x && y < size_y)
            elements.emplace_back(x++,y++);

        return elements;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    solution.diagonalSort(mat);
    return 0;

}