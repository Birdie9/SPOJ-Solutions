#include <iostream>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        scanint(n);
        scanint(k);
        int berry[n];
        for(int b=0;b<n;b++){
            scanint(berry[b]);
        }
        int dp[k+1][n+1];
        for(int ix=0;ix<=k;ix++)
        dp[ix][1]=berry[0]>ix?0:berry[0];
        for(int ix=0;ix<=k;ix++)
        dp[ix][0]=0;
        for(int ix=0;ix<=n;ix++)
        dp[0][ix]=0;

        for(int q=1;q<=k;q++){
            for(int l=2;l<=n;l++){
                if(berry[l-1]<=q)
                 dp[q][l]=max(dp[q][l-1],dp[q-berry[l-1]][l-2]+berry[l-1]);
                else dp[q][l]=dp[q][l-1];
            }
        }
        printf("Scenario #%d: %d\n",i,dp[k][n]);
    }

    return 0;
}
