#include "bits/stdc++.h"
using namespace std;
const int maxn=3e5+100;
typedef long long LL;
int n,k;
LL a[maxn],dp[maxn];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++) dp[i+k-1]=a[i+k-1]-a[1];
    for(int i=2*k;i<=n;i++) dp[i]=min(dp[i-1]+a[i]-a[i-1],dp[i-k]+a[i]-a[i-k+1]);
    printf("%lld\n",dp[n]);
    return 0;
}