/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2015 Jayati                                                    */
/*                                                                            */
/*   Description                                                           */
/*                                                                            */
/* ========================================================================== */
#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000
int n;
int min(a,b)
{
	if(a<b) return a;
	return b;
}
int*** floyd(int** mat)
{
	int i,j,k;
	int*** dist=(int***) malloc( sizeof(int**)*2);
	dist[0]=(int**) malloc(sizeof(int*)*100);
	for(i=0;i<100;i++)
		dist[0][i]=(int*) malloc(sizeof(int)*100);
	dist[1]=(int**) malloc(sizeof(int*)*100);
	for(i=0;i<100;i++)
		dist[1][i]=(int*) malloc(sizeof(int)*100);
		
		
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[0][i][j]=mat[i][j];
	
	for(k=1;k<=n;k++)
	{
		for(j=0;j<n;j++)
			for(i=0;i<n;i++)
			{
				dist[k%2][i][j]=min(dist[(k-1)%2][i][j],dist[(k-1)%2][i][k-1]+dist[(k-1)%2][k-1][j]);
			}
	}
	return dist;
}
int main()
{
int e,t,m;
scanf("%d%d%d%d",&n,&e,&t,&m);
int i,j;
int** mat = (int**) malloc(sizeof(int*)*100);
for(i=0;i<100;i++) mat[i] = (int*)malloc(sizeof(int)*100);

for(i=0;i<100;i++)
	for(j=0;j<100;j++) mat[i][j]=(i==j?0:INF);
for(i=0;i<m;i++)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a--;
	b--;
	mat[a][b]=min(c,mat[a][b]);
}
int*** dist= floyd(mat);
int count=0;
for(i=0;i<n;i++)
	if(dist[n%2][i][e-1]<=t) count++;
printf("%d\n",count);
return 0;
}
