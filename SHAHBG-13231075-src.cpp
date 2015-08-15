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

#include<cstring>
#include<algorithm>
#include <iostream>

#include<cstdio>
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
bool ar[30000];
int main()
{
    int gp=0;
    MSET(ar,false);
    int n,i,p;
    scanint(n);
    REP(i,n) {
        scanint(p);
        ar[--p]=true;
        if(p>0 && p<30000){
            if(ar[p-1] && ar[p+1]){
                gp--;
            }
            else if(!ar[p-1] && !ar[p+1]){
                gp++;
            }
        }
        else if(p==0 ){
            if(!ar[p+1]) gp++;
        }
        else{
            if(!ar[p-1]) gp++;
        }
        printf("%d\n",gp);
    }
    printf("Justice\n");
    return 0;
}
