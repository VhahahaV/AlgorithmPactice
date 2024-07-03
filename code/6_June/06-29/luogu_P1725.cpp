//
// Created by VhahahaV on 2024/6/29.
//
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N , L , R;
    cin >> N >> L >> R;
    vector<int> nums(N+1);
    for(int i = 0 ; i <= N;i++){
        cin >> nums[i];
    }
    vector<int> ans(N+1+L);
    deque<pair<int,int>> maxNums;
//    [K - R + L ,  K] -> K+L
//    维护单调队列
    int p = 0;
    for (int i = L; i <= N; i++) {
        if(!maxNums.empty() && maxNums.back().first <= ans[p]){
            maxNums.pop_back();
        }

        maxNums.emplace_back(ans[p],p);
        while (maxNums.front().second + R < i ){
            maxNums.pop_front();
        }
        ans[i] = nums[i]+maxNums.front().first;
        p++;
    }

    int maxDis = std::numeric_limits<int>::min();;

    for(int i = N - R + 1; i <= N; i++){
        if(i % R && i%R < L) continue;
        maxDis = max(maxDis,ans[i]);
    }
    cout << maxDis;

    return 0;
}/**/