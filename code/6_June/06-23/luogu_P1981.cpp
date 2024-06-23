//
// Created by VhahahaV on 2024/6/23.
//
#include <iostream>
#include <vector>
#include <stack>
using ull = unsigned long long;
using namespace std;

int main(){
    string str;
    stack<ull> nums;
    stack<char> ops;
    cin >> str;


    auto useOp = [&](char op){
        auto a = nums.top();
        nums.pop();
        auto b = nums.top();
        nums.pop();
        if(op == '+')
            nums.push((a+b) % 10000);
        else
            nums.push(a*b % 10000);
    };
    auto getPreference = [&](char op)->int{
        if(op == '+')
            return 1;
        else
            return 2;
    };
    auto clearOps = [&](char op){
        while (!ops.empty() && getPreference(op) <= getPreference(ops.top())){
            auto op = ops.top();
            ops.pop();
            useOp(op);
        }
    };
    for(int i = 0 ; i < str.size() ; ){
        if(isdigit(str[i])){
            ull num = 0;
            while(isdigit(str[i])){
                num = num*10+(str[i]-'0');
                i++;
            }
            nums.push(num % 10000);
        }
        else{
            if(ops.empty())
                ops.push(str[i]);
            else{
                if(getPreference(str[i]) <= getPreference(ops.top())){
//                    清空
                    clearOps(str[i]);
                    ops.push(str[i]);
                }
                else
                    ops.push(str[i]);
            }
            i++;
        }
    }
    clearOps('+');
    cout << nums.top() % 10000;
    return 0;
}