//
// Created by CZQ on 2024/4/30.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for(auto h : hours){
            if(h >= target)
                ans++;
        }
        return ans;
    }
};