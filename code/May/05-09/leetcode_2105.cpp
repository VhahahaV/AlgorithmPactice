//
// Created by VhahahaV on 2024/5/9.
//
//11min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0 , j = plants.size()-1 , n = plants.size();
        int waterA = capacityA , waterB = capacityB;
        int res = 0;
        while(i < j){
            if(plants[i] <= waterA && plants[j] <= waterB)
                waterA -= plants[i] , waterB -= plants[j];
            else if(plants[i] <= waterA)
                waterA -= plants[i] , waterB = capacityB - plants[j] , res++;
            else if(plants[j] <= waterB)
                waterB -= plants[j] , waterA = capacityA - plants[i] , res++;
            else
                waterA = capacityA - plants[i] , waterB = capacityB - plants[j] , res+=2;
            i++ , j--;
        }
        if(i == j)
            if (max(waterA,waterB) < plants[i])
                res++;
        return res;
    }
};