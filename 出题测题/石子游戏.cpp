#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
vector<int>p[3];
int hash[3][100010];
int dp[130][130][130];
int a[3];
int dfs(int s1,int s2,int s3){
   if(dp[s1][s2][s3] != -1) return dp[s1][s2][s3];
   int t1 = p[0][s1],t2 = p[1][s2],t3 = p[2][s3];
    int g;
    if((g = __gcd(t1,t2)) != 1){
        int n1,n2;
        for(int i = 1; i < p[0].size() && p[0][i] <= g; i++){
            if(g % p[0][i] == 0){
                n1 = t1 / p[0][i];
                n2 = t2 / p[0][i];
                if(!dfs(hash[0][n1],hash[1][n2],s3)) return dp[s1][s2][s3] = 1;
            }
        }
    }
    if((g = __gcd(t1,t3)) != 1){
        int n1,n3;
        for(int i = 1; i < p[0].size() && p[0][i] <= g; i++){
            if(g % p[0][i] == 0){
                n1 = t1 / p[0][i];
                n3 = t3 / p[0][i];
                if(!dfs(hash[0][n1],s2,hash[2][n3])) return dp[s1][s2][s3] = 1;
            }
        }
    }
    if((g = __gcd(t2,t3)) != 1){
        int n2,n3;
        for(int i = 1; i < p[1].size() && p[1][i] <= g; i++){
            if(g % p[1][i] == 0){
                n2 = t2 / p[1][i];
                n3 = t3 / p[1][i];
                if(!dfs(s1,hash[1][n2],hash[2][n3])) return dp[s1][s2][s3] = 1;
            }
        }
    }
//    if(__gcd(p[0][s1],p[1][s2]) != 1 && __gcd(p[1][s2],p[2][s3]) != 1 && __gcd(p[0][s1],p[2][s3]) != 1){
//        int t = __gcd(p[0][s1],p[1][s2]);
//        t = __gcd(p[2][s3],t);
//        int a = p[0][s1]/t;
//        int b = p[1][s2]/t;
//        int c = p[2][s3]/t;
//        if(t != 1 && __gcd(a,b) != 1 && __gcd(a,c)  != 1 && __gcd(b,c)!=1)
//            cout<<p[0][s1]<<" "<<p[1][s2]<<" "<<p[2][s3]<<endl;
//    }
    return dp[s1][s2][s3] = 0;

}
int main(){
    while(cin>>a[0]>>a[1]>>a[2]){
        for(int i = 0; i < 3; i++){
            p[i].clear();
            memset(hash[i],0,sizeof(hash[i]));
            for(int j = 1; j * j <= a[i]; j++){
                if(a[i] % j == 0){
                    p[i].push_back(j);
                    if(j != a[i] / j) p[i].push_back(a[i]/j);
                }
            }
            sort(p[i].begin(),p[i].end());
            for(int j = 0; j < p[i].size(); j++){
                int num = p[i][j];
                hash[i][num] = j;
            }
        }
        memset(dp,-1,sizeof(dp));
        if(dfs(p[0].size() - 1,p[1].size() - 1,p[2].size() - 1)){
            puts("YES");
        }else puts("NO");

    }
    return 0;
}
