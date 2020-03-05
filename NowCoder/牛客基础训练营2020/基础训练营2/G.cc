#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+8;
int T;
LL a,b,c,d,e,f,g;
LL quickmod(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d>>e>>f>>g;
        g%=mod;
        if(((quickmod(a,d)+quickmod(b,e))%mod+quickmod(c,f))%mod==g){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}