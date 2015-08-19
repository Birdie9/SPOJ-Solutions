#include<stdio.h>
#include<string.h>
int dp[500][500];
int n,m;
int yey[500][500];
int blog[500][500];
int count(int k,int row){
	if(row==n) return 0;
	if(dp[row][k]!=-1) return dp[row][k];
	int max=0;
	int temp=0,i;
	for(i=m-1;i>=k;i--)
	{
		temp+=(-yey[row][i]+blog[row][i]);
		int temp2=temp+ count(i,row+1);
		if(max<temp2) max=temp2;
	}
	return dp[row][k]=max;
}
int sum(int n,int m)
{
	int s=0;
	int i,j;
	for(i=0;i<n;i++ )
		for(j=0;j<m;j++) s+=yey[i][j];
	return s;
}
int main(){
	
	memset(dp,-1,sizeof(dp));
	int i,j;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&yey[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&blog[i][j]);
	int cur=sum(n,m);
	int temp=count(0,0);
	if(temp>0) cur+=temp;
	printf("%d\n",cur);
	return 0;
}