#include <iostream>
#include<cstdio>
using namespace std;
void traverse(int i,int j, int m, int n);
char mat[20][20];
bool traversed[20][20];
int e[2][2];
int t=0,n,m;
int points=0;
bool invalid=false;
int main()
{
    scanf("%d",&t);
    for (int i=0;i<t;i++){

        points=0;
        invalid=false;
        scanf("%d",&m);
        scanf("%d",&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    traversed[i][j]=false;
                    do{
                scanf("%c",&mat[i][j]);
                    }while(mat[i][j]!='.' && mat[i][j]!='#');
            }
            }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(((i==0) || (j==0)||(i==(m-1))||(j==(n-1))) && mat[i][j]=='.'){
                    if(points<2){
                e[points][0]=i;
                e[points++][1]=j;
                    }
                    else invalid=true;
            }
        }
        }
        if(points<2) invalid =true;
        if(invalid)
        {
            printf("invalid\n");
            continue;
        }
        else{
        traverse(e[0][0],e[0][1],m,n);
        if(traversed[e[1][0]][e[1][1]]) printf("valid\n");
        else printf("invalid\n");
        }
    }
    return 0;
}
void traverse(int i,int j, int m, int n){
    traversed[i][j]=true;
    if(i-1>=0){
        if(mat[i-1][j]=='.'){
            if(!traversed[i-1][j]) {
                    traverse(i-1,j,m,n);
                    if(traversed[e[1][0]][e[1][1]])

                    return;
            }
        }
    }
    if(i+1<m){
            if(mat[i+1][j]=='.'){
                      if(!traversed[i+1][j]) {
                    traverse(i+1,j,m,n);
                    if(traversed[e[1][0]][e[1][1]])

                    return;
            }

        }
    }
    if(j-1>=0){
        if(mat[i][j-1]=='.'){
                  if(!traversed[i][j-1]) {
                    traverse(i,j-1,m,n);
                    if(traversed[e[1][0]][e[1][1]])

                    return;
            }

        }
    }
    if(j+1<n){
        if(mat[i][j+1]=='.'){
                  if(!traversed[i][j+1]) {
                    traverse(i,j+1,m,n);
                    if(traversed[e[1][0]][e[1][1]])

                    return;
            }

        }
    }

}
