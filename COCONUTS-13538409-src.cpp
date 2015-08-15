#include <iostream>
#include<queue>
#define INF 100000
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
int cap[1002][1002];
int from[1000];
int n;
bool done[1000];
int aug(int s,int t)
{
    MSET(from,-1);
    bool reached=false;
    int i;
    MSET(done,false);
    queue<int> Q;
        Q.push(s);
        done[s]=true;
        while(!Q.empty())
        {
            int cur=Q.front();
            Q.pop();
            FORE(i,0,n+1)
            {
                if(cap[cur][i]>0&& !done[i])
                {
                    Q.push(i);
                    done[i]=true;
                    from[i]=cur;
                    if(i==t)
                    {
                        reached=true;
                        break;
                    }
                }
                if(reached)break;
            }
            if(reached)break;
        }
        if(reached){
            int bottle=INF;
            int cur=t;
            int prev=from[cur];
            while(prev!=-1)
            {

                bottle=min(bottle,cap[prev][cur]);
                cur=prev;
                prev=from[cur];
            }
            cur=t;
            prev=from[cur];
            while(prev!=-1)
            {

                cap[prev][cur]-=bottle;
                cap[cur][prev]+=bottle;
                cur=prev;
                prev=from[cur];
            }
            return bottle;
        }
        else return -1;
}
int maxflow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int f=aug(s,t);
        if(f==-1)break;
        flow+=f;
    }
    return flow;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)&&n){
        int m;
    scanint(m);
        MSET(cap,0);
        REP(i,n){
            int a;
            scanint(a);
            if(a==1){
                cap[i+1][n+1] =1;
            }
            else{
                cap[0][i+1]=1;
            }
        }
        REP(i,m)
        {
            int a,b;
            scanint(a);
            scanint(b);
            cap[a][b]=1;
            cap[b][a]=1;
        }
        cout<<maxflow(0,n+1)<<endl;
    }
    return 0;
}
