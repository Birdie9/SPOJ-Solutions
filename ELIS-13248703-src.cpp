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
#define INF 1000000000
#define gc getchar_unlocked
#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int ar[1000000],N;
int memo[1000000];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int lis(int n){
    int j,ret=1
    ;
    if(memo[n]!=-1) return memo[n];
    else{
            if(n<N-1){
                FOR(j,n+1,N)
                    if(ar[j]>ar[n]){
                        int temp=1+lis(j);
                        if (ret<temp )ret=temp;
                    }
                return memo[n]=ret;
            }
            else return memo[n]=1;
    }
}
int main()
{
    int i;
    scanint(N);
    MSET(memo,-1);
    REP(i,N) scanint(ar[i]);
    for(int i=0;i<N;i++) if(memo[i]==-1)lis(i);
    int mxm=0,ind;
    REP(i,N) {
        mxm=(mxm<memo[i])?memo[i]:mxm;
        if(mxm==memo[i]) ind=i;
    }
    cout<<mxm<<endl;

    return 0;
}
