#include <iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void scanlong(long long &x)
{
    register long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int t;
    scanint(t);
    for(int l=1;l<=t;l++){
    int n;
    int r;
    scanint(n);
    long long mat[n][n];
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
        scanlong(mat[i][j]);
    }
    long long fw[n][n][n+1];
   // bool repeat=false;
    for(int k=0;k<=n ;k++){
          //  repeat=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!k) fw[i][j][k]=mat[i][j];
                else{
                    fw[i][j][k]=min(fw[i][j][k-1],fw[i][k-1][k-1]+fw[k-1][j][k-1]);
                   // if(fw[i][j][k-1]<fw[i][k][k-1]+fw[k][j][k-1]) repeat=false;
                }
            }
        }
    }
    scanint(r);
    long long sum=0;
    for(int i=0;i<r;i++){
        int a,b;
        scanint(a);
        scanint(b);
        a--;
        b--;
        sum+=fw[a][b][n];
    }
    printf("Case #%d: %lld\n",l,sum);
    }
    return 0;
}
