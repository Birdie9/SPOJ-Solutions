#include <iostream>
#include <cstdio>
#include<vector>
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

int main()
{
    int t;
    scanint(t);
    REP(i,t)
    {
        int m,n;
        scanint(m);
        scanint(n);
        int a[n];
        int h1[m];
        int h2[m];
        int done[m];
        MSET(a,-1);
        bool success=true;
        REP(j,m)
        {

            scanint(h1[j]);
            scanint(h2[j]);
            if(success);
            MSET(done,0);
            int k=j,cur=-1,prev=-1;

            while(done[k]!=2 && success)
            {
                if(a[h1[k]]==-1)
                {
                    a[h1[k]]=k;
                    break;
                }
                else if(a[h2[k]]==-1)
                {
                    a[h2[k]]=k;
                    break;
                }
                else{
                            int loc1=h1[k],loc2=h2[k];
                            cur=(loc1==prev)?loc2:loc1;
                            prev=cur;
                            done[k]++;
                            int temp=a[cur];
                            a[cur]=k;
                            k=temp;
                }

            }
if(done[k]==2)success=false;

        }
        if(success) printf("successful hashing\n");
        else printf("rehash necessary\n");


    }

    return 0;
}
