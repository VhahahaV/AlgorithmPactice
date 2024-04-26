//
// Created by VhahahaV on 2024/4/26.
//
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
//归并排序 ，手撸一个
//1h15min
vector<ll> tmp;
vector<ll> nums;
ll ans = 0;

void merge(int start,int end){
    int mid = start + (end - start) / 2;
    int i = start, j = mid + 1;
    int tmp_idx = start;
    while( i <= mid && j <= end){
        if (nums[i] <= nums[j])
            tmp[tmp_idx++] = nums[i++];
        else{
            tmp[tmp_idx++] = nums[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid) tmp[tmp_idx++] = nums[i++];
    while (j <= end) tmp[tmp_idx++] = nums[j++];
    for (int k = start; k <= end; ++k) {
        nums[k] = tmp[k];
    }
}

void mergeSort(int start ,int end){
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    merge(start,end);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int sum;
    cin >> sum;
    nums.resize(sum);
    tmp.resize(sum);
    for (int i = 0; i < sum; ++i) {
        cin >> nums[i];
    }
    mergeSort(0,sum-1);
    cout << ans;

    return 0;
}