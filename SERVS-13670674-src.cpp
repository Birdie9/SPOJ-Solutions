#include <iostream>

#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define VI vector<int>
#define PII pair<int,int>
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define MSET(x,y) memset((x),(y),sizeof(x))

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
int main()
{
    int i,n;
    scanint(n);
    int c[n+1];
    REP(i,n)
    {
        scanint(c[i+1]);
    }
    int dp[n+1][2];
    dp[n][0]=c[n];
    dp[n][1]=n;
    for(int i=n-1;i>=1;i--)
    {
        int minm=dp[i+1][0]+dp[i+1][1]-i;
        int val=dp[i+1][1];
        for(int j=i;j<dp[i+1][1];j++)
        {
            int temp=c[j]+dp[j+1][0]+(j-i+1)*(j-i)/2;
            if(temp<minm ){ minm=temp;val=j;}
        }
        dp[i][0]=minm;
        dp[i][1]=val;
    }
    printf("%d\n",dp[1][0]);
    return 0;
}
