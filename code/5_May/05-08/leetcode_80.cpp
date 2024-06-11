//
// Created by VhahahaV on 2024/5/8.
//
//7min
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int> duplicate;
        duplicate.push(nums.front());
        auto it = nums.begin()+1;
        while(it != nums.end()){
            if(*it == duplicate.top()){
                if(duplicate.size() == 2)
                    nums.erase(it);
                else
                    duplicate.push(*(it++));
            }
            else{
                while(!duplicate.empty()) duplicate.pop();
                duplicate.push(*(it++));
            }
        }
        return nums.size();
    }
};