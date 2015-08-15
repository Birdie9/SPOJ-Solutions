//a(n)=a(n-1)*2+a(n-2)
	
//a[1]=3;
//a[2]=9;
//a[3]=21;
//a[4]=81-24=57
//=42+9=51
#include<stdio.h>

int main(){
	int n;
	long long int T[35];
	int t;
	int i;
	scanf("%d",&t);
	T[1]=3;
	T[2]=9;
	T[3]=21;
	for(i=4;i<=33;i++)
	{
		T[i]=2*T[i-1]+T[i-2];
	}
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%lld\n",T[n]);
	}
	return 0;
}