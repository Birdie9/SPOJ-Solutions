#include <iostream>
#include<cstdio>
#define gc getchar_unlocked

using namespace std;
void scanlong(long long &x)
{
    register long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
    int n;
    cin>>n;
    long long m[n];
    long long dp[n+1];
    for(int i=0;i<n;i++){
        scanlong(m[i]);
    }
    dp[0]=0;
    dp[1]=m[0];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+m[i-1]);
    }
    printf("Case %d: %lld\n",test,dp[n]);
    }
    return 0;
}
