//
// Created by CZQ on 2024/6/15.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++)
        cin>>nums[i];
    vector<int> diff_num(n);
    diff_num[0] = nums[0];
    for(int i = 1; i < n ; i++)
        diff_num[i] = nums[i] - nums[i-1];
//    1 0  1 0
//    0 0 -1 0
//    1 0 -1 0
    long long pos = 0 , neg = 0;
    for(int i = 1; i < n ; i++){
        if (diff_num[i] > 0)
            pos += diff_num[i];
        else if(diff_num[i] < 0)
            neg -= diff_num[i];
    }
    std::cout << max(pos,neg) << '\n' << abs(pos-neg) + 1;
    return 0;
}