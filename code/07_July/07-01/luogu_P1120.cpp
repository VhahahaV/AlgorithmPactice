//
// Created by VhahahaV on 2024/7/1.
//
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int N = 70 ;
vector<int> bucket(N+1);
int maxn = numeric_limits<int>::min(), minn = numeric_limits<int>::max() /* 2 */ ;

void dfs( int res , int sum , int target , int p ) {
    if( res == 0 ) {
        cout << target;
        exit( 0 );
    }
    if( sum == target ) {
        dfs( res - 1 , 0 , target , maxn );
        return;
    }
    for( int i = p ; i >= minn ; i -- ) { // 2  3
        if(bucket[ i ] && i + sum <= target ) {
            bucket[ i ] -- ;
            dfs( res , sum + i , target , i );
            bucket[ i ] ++ ;
            if ( sum == 0 || sum + i == target )  //4
                break;
        }
    }
    return;
}



int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i=0 ; i <n ; i++){
       int tmp;
       cin >>tmp;
       bucket[tmp]++;
       sum += tmp;
       maxn = max(maxn,tmp);
       minn = min(minn,tmp);
    }

    for(int num = n ; num >= 1 ; num--){
        if(sum % num)
            continue;
        int target = sum / num;
        dfs(num,0,target,maxn);
    }

    return 0;
}