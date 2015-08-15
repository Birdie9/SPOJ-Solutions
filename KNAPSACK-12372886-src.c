#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a)>(b)?(a):(b)
int S,N;
int main()
{
   scanf("%d %d",&S,&N);
   int item[N][2];
   int mem[N+1][S+1];
   int i,j;
   for(i=0;i<=S;i++){
    mem[0][i]=0;
   }
   for(i=0;i<=N;i++){
    mem[i][0]=0;
   }
   for(i=0;i<N;i++){
    scanf("%d %d",&item[i][0],&item[i][1]);
   }


   for(i=1;i<=N;i++){
    for(j=0;j<=S;j++){
        if(item[i-1][0] > j) mem[i][j]=mem[(i-1)][j];
        else{
            mem[i][j]=max(mem[(i-1)][j],item[i-1][1]+mem[(i-1)][j-item[i-1][0]]);
        }

    }

   }
   printf("%d",mem[N][S]);
    return 0;
}
