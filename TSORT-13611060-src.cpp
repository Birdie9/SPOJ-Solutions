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
int a[1000010];
    int ar[1000010];

int main()
{

    MSET(a,0);
    int t;
    scanint(t);
    int i;
    REP(i,t)
    {
        int b;
        scanint(b);
        ar[i]=b;
        a[b]++;
    }
    FOR(i,1,1000010)
    {
        a[i]=a[i-1]+a[i];
    }
    int b[t+1];
    REP(i,t)
    {
        b[a[ar[i]]]=ar[i];
        a[ar[i]]--;
    }
    FORE(i,1,t)
    {
        printf("%d\n",b[i]);
    }
    return 0;
}
