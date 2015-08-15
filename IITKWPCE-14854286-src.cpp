#include<cstdio>
#include<cstdlib>
using namespace std;
int sol[2000];
int palin[2000][2000];

int findMin(char* arr, int len)
{
	for(int i=0;i<len;i++)
	{
		palin[i][i]=1;
	}
	
	for(int i=0;i<len-1;i++)
	{
		if(arr[i]==arr[i+1])
			palin[i][i+1]=1;
		else
			palin[i][i+1]=0;	
	}
	
	for(int i=3;i<=len;i++)
	{
		for(int j=0;j<=len-i;j++)
		{
			if(arr[j]==arr[j+i-1])
				palin[j][j+i-1] = palin[j+1][j+i-2];
			else
				palin[j][j+i-1] = 0;
		}
	}
	/*
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(j<i)
				printf("-1 ");
			else
				printf(" %d ",palin[i][j]);
		}
		printf("\n");
	}
	*/
	sol[0] = 1;
	for(int i=1;i<len;i++)
	{
		if(palin[0][i]==1)
			sol[i]=1;
		else	
		{
			int min = 2001;
			for(int j =i;j>=0;j--)
			{
				if(palin[j][i] == 1)
				{
					if(sol[j-1]+1 < min)
						min = sol[j-1]+1;
				}
			}
			sol[i] = min;
		}
	}
	
	return sol[len-1];

}

int main()
{
	int t;
	scanf("%d",&t);
	char a[2001];
	getchar();
	for(int i=0;i<t;i++)
	{
		int len = 0;
		char c;
		while((c = getchar())!='\n' && c!=EOF)
		{
			a[len++] = c;
		}
		a[len]='\0';
		printf("%d\n",findMin(a,len));
	}
	return 0;
}