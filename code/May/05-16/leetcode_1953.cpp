//
// Created by CZQ on 2024/5/16.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(),milestones.end());
        // int prefix = 0;
        // auto minProject = upper_bound(milestones.begin(),milestones.end(),prefix+1);
        // long long  ans = 0;
        // while(minProject != milestones.end() && minProject!= milestones.end()-1){
        //     int minTask = *minProject-prefix-1;
        //     prefix+=(minTask);ans+=minTask*(milestones.end()-minProject);
        //     minProject = upper_bound(milestones.begin(),milestones.end(),prefix+1);
        // }
        // int max_tasks = milestones.back()-prefix;()
        // ans+=min((2*milestones.size()-1),(milestones.size()+max_tasks-1));
        // return ans;

        sort(milestones.begin(),milestones.end(),greater<int>());
        long long longest = *max_element(milestones.begin(),milestones.end());
        long long rest = accumulate(milestones.begin(),milestones.end(),0LL)-longest;
        if(longest > rest + 1)
            return rest*2+1;
        else{
//            可以完成所有工作
            return longest+rest;
        }

    }
};
int main(){
    vector<int> mile{1,10,7,1,7,2,10,10,355359359};
    Solution solution;
    solution.numberOfWeeks(mile);
    return 0;
}