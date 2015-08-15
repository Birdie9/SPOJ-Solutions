#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        long long v=1,h=1;
        int m,n;
        cin>>m>>n;
        long long x[m],y[n];
        for(int i=0;i<m-1;i++){
            cin>>x[i];
        }
        sort(x,x+m-1);
        for(int i=0;i<n-1;i++){
            cin>>y[i];
        }
        sort(y,y+n-1);
        int j=n-2;
        long long cost=0;
        int i=m-2;
        for( ;i>=0 && j>=0;){
            if(x[i]>y[j]){
                cost+=v*x[i];
                h++;
                i--;
            }
            else{
                cost+=h*y[j];
                v++;
                j--;
            }
        }
        while(j>=0){
            cost+=h*y[j];
            j--;
        }
        while(i>=0){
            cost+=v*x[i];
            i--;
        }
        cout<<cost<<endl;
    }
}
