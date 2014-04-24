#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int next[maxn];
void getnext(char *p){
    int l = strlen(p);
    next[0] = -1;
    int i = 0, j = -1;
    while(i < l){
        if(j == -1 || p[i] == p[j]){
            i++,j++;
            next[i] = j;
        }else j = next[j];
    }

}
int kmp(char t[],char p[]){
    int lp = strlen(p),lt = strlen(t);
    int i = 0, j = 0,cnt = 0;
    while(i < lt){
        if(j == -1 || t[i] == p[j]){
            i++,j++;
            if(j == lp){
                cnt++;
                j = 0;
            }
        }else j = next[j];
    }
    return cnt;
}

//void getnext(char p[]){
//    int l = strlen(p);
//    next[0] = -1;
//    int i = 0,j = -1;
//    while(i < l){
//        if(j == -1 || p[i] == p[j]){
//            j++, i++;
//            if(p[i] == p[j]){
//                next[i] = next[j];
//                continue;
//            }
//            next[i] = j;
//        }else j = next[j];
//    }
//}
//int kmp(char t[],char p[]){
//    int lt = strlen(t);
//    int lp = strlen(p);
//    int i = 0, j = 0;
//    int cnt = 0;
//    while(i < lt){
//        if(t[i] == p[j] || j == -1){
//            i++,j++;
//            if(j == lp) {
//                cnt++;
//                j = 0;
//            }
//        }else j = next[j];
//    }
//    return cnt;
//}
int main(){
    char s1[1010],s2[1010];
    while(scanf("%s",s1)!=EOF){
        if(s1[0] == '#') break;
        scanf("%s",s2);
        getnext(s2);
        cout<<kmp(s1,s2)<<endl;
    }
}
