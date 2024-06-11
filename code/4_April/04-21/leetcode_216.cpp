//
// Created by VhahahaV on 2024/4/21.
//
//28min
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        nums.reserve(k);
        dfs(k,n,0,1);
        return res;
    }
    vector<vector<int>> res;
    vector<int> nums;
    void dfs(int k , int n , int sum, int start){
        if(k == 0 ){
            if(sum == n){
                res.emplace_back(nums);
            }
            return;
        }
        for(int i  = start; i < 10 ; i ++){
            nums.emplace_back(i);
            sum += i;
            dfs(k-1,n,sum,i+1);
            nums.pop_back();
            sum -= i;
        }
    }
};