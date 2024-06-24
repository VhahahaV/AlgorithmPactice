//
// Created by CZQ on 2024/6/24.
//
#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned  long long;
constexpr ull MOD = 998244353;

ull ksm(ull a , ull n, ull mod){
    ull res = 1;
    ull base = a;
    while(n){
        if(n & 1){
            res = (res*base) % mod;
        }
        n = n >> 1;
        base = (base * base) % mod;
    }
    return res;
}

ull inv(ull a,ull mod){
    return ksm(a,mod-2,mod);
}


int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ull t , N;
    cin >> t >> N;
    vector<ull> acc(N + 1, 1),inv_acc(N + 1, 1) , invs(N+1,1);
    ull res = 0;
    for(ull i = 2 ; i <= N ; i++){
        acc[i] = (acc[i - 1] * i) % MOD;
        invs[i] = (MOD-MOD/i) * invs[MOD%i] % MOD;
    }

    for(ull i = 1 ; i <= N ; i++){
        inv_acc[i] = (inv_acc[i-1] * invs[i]) % MOD;
    }

    for(ull i = 0 ; i < t ; i++){
        ull n , m;
        cin >> m >> n;
        ull C1 = ((acc[m] % MOD) * (inv_acc[n] % MOD) % MOD * (inv_acc[m-n] % MOD)) % MOD;
        res ^= C1;
    }
    cout << res;
    return 0;
}