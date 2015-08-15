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
int p[1000];
 int dp[1001][1001],shift[1001][1001];
        int pos[1001];
int main()
{
     int t,n;
    // FILE * fp= fopen("input.txt","r");
    scanint(t);
     // fscanf(fp,"%d",&t);
    REP(i,t){
        //FILE * fp= fopen("input.txt","r");
     //   fscanf(fp,"%d",&n);
       scanint(n);
        REP(j,n);

        REP(j,n) {scanint(p[j]);
           // fscanf(fp,"%d",&p[j]);
        int q=p[j];
        pos[q]=j+1;}

        FOR(j,1,n) shift[0][j]=0;
        FORE(i,1,n)
        {
            FORE(j,1,n)
            {
                shift[i][j]=shift[i-1][j];
                if(pos[i]<pos[j])shift[i][j]++;
            }
        }
        FORE(j,1,n)dp[0][j]=0;
        FORE(j,1,n)
        {
            FORE(k,1,n-j+1)
            {
                int last=k+j-1;
                dp[j][k]=min(dp[j-1][k+1]+j*(pos[k]-(shift[last][k]-shift[k-1][k])),dp[j-1][k]+j*(pos[last]-(shift[k+j-1][last]-shift[k-1][last])));
              //  cout<<dp[j][k]<<"   ";
            }
           // cout<<endl;

        }
        cout<<dp[n][1]<<endl;
    }
    return 0;
}
