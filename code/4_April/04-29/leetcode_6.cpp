//
// Created by VhahahaV on 2024/4/29.
//
#include "bits/stdc++.h"
//17min
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int loop = 2*numRows-2;
        int width = numRows - 1;
        // 默认初始化为0 '\000'空字符串
        vector<vector<char>> mat(numRows,vector<char>(s.size(),0));

        for(int i = 0; i < s.size() ; i++){
            int index = i % loop;
            int time = i / loop;
            int row = index<numRows ? index : 2*numRows-2-index;
            int col = index<numRows ? time*width : time*width + index-numRows + 1;
            mat[row][col] = s[i];
        }
        string ans = "";
        for(auto &i : mat){
            for(auto j : i){
                if(j)
                    ans+=j;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    solution.convert("sdfagjkuhasdilfadsfs" ,6);
    return 0;
}