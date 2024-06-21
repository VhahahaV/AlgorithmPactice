//
// Created by CZQ on 2024/6/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct House{
    int b,e,t;
    House() = default;
    bool operator< (const House &other) const{
        return e < other.e || ( e == other.e && b > other.b);
    }
};
//要求区间的相交的数量最大的时候，优先考虑在尾部区间
int main(){
    int n,h;
    cin >> n >> h;
    vector<House> trees(h);
    for( int  i = 0 ; i < h ; i++){
        cin >> trees[i].b	>> trees[i].e  >> trees[i].t;
    }
    sort(trees.begin(),trees.end());
    int sum = 0;
    vector<bool> isPlanted(n+1,false);
    for(auto &house : trees){
        int curPlanted = 0;
        for(int i = house.b ;i<=house.e ; i++)
            if(isPlanted[i])
                curPlanted++;
        int j = house.e;
        while(curPlanted < house.t){
            if(!isPlanted[j]){
                isPlanted[j] = true;
                curPlanted++;
                sum++;
            }
            j--;
        }
    }
    cout << sum;


//    b e
//
}