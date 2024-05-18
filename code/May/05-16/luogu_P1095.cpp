//
// Created by CZQ on 2024/5/16.
//
#include "bits/stdc++.h"
using namespace std;

//7s -> 120
//1s->17
//2->60 3->60
//51
int main(){
    int M,S,T;
    cin >> M >>S >> T;
    int runDis =0,flashDis = 0;
    for(int i = 0 ; i<T;i ++){
        runDis+=17;
        if(M >= 10)
            flashDis+=60,M-=10;
        else
            M+=4;
        if(flashDis > runDis) runDis = flashDis;
        if(runDis > S){
            cout << "Yes\n" << i+1;
            return 0;
        }
    }

    cout << "No\n" << runDis;

    return 0;
}
