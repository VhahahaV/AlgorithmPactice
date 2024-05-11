//
// Created by VhahahaV on 2024/5/11.
//

#include "bits/stdc++.h"
using namespace std;

//再写一次KMP
vector<int> getNext(const string &pattern){
//    寻找最长公共前后缀
    int match = 0,i = 1;
    int n = pattern.size();
    vector<int> next(n);
    while(i < n){
        if (pattern[i] == pattern[match])
            next[i++] = ++match;
        else{
            if(match > 0){
                match = next[match-1];
            }
            else
                next[i++] = 0;
        }
    }
    return next;
}

vector<int> KmpSearch(const vector<int> &next,const string &str, const string &pattern){
    int i = 0, j = 0; //str -> i  pattern -> j
    int n = str.size();
    vector<int> firstMatch;
    while(i < n){
        if(str[i] == pattern[j]){
            i++,j++;
            if(j == pattern.size()){
                firstMatch.emplace_back(i-pattern.size());
                j = next[j-1];
            }
        }
        else{
//            这个地方有bug,需要考虑j == 0 的情况，否则会陷入死循环
            if(j > 0)
                j = next[j-1];
            else
                i++;
        }
    }
    return firstMatch;
}

int main(){
    string  a ,b;
    cin >> a >> b;
    vector<int> next = getNext(b);
    vector<int> firstMatch =  KmpSearch(next,a,b);
    cout << firstMatch.size();
    return 0;
}