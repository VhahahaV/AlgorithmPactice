//
// Created by VhahahaV on 2024/4/29.
//
#include "bits/stdc++.h"
using namespace std;
auto intMin = std::numeric_limits<int>::min();
auto intMax = std::numeric_limits<int>::max();
//15min
class Solution {
public:

    int myAtoi(string s) {
        long res = 0;
        bool sign = true;
        int i = 0;
        while(s[i]==' ')
            i++;
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '-') ? false : true;
            i++;
        }
        while(i < s.size()){
            if(s[i] < '0' || s[i] > '9')
                break;
            if(sign){
                res = res*10 + (s[i]-'0');
                if(res > intMax)
                    return intMax;
            }

            else{
                res = res*10 - (s[i]-'0');
                if(res < intMin)
                    return intMin;
            }
            i++;
        }
        return res;
    }
};

int main(){
    Solution solution;
    cout << solution.myAtoi("   -42");
    return 0;
}