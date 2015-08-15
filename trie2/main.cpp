#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char a[250000][31];
int num;
void reverse(char a[31]){
for(int j=0;j<i;j++)
{
    char b[31];
    strcpy(b,a[j]);
    int k,len=strlen(a[j]);
    for(k=0;k<len;k++)
    {
        b[k]=a[j][len-1-k];
    }
    strcpy(a[j],b);
    //cout<<a[j]<<endl;
}
}
int main()
{

    char c;
    int i=0,j=0;
    bool endw=false;
    while(true)
    {
        fgets(a[i],14,stdin);


        if(a[i][0]=='\n') break;
        int l=strlen(a[i]);
        a[i][l-1]='\0';
        for(int k=l-1;k<31;k++) a[i][k]='\0';
        i++;
    }
    num=i;



    return 0;
}
