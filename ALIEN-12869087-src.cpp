#include <cstdio>
#include<iostream>
#define gc getchar
using namespace std;
int sum[100000];
int st[100000];
int dp[100001];
int ppl[100001];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t,i;
    scanint(t);
    for(;t>0;t--){
        int a,b;
        scanint(a);
        scanint(b);

        for(i=0;i<a;i++){
            scanint(st[i]);
            if(i){
                sum[i]=sum[i-1]+st[i];
            }
            else sum[i]=st[i];
        }

        dp[0]=0;
        ppl[0]=0;

        for(i=1;i<=a;i++){
        int curr=sum[i-1]-sum[i-1-dp[i-1]];
        if(curr>b) {
                dp[i]=dp[i-1];
                ppl[i]=ppl[i-1];
        }
        else if(curr==b){
            dp[i]=dp[i-1];
            ppl[i]=ppl[i-1];
        }
        else if(curr<b){
            if(curr+st[i-1-dp[i-1]]<=b){
                dp[i]=dp[i-1]+1;
                ppl[i]=curr+st[i-1-dp[i-1]];
            }
            else{
                dp[i]=dp[i-1];
                ppl[i]=min(curr,ppl[i-1]);
            }
        }
        }

        printf("%d %d\n",ppl[a],dp[a]);
    }
    return 0;
}
