//
// Created by VhahahaV on 2024/4/23.
//
#include "bits/stdc++.h"
////线段树（Segment Tree）几乎是算法竞赛最常用的数据结构了，它主要用于维护区间信息（要求满足结合律）。与树状数组相比，它可以实现
////O(log n)的区间修改，还可以同时支持多种操作（加、乘），更具通用性。

using namespace std;
//线段树模板题
//90min
using ll = long long;
ll n,m;
vector<ll> tree; //线段树是一颗平衡二叉树，直接用数组存
vector<ll> mark; //懒标记数组,每次更新的时候，只过更新到第一次访问到的，目标更新区间的子区间的值，就不往下传了。
vector<ll> nums; //储存数据用的数组
//ATTENTION : 线段树的右节点区间长度 <= 左节点区间长度
void build(ll left = 1,ll right = n,ll p = 1){
    if (left == right){
//        叶子节点，直接建树
        tree[p] = nums[left];
    }
    else{
        ll mid = (left+right)/2;
        build(left,mid,2*p);
        build(mid+1,right,2*p+1);
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

//懒标记向上传一层
void push_down(ll p, ll len){
    mark[2*p] += mark[p];
    mark[2*p+1] += mark[p];
//    更新tree数组需要乘上区间长度
    tree[2*p] += mark[p] * (len - len/2);
    tree[2*p+1] += mark[p] * (len/2);
//  清除上一层的懒标记
    mark[p] = 0;
}
//ll tLeft , ll tRight 为目标区间（要更新的区间） ll p = 1, ll cLeft = 1, ll cRight = n 为当前处于的区间，从该区间不断二分去拟合更新区间
void update(ll tLeft , ll tRight ,ll val ,ll p = 1, ll cLeft = 1, ll cRight = n){
    if (cRight < tLeft || cLeft > tRight)
        return ;
    else if(cLeft >= tLeft && cRight <= tRight){
        mark[p] += val;
        tree[p] += val*(cRight-cLeft+1);
    }
    else{
//        如果当前区间与目标区间有交叉，则向下传递
        ll mid = (cLeft + cRight) / 2;
        push_down(p,cRight-cLeft+1);
        update(tLeft,tRight,val,2*p,cLeft,mid);
        update(tLeft,tRight,val,2*p+1,mid+1,cRight);
        tree[p]  = tree[2*p] + tree[2*p+1];
    }
}

ll query(ll tLeft , ll tRight ,ll p = 1, ll cLeft = 1, ll cRight = n){
    if (cRight < tLeft || cLeft > tRight)
        return 0;
    else if(cLeft >= tLeft && cRight <= tRight){
        return tree[p];
    }
    else{
        ll mid = (cLeft + cRight) / 2;
        push_down(p,cRight-cLeft+1);
        return (query(tLeft,tRight,2*p,cLeft,mid) + query(tLeft,tRight,2*p+1,mid+1,cRight));
    }
}


int main(){
    cin >> n >> m;
//    这里tree 和 mark 数组由于存的是一个树的结构，不能用n大小的空间，也不能用 n*n的空间，不然会RE，测试后4*n的空间足够。
    tree.resize(n*4),mark.resize(n*4),nums.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    build();
    while (m--){
        int model;
        cin >> model;
        if (model == 1){
            ll l,r,k;
            cin >> l >> r >> k;
            update(l,r,k);
        }
        else{
            ll l,r;
            cin >> l >> r;
            cout << query(l,r) << '\n';
        }
    }
    return 0;
}