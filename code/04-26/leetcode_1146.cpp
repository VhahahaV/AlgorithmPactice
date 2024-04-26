//
// Created by VhahahaV on 2024/4/26.
//

#include "bits/stdc++.h"
////题目思路，稀疏地记录每一次修改的值以及snap_id
////运用二分去查找snap
////50min
using namespace std;
class SnapshotArray {
public:
    SnapshotArray() = default;
    int next_id = 0;
    vector<vector<pair<int,int>>> nums;
    SnapshotArray(int length) {
        nums.clear();
        nums.resize(length);
        next_id = 0;
        for(int i = 0;i < length;i++){
            nums[i].emplace_back(next_id,0);
        }
    }

    void set(int index, int val) {
        auto &num = nums[index];
        if(num.back().first == next_id)
            num.back().second = val;
        else
            num.emplace_back(next_id,val);
    }

    int snap() {
        return next_id++;
    }

    int get(int index, int snap_id) {
        auto &num = nums[index];

        // 手写二分 A了
        // 需要注意的是，该二分为左闭右开的情况，从而mid会大于等于数组的正中心
        // 为了直观体现，建议分三种情况来表示，考虑等于的情况能够更直观。
        int l = 0,r = num.size();
        while(l < r){
            int mid = (l+r)/2;
            if(num[mid].first > snap_id)
                r = mid;
            else if(num[mid].first < snap_id)
                l = mid + 1;
            else
                return num[mid].second;
        }
        return num[l-1].second;


    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main(){

    SnapshotArray snapshotArray(2);
    snapshotArray.set(0,4);
    snapshotArray.snap();
    snapshotArray.set(1,13);
    snapshotArray.snap();
    cout << snapshotArray.get(1,1);

    snapshotArray.snap();
    snapshotArray.snap();

//    cout << snapshotArray.get(0,0);
    return 0;
}
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */