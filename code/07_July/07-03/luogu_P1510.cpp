////
//// Created by VhahahaV on 2024/7/3.
////
#include <iostream>

#include <vector>
using namespace std;
using ull = unsigned long long;

struct node{
    ull vol, con;
};

//dp[c] = {dp[c - col] + val}min

int main(){
    ull v, n, c;
    cin >>  v >> n >> c;
    vector<node> nodes(n+1);
    for(ull i = 1 ; i <= n ; i++)
        cin >> nodes[i].vol >> nodes[i].con;
    vector<ull> dp(c+1);


    for(ull i = 1 ; i <= n ; i++){
        for(ull j = c ; j >= nodes[i].con ; j--){
            if(dp[j] < dp[j - nodes[i].con] + nodes[i].vol)
                dp[j] = dp[j - nodes[i].con] + nodes[i].vol;
        }
    }

    for(ull i = 1 ; i <= c ; i++){
        if(dp[i] >= v){
            cout << c-i;
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}
