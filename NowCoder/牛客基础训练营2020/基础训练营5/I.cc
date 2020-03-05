#include "bits/stdc++.h"
using namespace std;
const int maxn=15;
int n,m;
struct node{
    int id,num;
}p[maxn];
bool cmp(node x,node y){
    return x.num>=y.num;
}
int main()
{
    cin>>n>>m;
    int tmp=-1;
    for(int i=1;i<=n;i++){
        cin>>p[i].num;
        p[i].id=i;
        if(i==9) tmp=p[i].num;
    }
    if(tmp==-1){
        cout<<"No"<<endl; return 0;
    }
    if((double)tmp>=((double)m*0.8)){
        cout<<"Yes"<<endl;
        return 0;
    }
    sort(p+1,p+1+n,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(p[i].id==9) break;
        if(p[i].num>tmp) cnt++;
    }
    if(cnt>=3){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}