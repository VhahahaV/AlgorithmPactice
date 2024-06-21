//
// Created by CZQ on 2024/6/21.
//
#include <iostream>

using namespace std;
using ull = unsigned long long;
constexpr ull MOD = 6662333;

ull Ksm(ull n){
    //计算2的n次方
    ull base = 2;
    ull res = 1;
    while(n){
        if(n & 1){
            res = (res * base)%MOD;
        }
        n  = n >> 1;
        base = (base * base) % MOD;
    }
    return res;
}

int main(){
    ull n;
    cin >> n;
//    n为奇数
    ull res = Ksm(n);
    if(res & 1){
        cout << (res + MOD) / 2;
    }
    else
        cout << res / 2;

    return 0;
}