#include <iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
        if ( b == 0) return a;
        else return gcd(b, a%b);
}
int main()
{  char inp[50];


    while(scanf("%s",inp) && strcmp(inp,"0")){


   long long num=999999999999999999LL;

    long long denom=999999999999999999LL;
    int len=2,i=2;
    while(inp[len]!='.'){
        len++;
    }
    len=len-2;

    while(inp[i]!='.'){
        long long d=0,ones=0;
        for(int nines=0;nines<len-i+2;nines++){
            d=d*10+9;
            ones=ones*10+1;
        }
        for(int p=0;p<i-2;p++)
            d*=10;

        long long n=0,x=0,y=0;
        for(int curr=2;curr<len+2;curr++){
            x=x*10+inp[curr]-48;
        }
        for(int curr=2;curr<i;curr++){
            y=y*10+inp[curr]-48;
        }
        n=x-y;
        long long gc=gcd(n,d);
        n/=gc;
        d/=gc;

         if(d<denom){
            denom=d;
            num=n;
         }
        i++;
    }
    cout<<num<<'/'<<denom<<endl;
}
    return 0;
}
