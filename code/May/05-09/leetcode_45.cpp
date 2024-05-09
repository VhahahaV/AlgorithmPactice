//
// Created by VhahahaV on 2024/5/9.
//
//16min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
// dp[i]为到达i需要的最小跳跃次数
// dp[i] = min( dp[j]+1 ) (j<i && j+num[j]>=i)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int num = cur + nums[cur];
            for(int i = cur+1;i<n && i<=num;i++){
                if(dp[i] == -1){
                    // if(i == n-1)
                    //     return dp[cur]+1;
                    dp[i] = dp[cur]+1;
                    q.push(i);
                }
            }
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> nums{2,3,1,1,4};
    Solution solution;
    solution.jump(nums);
    return 0;
}