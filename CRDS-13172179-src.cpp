#include <iostream>

using namespace std;
long long sum(long long n){
return (n*(n+1)/2)%1000007;
}
int main()
{
    int t;
   long long n;
   cin>>t;
   for(;t>0;t--){
    cin>>n;
   cout<<(2*sum(n)+sum(n-1))%1000007<<endl;
   }
    return 0;
}
