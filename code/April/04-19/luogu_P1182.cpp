//
// Created by CZQ on 2024/4/19.
//

#include "bits/stdc++.h"

using ll = long long ;
using namespace std;
using line = pair<int,int>;

//最大值的最小  最小值最大 都可以用二分来写
//二分模板
/*
 * while( l < r){
 *      int mid = (r + l ) / 2;
 *      if ( check(mid) )
 *          r = mid;
 *      else
 *          l = mid + 1;
 * }
 * */

//对于最大值最小
/*
 * while( l < r){
 *      int mid = (r + l  + 1) / 2;
 *      if ( check(mid) )
 *          r = mid;
 *      else
 *          l = mid - 1;
 * }
 * */

//对于最小值最大
/*
 *
 * while( l < r){
 *      int mid = (r + l ) / 2;
 *      if ( check(mid) )
 *          l = mid;
 *      else
 *          r = mid;
 * }
 */

int r = 1e9 + 1, l = 0;
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> nums(N);
    vector<line> lines;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        l = max(l , nums[i]);
    }
//    val为预计的最大值的最小值，如果满足题意就返回true
    auto check = [&](int val) ->bool {
        int total = 1;
        int sum = 0;
        for(auto it : nums){
            if (sum + it <= val)
                sum += it;
            else{
                sum = it;
                total++;
            }
        }
        if (total <= M)
            return true;
        else
            return false;
    };
//左闭右开
    while( l < r){
        int mid = ( l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;


    return 0;
}