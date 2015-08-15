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
#define LL long long
#include<algorithm>
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 | c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;
int dp[100];
int main()
{
    LL n;
    cin>>n;
    dp[0]=1;
    dp[1]=3;
    dp[2]=7;
    int i=3;
    while(i!=n+1 && i<100)
    {
        dp[i]=2*dp[i-1]+dp[i-2];
        //cout<<dp[i]<<endl;
        i++;
    }
    cout<<dp[n]<<endl;
    return 0;
}


