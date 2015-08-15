#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t=1;
    while(true){
        char str[2010];
        scanf("%s",str);
        if(str[0]=='-') break;
        int j=0;
        for(int i=0;str[i]!='\0' && str[j]!='\0';i=j){
            while(str[i]=='}' && str[i]!='\0') {
                    i++;

            }
            while(str[i]=='{' && str[i]!='\0'){
                i++;
            }
            j=i;
            i--;
            while(str[i]=='0' && i>=0)i--;
            while(str[j]=='}'&& i>=0 && str[j]!='\0' && str[i]=='{'){
                str[j]='0';
                str[i]='0';
                j++;
                while(str[i]=='0' && i>=0)i--;

            }

        }
        int num1=0,num2=0;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='}')num1++;
            else if(str[i]=='{')num2++;
        }
        if(num1%2==0) cout<<t<<". "<<(num1+num2)/2<<endl;
        else cout<<t<<". "<<((num1+num2)/2) +1<<endl;
t++;
    }
    return 0;
}
