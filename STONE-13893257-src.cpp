#include <iostream>
#include <cstdio>
#include<vector>
#include<iomanip>
#include<cstring>
#include<queue>
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
double x[1000010];
double y[1000010];
int main()
{
    int t;
//printf("%.2f",-0.005);
    scanint(t);
    REP(i,t)
    {
        int n;
        scanint(n);
        REP(j,n)
        {
            scanf("%lf%lf",&x[j],&y[j]);
        }
        x[n]=x[0];
        y[n]=y[0];
        double a=0;
        REP(j,n)
        {
           a+= x[j]*y[j+1]-x[j+1]*y[j];
        }

        double cx=0,cy=0;
        REP(j,n)
        {
            cx+=(x[j]+x[j+1])*(x[j]*y[j+1]-x[j+1]*y[j]);
            cy+=(y[j]+y[j+1])*(x[j]*y[j+1]-x[j+1]*y[j]);
        }
        cx/=(3.0*a);
        cy/=(3.0*a);

        printf("%.2lf ",cx);
        printf("%.2lf\n",cy);

    }
    return 0;
}
