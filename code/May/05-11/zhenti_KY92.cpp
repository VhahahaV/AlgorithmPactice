//
// Created by VhahahaV on 2024/5/11.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

enum tag{
    op,num,param
};
struct word{
    tag t;
    string content;
    word(tag _t,string &_c):t(_t),content(_c){}
};
vector<word> split(string &formula){
    vector<word> res;
    for(int i = 0 ; i < formula.size();i++){
        if(isdigit(formula[i])){

        }
    }
}

int main() {

}
// 64 位输出请用 printf("%lld")