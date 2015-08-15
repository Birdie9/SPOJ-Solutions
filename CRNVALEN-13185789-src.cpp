#include <iostream>

using namespace std;
int a[10000];
int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            int p;
            bool f=false,fool=false,same=true;
            for(int i=0;i<n;i++){
                if(a[i]>n-1) {fool=true;break;}
                else if(i==0){
                    p=a[i];
                }
                else{
                    if(!f){
                        if(a[i]==p+1) {
                            p=p+1;
                            f=true;
                            same=false;
                        }
                        else if(a[i]==p-1){
                            f=true;
                            same=false;
                        }
                        else if(a[i]!=p){
                            fool=true;
                            same=false;
                            break;
                        }
                    }
                    if(f){
                        if(!(a[i]==p || a[i]==p-1)){
                            fool=true;
                            break;
                        }
                    }
                }

            }
            int d=0;
            if(!fool && !same){
                for(int i=0;i<n;i++){
                    if(a[i]==(p-1)) d++;
                }
                if(d!=p) fool=true;
            }
            if(same){
                if(p){
                    if(n!=(p+1)) fool=true;
                    else{
                        p++;
                    }
                }
            }
            if(fool)cout<<-1<<endl;
            else cout<<p<<endl;

    }
    return 0;
}
