//
// Created by CZQ on 2024/4/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> nums(10,"0");
        // nums[i] = num1 * i
        for(int i = 1 ; i<10 ; i++){
            nums[i] = addBigInteger(num1,nums[i-1]);
        }
        string ans;
        int n = num2.size() , i = 0;
        while(i<n){
            if (ans != "0")
                ans += "0";
            ans = addBigInteger(ans,nums[num2[i]-'0']);
            i++;
        }
        return ans;
    }

    string addBigInteger(string &num1 , string &num2){
        int i = num1.size() - 1, j = num2.size() -1 , carry = 0;
        string ans;
        while(i >= 0 || j >= 0 || carry != 0 ){
            int  x = i >= 0 ? num1.at(i) - '0' : 0;
            int  y = j >= 0 ? num2.at(j) - '0' : 0;
            int res = x + y + carry;
            ans += to_string(res%10);
            carry = res / 10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};