//
// Created by CZQ on 2024/4/18.
//
#include "bits/stdc++.h"

using namespace std;
//并查集
vector<int> father;
int N,M;
int setNum = 0;
int findRoot(int x){
    if (x!=father[x])
        father[x] = findRoot(father[x]);
    return x;
}

void jointSet(int x, int y){
    int father1 = findRoot(x);
    int father2 = findRoot(y);
    if (father1 != father2){
        father[father1] = father[father2];
        setNum--;
    }
}

vector<int> getNeighbors(int x){
    vector<int> delta = {0,-1,1};
    vector<int> res;
    int row = x/M,col = x%M;
    for(auto deltaX: delta)
        for(auto deltaY : delta){
            if (deltaX == 0 && deltaY == 0
                ||row+deltaY < 0 || row+deltaY >= N || col+deltaX < 0 || col+deltaX>= M
                ||father[x + deltaX + deltaY*M] == -1)
                continue;
            else
                res.emplace_back(x + deltaX + deltaY*M);
        }
    return res;

}

int main(){
    cin >> N >> M;
    vector<vector<char>> place(N,vector<char>(M));
    father.resize(N*M,-1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> place[i][j];
            if (place[i][j] == 'W'){
                father[i*M+j]= i*M+j;
                setNum++;
            }
        }
    }
    for (int i = 0; i < N * M; ++i) {
        if (place[i/M][i%M] == '.')
            continue;
        vector<int> neighbors = getNeighbors(i);
        for (auto neighbor : neighbors) {
            jointSet(neighbor,i);
        }
    }
    cout << setNum;
    return 0;
}
