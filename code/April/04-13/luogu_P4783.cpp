//
// Created by CZQ on 2024/4/13.
//
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
constexpr ll MAX= 1e9+7;

ll Ksm(ll x, ll y = MAX-2){
    ll ans = 1;
    while (y > 0){
        if (y&1){
            ans = (ans*x)%MAX;
        }
       ( x *= x) %= MAX;
       y = y >> 1;
    }
    return ans;
}

ll Regularization(vector<ll> &f,int offset){
    ll inv = Ksm(f[offset]);
    for (int i = offset; i < f.size(); ++i) {
        f[i] =((f[i]*inv) % MAX + MAX) % MAX;
    }
    return inv;
}

void Elimination(const vector<ll> &f1,vector<ll> &f2,int offset){
    ll size = f2[offset];
    for (int i = offset; i < f2.size(); ++i) {
        f2[i] -= ((size * f1[i]) % MAX + MAX) % MAX;
    }
}

void Scale(vector<ll> &f,int offset,ll inv){
    for (int i = offset; i < f.size(); ++i) {
        f[i] =((f[i]*inv) % MAX + MAX) % MAX;
    }
}

int main(){
    int M;
    cin >> M;
    vector<vector<ll>> matrix(M,vector<ll>(M));
    vector<vector<ll>> inv_matrix(M,vector<ll>(M));
    for (int i = 0; i < M; ++i) {
        auto &f = matrix[i];
        for (int j = 0; j < M; ++j) {
            cin >> f[j];
        }
        inv_matrix[i][i] = 1;
    }

    for (int i = 0; i < M; ++i) {
        auto &f1 = matrix[i];
        auto &inv_f1 = inv_matrix[i];
        if(f1[i] == 0){
            int offset = i;
            while (f1[i] == 0) {
                swap(matrix[i],matrix[(offset+1)%M]);
                swap(inv_matrix[i],inv_matrix[(offset+1%M)]);
                offset = (offset+1)%M;
                if (!offset){
                    cout << "No Solution";
                    return 0;
                }
            }

            f1 = matrix[i];
            inv_f1 = inv_matrix[i];
        }
        ll scaleSize = Regularization(f1,i);
        Scale(inv_f1,i, scaleSize);
        for (int j = i+1; j < M; ++j) {
            auto &f2 = matrix[j];
            Elimination(f1,f2,i);
            auto &inv_f2 = inv_matrix[j];
            Elimination(inv_f1,inv_f2,i);
        }
    }

    for (int i = M-1; i >= 0 ; --i) {
        auto &f1 = matrix[i];
        auto &inv_f1 = inv_matrix[i];
        for (int j = i-1; j >= 0 ; --j) {
            auto &f2 = matrix[j];
            Elimination(f1,f2,i);
            auto &inv_f2 = inv_matrix[j];
            Elimination(inv_f1,inv_f2,i);
        }
        if (f1[i] != 1){
            cout << "No Solution";
            return 0;
        }
    }


    for(auto f : inv_matrix){
        for(auto item : f)
            cout << item << " ";
        cout << endl;
    }
    


    return 0;
}