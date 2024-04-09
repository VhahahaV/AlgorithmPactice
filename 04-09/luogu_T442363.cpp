//
// Created by CZQ on 2024/4/8.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef array<ll,2> loc_t;
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
ll crossProduct(const loc_t &a, const loc_t &b, const loc_t &c) {
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
}

bool onLine(const loc_t &start, const loc_t &end, const loc_t &p) {
    // 计算向量(start, p)和(start, end)的叉积
    ll cross = crossProduct(start, end, p);

    // 如果叉积为0且点p在线段的x轴和y轴范围内，则点p在线段上
    if (cross == 0 && p[0] >= min(start[0], end[0]) && p[0] <= max(start[0], end[0]) &&
        p[1] >= min(start[1], end[1]) && p[1] <= max(start[1], end[1])) {
        return true;
    }

    return false;
}

int main(){
    cin >> n >> P;
    distances.resize(P+1,0);
    vector<array<ll,2>> points(P+1,loc_t{0,0});
    vector<ll> BitX(P+1);
    vector<ll> BitY(P+1);

    map<loc_t ,int> pointMap;

    ll sumDis = 0;
    for (int i = 0; i < P; ++i) {
        cin >> points[i][0] >> points[i][1];

        ll deltaX;
        ll deltaY;
        if (i == 0)
            deltaX=deltaY=0;
        else{
            deltaX = points[i][0] - points[i-1][0];
            deltaY = points[i][1] - points[i-1][1];
        }

        updateBit(BitX,i+1,abs(deltaX));
        updateBit(BitY,i+1, abs(deltaY));

        sumDis += (abs(deltaY)+ abs(deltaX));
        pointMap.insert(pair<loc_t,int>(loc_t{points[i][0],points[i][1]},i));
    }
    sumDis += (abs(points[P-1][0]-points[0][0]) + abs(points[P-1][1]-points[0][1]));

    while (n--){
        int startX,startY,endX,endY;
        cin >> startX >> startY >> endX >> endY;
//        先拿出 posX,posY 相应的 index
        ll minStartDis = LONG_LONG_MAX , minEndDis = LONG_LONG_MAX;
        loc_t start,end;

        bool dirStart,dirEnd;

//       找到距离自己最近的点
        for (int i = 0; i < P; ++i) {
            ll x = points[i][0];
            ll y = points[i][1];


            if (x != startX && y!=startY && x != endX && y!=endY)
                continue;

            //            the nearest start point
            if (x == startX && minStartDis > abs(startY-y)){
                    minStartDis = abs(startY-y);
                    start.at(0) = x,start.at(1) = y;
                }
            else if(y == startY && minStartDis > abs((startX-x))){
                minStartDis = abs(startX-x);
                start.at(0) = x,start.at(1) = y;
            }

//            the nearest end point
            if (x == endX && minEndDis > abs(endY-y)){
                minEndDis = abs(endY-y);
                end.at(0) = x,end.at(1) = y;
            }
            else if(y ==endY && minEndDis > abs((endX-x))){
                minEndDis = abs(endX-x);
                end.at(0) = x,end.at(1) = y;
            }

        }

        int startIndex = pointMap[start],endIndex = pointMap[end];
//        然后使用树状数组的前缀和

        ll origin2start = getBIT(BitX,startIndex+1) + getBIT(BitY,startIndex+1);
//        如果在start点的后面,则还需要加一段minStartDis距离
        if (onLine(points[(startIndex+1)%P],points[startIndex],loc_t{startX,startY}))
            origin2start += minStartDis;
        else
            origin2start -= minStartDis;

        ll origin2end = getBIT(BitX,endIndex+1) + getBIT(BitY,endIndex+1);
        if (onLine(points[(endIndex+1)%P],points[endIndex],loc_t{endX,endY}))
            origin2end += minEndDis;
        else
            origin2end -= minEndDis;

        ll result = abs(origin2end-origin2start);
        result = min<ll>(result,sumDis-result);
        cout << result << '\n';


    }
    return 0;
}

//