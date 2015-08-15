#include <iostream>

using namespace std;
int n;
long long c[2500];

long long mem[2000][2000];
long long rec(int start,int en){
 long long&ans=   mem[start][en];
 if(ans) return ans;
 else if(start==en)
return n*c[en];
else {
        int age=n-(en-start);
ans=(max(rec(start,en-1)+age*c[en],rec(start+1,en)+age*c[start]));
return ans;
}

}
int main()
{


    cin>>n;

    for(int i=0;i<n;i++){
        cin>>c[i];

    }
long long ans=rec(0,n-1);
    cout<<ans<<endl;
    return 0;
}
