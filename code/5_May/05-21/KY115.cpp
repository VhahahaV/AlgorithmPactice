//
// Created by CZQ on 2024/5/21.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<string> subs;
    int len = str.size();
    for(int j = 0; j < len;j++){
        subs.emplace_back(str.substr(j,len-j));
    }
    sort(subs.begin(), subs.end());
    for(auto &sub : subs)
        cout << sub << '\n';
}
// 64 位输出请用 printf("%lld")