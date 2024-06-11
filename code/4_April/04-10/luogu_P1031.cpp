//
// Created by CZQ on 2024/4/10.
//

#include "bits/stdc++.h"

using namespace std;

int res = 0;
inline void moveCard(vector<int> &nums,int start,int end,int val){
    nums[start]-=val;
    nums[end]+=val;
    res++;
}
//贪婪法，寻找局部最优
int main(){
    int n;
    cin >> n;
    vector<int> nums(n+1);
    int average = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        average+=nums[i];
    }
    average/=n;

    for (int i = 1; i < n; ++i) {
        {
            if (nums[i]<average)
                moveCard(nums,i+1,i,average-nums[i]);
            else if(nums[i]>average)
                moveCard(nums,i,i+1,nums[i]-average);
            else
                continue;
        }

    }
    cout << res;
    return 0;
}