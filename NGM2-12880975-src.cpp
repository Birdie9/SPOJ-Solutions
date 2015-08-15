#include <iostream>
#include<cstdio>
#include<cstdlib>

template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
using namespace std;
typedef unsigned long long ull;

int main()
{
    ull d,val,n, s[16];
    int k,tot,nb;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>s[i];
    }
    tot=(1<<k);
     d=n;
    for(int i=1;i<tot;i++){
          val=1,nb=0;
        for(int j=0;j<k;j++){
                if(i &(1<<j)){
                    nb++;
                    val=lcm(val,s[j]);
                }
        }
        if(nb & 1) n-= d/val;
        else n+=d/val;
    }
    cout<<n<<endl;
    return 0;
}
