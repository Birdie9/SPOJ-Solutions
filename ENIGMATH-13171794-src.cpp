#include <iostream>

using namespace std;
long long gcd(long long a,long long b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
inline long long lcm(long long a,long long b){
return (a*b)/gcd(a,b);
}
int main()
{
   int t;
   cin>>t;
   for(;t>0;t--){
    long long a,b;
    cin>>a>>b;
    long long lc=lcm(a,b);
    cout<<lc/a<<" "<<lc/b<<endl;
   }
}
