#include <iostream>
#include<cmath>
using namespace std;

int main()
{
   int a[4];
   a[0]=942;
   a[3]=692;
   a[2]=442;
   a[1]=192;
   long long n,t;
   cin>>t;
   for(;t>0;t--){
     cin>>n;
     if(n>4){
     long long pr=n/4;
     if(n%4==0) pr--;
     cout<<pr<<a[n%4]<<endl;
     }
     else{
        cout<<a[n%4]<<endl;
     }
   }


    return 0;
}
