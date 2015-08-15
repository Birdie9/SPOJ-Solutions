#include<stdio.h>
#include<stdlib.h>

struct heap{
int **ar;
int len;
};
typedef struct heap heap;
int n;
int cluster[1001];
void swap(heap* h,int i,int j)
{
	int temp[3];
	temp[0]=h->ar[i][0];
	temp[1]=h->ar[i][1];
	temp[2]=h->ar[i][2];
	h->ar[i][0]=h->ar[j][0];
	h->ar[i][1]=h->ar[j][1];
	h->ar[i][2]=h->ar[j][2];
	h->ar[j][0]=temp[0];
	h->ar[j][1]=temp[1];
	h->ar[j][2]=temp[2];
}
int right(int i)
{
	return 2*i+2;
}
int left(int i)
{
	return 2*i+1;
}
int parent(int i)
{
	if(i%2==0) return (i/2)-1;
	else return i/2;
}
void minHeapify(heap* h,int i){
	int leftC=left(i);
	int rightC=right(i);
	int smallest=i;
	if(leftC<h->len && h->ar[leftC][0]<h->ar[smallest][0]) smallest=leftC;
	if(rightC<h->len && h->ar[rightC][0]<h->ar[smallest][0]) smallest=rightC;
	if(smallest!=i) 
	{
		swap(h,smallest,i);
		minHeapify(h,smallest);
	}
}
void buildHeap(heap* h)
{
	int i;
	for(i=parent(h->len-1);i>=0;i--)
	{
		minHeapify(h,i);
	}
}
int* getMin(heap* h )
{
	int* ret = (int*) malloc(sizeof(int)*3);
	ret[0]=h->ar[0][0];
	ret[1]=h->ar[0][1];
	ret[2]=h->ar[0][2];
	swap(h,0,h->len-1);
	h->len--;
	minHeapify(h,0);
	return ret;
}

void init(){
int i;
for(i=1;i<=n;i++)
{
	cluster[i]=i;
}
}
int findCluster(int a)
{
	int ans;
	while(1)
	{
		ans=cluster[a];
		if(ans!=a) a=ans;
		else return ans;
	}
	
}
void unionC (int head1,int head2)
{
	cluster[head1]=head2;
}
long int kruskal(heap* h)
{
	int added=0;
	long int cost=0;
	init();
	while(added!=n-1)
	{
		int* min=getMin(h);
		int c1=findCluster(min[1]);
		int c2=findCluster(min[2]);
		if(c1==c2) continue;
		cost+=min[0];
		free(min);
		added+=1;
		unionC(c1,c2);
	}
	return cost;
}
int main()
{
	int t;
	scanf("%d",&t);
	int i;
	heap* h;
	for(i=0;i<t;i++)
	{
		int price;
		scanf("%d",&price);
		scanf("%d",&n);
		int m;
		scanf("%d",&m);
		int j;
		h = (heap*) malloc(sizeof(heap));
		h->len=0;
		h->ar=(int**) malloc(sizeof(int*)*(m+10));
		for(j=0;j<m+10;j++)
		{
			h->ar[j]=(int*) malloc(sizeof(int)*3);
		}
		for(j=0;j<m;j++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			h->ar[h->len][0]=c;
			h->ar[h->len][1]=a;
			h->ar[h->len][2]=b;
			h->len++;
		}
		buildHeap(h);
		long int cost=kruskal(h);
		cost=cost*price;
		printf("%ld\n",cost);
		//for(j=1;j<n+1;j++) printf("%d\n",findCluster(j));
		for(j=0;j<m+10;j++)
		{
			free(h->ar[j]);
		}
		free(h->ar);
		free(h);
	}

}
