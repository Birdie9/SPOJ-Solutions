#include <iostream>
#include<cstring>
using namespace std;
int dp[11][11];

int main()
{
    int a,b;

for(int i=0;i<=10;i++){
    for(int j=0;j<=10;j++){
           dp[i][j]=1;


    }

}
for(int i=1;i<=10;i++){
    for(int j=1;j<=10;j++){

       dp[i][j]=dp[i][j-1]+dp[i-1][j];

    }

}
    while
   (cin>>a>>b && (a!=-1)){
       if(dp[a][b]!=(a+b))
       cout<<a<<"+"<<b<<"!="<<a+b<<endl;
        else
        cout<<a<<"+"<<b<<"="<<a+b<<endl;

   }

    return 0;
}
