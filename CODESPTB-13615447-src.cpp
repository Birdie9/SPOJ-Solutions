#include <iostream>
#define LL long long
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
int cnt=0;
LL mrg(int*a1,int*a2,int n1,int n2){
    int p=0,q=0;
    LL c=0;
    int i=0;
    int a[n1+n2];

    while(p<n1 && q<n2){
        if(a1[p]<=a2[q]) {
            a[i]=a1[p];
            i++;p++;
        }
        else{
            a[i]=a2[q];
            i++;q++;c+=(n1-p);
        }
    }
    if(p==n1){
        while(q<n2){
            a[i]=a2[q
            ];q++;i++;
        }
    }
    else{
        while(p<n1){
            a[i]=a1[p];p++;i++;
        }
    }
    FOR(i,0,n1+n2){
    a1[i]=a[i];
    }
    return c;
}
LL msort(int* a,int n){
if(n==1){
    return 0;
}
else{
    if(n%2==0)
        return msort(a,n/2)+msort(a+n/2,n/2)+mrg(a,a+n/2,n/2,n/2);
    else
        return msort(a,n/2)+msort(a+n/2,n/2+1)+mrg(a,a+n/2,n/2,n/2+1);
}
}
int main()
{
    int i,j,k,t;
    scanint(t);
    REP(i,t)
    {
        cnt=0;
        int n;
        scanint(n);
        int a[n];
        REP(j,n)
        {
            scanint(a[j]);
        }
        LL x=msort(a,n);

       cout<<x <<endl;
    }
    return 0;
}
