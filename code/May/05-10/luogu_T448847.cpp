//
// Created by VhahahaV on 2024/5/10.
//

#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
constexpr int MOD = 1e9+7;
bool isValid(char a , char b){
    if(a == '0') return false;
    return 10*(a-'0')+(b-'0') < 26;
}
int main(){
    int n ;
    string ciphertext;
    cin >> n >> ciphertext;
    vector<ull> dp(n+1);
//    vector<int> nums(n+1);
//    nums.emplace_back(0);
//    for(int i = 1; i <= n ;i++)
//        nums[i] = ciphertext[i-1]-'0';
//    dp[n] = 1;
//    if (nums[n-1]*10+nums[n] > 25)
//        dp[n-1] = 1;
//    else
//        dp[n-1] = 2;
//    for(int i = n - 2 ; i >= 1 ; i--){
//        if (nums[i]*10+nums[i+1] >= 25)
//            dp[i] = dp[i+1];
//        else
//            dp[i] = (dp[i+1]+dp[i+2])%MOD;
//    }
//    cout <<  dp[1];
    dp[1] = 1;
    for(int i = 2; i <= n ; i++){
        dp[i] += dp[i-1];dp[i]%=MOD;
//        if(nums[i-1] *10 + nums[i] <= 25){
        if(isValid(ciphertext[i-2],ciphertext[i-1])){
            if (i==2)
                dp[i]+=1;
            else
                dp[i]+=dp[i-2];dp[i]%=MOD;

        }
    }
    cout << dp[n];
    return 0;
}