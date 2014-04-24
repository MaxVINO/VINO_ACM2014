#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 400;
struct Edge{
    int b,c,nxt;
}e[N*N];
int p[N],cnt;
void addedge(int a,int b,int c){
    e[cnt].b = b;e[cnt].c = c;e[cnt].nxt = p[a];p[a] = cnt++;
    e[cnt].b = a;e[cnt].c = 0;e[cnt].nxt = p[b];p[b] = cnt++;
}
void init(){
    memset(p,-1,sizeof(p));
    cnt = 0;
}
int pre[N],path[N];
bool vis[N];
bool spfa(int s,int t,int n){
    int i,u;
    queue<int>q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        u = q.front(); q.pop();
        for(i = p[u]; i != -1; i = e[i].nxt){
            int v = e[i].b;
            if(e[i].c > 0 && !vis[v]){
                pre[v] = u, path[v] = i;
                vis[v] = 1;q.push(v);
                if(v == t) return 1;
            }
        }
    }
    return 0;
}
int ek(int s,int t,int n){
    int i,aug,maxflow = 0;
    while(spfa(s,t,n)){
        aug = inf;
        for(i = t; i != s; i = pre[i]) aug = min(aug,e[path[i]].c);
        for(i = t; i != s; i = pre[i])
            e[path[i]].c -= aug,e[path[i] ^ 1].c += aug;

        maxflow+=aug;
    }
    return maxflow;
}
int main(){
    int n,m,T,cas = 1;
    scanf("%d",&T);
    while(T-- && scanf("%d %d",&n,&m)){
        int s,e,c;
        init();
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&s,&e,&c);
            addedge(s,e,c);
        }
        printf("Case %d: %d\n",cas++,ek(1,n,n));
    }
    return 0;
}
