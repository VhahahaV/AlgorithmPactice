//
// Created by VhahahaV on 2024/5/8.
//
///8min

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 , n = prices.size();
        for(int i = 0 ; i + 1 < n ; i++)
            profit += max(0, prices[i+1]-prices[i]);
        return profit;
    }
};