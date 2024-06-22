//
// Created by VhahahaV on 2024/6/22.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<size_t> lens;
        stack<char> valid;
        vector<int> validIdx(s.size(), 0);
        int res = 0;
        auto findValidIndex = [&](int idx) -> int{
            if (s[idx] == ')') {
                return idx+1;
            }
            int pos = idx;
            stack<int> tmp;
            tmp.push(idx++);
            while (!tmp.empty()) {
                if (idx == s.size())
                    break;
                auto cur = s[idx];
                if (cur == '(')
                    tmp.push(idx);
                else{
                    validIdx[tmp.top()] = idx;
                    tmp.pop();
                }
                idx++;
            }
            if (tmp.empty()){
                validIdx[pos] = idx - 1;
                return idx;
            }
            else{
                return s.size();
            }
        };
        for (int i = 0; i < s.size(); )
            i = findValidIndex(i);

        auto updateRes = [&]()->void{
            int curLen = 0;
            while (!lens.empty()) {
                curLen += lens.top();
                lens.pop();
            }
            res = max(res, curLen);
        };
        for (int i = 0; i < s.size(); i++) {
            if (lens.empty() || !lens.empty() && validIdx[i]) {
                if (validIdx[i]) {
                    lens.push(validIdx[i] - i + 1);
                    i = validIdx[i];
                }
            } else {
                updateRes();
            }
        }
        updateRes();

        return res;
    }
};