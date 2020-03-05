#include "bits/stdc++.h"
using namespace std;
string s;
int n;
int main()
{
    cin>>n;
    cin>>s;
    int x=0,y=0;
    for(auto ch:s){
        if(ch=='6') x++;
        if(ch=='1') y++;
    }
    cout<<min(x-1,y)<<endl;
}