#include <iostream>
#define LL long long
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

int main()
{

    int n,i,j;
    scanint(n);
    int cnt[1<<10];
    MSET(cnt,0);
    REP(i,n)
    {
        char num[19];
        scanf("%s",num);
        int state=0;
        for(int k=0;num[k]!='\0';k++)
        {
            state|=1<<(num[k]-'0');
        }
        cnt[state]++;
    }
    LL palcount=0;
    REP(i,1<<10)REP(j,1<<10){
        if(i!=j && (i&j)) palcount+=(LL)cnt[i]*cnt[j];
    }
    REP(i,1<<10) palcount+=(LL)cnt[i]*(cnt[i]-1);
    printf("%lld\n",(palcount)/2);
    return 0;
}
