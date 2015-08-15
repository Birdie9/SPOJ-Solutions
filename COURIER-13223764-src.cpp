#include <iostream>
#define INF 1000000000
using namespace std;
int tot;
int memo[101][1<<12];
int fw[101][101][101];
int od[12][2],n,b;
int go(int strt,int state){
 if(memo[strt][state]!=-1)return memo[strt][state];
 int ret=INF,f=0;
 for(int i=0;i<tot;i++){
    if(!((1<<i)&state)){
        f=1;
        int temp=fw[strt][od[i][0]][n]+fw[od[i][0]][od[i][1]][n]+go(od[i][1],state|(1<<i));
        if(temp<ret)ret=temp;
    }
 }
 if(f) return memo[strt][state]=ret;
 else return memo[strt][state]=fw[strt][b][n];
}

int main()
{
    int t;
    cin>>t;
    for(;t>0;t--){
        int m;
        cin>>n>>m>>b;
        b--;
        int rd[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)rd[i][j]=(i==j)?0:INF;
        }
        for(int i=0;i<m;i++){
                int temp1,temp2,temp3;
                cin>>temp1>>temp2;
                temp1--;temp2--;
                cin>>temp3;
                if(temp3<rd[temp1][temp2])
                    {
                        rd[temp1][temp2]=temp3;
                        rd[temp2][temp1]=temp3;
                    }
        }
        int z;
        cin>>z;

        tot=0;
        int indx=0;
        for(int i=0;i<z;i++){
            int temp1,temp2,temp3;
            cin>>temp1>>temp2>>temp3;
            temp1--;temp2--;
            for(int j=0;j<temp3;j++){
                od[indx][0]=temp1;
                od[indx][1]=temp2;
                tot++;indx++;
            }
        }
        for(int i=0;i<101;i++)
            for(int j=0;j<(1<<12);j++) memo[i][j]=-1;

        for(int k=0;k<=n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!k)fw[i][j][k]=rd[i][j];
                    else{
                        fw[i][j][k]=min(fw[i][k-1][k-1]+fw[k-1][j][k-1],fw[i][j][k-1]);
                    }
                }
            }
        }


cout<<go(b,0)<<endl;
    }
    return 0;
}

