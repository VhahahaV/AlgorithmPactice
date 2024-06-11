//
// Created by CZQ on 2024/6/11.
//
#include <iostream>
#include <array>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
struct node{
    double weight;
    ll nums = 0;
    node *left,*right;
    explicit node(double w , ll n,node *l = nullptr, node *r = nullptr):weight(w),nums(n),left(l),right(r){}
    bool operator< (const node &b) const{
        return weight > b.weight;
    }
};
class HuffmanCode{

    node *root = nullptr;
    double sumWeight = 0.f;

public:
    explicit HuffmanCode(std::priority_queue<node> &nodes){
        // 将所有可能情况加入优先队列
        while(true){
            auto now=nodes.top(); nodes.pop();
            if(nodes.empty()&&now.nums==1) break;
            if(now.nums > 1){
                nodes.push(node(
                        now.weight*2.f,
                        now.nums/2
                        ));
                if(now.nums & 1)
                    nodes.push(node(
                            now.weight,
                            1
                            ));
                sumWeight += now.weight *(now.nums ^ (now.nums&1));
            }
            else{
                auto next = nodes.top(); nodes.pop();
                if(next.nums > 1)
                    nodes.push(node(
                            next.weight,
                            next.nums-1
                        ));
                nodes.push(node(
                        next.weight+ now.weight,
                        1
                        ));
                sumWeight += (now.weight + next.weight);
            }

        }
    }
    void showWeight() const{
        std::cout << std::fixed << std::setprecision(6) << sumWeight;
    }
};

int main(){
//   需要对4^n个节点构造huffman
    int n;
    std::array<double,4> P{};
    cin >> n;
    std::string tmp;
    array<std::vector<double>,4> poss;
    for(int i = 0 ; i < 4 ; i++){
        cin >> tmp;
        P[i] = std::stod(tmp);
        auto &p = poss[i];
        p.resize(n+1,1.f);
        for(int j = 1;j <= n;j++)
            p[j] = p[j-1] *  P[i];
    }

//    组合数
    std::vector<std::vector<double>> pbNum(n + 1, std::vector<double>(n + 1));
    for(int i = 0 ; i <= n ; i++){
        pbNum[i][0]=1;
        for(int j = 1; j <=i ; j++){
            pbNum[i][j] = pbNum[i - 1][j] + pbNum[i - 1][j - 1];
        }
    }


    std::priority_queue<node> nodes{};
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= n ; j++)
            for(int k = 0 ; k <= n ; k++)
                for(int l = 0 ; l <= n ; l++)
                    if(i+j+k+l == n){
                        nodes.push( node(
                                1.f*poss[0][i] * poss[1][j] * poss[2][k] * poss[3][l],
                                pbNum[n][i] * pbNum[n - i][j] * pbNum[n-i-j][k]
                                ));
                    }



//
    HuffmanCode huffmanCode(nodes);
    huffmanCode.showWeight();
    return 0;
}