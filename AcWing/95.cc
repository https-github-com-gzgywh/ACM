#include "bits/stdc++.h"
using namespace std;
const int maxn=10;
const int n=5;
char a[maxn][maxn],b[maxn][maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                a[i][j]=b[i][j]='0';
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        int m=pow(2,5),mi=INT_MAX;
        for(int cas=0;cas<m;cas++){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    b[i][j]=a[i][j];
            int cnt=0;
            for(int p=0;p<5;p++){
                if(cas>>p&1){
                    cnt++;
                    b[1][p+1]=(1-(b[1][p+1]-'0'))+'0';
                    b[0][p+1]=(1-(b[0][p+1]-'0'))+'0';
                    b[1][p]=(1-(b[1][p]-'0'))+'0';
                    b[1][p+2]=(1-(b[1][p+2]-'0'))+'0';
                    b[2][p+1]=(1-(b[2][p+1]-'0'))+'0';
                }
            }
            for(int i=2;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(b[i-1][j]=='0'){
                        cnt++;
                        b[i][j]=(1-(b[i][j]-'0'))+'0';
                        b[i-1][j]=(1-(b[i-1][j]-'0'))+'0';
                        b[i][j-1]=(1-(b[i][j-1]-'0'))+'0';
                        b[i][j+1]=(1-(b[i][j+1]-'0'))+'0';
                        b[i+1][j]=(1-(b[i+1][j]-'0'))+'0';
                    }
                }
            }
            int flag=0;
            for(int i=1;i<=n;i++){
                if(b[5][i]=='0'){
                    flag=1; break;
                }
            }
            if(!flag) mi=min(mi,cnt);
        }
        if(mi>6) printf("-1\n");
        else printf("%d\n",mi);
    }
    return 0;
}
