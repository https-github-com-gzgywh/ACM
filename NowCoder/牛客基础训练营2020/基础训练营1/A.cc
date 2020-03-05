#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL n,m;
int main()
{
    cin>>n>>m;
    LL sum=0;
    sum=(sum+(4ll*(n-1)*(m-2)%mod+(4ll*(m-1)*(n-2)%mod))%mod)%mod;
    sum=(sum+((2ll*(m-1)*(n-2)%mod*(n-2)%mod)%mod+(2ll*(n-1)*(m-2)%mod*(m-2)%mod)%mod)%mod)%mod;
    sum=(sum+((2ll*(m-2)*(n-1)%mod*(n-2)%mod)%mod+(2ll*(n-2)*(m-1)%mod*(m-2)%mod)%mod)%mod)%mod;
    cout<<sum<<endl;
    return 0;

}