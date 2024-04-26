//
// Created by VhahahaV on 2024/4/26.
//
#include "bits/stdc++.h"

using namespace std;

vector<int> father;

////8min
int findRoot(int child){
    if (child != father[child]){
        father[child] = findRoot(father[child]);
    }
    return father[child];
}

void joint(int a, int b){
    int fa1 = findRoot(a);
    int fa2 = findRoot(b);
    if (fa1 != fa2){
        father[fa1] = fa2;
    }
}

bool judge(int a,int b){
    return findRoot(a) == findRoot(b);
}

int main(){
    int N,M;
    cin >> N >>M;
    father.resize(N+1);
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
    }
    while (M--){
        int op,a,b;
        cin >> op >> a >> b;
        if (op == 1){
            joint(a,b);
        }
        else{
            if (judge(a,b))
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }
    return 0;
}