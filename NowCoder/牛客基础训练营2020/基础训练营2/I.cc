#include "bits/stdc++.h"
using namespace std;
int n;
int main()
{
    set<int>s;
    scanf("%d",&n);
    int v0=0,v1=pow(2,31)-1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v0|=x;
        v1&=x;
        s.insert(x);
    }
    int v=v0^v1;
    int ans=0;
    for(int i=0;i<=30;i++){
        int tmp=1<<i;
        if(tmp&v){
            ans=tmp*(s.size()-1);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}