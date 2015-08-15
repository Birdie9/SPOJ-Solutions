#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        unsigned long long n;
        cin>>n;
        unsigned long long up=(((n*(n+1))/2)*(n+2))/3;
        unsigned long long d;
        if(n%2==0){
            d=(n/2+1)*(n/2)*(2*n-1)/6;
        }
        else{
            d=(n-1)*(n+1)*(2*n+3)/24;
        }

        cout<<d+up<<endl;
    }
    return 0;
}
