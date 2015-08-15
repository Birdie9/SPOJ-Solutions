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
    int t,i,j,k;
    scanint(t);
    REP(i,t)
    {
        int n;
        scanint(n);
        char str[11][n][11];
        fflush(stdin);
        REP(j,n)
        scanf("%s",str[0][j]);
        //cout<<str[0][0]<<endl;
        //cout<<str[0][1];
        int b[123];
        FORE(j,1,10)
        {
            MSET(b,0);
            REP(k,n)
            {
                char ch=str[j-1][k][10-j];
                int idx=ch;
                b[idx]++;
            }
            FORE(k,1,122)
            {
                b[k]+=b[k-1];
            }
            for(k=n-1;k>=0;k--)
            {
                char ch=str[j-1][k][10-j];
                int idx=ch;
               strcpy(str[j][ b[idx]-1],str[j-1][k]);
              // cout<<str[j][ b[idx]-1]<<endl;
               b[idx]=b[idx]-1;
            }
        }
        FOR(j,0,n)
        {
           cout<<str[10][j]<<endl;
        }
    }
    return 0;
}
