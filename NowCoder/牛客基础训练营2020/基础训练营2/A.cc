#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL A,B,C,X,Y,Z;
int main()
{
    cin>>A>>B>>C>>X>>Y>>Z;
    cout<<min(A,Y)+min(B,Z)+min(C,X)<<endl;
    return 0;
}