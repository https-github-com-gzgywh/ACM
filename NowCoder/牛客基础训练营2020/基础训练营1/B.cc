#include "bits/stdc++.h"
using namespace std;
int n,x,a,b;
int main()
{
    scanf("%d%d%d%d",&n,&x,&a,&b);
    int tmp=n*(x*a+((100-x)*b));
    printf("%.2f\n",(double)tmp/100.0);
    return 0;
}