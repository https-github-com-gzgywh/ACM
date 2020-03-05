#include "bits/stdc++.h"
using namespace std;
const int maxn=2e5+100;
int n,k,a[maxn],b[maxn],dp1[maxn],dp2[maxn];
string s;
int main()
{
    scanf("%d%d",&n,&k);
    cin>>s;
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
        b[i]=1-a[i];
        dp1[i]=dp1[i-1]+a[i];
        dp2[i]=dp2[i-1]+b[i];
    }
    int l=1,r=1,mx=0;
    while(r<=n&&l<=r){
        while(dp1[r]-dp1[l-1]<=k&&r<=n) r++;
        mx=max(mx,r-l);
        //cout<<mx<<endl;
        l++;
    }
    l=1,r=1;
    while(r<=n&&l<=r){
        while(dp2[r]-dp2[l-1]<=k&&r<=n) r++;
        mx=max(mx,r-l);
        //cout<<mx<<endl;
        l++;
    }
    printf("%d\n",mx);
    return 0;
}