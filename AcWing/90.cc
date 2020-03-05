#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL a,b,p;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&p);
    LL res=0;
    while(b){
        if(b&1) res=(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    printf("%lld\n",res);
    return 0;
}