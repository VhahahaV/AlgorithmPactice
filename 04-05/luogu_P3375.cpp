//
// Created by CZQ on 2024/4/5.
//

#include "bits/stdc++.h"

using namespace std;

//前缀是指不包含最后一个字符的所有以第一个字符（索引为0）开头的连续子串
//后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串
vector<int> getNext(const string &PatternStr){
    vector<int> next(PatternStr.size(),0);
    int len = 0;
    int i = 1;
//   len为上个字串的最长长度，i 为 行进到PatternStr的位置

    while(i < PatternStr.size()){
//        循环开始时，len为上一个字串的最长公共字串长度
        if (PatternStr[i] == PatternStr[len])
            next[i++] = ++len;
        else{
//            如果不匹配，则去找上一个字符串的最长公共前缀的前缀为新的字串，并获取新字串的next
            if(len > 0)
//                最长公共字串的 最长公共字串， 《递归》
                len = next[len - 1];
            else
                next[i++] = 0;
        }
    }

    return next;
}
//next即代表最大公共字串的长度，也代表 最大公共字串的前缀 的下一个数
vector<int> kmpSearch(const string &PatternStr , const string &MatchStr , const vector<int> &next){
    vector<int> firstMatch;
    int j = 0;
    int i = 0;
    while(i < MatchStr.size()) {

        if (MatchStr[i] == PatternStr[j]){
            j++;
            i++;
        }
        else{
            if (j > 0)
                j = next[j-1];
            else
                i++;
        }

        if (j == PatternStr.size()){
            firstMatch.emplace_back(i - j + 1);
            j = next[j-1];
        }

    }
    return firstMatch;
}

int main(){
    string s2,s1;
    cin >> s1 >> s2;
    vector<int> next = getNext(s2);
    vector<int> firstMatch = kmpSearch(s2,s1,next);
    for(auto i : firstMatch)
        cout << i << endl;
    for(auto i : next){
        cout << i << " ";
    }
    return 0;
}