//
// Created by CZQ on 2024/5/21.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string line;
    while(cin >> line){
        vector<int> cnt(26);
        for(auto ch : line){
            if(ch >= 'A' && ch <= 'Z')
                cnt[ch-'A']++;
        }

        for(int i = 0 ;i < 26 ; i++){
            cout << char('A'+i) << ":" <<cnt[i] << '\n';
        }
    }
}
// 64 位输出请用 printf("%lld")