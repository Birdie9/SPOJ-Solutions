#include <iostream>
#include<cstring>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int n;
    while(cin>>n){
        int s[n][2];
    for(int i=0;i<n;i++){
        scanint(s[i][0]);
        scanint(s[i][1]);
    }
    bool cap[n];
    memset(cap,false,sizeof cap);
    int dp[n/2];
    dp[0]=s[0][1]+s[1][0];
    cap[1]=true;
    int diff=0,na;
    for(int i=1;i<n/2;i++){
        if(diff==0){
            for(int j=0;j<(2*i);j++){
                if(cap[j]){
                    if(diff<s[j][0]-s[j][1]){
                        diff=s[j][0]-s[j][1];
                        na=j;
                    }
                }
            }
        }
        if(-diff+s[2*i][0]<s[2*i][1]){
            dp[i]=dp[i-1]-diff+s[2*i][0]+s[(2*i)+1][0];
            int c1=s[2*i][0]-s[2*i][1];
            int c2=s[2*i+1][0]-s[2*i+1][1];
            cap[2*i]=true;
            cap[2*i+1]=true;
            cap[na]=false;
            if(diff<=c1 || diff<=c2){
                if(diff<c1){
                  diff=c1;
                  na=2*i;
                }
                else{
                    diff=c2;
                    na=2*i+1;
                }
            }
            else{
                diff=0;
            }
        }
        else{
            dp[i]=dp[i-1]+s[2*i][1]+s[2*i+1][0];
            if(diff<s[2*i+1][0]-s[2*i+1][1]){
                na=2*i+1;
                diff=s[2*i+1][0]-s[2*i+1][1];
            }
            cap[2*i+1]=true;
        }
    }
    int sum=0;
    for(int k=0;k<n;k++){
        if(cap[k])sum+=s[k][0];
        else sum+=s[k][1];
    }
    cout<<sum<<endl;
    }
    return 0;
}
