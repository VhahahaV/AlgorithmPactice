//
// Created by VhahahaV on 2024/6/28.
//
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    string str;
    cin >> str;

    auto getPreferece = [&](char op)->int{
        if(op == '+' || op == '-')
            return 0;
        else if(op == '*' || op == '/')
            return 1;
        else if(op == '^')
            return 2;
        return 3;
    };
    vector<string> splitedVec;
//    auto split = [&](){
//        for(int i = 0 ; i < str.size() ; ){
//
//            if(isdigit(str[i])){
//                string num;
//                while (isdigit(str[i]))
//                    num+=str[i++];
//                splitedVec.emplace_back(num);
//
//            }
//            else{
//                splitedVec.emplace_back(to_string(str[i++]));
//            }
//        }
//    };

    stack<char> nums;
    stack<char> ops;

    for(char i : str){
        if(isdigit(i)){
            nums.push(i);
        }
        else{
            if(i == '(' || i=='^'){
                ops.push(i);
            }
            else if(i == ')'){
                while (ops.top() != '('){
                    nums.push(ops.top());
                    ops.pop();
                }
                ops.pop();
            } else{
                while (!ops.empty() && ops.top() != '(' && getPreferece(i) <= getPreferece(ops.top())){
                    nums.push(ops.top());
                    ops.pop();
                }
                ops.push(i);
            }
        }
    }
    while(!ops.empty()){
        nums.push(ops.top());
        ops.pop();
    }

    vector<char> numsVec;
    vector<int> numsVec2;
    while(!nums.empty()){
        numsVec.emplace_back(nums.top());
        nums.pop();
    }
    std::reverse(numsVec.begin(), numsVec.end());
    auto display = [&](){
        for(auto c: numsVec2)
            cout << c << ' ';
        for(auto c:numsVec)
            cout << c << ' ';

        cout << endl;
    };
    auto operatorOnce = [&](char op){
        auto b = numsVec2.back() ;
        numsVec2.pop_back();
        auto a = numsVec2.back();
        numsVec2.pop_back();
        int res;
        switch (op) {
            case '-':
                res = (a-b);
                break;
            case '+':
                res = (a+b);
                break;
            case '/':
                res = (a/b);
                break;
            case '*':
                res = (a*b);
                break;
            case '^':
                res = (pow(a,b));
                break;

        }
        numsVec2.emplace_back(res);
    };

    while (isdigit(*numsVec.begin())){
        numsVec2.emplace_back(numsVec.front()-'0');
        numsVec.erase(numsVec.begin());
    }
    display();

    while (!numsVec.empty()){
        if(isdigit(*numsVec.begin())){
            numsVec2.emplace_back(numsVec.front()-'0');
            numsVec.erase(numsVec.begin());
        }
        else{
            operatorOnce(numsVec.front());
            numsVec.erase(numsVec.begin());
            display();
        }
    }
//    display();

    return 0;
}