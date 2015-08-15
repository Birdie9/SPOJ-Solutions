#include <iostream>
#include <queue>
#include <cstring>
#include<utility>
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> ppi;
int mat[25][25][15];
int dist[25][25][15];
int st[2][5]={{1,-1,0,0,0},{0,0,1,-1,0}};
int r,c,num;
bool available(int x,int y,int maze2){
return (x<r && x>=0 && y<c && y>=0 && (mat[x][y][maze2]!=1) );
}
int bfs (){
memset(dist,-1,sizeof dist);
if(r==1 && c==1)return 0;
pi start = pi(0,0);
ppi initial = ppi (start,0);
dist[0][0][0]=0;
queue<ppi> Q;
Q.push(initial);
while(!Q.empty()){
    ppi curr= Q.front();
    Q.pop();
    pi position = curr.first;
    int maze = curr.second;
    int x=position.first, y=position.second;

    for(int i=0;i<5;i++){
            int x2=x+st[0][i],y2=y+st[1][i],maze2;
            if(maze!=(num-1))
               maze2=maze+1;
            else maze2=0;
         if(available(x2,y2,maze2)){
             if(x2==r-1 && y2==c-1) return dist[x][y][maze]+1;
             if(dist[x2][y2][maze2]==-1){

                dist[x2][y2][maze2]=dist[x][y][maze]+1;
                Q.push(make_pair(make_pair(x2,y2),maze2));
             }

         }

    }

}
return -1;

}
int main()
{int test=0;

   while( cin>>r>>c>>num && r){
        test++;
    for(int i=0;i<num;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;){
                    char c;
                cin>>c;
            if(c=='0' || c=='1'){
                mat[j][k][i]=c-48;
                k++;
            }
            }
        }
    }
    int ans=bfs();
    if(ans<0) cout<<"Case "<<test<<": Luke and Leia cannot escape."<<endl;
   else cout<<"Case "<<test<<": Luke and Leia can escape in "<<ans<<" steps."<<endl;
   }
    return 0;
}
