//
// Created by VhahahaV on 2024/4/2.
//


#include <iostream>
#include <bits/stdc++.h>
long long dp[30][30];
int main(){
    long w,h,x,y;
    std::cin>>w>>h>>x>>y;
    const int delta[9][2]{
            0,0
            ,1,2
            ,1,-2
            ,2,1
            ,2,-1
            ,-1,2
            ,-1,-2
            ,-2,-1
            ,-2,1
    };
    std::memset(dp,0,sizeof(dp));
    for (auto i : delta) {
        int xx = x + i[0];
        int yy = y + i[1];
        if (xx < 0 || xx > w || yy < 0 || yy > h)
            continue;
        dp[xx][yy] = -1;

    }
    if (dp[w][h] == -1){
        std::cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= w; ++i) {
        for (int j = 0; j <= h; ++j) {
            if (dp[i][j] == -1)
                continue;
            if(i && dp[i-1][j] != -1)
                dp[i][j] += dp[i - 1][j];
            if(j && dp[i][j-1] != -1)
                dp[i][j] += dp[i][j - 1];
        }
    }

    std::cout << dp[w][h];

    return 0;
}


//ATTENTION:注意不同类型的长度
//short int and int: -32,767 to 32,767
//unsigned short int and unsigned int: 0 to 65,535
//long int: -2,147,483,647 to 2,147,483,647
//unsigned long int: 0 to 4,294,967,295
//long long int: -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
//unsigned long long int: 0 to 18,446,744,073,709,551,615