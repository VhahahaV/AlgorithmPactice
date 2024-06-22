//
// Created by VhahahaV on 2024/6/22.
//
#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int  n , x;
    cin >>n >>x;
    vector<int> candy(n);
    unsigned long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> candy[i];
        if(candy[i] > x){
            sum += (candy[i]-x);
            candy[i] = x;
        }
    }

//    先处理第一优先级的
    while (true){
        bool flag = false;
        for(int i = 1 ; i < n-1 ;i++){
            if(candy[i] + candy[i-1] > x && candy[i] + candy[i+1] > x){
                flag = true;
                int minCandy = min(candy[i] + candy[i-1] - x , candy[i] + candy[i+1] - x);
                sum+=minCandy;
                candy[i]-=minCandy;
            }
        }
        if(!flag)
            break;
    }


//    处理第二优先级
    while (true){
        bool flag = false;
        for(int i = 1 ; i < n-1 ;i++){
            if(candy[i] + candy[i-1] > x || candy[i] + candy[i+1] > x){
                flag = true;
                int minCandy = max(candy[i] + candy[i-1] - x , candy[i] + candy[i+1] - x);
                sum+=minCandy;
                candy[i]-=minCandy;
            }
        }
        if(!flag)
            break;
    }

    cout << sum;

    return 0;
}