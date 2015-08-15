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
    int t,n;
    scanint(t);
    REP(i,t)
    {
        char ht[101][16];
        bool empty[101];
        bool deleted[101];
        MSET(empty,true);
        MSET(deleted,false);
        MSET(ht,0);
        scanint(n);
        REP(j,n)
        {
            char inp1[21];
            char* inp=inp1;
            scanf("%s",inp);
            if(inp[0]=='A')
            {
                inp+=4;
                int hv=0;
                for(int k=0;inp[k]!='\0';k++)
                {
                    hv+=(k+1)*inp[k];
                }
                hv=(hv*19)%101;
                int org=hv,cnt=0,del=110;
                bool present=false;
                while(!empty[hv] && cnt <20)
                {
                    if(deleted[hv] && del==110 ) del=hv;
                    else if(strcmp(ht[hv],inp)==0) {present=true;break;}
                    cnt++;
                    hv=(org+cnt*cnt+23*cnt)%101;
                }
                if(!present && cnt<20)
                {
                    hv=del==110?hv:del;
                    empty[hv]=false;
                    deleted[hv]=false;
                    strcpy(ht[hv],inp);
                }
                else if(cnt==20 && del<101 && !present)
                {
                    hv=del;
                    empty[hv]=false;
                    deleted[hv]=false;
                    strcpy(ht[hv],inp);
                }

            }
            else
            {
                inp+=4;
                int hv=0;
                for(int k=0;inp[k]!='\0';k++)
                {
                    hv+=(k+1)*inp[k];
                }
                hv=(hv*19)%101;
                int org=hv;
                int cnt=0;
                bool present=false;
                while(!empty[hv] && cnt <20)
                {
                    if(!deleted[hv] && strcmp(ht[hv],inp)==0) {present=true;break;}
                    cnt++;
                    hv=(org+cnt*cnt+23*cnt)%101;
                }
                if(present && cnt<20)
                {
                    deleted[hv]=true;
                }
            }
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
