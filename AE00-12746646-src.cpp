#include <iostream>
#include<cmath>
using namespace std;
int multiples(int p){
int sum=0;
double q=sqrt(p);
for(int i=1;i<=q;i++){
    if(p%i==0) sum++;
}
return sum;
}
int main()
{int sum=0,N;
    cin>>N;
    for(int i=1;i<=N;i++){
        sum+=multiples(i);
    }
    cout<<sum<<endl;
    return 0;
}
