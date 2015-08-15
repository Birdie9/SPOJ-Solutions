#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int mat[16][16];
int dup1[16][16];
int dr[5]={0,1,-1,0,0};
int dc[5]={0,0,0,1,-1};
int r,c;
void flip(int i,int j){
    for(int f=0;f<5;f++){
        int x=i+dr[f],y=j+dc[f];
        if(x>=0 && y>=0 && x<r && y<c){
            dup1[x][y]=!dup1[x][y];
         }
    }
}
int main()
{

    while(cin>>r>>c && r){
            fill_n(*mat,sizeof (mat)/sizeof(**mat),0);
        for(int i=0;i<r;i++){
                char row[20];
                scanf("%s",row);
            for(int j=0;j<c;j++){
                if(row[j]=='X'){
                    mat[i][j]=1;
                }
            }
        }
        int flips=100000;
    for(int i=0;i<(1<<c);i++){
        memcpy(dup1,mat,sizeof mat);
        int curr=0;
        bool val=false;
        for(int j=0;j<c;j++){
            if((1<<j)&i){
                flip(0,j);
                curr++;
            }
        }
        for(int j=1;j<r;j++){
                for(int k=0;k<c;k++)
            {
                if(dup1[j-1][k]){
                    flip(j,k);
                    curr++;
                }
            }
        }
        for(int j=0;j<c;j++){
            if(dup1[r-1][j]){
                    val=true;
            }
        }
        if(!val){
            flips=min(flips,curr);
        }
    }
    if(flips==100000){
        cout<<"Damaged billboard."<<endl;
    }
    else cout<<"You have to tap "<<flips<<" tiles."<<endl;
    }
    return 0;
}
