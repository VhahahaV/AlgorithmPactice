//
// Created by VhahahaV on 2024/6/22.
//

#include <iostream>
#include <string>
using namespace std;


string getPre(string mid , string post){
    if(mid.empty() && post.empty()) return "";
    auto root = post.back();

    int midRootIdx = 0;
    while(mid[midRootIdx] != root)
        midRootIdx++;

    string midLeft = mid.substr(0,midRootIdx);
    string midRight = mid.substr(midRootIdx+1);
    string postLeft = post.substr(0,midRootIdx);
    string postRight = post.substr(midRootIdx);
    postRight.pop_back();

    string pre = root + getPre(midLeft,postLeft) + getPre(midRight,postRight);
    return pre;

}

int main(){
    string middle , post;
    cin >> middle >> post;

    cout << getPre(middle,post);

    return 0;
}