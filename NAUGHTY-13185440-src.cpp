#include <iostream>
#include<cstring>
using namespace std;
int num[100000];
int top[100000];
int main()
{
    int n;
    while(cin>>n){
        memset(num,0,sizeof num);
        memset(top,0,sizeof top);
        for(int i=0;i<n;i++){
            int t,b;
            cin>>t>>b;
            t--;b--;
            num[t]++;
            num[b]++;
            top[t]++;
        }
        int h=n%2==0?n/2:n/2+1;
        int tmax=0;
        bool imp=true;
        for(int i=0;i<100000;i++){
            if(num[i]>=h){
                    imp=false;
                if(tmax<top[i]){
                    tmax=top[i];
                }
            }
        }

        if(!imp) {
            if(h-tmax<0) cout<<0<<endl;
            else cout<<h-tmax<<endl;
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
