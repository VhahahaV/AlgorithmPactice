//
// Created by VhahahaV on 2024/4/2.
/**
 # 【深基2.例12】上学迟到

## 题目描述

学校和 yyy 的家之间的距离为 $s$ 米，而 yyy 以 $v$ 米每分钟的速度匀速走向学校。

在上学的路上，yyy 还要额外花费 $10$ 分钟的时间进行垃圾分类。

学校要求必须在上午 $\textrm{8:00}$  到达，请计算在不迟到的前提下，yyy 最晚能什么时候出门。

由于路途遥远，yyy 可能不得不提前一点出发，但是提前的时间不会超过一天。

## 输入格式

一行两个正整数 $s,v$，分别代表路程和速度。

## 输出格式

输出一个 $24$ 小时制下的时间，代表 yyy 最晚的出发时间。

输出格式为 $\texttt{HH:MM}$，分别代表该时间的时和分。必须输出两位，不足前面补 $0$。

## 样例 #1

### 样例输入 #1

```
100 99
```

### 样例输出 #1

```
07:48
```

## 提示

对于 $100\%$ 的数据，$1 \le s,v \le 10^4$。
 **/
#include<iostream>
#include "cstring"

using namespace std;

int main(){
    int N ;
    cin >> N;
    int res[40][40];
    memset(res,0, sizeof(res));
    int mid = N / 2;
    res[0][mid] = 1 ;
    int max = N * N;
    int preRow = 0;
    int preCol = mid;
    for(int i  = 1 ; i < max ; i++){

        if(preRow == 0 && preCol < N - 1){
            res[N-1][preCol + 1] = i + 1;
            preRow  = N -1;
            preCol = preCol + 1;
        }
        else if (preRow != 0 && preCol == N - 1){
            res[preRow - 1][0] = i + 1;
            preRow  =preRow - 1;
            preCol =0;
        }
        else if (preRow == 0 && preCol == N - 1){
            res[preRow + 1][preCol] = i + 1;
            preRow  = preRow + 1;
        }
        else if (res[preRow - 1][preCol + 1] == 0){
            res[preRow - 1][preCol + 1] = i + 1;
            preRow  =preRow - 1;
            preCol = preCol + 1;
        }
        else{
            res[preRow + 1][preCol] = i + 1;
            preRow  = preRow + 1;
        }

    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

};