//
// Created by CZQ on 2024/5/18.
//
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
//37min
int main() {
    int n, a ;
    auto getPrimes = [&](vector<int> &coff,int num){
        for (int i = 2; i*i<=num;i++) {
            while(num%i == 0){
                coff[i]++;
                num /= i;
                if(num <= 1) return ;
            }
        }
        if(num>1) coff[num]++;
    };
    while (cin >> n >> a) {
        vector<int> primes_n(n + 1);
        vector<int> primes_a(a+1);
        getPrimes(primes_a, a);
        for(int i = 2;i <= n ;i++){
            getPrimes(primes_n, i);
        }
        int  k = INT32_MAX;
        for(int i = 2; i <= a ; i++){
            if(primes_a[i])
                k = min(k , primes_n[i]/primes_a[i]);
        }
        cout << k << '\n';
    }


}
// 64 位输出请用 printf("%lld")