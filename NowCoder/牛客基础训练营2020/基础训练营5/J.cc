#include "bits/stdc++.h"
using namespace std;
const double pi=3.1415926;
int n,r,a,b;
int main()
{
    cin>>n>>r>>a>>b;
    int x=min(a,b);
    int y=max(a,b);
    double tmp=sin(pi/(double)n)*2.0*(double)r;
    int t=min(y-x,n-y+x);
    printf("%.6f\n",(double)t*tmp);
    return 0;
}