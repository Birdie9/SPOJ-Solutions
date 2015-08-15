#include <iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define comp(c) (c==1)?2:1
#define gc getchar_unlocked
using namespace std;
bool sus;
int idx[2000];
bool done[2000];
int bugs[2000];
int inter[2000][2000];
int n,in;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void bfs(){
    for(int p=0;p<n;p++){
if(!done[p]){
queue<int> Q;
bugs[p]=1;
done[p]=true;
Q.push(p);
while(!Q.empty()){
    int curr=Q.front();
    Q.pop();
    for(int i=0;i<idx[curr];i++){
     if(!done[inter[curr][i]]){
        bugs[inter[curr][i]]=comp(bugs[curr]);
        Q.push(inter[curr][i]);
        done[inter[curr][i]]=true;
     }
     else{
            if(bugs[inter[curr][i]]==bugs[curr]){
                sus=true;
                return;
            }

     }
    }
}
}
}
}
int main()
{

        long long t;
        cin>>t;
        for(long long j=1;j<=t;j++){
        scanint(n);
        scanint(in);

         memset(idx,0,sizeof idx);
        for(int i=0;i<in;i++){
                int x,y;
            scanint(x);
            scanint(y);
        x=x-1;
        y=y-1;
        inter[x][idx[x]]=y;idx[x]++;
        inter[y][idx[y]]=x;idx[y]++;
        }
        sus=false;
        memset(bugs,0,sizeof bugs);
        memset(done,false,sizeof bugs);
        bfs();
        cout<<"Scenario #"<<j<<":"<<endl;
        if(sus)printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        }
    return 0;
}

