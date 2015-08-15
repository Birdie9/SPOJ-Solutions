#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int lcs(char*,char*); int len=0;
short dp[3][6110];
int main()
{int n;

    cin>>n;
    for(int y=0;y<n;y++){
   char str[6110];
   scanf("%s",str);
   char rev[6110];
len=0;
   while(str[len]!='\0') {
        len++;
   }
   for(int i=0;i<len;i++){
    rev[i]=str[len-i-1];
   }
   rev[len]='\0';
   memset(dp,0,sizeof dp);
   cout<<(len-lcs(str,rev))<<endl;
   }
    return 0;
}

int lcs (char*str,char*rev){int i,j;
for(i=0;i<len+1;i++){
    for(j=0;j<len+1;j++){
        if((i==0)||(j==0)){
            dp[i%2][j]=0;
        }
        else if(str[i-1]==rev[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;
        else dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);

    }

}
return dp[(i-1)%2][j-1];

}


