#include<stdio.h>
int dp[5002][5002];
int max(int a,int b) 
{
	if(a>b) return a;
	return b;
}
int count(char* arr,char* rev, int n)
{
	int i,j;
	for(i=0;i<=n;i++) dp[i][0]=0;
	dp[0][1]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(arr[i-1]==rev[j-1]) dp[i][j] = dp[i-1][(j-1)]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][(j-1)]);
		
		}	
	
 return n-dp[n][n];

}

int main(){
	int n;
	scanf("%d",&n);
	char arr[5001];
	char rev[5001];
	int i,j;
	scanf("%s",arr);
	for(i=n-1,j=0;i>=0 && j<n;i--,j++) rev[j]=arr[i];
	rev[n]='\0';
	printf("%d\n",count(arr,rev,n));
	return 0;
}