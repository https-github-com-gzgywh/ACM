#include "bits/stdc++.h"
using namespace std;
const int maxn=2e5+100;
int n;
struct node{
    int a,b,id,sum;
}p[maxn];
bool cmp(node x,node y){
    return x.sum>y.sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i].a);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].b);
        p[i].id=i;
        p[i].sum=p[i].a+p[i].b;
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(i%2) printf("%d ",p[i].id);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(i%2==0) printf("%d ",p[i].id);
    }
    printf("\n");
    return 0;
}