//
// Created by CZQ on 2024/5/19.
//
//所有语言和计算器都遵循了尽量让商尽量靠近0的原则，即5%(-3) 的结果为2而不是-1，(-5)%3的结果是-2而不是1。
#include"bits/stdc++.h"

using namespace std;
int main(){
    map<string,int> Months{{"January",1}, {"February",2}, {"March",3}, {"4_April",4}, {"5_May",5}, {"6_June",6}, {"July",7},{ "August",8}, {"September",9}, {"October",10}, {"November",11},{ "December",12}};
    vector<string> Weeks{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    vector<vector<int>> dayTable{
            {31,28,31,30,31,30,31,31,30,31,30,31},
            {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    int day,year;
    string month;
    auto isLeap = [](int y)->bool{
        return ((y%4==0)&&(y%100!=0)) || (y%400==0);
    };
    auto isEarlier = [&](int d1,string m1,int y1,int d2,string m2,int y2) ->bool{
        if(y1!=y2) return y1<y2;
        if(m1!=m2) return Months[m1]<Months[m2];
        if(d1!=d2) return d1<d2;
        return false;
    };
    auto haveByDay = [&](int y,string m,int d)->int{
        int mon = Months[m];
        int ans = 0;
        if(isLeap(y)){
            for(int i = 0 ; i < mon-1 ;i++)
                ans+=dayTable[1][i];
        }
        else{
            for(int i = 0 ; i < mon-1 ;i++)
                ans+=dayTable[0][i];
        }
        return ans+d;
    };
    auto getDifferDay = [&](int y1,string m1,int d1,int y2,string m2,int d2)->int {
        int flag = -1;
        if(isEarlier(d1,m1,y1,d2,m2,y2)){
            swap(d1,d2), swap(m1,m2), swap(y1,y2);
            flag = 1;
        }
        int diffYears = y1-y2;
        if(diffYears){
            int differDays;
            if(isLeap(y2) )
                differDays = 366-haveByDay(y2,m2,d2);
            else
                differDays = 365-haveByDay(y2,m2,d2);
            for(int cur = y2+1; cur < y1 ; cur++){
                if(isLeap(cur))
                    differDays += 366;
                else
                    differDays += 365;
            }
            differDays+=haveByDay(y1,m1,d1);
            return differDays*flag;
        }
        return 0;
    };

    // 2024/5/20 = Mon
    while(cin >> day >> month >> year){
        int differDays = getDifferDay(2024,"5_May",20,year,month,day);
        cout <<Weeks[(differDays%7+7)%7]<<'\n';
    }
    return 0;
}