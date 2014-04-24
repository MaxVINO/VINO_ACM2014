#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[110][2];
int num1[110];
int num2[110];
int main(){
    ll x,y,x1,x2,y1,y2;
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        scanf("%I64d %I64d %I64d %I64d",&x1,&y1,&x2,&y2);
       // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        x = x1 - x2;
        y = y1 ^ y2;
        ll ans = 0;
        if(x & 1 && y == 0)  ans--;
        for(int j = 1; j <= 100; j++) {
            num1[j] = x & 1;
            x >>= 1;
            num2[j] = y & 1;
            y >>= 1;
        }
        dp[0][0] = 1;
        for(int i = 1; i <= 100; i++){
            int a = num1[i],b = num2[i];
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++){
                    if((j ^ k == b) && ((j + k + 1) & 1) == a){ //接受进位
                        if(j + k + 1 >= 2){
                            dp[i][1] += dp[i-1][1];
                        }else dp[i][0] += dp[i-1][1];
                    }
                     if((j ^ k == b) && ((j + k) & 1) == a){ //接受进位
                        if(j + k >= 2){
                            dp[i][1] += dp[i-1][0];
                        }else dp[i][0] += dp[i-1][0];
                    }
                }

        }
        ans += dp[100][0];
        printf("%I64d\n",ans);
    }
    return 0;
}
