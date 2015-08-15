/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2015 Jayati                                                    */
/*                                                                            */
/*   Description                                                           */
/*                                                                            */
/* ========================================================================== */

#include<cstdio>
#include<cstring>
#include<cstdlib>
#define INF 1000000000
#define MAX 35
#include<algorithm>
char** a;
int num;
int flag;
struct node;
typedef struct node node;
struct node{
	char c;
	int idx;
	int min1;
	int min2;
	node* child[27];
};
typedef struct stack{
	int top;
	node* nd[MAX];
}stack;
int index(int i,int j)
{
	int idx=a[i][j]-96;
	if(a[i][j]=='\0') idx=0;
		return idx;
}
/*
void sort(){
	int i,j,k;
	for(j=0;j<num;j++)
	for(i=strlen(a[j]);i<31;i++)
	{
		a[j][i]='\0';
	}
	int count[27];
	for(i=0;i<27;i++) count[i]=0;
	for(j=29;j>=0;j--)
	{
		for(i=0;i<num;i++)
		{
			int idx=index(i,j);
			count[idx]++;
		}
		char** b;
		b=(char**) malloc(sizeof(char*)*num);
		for(k=0;k<num;k++)
			b[k]=(char*) malloc(sizeof(char)*31);

		for(i=num-1;i>=0;i--)
		{
			strcpy(b[count[index(i,j)]--],a[i]);
		}
		free(a);
		a=b;
	}
}*/
void push(stack* st,node* nd)
{
	st->top++;
	st->nd[st->top]=nd;
}
node* pop(stack* st)
{
	node* ret=st->nd[st->top];
	st->top--;
	return ret;
}
node* createNode(char c)
{
	node* newNode=(node*) malloc( sizeof(node));
	newNode->c=c;
	int i;
	for(i=0;i<27;i++)
	{
		newNode->child[i]=NULL;
	}
	newNode->min1=INF;
	newNode->min2=INF;
	return newNode;
}
char* reverse(char* ar,char* b){


    int k,len=strlen(ar);
    for(k=0;k<len;k++)
    {
        b[k]=ar[len-1-k];
    }
	b[k]='\0';
   //return b;
    //cout<<a[j]<<endl;
}
stack* find(node* root,char query[35])
{
	flag=0;
	stack* st=(stack*) malloc(sizeof(stack));
	st->top=-1;
	int i=0;
		node* cur=root;
		push(st,cur);
		for(i=0;query[i]!='\0';i++)
		{
			int idx=query[i];
			idx-=97;
			if(cur->child[idx])
			{
				cur=cur->child[idx];
				push(st,cur);
				continue;
			}
			else
			{
				return st;
			}
		}
		if(query[i]=='\0') flag=1;
		return st;
}
inline void dfs(node* cur,char query[35],char ans[35]){
int i;
if(cur->c=='\0')
{
	if(strcmp(query,a[cur->idx])!=0)
	{
		if(strlen(ans)==0 )
		{
			strcpy(ans,a[cur->idx]);
			return;
		}
		else if(strcmp(ans,a[cur->idx])>0 )
		{
			strcpy(ans,a[cur->idx]);
			return;
		}
		return;
	}
}
for(i=0;i<27;i++)
{
	if(cur->child[i])
	{
		dfs(cur->child[i],query,ans);
	}
}
}
void update(node* cur,int pos)
{
	if(cur->min1>pos)
	{
		cur->min2=cur->min1;
		cur->min1=pos;
		return;
	}
	if(cur->min2>pos) cur->min2=pos;
}
void insert(node* root,char* a2,int pos)
{
	int i=0;
	node* cur=root;
	//char a2[35];
	//strcpy(a2,a1);
	update(cur,pos);
	for(i=0;a2[i]!='\0';i++)
	{
		int idx=a2[i];
		idx-=97;
		if(cur->child[idx])
		{
			cur=cur->child[idx];
			update(cur,pos);
			continue;
		}
		else
		{
			cur->child[idx]=createNode(a2[i]);
			cur=cur->child[idx];
			update(cur,pos);
		}
	}
	if(!cur->child[26])
	{
		cur->child[26]=createNode('\0');
		cur->child[26]->idx=pos;
	}
}
int cmp(const char* lhs, const char* rhs) { return strcmp(lhs,rhs) < 0; }
int main()
{

    char c;
    int i=0,j=0,k;
    int endw=0;
	a=(char**) malloc(sizeof(char*)*25000);
		for(k=0;k<25000;k++)
			a[k]=(char*) malloc(sizeof(char)*MAX);
    while(1)
    {
        fgets(a[i],33,stdin);


        if(a[i][0]=='\n') break;
        int l=strlen(a[i]);
        a[i][l-1]='\0';
		int k;
        for( k=l-1;k<MAX;k++) a[i][k]='\0';
        i++;
    }
    num=i;
	node* root = createNode ('0');
	std::sort(a, a+num,cmp);

	for(i=0;i<num;i++)
	{
		char ar[MAX];
		reverse(a[i],ar);
		insert(root,ar,i);
	}
	char query[MAX];
	while(scanf("%s",query)){
	char queryR[MAX];
	reverse(query,queryR);
	char ans[MAX]="\0";
	stack* st = find(root,queryR);
	while(strlen(ans)==0){
	node* suff=pop(st);
	if(strcmp(query,a[suff->min1])!=0) {
		strcpy(ans,a[suff->min1]);
	}
	else if(suff->min2!=INF )
	{
		strcpy(ans,a[suff->min2]);
	}
}
	free(st);
	printf("%s\n",ans);
}


    return 0;
}
