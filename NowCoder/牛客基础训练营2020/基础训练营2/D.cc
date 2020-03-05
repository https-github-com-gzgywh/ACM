#include "bits/stdc++.h"
using namespace std;
const int maxn=500+10;
const double eps=1e-9;
int n;
struct node{
    double x,y;
}p[maxn];
double dp[maxn][maxn];
double v[5];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dp[i][j]=((p[i].x-p[j].x)*(p[i].x-p[j].x))+((p[i].y-p[j].y)*(p[i].y-p[j].y));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    if(n<3){
        printf("0\n");
        return 0;
    }
    init();
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if((p[i].y-p[k].y)*(p[i].x-p[j].x)-((p[i].x-p[k].x)*(p[i].y-p[j].y))==0) continue;
                v[0]=dp[i][j];
                v[1]=dp[i][k];
                v[2]=dp[j][k];
                sort(v,v+3);
                if(v[0]+v[1]<v[2]) cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}