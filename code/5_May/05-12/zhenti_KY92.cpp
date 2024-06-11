//
// Created by VhahahaV on 2024/5/11.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;

enum tag{
    op,num,param
};
struct word{
    tag t;
    string content;
    word(tag _t,string &_c):t(_t),content(_c){}
};
vector<double> split(string &formula){
//    ax^2+bx+c
    vector<int> cofs(3);
    int isLeft = 1;
    int cof = 1;
    for(int i = 0 ; i < formula.size();i++){
        if(isdigit(formula[i])){
            int start = i;
            while(isdigit(formula[i])){
                i++;
            }
            string content(formula.begin()+start,formula.begin()+(i--));
            int n = stoi(content);
            cof *= n;
            if ((i+1) >= formula.size()||(i+1) < formula.size() && formula[i+1] != 'x'){
                cofs[2] += (cof*isLeft);
                cof = 1;
            }
        }
        else if(formula[i]=='x'){
            int start = i;
            if ((i+1) < formula.size() && formula[i+1] == '^'){
                i+=2;
                cofs[0] += (cof*isLeft);
                cof = 1;
            }
           else{
                cofs[1] += (cof*isLeft);
                cof = 1;
           }
        }
        else{
            if (formula[i] == '='){
                isLeft = -1;
            }
            else if (formula[i] == '+'){

            }
            else if(formula[i] == '-'){
                cof *= -1;
            }
        }
    }

//    calculate
//    -b+-sqrt(b^2-4ac)/2a
    auto a = cofs[0],b=cofs[1],c=cofs[2];
    int namda = b*b-4*a*c;
    vector<double> res;
    if(namda > 0){
        res.emplace_back((-1*b-sqrt(namda))/(2*a));
        res.emplace_back((-1*b+sqrt(namda))/(2*a));

    }
    else if(namda == 0){
        res.emplace_back((-1*b)/(2*a));

    }
    return res;
}


int main() {
    string formula;
    cin >>formula;
    auto res = split(formula);
    if (res.empty()){
        cout << "No Solution";
    }
    else{
        for(auto &x : res)
            cout << fixed << setprecision(2) << x<<' ';
    }
}
// 64 位输出请用 printf("%lld")