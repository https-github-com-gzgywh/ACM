#include "bits/stdc++.h"
using namespace std;
const int maxn=2000+10;
typedef long long LL;
const LL mod=1e9+7;
int n;
LL p[maxn],dp[maxn][maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]*(1-p[i]+mod)%mod;
        for(int j=1;j<=i;j++){
            dp[i][j]=((dp[i-1][j]*(1-p[i]+mod)%mod)+(dp[i-1][j-1]*p[i]%mod))%mod;
        }
    }
    for(int i=0;i<=n;i++) printf("%lld ",dp[n][i]);
    printf("\n");
    return 0;
}