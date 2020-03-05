#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
string s1,s2;
int n,m;
int main()
{
    cin>>n>>m;
    cin>>s1>>s2;
    int i=0,j=0;
    int cnt=0;
    while(i<n&&j<m){
        if(s1[i]==s2[j]){
            i++,j++;
        }else{
            i++,j++,cnt++;
        }
    }
    cout<<max(m,n)-min(n,m)+cnt<<endl;
    return 0;
}