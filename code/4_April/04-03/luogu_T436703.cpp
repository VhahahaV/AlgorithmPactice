//
// Created by VhahahaV on 2024/4/3.
//
#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
vector<int> ans;
void getDays(int start, int end){
    if (end < 0)
        return;
    if(arr[start] >= arr[end]){
        ans[start] += ans[end];
        int newEnd = end - ans[end] ;
        getDays(start, newEnd);
    }
    else
        return;

}
int main(){
    int N;
    cin >> N;

    arr.reserve(N);
    ans.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin>>tmp;
        arr.emplace_back(tmp);
    }
    ans.insert(ans.begin(),N,1);
    for(int i = 1 ; i < N ; i++){
        getDays(i, i - 1);
    }
    for(auto i : ans)
        cout << i << " ";

}