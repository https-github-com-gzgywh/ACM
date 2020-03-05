#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL n;
LL solve(LL a){
    if(a==2ll) return 2ll;
    LL tmp=2;
    for(LL i=2;i*i<=a;i++){
        if(i*i==a){
            tmp++;
        }else{
            if(a%i==0) tmp+=2;
        }
    }
    return tmp;
}
int main()
{
    scanf("%lld",&n);
    int cnt=0;
    while(n!=2){
        cnt++;
        n=solve(n);
    }
    printf("%d\n",cnt);
    return 0;
}