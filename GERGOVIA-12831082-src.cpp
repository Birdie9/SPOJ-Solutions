#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n){
            long long a[n],bag=0,dist=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(bag<0)
                dist-=bag;
        else
            dist+=bag;
            bag+=a[i];
        }
        cout<<dist<<endl;
    }
    return 0;
}
