#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[60][60];//j位开头，长度为i的个数
char str[60];
long long sum[60];
int num[60];
long long k;
long long ans;
int chg(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch - 'A';
    }else return ch - 'a' + 26;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s %I64d",str,&k);
        int l = strlen(str);
        for(int i = 1; i <= l; i++){
            num[i] = chg(str[i-1]);
        }
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= l; i++) {
            dp[1][i] = 1;
        }
        ans = 0;
        bool vis[60];
        memset(vis,0,sizeof(vis));
        for(int j = 1; j <= l; j++){
                int t = num[j];
                if(vis[t]) continue;
                else sum[1] += dp[1][j],vis[t] = true;

        }
        ans += sum[1];
        for(int i = 2; i <= l; i++){
            for(int j = 1; j <= l; j++){
                memset(vis,0,sizeof(vis));
                for(int k = j + 1; k <= l; k++){
                    int t = num[k];
                    if(vis[t]) continue;
                    else dp[i][j] += dp[i-1][k],vis[t] = true;
                }
            }
            memset(vis,0,sizeof(vis));
            for(int j = 1; j <= l; j++){
                int t = num[j];
                if(vis[t]) continue;
                else sum[i] += dp[i][j],vis[t] = true;
            }
            ans += sum[i];
           // cout<<i<<" "<<sum[i]<<endl;
            if(ans > k) break;
        }
        //for(int i = 1; i <= l; i++)
            //cout<<i<<" "<<sum[i]<<endl;
        k %= ans;
        k++;
        int len;
        //cout<<ans<<" "<<k<<endl;
        for(len = 1; len <= l; len++){
            if(k <= sum[len]) break;
            k -= sum[len];
        }
       // cout<<len<<endl;
        string Ans = "";
        int st = 1;
        while(true){
            int Min = 100,id;
            bool flag = false;
            for(int i = 0; i < 52 && !flag; i++){
                for(int j = st; j <= l; j++){
                    int t = num[j];
                    if(t == i){
                        if(dp[len][j] >= k){
                            flag = true;
                            if(i < 26){
                                Ans += (i) + 'A';
                            }else Ans += i - 26 + 'a';
                           // cout<<i<<endl;
                            st = j + 1;
                            len--;
                            break;
                        }else {
                            k-=dp[len][j];
                            break;
                        }
                    }
                }
            }
            if(k == 0 || len == 0) break;
        }
        cout<<Ans<<endl;



    }
    return 0;
}
