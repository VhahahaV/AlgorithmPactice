//
// Created by VhahahaV on 2024/6/27.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    int NP;
    int caseId = 1;
    while(cin>>NP){
        if(!NP) break;
        map<int,int> cnt;
        for(int i = 0 ; i < NP ; i++){
            int t;
            cin>>t;
            cnt[i+1] = t;
        }
        int NF;

        cin>>NF;
        vector<pair<map<int,int>,map<int,int>>> petri(NF);
        for(int i=0;i<NF;i++){
            auto &trans = petri[i];
            int put,input=0,output=0;
            while(true){
                cin>>put;
                if(!put) break;
                else if(put>0){
                    trans.second[put]++;
                }
                else
                    trans.first[put*-1]++;
            }
        }

        int transNum;
        cin>>transNum;
        auto canFire = [&](const pair<map<int,int>,map<int,int>> &trans) ->bool {
            for(const auto &[key,val]:trans.first){
                if(cnt[key] < val)
                    return false;
            }
            return true;
        };

        auto fireOnce = [&](const pair<map<int,int>,map<int,int>> &trans){
            for(const auto &[key,val]:trans.first){
                cnt[key] -= val;
            }
            for(const auto &[key,val]:trans.second){
                cnt[key] += val;
            }
        };
        int tmpNum=transNum;
        while(transNum){
            bool live= false;
            for(int i=0;i<NF;i++){
                const auto &trans = petri[i];
                while (canFire(trans) && transNum > 0){
                    live = true;
                    fireOnce(trans);
                    transNum--;
                }
            }

            if(!live)
                break;
        }
        if (!transNum){
            cout << "Case "<<caseId++<<": still live after "<<tmpNum<<" transitions\n";
        }
        else{
            cout << "Case "<<caseId++<<": dead after "<<tmpNum-transNum<<" transitions\n";
        }
        cout << "Places with tokens: ";
        for(auto &[k,v]:cnt){
            if(v)
                cout << k << " (" << v << ") ";
        }
        cout << '\n';

    }
    return 0;
}