#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1400;
struct Edge{
    int b,c,nxt;
}e[N*N];
int p[N],cnt;
void addedge(int a,int b,int c){
    //cout<<a<<" "<<b<<" "<<c<<endl;
    e[cnt].b = b;e[cnt].c = c;e[cnt].nxt = p[a];p[a] = cnt++;
    e[cnt].b = a;e[cnt].c = 0;e[cnt].nxt = p[b];p[b] = cnt++;
}
void init(){
    memset(p,-1,sizeof(p));
    cnt = 0;
}
int pre[N],dis[N],gap[N],cur[N];
int sap(int s,int t,int n){
    int i,v,u,c;
    int aug = -1,maxflow = 0;
    for(i = 0; i <= n; i++) cur[i] = p[i];
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    u = pre[s] = s;
    gap[0] = n;
    while(dis[s] < n){
    loop:
        for(int &ee = cur[u]; ee != -1; ee = e[ee].nxt){
            v = e[ee].b;c = e[ee].c;
            if(c > 0 && dis[u] == dis[v] + 1){
                if(aug == -1 || aug > c) aug = c;
                pre[v] = u;
                u = v;
                if(v == t){
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u,u = pre[u]){
                        e[cur[u]].c -= aug;
                        e[cur[u]^1].c += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        }
        int mindis = n;
        for(i = p[u]; i != -1; i = e[i].nxt){
            v = e[i].b;
            if(e[i].c > 0 && mindis > dis[v]){
                cur[u] = i,mindis = dis[v];
            }
        }
        if((--gap[dis[u]] == 0)) break;
        gap[dis[u] = mindis + 1] ++;
        u = pre[u];
    }
    return maxflow;
}
int main(){
    int n,m,T,cas = 1;
    scanf("%d",&T);
    while(T-- && scanf("%d %d",&n,&m)){
        int pi,si,ei;
        init();
        int sum = 0;
        int s = 0, t = 500 + n + 1;
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d",&pi,&si,&ei);
            for(int j = si; j <= ei; j++){
                addedge(j,500 + i,1);
            }
            addedge(500 + i,t,pi);
            sum += pi;
        }
        for(int i = 1; i <= 500; i++){
            addedge(s,i,m);
        }
        int ans = sap(s,t,t+1);
        if(ans == sum)
            printf("Case %d: Yes\n",cas++);
        else
            printf("Case %d: No\n",cas++);
        puts("");
    }
    return 0;
}

