#include "bits/stdc++.h"

using namespace std;
#define ull unsigned long long
#define BASE 62
constexpr auto MOD = std::numeric_limits<ull>::max();
int getInt(char i);
ull getHash(string tmp){
    ull res = 0;
    for(auto i : tmp){
        int a = getInt(i);
        res =( res*BASE + a) % MOD;
    }
    return res;
}
int getInt(char i){
    if (i >= '0' && i <= '9')
        return i-'0';
    else if (i >= 'a' && i <= 'z')
        return i-'a'+10;
    else
        return i-'A'+36;
}
int main(){
    int num;
//    hash<ull>
    unordered_map<ull,bool> res;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        string tmp;
        cin >> tmp;
        ull hashInt = getHash(tmp);

        if (res.find(hashInt) == res.end())
            res.emplace(hashInt, true);
    }
    cout << res.size();
}