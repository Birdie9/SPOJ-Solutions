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
char ht[101][20];
bool empty[101];
bool deleted[101];
int hash(char inp[20])
{
    int hv=0;
                for(int k=0;inp[k]!='\0';k++)
                {
                    hv+=(k+1)*inp[k];
                }
                hv=(hv*19)%101;
                return hv;
}
int find(char inp[20])
{
    int key=hash(inp);
    FOR(j,0,20)
    {
        int probe=(key+j*j+23*j)%101;
        if(strcmp(ht[probe],inp)==0 && !deleted[probe] && !empty[probe])return probe;
        else if(empty[probe]) return -1;
    }
    return -1;
}
void del(char inp[20])
{
    int probe=find(inp);
    if(probe>=0)
    {
        deleted[probe]=true;
    }
}
void add(char inp[20])
{
    int probe=find(inp);
    if(probe>=0) return;
    int key=hash(inp);
    REP(j,20)
    {
        probe=(j*j +23*j+key)%101;
        if(deleted[probe] || empty[probe])
        {
            strcpy(ht[probe],inp);
            deleted[probe]=false;
            empty[probe]=false;
            return;
        }
    }
}
int main()
{
   // FILE* fp=fopen("input.txt","r");
    int t;
    scanint(t);
    //fscanf(fp,"%d",&t);
    REP(i,t)
    {
        MSET(empty,true);
        MSET(deleted,false);
       int n;
        scanint(n);
        //fscanf(fp,"%d",&n);
        REP(j,n)
        {
            char ar[25];
            cin>>ar;
            //fscanf(fp,"%s",ar);
            if(ar[0]=='A') add(ar+4);
            else del(ar+4);
        }
        int num=0;
           REP(j,101)
        {
            if(!deleted[j] && !empty[j]) num++;
        }
        printf("%d\n",num);
        REP(j,101)
        {
            if(!deleted[j] && !empty[j]) printf("%d:%s\n",j,ht[j]);
        }
    }

    return 0;
}
