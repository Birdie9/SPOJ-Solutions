#include <iostream>
#include<cmath>
using namespace std;
long long powr(int i,int j){
    int k=i;
    if(!j) return 1;
    if (j==1)return i;
    j--;
for(;j>0;j--) i=i*k;
return i;
}
int rev(int x){
int d[10],i;
for( i=0;x!=0;i++){
    d[i]=x%10;
    x/=10;
}
int r=0;
for(int t=0;t<i;t++){
    r+=(d[t]*(powr(10,i-1-t)));

}

return r;
}
int main()
{
    int n;
    cin>>n;
    for(;n>0;n--){
        int i,j;
        cin>>i>>j;
        int sum=rev(rev(i)+rev(j));
        cout<<sum<<endl;
    }
    return 0;
}
