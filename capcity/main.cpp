#include <cstdio>
#include<iostream>

#include <vector>

#define PB push_back
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FORE(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define RFOR(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define RFORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define MSET(a,b) memset(a,b,sizeof(a))
#define gc getchar_unlocked
#define LL long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
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

vector<int> stack2;
vi adj[200000];
vi rev[200000];
bool done[200000];
int in[200000];
int leader[200000];
int ans[200000];
int cur,n;
int tot=0;
void dfs_visit1(int i)
{

    done[i]=true;
    FOR(j,0,adj[i].size())
    {
        if(!done[adj[i][j]]) dfs_visit1(adj[i][j]);
    }

    stack2.PB(i);
}
void dfs_visit2(int i,int l)
{

    done[i]=false;
    FOR(j,0,rev[i].size())
    {
        if(done[rev[i][j]]) dfs_visit2(rev[i][j],l);
    }
    leader[i]=l;


}
int main()
{
    int m;
   scanint(n);
  // FILE* fp=fopen("input.txt","r");
  //fscanf(fp,"%d",&n);

scanint(m);
     // fscanf(fp,"%d",&m);
     REP(i,n){adj[i].clear();rev[i].clear();}
    REP(i,m)
    {
        int a,b;
    scanint(a);
    //    fscanf(fp,"%d",&a);
       scanint(b);
       //   fscanf(fp,"%d",&b);
        a--;b--;
        adj[a].PB(b);
        rev[b].PB(a);
    }
    REP(i,n) done[i]=false;
    REP(i,n)
   {
       if(!done[i]) dfs_visit1(i);
   }
   tot=0;
   int top=stack2.size();
   while(top>0){
        cur=stack2[top-1];
       top--;
       if(done[cur]){ dfs_visit2(cur,tot);
       tot++;}
   }
   int cnt=0;
    REP(i,tot){in[leader[i]]=0;}
    REP(i,n)
    {
        for(int j=0;j<rev[i].size() ;j++)
        if(leader[i]!=leader[rev[i][j]]  )
        {
            in[leader[rev[i][j]]]++;
        }
    }
    REP(i,tot)
    {
        if(in[i]==0) cnt++;
    }

    if(cnt!=1){printf("0\n");}
    else{
    int k=0;
    REP(i,n)
    {
        if(in[leader[i]]==0) { ans[k]=i;k++;}
    }
    printf("%d\n",k);
    REP(i,k)
    {
         printf("%d ",ans[i]+1);
    }
    printf("\n");
    }

    return 0;
}




