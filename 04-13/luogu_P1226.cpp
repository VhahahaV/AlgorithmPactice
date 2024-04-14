//
// Created by CZQ on 2024/4/13.
//
#include "bits/stdc++.h"

using namespace std;
using ull = uint64_t;
using ll = int64_t;

ll FastPow(const ll &a,ll b, const ll &p){
    ll res = 1LL;
    for (ll i = 1LL; i <= b; i++) {
        res *= a;
        if (res >= p){
            res %= p;
            res = FastPow(res,b/i,p);
            b = b%i,i=0;
        }
    }
    return res;
}
ll fastPow(ll n, ll k, ll p){
    ll ans = 1;
    while(k > 0){
        if(k & 1){
            ans *= n;
            ans %= p;
        }
        n *= n;
        n %= p;
        k >>= 1;
    }
    return ans;
}

ll fastPow2(ll n , ll k , ll p){
    ll res = 1,base = n;
    while (k > 0){
        if (k & 1)
            (res *= base)%=p;

        (base *= base)%=p;
        k >>= 1;

    }
    return res;
}
int main(){
    ll a ,b,p;
    cin >> a >> b >> p;
    cout << a<<'^'<<b<<" mod "<<p<<'='<<fastPow2(a%p,b,p);
    return 0;
}