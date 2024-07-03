//
// Created by VhahahaV on 2024/6/30.
//
#include <iostream>
#include <vector>
using namespace std;
using loc = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> circles(n,vector<int>(3));
    for(int i = 0 ; i < n ; i++){
        cin >> circles[i][0];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> circles[i][1];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> circles[i][2];
    }
    loc u , v;
    cin >> u.first >> u.second >> v.first >> v.second;

    auto inCircle = [](vector<int> cir ,  loc point)->bool {
        return (point.first-cir[0])*(point.first-cir[0])+(point.second-cir[1])*(point.second-cir[1]) < cir[2]*cir[2];
    };

    int ans = 0;
    for(auto circle : circles){
        bool flag1 = inCircle(circle,u),flag2 = inCircle(circle,v);
        ans += (flag1 ^ flag2);
    }
    cout << ans;
    return 0;
}