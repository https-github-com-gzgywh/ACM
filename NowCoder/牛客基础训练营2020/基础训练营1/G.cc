#include "bits/stdc++.h"
using namespace std;
const int maxn=27;
vector<int>g[maxn];
int v[maxn];
int n,k;
string s;
int main()
{
    cin>>n>>k;
    cin>>s;
    int len=s.length();
    for(int i=0;i<26;i++) v[i]=INT_MAX;
    for(int i=0;i<len;i++){
        int tmp=s[i]-'a';
        g[tmp].push_back(i+1);
        if(g[tmp].size()>=k){
            int l=g[tmp].size()-1;
            int mi=g[tmp][l]-g[tmp][l-k+1]+1;
            v[tmp]=min(v[tmp],mi);
        }
    }
    int mx=INT_MAX;
    for(int i=0;i<26;i++){
        mx=min(mx,v[i]);
    }
    if(mx==INT_MAX) printf("-1\n");
    else printf("%d\n",mx);
    return 0;
}