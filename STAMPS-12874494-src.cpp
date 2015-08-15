#include <iostream>
#include<algorithm>
#include<cstdio>
#define gc getchar_unlocked
int f[1000];
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t;
    scanint(t);
    for(int i=1;i<=t;i++){
            int r,n;
        scanint(r);
        scanint(n);

        for(int j=0;j<n;j++){
            scanint(f[j]);
        }
        sort(f,f+n);
        int sum=0,k=0;
        while(sum<r && k<n){
            sum+=f[n-k-1];
            k++;
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        if(sum>=r){
        cout<<k<<endl;
        }
        else cout<<"impossible"<<endl;
        cout<<endl;
    }
    return 0;
}

