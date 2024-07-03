//
// Created by VhahahaV on 2024/7/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
constexpr int MOD = 80112002;

using namespace std;
int n , m;
vector<vector<int>> mat;
vector<int> nums;

using ull = unsigned long long;

//25mins
ull dfs(ull cur){
    if(nums[cur])
        return nums[cur];

    ull ans = 0;
    for(auto nex : mat[cur]){
        ans = (ans + dfs(nex)) % MOD;
    }
    nums[cur] = ans;
    return ans;
}

int main(){
    cin >> n >> m;
    map<int,int> eating;
    map<int,int> ate;
    mat.resize(n+1);
    nums.resize(n+1);

    for(int i = 0 ; i < m ;i++) {
        int A,B;
        cin >> A >> B;
        mat[B].emplace_back(A);
        eating[B]++;
        ate[A]++;
    }
    for(int i = 1 ; i <= n ; i++){
        if(!eating[i])
            nums[i] = 1;
    }

    ull ans = 0;
   for(int i = 1 ; i <= n ; i++){
       if(!ate[i]){
           dfs(i);
           ans = (ans + nums[i]) % MOD;
       }
   }

   cout << ans;

    return 0;
}