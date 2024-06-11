//
// Created by VhahahaV on 2024/4/30.
//
#include "bits/stdc++.h"

using namespace std;
//7min
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1 , j = b.size()-1,carry = 0;
        while(i >= 0 || j >= 0 || carry != 0){
            int num1 = i>=0 ? a[i]-'0' : 0;
            int num2 = j>=0 ? b[j]-'0' : 0;
            int res = num1+num2+carry;
            ans+=to_string(res%10);
            carry = res/10;
            i--,j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution solution;
    cout << solution.addBinary("11","1");
    return 0;
}
