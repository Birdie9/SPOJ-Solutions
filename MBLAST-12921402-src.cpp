#include <iostream>
#include<cstdio>
#define minm(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define val(a,b) (a-b)<0?(b-a):(a-b)
using namespace std;
int dp[2010][2010];
int main()
{
    char a[2010];
    char b[2010];
    int gap;
    scanf("%s%s",a,b);
    cin>>gap;
    dp[0][0]=0;

    for(int j=1;b[j-1]!='\0';j++){
        dp[0][j]=gap*j;
    }
    for(int j=1;a[j-1]!='\0';j++){
        dp[j][0]=gap*j;
    }
    int i,j;
    for( i=1;a[i-1]!='\0';i++){
        for( j=1;b[j-1]!='\0';j++ ){
            dp[i][j]=
            minm(dp[i-1][j]+gap,
                 dp[i][j-1]+gap,
                 dp[i-1][j-1]+(val(a[i-1],b[j-1])));
        }
    }
    cout<<dp[--i][--j]<<endl;
    return 0;
}
