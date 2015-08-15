#include <iostream>
#include<map>
#include<stdio.h>
#define LL long long
using namespace std;
map<LL,LL> val;


LL calculate(LL k)
{
    if(val.find(k)!=val.end())
        {
            return val[k];
        }
    else return val[k] =max( calculate(k/2) + calculate(k/3) +calculate(k/4),k);

}
int main()
{
    val[1]=1;
    val[0]=0;
    val[2]=2;
    long long q;
    int t=0;
    while(scanf("%lld",&q))
    {
        t++;
        if(val.find(q)!=val.end())
        {
            cout<<val[q]<<endl;
        }
        else
         {
            calculate(q);
            cout<<val[q]<<endl;
         }
         if(t==10) break;
    }
    return 0;
}
