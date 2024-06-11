//
// Created by VhahahaV on 2024/4/2.
//

#include <bits/stdc++.h>
using namespace std;

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
    string word;
    cin >> word;
    int num[26];
    memset(num,0,sizeof(num));
    for(auto i : word){
        if (i <= 'z' &&i >= 'a')
        num[i-'a']++;
    }
    sort(num,num+26);
    int res = 0;
    for(int i : num) {
        if (i != 0){
            res = i;
            break;
        }
    }
    res = num[25] - res;
    if(is_prim(res))
        std::cout << "Lucky Word" << std::endl << res;
    else
        std::cout << "No Answer" << std::endl << 0;

}