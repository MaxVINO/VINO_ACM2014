//hdu 4644
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 2100000;
int next[maxn];
void getnextval(char p[]){
    int j = 0, k = -1, len = strlen(p);
    next[0] = -1;
    while(j < len){
        if(k == -1 || p[k] == p[j]){
            j++,k++;
            if(p[k] == p[j]){
                next[j] = k;
                continue;
            }
            next[j] = k;
        }else k = next[k];
    }
}
bool kmp(char p[],char t[]){
    int j = 0, k = 0,lent = strlen(t),lenp = strlen(p);
    int cnt = 0;
    while(j < lent){
        if(t[j] == p[k] || k == -1){
            k++,j++;
            if(k == lenp) return true;
        }else k = next[k];
    }
    return cnt;
}
char str[maxn],t[maxn];
pair<int,int>p[maxn];
int ch[maxn];
int main(){
    while(~scanf("%s",str)){
        int n = strlen(str);
        for(int i = 0; i < n; i++){
            p[i].first = str[i];
            p[i].second = i;
        }
        stable_sort(p,p+n);
        for(int i = 0; i < n; i++) ch[i] = p[i].second;
        int now = ch[0];
        n--;
        for(int i = 0; i < n; i++){
            t[i] = p[now].first;
            now = ch[now];
        }
        t[n] = '\0';
        //cout<<t<<endl;
        int m;
        cin>>m;
        for(int i = 0; i < m; i++){
            scanf("%s",str);
            int len = strlen(str);
            getnextval(str);
            if(kmp(str,t)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
