//
// Created by VhahahaV on 2024/4/23.
//
#include "bits/stdc++.h"

using namespace std;

//32min
//贪婪
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int preSum = 0;

        for(int i = 0;i < minutes ; i++)
            preSum+=customers[i] * grumpy[i];
        int proSum = 0,proSum2 = 0;
        for(int i =  minutes ; i < customers.size() ; i++){
            if(proSum + customers[i] * grumpy[i] > proSum2 + customers[i-minutes] * grumpy[i - minutes]){
                preSum = preSum - (proSum2 + customers[i-minutes] * grumpy[i - minutes]) + (proSum + customers[i] * grumpy[i]);
                proSum2 = proSum = 0;
            }
            else{
                proSum += customers[i] * grumpy[i];
                proSum2 += customers[i-minutes] * grumpy[i - minutes];
            }
        }
        for(int i = 0 ; i < customers.size() ; i++){
            sum += customers[i] * (1-grumpy[i]);
        }
        sum+=preSum;

        return sum;
    }
};