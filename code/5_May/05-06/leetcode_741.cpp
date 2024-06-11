//
// Created by CZQ on 2024/5/6.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
// F[i][j]为玩家走到F[i][j]时能拿到的最多的樱桃
// DP问题： F[i][j] = (F[i-1][j] , F[i][j-1]) + grid[i][j]
    using loc_t = pair<int,int>;
    int cherryPickup(vector<vector<int>>& grid) {
        int nRows = grid.size(),nCols = grid.front().size();
        vector<vector<int>> F(nRows,vector<int>(nCols));
        F[0][0] = grid[0][0];
        auto lastloc = [&](loc_t a) ->vector<loc_t>{
            auto i = a.first, j = a.second;
            vector<loc_t> res;
            if(i-1 >= 0)
                if (grid[i-1][j] != -1)
                    res.emplace_back(i-1,j);
            if(j-1 >= 0 )
                if (grid[i][j-1] != -1)
                    res.emplace_back(i,j-1);
            return res;
        };
        for(int i = 0 ; i < nRows ; i++){
            for(int j = 0 ; j < nCols ; j++){
                if(i == 0 && j == 0 || grid[i][j] == -1)
                    continue;
                auto laststep = lastloc(loc_t{i,j});
                if (laststep.empty())
                    continue;
                int ans = 0;
                for(auto &f : laststep){
                    auto _i = f.first , _j = f.second;
                    ans = max<int>(ans,F[_i][_j]);
                }
                F[i][j] = ans + grid[i][j];
            }
        }
        //before findPath:
//1 -1 -1 -1 -1
//1 0 1 -1 -1
//0 -1 1 0 1
//1 0 1 1 0
//-1 -1 -1 1 1
//after findPath:
//0 -1 -1 -1 -1
//0 0 1 -1 -1
//0 -1 1 0 1
//0 0 0 0 0
//-1 -1 -1 0 0
        auto findPath = [&]()->bool {
            int i = nRows-1,j = nCols-1;
            while(true){
                int flag = 0,curF = F[i][j];
                if(grid[i][j] == 1)
                    grid[i][j] = 0 , flag = 1;
                if (i == 0 && j == 0)
                    break;
                auto laststep = lastloc(loc_t{i,j});
                if(laststep.empty())
                    return false;
                for(auto &f : laststep){
                    auto _i = f.first , _j = f.second;
                    if(F[_i][_j] == curF-flag)
                        i = _i , j = _j;
                }
            }
            grid[0][0] = 0;

            return true;
        };
        cout << "before findPath: \n";
        printGrid(grid);
        if(!findPath())
            return 0;
        cout << "after findPath: \n";
        printGrid(grid);


        vector<vector<int>> _F(nRows,vector<int>(nCols));
        _F[nRows-1][nRows-1] = grid[nRows-1][nRows-1];
        auto _lastloc = [&](loc_t a) ->vector<loc_t>{
            auto i = a.first, j = a.second;
            vector<loc_t> res;
            if(i+1 < nRows)
                if ( grid[i+1][j] != -1)
                    res.emplace_back(i+1,j);
            if(j+1 < nCols )
                if( grid[i][j+1] != -1)
                    res.emplace_back(i,j+1);
            return res;
        };
        for(int i = nRows-1 ; i >= 0 ; i--){
            for(int j = nCols -1 ; j >= 0  ; j--){
                if(i == nRows-1 && j == nCols -1 || grid[i][j] == -1)
                    continue;
                auto laststep = _lastloc(loc_t{i,j});
                if (laststep.empty())
                    continue;
                int ans = 0;
                for(auto &f : laststep){
                    auto _i = f.first , _j = f.second;
                    ans = max<int>(ans,_F[_i][_j]);
                }
                _F[i][j] = ans + grid[i][j];
            }
        }

        return  F[nRows-1][nCols-1] + _F[0][0];

    }

    void printGrid(const vector<vector<int>> &grid){
        int nRows = grid.size(),nCols = grid.front().size();
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }
};


int main(){
//    vector<vector<int>> grid{{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
//    vector<vector<int>> grid{{0,1,-1},{1,0,-1},{1,1,1}};
    vector<vector<int>> grid{{1,-1,-1,-1,-1},{1,0,1,-1,-1},{0,-1,1,0,1},{1,0,1,1,0},{-1,-1,-1,1,1}};

    Solution solution;
    cout << solution.cherryPickup(grid);

//   错误解法，应该使用三维DP……
//略
    return 0;
}