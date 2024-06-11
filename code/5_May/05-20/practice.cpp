//
// Created by CZQ on 2024/5/20.
//字节一面
//题目：对于一个vec，在不使用其他数组或结构的情况下，向右shift k位
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
//    直接跳着走 swap N次
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    int start = 0;
    int i = 0;
    int swapNum = 0;
    int siz = nums.size();
    int tmp = nums[0];
    do{
        swap(tmp,nums[(i+k)%siz]);
        swapNum++;
        i = (i+k)%siz;
        if(i == start){
            i = ++start;
        }
    }while(swapNum != 10);
    for(int j = 0 ;j < 9 ; j++){
        cout << nums[j] << " ";
    }


//    也可以1~n对称变换一次 1~k,k+1~n分别对称变换一次
    return 0;
}