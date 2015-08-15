
#include <iostream>
#include<cstdio>
#define INF 1000000000
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int p[510],w[510];
int dp[10010][510];

int main()
{
    int t;
    scanint(t);
    for(;t>0;t--){
        int e,f;
        scanint(e);
        scanint(f);
        int W=f-e;
        int n;
        scanint(n);

        for(int i=0;i<n;i++){
            scanint(p[i]);
            scanint(w[i]);
        }

        for(int i=0;i<n;i++) dp[0][i]=0;
        for(int i=1;i<=W;i++){
            dp[i][0]=(i%w[0]==0)?((i/w[0])*p[0]):INF;

        }
        for(int i=1;i<=W;i++){
            for(int j=1;j<n;j++){
                    if(i>=w[j])
                    {
                        dp[i][j]=min(dp[i-w[j]][j]+p[j],dp[i][j-1]);
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                    }

            }
        }
        if(dp[W][n-1]==INF){
            printf("This is impossible.\n");
        }
        else{
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W][n-1]);
        }
    }
    return 0;
}


