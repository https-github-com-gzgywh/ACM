#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL mod=9901;
LL a,b;
LL quickmod(LL x,LL y){
    LL res=1;
    x%=mod;
    while(y){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
LL dfs(LL p,LL k){
    if(k==1) return 1;
    if(k%2==0) return ((1+quickmod(p,k/2)%mod)*dfs(p,k/2))%mod;
    else return (1+(p*dfs(p,k-1)))%mod;
}
int main()
{
    scanf("%lld%lld",&a,&b);
    if(a==0){
        printf("0\n");
        return 0;
    }
    LL res=1;
    for(LL i=2;i*i<=a;i++){
        LL cnt=0;
        if(a%i==0){
            while(a%i==0){
                a/=i;
                cnt++;
            }
        }
        res=res*dfs(i,b*cnt+1ll);
        res%=mod;
    }
    if(a>1) res=(res*dfs(a,b+1ll))%mod;
    printf("%lld\n",res);
    return 0;
}