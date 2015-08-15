#include <iostream>
#include<cstring>
using namespace std;
int mat[10000][3];
int score[10001];
bool processed[10001];
int main()
{
    int t,v,e,start,trgt;
    cin>>t;
    for(int i=0;i<t;i++){
            memset(score,-1,sizeof score);
    memset(processed,false,sizeof processed);

        cin>>v>>e;
        for(int i=0;i<e;i++){
            cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
        }
        cin>>start>>trgt;
        int num=1;
        score[start]=0;
        processed[start]=true;
        while(true){
                int k=-1,mini=100000000,greedy;


                    for(int j=0;j<e;j++){
                            if(processed[mat[j][0]] && !processed[mat[j][1]]){
                                   greedy= score[mat[j][0]]+mat[j][2];
                            if(mini>greedy){

                                k=mat[j][1];
                            mini=greedy;


                    }
                    }
                    }
                    processed[k]=true;
                    score[k]=mini;

            num++;
        if(processed[trgt]) {
                cout<<score[trgt]<<endl;break;
        }
        else if(num==v) {cout<<"NO"<<endl;break;}
        }
    }
    return 0;
}
