//
// Created by CZQ on 2024/5/18.
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//36min
//啥博弈数据集卡大小
//注意map的iterater是属于bidirectional,这种类型的迭代器没有提供运算符 加号，（但是自加和自减可以）
//https://cplusplus.com/reference/iterator/  迭代器
//https://blog.csdn.net/dauiwsbd/article/details/119490444  双指针
int main(){
    int n,c;
    cin >> n >> c;
    map<int,int> nums;
    for(int i =0 ;i < n ; i++){
        int tmp;cin>>tmp;
        nums[tmp]++;
    }
    unsigned long long  ans= 0;
    auto left = nums.begin();
    for(auto right = left; right!=nums.end();right++){
        int cha = right->first-left->first;
        while(cha >= c && left!=right){
            if(cha == c)
                ans+=(unsigned long long)( left->second)*(unsigned long long)right->second;
            cha = right->first-(++left)->first;
        }

    }
    cout << ans;
    return 0;
}