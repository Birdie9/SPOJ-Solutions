#include <iostream>
#include<cstdio>
using namespace std;
int jos[1000010];
int main()
{
    int n,d;
    while(scanf("%d",&n)&& n)
    {
        cin>>d;
        int a[n],i=2;

        jos[1]=1;
        while(i!=n+1)
        {
            jos[i]=(jos[i-1]+d-1)%i+1;
            i++;
        }
        cout<<n<<" "<<d<<" "<< jos[n]<<endl;
    }
    return 0;
}
