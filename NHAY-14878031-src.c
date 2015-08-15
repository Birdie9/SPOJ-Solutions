#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n;
	char* str;
	char S;
	int* T;

	while(scanf("%d",&n)==1){
		int i;
		
		
		str= (char*) malloc(sizeof(char) * (n+10));
		T=(int*) malloc(sizeof(int)*(n+10));
		scanf("%s",str);
		
		int len=strlen(str);
		int pos=2;
		T[0]=-1;
		T[1]=0;
		int cnd=0;
		while(pos<len)
		{
			if(str[pos-1]==str[cnd])
			{
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
				pos=pos+1;
			}

		}
		
		
		int m=0;
		i=0;
		int j=0;
		int ok=0;
		S=getchar_unlocked();
		while(1)
		{

			if(m+i==j)
			{
				S=getchar_unlocked();
				if(S=='\n') break;
				else j++;
			}
			if(str[i]==S) 
				if(i==strlen(str)-1) 
				{
					printf("%d\n",m);
					ok=1;
					if(T[i]>-1){
						m=m+i-T[i];
						i=T[i];
					}
					else 
					{
						i=0;
						m=m+1;
					}
				}
				else i++;
			else
			{
				if(T[i]>-1){
					m=m+i-T[i];
					i=T[i];
				}
				else 
				{
					i=0;
					m=m+1;
				}
				
			}
		}
		if(!ok) printf("\n");
		if(T!=NULL) free(T);
		if(str!=NULL) free(str);

}
return 0;
}