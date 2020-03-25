#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
typedef long long LL;
int n,s[maxn];
LL v[maxn];
priority_queue<LL,vector<LL>,greater<LL> > que;
vector<int>g[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%d",&v[i],&s[i]);
        g[s[i]].push_back(i);
    }
    LL mx=0;
    LL sum=0;
    for(int i=n;i>=1;i--){
        for(auto x:g[i]){
            sum+=v[x];
            que.push(v[x]);
        }
        while(que.size()>i){
            sum-=que.top();
            que.pop();
        }
        mx=max(mx,sum);
    }
    printf("%lld\n",mx);
    return 0;
}