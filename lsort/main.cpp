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
#define FILL(l,x) fill_n(*(l),( sizeof (l)) / sizeof (**(l)), (x))
#define INF 999999999

#include<utility>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int memo[1000][1000],n,p[1000];
int solve (int s,int e,int ST,int* acc){
int ret=INF,i;
if(s<0){
    REP(i,n){
        int temp=(i+1)*1+solve(p[i],p[i],0);
        if(temp<ret) ret=temp;
    }
    return ret;
}
else{
    if(memo[s-1][e-1]!=-1) return memo[s-1][e-1];
    else if(e-s+1==n){
         return memo[s-1][e-1]=0;
    }
   int step=e-s+2;
   bool done1=false,done2=false,inc=true;int x=0;int st=0;
   FOR(i,ST,n){
        if((p[i]>e) || (p[i]<s)) x++;
        if(x) inc=false;
        if(inc) st++;
        if(p[i]==s-1){
           int temp=(x)*step+solve(p[i],e,st);
           if(temp<ret) ret=temp;
           done1=true;
        }
        else if(p[i]==e+1){
            int temp=(x)*step+solve(s,p[i],st);
           if(temp<ret) ret=temp;
           done2=true;
        }
        if(done1 && done2) break;
   }
}
return memo[s-1][e-1]=ret;
}
int main()
{
    int t,i,j;
    scanint(t);
    REP(i,t){

        scanint(n);
        REP(j,n)
        REP(k,n) memo[j][k]=-1;
        REP(j,n) scanint(p[j]);
        int acc=0;
        printf("%d\n",solve(-1,-1,0,&acc));
    }
    return 0;
}

