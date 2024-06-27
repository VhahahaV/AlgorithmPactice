//
// Created by VhahahaV on 2024/6/27.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//
//struct MemPage{
//    int id;
//    int useCnt;
//    int timeStamp;
//    MemPage *next = nullptr,*last = nullptr;
//    MemPage(int i,int n,int useCnt): id(i),useCnt(n), timeStamp(useCnt){}
//    bool operator<=(const MemPage &other) const{
//        if(useCnt != other.useCnt)
//            return useCnt <= other.useCnt;
//        else
//            return timeStamp >= other.timeStamp;
//    }
//};
//
//int main(){
//    ifstream input("input.txt");
//    int n,m;
//    input >> n >> m;
//    map<int,int> cnt;
//    map<int,MemPage*> pages;
//
//    MemPage *lastUse = nullptr;
//    MemPage *head = nullptr;
//    auto searchMem = [&](int key)->bool {
//        return cnt.count(key);
//    };
//
//    auto findInsert = [&](MemPage *curLoc)->MemPage*{
//        auto ans = curLoc;
//        while(ans && * ans <= *curLoc){
//            ans = ans->next;
//        }
//        return ans;
//    };
//
//    auto downFind = [&](MemPage *curLoc)->MemPage*{
//        auto ans =
//    };
//    for(int i = 0 ; i <m ; i++){
//        int cur;
//        input >>cur;
//        if(searchMem(cur)){
//            cnt[cur]++;
//            auto curPage = pages[cur];
//            curPage->useCnt++;
//            auto insertPos = findInsert(curPage);
//            if(curPage->last)
//                curPage->last->next = curPage->next;
//            if(curPage->next)
//                curPage->next->last = curPage->last;
//
//            curPage->last = insertPos;
//
//            if(insertPos){
//                curPage->next = insertPos;
//            }
//            else{
//                if(head != curPage)
//                    head->next = curPage;
//            }
//        }
//        else{
//            auto *curPage = new MemPage(cur,1,i);
//            cnt[cur] = 0;
//            if(head){
////                下潜
//                curPage->last = head;
//                head->next = curPage;
//            }
//            else{
//                lastUse = head = curPage;
//            }
//            if(cnt.size() > n){
//                auto deletedMem = lastUse;
//                cnt.erase(deletedMem->id);
//                pages.erase(deletedMem->id);
//                lastUse = lastUse->last;
//                delete deletedMem;
//            }
//            pages[cur] = curPage;
//        }
//    }
//    return 0;
//}

#include<algorithm>
using namespace std;
const int maxn=1e6+5;
struct MemPage {
    int timestamp,useCnt;
    MemPage(int t ,int u):timestamp(t),useCnt(u){}
    bool operator<(const MemPage &a)const {
        if(useCnt == a.useCnt)return timestamp > a.timestamp;
        return useCnt > a.useCnt;
    }
};
priority_queue<MemPage> priorityQueue;
int pageRank[maxn],uniquePages[maxn];
int num[maxn];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> pageRank[i];
        uniquePages[i]=pageRank[i];
    }
    sort(uniquePages + 1, uniquePages + m + 1);
    int k = unique(uniquePages + 1, uniquePages + m + 1) - uniquePages - 1;
    int tot=0,ans=0;
    for(int i=1; i<=m; i++) {
        pageRank[i]= lower_bound(uniquePages + 1, uniquePages + k + 1, pageRank[i]) - uniquePages;
        if(num[pageRank[i]]) {
            num[pageRank[i]]++;
            ans++;
        }
        else if(tot<n){
            tot++;
            num[pageRank[i]]=1;
        }
        else {
            MemPage res=priorityQueue.top();
            priorityQueue.pop();
            while(num[pageRank[res.timestamp]] != res.useCnt) {
                res = priorityQueue.top();
                priorityQueue.pop();
            }
            num[pageRank[i]]++, num[pageRank[res.timestamp]]=0;
        }
        priorityQueue.emplace(i, num[pageRank[i]]);
    }
    cout <<ans;
    return 0;
}