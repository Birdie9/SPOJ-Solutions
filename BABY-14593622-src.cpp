#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define unsigned long long ULL;
using namespace std;
int n;
int state1[17],state2[17];
int dp[(1<<17)-1];
int solve(int mask,int currRow)
{
    if(currRow==n) return 0;
    if(dp[mask]!=-1) return dp[mask];
    else
    {
        int minimum=1000000000;

        for(int i=0;i<n;i++)
        {
            if(!(mask&(1<<i)))
            {
                minimum = min (minimum, abs(currRow-i) + abs(state1[currRow]-state2[i])+solve(mask | (1<<i),currRow+1));
            }
        }
        return dp[mask] = minimum;
    }
}
int main()
{
    while(scanf("%d",&n))
    {
     if(n==0) break;
    memset(dp,-1,sizeof (int)*(1<<n));
    for(int i=0;i<n;i++)
        scanf("%d",&state1[i]);
    for(int j=0;j<n;j++)
        scanf("%d",&state2[j]);
    printf("%d\n", solve(0,0));
    }


    return 0;
}
