#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000;
int sum[maxn + 10];
int cnt[maxn + 10];
char str[maxn + 10];
int main(){
    int T,k;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%s %d",str,&k);
        int len = strlen(str);
        sum[0] = 0;
        cnt[0] = str[0] == '0';
        for(int i = 0; i < len; i++){
            if(str[i] == '1') {
                sum[i] = sum[i-1] + i;
                cnt[i] = cnt[i-1] + 1;
            }
            else {
                sum[i] = sum[i-1];
                cnt[i] = cnt[i-1];
            }
        }
        int ans = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == '1'){
                int left = i,right;
                for(;str[i] == '1' && i < len; i++);
                i--;
                right = i;
                ans = max(ans,right - left + 1);
                int l = 1, r = len,mid,s;
                while(l <= r){
                    mid = l + r >> 1;
                    int ll = left - mid;
                    int rr = right + mid;
                    long long  cost = 0;
                    s = right - left + 1;
                    rr = min(len - 1,rr);
                    cost += (sum[rr] - sum[right]) - right * (cnt[rr] - cnt[right]) - (cnt[rr] - cnt[right]) * (cnt[rr] - cnt[right] + 1) / 2;
//                   // cout<<rr<<" "<<sum[rr]<<" "<<right<<" "<<sum[right]<<" "<<cnt[rr]<<" "<<cnt[right]<<" "<<cost<<endl;
                    s += cnt[rr] - cnt[right];
                    if(left != 0){
                       ll = max(ll,0);
                       int cn = 0;
                       if(ll != 0) cn = cnt[left - 1] - cnt[ll - 1];
                       else cn = cnt[left-1];
                       cost += cn * left -  (sum[left - 1] - (ll == 0 ? 0 : sum[ll-1])) - cn * (cn + 1) / 2;
                       s += cn;
//                     //  cout<<ll<<" "<<left<<" "<<cn<<" "<<cost<<endl;
                    }
//                    //cout<<ans<<" "<<s<<endl;
//                    //cout<<left<<" "<<right<<" "<<mid<<" "<<cost<<endl;
                    if(cost <= k){
                        if(right + mid + 1 < len && str[right + mid + 1] == '1'){
                        if(cost + mid  - (cnt[rr] - cnt[right]) <= k){
                            ans = max(ans,s + 1);
                        }
                    }
                    if(left - mid - 1 >= 0 && str[left - mid - 1] == '1'){
                        if(cost + mid  - (cnt[left-1] - cnt[left-mid-1]) <= k){
                            ans = max(ans,s + 1);
                        }
                    }
                        ans = max(ans,s);
                        l = mid + 1;
                    }else r = mid - 1;
          //          cout<<mid<<" "<<cost<<" "<<left<<" "<<right<<" "<<ans<<endl;

                }

            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
