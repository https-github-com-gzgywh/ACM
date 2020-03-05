#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
int n,a[maxn],vis[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&a[i]);
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            printf("%d\n",i);
            return 0;
        }
    }
}