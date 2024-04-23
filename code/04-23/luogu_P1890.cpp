//
// Created by VhahahaV on 2024/4/23.
//

////10min -> 90 points
////需要用线段树优化，来日再战
////线段树参考： https://zhuanlan.zhihu.com/p/106118909

////写完线段树模板的思考：这题不需要区间修改，，能用线段树的原因是gcd的运算满足交换了，从而可以用区间来存
////线段树第一版 差0.05s,继续优化
////
#include "bits/stdc++.h"


using namespace std;
int n,m;
//    默认a>b
int gcd(int a , int b ){
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
////线段树方案，将区间存在线段树中，直接查询,数据不是很大，直接用int搓
vector<int> tree;
//vector<int> mark;
//由于没有修改，所以可以不用懒标记mark
vector<int> nums;

void build(int left = 1,int right = n,int p = 1) {
    if (left == right){
        tree[p] = nums[left];
    }
    else {
        int mid = (left + right) / 2;
        build(left,mid,2*p);
        build(mid+1,right,2*p+1);
        tree[p] = gcd(tree[2*p+1],tree[2*p]);
    }
}

int query(const int &tLeft,const int &tRight ,int p = 1, int cLeft = 1, int cRight = n){
    if (cLeft > tRight || cRight < tLeft)
        return 0;
    else if(cLeft >= tLeft && cRight <= tRight){
        return tree[p];
    }
    else{
        int mid = (cLeft + cRight) / 2;
        int child1 = query(tLeft,tRight,2*p,cLeft,mid);
        int child2 = query(tLeft,tRight,2*p+1,mid+1,cRight);
        if (!child2 || !child1)
            return child1 ? child1 : child2;
        return gcd(child1,child2);
    }
}

int main(){
////优化输入
//取消同步流
//同步流 将时间从 1.05s -> 284ms easy
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n >> m;
    nums.resize(n+1),tree.resize(n<<2);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
//    顺序做gcd（辗转相除）的思想，每次操作都要遍历一次，复杂度高
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
    build();
    while (m--){
        int l,r;
        cin >> l >> r;
        cout << query(l,r) << '\n';
//        cout << findMaxGcd(l,r) << '\n';
    }


    return 0;
}