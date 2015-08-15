#include <iostream>
#include<cstring>
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
    int n,m;
    scanint(n);
    scanint(m);
    int hot[n];
    long long sum[n];
    int last[n];
    scanint(hot[0]);
    sum[0]=hot[0];
    for(int i=1;i<n;i++){
       scanint(hot[i]);
        sum[i]=sum[i-1]+hot[i];
    }
    long long dp[n];

    dp[0]=hot[0]>m?0:hot[0];
    last[0]=hot[0]>m?1:0;
    for(int i=1;i<n;i++){
            if(sum[i]<=m) {
            dp[i]=sum[i];
            last[i]=0;
            }
            else{
                int j=last[i-1]-1;
                if(last[i-1]==0) j=0;
                for(;i>=j && sum[i]-sum[j]>m ;j++);
                last[i]=j+1;
            dp[i]=max(dp[i-1],sum[i]-sum[j]);
            }
        }
    cout<<dp[n-1]<<endl;
    return 0;
}
