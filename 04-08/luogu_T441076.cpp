//
// Created by CZQ on 2024/4/8.
//
#include "bits/stdc++.h"

using namespace std;

//idea1： Q2用于充当一个队列，遇到T加一，遇到F减一。
//idea2  层次遍历想法，将下一轮的T/F直接加在s的尾部
int main(){
    int n;
    string s;
    cin >> n >> s;
    int Queue = 0;
    int numT = 0 , numF = 0;
    for(auto i : s){
        if (i == 'T')
            numT++;
        else
            numF--;
    }

    for(int i = 0; i < s.size() ; i++){
        if (Queue > numT || Queue < numF )
            break;
        if (s[i] == 'T' && Queue >= 0)
            Queue++;
        else if(s[i] == 'F' && Queue <= 0)
            Queue--;
        else if (s[i] == 'F' && Queue > 0){
            Queue--;
            s+="T";
        }
        else if (s[i] == 'T' && Queue < 0){
            Queue++;
            s+="F";
        }
    }
    if (Queue > 0)
        cout << 'T';
    else
        cout << 'F';

}