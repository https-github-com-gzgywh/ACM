#include "bits/stdc++.h"
using namespace std;
const int maxn=3e5+10;
typedef long long LL;
int n;
LL a,b,c,dp[maxn];
string s;
int main()
{
    cin>>n>>a>>b>>c;
    cin>>s;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(i>=4){
            if(s.substr(i-4,4)=="nico") dp[i]=max(dp[i],dp[i-4]+a);
        }
        if(i>=6){
            if(s.substr(i-6,6)=="niconi") dp[i]=max(dp[i],dp[i-6]+b);
        }
        if(i>=10){
            if(s.substr(i-10,10)=="niconiconi") dp[i]=max(dp[i],dp[i-10]+c);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}