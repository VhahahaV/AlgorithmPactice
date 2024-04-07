//
// Created by CZQ on 2024/4/7.
//

//约瑟夫环问题，链表解决，手搓

#include "bits/stdc++.h"

using namespace std;

struct node{
    int val;
    node* next;
public:
    node(int a):val(a){
        next = nullptr;
    }
};

class listpoint{
private:
    node *head;
    int size;

public:
    listpoint() = default;
    listpoint(int num):size(num){
        head = new node(1);
        node *current = head;
        for (int i = 2; i <= num; ++i) {
            current->next = new node(i);
            current = current->next;
        }
        current->next = nullptr;
    }

    bool goAhead(node *&cur , int step,node *&prev){
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
        node *current = head;
        node *prev = nullptr;

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
                node *del = current;
                if (!goAhead(current,step+1,prev)){
                    free(del);
                    break;
                }
                free(del);
            }
        }
        return false;
    }


    void printAll(){
        node *current = head;
        while (current){
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

};
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
    for (int i = 0; i < N; ++i) {
        int day = 0;
        listpoint l1(nums[i]);
        while (++day && !l1.remove(steps[i])){
//        l1.printAll();
        }
        cout << day << endl;

    }
//    结果： A了60%，其他TLE……

    return 0;
}