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
#include<string.h>
typedef struct stack {
int rc[10000][3];
int top;
int empty;

}stack;
char str[]="ALLIZZWELL";
void push(stack* st,int r,int c,int l)
{

	st->top++;
	if(st->top<10000) {
	st->rc[st->top][0]=r;
	st->rc[st->top][1]=c;
	st->rc[st->top][2]=l;
	if(st->empty) st->empty=0;
	//printf("%c pushed\n",str[l]);
}

}
void pop (stack* st,int ret[3])
{
	if(st->top>=0 && st->top<10000)
	{

		ret[0]=st->rc[st->top][0];
		ret[1]=st->rc[st->top][1];
		ret[2]=st->rc[st->top][2];
		st->top--;
		if(st->top==-1) st->empty=1;
	//printf("%d %d %d\n",ret[0],ret[1],ret[2]);
	}
}

int done[100][100][10];
int mat[100][100];
int dfs(stack* st,int rMAX,int cMAX)
{

	int adj[2][8]={
			{1,1,1,0,0,-1,-1,-1},
			{1,0,-1,1,-1,1,0,-1}
	};
	int i,j,k;
	int pos[10][2];
	while(!st->empty)
	{
		//printf("dfs2\n");
		int rc[3];
		pop(st,rc);
		if(rc[2]==0)
		{

			int i1,j1,k1;
			for(i1=0;i1<rMAX;i1++) for(j1=0;j1<cMAX;j1++) for(k1=0;k1<10;k1++) if(k1!=0)done[i1][j1][k1]=0;
		}
		int r=rc[0];
		int c=rc[1];
		int l=rc[2];
		pos[l][0]=r;
		pos[l][1]=c;
		//printf("exploring %c\n",mat[rc[0]][rc[1]]);
		for(i=0;i<8;i++){

			r=rc[0]+adj[0][i];
			c=rc[1]+adj[1][i];
			//printf("on %d %d %d\n",r,c,l);
			if(r>=0 && c>=0 && r<rMAX && c<cMAX && !done[r][c][l+1])
			{
				int m,br=0;
				for(m=0;m<=l;m++) {
					if(pos[m][0]==r && pos[m][1]==c){
					 br=1;break;
					}
					}

				if(br) continue;
				done[r][c][l+1]=1;
				if(l==9) return 1;
				else{
					//printf("before equating %c %c \n",str[l+1],mat[r][c]);
					if(str[l+1]==mat[r][c]) {
					if(l==8) return 1;
					push(st,r,c,l+1);

					}
				}
			}
		}
	}
return 0;
}
int main()
{
int t;
scanf("%d",&t);
int i,i1,j,k;
for(i=0;i<t;i++)
{
	int r,c;
	scanf("%d",&r);
	scanf("%d",&c);
	//int** mat= (int**) malloc(sizeof(int*)*r);
	//for(j=0;j<r;j++)
	//	mat[j] = (int*) malloc(sizeof(int)*c);
	stack*  st = (stack*) malloc(sizeof(stack));
	st->top=-1;
	st->empty=1;
	for(i1=0;i1<r;i1++) for(j=0;j<c;j++) for(k=0;k<10;k++) done[i1][j][k]=0;
	for(j=0;j<r;j++)
		for(k=0;k<c;k++)
		{
			char ch;
			while(scanf("%c",&ch) && ch<31);
			mat[j][k]=ch;
			if(ch==65) push(st,j,k,0);
			done[j][k][0]=1;
		}

	if(dfs(st,r,c)) printf("YES\n");
	else printf("NO\n");

}
return 0;
}
