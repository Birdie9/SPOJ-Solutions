#include <iostream>
#define INF 1000000000000LL
#define LL long long
#define FOR(i,a,b) for( i=(a);i<(b);++i)
#define FORE(i,a,b) for( i=(a);i<=(b);++i)
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
LL dp[101][101];
int ar[101];
LL dp2[101][101];
int sum(int a,int b)
{
    if(dp2[a][b]!=-1)return dp2[a][b];
    int ret=0;
    int st=a,en=b;
    while(st<=b)
    {
        ret=(ret+ar[st])%100;
        st++;
    }
    return dp2[a][b]=ret;
}
LL smoke(int a,int b)
{
    if(dp[a][b]!=-1)return dp[a][b];
    if(a==b) return dp[a][b]=0;
    LL ret=-1;
    int st=a,en=b;
    while(st<en)
    {
        LL temp=(smoke(a,st)+smoke(st+1,b)+sum(a,st)*sum(st+1,b));
        if(temp<ret || ret==-1) ret =temp;
        st++;
    }
    return dp[a][b]=ret;
}
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        REP(i,n)
        {
            scanint(ar[i+1]);
        }
        REPE(i,n)REPE(j,n) {dp[i][j]=-1;dp2[i][j]=-1;}
        printf("%lld\n",smoke(1,n));
    }
    return 0;
}
