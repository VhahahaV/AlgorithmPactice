//
// Created by CZQ on 2024/5/15.
//

#include "bits/stdc++.h"

//TLE了，估计是每次循环都需要max_element
//使用哈希表存储每一天的利用率
using namespace std;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        map<int,unordered_set<int>> cnt;
        vector<int> ans;
        int tasks_num = tasks.size();
        auto cmp = [](const pair<int,unordered_set<int>> a , const pair<int,unordered_set<int>> b)->bool{
            return a.second.size() < b.second.size();
        };
        for(int index = 0 ; index < tasks_num;index++){
            auto &task = tasks[index];
            auto s = task[0],t = task[1];
            for(int i = s ; i <= t ; i++){
                cnt[i].insert(index);
            }
        }
        int cover_task= 0;
        while(cover_task != tasks_num){
            auto maxday = max_element(cnt.begin(),cnt.end(),cmp);
            auto indexs = maxday->second;
            for(auto index : indexs){
                if((--tasks[index][2]) == 0 ){
                    auto &task = tasks[index];
                    auto s = task[0],t = task[1];
                    for(int i = s ; i <= t ; i++){
                        auto it = cnt[i].find(index);
                        cnt[i].erase(it);
                    }
                    cover_task++;
                }

            }
            ans.emplace_back(maxday->first);
        }
        return ans.size();

    }
};



//参考贪婪的做法
class Solution_Correct {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &t1, const vector<int> &t2) -> bool {
            return t1[1] < t2[1];
        });
        vector<int> run(tasks[n - 1][1] + 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            res += max(duration, 0);
            for (int j = end; j >= 0 && duration > 0; j--) {
                if (run[j] == 0) {
                    duration--;
                    run[j] = 1;
                }
            }
        }
        return res;
    }
};


int main(){
//    map<int,int> cnt;
//    cout << cnt[2];
    vector<vector<int>> tasks{{1,2000,2000}};
    Solution solution;
    cout << solution.findMinimumTime(tasks);
    return 0;
}