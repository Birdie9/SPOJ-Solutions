#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define INF 1000000000
int mat[2010][2010];
int matc[2010][2010];


int count(char* str,int st,int en)
{

    if(mat[st][en]!=-1) return mat[st][en];
    if(matc[st][en]==1) return mat[st][en]=1;
    int min = INF;
    int i=1;
    while(st+i<=en)
    {
        int temp1=count(str,st,st+i-1);
        if(temp1>min-2){i++;continue;}
        int temp2= count(str,st+i,en);
        int temp=temp1+temp2;
        if(temp==2) {min=2; break;}
        if(min>temp) min=temp;
        i++;
    }
    return mat[st][en]=min;
}
int main()
{

    int t;
    scanf("%d",&t);
    for(;t>0;t--){
    char str[2010];
    scanf("%s",str);
    int n=strlen(str);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++) {mat[i][j]=-1;matc[i][j]=-1;}
    for(i=0;i<n;i++) matc[i][i]=1;
    for(i=0;i<n-1;i++)
        if(str[i]==str[i+1]) matc[i][i+1]=1;
          else matc[i][i+1]=0;
    for(i=3;i<=n;i++)for(j=0;j<=n-i;j++)
    {
        if(matc[j+1][j+i-2]==1 && str[j]==str[j+i-1]) matc[j][j+i-1]=1;
        else matc[j][j+i-1]=0;
    }

    printf("%d\n",count(str,0,n-1));
    }
    return 0;
}
