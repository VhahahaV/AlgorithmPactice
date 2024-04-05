//
// Created by CZQ on 2024/4/5.
//
#include "bits/stdc++.h"

using namespace std;

void getStep(string &s,int end){
    int num;
    if (!s.empty())
        num = s[end] - '0';
    else{
        num += '1';
        return;
    }
    if (num + 1 < 10)
        s[s.size()-1] += 1;
    else{
        s[s.size()-1] = 0;
        getStep(s,end-1);
    }

}

int main(){
    string a,b;
    string ans = "";
    cin >> a >> b;
    int i = 0;
    while (i < a.size() && i < b.size()){
        int sum =( a[i] - '0') + ( b[i] - '0');
        if (sum < 10){
            ans = ans + to_string(sum);
        }
        else{
            getStep(ans,ans.size()-1);
            ans = ans + to_string(sum-10);
        }
        i++;
    }
    cout << ans;
}