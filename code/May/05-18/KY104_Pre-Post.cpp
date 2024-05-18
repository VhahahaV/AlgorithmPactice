#include <iostream>
#include <string>
using namespace std;
// pre: root,child1->childm
// post:child1->childm,root

//80min+
void getPosssible(string pre, string post, int m, int& ans) {
    if(pre == "") return;
    if (pre.front() == post.back()) {
        // 位于同一颗根节点的树上
        int len = post.size();
        ans *= m;
        getPosssible(pre.substr(1,len-1), post.substr(0,len-1), m, ans);
    } else {
        // 位于不同根节点的树上
        int rootNum = 0;
        while (!pre.empty()) {
            char root1 = pre.front();
            int root1Len = post.find(root1) ;
            getPosssible(pre.substr(1, root1Len), post.substr(0, root1Len),  m,  ans);
            rootNum++;
            int restLen = post.size() - root1Len;
            if(!restLen) break;
            pre = pre.substr(root1Len+1, restLen);
            post = post.substr(root1Len+1, restLen);
        }
        // 得到分支数
        int a = 1, b = 1;
        for (int i = 0 ; i < rootNum; i++) {
            a *= (m - i);
            b *= (rootNum - i);
        }
        ans *= (a / b);

    }
}
int main() {
    int m;
    while (cin >> m && m != 0) {
        string pre, post;
        cin >> pre >> post;
        int ans = 1;
        int len = post.size();
        getPosssible(pre.substr(1,len-1), post.substr(0,len-1), m, ans);
        cout << ans << '\n';
    }
}
// 64 位输出请用 printf("%lld")