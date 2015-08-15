#include<stdio.h>
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FORE(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define RFOR(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define RFORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define MSET(a,b) memset(a,b,sizeof(a))

int ar[1000];
int n;
int memo[1000];
int ht(int i)
{

    if(i>=n) return 0;
    if(memo[i]==-1)
    {

        if(ar[i]==-1) return memo[i]=0;
       int h1=ht(2*i+1),h2=ht(2*i+2);
       if(h1>h2) memo[i] =h1+1;
       else memo[i]=h2+1;
    }

   return memo[i];
}
int isAVL(int i)
{
    if(i>=n || ar[i]==-1 )return 1;
    int h1=ht(2*i+1),h2=ht(2*i+2);
    if((h1<h2 && h2-h1<=1 )|| (h1==h2) || (h2<h1 && h1-h2<=1))
    {
     int b=  isAVL(2*i+1)  ;
     if(b)
     {
         int c=  isAVL(2*i+2);
         if(c) return 1;
     }
    }

    else return 0;

}
int main()
{
    int i,j,t;
    //FILE * fp= fopen ("input.txt","r");
    scanf("%d",&t);
    //fscanf(fp,"%d",&t);
    REP(i,t)
    {

        scanf("%d",&n);
       // fscanf(fp,"%d",&n);

        REP(j,n)
        {
            scanf("%d",&ar[j]);
            //fscanf(fp,"%d",&ar[j]);
            memo[j]=-1;
        }
        if(isAVL(0)) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
