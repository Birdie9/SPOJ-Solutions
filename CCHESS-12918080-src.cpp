#include <iostream>
#include<vector>
#include<utility>
#define PB push_back
using namespace std;
typedef pair <int,int> pii;
typedef vector<pair<int,int> > vii;

bool done[8][8];
int cost[8][8];
int dr[8]={1,1,-1,-1,2,2,-2,-2};
int dc[8]={2,-2,2,-2,1,-1,1,-1};
bool ig(int x,int y);
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
            vii reached;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                done[i][j]=false;
        }
        done[a][b]=true;
        reached.PB(pii (a,b));
        cost[a][b]=0;
        while(!done[c][d]){
            int minm=100000,xtemp,ytemp;
            for(vector<pair<int,int> >::iterator it=reached.begin();it!=reached.end();it++){
                    int x=(*it).first,y=(*it).second;
                for(int i=0;i<8;i++){
                        int x1=x+dr[i],y1=y+dc[i];
                    if(ig(x1,y1)){
                        if(!done[x1][y1]){
                            int temp=(x*x1)+(y*y1)+cost[x][y];
                            if(temp<minm){
                                minm=temp;
                                xtemp=x1;
                                ytemp=y1;
                            }
                        }
                    }
                }
            }
           done[xtemp][ytemp]=true;
           cost[xtemp][ytemp]=minm;
           reached.PB(pii (xtemp,ytemp));
        }
        cout<<cost[c][d]<<endl;
    }
    return 0;
}
bool ig(int x,int y){
return(x>=0 && y>=0 && x<8 && y<8);
}
