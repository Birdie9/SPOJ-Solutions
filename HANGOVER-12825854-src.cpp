#include <iostream>
#include<cstring>
using namespace std;
int arr[600];
int main()
{
    float c;
    memset(arr,0,sizeof arr);
    arr[1]=50000000;
    for(int i=2;i<300;i++){

        arr[i]=arr[i-1]+100000000/(i+1);
    }
    while(cin>>c && c){
       int val=100000000*c,y=0;
        while(arr[y]<val){
            y++;
        }
        cout<<y<<" card(s)"<<endl;
    }

}

