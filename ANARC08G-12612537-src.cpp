#include <iostream>
#include<cstdio>
#include<cstdlib>
#define gc getchar_unlocked
using namespace std;
inline void scanint(int &x);
 int a[1001];
long long int sum;
int test;
int main()
{
int i,j,k,n;
while(scanf("%d",&n) && n){
    test++;sum=0;
    for(i=0;i<n;i++) a[i]=0;
       for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int c=0;
        scanint(c);
               a[i]-=c;
               a[j]+=c;
           sum+=(c);
              }
           }
  long long int sum2=0;
    for(i=0;i<n;i++){
            if(a[i]>0)
       sum2+=a[i];
   }
   printf("%d. %lld %lld\n",test,sum,sum2);
}
    return 0;
}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
