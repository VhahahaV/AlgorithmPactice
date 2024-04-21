//
// Created by VhahahaV on 2024/4/3.
//
#include <bits/stdc++.h>

using namespace std;
string res = "";
int N;
int getPath(string line1,string line2,int len){
    if (len == 1){
        res += line2;
        return 1;
    }
    if (line1[1] < line2[0]){
        res += line1[1];
        line1.erase(line1.begin());
        line2.erase(line2.begin());
        return getPath(line1,line2,len-1);
    }
    else if (line1[1] > line2[0]){
        res += line2;
        return 1;
    }
    else{
//        cout << res << endl;
        string res_tmp = res + line2;
        res += line1[1];
        line1.erase(line1.begin());
        line2.erase(line2.begin());
        int addedNum =  getPath(line1,line2,len-1);
        if(res_tmp > res)
            return addedNum;
        else if (res_tmp < res){
            res = res_tmp;
            return 1;
        }
        else
            return addedNum + 1;

    }

}
int main(){
    cin >> N;
    string line1, line2;
    cin >> line1 >> line2;
    res += line1[0];
    int num = getPath(line1,line2,N);
    cout << res << endl << num;
}