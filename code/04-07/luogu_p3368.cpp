//
// Created by CZQ on 2024/4/7.
//
#include "bits/stdc++.h"
//差分 ＋ 树状数组
//树状数组 参考： https://blog.csdn.net/TheWayForDream/article/details/118436732
//树状数组分两种情况：
// 1.单点修改，区间查询 ，直接对原数组构造树状数组
// 2.单点查询，区间修改 ， 对原数组的差分数组构造树状数组来单点查询，区间修改
#define ll long long
using namespace std;
ll N,M;

ll lowBit(ll a){
    return a & (-a);
}

void updateBIT(vector<ll> &BIT,ll pos,ll val){
//    使用lowBit函数的时候应该注意输入的参数为 i ，而不是pos, i才是当前节点的位置
    for (ll i = pos; i <= N+1; i += lowBit(i)) {
        BIT.at(i) += val;
    }
}

ll getBIT(const vector<ll>&BIT,ll pos){
    ll sum = 0;
    for (ll i = pos; i > 0; i-= lowBit(i)) {
        sum += BIT.at(i);
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> N >> M;
    vector<ll> init(N+1);
    for (ll i = 1; i <= N; ++i) {
        cin >> init.at(i);
    }

//   对差分数组构造 树状数组
    vector<ll> BIT(N+2);

    for (ll i = 0; i < M; ++i) {
        ll tmp;
        cin >> tmp;
        if (tmp == 1){
            ll start,end,k;
            cin >> start >> end >> k;
            updateBIT(BIT,start,k);
            updateBIT(BIT,end+1,-k);
        }
        else{
            ll index;
            cin >> index;
            cout << init[index] + getBIT(BIT,index) << '\n';
        }
    }

//   暴力解法，时间复杂度为O(n^2)
//    vector<ll> diff_arr(N+2,0);
//    for (ll i = 0; i < M; ++i) {
//        ll tmp;
//        cin >> tmp;
//        if (tmp == 1){
//            ll start,end,k;
//            cin >> start >> end >> k;
//            diff_arr[start] += k;
//            diff_arr[end+1] -= k;
//        }
//        else{
//            ll index,diff_sum = 0;
//            cin >> index;
//            for (ll j = 1; j <= index; ++j) {
//                diff_sum += diff_arr[j];
//            }
//            cout << init[index] + diff_sum << '\n';
//        }
//    }

}