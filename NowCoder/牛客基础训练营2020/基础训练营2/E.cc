#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL n;
int main()
{
    scanf("%lld",&n);
    LL cnt=0;
    for(LL i=1;i*i<=n;i++){
        LL tmp=i*i;
        for(LL j=1;j*j<=tmp;j++){
            if(tmp%j==0){
                if(j*j==tmp) cnt++;
                else cnt+=2;
            }
        }
    }
    printf("%lld\n",cnt);
    return 0;
}