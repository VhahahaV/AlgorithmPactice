//
// Created by CZQ on 2024/4/7.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> parseInt(int n){
    int carry = 0;
    vector<int> res;
    do{
        if (n % 2 == 1)
            res.emplace_back(carry);
        carry++;
        n = n>>1;
    } while (n);
    return res;
}

void printFormula(int n){
    vector<int> res = parseInt(n);
    for (auto i = res.rbegin(); i < res.rend(); i ++) {
        if (*i > 1){
            cout << "2(";
            printFormula(*i);
            cout << ")";
        }
        else if(*i == 1){
            cout << 2;
        }
        else{
            cout << "2(0)";
        }

        if(i != res.rend()-1)
            cout << "+";
    }
}

int main(){
    int a;
    cin >> a;
    printFormula(a);
}