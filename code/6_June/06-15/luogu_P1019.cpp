//
// Created by CZQ on 2024/6/15.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
using WordPair = pair<int,int>;

int maxLen = 0;
void getLen(const vector<string> &words,const vector<vector<WordPair>> &nextWords,vector<int> &useTimes,int curIndex,int curLen){
    if(useTimes[curIndex] > 2)
        return ;
    maxLen = max(maxLen,curLen);
    for(auto &[index,len] : nextWords[curIndex]){
        useTimes[index]++;
        getLen(words,nextWords,useTimes,index,curLen + words[index].size() - len);
        useTimes[index]--;
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0 ; i < n ; i++)
        cin >> words[i];

    auto getNextWords = [&](int index)->vector<WordPair>{
        vector<WordPair> res;
        auto curStr = words[index];
        for(int k = 0 ; k < n ; k++){
            const auto &w = words[k];
            auto concatStr = w + curStr;
//            最长公共前后缀长度
            std::vector<int> shareLen(concatStr.size());
            int j = 0;
            for(int i = 1 ; i < concatStr.size() ;){
                if(concatStr[i] == concatStr[j]){
                    shareLen[i] = j+1;
                    j++;
                    i++;
                }
                else{
                    if(!j)
                        shareLen[i++] = 0;
                    else
                        j =  shareLen[j-1];
                }
            }
            int len = shareLen.back();
            if(len && len != w.size() && len != curStr.size())
                res.emplace_back(k,len);
        }
        return res;
    };


    vector<vector<WordPair>> nextWords; nextWords.reserve(n);
    for(int i = 0 ; i < n ; i++){
        nextWords.emplace_back(getNextWords(i));
    }
    vector<int> useTimes(n);
    for(int i = 0 ; i < n ; i++){
        useTimes[i]++;
        getLen(words,nextWords,useTimes,i,words[i].size());
        useTimes[i]--;
    }
    cout << maxLen;
    return 0;
}