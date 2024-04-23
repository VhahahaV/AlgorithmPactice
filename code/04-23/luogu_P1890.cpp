//
// Created by VhahahaV on 2024/4/23.
//

//10min -> 90 points
//需要用线段树优化，来日再战
//线段树参考： https://zhuanlan.zhihu.com/p/106118909

#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
//    默认a>b
    auto gcd = [&](int a , int b ) -> int {
        if (a < b)
            swap(a,b);
        int tmp = a % b;
        while (tmp){
            a = b;
            b = tmp;
            tmp = a % b;
        }
        return b;
    };

    auto findMaxGcd = [&](int l ,int r)-> int {
        if (l == r)
            return nums[l];
        int res = gcd(nums[l],nums[l+1]);
        for (int i = l+2; i <= r; ++i) {
            res = gcd(res,nums[i]);
            if (res == 1)
                return 1;
        }
        return res;
    };
    while (m--){
        int l,r;
        cin >> l >> r;
        cout << findMaxGcd(l,r) << '\n';
    }
    return 0;
}