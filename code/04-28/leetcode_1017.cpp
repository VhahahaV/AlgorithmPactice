//
// Created by CZQ on 2024/4/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
// 对于正常二进制，奇数位如果为1，奇数位前一个加1
    string baseNeg2(int n) {
        if(!n)
            return "0";
        string ans = "";
        int num = n;
        int a = -1;
        while(n){
            if( !((++a)%2 ) || !(n&1)){
                n = n>>1;
                continue;
            }
            add_Neg(num,a+1, true);
            n = n>>1;
        }
        while(num){
            ans += to_string((num&1));
            num =  num >> 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void add_Neg(int &num,int carry,bool add){
        if(!(num & (1<<carry)) && add)
            num += (1<<carry);
        else if((num & (1<<carry)) && !add){
            num -= (1<<carry);
        }
        else{
            if(add){
                num -= (1<<carry);
                add_Neg(num,carry+1, false);
            }
            else{
                num += (1<<carry);
                add_Neg(num,carry+1, true);
            }
        }
    }
};