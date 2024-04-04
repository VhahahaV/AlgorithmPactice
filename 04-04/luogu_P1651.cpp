//
// Created by CZQ on 2024/4/4.
//
//DP 数塔问题
//二维动态规划问题
//dp[t] [j] 代表已经用了 t 个积木后 高积木和矮积木高度差为 j  的 高积木的高度


#include <bits/stdc++.h>

using namespace std;
inline int getIndex(int row , int col , int heiSum){
    return row*(heiSum+1)+col;
}
int main(){
    int num;
    int heiSum = 0;
    vector<int> height;
    cin >> num;
    height.emplace_back(0);
    for (int i = 0; i < num; ++i) {
        int tmp;
        cin >> tmp;
        heiSum += tmp;
        height.emplace_back(tmp);
    }
    vector<int> dp((num+1) * (heiSum+1) , -50000);
//    for (int i = 0; i < heiSum; ++i) {
//        dp[i] = 0;
//    }
    dp[0] = 0;

    for (int i = (heiSum + 1); i < dp.size(); ++i) {
        int t = i / (heiSum + 1);
        int j = i % (heiSum + 1);

        dp[getIndex(t , j ,heiSum)] = max(dp[getIndex(t-1,j,heiSum)] , dp[getIndex( t-1, j+height[t] , heiSum )] );

        if( j > height[t])
            dp[getIndex(t , j ,heiSum)] = max( dp[getIndex(t , j ,heiSum)], dp[getIndex(t-1, j-height[t] ,heiSum)] + height[t]);
        else
            dp[getIndex(t,j,heiSum)] = max( dp[getIndex(t,j,heiSum)] , dp[getIndex(t-1,height[t]-j,heiSum)] + j);

    }
    if (dp[num*(heiSum+1)])
        cout << dp[num*(heiSum+1)];
    else
        cout << -1;
}
