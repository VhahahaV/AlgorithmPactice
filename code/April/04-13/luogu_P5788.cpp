//
// Created by CZQ on 2024/4/13.
//
#include "bits/stdc++.h"

//单调栈问题，维护一个 降序的栈
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> nums(N+1);
    stack<int> stack;
    vector<int> ans(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }
    for (int i = N;i>=1 ; i--){
        if (stack.empty()){
            stack.push(i);
            continue;
        }
        else{
            int prev = nums[stack.top()];
            while (prev <= nums[i]){
                stack.pop();
                if (!stack.empty())
                    prev = nums[stack.top()];
                else
                    break;
            }
            if (!stack.empty())
                ans[i] = stack.top();
            stack.push(i);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}