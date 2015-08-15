#include <iostream>

using namespace std;

int main()
{
   int n,m,x,y;
  while(  cin>>n>>m>>x>>y){
   int mat[n][m];
   x--;
   y--;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
        cin>>mat[i][j];
   }
   for(int i=x+1;i<n;i++) mat[i][y]=mat[i-1][y]-mat[i][y];
   for(int i=y+1;i<m;i++) mat[x][i]=mat[x][i-1]-mat[x][i];
   for(int i=x+1;i<n;i++){
    for(int j=y+1;j<m;j++){
        mat[i][j]=max(mat[i-1][j]-mat[i][j],mat[i][j-1]-mat[i][j]);
    }
   }
   if(mat[n-1][m-1]<0) cout<<"N"<<endl;
   else cout<<"Y "<<mat[n-1][m-1]<<endl;
  }
    return 0;
}
