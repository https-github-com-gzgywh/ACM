#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL n,x,y,a,b;
void mul(LL f[2],LL res[2][2]){
    LL c[2];
    memset(c,0,sizeof(c));
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++)
            c[j]=(c[j]+f[k]*res[k][j])%(mod-1);
    }
    memcpy(f,c,sizeof(c));
}
void mulself(LL res[2][2]){
    LL c[2][2];
    memset(c,0,sizeof(c));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j]=(c[i][j]+res[i][k]*res[k][j])%(mod-1);
            }
        }
    }
    memcpy(res,c,sizeof(c));
}
LL quick(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
int main()
{
    cin>>n>>x>>y>>a>>b;
    if(n==1){
        cout<<x%mod<<endl;
        return 0;
    }
    if(n==2){
        cout<<y%mod<<endl;
        return 0;
    }
    if(x%mod==0||y%mod==0||a%mod==0){
        cout<<"0"<<endl;
        return 0;
    }
    x%=mod,y%=mod,a%=mod;
    a=quick(a,b);
    LL f[2]={1,0};
    LL res[2][2]={{0,1},{1,1}};
    n--;
    for(;n;n>>=1){
        if(n&1) mul(f,res);
        mulself(res);
    }
    LL tmp1=quick(x,f[0]);
    LL tmp2=quick(y,f[1]); 
    LL tmp3=quick(a,f[0]+f[1]-1);
    cout<<((tmp1*tmp2)%mod*tmp3)%mod<<endl;
    return 0;
}