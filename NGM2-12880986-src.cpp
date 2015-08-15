#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <bitset>
#include <limits>
#include <numeric>

using namespace std;
typedef unsigned long long ull;

ull lcm1(ull a, ull b);
ull gcd (ull x,ull y);
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
                    val=lcm1(val,s[j]);
                }
        }
        if(nb & 1) n-= d/val;
        else n+=d/val;
    }
    cout<<n<<endl;
    return 0;
}
ull lcm1(ull a,ull b){

return (a*b/(gcd(a,b)));

}
ull gcd (ull x,ull y){
if(y==0) return x;
else return gcd(y,x%y);
}
