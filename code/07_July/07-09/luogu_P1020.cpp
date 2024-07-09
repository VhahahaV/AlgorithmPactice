//
// Created by VhahahaV on 2024/7/9.
//
#include <bits/stdc++.h>

using namespace std;

int main(){

    string hei;
    vector<int> dd;
    string line;
    getline(cin,line);
    stringstream ss(line);
    while(ss >> hei){
        dd.emplace_back(stoi(hei));
    }

//    for(auto h : dd)
//        cout << h << endl;

    vector<int> dq;

    int ans1 = 0;
    for(auto h :dd){
        if(dq.empty())
            dq.emplace_back(h);
        else{
                auto it = upper_bound(dq.begin(),dq.end(),h,greater<int>());
                if(it == dq.end()){
                    dq.emplace_back(h);
                }
                else{
                    *it = h;
                }
        }
    }
//    for(int i = (int)dd.size()-1; i >= 0;i--){
//            for(int j = i+1 ; j < dd.size() ; j++){
//                if(dd[j] <= dd[i]){
//                    dq[i] = max(dq[i],dq[j]+1);
//                }
//            }
//        ans1 = max(ans1,dq[i]);
//    }
    ans1 = dq.size();
    vector<int> q;

    for(int i = 0 ; i < dd.size() ; i++){
        if(q.empty())
            q.emplace_back(dd[i]);
        else{
            auto pos = std::lower_bound(q.begin(), q.end(),dd[i]);
            if(pos == q.end()){
                q.emplace_back(dd[i]);
            }
            else{
                *pos = dd[i];
            }
        }
    }
    cout << ans1 << endl << q.size();


    return 0;
}