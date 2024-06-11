//
// Created by VhahahaV on 2024/5/10.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int  ans = 0;
        for(int i = 0 ; i < n ; i++){
            batteryPercentages[i] -= ans;
            if(batteryPercentages[i] > 0){
                ans++;
            }
        }
        return ans;
    }
};