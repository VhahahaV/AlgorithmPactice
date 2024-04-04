//
// Created by CZQ on 2024/4/4.
//

#include "bits/stdc++.h"

using namespace std;

class PrimeEhrilich{
private:
    vector<bool> mIsPrime;
public:
    PrimeEhrilich(int n):mIsPrime(n, true){
        mIsPrime[0] = mIsPrime[1] = false;
        for(int i=2; i<n; i++){
            if(mIsPrime[i]){
                int m=2;
                while (m*i < mIsPrime.size()){
                    mIsPrime[m*i] = false;
                    m++;
                }
            }
        }
    }
    bool isPrime(int x)const{
        return mIsPrime.at(x);
    }
};
vector<int> isPrimeEhrlich(int a){
    vector<bool> vis(a);
    vector<int> primes;
    vis[0] = vis[1] = true;
    for (int i = 2; i < a; ++i) {
        if(!vis[i])
            primes.emplace_back(i);
        for (int j = 2; j * i <= a ; ++j) {
            vis[j*i] = true;
        }
    }
    return primes;
}


vector<int> isPrimeEuler(int a){
    vector<bool> vis(a);
    vector<int> primes;
    vis[0] = vis[1] = true;

    for (int i = 2; i < a; ++i) {
        if(!vis[i])
            primes.emplace_back(i);
        for (int j = 0; j < primes.size(); ++j) {

            if (i*primes[j] > a)
                break;

            vis[i * primes[j]] = true;

//            如果i含有最小素数因数 prime[j] 后，则后面的循环到的 i' * prime[j] 必能代替 i * prime[j+1] ，且 i' % prime[j] != 0
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}

bool is_prim(int n){
    int i;
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else
    {
        for (i = 2; i <= (int)sqrt(n) + 1; i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,num;
    vector<int> nums;
    cin >> a >> num;
    for (int i = 0; i < num; ++i) {
        int tmp;
        cin >> tmp;
        nums.emplace_back(tmp);
    }

    vector<int> res;
    res = isPrimeEuler(a);
    for (int i = 0; i < num; ++i) {
        cout << res[nums[i]-1] << '\n';
    }


}