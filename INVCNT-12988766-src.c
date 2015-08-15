#include <stdio.h>
#include <stdlib.h>
long long int countnmerge(int *a1,int n1, int *a2, int n2);
long long int countnsort(int *a,int n);
int main()
{
    //FILE * fp;
    //fp=fopen("IntegerArray.txt","r");if (fp==NULL) printf("error");
    int t,n;
    scanf("%d",&t);
    for(;t>0;t--){
    scanf("%d",&n);
    int a[n],i;
    long long int p;

    for(i=0;i<n;i++) scanf("%d",&a[i]);
    //fclose(fp);
  /* for(i=0;i<100000;i++)
    printf("%d\n",a[i]);*/
   p= countnsort(a,n);
// for(i=0;i<n;i++)
  //   printf("%u\n",a[i]);
    printf("%lld\n",p);
    }
    return 0;
}
long long int countnsort(int *a,int n)
{
    long long int x,y,z;
    if(n==1)
   return 0;
    else if(n>1)
    {
        if(n%2!=0)
   {
       x=countnsort(a,n/2+1);
      y=countnsort(a+n/2+1,n/2);int p=n/2;
    z=countnmerge(a,p+1,a+p+1,p);return (x+y+z);
   }
   else
   {
     x= countnsort(a,n/2);
      y=countnsort(a+n/2,n/2);
      z=countnmerge(a,n/2,a+n/2,n/2);return (x+y+z);
   }

    }
}
long long int countnmerge(int *a1,int n1, int *a2, int n2)
{
    int *p=a1; int *q=a2,i,j;
    long long int c=0;
    int arr[n1+n2];
    for(i=0;i<(n1+n2) && p<(n1+a1) && q<(n2+a2);i++)
    {
        if(*p<*q)
        {
            arr[i]=*p;p++;
        }
        else if(*p>*q)
        {
            arr[i]=*q;q++;c=c+n1-(p-a1);

        }
        else if(*p==*q)
        {
            arr[i]=*p;p++;
        }
    }

    if(p!=(n1+a1))
    {
        while(p!=(n1+a1)) {arr[i]=*p;p++;i++;}
    }
     if(q!=(n2+a2))
    {
        while(q!=(n2+a2)) {arr[i]=*q;q++;i++;}
    }
    j=0;
    while(j<(n1+n2)) {a1[j]=arr[j];j++;}return c;
}
