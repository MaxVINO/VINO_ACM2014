#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 100000;
ll exp_mod(ll a,ll b,ll m){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % m;;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}
ll s[1010];
int main(){
    int n;

        for(int x = 1; x <= 1010; x++){
            ll sum = 0;
            for(int a = 1; a <= 9; a++)
                for(int t = 1; t <= a; t++){
                    ll g = 10 * t - 1;
                    ll ret = exp_mod(10,x,g);
                    ret = ret * a % g;
                    ret = (ret - t*a) % g;
                    if(ret == 0){
                        //cout<<x<<" "<<a<<" "<<t<<endl;
                        ll res = exp_mod(10,x,g * 1000000);
                        res = res * a % (g * 1000000);
                        res = (res - t * a) % (g * 1000000);
                        //cout<<res<<" "<<g<<endl;
                        res /= g;
                        res = (res * 10 + a) % 1000000;
                        sum = sum + res;
                        sum %= mod;
                    }
                }
                s[x] = (s[x-1] + sum) % mod;
        }

    while(cin>>n){
        cout<<s[n-1]<<endl;
    }
    return 0;
}
