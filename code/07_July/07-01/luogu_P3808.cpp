//
// Created by VhahahaV on 2024/7/1.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//KMP过不了，使用哈希进行优化，依然过不了
vector<int> findNext (const string &a){
    vector<int> ans(a.size());
    int j = 0;
    for(int i = 1 ;i < a.size() ;){
        if(a[i] == a[j]){
            j++;
            i++;
            ans[i] = j;

        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = ans[j-1];
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n ;
    vector<string> modes(n);
    map<string,vector<int>> pos;
    vector<vector<int>> nexts(n);
    for(int i = 0 ; i < n ; i++){
        cin >> modes[i];
        nexts[i] = findNext(modes[i]);
    }
    string t;
    cin >> t;
    for(int i = 1 ; i < t.size();i++){
        string tmp;
        tmp.push_back(t[i-1]);
        tmp.push_back(t[i]);
        pos[tmp].emplace_back(i-1);
    }
    int ans = 0;
    map<string ,bool> cnt;
    for(int i = 0 ; i < n ; i++){
//        TLE
//        if(t.find(modes[i])!=string::npos)
//            ans++;
        const auto &cur = modes[i];
        const auto &next = nexts[i];
        if(cnt[cur]){
            ans++;
            continue;
        }
        if(cur.size()==1){
            if(t.find(cur)!=string::npos)
                ans++;
            continue;
        }
        int j = 0;
        int maybeNext = 0;
        string tmp;
        tmp.push_back(cur[0]);
        tmp.push_back(cur[1]);
        const auto &maybePos = pos[tmp];
        if(maybePos.empty())
            continue;
        for (int k = maybePos[maybeNext++]; k < t.size(); ) {
            if(cur[j] == t[k]){
                j++;
                k++;
                if(j == cur.size()){
                    cnt[cur] = true;
                    ans++;
                    break;
                }
            }
            else{
                if(j == 0){
                    if(maybeNext < maybePos.size()){
                        k = maybePos[maybeNext++];
                    }
                    else{
                        break;
                    }
                }
                else{
                    j = next[j-1];
                }
            }
        }
    }
    cout << ans;
    return 0;
}