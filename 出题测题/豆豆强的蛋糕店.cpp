#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
double minl,maxl;
struct TPoint
{
    double x,y;
    TPoint(){};
    TPoint(double _x,double _y):x(_x),y(_y){}
    TPoint operator-(const TPoint p){return TPoint(x-p.x,y-p.y);}
};
double dist(TPoint a,TPoint b)//两点距
{
    TPoint c(a-b);
    return sqrt(c.x*c.x+c.y*c.y);
}
double cross(TPoint a,TPoint b,TPoint c)//叉积
{
    TPoint s(b-a),t(c-a);
    return s.x*t.y-s.y*t.x;
}
double disps(TPoint a,TPoint b,TPoint c)//点到线段的最近距离
{
    TPoint s(a-b),t(c-b);
    if(s.x*t.x+s.y*t.y<0) return dist(a,b);
    s=(a-c); t=(b-c);
    if(s.x*t.x+s.y*t.y<0) return dist(a,c);
    return fabs(cross(a,b,c))/(dist(b,c));
}
double n,m;
TPoint ori,s,e;
double cal(double x,double y,double r){
    if(r <= x/2.0){
        return PI * r * r;
    }else if(r <= y/2.0){
        double s = PI * r * r;
        double arg = acos((x/2.0)/r) * 2;
        double s1 = 2 * (PI * r * r * (arg/(2*PI)) - r * r * 0.5 * sin(arg));
        return s - s1;
    }else if(r <= sqrt(x*x/4.0 + y*y/4.0)){
        double s = PI * r * r;
        double arg = acos((x/2.0)/r) * 2;
        double s1 = 2 * (PI * r * r * (arg/(2*PI)) - r * r * 0.5 * sin(arg));
        arg = acos((y/2.0)/r) * 2;
        double s2 = 2 * (PI * r * r *(arg/(2*PI)) - r * r * 0.5 * sin(arg));
        return s - s1 - s2;
    }else return x * y;
}
int main(){
    int T;
    ori.x = 0,ori.y = 0;
    scanf("%d",&T);
    double S;
    while(T--){
        scanf("%lf %lf %lf",&n,&m,&S);
        if(n > m) swap(n,m);
        scanf("%lf %lf %lf %lf",&s.x,&s.y,&e.x,&e.y);
        double ans;
        if(s.x == e.x && s.y == e.y) {
            ans = 0.000;
        }else{
            minl = disps(ori,s,e);
            maxl = max(dist(ori,s),dist(ori,e));
            ans = cal(n,m,maxl) - cal(n,m,minl);
        }
        if(ans >= S){
            puts("YES");
        }else puts("NO");
        //printf("%.3f\n",ans);
    }
    return 0;
}
