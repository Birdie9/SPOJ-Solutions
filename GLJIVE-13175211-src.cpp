#include <iostream>

using namespace std;

int main()
{
    int p[10];
    bool done=false;
    int sum=0;
    for(int i=0;i<10;i++){
        cin>>p[i];
        if(!done){
        sum+=p[i];
        if(sum>100){
            if(100-sum+p[i]<sum-100){
                sum-=p[i];
            }
           done=true;
        }
        }

    }
     cout<<sum<<endl;
    return 0;
}
