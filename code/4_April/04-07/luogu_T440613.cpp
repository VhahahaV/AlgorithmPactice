//
// Created by CZQ on 2024/4/7.
//

//约瑟夫环问题，链表解决，手搓

#include "bits/stdc++.h"

using namespace std;

struct MemPage{
    int val;
    MemPage* next;
public:
    MemPage(int a): val(a){
        next = nullptr;
    }
};

class listpoint{
private:
    MemPage *head;
    int size;

public:
    listpoint() = default;
    listpoint(int num):size(num){
        head = new MemPage(1);
        MemPage *current = head;
        for (int i = 2; i <= num; ++i) {
            current->next = new MemPage(i);
            current = current->next;
        }
        current->next = nullptr;
    }

    bool goAhead(MemPage *&cur , int step, MemPage *&prev){
        while (step--){
            if (cur->next){
                prev = cur;
                cur = cur->next;
            }
            else
                return false;
        }
        return true;
    }

    bool remove(int step){
        MemPage *current = head;
        MemPage *prev = nullptr;

//        if (!current->next)
//            return false;
        {
            while (true){
                if (current->val == size)
                    return true;
                if (!prev)
                    head = head->next;
                else
                    prev->next = current->next;
                MemPage *del = current;
                if (!goAhead(current,step+1,prev)){
                    delete(del);
                    break;
                }
                delete(del);
            }
        }
        return false;
    }


    void printAll(){
        MemPage *current = head;
        while (current){
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

};

array<vector<int> , 11> track;
int getDays(int nums , int step){
    int mem = track[step][nums];
    if (mem != -1)
        return mem;
    if ((nums-1)% step == 0)
        return 1;
    return track[step][nums] = getDays(nums - (nums+step-1)/step , step) + 1;
}
int main(){

    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> steps(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        cin >> steps[i];
    }
    vector<int> res(N);
//    使用记忆化搜索 加 递归
    for (int i = 0; i < N; ++i) {
        int step = steps[i] + 1;
        track[step].resize(std::max<size_t>(track[step].size(), nums[i]+2),-1);
        cout << getDays(nums[i],step) <<'\n';
    }

//    构建链表
//    for (int i = 0; i < N; ++i) {
//        int day = 0;
//        listpoint l1(nums[i]);
//        while (++day && !l1.remove(steps[i])){
////        l1.printAll();
//        }
//        cout << day << endl;
//
//    }
//    结果： A了60%，其他TLE……

    return 0;
}