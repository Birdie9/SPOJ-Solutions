#include <iostream>

using namespace std;

int main()
{
    char str[21];
    cin>>str;

    int dp[21];
    dp[0]=1;
    dp[1]=1;
    int len=0;
    while(str[len]!='\0')len++;
    if(len>1)
    for(int i=2;i<=len;i++){
        if((((str[i-2]-48) *10 +str[i-1]-48)<=20)&&str[i-2]!='0')
            dp[i]=dp[i-1]+dp[i-2];
        else dp[i]=dp[i-1];
    }
    cout<<dp[len]<<endl;
    return 0;
}
