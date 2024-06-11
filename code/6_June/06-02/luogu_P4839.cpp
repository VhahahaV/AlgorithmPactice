//
// Created by CZQ on 2024/6/2.
//
#include "vector"
#include <iostream>
using namespace std;
using numSet = vector<int>;
auto getHighestBit = [](int a)->int{
    int n = 0;
    while(a){
        n++;
        a = a>>1;
    }
    return n-1;
};

auto getNext = [](int a)->int {
    int n = getHighestBit(a);
    for(int res = n-1;res >=0;res--){
        if( !(a & (1<<res)) )
            return res;
    }
    return -1;
};

int ans = 0;
void dfs(int pos,const vector<numSet>& tmp,int val){
    if(pos < 0 ){
        return;
    }
    auto &buk = tmp[pos];
    for(auto num : buk){
        int cur = val ^ num;
        ans = max(ans,cur);
//        拿到离最大的1的位置最近的0位
        dfs(getNext(cur),tmp,cur);
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n , m ;
    cin >> n >> m;
    vector<vector<numSet>> bucket(m+1,vector<numSet>(32));

    while(n--){
        int mode;
        cin >> mode;
        if(mode == 1){
            int k ,x;
            cin >> k >>x;
            bucket[k][getHighestBit(x)].emplace_back(x);
        }
        else{
            int l , r;
            cin >> l >> r;
            ans = 0;
            vector<numSet> tmp(32);
            for(int i = l ; i <=r; i++){
                auto &buc = bucket[i];
                for(int j = 0 ; j < 32 ; j++)
                    for(auto num:buc[j])
                        tmp[j].emplace_back(num);
            }
            for(int i = 31; i>=0;i--){
                auto &buc = tmp[i];
                if(!buc.empty()){
                    for(auto num:buc)
                        dfs(i,tmp,0);
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}