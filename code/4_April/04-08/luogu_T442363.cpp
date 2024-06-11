//
// Created by CZQ on 2024/4/8.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
//一眼前缀和问题，需要考虑两种情况，顺时针走or逆时针走
//前缀和有点问题， 差分 + 树状数组
vector<ll> distances;
ll n,P;


ll lowBit(ll a){
    return a & (-a);
}

void updateBit(vector<ll> &Bit,ll pos,ll val){
//    使用lowBit函数的时候应该注意输入的参数为 i ，而不是pos, i才是当前节点的位置
    for (ll i = pos; i <= P; i += lowBit(i)) {
        Bit.at(i) += val;
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
    cin >> n >> P;
    distances.resize(P+1,0);
    vector<array<ll,2>> points(P+1,array<ll,2>{0,0});
    vector<ll> BitX(P+1);
    vector<ll> BitY(P+1);
    for (int i = 1; i <= P; ++i) {
        cin >> points[i][0] >> points[i][1];

        ll deltaX = points[i][0] - points[i-1][0];
        ll deltaY = points[i][1] - points[i-1][1];

        updateBit(BitX,i,deltaX);
        updateBit(BitY,i,deltaY);

    }

    while (n--){
        int startX,startY,endX,endY;
        cin >> startX >> startY >> endX >> endY;
        int posX,posY;
//        先拿出 posX,posY 相应的 index
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
        }

//        然后使用树状数组的前缀和


    }
    return 0;
}

//