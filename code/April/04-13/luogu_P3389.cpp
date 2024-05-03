//
// Created by VhahahaV on 2024/4/13.
//
#include "bits/stdc++.h"

using namespace std;

////需要考虑如果主元为零的话，需要行交换

void Regularization(vector<double> &f,int offset){
    double size = f[offset];
    for (int i = offset; i < f.size(); ++i) {
        f[i] /= size;
    }
}

void Elimination(const vector<double> &f1,vector<double> &f2,int offset){
    double size = f2[offset];
    for (int i = offset; i < f2.size(); ++i) {
        f2[i] -= (size * f1[i]);
    }
}


int main(){
    int M;
    cin >> M;
    vector<vector<double>> formulas(M,vector<double>(M+1));
    for (int i = 0; i < M; ++i) {
        auto &f = formulas[i];
        for (int j = 0; j <= M; ++j) {
            cin >> f[j];
        }
    }

    for (int i = 0; i < M; ++i) {
        auto &f1 = formulas[i];
        if(f1[i] == 0){
            int offset = i;
            while (f1[i] == 0) {
                swap(formulas[i],formulas[(offset+1)%M]);
                offset = (offset+1)%M;
                if (!offset){
                    cout << "No Solution";
                    return 0;
                }
            }

            f1 = formulas[i];
        }
        Regularization(f1,i);
        for (int j = i+1; j < M; ++j) {
            auto &f2 = formulas[j];
            Elimination(f1,f2,i);
        }
    }

    vector<double> res(M);

    for (int i = M-1; i >= 0 ; --i) {
        auto &f1 = formulas[i];
        for (int j = i-1; j >= 0 ; --j) {
            auto &f2 = formulas[j];
            Elimination(f1,f2,i);
        }
        if (f1[i] != 1){
            cout << "No Solution";
            return 0;
        }
        res[i] = f1[M];
    }

    for(auto it : res)
        cout <<  fixed << setprecision(2) <<it << endl;

    return 0;
}