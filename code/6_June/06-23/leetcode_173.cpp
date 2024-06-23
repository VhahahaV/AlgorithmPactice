//
// Created by VhahahaV on 2024/6/23.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> splited;
        string tmp;
        for(int i = 0 ; i < sentence.size() ; i++){
            if(sentence[i] == ' '){
                splited.emplace_back(tmp);
                tmp.clear();
            }
            else
                tmp += sentence[i];
        }
        if(!tmp.empty())
            splited.emplace_back(tmp);
        string ans;
        for(auto &word : splited){
            if(word[0] == '$' && word.size() > 1){
                double price = 0.0;
                bool flag = true;
                for(int i = 1 ; i<word.size();i++){
                    if(isdigit(word[i])){
                        price = price*10 + (word[i] - '0');
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    price = price * (double(100-discount)/100);
                    price = (price+0.005);
                    string priceStr = to_string(price);
                    auto it = find(priceStr.begin(),priceStr.end(),'.');
                    priceStr = string(priceStr.begin(),it+3);
                    word = '$'+ priceStr;
                }
            }
            ans += word + ' ';
        }
        ans.pop_back();
        return ans;
    }
};