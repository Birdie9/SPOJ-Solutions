#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
	int ar[100000][2];
	int top;
	int empty;
}stack;
void push(stack* st,int i,int j)
{
	st->top++;
	st->ar[st->top][0]=i;
	st->ar[st->top][1]=j;
	if(st->empty) st->empty=0;
}
int* pop(stack* st)
{
	int* ar= (int*) malloc(sizeof(int)*2);
	ar[0]=st->ar[st->top][0];
	ar[1]=st->ar[st->top][1];
	st->top--;
	if(st->top==-1) st->empty=1;
	return ar;
}
int mat[100][100];
int done1[100][100];
int r,c;
char str[]="ALLIZZWELL";
int dfs(int r1,int c1,int pos)
{
	int i;
	if(pos==10) return 1;
	int adj[2][8]={
				{1,1,1,0,0,-1,-1,-1},
				{1,0,-1,1,-1,1,0,-1}
		};
	for(i=0;i<8;i++)
	{
		int x=r1+adj[0][i];
		int y=c1+adj[1][i];
		if(x<r && y<c && x>=0 && y>=0 && !done1[x][y])
		{
			if(mat[x][y]==str[pos])
			{
				done1[x][y]=1;
				int res=dfs(x,y,pos+1);
				if(!res) done1[x][y]=0;
				else return res;
			}
		}
	}
	return 0;
}
int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	int i,j,k;
	
	for(i=0;i<t;i++)
	{
		
		scanf("%d",&r);
		scanf("%d",&c);

	
	stack*  st = (stack*) malloc(sizeof(stack));
	st->top=-1;
	st->empty=1;
	
	for(j=0;j<r;j++)
		for(k=0;k<c;k++)
		{
			char ch;
			while(scanf("%c",&ch) && ch<31);
			mat[j][k]=ch;
			if(ch==65) push(st,j,k);
		}
	int done=0;
	while(!st->empty)
	{
		int* a=pop(st);
		int r1=a[0];
		int c1=a[1];
		memset(done1,0,sizeof(done1));
		done1[r1][c1]=1;
		if(dfs(r1,c1,1))
		{
			printf("YES\n");
			done=1;
			break;
		}
	
	}
	if(!done)
	printf("NO\n");
	}
	return 0;
}
