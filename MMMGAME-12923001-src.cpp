#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){

        int n;
        cin>>n;
        long long ans=0;
        bool allOnes=true;
        for(int i=0;i<n;i++){
            long long temp;
            cin>>temp;
            if(temp!=1) allOnes=false;
            ans=ans^temp;
        }
       if(allOnes ){
        if(n%2==0) cout<<"John"<<endl;
        else cout<<"Brother"<<endl;
       }
       else if(ans==0)cout<<"Brother"<<endl;
       else cout<<"John"<<endl;
    }
    return 0;
}
