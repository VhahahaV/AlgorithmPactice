//
// Created by VhahahaV on 2024/6/25.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//30min
int main(){
    int p1,p2,p3;
    cin >> p1 >> p2 >>p3;
    string str;
    cin>>str;
    vector<int> validPos;
    auto getHandle = [&]()->vector<pair<char,char>>{
        vector<pair<char,char>> ans;
        for (int i = 0; i < str.size(); ++i) {
            if(str[i] == '-'){
                char s = str[i - 1] , t =str[i + 1];
                if((isdigit(s) && isdigit(t) ||
                    s >= 'a' && s <= 'z' && t >= 'a' && t <= 'z'
                    || s >= 'A' && s <= 'Z' && t >= 'A' && t <= 'Z')
                   && s < t){
                    ans.emplace_back(s, t);
                    validPos.emplace_back(i);
                }
            }
        }
        return ans;
    };
    auto strPair = getHandle();

    auto handlePair = [&](char s, char t)->string {
        string ans;
        for(char i = s+1; i < t ; i++){
            char cur = i;
            if(p1 == 1){
                if(cur >= 'A' && cur <= 'Z'){
                    cur = 'a' + (cur - 'A');
                }
            }
            else if(p1 == 2){
                if(cur >= 'a' && cur <= 'z'){
                    cur = 'A' + (cur - 'a');
                }
            }
            else if(p1 == 3){
                cur = '*';
            }

            ans += string(p2,cur);

        }

        if(p3 == 2)
            reverse(ans.begin(),ans.end());

        return ans;

    };

    auto curPair = strPair.begin();
    int changedLen = 0;
    for (auto i :validPos) {
        auto replacedStr = handlePair(curPair->first,curPair->second);
        str.replace(i+changedLen,1,replacedStr);
        curPair++;
        changedLen += (replacedStr.size()-1);
    }

    cout << str;
    return 0;
}
