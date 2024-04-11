//
// Created by CZQ on 2024/4/8.
//

#include "bits/stdc++.h"

using namespace std;

typedef array<int,2> loc_t;
//一眼前缀和问题，需要考虑两种情况，顺时针走or逆时针走
//前缀和有点问题， 差分 + 树状数组
//差分 + 树状数组也问题，可以不用树状数组,直接前缀和搞定，可以不用管顺序
int n,P;

int main(){
    constexpr int MAX = 1001;
    cin >> n >> P;
    vector<array<int,2>> points(P+1,loc_t{0,0});

    vector< map<int ,vector<int>>> verticalBucket(MAX),horizontalBucket(MAX);

    for (int i = 0; i < P; ++i) {
        cin >> points[i][0] >> points[i][1];
    }


    auto buildVerticalBucket = [&verticalBucket](int x,int y,int idx){
        auto &bucket = verticalBucket.at(x);
        auto insertPos = bucket.find(y);
        if (insertPos == bucket.end())
            bucket.insert(make_pair(y, vector<int>{idx}));
        else
            insertPos->second.emplace_back(idx);
    };
    auto buildHorizontalBucket = [&horizontalBucket](int x,int y,int idx){
        auto &bucket = horizontalBucket.at(y);
        auto insertPos = bucket.find(x);
        if (insertPos == bucket.end())
            bucket.insert(make_pair(x, vector<int>{idx}));
        else
            insertPos->second.emplace_back(idx);
    };

    vector<loc_t> consultPoints(2*n+5);
    for(int i = 0; i < n;i++){
        int startX,startY,endX,endY;
        cin >> startX >> startY >> endX >> endY;
        buildHorizontalBucket(startX,startY,2*i);
        buildHorizontalBucket(endX,endY,2*i+1);
        buildVerticalBucket(startX,startY,2*i);
        buildVerticalBucket(endX,endY,2*i+1);
        consultPoints[2*i] = loc_t {startX,startY};
        consultPoints[2*i+1] = loc_t {endX,endY};
    }

    vector<int> consultDis(2*n+5);
    int prevDis = 0;
//    桶排序之后再遍历整张图
    for (int i = 1; i <= P; ++i) {
        loc_t cur = points[i % P];
        loc_t prev = points[(i - 1 + P) % P];
        if (cur[0] == prev[0]) {
//            垂直线，x相等
//            通过桶找到这条线上的所有查询点
            int minY = min<int>(cur[1], prev[1]);
            int maxY = max<int>(cur[1], prev[1]);
            auto &bucket = verticalBucket.at(cur[0]);
            for (auto iter = bucket.lower_bound(minY); iter != bucket.end() && iter->first <= maxY; iter++) {
                for (auto idx: iter->second) {
                    consultDis.at(idx) = prevDis + abs(consultPoints.at(idx).at(1) - prev[1]);
                }
            }
            prevDis += (maxY - minY);
        }
        else {
//      水平线，X相等
            int minX = min<int>(cur[0], prev[0]);
            int maxX = max<int>(cur[0], prev[0]);
            auto &bucket = horizontalBucket.at(cur[1]);
            for (auto iter = bucket.lower_bound(minX); iter != bucket.end() && iter->first <= maxX; iter++) {
                for (auto idx: iter->second) {
                    consultDis.at(idx) = prevDis + abs(consultPoints.at(idx).at(0) - prev[0]);
                }
            }
            prevDis += (maxX - minX);
        }

    }

    for(int i=0; i<n; i++){
        int sIdx = 2*i, tIdx = 2*i+1;
        auto d = abs(consultDis.at(sIdx)-consultDis.at(tIdx));
        d = min(d, prevDis-d);
        cout << d << '\n';
    }
    return 0;
}

//