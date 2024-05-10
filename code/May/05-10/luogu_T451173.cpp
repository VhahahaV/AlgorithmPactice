//
// Created by VhahahaV on 2024/5/10.
//
#include "iostream"
#include "vector"
constexpr int MOD = 100000007;
//45min
using namespace std;
//关键词:两两配对,N和2N 5时为42

using ull = unsigned long long;
ull Catalan(ull n)
{
    if(n<=1) return 1;
    vector<ull>  h(n+1);//保存临时结果
    h[0] = h[1] = 1;        //h(0)和h(1)
    for(int i=2;i<=n;++i)    //依次计算h(2),h(3)...h(n)
    {
        for(int j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)
            h[i] = (h[i]+((h[j] * h[i-1-j]))%MOD)%MOD;
    }
    ull result = h[n]; //保存结果
    return result;
}

int main(){
    int n;
    cin >>n;
    cout << Catalan(n);
    return 0;
}

//Catalan其他题目：
/**
 1. 出栈次序
一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列?
2. 01序列
给出一个n，要求一个长度为2n的01序列，使得序列的任意前缀中1的个数不少于0的个数， 有多少个不同的01序列?
以下为长度为6的序列:
111000 101100 101010 110010 110100
     a.因为对于每一个数来说，必须进栈一次、出栈一次。我们把进栈设为状态‘1’，出栈设为状态‘0’。n个数的所有状态对应n个1和n个0组成的2n位二进制数。
     b. 由于等待入栈的操作数按照1‥n的顺序排列、入栈的操作数b大于等于出栈的操作数a(a≤b)，因此输出序列的总数目=由左而右扫描由n个1和n个0组成的2n位二进制数，1的累计数不小于0的累计数的方案种数。
3. 找零问题
2n个人要买票价为五元的电影票，每人只买一张，但是售票员没有钱找零。其中，n个人持有五元，另外n个人持有十元，问在不发生找零困难的情况下，有多少种排队方法？
4. 找零问题
P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案？
5. 二叉树计数
有n个节点构成的二叉树（非叶子节点都有2个儿子），共有多少种情形？
有n+1个叶子的二叉树的个数？
*
*/
