//
// Created by VhahahaV on 2024/6/25.
//
// 22min
#include <bits/stdc++.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> slidesNums;
        for(int i = 0 ; i < k ; i++){
            while(!slidesNums.empty() && slidesNums.back().first <= nums[i])
                slidesNums.pop_back();
            slidesNums.push_back(make_pair(nums[i],i));
        }
        vector<int> ans;
        ans.emplace_back(slidesNums.front().first);
        for(int i = k ; i < nums.size() ; i++){
            if(slidesNums.front().second == i-k)
                slidesNums.pop_front();
            while(!slidesNums.empty() && slidesNums.back().first <= nums[i])
                slidesNums.pop_back();
            slidesNums.push_back(make_pair(nums[i],i));
            ans.emplace_back(slidesNums.front().first);
        }

        return ans;
    }
};