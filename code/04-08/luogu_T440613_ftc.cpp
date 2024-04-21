#include <iostream>
#include <vector>
#include <array>
using namespace std;

constexpr int MAX_K = 12;
array<vector<int>, MAX_K> result;

int solve(int n, int d){
    auto mem = result[d][n];
    if(mem != -1) return mem;
    if((n-1)%d == 0) return 1;
    return result[d][n] = solve(n-(n+d-1)/d, d)+1;
}

int solve2(int n, int d){
    int cnt;
    for(cnt=1; (n-1)%d != 0; cnt++){
        n -= (n+d-1)/d;
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int Q; cin >> Q;
    while (Q--){
        int n,k; cin >> n >> k;
        int d = k+1;
        result[d].resize(std::max<size_t>(result[d].size(), n+3), -1);
        cout << solve(n, d) << '\n';
    }
    return 0;
}