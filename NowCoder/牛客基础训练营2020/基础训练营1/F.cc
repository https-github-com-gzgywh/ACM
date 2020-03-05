#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=1e5+100;
char s[maxn];
int n;
vector<int>g[maxn];
LL sum;
void dfs(int u,int fa){
    if(s[u]=='B') return;
    sum++;
    for(auto v:g[u]){
        if(v!=fa) dfs(v,u);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='B'){
            LL res1=0,res2=0;
            for(auto v:g[i]){
                sum=0;
                dfs(v,v);
                ans+=sum;
                res1+=sum;
                res2+=sum*sum;
            }
            ans+=(res1*res1-res2)/2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}