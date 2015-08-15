#include <iostream>

using namespace std;
#define ABS(a) (a)<0?(-(a)):(a)
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
#define LL long long
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
LL a[10000000];
int main()
{
    int i,t;
    scanint(t);
    for(;t>0;t--)
    {
        LL n;
        cin>>n;
        REP(i,n)
        {
            string str;
            cin>>str>>a[i];
        }
        sort(a,a+n);
        LL count=0;
        REP(i,n)
        {
            count+=ABS(i+1-a[i]);
        }
        cout<<count<<endl;
    }

    return 0;
}
