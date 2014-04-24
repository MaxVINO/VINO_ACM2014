#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Node{
    int s,id;
};
const int maxn = 200000;
vector<int>G[maxn];
vector<Node>d[maxn];
int c[maxn];
int l[maxn],r[maxn];
int dep[maxn],Maxdep;
int dfs_clock;
int dfs(int rt,int depth){
    int &s = c[rt] = 1;
    dep[rt] = depth;
    Maxdep = max(Maxdep,depth);
    l[rt] = ++dfs_clock;
    for(int i = 0; i < G[rt].size(); i++){
        int v = G[rt][i];
        s += dfs(v,depth+1);
    }
    Node tmp;
    tmp.s = c[rt];
    tmp.id = l[rt];
    d[depth].push_back(tmp);
    r[rt] = dfs_clock;
    return s;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        dfs_clock = 0;
        int N;
        scanf("%d",&N);
        for(int i = 1; i <= N; i++) G[i].clear(),d[i].clear(),c[i] = 0;
        for(int i = 2; i <= N; i++){
            int x;
            scanf("%d",&x);
            G[x].push_back(i);
        }
        Maxdep = 1;
        dfs(1,1);
        for(int i = 1; i <= Maxdep; i++){
            for(int j = 1; j < d[i].size(); j++){
                d[i][j].s += d[i][j-1].s;
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int u,L;
            scanf("%d %d",&u,&L);
            int v = dep[u] + L - 1;
            if(v >= Maxdep){
                printf("%d\n",c[u]);
                continue;
            }else{
                v++;
                int left = 0,right = d[v].size() - 1,mid;
                while(left <= right){
                    int mid = left + right >> 1;
                    if(d[v][mid].id >= l[u]) right = mid - 1;
                    else left = mid + 1;
                }
                int ls = right + 1;
                if(ls == 0) ls = 0;
                else ls = d[v][ls - 1].s;

                left = 0,right = d[v].size() - 1;
                while(left <= right){
                    int mid = left + right >> 1;
                    if(d[v][mid].id <= r[u]) left = mid + 1;
                    else right = mid - 1;
                }
                int rs = left - 1;
                rs = d[v][rs].s;
                printf("%d\n",c[u] - (rs - ls));
            }
        }
    }
    return 0;
}
/*
10

*/
