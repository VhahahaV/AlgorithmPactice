//
// Created by CZQ on 2024/5/18.
//

//双指针+前缀和
//双指针的题不熟悉，加练
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

constexpr int MAX = numeric_limits<int>::max();
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> maze(n+1,vector<int>(m+1));
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ;j++){
            cin >> maze[i][j];
            maze[i][j] += maze[i-1][j];
        }
    int ans = MAX;
    for(int up = 1 ; up <= n ; up++)
        for(int down = up ; down <= n ; down++){
            // 双指针，
            for(int right = 1,left=1,sum=0 ; right <= m ; right++){
                sum+=maze[down][right]-maze[up-1][right];
                while(sum-(maze[down][left]-maze[up-1][left]) >= k){
                    left++;
                    sum -= (maze[down][left]-maze[up-1][left]);
                }
                if(sum >= k)
                    ans = min(ans,(down-up+1)*(right-left+1));
            }
        }
    if(ans == MAX)
        cout << "-1";
    else
        cout << ans;
    return 0;
}
// 64 位输出请用 printf("%lld")