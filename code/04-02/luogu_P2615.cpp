//
// Created by VhahahaV on 2024/4/2.

//
#include<iostream>
#include<vector>
#include "cstring"

using namespace std;

int main(){
    int N ;
    cin >> N;
    int res[40][40];
    memset(res,0, sizeof(res));
    int mid = N / 2;
    res[0][mid] = 1 ;
    int max = N * N;
    for(int i  = 1 ; i < max ; i++){
        int preRow = (i - 1) / max;
        int preCol =  (i - 1) % max;
        if(preRow == 0 && preCol < N - 1){
            res[N-1][preCol + 1] = i;
        }
        else if (preRow != 0 && preCol == N - 1){
            res[preRow - 1][0] = i;
        }
        else if (preRow == 0 && preCol == N - 1){
            res[preRow + 1][preCol] = i;
        }
        else if (res[preRow - 1][preCol + 1] == 0){
            res[preRow - 1][preCol + 1] = i;
        }
        else
            res[preRow - 1][preCol] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

};