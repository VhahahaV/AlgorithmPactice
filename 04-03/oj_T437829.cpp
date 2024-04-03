//
// Created by VhahahaV on 2024/4/3.
//

#include <bits/stdc++.h>

using namespace std;

int handleBracket(string md)    {
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
    for(int i = 0 ; i < md.size(); i++){
        if (md[i]>='0' && md[i] <='9' || md[i] == '.' )
            continue;
        else
            return i;
    }
    return md.size();
}

void calculateNum(stack<double> &nums , stack<char> &operations ,int level){
    bool flag;
    switch(level) {
        case 1:
            flag = !operations.empty();
            break;
        case 2:
            flag = !operations.empty()&&operations.top() != '+' && operations.top() != '-';
            break;
        case 3:
            flag = !operations.empty()&&operations.top() == '^';
            break;
    }
    while (flag){
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
        switch(level) {
            case 1:
                flag = !operations.empty();
                break;
            case 2:
                flag = !operations.empty()&&operations.top() != '+' && operations.top() != '-';
                break;
            case 3:
                flag = !operations.empty()&&operations.top() == '^';
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
                    calculateNum(nums,operations,2);
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
                    calculateNum(nums,operations,3);
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
            default:
                int next = handleNumber(string (md.begin()+i,md.end()));
                string numStr(md,i,next);
                double newNum = stod(numStr);
                nums.push(newNum);
                i+=next;
                break;

        }


    }
    if(!operations.empty())
        calculateNum(nums,operations,1);

    return nums.top();
}

int main(){
    string formula;
    cin >> formula;
    double res =  handleFormula(formula);
    int n = 0;
    while (abs(res) > 10){
        res /= 10;
        n++;
    }
    cout << fixed << setprecision(6) << res << " " << n;
}