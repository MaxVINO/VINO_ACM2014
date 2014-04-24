#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1010][1010];
int mp[1010][1010];
int main(){
    int T;
    //freopen("1.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        int Q;
        scanf("%d",&Q);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) mp[i][j] = 0,dp[i][j] = 0x3f3f3f3f;
        for(int i = 1; i <= Q; i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            for(int j = 1; j <= b; j++){
                mp[a][j] = 1;
            }
            for(int j = 0; j < c; j++){
                mp[a][n-j] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            if(mp[1][i] != 1) dp[1][i] = 0;
        }
        for(int i = 2; i <= m; i++){
            for(int j = 1; j <= n; j++)
                if(!mp[i][j]){
                    int x = i - 1,y = j + 1;
                    if(y <= n){
                        dp[i][j] = min(dp[i][j],dp[x][y]);
                    }
                    y = j - 1;
                    if(y >= 1)
                        dp[i][j] = min(dp[i][j] ,dp[x][y] + 1);
                }
//            for(int j = 1; j <= n; j++){
//                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++)
            ans = min(dp[m][i],ans);
        if(ans == 0x3f3f3f3f) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}
