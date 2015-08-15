#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    long long t;
    cin>>t;
    for(;t>0;t--){
        long long N;
        cin>>N;
        long long  n;
        long long sum[N+1];
        memset(sum,0,sizeof sum);
        for(int i=0;i<N;i++){
            cin>>n;
            sum[i+1]=sum[i]+n;
        }
        sort(sum,sum+N+1);
        long long ans=0;
        for(long long i=0;i<N+1;i++){
                long long curr=sum[i];
                long long r=0;
        while(sum[i]==curr){
            r++;
            i++;
        }
        ans+=r*(r-1)/2;
        i--;
        }
        cout<<ans<<endl;
    }
    return 0;
}

