//
// Created by VhahahaV on 2024/5/14.
//

#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    vector<int> ans;
    int getDays(int nums) {
        if (ans[nums])
            return ans[nums];
        int F1 = getDays(nums - 2), F2 = getDays(nums - 3);
        if (F1 == -1 && F2 == -1)
            ans[nums] = -1;
        else if (F1 == -1 || F2 == -1)
            ans[nums] = F1 == -1 ? F2 + 1 : F1 + 1;
        else
            ans[nums] = min(F1, F2) + 1;
        return ans[nums];
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        int maxCnt = 0;
        for (auto i : tasks) {
            if (!cnt.count(i))
                cnt[i] = 1;
            else
                cnt[i] += 1;
            maxCnt = max(maxCnt, cnt[i]);
        }
        ans.resize(maxCnt + 3, 0);
        ans[1] = -1;
        ans[2] = ans[3] = 1;
        int sum = 0;
        for (auto& [k, v] : cnt) {
            int day = getDays(v);
            if (day == -1) {
                sum = -1;
                break;
            }
            sum += day;
        }
        return sum;
    }
};
