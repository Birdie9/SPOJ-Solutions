#include <iostream>
#include<cstring>
#include<cstdio>
#define gc getchar
using namespace std;
void scanint(unsigned long long &x)
{
    register unsigned long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()

{
       unsigned long long o=1;
    long long n;
    cin>>n;
    unsigned long long bits=0;
   unsigned  long long s1,s2;
    scanint(s1);
    scanint(s2);
    unsigned long long s=s1^s2;
    for(unsigned long long i=0;i<64;i++){

        if(s&(o<<i)) bits=bits|(o<<i);

    }
    for( int i=2;i<n;i++){
        unsigned long long j;
        scanint(j);
        for(unsigned long long k=0;k<64;k++){
            if(!(bits&(o<<k))){
                unsigned long long a=0,b=0;
                if(j&(o<<k))a=1;
                if(s1&(o<<k)) b=1;
               if(a^b){
                bits=bits|(o<<k);
               }
            }
        }
    }

   cout<<bits<<endl;

    return 0;
}
