#include <iostream>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        int n;
        scanint(n);
        if(n==1) cout<<"poor conductor"<<endl;
        else{
                int r=(n-1)/5;
                int s,d;
                char seat;
                s=(n-1)%5;
                if(s!=0) r++;
                else s=s+5;
                if(r%2!=0){
                    if(s<3) d=0;
                    else d=1;
                    switch(s){
                    case 1:seat='W';
                    break;
                    case 2:seat='A';
                    break;
                    case 3:seat='A';
                    break;
                    case 4:seat='M';
                    break;
                    case 5:seat='W';
                    break;
                    }

                }
                else{
                    if(s<=3) d=1;
                    else d=0;
                      switch(s){
                    case 5:seat='W';
                    break;
                    case 4:seat='A';
                    break;
                    case 3:seat='A';
                    break;
                    case 2:seat='M';
                    break;
                    case 1:seat='W';
                    break;
                    }

                }
                cout<<r<<" "<<seat<<" "<<(d?"R":"L")<<endl;

        }

    }
    return 0;
}
