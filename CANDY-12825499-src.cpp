#include <iostream>
#include<cmath>
using namespace std;
int N;
int main()
{

   while(cin>>N && N!=-1){
        int arr[N];
        double sum=0;
   for (int i=0;i<N;i++){
    cin>>arr[i];
   sum+=arr[i];
   }
   sum/=(double)N;
   int num=0;
   if(ceil(sum)!=sum){
    cout<<-1<<endl;
   }
   else{
   for(int i=0;i<N;i++){
        if(arr[i]>sum)
    num=num+arr[i]-sum;
   }
    cout<<num<<endl;
   }

   }
    return 0;
}
