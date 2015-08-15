#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
char mat[101][101];
int dr[2][4]={{1,-1,0,0},{0,0,1,-1}};
int r,c;
int dist[101][101][16];
inline bool inGrid(pii p){
if(p.first>=0  && p.first<r && p.second>=0 &&p.second<c) return true;
else return false;
};
int bfs(pii &s){
pii u, v;
int umask, vmask, i;
queue< ppi > Q;
Q.push(ppi(s,0));
dist[s.first][s.second][0] = 0;
while(!Q.empty()) {
u = Q.front().first;
umask = Q.front().second;
Q.pop();
for(int i=0;i<4;i++){
v =pii (u.first+dr[0][i],u.second+dr[1][i]);
if(inGrid(v) && mat[v.first][v.second]!='#'){
if(mat[v.first][v.second]=='X') return dist[u.first][u.second][umask]+1;
else if(dist[v.first][v.second][umask]==-1){
vmask=umask;
if(islower(mat[v.first][v.second])){
char c=mat[v.first][v.second];
switch (c){
case 'r': vmask|=0x1;break;
case 'g':vmask|=0x2;break;
case 'b':vmask|=0x4;break;
case 'y':vmask|=0x8;break;
}
Q.push(ppi(v,vmask));
dist[v.first][v.second][umask]=dist[u.first][u.second][umask]+1;
dist[v.first][v.second][vmask]=dist[v.first][v.second][umask];
}
else if(isupper(mat[v.first][v.second])){

switch(mat[v.first][v.second]){
case 'R': if(umask& 0x1)Q.push(ppi(v,umask));break;
case 'G': if(umask& 0x2) Q.push(ppi(v,umask));break;
case 'B': if(umask& 0x4) Q.push(ppi(v,umask));break;
case 'Y': if(umask& 0x8) Q.push(ppi(v,umask));break;
}
dist[v.first][v.second][umask]=dist[u.first][u.second][umask]+1;//change
}
else{
Q.push(ppi(v,umask));
dist[v.first][v.second][umask]=dist[u.first][u.second][umask]+1;
}
}
}
}
}
return -1;
}
int main(){
while(scanf("%d%d",&r,&c)==2){
pii start;
if(!r && !c) return 0;
else{
for(int i=0;i<r;i++){
scanf("%s",mat[i]);
for(int j=0;j<c;j++){
if(mat[i][j]=='*') start=pii(i,j);
for(int k=0;k<16;k++) dist[i][j][k]=-1;
}
}
int S= bfs(start);
if(S<0) printf("The poor student is trapped!\n");
else printf("Escape possible in %d steps.\n",S);
}

}


}



