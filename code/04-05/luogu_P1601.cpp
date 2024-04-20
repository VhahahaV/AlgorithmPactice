//
// Created by CZQ on 2024/4/5.
//
#include "bits/stdc++.h"

using namespace std;

void oneStep(int sum ,string &ans,int i){
    if (sum < 10 && ans.size() == i){
        ans = to_string(sum) + ans;
    }
    else if(sum < 10 && ans.size() > i){
        if (ans.empty())
            ans += to_string(sum);
        else
            ans[0] = char (sum+'0');
    }
    else if (ans.size() > i){
        if (ans.empty())
            ans += to_string(sum%10);
        else
            ans[0] = char (sum%10+'0');
        ans = to_string(sum/10) + ans;
    }
    else{
        ans = to_string(sum) + ans;
    }
}

int main(){
    string a,b;
    string ans;
    ans.reserve(500);
    cin >> a >> b;
    int i = 0;
    while (i < a.size() && i < b.size()){
        int indexA = a.size() - 1 - i;
        int indexB = b.size() - 1 - i;
        int sum =( a[indexA] - '0') + ( b[indexB] - '0');
        if (ans.size() > i)
            sum += (ans[0] - '0');

        oneStep(sum,ans,i);
        i++;
    }
    if (i != a.size()){
        while (i < a.size()){
            int indexA = a.size() - 1 - i;
            int sum =( a[indexA] - '0');
            if (ans.size() > i)
                sum += (ans[0] - '0');
            oneStep(sum,ans,i);
            i++;
        }
    }
    else if (i != b.size()){
        while (i < b.size()){
            int indexB = b.size() - 1 - i;
            int sum =( b[indexB] - '0');
            if (ans.size() > i)
                sum += (ans[0] - '0');
            oneStep(sum,ans,i);
            i++;
        }
    }
    cout << ans;
}