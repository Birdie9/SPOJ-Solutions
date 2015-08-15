/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2015 Jayati                                                    */
/*                                                                            */
/*   Description                                                           */
/*                                                                            */
/* ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/*typedef struct vert{
	int v;
	struct vert* next;
}vert;*/
int mat2[100][100];
void copy(int _mat[100][100],int mat_[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			_mat[i][j]=mat_[i][j];
}
int floyd(int mat[100][100],int n)
{
	int ret=n,k,i,j;
	//int** mat2 = (int**) malloc(sizeof(mat));
	copy(mat2,mat,n);
	for(k=0;k<n;k++)
	{	
		for(i=0;i<n;i++)
		{
			if(i==k) continue;
			for(j=0;j<n;j++)
			{
				if(j==k) continue;
				if(mat[i][k] && mat[k][j] && !mat[i][j])
				{
					mat2[i][j]=1;
					ret++;
				}
			}
		}
		copy(mat,mat2,n);
	}
	return ret;
}
int mat[100][100];
int main()
{
	int t,i;
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int j,k;
		//vert* adlist[n];
		//for(j=0;j<n;j++) adlist[j]=NULL;
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				mat[j][k]=0;
		for(j=0;j<n;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			/*vert* new1= (vert*) malloc(sizeof(vert));
			new1->v=b;
			vert* temp=adlist[a];
			adlist[a]=new1;
			new1->next=temp;
			vert* new2	= (vert*) malloc(sizeof(vert));
			new2->v=a;
			temp=adlist[b];
			adlist[b]=new2;
			new2->next=temp;*/
			mat[a][b]=1;
			
		}
		int k1=floyd(mat,n);
		printf("Case #%d: %d\n",i+1,k1-n);

	}
	

return 0;
}
