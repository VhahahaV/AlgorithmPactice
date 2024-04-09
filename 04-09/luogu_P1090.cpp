//
// Created by CZQ on 2024/4/9.
//
#include<bits/stdc++.h>

using namespace std;

////使用优先队列,主要通过堆来实现

////自己实现一个最小堆
class smallestHeap{
private:
    vector<int> heap;
    int len=0;
public:
    smallestHeap(int size){
        heap.resize(size+1,0);
        len = 0;
    }

    void push(const int &a){
        heap[++len] = a;
        int son = len, father = son/2;
        while(heap.at(son)<heap.at(father) && father>=1){
            swap(heap.at(son),heap.at(father));
            son=father,father=son/2;
        }
    }

    void pop(){
        if (!len)
            return;
        swap(heap[1],heap[len]);
        len--;
        int father = 1 ,son = 2;
        while (son <= len){
//            子节点中更小的与父节点呼唤
            if (son < len && heap.at(son) > heap.at(son+1))
                son++;
            if (heap.at(father) > heap.at(son)){
                swap(heap.at(father),heap.at(son));
                father = son;
                son = father*2;
            }
            else
                break;
        }
    }

    int top(){
        return heap[1];
    }

    int size(){
        return len;
    }
};


int main(){
    int n;

//    使用自建最小堆smallestHeap测试通过
    cin >> n;
    smallestHeap priorityQueue(n);

//    使用现有容器priority_queue测试通过
//    priority_queue<int ,vector<int> , greater<int>> priorityQueue;

    while (n--){
        int a;
        cin >> a;
        priorityQueue.push(a);
    }
    int sum = 0;
    while (priorityQueue.size() != 1){
        int a = priorityQueue.top();
        priorityQueue.pop();
        int b = priorityQueue.top();
        priorityQueue.pop();
        sum += (a+b);
        priorityQueue.push(a+b);
    }
    cout << sum;

    return 0;
}