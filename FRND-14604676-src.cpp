#include <iostream>
#include <cstdio>
#define gc getchar_unlocked
#define ULL unsigned long long
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[1000000];
int main()
{
    int n;
    scanint(n);
    for(int i=0;i<n;i++)
    {

        scanint(arr[i]);

    }
    ULL sum=0;
    for(int j=0;j<21;j++)
    {
        ULL zero=0,one=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] & (1<<j)) one ++;
            else zero ++;
        }
        sum+= one*zero*(1<<j);
    }
        printf("%llu\n",sum);
    return 0;
}
