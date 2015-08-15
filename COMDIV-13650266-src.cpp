#include <iostream>

#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define VI vector<int>
#define PII pair<int,int>
#define gc getchar_unlocked
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
int factors[1000010];
int count1(int x)
{
    int i,tempx=x;
    REPE(i,tempx){
        factors[i]=0;
    }
    for(int i=2;i<=x ;i++)
    {
        while(x%i==0)
        {
            x/=i;
            factors[i]++;
        }
    }
    int ret=1;
    REPE(i,tempx){
        ret*=(factors[i]+1);
    }
    return ret;
}
int div1 (int a,int b)
{
while(true){
    if(b==0) return count1(a);
    int temp=b;
    b=a%b;
    a=temp;
    }
}
int main()
{
    int t;
    scanint(t);
    for(;t>0;t--)
    {
        int a,b;
        scanint(a);
        scanint(b);
        if(a<b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        printf("%d\n",div1(a,b));
    }
    return 0;
}

