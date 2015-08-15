#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100010];
int T[100010];
int main(){
	while(1){
	
	scanf("%s",str);
	if(strcmp(str,"*")==0) break;
	int cnd=0;
	int len=1;
	int n=strlen(str);
	int i,pos=2;
	T[0]=-1;
	T[1]=0;
	while(pos<=n)
	{
		if(str[cnd]==str[pos-1]) {
			cnd++;
			T[pos]=cnd;
			pos++;
		}
		else if(cnd>0)
		{
			cnd=T[cnd];
		}
		else
		{
			T[pos]=0;
			pos++;
		}
	}
	int ans=0;
	for(i=-1;i<=n;)
	{
		while(T[i]!=1 && i<=n) i++;
		if(i==n+1) {ans=n ; break;}
		ans=i-1;
		while(i<n && T[i+1]==T[i]+1) i++;
		if(i==n) break;
		else i++;
	}
	if(n%ans==0) printf("%d\n",n/ans);
	else printf("%d\n",1);
}
return 0;
}