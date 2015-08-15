#include <iostream>

#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define VI vector<int>
#define PII pair<int,int>
#define gc getchar
#define PB push_back
#define MP make_pair
#define MSET(x,y) memset((x),(y),sizeof(x))
#define gc getchar
#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
#include<algorithm>
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 | c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;
int dp[5010][5010];
int rec(int n,int k)
{

    if(n==0 && k>=0) return 1;
    if(n>0 && k==0) return 0;
    if(n<0 ) return  0;
    if(dp[n][k]>=0) return dp[n][k];
    return dp[n][k]=(rec(n,k-1)+rec(n-k,k))%1988;
}
int main()
{
    int i,j, n,k;
    REP(i,5010) REP(j,5010) dp[i][j]=-1;
    while(scanf("%d",&n)&&n)
    {

        scanint(k);
    printf("%d\n",rec(n-k,k));

    }

    return 0;
}
