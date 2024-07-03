////
//// Created by VhahahaV on 2024/6/30.
////
//#include <iostream>
//
//#include <vector>
//
//using namespace std;
//using loc = pair<int,int>;
//int main(){
//    int N , M , K;
//    cin >> N >> M >> K;
//    long long  ans = 0;
//    if(N > M)
//        swap(N,M);
//    loc curLoc = {1,1};
//    int line = 1;
//    auto addNums = [&]()->int{
//        auto lastX = curLoc.first-1,lastY = curLoc.second-1;
//        return lastX * lastY;
//    };
//    auto stepNext = [&](){
//        auto &x = curLoc.first, &y = curLoc.second;
//        if(x == y){
//            x = ++line;
//            y = 1;
//        }
//        else if( x > y){
//            if(y == N){
//                y = 1;
//                x++;
//                return ;
//            }
//            if(x == y+1){
//                x = 1;
//                y = line;
//            }
//            else{
//                y++;
//            }
//        }
//        else{
//            x++;
//        }
//        return;
//
//    };
//    while (K--){
//        ans += addNums();
//        stepNext();
//    }
//
//    cout << ans;
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    int maxn=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        if(k/i>=m)continue;
        int len=k/i;
        int mod=k%i;
        maxn=max(maxn,(i*(i-1)/2*len*(len-1)/2+(len+1)*len/2*mod*(mod-1)/2-(len*(len-1)/2*mod*(mod-1)/2)));
    }
    for(int i=1;i<=m;i++){
        if(k/i>=n)continue;
        int len=k/i;
        int mod=k%i;
        maxn=max(maxn,(i*(i-1)/2*len*(len-1)/2+(len+1)*len/2*mod*(mod-1)/2-(len*(len-1)/2*mod*(mod-1)/2)));
    }
    cout<<maxn<<endl;
    return 0;
}