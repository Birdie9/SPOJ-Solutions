#include <iostream>
#include <cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm>
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FORE(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define RFOR(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define RFORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define MSET(a,b) memset(a,b,sizeof(a))
#define PB push_back
#define gc getchar
#define LL long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 | c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


void scanlong(long long &x)
{
    register long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
using namespace std;

int main()
{
    map<string,int> h;
    int t;
    scanint(t);
    REP(i,t)
    {
        int n;
        scanint(n);
        REP(j,n)
        {
         string name;
         cin>>name;
         if(h.count(name)==0) h[name]=j;
         else h.erase(name);
        }
        cout<<h.size()<<endl;

    }

    return 0;
}
