#include<stdio.h>
#include<string.h>
int dp[65][65][65];
int main(){
int t;
scanf("%d",&t);
for(;t>0;t--)
{
char s1[65],s2[65],s3[65];
scanf("%s%s%s",s1,s2,s3);
int i,j,k,m;
for(i=0;i<strlen(s1)+1;i++)
	for(j=0;j<strlen(s2)+1;j++)
		for(k=0;k<strlen(s3)+1;k++)
		{
			if(k==0) dp[i][j][k]=1;
			else if((i+j)<k) dp[i][j][k]=0;
			else
			{
				int ans=0;
				for(m=i-1;m>=0 && m<i;m--) if(s1[m]==s3[k-1]) ans+=dp[m][j][k-1];
				for(m=j-1;m>=0 && m<j;m--) if(s2[m]==s3[k-1]) ans+=dp[i][m][k-1];
				dp[i][j][k]=ans;

			}
		}
printf("%d\n",dp[strlen(s1)][strlen(s2)][strlen(s3)]);

}
return 0;
}