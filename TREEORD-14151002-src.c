#include<stdio.h>
#include<stdlib.h>
typedef struct inord{
	int v;
	struct inord* next;
}inord;
int trav(int* o1,int* o2,inord* o3,int n)
{
	if(o1[0]!=o2[n-1]) return 0;

	if(n==1)
	{
		if(o1[0]==o2[0] && o2[0]==o3->v) return 1;
		else return 0;
	}
	inord* cur=o3;
	int ret=1;
	int i;
	while(cur)
	{
		if(cur->v==o1[0]) break;
		cur=cur->next;
	}
	if(cur)
	{
		int leftnum=0;
		if(cur->next!=NULL)
		{
			//right child exists
			inord* right=cur->next;
			int rightv=o2[n-2];
			for(i=0;i<n;i++)
			{
				if(o1[i]==o2[n-2]) 
				{
					leftnum=i-1;
					ret=ret*trav(o1+i,o2+i-1,right,n-i);
					break;
				}
			}
		}
		if(cur!=o3)
		{
			//left child exists
			ret=ret*trav(o1+1,o2,o3->next,leftnum);
		}
		return ret;
	}
	else return 0;
}
int main(){
	
int n,i;
scanf("%d",&n);
int* o1,*o2;
inord *o3;
o1= (int*) malloc( sizeof(int)*n);
o2= (int*) malloc( sizeof(int)*n);
o3= (inord*) malloc( sizeof(inord));
inord* cur=o3,*prev=NULL;
for(i=0;i<n;i++)
{
	scanf("%d",&o1[i]);
}
for(i=0;i<n;i++)
{
	scanf("%d",&o2[i]);
}
for(i=0;i<n;i++)
{

	scanf("%d",&cur->v);
	if(prev)prev->next=cur;
	cur->next=NULL;
	prev=cur;
	if(i!=n-1)
		cur=(inord*) malloc(sizeof(inord));
}
int t=trav(o1,o2,o3,n);
if(t) printf("yes\n");
else printf("no\n");
return 0;
}