//
// Created by CZQ on 2024/4/10.
//

#include "bits/stdc++.h"
using namespace std;

//鉴定为最长升序列为题，求出每个位置开始或者每个位置结束的最长升序列，然后相加

//朴素方法：复杂度O(n^2)

vector<int> max_up;
vector<int> max_down;
int main(){
    int n;
    cin >> n;
    vector<int> heights(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> heights[i];
    }
    max_up.resize(n+1);
    max_down.resize(n+1);

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (heights[i] > heights[j] && max_up[i] <= max_up[j])
                max_up[i] = max_up[j]+1;

        }
    }

    for (int i = n-1; i >= 1; --i) {
        for (int j = n; j > i; --j) {
            if (heights[i] > heights[j] && max_down[i] <= max_down[j])
                max_down[i] = max_down[j]+1;
        }
    }

    int maxPeoples = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxPeoples < max_down[i]+max_up[i]+1)
            maxPeoples = max_down[i]+max_up[i]+1;
    }
    cout << n - maxPeoples;

    return 0;
}
