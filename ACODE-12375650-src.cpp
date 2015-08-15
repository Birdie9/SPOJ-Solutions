#include <iostream>
#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
char inp[5001]="";unsigned long long mem[5001];
int main()
{
while(1){scanf("%s",inp);
if(inp[0]=='0')break;
   int j;
   for(j=0;inp[j]!='\0';j++);
    mem[0]=0;
    mem[1]=1;
    for(int i=2;i<j+1;i++){mem[i]=0;
            int temp=inp[i-1]-'0'+10*(inp[i-2]-'0');
            if(inp[i-1]!='0')mem[i]=mem[i-1];
            if(temp<=26&&temp>9)
        mem[i]+=max(mem[i-2],1);

 }
    printf("%llu\n",mem[j]);
}
return 0;
}
