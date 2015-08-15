#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        int N;
        cin>>N;
        int men[N],woman[N],sum=0;
        for(int i=0;i<N;i++){
            cin>>men[i];
        }
        sort(men,men+N);
        for(int i=0;i<N;i++){
            cin>>woman[i];
        }
        sort(woman,woman+N);
        for(int i=0;i<N;i++){
            sum+=(woman[i]*men[i]);
        }
        cout<<sum<<endl;

    }
    return 0;
}
