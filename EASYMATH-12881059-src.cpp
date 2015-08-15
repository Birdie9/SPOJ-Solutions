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
    int t;
    cin>>t;
    for(;t>0;t--){
    ull d,d1,d2,val, s[5],n,m,a;
    int k=5,tot,nb;
    cin>>n>>m>>a>>d;
    for(int i=0;i<5;i++){
        s[i]= a+ i*d;
    }
    tot=(1<<k);
     d1=(--n),d2=m;
    for(int i=1;i<tot;i++){
          val=1,nb=0;
        for(int j=0;j<k;j++){
                if(i &(1<<j)){
                    nb++;
                    val=lcm1(val,s[j]);
                }
        }
        if(nb & 1) {
                n-= d1/val;
        m-=d2/val;
        }
        else {
                n+=d1/val;
        m+=d2/val;
        }
    }
    cout<<m-n<<endl;
    }
    return 0;
}
ull lcm1(ull a,ull b){

return (a*b/(gcd(a,b)));

}
ull gcd (ull x,ull y){
if(y==0) return x;
else return gcd(y,x%y);
}
