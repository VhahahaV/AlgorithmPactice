//
// Created by CZQ on 2024/4/24.
//
#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    using loc_t = pair<int, int>;
    int m, n; cin >> m >> n;
    auto isValidLoc = [m,n](const loc_t& loc)->bool {
        if(loc.first < 0 || loc.first >= m) return false;
        if(loc.second < 0 || loc.second >= n) return false;
        return true;
    };
    vector<vector<bool>> maze(m, vector<bool>(n));
    loc_t locA, locB;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            while (true) {
                auto c = (char) getchar();
                if(c == 'X') maze[i][j] = false;
                else if(c == 'O') maze[i][j] = true;
                else if(c == 'A'){
                    maze[i][j] = true;
                    locA = {i, j};
                } else if(c == 'B'){
                    maze[i][j] = true;
                    locB = {i, j};
                } else continue;
                break;
            }
        }
    }
    const vector<loc_t> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<loc_t>> prevLocs(m, vector<loc_t>(n, {-1, -1}));
    // BFS
    queue<pair<loc_t, loc_t>> q;
    q.emplace(locA, locA);
    while (!q.empty()){
        auto [currentLoc, prevLoc] = q.front();
        q.pop();
        auto& storedLoc = prevLocs[currentLoc.first][currentLoc.second];
        if(storedLoc != make_pair(-1, -1)) continue;
        storedLoc = prevLoc;
        if(currentLoc == locB) break;
        for(auto [dx, dy]: dxy){
            loc_t nextLoc = {currentLoc.first+dx, currentLoc.second+dy};
            if(!isValidLoc(nextLoc)) continue;
            if(!maze[nextLoc.first][nextLoc.second]) continue;
            q.emplace(nextLoc, currentLoc);
        }
    }
    vector<vector<bool>> line(m, vector<bool>(n, false));
    // Backward
    for(auto [currentLoc, prevLoc] = make_pair(locB, prevLocs[locB.first][locB.second]);;
        tie(currentLoc, prevLoc) = make_pair(prevLoc, prevLocs[prevLoc.first][prevLoc.second])){
        line[currentLoc.first][currentLoc.second] = true;
        if(currentLoc == locA) break;
    }
    // Output
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!maze[i][j]){
                cout << 'X';
            } else if(line[i][j]){
                cout << 'o';
            } else {
                cout << '.';
            }
            if(j+1 == n){
                cout << '\n';
            } else {
                cout << ' ';
            }
        }
    }
    return 0;
}