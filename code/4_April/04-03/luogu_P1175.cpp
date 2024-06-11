//
// Created by CZQ on 2024/4/3.
//
#include "bits/stdc++.h"

using namespace std;

void printFormula(stack<int> nums,vector<string> formula,int i){
    vector<int> newNums;
    while (!nums.empty()){
        newNums.emplace_back(nums.top());
        nums.pop();
    }
    for(auto it = newNums.rbegin(); it != newNums.rend(); ++it)
        cout << *it << " ";
    for(;i < formula.size(); i++)
        cout << formula[i] << " ";
    cout << endl;
}

int main(){
    string str;
    cin >> str;
    stack<int> nums;
    stack<char> operations;
    vector<string> formula;
    int num = 0;
//    compute houzhui
    for(int i = 0 ; i < str.size() ; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            while (i < str.size() && str[i] >= '0' && str[i] <= '9'){
                num = num*10 + (str[i]-'0');
                i++;
            }
            formula.emplace_back(to_string(num));
            num = 0;
            i--;
            continue;
        }

        if(str[i] == '('){
            operations.push(str[i]);
            continue;
        }
        else if (str[i] == ')'){
            while(operations.top() != '('){
                char tmp = operations.top();
                operations.pop();
                formula.emplace_back(string (1,tmp));
            }
            operations.pop();
            continue;
        }

        if (str[i] == '+' || str[i] == '-'){
            if (operations.empty()  || operations.top() == '(')
                operations.push(str[i]);
            else{
                while (!operations.empty()  && operations.top() != '('){
                    char tmp = operations.top();
                    operations.pop();
                    formula.emplace_back(string (1,tmp));
                }
                operations.push(str[i]);
            }
        }

        else if(str[i] == '*' || str[i] == '/'){
            if (operations.empty() || operations.top() == '(' || operations.top() == '+' ||  operations.top() == '-')
                operations.push(str[i]);
            else{
                while (!operations.empty() && operations.top() != '(' && operations.top() != '+' &&  operations.top() != '-'){
                    char tmp = operations.top();
                    operations.pop();
                    formula.emplace_back(string (1,tmp));
                }
                operations.push(str[i]);
            }
        }
        else if (str[i] == '^')
            operations.push(str[i]);
    }

    if (!operations.empty())
        while(!operations.empty()){
            char tmp = operations.top();
            operations.pop();
            formula.emplace_back(string (1,tmp));
        }

    for (auto i : formula)
        cout << i << " ";
    cout << endl;

//    calculate the formula
    for (int i = 0; i < formula.size(); ++i) {
        if (formula[i][0] >= '0' && formula[i][0] <= '9'){
            int n = stoi(formula[i]);
            nums.push(n);
            continue;
        }
        else{
            int B = nums.top();
            nums.pop();
            int A = nums.top();
            nums.pop();
            if (formula[i] == "+"){
                nums.push(A+B);
            }
            else if (formula[i] == "-"){
                nums.push(A-B);
            }
            else if (formula[i] == "*"){
                nums.push(A*B);
            }
            else if (formula[i] == "/"){
                nums.push(A/B);
            }
            else if (formula[i] == "^"){
                nums.push(pow(A,B));
            }
            printFormula(nums,formula,i+1);
        }
    }

}