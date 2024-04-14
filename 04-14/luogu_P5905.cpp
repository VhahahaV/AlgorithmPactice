//
// Created by CZQ on 2024/4/14.
//
#include "bits/stdc++.h"

using namespace std;
//最短路径问题---SPFA算法详解https://blog.csdn.net/qq_35644234/article/details/61614581
//最短路径问题---Floyd算法详解https://blog.csdn.net/qq_35644234/article/details/60875818
//图论详解——Bellman-Ford（清晰易懂）https://blog.csdn.net/lsy201009/article/details/129149905
//最短路径问题---SPFA算法详解https://blog.csdn.net/qq_35644234/article/details/61614581

//先抄了个模板在这，明天再看
using namespace std;
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

int N,M;
struct edge{
    int v;//顶点和边的权值
    ll w;
};
edge make_edge(int _v,int _w){
    edge cur;cur.v = _v;cur.w = _w;
    return cur;
}
struct node {
    ll dis;
    int v;
    friend bool operator < (node A,node B){
        return A.dis>B.dis;//重载小于号，默认为大顶堆
    }
};
node make_node(ll _dis,int _v){
    node cur;cur.dis = _dis;cur.v = _v;
    return cur;
}
vector<edge> g[100005];
ll dis[3005][3005]; //dis[i][j]表示第i个点到第j个点的最短距离
ll d[3005]; //存放虚拟点到各个点的最短距离
int vis[100005];
priority_queue<node>q; //优先队列来存放顶点和改顶点距源点的距离

bool Dellman_Ford(int s){
    int i,j,k;
    for(i = 1;i<=N;i++){
        int flag = 0;
        for(j = 1;j<=N;j++){
            for(k = 0;k<g[j].size();k++){
                if(d[g[j][k].v]>d[j]+g[j][k].w){
                    flag = 1;
                    d[g[j][k].v] = d[j]+g[j][k].w;
                }
            }
        }
        if(flag == 0)
            return true;
    }
    //进行负环的验证
    for(j = 1;j<=N;j++){
        for(k = 0;k<g[j].size();k++){
            if(d[g[j][k].v]>d[j]+g[j][k].w){
                return false;
            }
        }
    }
    return true;
}
void dijkstra(int s){
    int now;//用于存放从队列中取出当前距离最小的点
    memset(vis,0,sizeof(vis));
    dis[s][s] = 0;
    q.push(make_node(dis[s][s],s));
    while(!q.empty()){
        now = q.top().v;q.pop(); //取出队列中距离最小的点
        if(vis[now] == 1)continue;//如果该点访问过则continue
        vis[now] = 1;
        for(int  i = 0;i<g[now].size();i++){
            int v = g[now][i].v; //与now相邻的点
            int w = g[now][i].w; //边权
            if(dis[s][v]>dis[s][now]+w){
                dis[s][v] = dis[s][now]+w;
                q.push(make_node(dis[s][v],v));
            }
        }
    }
}

int main(){
    int i,j,k;
    int a,b;
    ll c;
    cin>>N>>M;
    for(i = 1;i<=N;i++){
        for(j = 1;j<=N;j++){
            dis[i][j] = inf;
        }
    }
    for(i = 1;i<=N;i++){
        dis[i][i] = 0;
    }
    for(i = 1;i<=M;i++){
        scanf("%d %d %lld",&a,&b,&c);
        g[a].push_back(make_edge(b,c));
    }
    if(!Dellman_Ford(0)){
        printf("-1\n");
        return 0;
    }

    //更新权值
    for(i = 1;i<=N;i++){
        for(j = 0;j<g[i].size();j++){
            g[i][j].w = g[i][j].w + d[i]-d[g[i][j].v];
        }
    }
    for(i = 1;i<=N;i++){
        dijkstra(i);
    }

    //更新最小距离
    for(i =1;i<=N;i++){
        for(j = 1;j<=N;j++){
            if(dis[i][j] == inf)//将第i行要输出的数存在dis[i][0]中
                dis[i][0] +=j*dis[i][j];
            else{
                dis[i][j] = dis[i][j]+d[j]-d[i];
                dis[i][0]+=j*dis[i][j];
            }
        }
    }

    for(i = 1;i<=N;i++){
        printf("%lld\n",dis[i][0]);
    }
    return 0;
}