//
// Created by VhahahaV on 2024/4/2.
//


#include <iostream>
#include <bits/stdc++.h>
#include "vector"
using namespace std;


int main(){
    int N;
    cin>>N;
    int *arr=(int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    vector<int> res;
    for(int a = 0; a < N ; a++){
        for (int b = a + 1; b < N; ++b) {
            int sum = arr[a] + arr[b];
            for (int j = b+1; j <N; ++j) {
                if(sum == arr[j])
                    if (std::find(res.begin(), res.end(),sum) == res.end())
                        res.push_back(sum);
            }
        }
    }
    cout<<res.size();
    return 0;
}