#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
int t;
cin>>t;
for(;t>0;t--){
int n;
cin>>n;
long long num[n];
for(int i=0;i<n;i++)cin>>num[i];
sort(num,num+n);
long long ans=1,i=0;

while(i<num[i] && i<n){
    ans=(ans*((num[i]-i)%1000000007))%1000000007;
    i++;
}
if(i!=n) cout<<0<<endl;
else cout<<ans<<endl;
}
cout<<"KILL BATMAN"<<endl;
    return 0;
}
