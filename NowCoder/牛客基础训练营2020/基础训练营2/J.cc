#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=2e5+10;
const LL mod=1e9+7;
int n,m;
LL b[maxn],k[maxn];
struct node{
    int l,r;
    LL k,b;
}tree[maxn<<2];
void pushup(int rt){
    tree[rt].k=tree[rt<<1].k*tree[rt<<1|1].k%mod;
    tree[rt].b=(tree[rt<<1].b*tree[rt<<1|1].k+tree[rt<<1|1].b)%mod;
}
void build(int l,int r,int rt){
    tree[rt].l=l,tree[rt].r=r;
    if(l==r){
        tree[rt].k=k[l];
        tree[rt].b=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void update(int id,int rt,LL k1,LL b1){
    if(tree[rt].l==tree[rt].r){
        tree[rt].k=k1,tree[rt].b=b1;
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(id<=mid) update(id,rt<<1,k1,b1);
    else update(id,rt<<1|1,k1,b1);
    pushup(rt);
}
pair<LL,LL> query(int l,int r,int rt){
    if(tree[rt].l==l&&tree[rt].r==r) return make_pair(tree[rt].k,tree[rt].b);
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(r<=mid) return query(l,r,rt<<1);
    else if(l>mid) return query(l,r,rt<<1|1);
    else return make_pair(query(l,mid,rt<<1).first*query(mid+1,r,rt<<1|1).first%mod,
                (query(l,mid,rt<<1).second*query(mid+1,r,rt<<1|1).first+query(mid+1,r,rt<<1|1).second)%mod);
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    build(1,n,1);
    while(m--){
        int op,i,l,r;
        LL k1,b1;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%lld%lld",&i,&k1,&b1);
            update(i,1,k1,b1);
        }else{
            scanf("%d%d",&l,&r);
            pair<LL,LL> tmp=query(l,r,1);
            printf("%lld\n",(tmp.first+tmp.second)%mod);
        }
    }
    return 0;
}