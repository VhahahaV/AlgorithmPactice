//
// Created by CZQ on 2024/5/21.
//
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

//dfs复杂度太高，，， 复杂度位2^n需要剪枝
long long dfs(const vector<int>& nums,const long long ave,int index){
    if(ave<=1){
        return abs(ave);
    }
    else if(index < 0 )
        return ave;
    else{
        long long ans = ave;
        int val=nums[index];
        ans = min<long long>(ans,dfs(nums, ave-val,index-1));
//        稍微剪了一下枝，终于过了
        if(ans<=0){
            return abs(ans);
        }
        ans = min<long long>(ans, dfs(nums,ave,index-1));
        return ans;
    }
}

int main() {
    vector<int> nums{0,1,2,3,4,5};
    nums.reserve(100);
    auto it = nums.begin()+2;
    cout << *it << endl;

    nums.emplace_back(1);
    cout << *it;
    return 0;
    string line;
    while(getline(cin, line)){
        int i = 0;
        vector<int> nums;
        bool err = false;
//        似乎可以使用stringstream
        while(i < line.size()){
            while(i < line.size() && line[i]==' '){i++;}
            string num;
            while (i < line.size() && isdigit(line[i])) {
                num.push_back(line[i++]);
            }
            if(num.empty()){
                err = true;
                break;
            }
            nums.emplace_back(stoi(num));
        }
        if(err){
            cout << "ERROR\n";
            continue;
        }
        long long  sum = accumulate(nums.begin(),nums.end(),0);
        long long  ave = sum/2;
        // sort(nums.begin(),nums.end());
        long long ans = ave;
        ans = min<long long>(ans, dfs(nums, ave, nums.size()-1));
        cout << sum-ave+ans  << " " << ave-ans<< '\n';
    }
}
// 64 位输出请用 printf("%lld")