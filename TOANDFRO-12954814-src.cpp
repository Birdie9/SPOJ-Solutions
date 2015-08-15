#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    while(true){
    char str[210];
    char arr[210][22];
    int c;
    cin>>c;
    if(!c)break;
    scanf("%s",str);
    int k=0,i,j;
    for( i=0;str[k]!='\0';i++){
        for( j=0;j<c;j++){
            if(i%2==0){
                arr[i][j]=str[k];
            }
            else{
                arr[i][c-j-1]=str[k];
            }
            k++;
        }
    }
    for(int q=0;q<c;q++){
    for(int p=0;p<i;p++){
        cout<<arr[p][q];
    }
    }
    cout<<endl;
    }
    return 0;
}
