//
// Created by CZQ on 2024/6/21.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = height[0] , right = 0;
        int i = 0;
        long res = 0;
        auto findRight = [&](int i)->int{
            if(i == n-1) return i;
            int tmp = i;
            int cur = height[i++];
            int maxIdx = i , maxHei = height[i];
            while (i < n && cur > height[i]){
                if(height[i] > maxHei){
                    maxHei = height[i];
                    maxIdx = i;
                }
                i++;
            }
            if(i == n){
                height[tmp] = maxHei;
                i = maxIdx;
            }
            return i;
        };

        while(i < n){

            while (i+1 < n && !left)
                left = height[++i];
            if(!left)
                break;

            auto rightIdx = findRight(i);
            if(rightIdx == i)
                break;

            right = height[rightIdx];
            left = height[i];
            int cur = min(left,right);
            i++;
            while(i < rightIdx){
                res += (cur - height[i++]);
            }
            left = height[i];
        }
        return res;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0 ; i < n ; i++)
        cin >> height[i];
    int left = height[0] , right = 0;
    int i = 0;
    long res = 0;
    auto findRight = [&](int i)->int{
        int tmp = i;
        int cur = height[i++];
        int maxIdx = i , maxHei = cur;
        while (i < n && cur > height[i]){
            i++;
            if(height[i] > maxHei){
                maxHei = height[i];
                maxIdx = i;
            }
        }
        if(i == n){
            height[tmp] = maxHei;
            i = maxIdx;
        }
        return i;
    };

    while(i < n){

        while (!left)
            left = height[++i];

        right = findRight(i);
        left = height[i];

        int cur = min(left,right);
        i++;
        while(i < right){
            res += (cur - height[i++]);
        }
        left = height[i];
    }
    cout << res;
    return 0;
}