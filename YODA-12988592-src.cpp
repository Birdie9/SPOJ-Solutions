#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long fact(long long i){
if (i==0) return 1;
else return i*fact(i-1);
}
char s[1000000];
int main()
{

    long long let[26];
    while(gets(s)){

    memset(let,0,sizeof let);
    for(int i=0;s[i]!='\0';i++){
      if(s[i]<=90 && s[i]>=65)  {
        let[s[i]-65]++;
      }
      else if(s[i]>= 97 && s[i]<=122){
        let[s[i]-97]++;
      }
    }
    long long odd=0,esum=0,eprod=1;
    bool zero=false;
    for(int i=0;i<26;i++){
     if(let[i]){
        if(let[i]%2==0){
            esum+=((let[i])/2);
            eprod*=fact((let[i])/2);
        }
        else if(odd){
            zero=true;break;
        }
        else{
            odd++;
            esum+=((let[i]-1)/2);
            eprod*=fact((let[i]-1)/2);
        }
     }
    }
    if(esum){
    if(!zero)cout<<fact(esum)/eprod<<endl;
    else cout<<0<<endl;
    }

    else{
            if(!zero)
            cout<<1<<endl;
    else cout<<0<<endl;
    }
    }
    return 0;
}


