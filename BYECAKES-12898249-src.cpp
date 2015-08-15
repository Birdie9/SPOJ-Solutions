#include <iostream>

using namespace std;

int main()
{
    int inp[8];
    while(true){
        for(int i=0;i<8;i++){
            cin>>inp[i];
        }
        if(inp[0]==-1) return 0;
        int maxm=0;
        for(int i=4;i<8;i++){
            int n=inp[i-4]/inp[i];
            if(inp[i-4]%inp[i]!=0) n++;
            maxm=max(maxm,n);
        }

            cout<<-inp[0]+maxm*inp[4]<<" "<<-inp[1]+maxm*inp[5]<<" "<<-inp[2]+maxm*inp[6]<<" "<<-inp[3]+maxm*inp[7]<<endl;

    }
    return 0;
}
