#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int mod = 1000000007;
const int magic = 12347;
const int maxn = 100010;
int N;
int dfs_clock;
vector<int>G[maxn];
int l[maxn],r[maxn];
int dep[maxn];
struct OP{
    int l,r,add;
};
vector<OP>p[maxn];
typedef long long ll;
ll ans[maxn+10];
ll a[maxn+10];
struct Bit{
    int lowbit(int x){
        return x & -x;
    }
    void add(int pos,int v){
        for(int i = pos; i <= maxn; i += lowbit(i)){
            a[i] += v;
        }
    }
    ll getsum(ll pos){
        ll sum = 0;
        for(int i = pos; i >= 1; i -= lowbit(i)){
            sum += a[i];
        }
        return sum;
    }
}bit;

void dfs(int rt,int d){
    for (int i = 0;i < p[rt].size();i++){
        OP tmp = p[rt][i];
        bit.add(tmp.l,tmp.add);
        bit.add(tmp.r + 1,-tmp.add);
    }
    ans[rt]=bit.getsum(d);
    for(int i = 0; i < G[rt].size(); i++){
        int v = G[rt][i];
        dfs(v,d+1);
    }
     for (int i = 0;i < p[rt].size();i++){
        OP tmp = p[rt][i];
        bit.add(tmp.l,-tmp.add);
        bit.add(tmp.r + 1,tmp.add);
    }
}
int main(){
    int T;
    cin>>T;
    for(int cas = 1; cas <= T; cas++){
        cin>>N;
        for(int i = 1; i <= N; i++) G[i].clear(),p[i].clear(),a[i] = 0;
        for(int i = 2; i <= N; i++){
            int x;
            scanf("%d",&x);
            G[x].push_back(i);
        }
        int Q;
        cin>>Q;
        while(Q--){
            int u,l,r,d;
            scanf("%d %d %d %d",&u,&l,&r,&d);
            OP tmp;
            tmp.l = l,tmp.r = r,tmp.add = d;
            p[u].push_back(tmp);
        }
        dfs(1,1);
        ll sum = 0;
        for (int i = 1;i <= N; i++)
            sum = (sum * magic + ans[i]) % mod;
        printf("Case %d: %lld\n",cas,sum);
    }
}
