#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n){
           int mat[n][n];

           for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=-1;
                }
            int j;
            char x[10];
            cin>>j>>x;
           mat[i][j-1]=strcmp(x,"true")?0:1;
           }
           bool done[n];
           memset(done,false,sizeof done);
           int ass[n];
           memset(ass,-1,sizeof ass);
           queue<int> q;
           bool para=false;
           for(int i=0;i<n;i++){
            if(!done[i]){
            done[i]=true;
            ass[i]=1;
            q.push(i);
                while(!q.empty()){
                        int j=q.front();
                        q.pop();
                       for(int r=0;r<n;r++){
                            if(mat[r][j]!=-1){
                                if((ass[j]==mat[r][j])){
                                    if(done[r]){
                                        if(ass[r]!=1){
                                            para=true;
                                            break;
                                        }
                                    }
                                    else{
                                        ass[r]=1;
                                        done[r]=true;
                                        q.push(r);
                                    }
                                }
                                else{
                                    if(done[r]){
                                        if(ass[r]==1){
                                            para=true;
                                            break;
                                        }
                                    }
                                    else{
                                        ass[r]=0;
                                        done[r]=true;
                                        q.push(r);
                                    }
                                }
                            }
                        }
                        for(int c=0;c<n;c++){
                            if(mat[j][c]!=-1){
                                if(ass[j]==1){
                                    if(done[c] && ass[c]!=mat[j][c]) {
                                            para=true;
                                            break;
                                    }
                                    else if(!done[c]){
                                        done[c]=true;
                                        q.push(c);
                                        ass[c]=mat[j][c];
                                    }
                                }
                                else{
                                    if(done[c] && ass[c]==mat[j][c]) {
                                            para=true;
                                            break;
                                    }
                                    else if(!done[c]){
                                        done[c]=true;
                                        q.push(c);
                                        ass[c]=!mat[j][c];
                                    }
                                }
                            }
                        }
                        if(para) break;
                    }
                }
                if(para) break;
           }
           if(para) cout<<"PARADOX"<<endl;
           else cout<<"NOT PARADOX"<<endl;

    }
    return 0;
}
