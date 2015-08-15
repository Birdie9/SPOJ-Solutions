#include <stdio.h>
#include <stdlib.h>
#include<inttypes.h>
#define LL uint64_t
#include <math.h>
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        LL n;
        scanf("%I64d",&n);


        char* str = (char*) malloc(1001 * sizeof(char));
        int idx=999;
        str[1000]='\0';
        int powers[1000];
        int as=0;
        LL k,p=1;

        for(k=0;k<64;k++)
        {
            if(n&(p<<k)) {powers[as]=k;
            as++;}
        }
        int j,temp=0;
        int m;
        for(m=0;m<as;m++)
        {
            for(j=powers[m]-temp;j>0;j--)
            {
                str[idx]=')';
                idx--;
            }
            temp=powers[m];
            str[idx]='A';
            idx--;

        }
        for(j=powers[as-1];j>0;j--)
            {
                str[idx]='(';
                idx--;
            }
idx++;
            printf("%s\n",str+idx);
    }
    return 0;
}
