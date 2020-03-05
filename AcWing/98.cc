#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
struct node{
    LL x,y;
};
node dfs(LL n,LL p){
    if(n==0) return {0,0};
    LL block=1ll<<2*n-2,len=1ll<<n-1;
    auto point=dfs(n-1,p%block);
    int m=p/block;
    LL x=point.x,y=point.y;
    if(m==0) return {y,x};
    else if(m==1) return {x,y+len};
    else if(m==2) return {x+len,y+len};
    else return {len*2-1-y,len-1-x};
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        LL n,a,b;
        scanf("%lld%lld%lld",&n,&a,&b);
        auto pa=dfs(n,a-1ll);
        auto pb=dfs(n,b-1ll);
        double x=pa.x-pb.x,y=pa.y-pb.y;
        printf("%.0lf\n",sqrt(x*x+y*y)*10);
    }
    return 0;
}