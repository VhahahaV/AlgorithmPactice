//
// Created by CZQ on 2024/4/22.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        return dpSolution(nums,target);
    }
    // 直接DFS遍历所有可能性不可取，时间超限制了，需要用DP
    // int res = 0;
    // int sum = 0;
    // void dfs(vector<int>& nums, int target){
    //     if(sum > target)
    //         return;
    //     else if(sum == target){
    //         res++;
    //         return;
    //     }
    //     else{
    //         for(auto n : nums){
    //             sum+=n;
    //             dfs(nums,target);
    //             sum-=n;
    //         }
    //         return;
    //     }
    // }


    // DP思想，dp[i] 代表目标值为 i 时共有多少种情况， dp[i] = sum(dp[i-num])  {num 属于nums}
    int dpSolution(vector<int>& nums, int target){
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i <= target;i++){
            for(auto num : nums){
                if(i-num < 0 || dp[i-num] >= INT32_MAX-dp[i])
                    continue;
                else{
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];

    }
};
int main(){
    vector<int> nums{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target = 999;
    Solution solution;
    cout << solution.combinationSum4(nums,target);
    return 0;
}