//
// Created by VhahahaV on 2024/4/3.
//

#include <bits/stdc++.h>

using namespace std;



int handleBracket(string md){
    if (md[0] == '{' || md[0] == '['){
        stack<int> tmp;

        for(int i = 0 ; i < md.size(); i++){
            if(md[i] == '{' || md[i] == '['){
                tmp.push(md[i]);
            }
            else if (md[i] == '}' || md[i] == ']'){
                tmp.pop();
            }
            if (tmp.empty())
                return i;
        }
    }
}

int handleNumber(string md){
    for(int i = 0 ; i < md.size(); i++)
        if (md[i]<'0' || md[i] >'9' || md[i] != '.' )
            return i-1;
}

void calculateNum(stack<double> &nums , stack<char> &operations){
    while (!operations.empty()){
        char op = operations.top();
        operations.pop();
        double B = nums.top();
        nums.pop();
        double A = nums.top();
        nums.pop();
        switch (op) {
            case '+':
                nums.push(A+B);
                break;
            case '-':
                nums.push(A-B);
                break;
            case '*':
                nums.push(A*B);
                break;
            case '/':
                nums.push(A/B);
                break;
            case '^':
                nums.push(pow(A,B));
                break;
        }
    }
}



double handleFormula(string md){
    stack<double> nums;
    stack<char> operations;
    for (int i = 0; i < md.size(); ) {
        switch (md[i]) {

//        handle basic operations
            case '+':
            case '-':
                if (operations.empty() || operations.top() == '+' ||operations.top() == '-' )
                    operations.push(md[i]);
                else{
                    calculateNum(nums,operations);
                    operations.push(md[i]);
                }
                i+=1;
                break;

            case '*':
            case '/':
                if (operations.empty() || operations.top() == '+' ||operations.top() == '-'
                                        || operations.top() == '/' ||operations.top() == '*' )
                    operations.push(md[i]);
                else{
                    calculateNum(nums,operations);
                    operations.push(md[i]);
                }
                i+=1;
                break;

            case '^':
                operations.push(md[i]);
                i+=1;
                break;

//            handle functions
            case '\\':

                break;


//            handle numbers
            defaut:
                int next = handleNumber(md.data());
                string numStr(md,0,next);
                double newNum = stod(numStr);
                nums.push(newNum);
                i+=next;
                break;

        }
    }
}