#include "bits/stdc++.h"
using namespace std;
int n,k;
int main()
{
    double x0,y0;
    cin>>x0>>y0;
    cin>>n>>k;
    k=n-k;
    vector<double>v1,v2;
    for(int i=1;i<=n;i++){
        double x,y;
        cin>>x>>y;
        if(x*x0<0){
            v1.push_back(y0-x0*(y-y0)/(x-x0));
        }
        if(y*y0<0){
            v2.push_back(x0-y0*(x-x0)/(y-y0));
        }
    }
    double mi=1e18;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1.size()>=k){
        int head=0,tail=k-1;
        while(tail<v1.size()){
            mi=min(mi,v1[tail]-v1[head]);
            head++,tail++;
        }
    }
    if(v2.size()>=k){
        int head=0,tail=k-1;
        while(tail<v2.size()){
            mi=min(mi,v2[tail]-v2[head]);
            head++,tail++;
        }
    }
    if(mi==1e18) printf("-1\n");
    else printf("%.6f\n",mi);
    return 0;
}