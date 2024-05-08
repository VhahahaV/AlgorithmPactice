//
// Created by VhahahaV on 2024/5/8.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
// 前缀和
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur = -1,plantNum = plants.size();
        int water = capacity;
        int step = 0;
        while(true){
            int next = cur + 1;
            if(next == plantNum){
                break;
            }
            if(plants[next] <= water){
                water -= plants[next],step++,cur++;
                continue;
            }
            else{
                water = capacity, step = step + 2*(cur+1);
                continue;
            }
        }
        return step;
    }
};